# Fluxon
## Project Overview
<img width="540" height="829" alt="Zine" src="https://github.com/user-attachments/assets/eaf1ff35-3a0c-4616-86d3-dcac96252f5d" />

Fluxon - A PVDF Sensor based Flux logger that collects collision data, a especailly designed payload for cubeSat exterior\
Collects useful data values once embedded on side walls of the satellite as shown in the Zine page above. 
 ## Why I made this
 I made this project for a hardware hackathon called fallout organised by [Hack Club](https://github.com/hackclub), and particularly choosed to make this Iot device as i wanted to make a prototype of something real used in spacecrafts.
 ## How it works
 The payload is mainly divided into 4 major chunks-
 ### 1. Sensor Frontend (Impact Detection Hardware)
Converts tiny charge generted by the peizoelectric sensors into a measurable voltage.
<img width="1938" height="1057" alt="image" src="https://github.com/user-attachments/assets/1fe7e593-6a07-4d5a-b506-2516fa067ced" />

 ### 2. Signal Conditioning
 Gives Amplified, noise reduced input for Microcontroller unit.
 <img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/b78b373f-7ada-4b57-9368-d0b9582891c0" />

 ### 3. Microcontroller and Firmware
 Processes sensor data and uses specific codes that brigdes the hardware requirements
<img width="1507" height="850" alt="image" src="https://github.com/user-attachments/assets/c0cac099-c382-40d2-b949-dafbb01d92a3" />

 ### 4. Data Storage System
 Uses W25Q128JV to store collected events
<img width="1014" height="820" alt="image" src="https://github.com/user-attachments/assets/aa8c10e4-79cb-4f79-93b5-d5771b04f43a" />

 ## What's inside this folder
 

 

 
 
 
