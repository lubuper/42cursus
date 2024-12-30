import json
from channels.generic.websocket import AsyncWebsocketConsumer

class ChatConsumer(AsyncWebsocketConsumer):
	async def connect(self):
		self.user_name = self.scope['url_route']['kwargs']['user_name']
		self.friend_name = self.scope['url_route']['kwargs']['friend_name']
		self.room_group_name = f"chat_{min(self.user_name, self.friend_name)}_{max(self.user_name, self.friend_name)}"
		await self.channel_layer.group_add(
			self.room_group_name,
			self.channel_name
		)
		await self.accept()
	async def disconnect(self, close_code):
		await self.channel_layer.group_discard(
			self.room_group_name,
			self.channel_name
		)
	async def receive(self, text_data):
		data = json.loads(text_data)
		message = data['message']
		await self.channel_layer.group_send(
			self.room_group_name,
			{
				'type': 'chat_message',
				'message': message,
				'sender': self.user_name
			}
		)
	async def chat_message(self, event):
		message = event['message']
		sender = event['sender']
		await self.send(text_data=json.dumps({
			'message': message,
			'sender': sender
		}))

class GamePongConsumer(AsyncWebsocketConsumer):
    # Store connected players for each game
    connected_players = {}

    async def connect(self):
        self.game_id = self.scope['url_route']['kwargs']['game_id']
        self.room_group_name = f'game_{self.game_id}'

        query_params = self.scope['query_string'].decode()
        self.purpose = None
        if "purpose=reject" in query_params:
            self.purpose = "reject"
        elif "purpose=join" in query_params:
            self.purpose = "join"

        if self.game_id not in self.connected_players:
            self.connected_players[self.game_id] = []

        if self.purpose == "reject":
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'player_reject',
                    'message': 'A player rejected the game.',
                }
            )
            await self.close()
            return

        if self.purpose == "join":
            # Reject if room already has 2 players
            if len(self.connected_players[self.game_id]) >= 2:
                await self.close()
                return

            self.connected_players[self.game_id].append(self.channel_name)
            await self.channel_layer.group_add(self.room_group_name, self.channel_name)
            await self.accept()

            await self.notify_players()

    async def disconnect(self, close_code):
        # Ensure the player is removed from the room
        if self.game_id in self.connected_players:
            if self.channel_name in self.connected_players[self.game_id]:
                self.connected_players[self.game_id].remove(self.channel_name)

                # Notify the remaining player
                if close_code != 1000 or close_code != 1001:
                    await self.channel_layer.group_send(
                         self.room_group_name,
                         {
                              'type': 'player_left',
                              'message': 'A player has closed the game.',
                         }
                    )
                elif close_code == 1000 and len(self.connected_players[self.game_id]) == 1:
                    await self.channel_layer.group_send(
                        self.room_group_name,
                        {
                            'type': 'player_left',
                            'message': 'A player has abandoned the game.',
                        }
                    )
                elif close_code == 1001:
                    await self.channel_layer.group_send(
                        self.room_group_name,
                        {
                            'type': 'player_reject',
                            'message': 'The other player rejected the game.',
                        }
                    )

                # Clean up the room if empty
                if not self.connected_players[self.game_id]:
                    del self.connected_players[self.game_id]

        # Leave the channel group
        await self.channel_layer.group_discard(self.room_group_name, self.channel_name)

    async def receive(self, text_data):
        data = json.loads(text_data)
        action = data.get('action')

        if action == 'player_move':
            # Broadcast the move with player ID
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'player_move',
                    'player': data.get('player'),
                    'move_data': data.get('move_data'),
                }
            )

        if action == 'update_ball':
            # Broadcast ball state to all clients
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'update_ball',
                    'ball_state': data.get('ball_state'),
                }
            )

        if action == 'update_scores':
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'update_scores',
                    'player': data.get('player'),
                    'score': data.get('score'),
                }
            )

    async def player_move(self, event):
        # Send the move to WebSocket clients
        await self.send(text_data=json.dumps({
            'action': 'player_move',
            'player': event['player'],  # Include the player ID
            'move_data': event['move_data'],
        }))

    async def update_ball(self, event):
            # Send ball state to WebSocket clients
         await self.send(text_data=json.dumps({
                'action': 'update_ball',
                'ball_state': event['ball_state'],
         }))

    async def notify_players(self):
        if len(self.connected_players[self.game_id]) == 2:
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'start_game',
                }
            )
        else:
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'player_wait',
                }
            )

    async def update_scores(self, event):
        await self.send(text_data=json.dumps({
            'action': 'update_scores',
            'player': event['player'],
            'score': event['score'],
        }))

    async def start_game(self, event):
        await self.send(text_data=json.dumps({
            'action': 'start_game',
        }))

    async def player_wait(self, event):
        await self.send(text_data=json.dumps({
            'action': 'waiting',
            'message': 'Waiting for the other player to join...',
        }))

    async def player_left(self, event):
        await self.send(text_data=json.dumps({
            'action': 'player_left',
            'message': event['message'],
        }))

    async def player_reject(self, event):
        await self.send(text_data=json.dumps({
            'action': 'player_reject',
            'message': event['message'],
        }))

    async def game_finish(self, event):
        await self.send(text_data=json.dumps({
            'action': 'game_finish',
            'message': event['message'],
        }))

