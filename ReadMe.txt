README

Class:              CSE 321 Term Project
Date:               12/02/2023
Collaborators:      Tyler Rutley, Frankie Peretti

--------------------------------------------------------------
                        RC SmartCar
--------------------------------------------------------------


COMPONENTS AND SOFTWARE
-----------------------

  * RC Smart Car
    * Arduino UNO
    * Adafruit Motor Shield V2
    * Battery Holder
    * AA Batteries (x4)
    * Car Base
    * Ultrasonic Distance Sensor (x2)
    * DC Gear Motors (x4)
    * Wheels (x4)
  
  * USB-A to USB-B wire

  * 10ft USB-A Male to Female wire

  * Arduino IDE code file (rcSmartCar.ino)

  * Python code file (smartRCCar_python.py)


HARDWARE SETUP
--------------

    * Stack Motor Shield on top of the Arduino
    * Connect the motors to the wheels
    * Connect the motors to the motor shield
    * Place 4 AA batteries in the battery holder
    * Connect battery holder terminals to the motor shield power
    * Attatch Arduino Vcc 5V to the Vcc of both distance sensors
    * Attach ground of both distance sensors to Arduino ground

    * For the front distance sensor
        * Connect Echo Pin to Pin 10
        * Connect Trig Pin to Pin 9

    * For the back distance sensor
        * Connect Echo Pin to Pin 11
        * Connect Trig Pin to Pin 12

    *Plug USB-A to USB-B to USB extenstion cable
    *Finally, connect extenstion into computer


SOFTWARE SETUP
--------------

    * Download Python for terminal usage
  
    * Type these commands into terminal command line
      * pip install pyserial[^1]
      * pip install pynput[^2]
  
    * Open Arduino code file (rcSmartCar.ino) 
  
    * Compile and Upload Arduino code file to Arduino UNO on RC SmartCar
  
    * Run Python code file on terminal command line (smartRCCar_python.py)
      * python ./smartRCCar_python.py
  
    * Press keys in terminal after running python file to move the RC SmartCar
      * Use W, A, S, and D keys to move the car fowards, left, right, and backwards respectively
  
    * Type Ctrl+C (^C) in terminal to terminate the program

REFERENCES
----------

    *[^1][Pyserial Documentation](https://pyserial.readthedocs.io/en/latest/pyserial.html#overview)
    *[^2][Pynput Documentation](https://pynput.readthedocs.io/en/latest/keyboard.html#monitoring-the-keyboard)
    *[Arduino Documentation](https://www.arduino.cc/reference/en/)
