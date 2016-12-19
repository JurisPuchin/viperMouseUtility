# viperMouseUtility
Utility for Viper V560 mouse, enables tilt wheel functionality. 
Your tilt wheel will do Super+Left and Super+Right, to allow you to throw your windows around.
Tested on Ubuntu (Mint).

###To compile use:
```
gcc -o viperMouseUtility -O3 wheelEvent.c -lX11 -lXtst
```
###To run:
Run manually with sudo.
```
sudo viperMouseUtility
```
###To run on startup:
Edit visudo:
```
sudo visudo
```
Add the line:
```
%sudo    ALL=(ALL:ALL) NOPASSWD: /usr/local/sbin/viperMouseUtility
```
Copy utility to sbin:
```
sudo cp ./viperMouseUtility /usr/local/sbin/viperMouseUtility
```
And add a new entry into Startup Applications:
- Click Menu
- Type "startup" into search
- Click Startup Applications Preferences
- Click Add
- Type "wheelTilt" into Name
- Type the following into Command
```
sudo /usr/local/sbin/viperWheelEvent
```
###If you like this, or want help, or think I should keep working on this.
Please let me know!

###Hint:
Make sure your mouse is mapped to:
```
/dev/input/by-id/usb-Areson_PATRIOT_VIPER_MOUSE-event-if02
```
If not, change the definition at the start of the `wheelEvent.c` file. 

If you are missing libraries, try:
```
sudo apt-get install libxtst-dev
```
