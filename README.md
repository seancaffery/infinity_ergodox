TMK/chibios for Input Club Infinity Ergodox
===========================================

This is an unofficial keyboard firmware for Infinity Ergodox. 

[http://input.club/devices/infinity-ergodox](http://input.club/devices/infinity-ergodox)
    
It is based on Jun Wako's TMK firmware

[https://github.com/tmk/tmk_core](https://github.com/tmk/tmk_core) and [https://github.com/tmk/tmk_keyboard](https://github.com/tmk/tmk_keyboard). The readme files for those projects has a lot of useful information, as do the [Wiki](https://github.com/tmk/tmk_keyboard/wiki).

Git notes
---------
This repository uses submodules, so usually you need to run:
`git submodule update --init --recursive`
after you clone the repository, and after that, every time you switch a branch or pull a new version.

Prerequisites
-------------
If you are using Windows, I recommend that you use Cygwin (that's what I'm using). I haven't tested any other operating systems, but if you can install the required tools it will probably work.

In order to compile the firmware you need:

1.  GNU make
1.  [GCC ARM Embedded](https://launchpad.net/gcc-arm-embedded). Note that the 5.x and 6.x versions don't work at the moment, so I recommend that you download the 4.9 version.
    
    You can also download the ChibiStudio from [www.chibios.org](http://www.chibios.org), which comes with eclipse and other tools.

	Make sure to add the bin folder to the path. In Cygwin you can edit .bash_profile in your home directory and add it. Here's what I added to the end of the file `PATH="${PATH}:/cygdrive/C/ChibiStudio/tools/GNU Tools ARM Embedded/4.9 2015q3/bin"`
1. dfu-util - On windows you also need to install some drivers. You can find more detailed instructions on the [Kiibohd controller wiki page](https://github.com/kiibohd/controller/wiki/Loading-DFU-Firmware). You also need to ensure that dfu-util is in your path.

Build
-----
Just run  
$ make  
to build the everything.

Upload
------
To upload(flash) a new firmware to the keyboard run  
$ make program

Changing keyboard layout
------------------------
Changing the keyboard layout works the same way as for the other TMK based keyboards. So read [this](https://github.com/tmk/tmk_keyboard/wiki/FAQ-Keymap).

LCD Visualization
-----------------
In order to customize the LCD visualization, which includes both the backlight and the LCD screen display itself, you need to edit the visualizer_user.c file. The file is quite well commented, so just read through the comments, and start experimenting. At the very least you probably want to edit the layer names and colors, in the update_user_visualizer_state function.
