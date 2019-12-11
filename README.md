# ECE202 WASM for IoT Devices
This is a course project of EE202 embedded system. The group members are Ximeng Liu and Yiru Wang.
Project #11 Framework to Expose IoT Sensor and Actuator Services.

## Abstract  
WebAssembly, also know as Wasm, is a binary instruction format for a stack-based virtual machine. WebAssembly is originally designed for the compilation of high-level languages and deployed on the Web for client and server applications. It can run large, complex applications on the web and brings predictable performance to the web platform. Nowadays, developers are starting to push WebAssembly beyond the browser, since it provides a fast, scalable, and secure way to run the same code across all machines. In this project, members implemented WASM with and without the browser on Raspberry Pi (B+) and laptops (Windows, Linux, macOS). Members also tested various WASM under heterogeneous settings. The rest of this report is constructed as follows: Section I, providing basic introduction and theoretical backgrounds of WebAssembly; Section II, introducing test environment; Section III, Analyzing; Section IV, future and conclusion.

## I. Intruduction
Designed by W3C Community Group, WebAssembly is a new web compilation method which can be encoded in a size/load-time-efficient binary format, aming to execute at native speed by taking advantage of common hardware capabilities available on wide range of platforms. WebAssembly is initially designed to run on the Web, though the non-web embeddings of WebAssembly are also desirable for executing well in other environments, such as minimal testing shells and advanced application environments. 
Since the very first WebAssembly just appeared in March 2017, there are only a few non-browsor implantation has been made. A plug-and-play WebAssembly-Orientated software or hardware is not available either. Most of the existing WebAssembly platforms are developed in highly customized settings with minor overlapping with each other. (More detail on WASM runtime). Briefly, the objective of this project is to construct a preliminary result on characterizing the implentation of WebAssembly runtimes on different platforms(ARMs,x86). The result is drawn from the comparison of distinct runtimes crossmatching with different compilers and coding languages. In the future, a standardized WebAssembly runtime can implement with actuators, such as sensors and cameras. A framework combined with DDFlow and RemedIot may tend to be accomplished. (A demonstration of future application may be present).

## II. Non-Web Environments
WebAssembly requires additional tools in order to function in the non-web environments. In this project, members explored following tools in the order as listed. (expend)

### Emscripten
Emscripten Toolchain is the first tool for producing WebAssembly, which emulates a particular OS system interface on the web. It allows developers using functions from the C standard libnrary(libc). Emscipten SDK is required to specify setting of tools including Emscripten Compiler Frontend (emcc). Emcc is a drop-in replacement for a standard compiler like gcc. Emcc uses Clang and LLVM to compile to wasm or `asm.js`, producing JavaScript which can run the compihttps://unix.stackexchange.com/questions/117037/how-to-send-data-to-a-serial-port-and-see-any-answerled code and provide the necessary runtime support. This JavaScript can be executed by `node.js` or form within HTML in a browser. When using emcc to build to WebAssembly, the output contains both `.wasm` and `.js` file. Both of two files are required to work together as most WebAssembly currently depends on a JavaScript runtime. The `.js` file loads and sets up imports/exports for WebAssembly code. In this case, the `.wasm` is not standalone, meaning it cannot be easily configuried and excuted withour `.js` code. In this project, trying to avoid JS runtime, memebrs extracted a standalone `.wasm` file from `$ emcc source.c -s STANDALONE_WASM` and `$ emcc source.c -o output.wasm` (requires LLVM wasm backend). The standalone `.wasm` file is used for other runtimes such as Wasmer and wasmtime, which will be discussed later.

### LLVM
LLVM Project is a collection of modular and reusable compiler and toolchain technologies. Unlike the Emscripten which includes additional tools and libraries to support whole C/C++ codebases, LLVM toolchain acts more like a compiler which currently has the most support for compiling high level programing language (C) to WebAssembly. The LLVM Core libraries are built around the LLVM intermediate representaion (LLVM IR) which can understand and optimize the compilation process. A native C compiler, called Clang, is used at the front-end to compile C to the LLVM IR. In this project, members used Clang to compile `source.c` to `ouputC.wasm`. The `outputC.wasm` repersents `.wasm` files originally written in C.

