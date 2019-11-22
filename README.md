# [A G M] Air Gesture Mouse
## Executive Summary :
##### In this project, I looked to design and implement a wireless mouse unit with gyroscope based movement control. The aims of this project were to simulate cursor motion/click mechanisms simply by using hand gestures; by moving the unit freely in the air. The challenge was to give the user the ability to operate any computer unit as their hands are in midair; this would mean taking wires and surfaces out of the picture.
 
##### To make this possible, the STM32F103C8T6 [Blue Pill] was used as the main microcontroller as it will be programmed for the interference with 2 push buttons [Left, Right], Bluetooth Module HC-05 [For Wireless Communication], and an MPU-6050 [Gyroscope/Accelerometer]. In addition, a Buck Converter [DC-to-DC] would be used to step down the voltage of the unit; doing so to reduce the unit’s heat and extend the battery/lifetime. For the finishing touch, it will be necessary to provide the user dynamic feedback; so an OLED screen will be put on the wireless unit showing realtime sensor data points.
 
##### Now, let’s take a look at the process flow; as the Bluetooth Module will be interfaced with the Blue Pill, it will be able to establish UART communication [Receive and Transmit] with the preferred laptop/computer the bluetooth is paired to. When the unit is on, the MPU-6050 IMU sensor will give it’s dynamic positional values, as they will be used by the Blue Pill Microcontroller. These values will then accordingly give instructions to the laptop/computer to move the cursor dynamically in the desired direction; it will also send serial print data [Such as: Left, Right, Up, Down, Left Click, Right Click, Double Click] to the laptop/computer through bluetooth. The user will be provided the realtime X-Y coordinates dynamically on the OLED display on the wireless unit, along with a moving circle graphic which will correspond to the X-Y movement.
 
##### Putting the picture together, the user will be able to simulate mouse movement by performing an X-axis Pitch [Rotating unit Left or Right] , as well as a Y-axis Roll [Rotating unit Forwards or Backwards] or [Both Together]. (Figures shown below) This will coincide with the 2 push buttons [Left, Right] available to perform the operations of Left Click, Right Click, and Double Click.
> ![X-axis Pitch : Y-axis Roll](https://raw.githubusercontent.com/HG7777/AGM/master/node_modules/pitchRoll.png)

## Hardware :
- STM32F103C8T6 [Blue Pill]  -  ARM Cortex M3 Microcontroller
- HC-05 [Bluetooth Module]
- MPU-6050 [Gyroscope/Accelerometer]
- LM2596 Buck Converter [DC-to-DC]
- OLED Display [0.96" I2C]
- Half-Sized Flex PCB [Adafruit]
- Push Buttons [2]
- Wires

#### Hardware Schematic :
![Hardware Schematic](https://raw.githubusercontent.com/HG7777/AGM/master/schematics/Breadboard%20Diagram.png)
> ##### Modules in Diagram: 
> ###### MPU-6050 [Top-Left], OLED [Top-Right], Buck Converter [Bottom-Left], HC-05 [Bottom-Right], STM32F103C8T6 [Bottom-Middle], Push Buttons (2) [Dead Center]
#### Block Diagram :
![Block Diagram](https://raw.githubusercontent.com/HG7777/AGM/master/schematics/Block%20Diagram.png)

## Software Dependencies :
###### Release Used : Python `3.6.5 x86-64`
##### For Windows : Run the dependencies script 
```
install.bat
```
##### For Mac OS : Install dependencies individually
```
pip3 install pyautogui
pip3 install python3-xlib
pip3 install pyserial
```
##### For Linux : Install dependencies individually
```
sudo pip3 install pyautogui
sudo pip3 install python3-xlib
sudo pip3 install pyserial
```

## Hardware Pin Configuration :
After configuring & connecting the STM32F103C8T6 [Blue Pill] to your machine, through the Arduino IDE you will be able to select the **method of upload**: `serial` as well as select the **corresponding communications channel**: `COM port`.

Now you can open the [A G M] **configuration code** in the file : `airGestureMouse.ino`

Press the **reset button** on the Blue Pill board and hit the **upload button** on the Arduino IDE; compilation and upload process should initiate.
##### :warning:Warning : Take Precaution:warning:
###### The +5V pins on this board are directly connected to the +5V pin of the USB connector. There is no protection in place. Do not power this board through USB and an external power supply *AT THE SAME TIME*.
> ###### For deeper insight on the Blue Pill, please refer to this [Guide](https://www.techshopbd.com/uploads/product_document/STM32bluepillarduinoguide(1).pdf): 

## Input Voltage :
After the hardware modules have been interfaced with the Blue Pill, you can power the device with a: 
##### **5V 2 Amps DC Power Supply**
> ###### DC-to-DC buck converter ICs are intended to take **input voltages** from various battery chemistries: `IN+ : IN-`

## Bluetooth Connectivity :
Open your machine's bluetooth settings to connect and pair the: `HC-05`.

By default the **Passkey** is set to: `1234`.

> ###### At this point if you have successfully established connection, the HC-05 red LED indicator will change its blinking pattern and at times won't blink at all.

## Initiate [A G M] :
###### Command Line Utility


