import zmq
import json
#import threading

context = zmq.Context()

class gZeroMaster:
    def __init__(self, port):
        self.gZero_socket = context.socket(zmq.REQ)
        self.gZero_socket.connect("tcp://127.0.0.1:{}".format(port))
        with open("gZeroMaster_JSON.json") as json_file:
            self.gZero_obj = json.load(json_file)

    def send_command(self):
        json_str = json.dumps(self.gZero_obj)
        self.gZero_socket.send(json_str.encode())
        recv_msg = self.gZero_socket.recv()
        print(recv_msg.decode())

class Attenuator:
    def __init__(self, port):
        self.Atten_socket = context.socket(zmq.REQ)
        self.Atten_socket.connect("tcp://127.0.0.1:{}".format(port))

    def send_command(self, dB):
        dB = str(dB)
        send_msg = "{ \"ATTEN\" : { \"value\": " + dB + " } }"
        self.Atten_socket.send(send_msg.encode())
        recv_msg = self.Atten_socket.recv()
        print(recv_msg.decode())

gZero = gZeroMaster(5555)
Atten = Attenuator(12345)

while True:
    data = input()
    if (data == "1"):
        print("HELLO")
        
        gZero.send_command()
    elif (data == "2"):
        print("HI")
        Atten.send_command(1)
