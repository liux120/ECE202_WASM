import time
import serial
               
ser = serial.Serial(            
    port='/dev/serial0',
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)
ls = ['a ', 'b ', 'c ', 'd ']
for i in range(4):
    '''while(1):'''
    ser.write(ls[i].encode())
    '''ser.write('hello '.encode())'''
    time.sleep(1)

while(1):
    print(ser.read().decode())

