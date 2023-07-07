# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ReadMe.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 14:00:44 by lde-sous          #+#    #+#              #
#    Updated: 2023/05/11 16:29:42 by lde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


-----------------------------------------------------------------------------------
THIS IS AN INSTRUCTIONAL FILE TO THREADS
-----------------------------------------------------------------------------------

Threads are function executions that go in paralel with their Thread "sisters".
	ie:
		void *func1()
		{
			printf("start of thread\n")
			sleep(2);
			printf("end of thread\n")
		}

		int main (int ac, char *av)
		{
			pthread_t t1; ->Thread variable
			pthread_t t2;

			if (pthread_create(&t1, NULL, &func1, NULL) != 0) ->Thread create function
				return (1);
			if (pthread_create(&t2, NULL, &func1, NULL) != 0)
				return (2);
			if (pthread_join(t1, NULL) != 0) -> Thread "waiting for sister" function
				return (3);
			if (pthread_join(t2, NULL) != 0)
				return (4);
			return 0;
		}
-----------------------------------------------------------------------------------

Data races are a type of errors that occur when executing heavy work inside threads
that can output wrong results. They happen because of the many steps linux ASSEMBLY
is making when augmenting x.                                           |
	ie:							       |
		x = 0;						       |
								       |
		void *func1()					       |
		{						       |
			i = 0;					       |
			while (i < 1000000)			       |
			{					       |
				x++; -> (ASSEMBLY:         <-----------/
					reads variable x
					increases x
					saves variable x)
				i++;
			}
			printf("x =%d\n", x);
		}
		
		int	main(int ac, char *av)
		{
			pthread_t t1; ->Thread variable
			pthread_t t2;

			if (pthread_create(&t1, NULL, &func1, NULL) != 0) ->Thread create function
				return (1);
			if (pthread_create(&t2, NULL, &func1, NULL) != 0)
				return (2);
			if (pthread_join(t1, NULL) != 0) -> Thread "waiting for sister" function
				return (3);
			if (pthread_join(t2, NULL) != 0)
				return (4);
			return 0;
		}
		
		OUTPUT: x = 1791003 when it should be 2000000. This is a Data Race as the functions
		compete to get the result.
-----------------------------------------------------------------------------------

Mutexes are functions that lock the Threads to protect the results from Data Races.
	ie:
		x = 0;
		pthread_mutex_t	mutex;

		void *func1()
		{
			i = 0;
			while (i < 1000000)
			{
				pthread_mutex_lock(&mutex);
				x++;
				i++;
				pthread_mutex_unlock(&mutex);
			}
		}
		
		int	main(int ac, char *av)
		{
			pthread_t t1;
			pthread_t t2;

			pthread_mutex_init(&mutex, NULL);
			if (pthread_create(&t1, NULL, &func1, NULL) != 0)
				return (1);
			if (pthread_create(&t2, NULL, &func1, NULL) != 0)
				return (2);
			if (pthread_join(t1, NULL) != 0)
				return (3);
			if (pthread_join(t2, NULL) != 0)
				return (4);
			pthread_mutex_destroy(&mutex);
			printf("x = %d", x);
			return 0;
		}
		
		OUTPUT: x = 2000000.
-----------------------------------------------------------------------------------

Optimizing the 'main' function to use many Threads according to norminette:

	int	main(int ac, char *av)
	{
		pthread_t thread[20];
		int	i;

		i = 0;
		pthread_mutex_init(&mutex, NULL);
		while (i++ < 20)
		{
			if (pthread_create(thread[i], NULL, &function, NULL != 0))
			{
				perror("FAILED to create thread");
				return (1);
			}
		}
		i = 0;		
		while (i++ < 20)
		{
			if (pthread_join(thread[i], NULL, &funcion, NULL) != 0)
			{
				perror("FAILED to join threads");
				return (2);
			}
		}
		pthread_destroy_mutex(&mutex);
		printf("x =%d\n", x);
		return (0);
	}
