The code directory is as follows.

Directly under our Medical-Imager folder, we have:
-LucidQT folder
-DeviceContrl.mlapp

DeviceControl.mlapp is the MATLAB prototype included from the original product owners' prototype.
This was included in order to give a baseline for how the software should work, but is not necessary.

-LEDQT_TEST.ino is the arduino project file required for testing the LEDs. 
This requires the Arduino IDE to properly upload and test.

The LucidQT folder hold s the source files necessary for the software:

-arduinowindow.cpp holds the code for what the buttons in the LED control window do.
This includes connecting to the arduino and enabling and disabling the LED lights.

-arduinowindow.h is the header file for the LED control window. 
It defines methods and holds constants, such as the arduino device information.

-arduinowindow.ui is the UI file for QT Creator.
Opening it with QT allows for the editing of the button layout and even direct access to their functionality.

-arenaassistanticon.ico is the icon file used to display on the windows.

-License.txt is the license for the SpyBot QSS file

-lightOff.png
-lightOn.png
Are files used in the Arduino Window to show the software side of the LED lights' state

-LucidQT.pro is the project file for the entire software. 
It holds information such as included library paths and included QT components.

-LucidQT.pro.user is an additional file required by QT, but does not concern us

-main.cpp is the software's main cpp file, that starts the GUI

-mainwindow.cpp is the main menu of Arena Assistant, defining the methods for the buttons.
This also allows for the link to the ARDUINO window.

-mainwindow.h is the header file for defining the button functions

-mainwindow.ui is the QT Creator file for defining the layout of the main menu.
Opening it within the QT program allows for editing of the layout.

-Spybot.qss is a qss file that edits the stylesheet properties of the software

-stylesheet.qrc is a resource file that holds the necessary resources for QT to recognize.
