jeenode2yun
========

Hosts data on the Yun from a Jeelink-- humidity data, in this case.

Getting started:
 * From the yun, opkg update && opkg install pyserial kmod-usb-serial-ftdi
 * Flash your humidity-sensor-equipped Jeenode with the sketch in Jeenode/
 * Flash your Jeelink with the sketch in Jeelink
 * Plug the Jeelink into the Yun
 * Copy index.html to /www/humidity/ on the yun (feel free to change the directory and update rc.local)
 * Copy upload.py to /www/humidity/ on the yun
 * Copy rc.local to /etc/rc.local on the yun to add the script to startup
 * Reboot the yun

