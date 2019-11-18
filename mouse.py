"""
Harshdeep Goraya   |   A G M  [Air Gesture Mouse]   |   Phase 1 Prototype

	- "There are but 2 powers in the world, the sword and the mind.
	 	In the long run the sword is always beaten by the mind."
"""

import serial
import time
import pyautogui


ser=serial.Serial(port='COM3',baudrate=9600,timeout=0.1)   # Incoming COM Port of the HC-05

time.sleep(0.1)   #give some time for port to be ready
def RIGHT():
	pyautogui.moveRel(15,0)

def LEFT():
	pyautogui.moveRel(-15)

def UP():
	pyautogui.moveRel(0,-15)

def DOWN():
	pyautogui.moveRel(0,15)

def STOP():
	pyautogui.moveRel(0,0)

def LCLICK():
	pyautogui.click()

def RCLICK():
	pyautogui.rightClick()

def DCLICK():
	pyautogui.doubleClick()


while 1:
	ardSer= ser.readline().decode('ascii')
	#removes 'b' and apostrophe  characters from the serial data

	print(ardSer)

	#performs the desired action
	if 'right' in ardSer:
		RIGHT()
	elif 'left' in ardSer:
		LEFT()

	elif 'up' in ardSer:
		UP()

	elif 'down' in ardSer:
		DOWN()

	elif 'stop' in ardSer:
		STOP()

	elif 'rclick' in ardSer:
		RCLICK()

	elif 'lclick' in ardSer:
		LCLICK()
	elif 'dclick' in ardSer:
		DCLICK()
adrSer=""
