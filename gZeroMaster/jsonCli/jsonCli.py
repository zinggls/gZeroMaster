
import zmq
import json

context = zmq.Context()

print("Connecting to hello world server…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

for request in range(3):
    print("Sending request %s …" % request)

    # Define a string of json data
    raw = '''{  "LNA Gain": 4,
                "Limiting Amplifier Enable": true,
                "RX Data Interface": true
    }'''

    info = json.loads(raw)              # Convert string into a python object
    info_as_jason = json.dumps(info)    # convert python objects to json
    socket.send_json(info_as_jason)

    message = socket.recv_json()
    print("Received reply %s [ %s ]" % (request, message))