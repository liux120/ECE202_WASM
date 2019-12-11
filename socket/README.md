wasmtime read mouse input:
`sudo chmod -o+rw /dev/input/mice && wasmtime --dir=. --dir=/dev/input read.wasm /dev/input/mice`

socket:
server...
`python3 server.py <port number> <server ip address>`
and enter the file
client...
`python3 server.py <port number> <server ip address>`
