# Setup procedure for compilers and runtimes
## Runtimes

Wasmer can be installed on both Intel and ARMv8 based processors. Meanwhile, Wasmtime and WAMR only support Intel processors so far.

#### Wasmer:
```$ curl https://get.wasmer.io -sSfL | sh```

#### Wasmtime:
```$ curl https://wasmtime.dev/install.sh -sSf | bash```

#### WAMR:
Follow the [setup](https://github.com/bytecodealliance/wasm-micro-runtime/blob/master/doc/build_wamr.md) provided by the WAMR.

## Compiler
The compilers we successfully used are Rust, EMSKD and Clang-9. They support Intel based processors but not ARM. The details of each compilers are given below.

#### Rust:

Rust has its build-in compiler for WASM. We used Cargo, a Rust project managing tool, to compile Rust to WASM. The procedures can be found in [WASI tutorial](https://github.com/bytecodealliance/wasmtime/blob/master/docs/WASI-tutorial.md)

First we create a project, demo.
```$ cargo new --bin demo```

Then, we install the WASI-enabled Rust toolchain and build the project.
``` 
$ rustup target add wasm32-wasi
$ cargo build --target wasm32-wasi
```

Finally, the output WASM code is in the directory, `target/wasm32-wasi/debug`.

#### EMSDK
EMSDK is an official compiler for C/C++ to WASM. The [setup](https://emscripten.org/docs/getting_started/downloads.html) is given in their document. The procedures is,

```
# Get the emsdk repo
$ git clone https://github.com/emscripten-core/emsdk.git

# Enter that directory
$ cd emsdk

# Fetch the latest version of the emsdk (not needed the first time you clone)
$ git pull

# Download and install the latest SDK tools.
$ ./emsdk install latest

# Make the "latest" SDK "active" for the current user. (writes ~/.emscripten file)
$ ./emsdk activate latest

# Activate PATH and other environment variables in the current terminal
$ source ./emsdk_env.sh

# compile the code
$ emcc demo.c -o demo.wasm
```

#### Clang
Clang-9 is equiped with LLVM for compiling the C code into WASM. [Here](https://solarianprogrammer.com/2017/12/13/linux-wsl-install-clang-libcpp-compile-cpp-17-programs/) is a tutorial for installation.

To make Clang work, we need to direct it to a WASI library, which is called [wasi-sdk](https://github.com/CraneStation/wasi-sdk/releases). After we download the library, we need to add it to our path.

```
export WASI_SYSINTERFACE_HOME="$HOME/path-to/wasi-sdk"
export PATH="$WASI_SYSINTERFACE_HOME/bin:$PATH"
export WASI_SYSROOT="$WASI_SYSINTERFACE_HOME/share/wasi-sysroot"

```

Once the path is added, we can compile c code into WASM. Note that we need to use `--sysroot` to direct to the library where the wasi-sdk is located.
```
$ clang demo.c --sysroot <path to sysroot> -o demo.wasm
```
