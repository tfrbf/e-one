## Overview 

This is an arduino based robot that can detect Fire, CO gas and send defined alarms to controller.




## Hardware 
**1.** We used Arduino UNO as a microcontroller (Arduino CH can be used instead)

- :pushpin:	 check Datasheet [here](https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf)

![arduino-uno-r3](https://user-images.githubusercontent.com/79377894/207100737-8ac57d72-b788-4916-b25a-ad8c26017737.jpeg)


**2. L298N** 
The L298N is a dual H-Bridge motor driver which allows speed and direction control of two DC motors at the same time. The module can drive DC motors that have voltages between 5 and 35V, with a peak current up to 2A.
If you want to upgrade it to use 4 gearboxes notice that each pair of gearboxes in one axis should act same. This driver needs 9v voltage to work so choose your battery carefully.Remove speed pins cover to control the speed otherwise it runs in highest speed as default.

- :pushpin:	 Check Datasheet [here](https://components101.com/sites/default/files/component_datasheet/L298N-Motor-Driver-Datasheet.pdf)

![L298N-Module-Pinout](https://user-images.githubusercontent.com/79377894/207098358-5c0fe90d-50ac-4b91-9aca-4314d2df1335.jpg)

**3. HY SRF05** 
The HY-SRF05 is an ultrasonic emitter/receiver used to measure distance with a precision of ~0.3cm. It sends out a 40 KHz square wave signal that reflects on objects in front of the sensor. This signal is then read back by the sensor and the duration of the received signal is reflected on the ECHO pin.

- :pushpin:	check Datasheet [here](https://www.micros.com.pl/mediaserver/M_HY-SRF05_0003.pdf)

![71IfHMKGsHL _AC_SY450_](https://user-images.githubusercontent.com/79377894/207102423-369e860b-baa1-4dcf-b724-ee1499a1d19e.jpg)

**4. HC05 Bluetooth module** Designed to replace cable connections HC-05 uses serial communication to communicate with the electronics. Usually, it is used to connect small devices like mobile phones using a short-range wireless connection to exchange files. It uses the 2.45GHz frequency band.

- :pushpin:	check Datasheet [here](https://components101.com/sites/default/files/component_datasheet/HC-05%20Datasheet.pdf)

![61uiAKEPWPL _SL1000_](https://user-images.githubusercontent.com/79377894/207105268-fa7e045a-3bb6-4cdb-91a7-8120662943fd.jpg)

- At the end Specially thanks to our awesome friends [Amir Atapour](https://github.com/Amiratpr) , [Sajed davoodi](https://github.com/Sdavoodi) and Omid Maleki :wink:

:interrobang:	 Any idea to make this project better?

:envelope_with_arrow:	 please contact us

- t_farshbaf@outlook.com
- atadibazar2016@gmail.com
- e.fakhrzadeh@gmail.com
