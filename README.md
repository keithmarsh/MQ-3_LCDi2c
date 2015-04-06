Here's a very simple project that just connects to an easily available MQ-3 sensor module and displays the readings on an i2c LCD module.

![Pic goes here](https://raw.githubusercontent.com/keithmarsh/MQ-3_LCDi2c/master/img/IMG_20150406_164749305.jpg)

I experimented by having one 500mL 5% lager where show.  Taking readings every half an hour (first one just before the first beer) gave readings of:
* 00:00 110 Beer
* 00:30 162
* 01:00 281 Beer
* 01:30 324
* 02:00 363 Beer
* 02:30 345
* 03:00 394 Beer
* 03:30 453 Beer
* 04:00 469

Rinsing with a mouthful of Becherovka and taking a reading immediately gives a reading over 600.

Allow the sensor to cool and settle down when it first turns on - 30 seconds or so.

I have never seen the digital pin read anything other than 1.
