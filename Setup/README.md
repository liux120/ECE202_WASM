# Setup procedure for compilers and runtimes
### Runtimes

Wasmer can be installed on both Intel and ARMv8 based processors. Meanwhile, Wasmtime and WAMR only support Intel processors so far.

Wasmer:
```curl https://get.wasmer.io -sSfL | sh```

Wasmtime:
```curl https://wasmtime.dev/install.sh -sSf | bash```

WAMR:
Follow the [setup](https://github.com/bytecodealliance/wasm-micro-runtime/blob/master/doc/build_wamr.md) provided by the WAMR.

#### Compiler
The compilers we successfully used are Rust, EMSKD and Clang-9. They support Intel based processors but not ARM. The details of each compilers are given below.

Rust:

Rust has its build-in compiler for WASM. We used Cargo, a Rust project managing tool, to compile Rust to WASM. The procedures can be found in [WASI tutorial](https://github.com/bytecodealliance/wasmtime/blob/master/docs/WASI-tutorial.md)

First we create a project, demo.
```$ cargo new --bin demo```

Then, we install the WASI-enabled Rust toolchain and build the project.
``` 
$ rustup target add wasm32-wasi
$ cargo build --target wasm32-wasi
```

Finally, the output WASM code is in the directory, `target/wasm32-wasi/debug`.

