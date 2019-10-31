# ECE202 WASM for IoT Devices
This is a course project of EE202 embedded system. The group members are Ximeng Liu and Yiru Wang.
Project #11 Framework to Expose IoT Sensor and Actuator Services.

## Abstract  
The objective of this project is getting familiar with the WASM and implement WASM in the general embedded devices under distributed and heterogeneous settings. To achieve the goal, members plan to first run WASM without the browser on a Raspberry Pi or personal laptops. Then, members will implement the WASM with actuators, such as sensors and cameras. Communication network using the WASM framework tend to be accomplished at this stage. Finally, the WASM framework will be generalized so that the WASM can be run in distributed and heterogeneous settings. In the future, we plan to combine the WASM with other frameworks, such as DDFlow and RemedIoT.

*NOTE: DDFlow a macroprogramming abstraction and accompanying runtime that provides an efficient means to program high-quality distributed applications that span a diverse and dynamic IoTnetwork. RemedIoT is a remedial action framework for resolving Internet-of-Things conflicts.*

## Prospective Result
1. Make the non-browser WASM work on the Intel/ARM based processers and display "Hello World."
1. Implement the drivers for sensors and actuators with WASM
1. Generalize the WASM framework and develop an API for IoT devices
1. In the future, Combine the framework with state-of-art framework, e.g. DDFlow and RemedIoT. 

## Timeline
* Week 4-5: Get familiar with WASM and make it run on IoT devices
* Week 5-6: Implement simple sensors and actuators (Buttons, Serial Ports, and etc.) on the devices and the interface using WASM
* Week 6-8: Further develop the interface with WASM on complex prepherals (IMU, cameras).
* Week 8-10: Develop an API for general devices. 

## Member Contribution
* Ximeng: 
  * WASM implementation on Windows and Raspberry Pi; 
  * Serial transmission interaction using WASM; 
  * Interaction with camera; 
  * Part of the API development.
* Yiru: 
  * WASM implementation on MacOS and Linux.
  * Bit interaction using WASM; 
  * Interaction with IMU; 
  * Part of the API development.

## Devices
* Raspberry Pi
* Ubuntu
* Windows

## Related Work
There are two parts in the related works. The first part is the frameworks built based on the Web Assembly (WASM) and the second part is some document regarding the concept of WASM. We will go into details in the following.

1. Frameworks
    
    **DDFlow** is a framework built based on the **Node-Red**. It introduces a dynamic way to connect and disconnect devices in a certain working area so that an optimal computational performance is achieved. This requires timely communication between devices and thus it is built on WASM as it is considered as a faster way for transmission than JavaScript. 

    **RemedIoT** is a framework concept used to remediate the conflicts in IoT framework. This is a more conceptual framework than DDFlow, since it focuses on the algorithm that solves the conflicts in a framework. This includes assigning priority to different requests and differing the levels of emergency.

2. Web Assembly Documents
    
    **There are several developments on Web-based WASM.**
    
    [Mozilla Blog](https://blog.mozilla.org/blog/2017/11/13/webassembly-in-browsers/) introduces the overall idea of the WASM and provides several links.
    
    [Understanding WebAssembly](https://developer.mozilla.org/en-US/docs/WebAssembly/Understanding_the_text_format) is a tutorial on how to write a program in WASM.
    
    [WebAssembly Explorer](https://mbebenita.github.io/WasmExplorer/) and [WasmFiddle](https://wasdk.github.io/WasmFiddle/) are online compiler to provide a insight on WASM. Also, there is a [WebAssembly Code Explorer](https://wasdk.github.io/wasmcodeexplorer/) helps us to understand the binary code.
    
    [The official guild](https://webassembly.org/getting-started/developers-guide/) describes the fundamental usage of WASM in Windows/IOS/Linux. It talks about the Web-based WASM. However, the toolchain "emsdk" is usable on Intel but may not be on the Arm processors.

    [WebAssembly Literacy](https://docs.google.com/document/d/1K8EjLSKl62s_M7ZkDfuOizdsamv2UKUwwQRF2DmIba0/edit) is a document provided by people in Mozilla. It is a handbook describing syntax about writing WASM.

    [Rust](https://rustwasm.github.io/docs/book/introduction.html) is a programming language that can be complied into WASM. The setup on Raspberry Pi has some troubles but they are expected to be solved. This may also work for Web-based WASM.


    **There are some Hello-World tutorials:**

    Running a [funcition](https://medium.com/@dai_shi/my-first-webassembly-trial-with-node-js-only-a9281641e9ed) on Raspberry Pi which is written in .WAT and compiled into .WASM with "npx wat2wasm". It runs in non-web setting using Node.js.
    
    [Run WAST](https://gist.github.com/kanaka/3c9caf38bc4da2ecec38f41ba24b77df) is also an example on running WASM using Node.js without browser.
    
    Run WASM with a [html code](https://medium.com/@BenedekGagyi/the-simplest-way-to-get-started-with-webassembly-1f92f6f90d24) gives the way to run WASM in browser.

Related work summary. [Wiki](https://github.com/liux120/ECE202_WASM/wiki/Related-Work-Review)

## Progress
#### Acomplished
* "Hello world" on devices.
  * Generated and complied .wasm/.c/.html file using Emscripten on all of 3 devices.
#### In progress
* Non-Web application.

## Reference
Start-up gauide: https://webassembly.org/getting-started/developers-guide/

Non-Web Embeddings: https://webassembly.org/docs/non-web/

***
***
# Template
## Welcome to GitHub Pages

You can use the [editor on GitHub](https://github.com/liux120/ECE202_WASM/blob/master/README.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/liux120/ece202.github.io/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.
