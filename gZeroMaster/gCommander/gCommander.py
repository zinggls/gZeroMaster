import zmq

context = zmq.Context()

print("Connecting to gZeroMaster…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

f = open("..\\tests\\rx.json",'r')
data = f.read()
f.close()

socket.send_string(data);
print("Response:%s" %socket.recv_string())