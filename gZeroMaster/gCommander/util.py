import zmq
import json

def readData(path):
    f = open(path,'r')
    data = f.read()
    f.close()
    return data

def connect(addr):
    context = zmq.Context()
    socket = context.socket(zmq.REQ)
    socket.connect(addr)
    return socket

def jsonLoad(path):
    with open(path) as json_file:
        json_data = json.load(json_file)
        return json_data
