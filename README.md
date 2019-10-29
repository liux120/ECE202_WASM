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
  * WASM implementation on Windows; 
  * Serial transmission interaction using WASM; 
  * Interaction with camera; 
  * Part of the API development.
* Yiru: 
  * WASM implementation on Raspberry Pi; 
  * Bit interaction using WASM; 
  * Interaction with IMU; 
  * Part of the API development.

## Devices in Need
2 Raspberry Pi

## Progress
Related work summary. [Wiki](https://github.com/liux120/ECE202_WASM/wiki)

"Hello world" on devices.

***
===============================================================================

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
