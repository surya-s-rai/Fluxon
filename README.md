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
 Processes sensor data and uses specific codes that brigdes the hardware requirements.
 
<img width="1507" height="850" alt="image" src="https://github.com/user-attachments/assets/c0cac099-c382-40d2-b949-dafbb01d92a3" />

 ### 4. Data Storage System
 Uses W25Q128JV to store collected events.
 
<img width="1014" height="820" alt="image" src="https://github.com/user-attachments/assets/aa8c10e4-79cb-4f79-93b5-d5771b04f43a" />

 ## What's inside this folder
 # PCB Files:
 `flux logger project.kicad_sch`-contains an illustrative layout of parts and wires used in the project
 
 <img width="1166" height="797" alt="image" src="https://github.com/user-attachments/assets/abe98c51-2612-43f5-a112-66fb6d45fb3a" />

 `flux logger project.kicad_pcb`\-The actual pcb layout with all components placed and routed
 
 <img width="982" height="820" alt="image" src="https://github.com/user-attachments/assets/4a2a69ac-9b31-41ac-98d9-6eb163553131" />
 
 `BOM updated1.xlsx`-Bill of materials with all parts
 
 <img width="1862" height="621" alt="image" src="https://github.com/user-attachments/assets/8ff124d1-da61-4c2b-8bc6-aa3ef9158764" />

 # Firware:
 `Firmware` folder contains hardware specific C codes for parts to operate
 
 # Other files
 `Flux logger project.kicad_pro`-links `kicad_sch` and `kicad_pcb` files.
 
 `ChargeAmplifier.kicad_sch`,`TPS_Vin.kicad_sch` and`Thre_comp.Kicad_sch` are sub parts of main schema file i.e. `flux logger project.Kicad_sch` 
 ## Build Guide
 1. Replicate the Repository into your local environment
 
 2. View `flux logger project.kicad_sch`,`flux logger project.kicad_pcb` along with the pcb's 3D View on [Kicad](https://www.kicad.org/)
 
 3. PCB Assembly
 Solder components in the following order:
 resistors and capacitors,Sensor, ADA4530-1, MSP430, W25Q128JV, Connectors and testpoints

 4. Check High Impedance Areas
 Ensure gaurd ring surrounding Amplifier and Sensor input traces.
 Also, keep sensor input clean and isolated.

 5. Power Supply Check
 Apply 3.3V Supply according to `.kicad_sch` file and verify 3.3V rail across each IC.

 6. Firware Installation

 #### Required Software
 * Visual Studio Code Editor
 * PlatformIO Extension
 * Texas Instruments MSP430 Toolchain

 7. Build and Upload Firware

 * Open Firmware folder and run `pio run` on CLI

 * Use upload Button on PlatformIO in order to upload the programme

  ## Credit
  I thank this project to-\
  [Kicad](https://www.kicad.org/)\
  [HackClub Fallout](https://fallout.hackclub.com)\
  my beloved parents and friends...
 
 

 

 
 
 
