wasmtime read mouse input:
`sudo chmod -o+rw /dev/input/mice && wasmtime --dir=. --dir=/dev/input read.wasm /dev/input/mice`
