import serial
from pynput import keyboard
import threading
import time
import sys


ser = serial.Serial('COM4', 9600)

distance=0
distance2=0

key_states = {'w': False, 'a': False, 's': False, 'd': False, 'x':False}

def send_command(command):
    ser.write(command.encode())

def key_monitor():
    while True:
        for key, is_pressed in key_states.items():
            if is_pressed:
                send_command(key)
                time.sleep(0.1) 

def on_key_press(key):
    try:
        key_pressed = key.char
        if key_pressed in key_states:
            key_states[key_pressed] = True
            send_command(key_pressed)
    except AttributeError:
        pass  

def on_key_release(key):
    try:
        key_released = key.char
        key_states[key_released] = False
        send_command('x') 
    except AttributeError:
        pass 

with keyboard.Listener(on_press=on_key_press, on_release=on_key_release) as listener:
    monitor_thread = threading.Thread(target=key_monitor, daemon=True)
    monitor_thread.start()

    try:
        while True:

            if ser.in_waiting > 0:
                arduino_data = ser.readline().decode().strip()
                
                if arduino_data.startswith("1:"):
                    try: distance = int(arduino_data.split(":")[1])

                    except:distance=0
                
                if (distance < 200):
                    send_command('x')

                if arduino_data.startswith("2:"):
                    try: distance2 = int(arduino_data.split(":")[1])
                    
                    except:distance2=0
                
                if (distance2 < 200):
                    send_command('x')
            time.sleep(.5) 
    
    except KeyboardInterrupt:
        ser.close()
        print("\nScript interrupted. Exiting...")
        sys.exit(0)  
