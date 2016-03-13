/*
Copyright 2016 Fred Sundvik <fsundvik@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keyboard.h"
#include "action_layer.h"
#include "visualizer.h"
#include "host.h"
#include "hooks.h"
#include "usb_main.h"
#include "serial_link/system/driver.h"

void early_init_hook(void) {
    init_serial_link();
    visualizer_init();
}

host_driver_t* keyboard_connect_hook(host_driver_t* default_driver) {
    while (true) {
      if(USB_DRIVER.state == USB_ACTIVE) {
          return default_driver;
      }
      if(is_serial_link_connected()) {
          return get_serial_link_driver();
      }
      serial_link_update();
      chThdSleepMilliseconds(50);
    }
}

void scan_loop_hook() {
    serial_link_update();
    visualizer_set_state(default_layer_state, layer_state, host_keyboard_leds());
}
