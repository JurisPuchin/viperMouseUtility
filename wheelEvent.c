#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <linux/input.h>
#include <fcntl.h>

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

#define DEV_ADD "/dev/input/by-id/usb-Areson_PATRIOT_VIPER_MOUSE-event-if02"

void windowMove(int right) {
  Display *display;
  unsigned int arrow_key;
  unsigned int plus_key;
  unsigned int window_key;
  display = XOpenDisplay(NULL);
  
  window_key = XKeysymToKeycode(display, XK_Super_L);

  if(right) {
    arrow_key = XKeysymToKeycode(display, XK_Right);
  } else {
    arrow_key = XKeysymToKeycode(display, XK_Left);
  }

  XTestFakeKeyEvent(display, window_key, True, 0);
  XTestFakeKeyEvent(display, arrow_key, True, 0);
  XTestFakeKeyEvent(display, arrow_key, False, 0);
  XTestFakeKeyEvent(display, window_key, False, 0);
  XFlush(display);
}

int main()
{
  int fd;
  struct input_event event_data;

  if((fd = open(DEV_ADD, O_RDONLY)) == -1) {
    perror("opening device");
    exit(EXIT_FAILURE);
  }

  while (read(fd, &event_data, sizeof(event_data))) 
  {
    if(event_data.type == 3 && event_data.code == 48 && event_data.value != 0) {
      if (event_data.value == 1) {
        //printf("time %ld.%06ld: Right\n", event_data.time.tv_sec, event_data.time.tv_usec);
        windowMove(1);
      } else if (event_data.value == -1) {
        //printf("time %ld.%06ld: Left\n", event_data.time.tv_sec, event_data.time.tv_usec);
        windowMove(0);
      }
    }
  }
}
