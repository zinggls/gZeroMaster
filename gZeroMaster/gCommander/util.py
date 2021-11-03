import zmq

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
