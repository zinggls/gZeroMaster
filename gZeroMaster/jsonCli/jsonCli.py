
import zmq
import json

context = zmq.Context()

print("Connecting to hello world server…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

for request in range(3):
    print("Sending request %s …" % request)

    # Define a string of json data
    raw = r'{ "RX": {  "LNA Gain": 4, "Limiting Amplifier Enable": true, "RX Data Interface": true } }'

    socket.send_string(raw);
    message = socket.recv_string()
    print("Received reply %s [ %s ]" % (request, message))