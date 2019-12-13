# Sample codes tested on PC and Pi

## WAT Programs
Writing WASM text format code is the most direct way to get a WASM program, since no compiler is included. We can simply compile it using the function `wat2wasm` provided by node.js. To run the code, however, a javascript program is in need to provide a environment to run the WASM code. Using the [runwasm.js](https://github.com/liux120/ECE202_WASM/blob/master/Samples/Run_on_Node.js/runwasm.js), we can run a function in WASM.

```
$ node ./runwasm.js <wasmFile.wasm> <function name> arg1 arg2 ...
```

## Fundamental Functions from Rust/C/C++

We wrote Rust/C/C++ programs for 'hello world' and 'file copying'. We have tested the code with Wasmer and Wasmtime. The fundamental functions can be run on both PC and Pi, but reading and writing to file can only work on Pi. To run the code, a standard way is given in the following. Detailed explanation is given in the [Wasmtime tutorial](https://github.com/bytecodealliance/wasmtime/blob/master/docs/WASI-tutorial.md).

```
# for computational program
$ wasmer <yourProgram.wasm>
$ wasmtime <yourProgram.wasm>

# for reading and writing file
$ wasmer --dir=. --dir=<path to the files> <yourProgram.wasm> arg1 arg2 ...
$ wasmtime --dir=. --dir=<path to the files> <yourProgram.wasm> arg1 arg2 ...
```

Since WASM requires a sandbox as its environment, we need `--dir=` to include all the files used in the program. Note that if we want to read system files, e.g. `proc` or `/dev`, only Wasmtime is available. Wasmer has no access to those files yet.
