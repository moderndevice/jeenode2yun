jeenode2yun
========

Hosts data on the Yun from a Jeelink-- humidity data, in this case.

Getting started:
 * From the yun, opkg update && opkg install pyserial kmod-usb-serial-ftdi
 * Flash your humidity-sensor-equipped Jeenode with the sketch in Jeenode/
 * Flash your Jeelink with the sketch in Jeelink
 * Plug the Jeelink into the Yun
 * Make a directory for your project in /www/, default is /www/humidity
 * Copy index.html, upload.py and style.css to /www/humidity/ on the yun
 * If you want to change the directory, change it in index.html and rc.local
 * Copy rc.local to /etc/rc.local on the yun to add the script to startup
 * Reboot the yun

