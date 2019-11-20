# [A G M] Air Gesture Mouse
## Executive Summary :
##### In this project, I looked to design and implement a wireless mouse unit with gyroscope based movement control. The aims of this project were to simulate cursor motion/click mechanisms simply by using hand gestures; by moving the unit freely in the air. The challenge was to give the user the ability to operate any computer unit as their hands are in midair; this would mean taking wires and surfaces out of the picture.
 
##### To make this possible, the STM32F103C8T6 [Blue Pill] was used as the main microcontroller as it will be programmed for the interference with 2 push buttons [Left, Right], Bluetooth Module HC-05 [For Wireless Communication], and an MPU-6050 [Gyroscope/Accelerometer]. In addition, a Buck Converter [DC-to-DC] would be used to step down the voltage of the unit; doing so to reduce the unit’s heat and extend the battery/lifetime. For the finishing touch, it will be necessary to provide the user dynamic feedback; so an OLED screen will be put on the wireless unit showing realtime sensor data points.
 
##### Now, let’s take a look at the process flow; as the Bluetooth Module will be interfaced with the Blue Pill, it will be able to establish UART communication [Receive and Transmit] with the preferred laptop/computer the bluetooth is paired to. When the unit is on, the MPU-6050 IMU sensor will give it’s dynamic positional values, as they will be used by the Blue Pill Microcontroller. These values will then accordingly give instructions to the laptop/computer to move the cursor dynamically in the desired direction; it will also send serial print data [Such as: Left, Right, Up, Down, Left Click, Right Click, Double Click] to the laptop/computer through bluetooth. The user will be provided the realtime X-Y coordinates dynamically on the OLED display on the wireless unit, along with a moving circle graphic which will correspond to the X-Y movement.
 
##### Putting the picture together, the user will be able to simulate mouse movement by performing an X-axis Pitch [Rotating unit Left or Right] , as well as a Y-axis Roll [Rotating unit Forwards or Backwards] or [Both Together]. (Figures shown below) This will coincide with the 2 push buttons [Left, Right] available to perform the operations of Left Click, Right Click, and Double Click.


###### [For Reengineering] 
## Hardware :
- STM32F103C8T6 [Blue Pill]  -  ARM Cortex M3 Microcontroller
- HC-05 [Bluetooth Module]
- MPU-6050 [Gyroscope/Accelerometer]
- LM2596 Buck Converter [DC-to-DC]
- OLED Display [0.96" I2C]
- Half-Sized Flex PCB [Adafruit]
- Push Buttons [2]
- Wires

### Hardware Schematic :
![Hardware Schematic](https://raw.githubusercontent.com/HG7777/AGM/master/schematics/Breadboard%20Diagram.png)
##### Modules in Diagram: 
###### MPU-6050 [Top-Left], OLED [Top-Right], Buck Converter [Bottom-Left], HC-05 [Bottom-Right], STM32F103C8T6 [Bottom-Middle], Push Buttons (2) [Dead Center]
### Block Diagram :
![Block Diagram](https://raw.githubusercontent.com/HG7777/AGM/master/schematics/Block%20Diagram.png)

## Software :
