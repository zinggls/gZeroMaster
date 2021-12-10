import time
import json
import zmq
import serial
import serial.tools.list_ports
from functools import partial
import threading
import tkinter
from tkinter import ttk

root = tkinter.Tk()
rx_thread_flag = 0
dp_list = []
comm_serial = None
atten_value = None
root_frame = tkinter.Frame(root)
comm_frame = tkinter.Frame(root_frame)
atten_frame = tkinter.Frame(root_frame)
comm_init = False

def zmq_server_init():
    context = zmq.Context(1)

    socket = context.socket(zmq.REP)
    server = socket.bind("tcp://127.0.0.1:12345")

    return socket

def zmq_atten(value):
    global dp_list, atten_value, comm_serial
    result = int(value / 2)
    if (result > 7):
        result += 4

    for i in range(4):
        bit = (result >> i) & 0b0001
        if (bit == True):
            dp_list[i].select()
            data = bytearray([0x7A, 0xD2 + i, 0x01, 0xEA])
        else:
            dp_list[i].deselect()
            data = bytearray([0x7A, 0xD2 + i, 0x00, 0xEA])
        #print(data)
        comm_serial.write(data)
    atten_value.configure(text = "{}".format(value))
    
        
def zmq_server_start(socket):
    global rx_thread_flag
    while True:
        json_msg = socket.recv()
        json_obj = json.loads(json_msg.decode())
        atten = json_obj.get("ATTEN")
        if atten == None:
            error_msg = "not found command"
            socket.send(error_msg.encode())
        else:
            value = atten.get("value")
            if (value % 2 == 0 and value <= 22 and value >= 0) == True:
                if (rx_thread_flag == 1):
                    zmq_atten(value)
                    ack_msg = "complete"
                    socket.send(ack_msg.encode())
                else:
                    error_msg = "serial is not opened yet"
                    socket.send(error_msg.encode())
            else:
                error_msg = "wrong value"
                socket.send(error_msg.encode())

def serial_rx():
    global rx_thread_flag, comm_serial, comm_init
    
    while rx_thread_flag:
        if (comm_serial.read(2)).decode() == "Hi":
            comm_init = True

def comm_connect(port, combobox, button):
    global rx_thread_flag, comm_serial, dp_list, comm_init
    
    baud_rate = 9600
    comm_serial = serial.Serial(port, baud_rate)
    button.configure(text = "Disconnect", command = lambda: comm_disconnect(combobox, button))
    """
    for dp in dp_list:
        dp.configure(state = tkinter.NORMAL)
    """
    
    rx_thread_flag = 1
    threading.Thread(target = serial_rx, daemon = True).start()

    while comm_init != True:
        time.sleep(1)

def comm_disconnect(combobox, button):
    global rx_thread_flag, comm_serial, dp_list

    rx_thread_flag = 0
    comm_serial.close()
    button.configure(text = "Connect", command = lambda: comm_connect(combobox.get(), combobox, button))
    for dp in dp_list:
        dp.configure(state = tkinter.DISABLED)

def gui_comm():
    grid_pad_x = 5
    grid_pad_y = 0
    ports = []
    port_list = serial.tools.list_ports.comports()
    for i in port_list:
        ports.append(i.device)

    label = tkinter.Label(comm_frame, text = "COM Port")
    label.grid(row = 0,  column = 0, padx = grid_pad_x, pady = grid_pad_y)

    combobox = ttk.Combobox(comm_frame, values = ports, width = 7)
    combobox.configure(state = "readonly")
    combobox.set(ports[0])
    combobox.grid(row = 0, column = 1, padx = grid_pad_x, pady = grid_pad_y)

    button = tkinter.Button(comm_frame, text = "Connect", command = lambda: comm_connect(combobox.get(), combobox, button))
    button.grid(row = 0, column = 2, padx = grid_pad_x, pady = grid_pad_y)    

def atten_result(attn):
    if (attn > 7):
        attn -= 4
    value = attn * 2
    return value

def atten(dpin, var):
    global dp_var, comm_serial, atten_value
    var = var.get()
    atten_dB = 0
    count = 0
    if (var == True):
        if (dpin != 4):
            data = bytearray([0x7A, 0xD2 + dpin, 0x01, 0xEA])
        else: # LE
            data = bytearray([0x7A, 0xDE, 0x01, 0xEA])
    else:
        if (dpin != 4):
            data = bytearray([0x7A, 0xD2 + dpin, 0x00, 0xEA])
        else: # LE
            data = bytearray([0x7A, 0xDE, 0x00, 0xEA])
    for dp in dp_var:
        if (count != 4):
            if (dp.get() == True):
                atten_dB += 0b0001 << count
        count += 1
        
    result = atten_result(atten_dB)
    atten_value.configure(text = "{}".format(result))
    #comm_serial.write(data)
    print(data)

def gui_atten():
    global dp_var, dp_list, atten_value
    
    dp_label = [ "D2", "D3", "D4", "D5", "LE" ]
    dp_var = [ tkinter.BooleanVar(), tkinter.BooleanVar(), tkinter.BooleanVar(), tkinter.BooleanVar(), tkinter.BooleanVar() ]
    c = 0
    for label in dp_label:
        dx_label = tkinter.Label(atten_frame, text = label)
        dx_label.grid(row = 0, column = c)
        dx_btn = tkinter.Checkbutton(atten_frame, variable = dp_var[c], state = tkinter.DISABLED, command = partial(atten, c, dp_var[c]))
        dx_btn.grid(row = 1, column = c)
        dx_btn.select()
        dp_list.append(dx_btn)
        c += 1

    dp_list[4].select()

    atten_label = tkinter.Label(atten_frame, text = "Atten (dB)")
    atten_label.grid(row = 0, column = c)
    atten_value = tkinter.Label(atten_frame, text = "0")
    atten_value.grid(row = 1, column = c)

def gui_place_frame():
    root_frame.grid(row = 0, column = 0)
    comm_frame.grid(row = 0, column = 0)
    atten_frame.grid(row = 1,  column = 0)

def main():
    socket = zmq_server_init()
    threading.Thread(target = zmq_server_start, args = [socket], daemon = True).start()

    gui_place_frame()
    gui_comm()
    gui_atten()
    
    root.mainloop()

if __name__ == "__main__":
    main()
