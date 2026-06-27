# Fluxon
## Project Overview
<p align="center">
<img width="540" height="829" alt="fallout&#39;26 zine" src="https://github.com/user-attachments/assets/cb8a3d84-cd27-463f-b567-25654c44a3a7" />

</p>
<br><br>

__Fluxon__ - A PVDF Sensor based Flux logger that collects collision data, a especailly designed payload for CubeSat\
Collects useful data values once embedded on side walls of the satellite as shown in the Zine page above.
<br><br>
<img width="867" height="867" alt="image" src="https://github.com/user-attachments/assets/56ceeae7-de43-4637-a41e-dbeec7a8c554" />



 ## Why I made this
 I made this project for a hardware hackathon called fallout organised by [Hack Club](https://github.com/hackclub), and particularly choosed to make this Iot device as i wanted to make a prototype of something real used in spacecrafts.
 ## Why it is relevant
 * Scientific value: Current flux models like [ORDEM](https://orbitaldebris.jsc.nasa.gov/modeling/ordem.html) and [MASTER](https://conference.sdo.esoc.esa.int/proceedings/sdc3/paper/92/SDC3-paper92.pdf) rely mainly on simulations and ground based radar data. A physical sensor mounted on small satellite misson measures impact data better than any simulation can replicate.
 * Cost effective: Commercial impact detectors used in experiments cost thousands of dollars, whereas Fluxon is an open source, low cost substitute PCB board.
 * Mechanical compatibility with real CubeSats: The 60mm x 60mm form factor matches the standard face panel dimensions of CubeSat.
 * Solar powered: The SPV1040 maximum power point tracker(MPPT) harvests energy form solar cell and charges the supercapacitor which reduces the burden of holding a separate battery into a small scale satellite.
 * Mass-frequency distribution: This statistically relevant distribution is obtained from the measured peak voltage which is proportional to mechanical impulse delivered on the aluminium face panel.
 * Flux density: The DS3231 which is a highly accurate real time clock(RTC) helps us to measure particle flux in units of particles per area per second. Flux density is meaningful beacause it varies with orbital altitude, inclination and the time of year(the earth's debris envionment is not uniform).
 * Impact direction: If we embed Fluxon on each face panel of CubeSat, we can calculate angular distribution of impact using parameters like time difference between sensor pairs, speed of sound in aluminium (6320 m/s) and known sensor geometry.
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
 `* flux logger project.kicad_sch`-contains an illustrative layout of parts and wires used in the project
 
 <img width="1166" height="797" alt="image" src="https://github.com/user-attachments/assets/abe98c51-2612-43f5-a112-66fb6d45fb3a" />

 `* flux logger project.kicad_pcb`\-The actual pcb layout with all components placed and routed
 
 <img width="982" height="820" alt="image" src="https://github.com/user-attachments/assets/4a2a69ac-9b31-41ac-98d9-6eb163553131" />
 
 `* BOM(CSV).csv`-Bill of materials with all parts
 

 # Firmware:
 `* Firmware` folder contains hardware specific C codes for parts to operate
 
 # Other files
 `* Flux logger project.kicad_pro`-links `kicad_sch` and `kicad_pcb` files.
 
 `ChargeAmplifier.kicad_sch`,`TPS_Vin.kicad_sch` and`Thre_comp.Kicad_sch` are sub parts of main schema file i.e. `flux logger project.Kicad_sch` 
 ## Build Guide
 1. Replicate the Repository into your local environment
 
 2. View `flux logger project.kicad_sch`,`flux logger project.kicad_pcb` along with the pcb's 3D View on [Kicad](https://www.kicad.org/)
 
 3. PCB Assembly\
 Solder components in the following order:
 resistors and capacitors,Sensor, ADA4530-1, MSP430, W25Q128JV, Connectors and testpoints

 4. Check High Impedance Areas
 Ensure gaurd ring surrounding Amplifier and Sensor input traces.
 Also, keep sensor input clean and isolated.

 5. Power Supply Check
 Apply 3.3V Supply according to `.kicad_sch` file and verify 3.3V rail across each IC.

 6. Firmware Installation

 #### Required Software
 * Visual Studio Code Editor
 * PlatformIO Extension
 * Texas Instruments MSP430 Toolchain

 7. Build and Upload Firware

 * Open Firmware folder and run `pio run` on CLI

 * Use upload Button on PlatformIO in order to upload the programme


## BOM
| Value              | Reference                                  | Footprint                                                                          | Qty | Unit Price     | Total Price    | URL                                                                                                                                                                                                                                                                                                                            |
|--------------------|--------------------------------------------|------------------------------------------------------------------------------------|-----|----------------|----------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 100nf              | C1,C2,C3,C5,C6,C7,C13,C15,C16              | Capacitor_SMD:C_0805_2012Metric                                                    | 9   | 1.00rs            | 9.00rs            | https://projectpoint.in/index.php?route=product/product&product_id=636107122                                                                                                                                                                                                                                                   |
| 1uf                | C17,C12                                    | Capacitor_SMD:C_0805_2012Metric                                                    | 2   | 2.09rs         | 4.18rs         | https://robu.in/product/1uf-1000nf-50v-capacitor-0805-smd-package-pack-of-10/                                                                                                                                                                                                                                                  |
| 10uF               | C9,C11,C8,C18                              | Capacitor_SMD:C_0805_2012Metric                                                    | 4   | 3.44rs         | 13.76rs        | https://robu.in/product/grm21bb31c106me15l-murata-electronics-16v-10uf-%C2%B120-0805-multilayer-ceramic-capacitors-mlcc-smd-smt-rohs/                                                                                                                                                                                          |
| 22uF               | C10,C14                                    | Capacitor_SMD:C_1206_3216Metric                                                    | 2   | 0.98rs         | 1.96rs         | https://robu.in/product/cs3216x5r226m6r3nri-samwha-6-3v-22uf-x5r-%C2%B120-1206-multilayer-ceramic-capacitors-mlcc-smd-smt-rohs/                                                                                                                                                                                                |
| 10pf               | Cf1                                        | Resistor_SMD:R_0603_1608Metric                                                     | 1   | 0.92rs         | 0.92rs         | https://robu.in/product/10pf-0603-surface-mount-multilayer-ceramic-capacitor-pack-of-50/                                                                                                                                                                                                                                       |
| 100mf              | S_Cap1                                     | Capacitor_THT:CP_Radial_D10.0mm_P5.00mm                                            | 1   | 99.00rs        | 99.00rs        | https://robu.in/product/0-1f-5-5v-dip-super-capacitor/                                                                                                                                                                                                                                                                         |
| Conn_01x04         | J1                                         | Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical                         | 2   | 1.50rs         |         3.00rs | https://ifuturetech.org/product/xh2-54-2p-curved-needle-connector-holder-2-54mm-white/                                                                                                                                                                                                                                         |
| 22uH               | L2                                         | Inductor_SMD:L_7.3x7.3_H4.5                                                        | 1   | 8.00rs         | 8.00rs         | https://robu.in/product/68mm-22%C2%B5h-dip-power-inductor-pack-of-5/?gad_source=4&gad_campaignid=17427802703&gbraid=0AAAAADvLFWcfg8oALnufuCDn7QS7Yxsgw&gclid=CjwKCAjw9NjRBhATEiwA_p2J8UuSwcfA2Lr5wrlX0WQkwEzMOyO9Nd1P-ll7UbZbTWQCKsbAUmGBtxoCC_MQAvD_BwE                                                                       |
| 10K                | RV2                                        | Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical                              | 1   | 14.70rs        | 14.70rs        | https://projectpoint.in/index.php?route=product/product&product_id=1500453261                                                                                                                                                                                                                                                  |
| 4.7K               | R1,R3                                      | Resistor_SMD:R_0805_2012Metric                                                     | 2   | 0.44rs         | 0.88rs         | https://robu.in/product/yageo-4-7k-ohm-1-4w-0805-surface-mount-resistor-pack-of-50/?gad_source=4&gad_campaignid=17427802703&gbraid=0AAAAADvLFWcfg8oALnufuCDn7QS7Yxsgw&gclid=CjwKCAjw9NjRBhATEiwA_p2J8W7dYQrZnCsdsWutgfi2JOE-1O_Ukj8FJljlKnBzD6cBGYgiVhon4hoCGU4QAvD_BwE                                                        |
| 100M               | R2                                         | Resistor_SMD:R_1206_3216Metric                                                     | 1   | 84.75rs        | 84.75rs        | https://srkelectronics.in/product/1-mega-ohm-1206-smd-resistor-cfr-pack-of-100/                                                                                                                                                                                                                                                |
| 470K               | R10                                        | Resistor_SMD:R_0603_1608Metric                                                     | 1   | 8.00rs         | 8.00rs         | https://quartzcomponents.com/products/470k-ohm-0603-package-1-10w-smd-resistor-5-tolerance-pack-of-20-pieces?variant=44678130565354&country=IN&currency=INR&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&srsltid=AfmBOooqJKQhW7YbzG5QFEy0RA-DWadXqpZfb886LD__9LHmBCOOGl79qMo     |
| 10K                | R5,R8,R4,R11                               | Resistor_SMD:R_1206_3216Metric                                                     | 4   | 0.69rs         |       2.76rs   | https://robu.in/product/10k-ohm-1-4w-1206-surface-mount-chip-resistor-pack-of-100/?gad_source=4&gad_campaignid=17427802703&gbraid=0AAAAADvLFWcfg8oALnufuCDn7QS7Yxsgw&gclid=CjwKCAjw9NjRBhATEiwA_p2J8YndTZpSAUk0yIELKsWgMxWpWZsCg3WXOXNIa_TPXrjVBX5Mqxgn4xoChh0QAvD_BwE                                                         |
| 13.3K              | R6                                         | Resistor_SMD:R_1206_3216Metric                                                     | 1   | 1.70rs         | 1.70rs         | https://projectpoint.in/index.php?route=product/product&product_id=499506064082                                                                                                                                                                                                                                                |
| 47k                | R7                                         | Resistor_SMD:R_1206_3216Metric                                                     | 1   | 1.70rs         | 1.70rs         | https://projectpoint.in/index.php?route=product/product&product_id=501263610758                                                                                                                                                                                                                                                |
| 9.1K               | R9                                         | Resistor_SMD:R_1206_3216Metric                                                     | 1   | 1.70rs         | 1.70rs         | https://projectpoint.in/index.php?route=product/product&product_id=502522332251                                                                                                                                                                                                                                                |
| 220K               | RST1                                       | Resistor_SMD:R_1206_3216Metric                                                     | 1   | 1.70rs         | 1.70rs         | https://projectpoint.in/index.php?route=product/product&product_id=501903421507                                                                                                                                                                                                                                                |
| 100K               | RST2                                       | Resistor_SMD:R_1206_3216Metric                                                     | 1   | 0.79rs         | 0.79rs         | https://robu.in/product/100k-ohm-1-4w-1206-surface-mount-chip-resistor-pack-of-100/?gad_source=4&gad_campaignid=17427802703&gbraid=0AAAAADvLFWcd2632Ty4S6PMw-fukdNsD1&gclid=CjwKCAjwl97RBhBWEiwAa9rbXZb4d1umDK0ptoRG9JBTgPPU3BVFfywxlvYmKyawWVLWZqEBT12_WRoCiUYQAvD_BwE                                                        |
| 1M                 | R_hys1                                     | Resistor_SMD:R_0603_1608Metric                                                     | 1   | 9.00rs         | 9.00rs         | https://quartzcomponents.com/products/yageo-1m-ohm-0603-package-1-10w-smd-resistor-1-tolerance-pack-of-20-pieces?variant=45952342458602&country=IN&currency=INR&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&srsltid=AfmBOop2TJlavxmk_Py0tepDthLo-4WGt6L3SB3oAG36sDNxWqzsWehiqpk |
| 1K                 | R12                                        | Resistor_SMD:R_1206_3216Metric                                                     | 1   | 0.65rs         | 0.65rs         | https://robu.in/product/1k-ohm-1-4w-1206-surface-mount-chip-resistor-pack-of-100/?gad_source=4&gad_campaignid=17427802703&gbraid=0AAAAADvLFWcd2632Ty4S6PMw-fukdNsD1&gclid=CjwKCAjwl97RBhBWEiwAa9rbXZhhZrsnIQ2GC6qdmROeP4HSg4zL3TrdbdUty2efHun2CRlimZtfgBoCH5kQAvD_BwE                                                          |
| PDVF Sensor        | S1                                         | Connector_JST:JST_PH_B2B-PH-K_1x02_P2.00mm_Vertical                                | 1   | 42.00rs           | 42.00rs           | https://www.flyrobo.in/10cm-2pin-jst-male-female-plug-connector-plug?tracking=ads&srsltid=AfmBOorg-c1t1ZMkoyWb0uI_qOGQkm21_S4UDt7C8W2L81626DcfXFoIQn0                                                                                                                                                                          |
| Solar_Cell         | SC2                                        | Connector_JST:JST_PH_B2B-PH-K_1x02_P2.00mm_Vertical                                | 1   | 42.00rs           | 42.00rs           | https://www.flyrobo.in/10cm-2pin-jst-male-female-plug-connector-plug?tracking=ads&srsltid=AfmBOorg-c1t1ZMkoyWb0uI_qOGQkm21_S4UDt7C8W2L81626DcfXFoIQn0                                                                                                                                                                          |
| PRTR5V0U2X         | D2                                         | Package_TO_SOT_SMD:SOT-143                                                         | 1   | 84.11rs        | 84.11rs        | https://www.digikey.in/en/products/detail/microchip-technology/MIC5203-5.0YM4-TR/771725                                                                                                                                                                                                                                        |
| W25Q128JVS         | U1                                         | Package_SO:SOIC-8_5.3x5.3mm_P1.27mm                                                | 1   |       223.02rs | 223.02rs       | https://evelta.com/serial-nor-flash-memory-128mbit-8pin-soic/?srsltid=AfmBOop8ij99XVMBrUPP4MTaUBqT3zbdZ3cGI8FHUhDra9BC5HyqyAIr                                                                                                                                                                                                 |
| TLV3501AIDBV       | U3                                         | Package_TO_SOT_SMD:SOT-23-6                                                        | 1   | 336.38rs       | 336.38rs       | https://www.mouser.in/ProductDetail/Texas-Instruments/TLV3501AIDR?qs=m96fseALk3U7ir0PfDMQ%252BA%3D%3D&mgh=1&srsltid=AfmBOor5vJxjcE3nIdmz1dbCXO-Uv17hTZ7m_LMbHJgRObglxWCiYOP0Zco                                                                                                                                                |
| MSP430FR5994IPMR.B | U4                                         | MCU:MSP430FR footprint                                                             | 1   | 929.00rs       | 929.00rs       | https://www.mouser.in/ProductDetail/Texas-Instruments/MSP430FR5994IPMR?qs=dSktwyqbRaUcLErRS51dOQ%3D%3D&mgh=1&srsltid=AfmBOorC_1wTVOKZsgPyuOEpQwWsIM3aE6d3V3cPUSy3F-jRGF3ltK4Pe94                                                                                                                                               |
| ADA4530-1          | U5                                         | Package_SO:SOIC-8_3.9x4.9mm_P1.27mm                                                | 1   | 3579.04rs      | 3579.04rs      | https://www.mouser.in/ProductDetail/Analog-Devices/ADA4530-1ARZ?qs=JeIcUl65ClBv6gT9eb3ViA%3D%3D&mgh=1&srsltid=AfmBOorU-kISNIBcR4dI59y3OOEkDu8qQd61ynzLychaZnXB45u1Smna6m4                                                                                                                                                      |
| DS3231M            | U6                                         | Package_SO:SOIC-16W_7.5x10.3mm_P1.27mm                                             | 1   | 218.00rs       | 218.00rs       | https://robu.in/product/ds3231-ic-real-time-clock-integrated-rtc-tcxo-crystal/?gad_source=4&gad_campaignid=17427802703&gbraid=0AAAAADvLFWcd2632Ty4S6PMw-fukdNsD1&gclid=CjwKCAjw9NjRBhATEiwA_p2J8bUNeLHsm7K7N2HT5aExEh7PZg8PEYmbdlRroAsWpZUMoNvL3sb1choCtCgQAvD_BwE                                                             |
| TPS7A4701xRGW      | U8                                         | Package_DFN_QFN:Texas_RGW0020A_VQFN-20-1EP_5x5mm_P0.65mm_EP3.15x3.15mm_ThermalVias | 1   | 540.76rs       | 540.76rs       | https://www.lioncircuits.com/parts/TPS7A4701RGWR?srsltid=AfmBOopbvZxVMUhUOCdwxvLDpRitcg0Les7a-ZnXqwtRMHtWEGWGjgl7EgQ                                                                                                                                                                                                           |
| SPV1040TTR         | U9                                         | Package_DFN_QFN:SOIC_1040T_STM                                                     | 1   | 342.13rs       | 342.13rs       | https://www.digikey.in/en/products/detail/stmicroelectronics/SPV1040TTR/2672694                                                                                                                                                                                                                                                |
| TesPoint           | TP_3v3, TP_GND1,TP_GND4, TP_SCAP1,TP_COMP1 | TestPoint:TestPoint_Pad_D1.5mm                                                     | 5   | 15.61rs        |       78.08rs  | https://in.element14.com/keystone/5000/test-point-pcb-color-coded/dp/2250281                                                                                                                                                                                                                                                   |
|                    |                                            |                                                                                    |     | TOTAL=         |     6682.68rs  |                                                                                                                                                                                                                                                                                                                                |

  ## Credit
  I thank this project to-\
  [Kicad](https://www.kicad.org/)\
  [HackClub Fallout](https://fallout.hackclub.com)\
  my beloved parents and friends...
 
 

 

 
 
 
