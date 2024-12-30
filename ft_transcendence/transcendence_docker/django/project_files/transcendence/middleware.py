from django.shortcuts import redirect

class Custom404Middleware:
    def __init__(self, get_response):
        self.get_response = get_response

    def __call__(self, request):
        response = self.get_response(request)
        if response.status_code == 404:
            return self.handle_404(request)
        return response

    def handle_404(self, request):
        # Redirect to the homepage
        return redirect('/')
