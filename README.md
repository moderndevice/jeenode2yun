yunidity
========

Hosts data on the Yun from a Jeelink-- humidity data, in this case.

Getting started:
 * From the yun, opkg update && opkg install pyserial kmod-usb-serial-ftdi
 * Flash your Jeenode with a humidity sensor on it with the sketch in Jeenode/
 * Flash your Jeelink with the sketch in Jeelink
 * Plug the Jeelink into the Yun
 * Copy upload.py to /www/humidity on the yun
 * Copy rc.local to /etc/rc.local on the yun to add the script to startup
 * Reboot the yun

