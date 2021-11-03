import zmq

context = zmq.Context()

print("Connecting to gZeroMaster…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

# Define a string of json data
raw = ( r'{ "RX": {  '
                    r'"LNA Gain": 4,'
                    r'"Limiting Amplifier Enable": true,'
                    r'"RX Data Interface": true'
                r'}'
        r'}')

socket.send_string(raw);
print("Response:%s" %socket.recv_string())