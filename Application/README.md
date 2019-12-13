# The application of mouse reading

This application is built based on a socket transmission (in Python) and a system file reading (in WASM). There are 3 steps in this application. First, the Pi sends the WASM code to the PC. The code is used to read a file from the Linux system and copy all the data into  another file (output.txt in our case).

Then, the WASM program is run by Wasmtime. It reads the mouse input and saves all the data into the output.txt. Finally, another socket connection is established, and the output.txt is snet to the Pi. In such way, the Pi requests and receives the information of the mouse movement from the Linux-based PC.

To Run the code with one commend of line. Do as the following.

```
# Pi Terminal
$ python3 server.py 40000 192.168.50.38 copy.wasm \
    && python3 client.py 50000 192.168.50.2 input.txt \
    && od -t x1 input.txt

# PC Terminal
$ python3 client.py 40000 192.168.50.38 received.wasm \
    && sudo chmod -o+rw /dev/input/mice \
    && wasmtime --dir=. --dir=/dev/input received.wasm /dev/input/mice output.txt \
    && python3 server.py 50000 192.168.50.2 output.txt
```

Note that at the PC side, `sudo chmod -o+rw` is required for the access to system files.

The results are shown in the figures.

<img src="https://github.com/liux120/ECE202_WASM/blob/master/Application/mouse_read_pi.png" width="450">
<img src="https://github.com/liux120/ECE202_WASM/blob/master/Application/mouse_read_linux.png" width="450">
