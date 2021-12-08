import zmq
import json

class gZeroMaster_Lib:
    def __init__(self, port):
        context = zmq.Context()
        self.gZero_socket = context.socket(zmq.REQ)
        self.gZero_socket.connect("tcp://127.0.0.1:{}".format(port))
        
    def json_file_load(self, path):
        with open(path) as json_file:
            self.gZero_obj = json.load(json_file)

    def send_all_command(self):
        json_str = json.dumps(self.gZero_obj)
        self.gZero_socket.send(json_str.encode())
        recv_msg = self.gZero_socket.recv()
        print(recv_msg)

class Attenuator_Lib:
    def __init__(self, port):
        context = zmq.Context()
        self.Atten_socket = context.socket(zmq.REQ)
        self.Atten_socket.connect("tcp://127.0.0.1:{}".format(port))

    def set_atten(self, dB):
        Atten_obj = { "ATTEN":{} }
        Atten_obj["ATTEN"] = dB
        json.dumps(Atten_obj)
