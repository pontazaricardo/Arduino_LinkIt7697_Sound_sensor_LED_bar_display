# Arduino_LinkIt7697_Sound_sensor_LED_bar_display

This project shows how to connect a sound sensor (analogic) and how to display its output in a LED bar display using LinkIt 7697.

## Installation

If you want to use the **LinkIt 7697** with the Arduino IDE, follow [this](https://docs.labs.mediatek.com/resource/linkit7697-arduino/en/environment-setup) tutorial. As a summary:
1. Go to *File -> Preferences* and in the **Additional Boards Manager URLs**, type
```
http://download.labs.mediatek.com/package_mtk_linkit_7697_index.json
```
![install02](/images/install02.gif?raw=true)

2. Then go to *Tools -> Boards -> Board Manager...* and in the search box look for **LinkIt**. Install the additional libraries.

![install03](/images/install03.gif?raw=true)

3. Finally install the USB driver (CP210x) from [here](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers), selecting the correct OS configuration.

![install04](/images/usb_driver.png?raw=true)

## Code and configuration

In order to correctly connect the board and the sensors, the code has to be analyzed first.

### Code

In order to use the LED Bar, we need to import the **Grove_LED_Bar** library and initialize the **Grove_LED_Bar** object as follows.
```arduino
#include <Grove_LED_Bar.h>

const int pinAdc = A0;
Grove_LED_Bar bar(9, 8, 0);	// Clock pin, Data pin, Orientation. Modify for your input pin (in our case, pin 8 in the LinkIt 7697).
```