### JavaScript VMs (Node.js)
Javascrip is a widely used programming language of HTML and the Web. It provides WebAssembly JavaScript API to load and run the WebAssembly module inside a `.js` file. Although it is supposed to be run with browers primarily, it can actually run the WebAssembly functions without browsers by using Node.js. As given by the Wikipedia, Node.js is an open-source, cross-platform, JavaScript runtime environment that executes JavaScript code outside of a browser. In practise, we first load the WebAssembly module inside the JavaScript file by using `imports`. Then we load the `.wasm` file and read the function to run. We pass the parameters in the terminal as the following format, `./runwasm.js prog.wasm func INT_ARG...`. The testing files are given in the [jsRun](https://github.com/liux120/ECE202_WASM/tree/master/jsRun).  

### WebAssembly Runtimes
All runtimes support three mainstrain platforms, Linux, macOS, Windows.

Names | Wasmer | WAMR | Wasmtime | WASMO
:---: | :---: | :---: | :---: | :---:
Language | Rust, C/C++ | C | Rust, C/C++ | Rust
Compiler | Carnelift, Dynasm.rs, LLVM| Custom | Carnelift | LLVM
Host APIs | Emscripten | N/A | WASI | N/A 
Pkt manager | Wapm | N/A | WASI | N/A 
Build succeed | Y | Y | Y | S 
`cowsay.wasm` passed | Y | N | Y | N 
`math.wasm` passed | Y | N | Y | N 

#### WebAssembly Micro Runtime (WAMR)
[WAMR](https://github.com/bytecodealliance/wasm-micro-runtime) is a small footprint standalone WebAssembly runtime which includes a WebAssembly VMcore (iwasm), a supporting API, and a application dynamic management mechanism. It is the first runtime explored by members.

#### Wasmer
[Wasmer](https://github.com/wasmerio/wasmer) is a non-browser standalone WebAssembly runtime which supports WASI and Emscripten. It can be implemented in x86 and ARM devices, embedded in various languages (Rust, C/C++,, Python, Go, Ruby, etc). It is the most comperhensive runtime been explored by members so far.

#### Wasmtime
[Wasmtime](https://github.com/bytecodealliance/wasmtime), developed by moz://a group, is a standalone wasm-only optimizing runtime specificly for WebAssembly and WASI, which can be used as a command-line utiltiy and a library embedded in a larger application. It supports Rust, C/C++.

## III. WebAssembly System Interface
WebAssembly is considered as an assembly language for a conceptual machine and has the capability of running across all different OSs. WebAssembly is a language does not have direct access to manage files on most operation systems due to stability and security. One solution is to use kernel which sets the barrier between the user's program and the system's core resource. Kernal allows users to access resources through a system call. Since each operating system may have unique system calls, most programming languages provide a standard library that acts as an interface. Upon compiling, toolchains select interface implementation based on targeting system's API. A system interface for WebAssembly, therefore, is necessary. The core of the WebAssembly system interface contains the most fundamental modules used for WebAssembly. It contains basic principles that all programs need, such as portability. The WebAssembly system interface can compile the same source code once and allow the source code running across various devices. WebAssembly system interface is more secure since it provides a sandbox where browsers or runtimes put functions in. The sandbox equipped with file descriptors requires additional permissions. In this project, members discovered WebAssembly runtimes based on the concepts of WebAssembly system interface.

### WASI-API
In this project, members mainly interact with the WASI-API, a family of APIs designed by the Wasmtime project, that proposed as a standard-independent non-Web system-oriented API for WebAssembly. In the browser environment, WebAssembly interacts with the system using the existing Web APIs bundled with browsers. However, there is currently no standard set of APIs that support WebAssmebly programs on different platforms. The WASI-API is created to implement WebAssembly programs on multiple platforms and depend on browser functionality. The core of WASI-API ([WASI Core](https://github.com/bytecodealliance/wasmtime/blob/master/docs/WASI-api.md)) is derived from CloudABI and POSIX. Members have run some system calls provided on macOS and Raspberry Pi.

### POSIX
Portable Operating System Interface (POSIX) is an IEEE standard designed to facilitate application portability. It is can be used among a large family of Unix derivatives including Linux and macOS. In this project, the WASI-API mostly follows the POSIX such as system-call functions.

## IV. Analysis Results
This section presents what the members have accomplished in this project. The process of this project can be considered as the following two steps: Compilation of source files and Execution of target files. Each process has been done on multiple ARM and x86 devices with different OS, including two Raspberry Pi (ARMv7, ARMv8) with Raspain and Monjaro; and three laptops with Linux, macOS, and Windows10. The following table listed the over-all results of each process. The rest of this section describes the result in detail.

Devices|Operation System|Compilation (Failed/Succeeded)|Execution (Failed/Succeeded)
:---:|:---:|:---:|:---:
Raspberry Pi 3B+ (ARMv7)|Raspain|---|---
Raspberry Pi 4B+ (ARMv8)|Raspain (32/64bit)|F|S
|-|Monjaro 64bit|F|S
Macbook pro (x86-darwin)|macOS Catalina|S|S
HP (x86)|Windows10|S|S
PC (x86)|Ubuntu Linux|S|S

### Compile C/C++ into WebAssembly
This part describes the compilation of source file written in C/C++ into target file written in WebAssembly. In this project, members mainly used two compilers that currently supports WebAssembly, Emscripten(emcc) and LLVM(clang).

#### Cowsay
In this project, members initially used a pre-existed WebAssembly program called [Cowsay](https://wapm.io/package/cowsay) to verify the implementation of each runtimes. `cowsay.wasm` generates ASCII pictures of an animal with a message, both of which are defined specificly by users. Since `cowsay.wasm` is originally from Rust implementation, it is assumed to be optimized and bug-free in Rust-based runtime.
* `cowsay.wasm` is pre-existed, therefore, it doesn't need to be compiled (compiled successed).

#### Hello World files
The hello world files are wrote by members to demostrate basic input and output functions in the system terminal. In this step, members surprisedly realized that both `emcc` and `clang` do not support `stdio.h` out-of-box. The solution is either writing a self-defined `stdio.h` or using the wasi-core provided bu wasmtime project.
* `hello.c` & `hello_c.wasm`: Hello world fucntion uses `stdio.h` writen in C. Compiled successed.
* `hello.cpp` & `hello_cpp.wasm`: Hello world fucntion uses `<iostream>` writen in C++. Compiled successed.

#### Math.h functions
The math files contains functions from `math.h` header file. Members wrotes some simple math functions to demostrate basic algorithm capibility of WebAssembly program.
* `math.cpp` & `math_cpp.wasm`:functions that uses `math.h` writen in C++. Compiled successed.

#### WASI-SDK-8
The wasi-sdk contains most of the APIs, header files, and functions used by C and partially used by C++. It is optimized to used on wasmtime. Some of the system-call functions are not support on wasmer. In this part, all files are compiled using `clang-9`, since `emcc` does not support wasi-core. It requires the commond `clang-9 source.c --sysroot /Users/yiruwang/Documents/202/wasi-sdk/share/wasi-sysroot/ -o target.wasm`.
* `wasi_project` folder contains `.c` and `.wasm` file compiled useing clang-9 by specificlly defined sysroot that use the wasi-sdk.

### ARMv7L / ARMv8 (Raspberry Pi B+)
This part is the implementation of WebAssembly on ARM devices, following by the excution results of each platform.

#### Compilers
Members tested the compilers Emscripten and Rust. Emscripten SDK is an official toolkit to generate `.wasm` from C/C++. However, it is not well-delevoped and have failed to be installed onto the Arm7L devices. Members followed the instruction `./emsdk install latest` and get the error: `Error: 'sdk-releases-upstream-b024b71038d1291ed7ec23ecd553bf2c0c8d6da6-64bit' is only provided for 64-bit OSes.` Since Arm7L uses 32-bit instruction set, it is not possible to install the Emscripten compiler onto the Raspberry Pi B+. However, since the Arm8 is a 64-bit processer, it may be able to run the SDK. Besides, members also tested the Rust compiler since it has a build-in compiler for WebAssembly. Members followed the [tutorial](https://github.com/bytecodealliance/wasmtime/blob/master/docs/WASI-tutorial.md) in the Wasmtime and when tried to build the project by `cargo build --target wasm32-wasi`, members have the error `error: linker rust-lld not found`, which is an unsolved issue within the Rust compiler. After all, members haved tried to generate `.wasm` file from C and Rust, but members failed for both. The main issue here is that the compilers work for particular processers' architectures and the Arm7L is not yet included in their development. Thus, if members want to use these compilers, we may need to wait until they are further developed.

#### Directly Write WAT
Since the compilers cannot work on the Arm7L architectures, we tried to write WabAssembly code by ourselves. Though it is almost impossible to directly write `.wasm` code due to its binary format, we can write `.wat` code which is called WebAssembly Text (WAT). It can be translated into `.wasm` by a simple function `wat2wasm` provided Node.js. We followed the [WebAssembly Literacy](https://developer.mozilla.org/en-US/docs/WebAssembly/Understanding_the_text_format) and tried the fundamental functions with the help of `Node.js`. The `.wasm` programs are successfully run and the demos are in [jsRun](https://github.com/liux120/ECE202_WASM/tree/master/jsRun). We succeeded in fundamental arithmetics, loop, condition, arrays, and recursion. However, due to the complexity of writing WAT, we are not able to do further tests.

#### WAMR
Due to the different processer's architecture, the WAMR cannot run properly in the Raspberry Pi B+. When we try to build the runtime, there are several problems showing up.
`make[2]: *** [CMakeFiles/vmlib.dir/build.make:63: CMakeFiles/vmlib.dir/home/pi/runTime/wasm-micro-runtime/core/iwasm/runtime/platform/linux/wasm_native.c.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:110: CMakeFiles/vmlib.dir/all] Error 2
make: *** [Makefile:130: all] Error 2`

#### Wasmer
Wasmer provides runtime for Intel processers but not for the Arm7L. As we tried to install the runtime by `curl https://get.wasmer.io -sSfL | sh`, we have the error: `The system architecture (armv7l) is not supported by this installation script.`. It is said to be further developed for IoT devices, so the arm architectures may be available in their future version. On Nov.17th, wasmer announced that it supports the Rapsbarry Pi 4B+ (Armv8). Members tried to install wasmer following the guildline, however, the wasmer does not support on defalut Raspain 32bit or its 64bit kernal. Members later tried on Mojaro, and successfully installed wasmer. 

#### Wasmtime
To build the Wasmtime, members first used `git pull` their source files and then build their rust program by `cargo build --release`. Similar to Wasmer, the build failed with error: `error: could not compile wasi-common`. Besides, it has issue with some other packages, like `unicode-xid`, `libc`, `proc-macro2` and `cc`. This error seems to be the issue of its 32-bits instruction set. Later, memebrs used `curl https://wasmtime.dev/install.sh -sSf | bash`. The result shows the Wasmtime currently does not support on ARM.

### Intel x86 (Macbook pro and Windows/Ubuntu PC)
#### WAMR
Members first tried to build WAMR by following the [Build WAMR Core](https://github.com/bytecodealliance/wasm-micro-runtime/blob/master/doc/build_wamr.md). WAMR core is able to be build successfully on both Mac and PC. However, it can not run `cowsay.wasm` or `hello_c.wasm` or `test.wasm` file. Error:`Read file to buffer failed: open file test.wasm failed.`
* cowsay execution failed.
* hello world function execution failed.

#### Wasmer & Wasmtime
Wasmer and Wasmtime is able to be build successfully on all of the x86 devices. It supports cowsay, math.h, and wasi_sdk funcitons. However, using different compilers tend to affect the reslut.
* `hello_c.wasm` execution successed with self-defined header file `stdio.h` using `emcc` and `wasi-core` with `clang-9`. However, it can not execute if the`.wasm` file is directly compiled from `emcc` and `clang-9`.
* `hello_cpp.wasm`successed. [Issue fixed](https://github.com/wasmerio/wasmer/issues/327).
* math.h function successed.

#### Wasmo
Wasmo is successfully build on all of the x86 devices. However, `.wasm` file execution failed.
* [Fixed Error](https://github.com/rust-lang/rust/issues/60149): note: "cc" "-m64" "-L"

## WASM Application

### Sample Codes
As dicussed before, we have compiled several sample codes with Emsdk and Clang. We can put those codes into some categories and here is a table showing the result of them.

Code Categories|Linux based PC|Raspberry Pi 4 (ARMv8)|Compiler|Note
:---:|:---:|:---:|:---:
Logical (loop, condition...)|Y|Y|Emsdk/Clang/Rust/WAT|---
Math.h & Vector.h|Y|Y|Emsdk/Clang|---
string.h|Y|Y|Emsdk/Clang|---
stdio.h|Y|Y|Emsdk/Clang|Emsdk requries customized stdio.h
file Read/Write|Y|N|Clang|requrie `--dir=.` in the commend for access ;Wasmer doesn't support file W/R on ARM
access to sensors (/proc or /dev)|Y|N|Clang|Can read mouse but have trouble with UART

### Mouse Scan Application


## V. Reference
1. Start-up gauide for WebAssembly: https://webassembly.org/getting-started/developers-guide/
2. Non-Web Embeddings: https://webassembly.org/docs/non-web/
3. Mozilla Blog: https://blog.mozilla.org/blog/2017/11/13/webassembly-in-browsers/
4. Node.js: https://en.wikipedia.org/wiki/Node.js
5. Emscripten SDK: https://emscripten.org/docs/getting_started/downloads.html

# Updates for course purpose
## Prospective Result
1. Make the non-browser WASM work on the Intel/ARM based processers and display "Hello World."
1. Implement the drivers for sensors and actuators with WASM
1. Generalize the WASM framework and develop an API for IoT devices
1. In the future, Combine the framework with state-of-art framework, e.g. DDFlow and RemedIoT. 

## Timeline
* Week 4-5: Get familiar with WASM and make it run on IoT devices
* Week 5-6: Install and test WASM runtime enviroments.
* Week 6-8: Compile and basic functions using WASM.
* Week 8-9: Test .wasm files on various WASM runtimes. 
* Week 9-10: Interface the system calls with WASI-SDK using wasmtime.

## Member Contribution
* Ximeng: 
  * WASM implementation on Windows and Raspberry Pi; 
  * Write, complie programs and translate in to .wasm.
  * Test `.wasm` files on WASM runtimes.
* Yiru:  
  * WASM implementation on macOS & Linux.
  * Build WASM runtime enviroments on macOS & Linux.
  * Test `.wasm` files on WASM runtimes.

## Devices
* Raspberry Pi: 3B+, 4B+.
* Windows/Ubuntu, dual-OS PC with intel i7-7700k processor.
* Macbook pro 15", x86-darwin.

## Related Work
There are two parts in the related works. The first part is the frameworks built based on the Web Assembly (WASM) and the second part is some document regarding the concept of WASM. We will go into details in the following.

1. Frameworks

   **DDFlow** is a framework built based on the **Node-Red**. It introduces a dynamic way to connect and disconnect devices in a certain working area so that an optimal computational performance is achieved. This requires timely communication between devices and thus it is built on WASM as it is considered as a faster way for transmission than JavaScript. 
    
    *NOTE: DDFlow a macroprogramming abstraction and accompanying runtime that provides an efficient means to program high-quality distributed applications that span a diverse and dynamic IoTnetwork. RemedIoT is a remedial action framework for resolving Internet-of-Things conflicts.*

    **RemedIoT** is a framework concept used to remediate the conflicts in IoT framework. This is a more conceptual framework than DDFlow, since it focuses on the algorithm that solves the conflicts in a framework. This includes assigning priority to different requests and differing the levels of emergency.

2. Web Assembly Documents

    **Premium Resources** (expend)
    
    [WASM Micro Runtime](https://github.com/wyr8633/wasm-micro-runtime) is a standalone WebAssembly runtime with small footprint.
    
    [Wasmer](https://github.com/wasmerio/wasmer) is a WebAssembly runtime with package manager.
    
    [Wasmo](https://github.com/appcypher/wasmo)
    
    [Wasmtime](https://github.com/bytecodealliance/wasmtime)
    
    
    **There are several developments on Web-based WASM.**
    
    [WASI](https://hacks.mozilla.org/2019/03/standardizing-wasi-a-webassembly-system-interface/) official wasm interface
    
    [Node.js](https://www.joyent.com/blog/improved-wasm-support-coming-to-node) support for wasm
    
    [Rust Wasm](https://github.com/rustwasm/wasm-pack) compile rust to wasm, and make it run by node.js
    
    [Understanding WebAssembly](https://developer.mozilla.org/en-US/docs/WebAssembly/Understanding_the_text_format) is a tutorial on how to write a program in WASM.
    
    [WebAssembly Explorer](https://mbebenita.github.io/WasmExplorer/) and [WasmFiddle](https://wasdk.github.io/WasmFiddle/) are online compiler to provide a insight on WASM. Also, there is a [WebAssembly Code Explorer](https://wasdk.github.io/wasmcodeexplorer/) helps us to understand the binary code.
    
    [The official guild](https://webassembly.org/getting-started/developers-guide/) describes the fundamental usage of WASM in Windows/IOS/Linux. It talks about the Web-based WASM. However, the toolchain "emsdk" is usable on Intel but may not be on the Arm processors.

    [WebAssembly Literacy](https://docs.google.com/document/d/1K8EjLSKl62s_M7ZkDfuOizdsamv2UKUwwQRF2DmIba0/edit) is a document provided by people in Mozilla. It is a handbook describing syntax about writing WASM.

    [Rust](https://rustwasm.github.io/docs/book/introduction.html) is a programming language that can be complied into WASM. The setup on Raspberry Pi has some troubles but they are expected to be solved. This may also work for Web-based WASM.

    [WebUSB API](https://wicg.github.io/webusb/) provides the access to USB in Web.

    **There are some Hello-World tutorials:**

    Running a [funcition](https://medium.com/@dai_shi/my-first-webassembly-trial-with-node-js-only-a9281641e9ed) on Raspberry Pi which is written in .WAT and compiled into .WASM with "npx wat2wasm". It runs in non-web setting using Node.js.
    
    [Run WAST](https://gist.github.com/kanaka/3c9caf38bc4da2ecec38f41ba24b77df) is also an example on running WASM using Node.js without browser.
    
    Another [example](http://thecodebarbarian.com/getting-started-with-webassembly-in-node.js.html) using node.js to run WASM. Also this [one](https://github.com/yusinto/node-wasm).
    
    Run WASM with a [html code](https://medium.com/@BenedekGagyi/the-simplest-way-to-get-started-with-webassembly-1f92f6f90d24) gives the way to run WASM in browser.

## Progress

#### Acomplished
* "Hello world" on devices.
* Generated and complied .wasm/.c/.html file using Emscripten on all of 3 devices.
* Wasmer sucessully installed, able to run simple .wasm file.
* Wasmtime sucessully installed, able to run simple .wasm file.
* Compile different functions into Wasm and test.
* Run Wasm with node.js with the help of javascript.
* Run Wasm directly in node.js
  
#### In progress
* WASI with System calls.
* UART setup on Ubuntu: attached to ttyUSB0 [help](https://blog.mypapit.net/2008/05/how-to-use-usb-serial-port-converter-in-ubuntu.html)
* [help on tty rw](https://unix.stackexchange.com/questions/117037/how-to-send-data-to-a-serial-port-and-see-any-answer)

#### Failure
* Wasmo: 
  * Fixed ERROR:note: "cc" "-m64" "-L" https://github.com/rust-lang/rust/issues/60149
  * Fail to run .wasm file: ERROR: dyld: Symbol not found: _ffi_type_double
* WebAssembly Micro Runtime: 
  * ERROR:Load import section failed: resolve import function (wasi_unstable, fd_prestat_get) failed.
* Runtime Wasmer and Wasmtime cannot be installed to the Rasp Pi 3+ due to arm7l architecture.
