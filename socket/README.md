wasmtime read mouse input:
`sudo chmod -o+rw /dev/input/mice && wasmtime --dir=. --dir=/dev/input read.wasm /dev/input/mice`

socket:
server...
`python3 server.py <port number> <server ip address>`
and enter the file
client...
`python3 server.py <port number> <server ip address>`

Example:
WASM read mouse
Pi: `pytho3 server.py 60000 192.168.50.38 read.wasm`

Linux: `python3 client.py 60000 192.168.50.38 && sudo chmod -o+rw /dev/input/mice && wasmtime --dir=. --dir=/dev/input received.wasm /dev/input/mice`

