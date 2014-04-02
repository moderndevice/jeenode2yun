#!/usr/bin/python
# This program reads off /dev/ttyUSB0 and writes an auto-updating html file with the results
# We have a jeelink on /dev/ttyUSB0 sending us data like "2580 7183 16132", which we divide by 100 to
# get humidity, temperature in celsius, and temperature in fahrenheit

import serial # opkg install pyserial if you don't have it
ser = serial.Serial('/dev/ttyUSB0', 57600, timeout=3) # Open the serial port at 57600

while True: # Loop forever
        data = ser.readline().split() # Split our data into an array, "2580 7183 16132" becomes [2580, 7183, 1613]
        if len(data) is 3: # The first line usually says something like "reading data..." ignore it.
                data = [float(thing)/100 for thing in data] # Divide each number by 100
                file = open('/www/humidity/data.html', 'w') # Open the html file for writing
                file.write("<html><head></head>\n<body>\n \
<title>Yun server</title>\n<p>Humidity: {0:.2f}</p>\n<p>Temperature (C): {1:.2f} \
                </p>\n<p>Temperature (F): {2:.2f}</p>\n</body></html>".format(*data)) # Write the html page with the data-- *data unpacks it
                file.close() # Close the file
