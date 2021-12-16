import zmq
import json

class gZeroMaster_Lib:
    value_idx = 0
    modify_idx = 1
    def __init__(self, port):
        context = zmq.Context()
        self.gZero_socket = context.socket(zmq.REQ)
        self.gZero_socket.connect("tcp://127.0.0.1:{}".format(port))
        with open("gZeroMaster_JSON.json") as json_file:
            gZero_obj = json.load(json_file)

        self.gZero_reg = dict()
        for mod in gZero_obj:
            self.gZero_reg[mod] = dict()
            for reg in gZero_obj[mod]:
                self.gZero_reg[mod][reg] = [gZero_obj[mod][reg], False]

    def set_register(self, mod, reg, value):
        if ((mod in self.gZero_reg) == True):
            if ((reg in self.gZero_reg[mod]) == True):
                self.gZero_reg[mod][reg] = [value, True]
                return True
        print("Not found register {} in {}".format(reg, mod))
        return False

    def send_command(self):
        gZero_obj = dict()
        for mod in self.gZero_reg:
            gZero_obj[mod] = dict()
            for reg in self.gZero_reg[mod]:
                value, modify = self.gZero_reg[mod][reg]
                if (modify == True):
                    gZero_obj[mod][reg] = value
        gZero_obj = json.dumps(gZero_obj, indent = 4)
        self.gZero_socket.send(gZero_obj.encode())
        self.gZero_socket.recv()

    def send_all_command(self):
        gZero_obj = dict()
        for mod in self.gZero_reg:
            gZero_obj[mod] = dict()
            for reg in self.gZero_reg[mod]:
                gZero_obj[mod][reg] = self.gZero_reg[mod][reg][self.value_idx]
        gZero_obj = json.dumps(gZero_obj, indent = 4)
        self.gZero_socket.send(gZero_obj.encode())
        self.gZero_socket.recv()

    def save_in_csv(self, csv, port):
        for mod in self.gZero_reg:
            for reg in self.gZero_reg[mod]:
                value, modify = self.gZero_reg[mod][reg]
                if (modify == True):
                    csv_data = "{},{},{},0x{:X}\n".format(port, mod, reg, value)
                    csv.write(csv_data)

    def save_all_in_csv(self, csv, port):
        for mod in self.gZero_reg:
            for reg in self.gZero_reg[mod]:
                value, modify = self.gZero_reg[mod][reg]
                #if (modify == True):
                csv_data = "{},{},{},0x{:X}\n".format(port, mod, reg, value)
                csv.write(csv_data)

class Attenuator_Lib:
    def __init__(self, port):
        context = zmq.Context()
        self.Atten_socket = context.socket(zmq.REQ)
        self.Atten_socket.connect("tcp://127.0.0.1:{}".format(port))

    def set_atten(self, dB):
        Atten_obj = dict()
        Atten_obj["ATTEN"] = dict()
        Atten_obj["ATTEN"]["value"] = dB
        Atten_obj = json.dumps(Atten_obj)
        self.Atten_socket.send(Atten_obj.encode())
        self.Atten_socket.recv()
