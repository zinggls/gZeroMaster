
import zmq

context = zmq.Context()

print("Connecting to hello world server…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

for request in range(3):
    print("Sending request %s …" % request)

    # Define a string of json data
    raw = (r'{ "RX": {  '
                        r'"LNA Gain": 4,'
                        r'"Limiting Amplifier Enable": true,'
                        r'"RX Data Interface": true'
                        r'} }')

    socket.send_string(raw);
    message = socket.recv_string()
    print("Received reply %s [ %s ]" % (request, message))