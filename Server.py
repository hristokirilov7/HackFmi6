import RPi.GPIO as GPIO
import time
import SocketServer
#import test_relay
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

class MyTCPHandler(SocketServer.BaseRequestHandler):
    """
    The RequestHandler class for our server.

    It is instantiated once per connection to the server, and must
    override the handle() method to implement communication to the
    client.
    """

    def handle(self):
        # self.request is the TCP socket connected to the client
        self.data = self.request.recv(1024).strip()
        print "{} wrote:".format(self.client_address[0])
        print self.data
        # just send back the same data, but upper-cased
        self.request.sendall(self.data.upper())
        if self.data == 'forward' :
         #   execfile('Car.cpp')
		    from subprocess import call
		    call(["./forward", "args", "to", "forward"])
        elif self.data == 'backward' :
            from subprocess import call
            call(["./backward", "args", "to", "backward"])
        elif self.data == 'left' :
            from subprocess import call
            call(["./left", "args", "to", "left"])
        elif self.data == 'right' :
            from subprocess import call
            call(["./right", "args", "to", "right"])
        else self.data == 'stop' :
            from subprocess import call
            call(["./stop", "args", "to", "stop"])
if __name__ == "__main__":
    HOST, PORT = "10.0.201.48", 5011

    # Create the server, binding to localhost on port 9999
    server = SocketServer.TCPServer((HOST, PORT), MyTCPHandler)

    # Activate the server; this will keep running until you
    # interrupt the program with Ctrl-C
    server.serve_forever()
