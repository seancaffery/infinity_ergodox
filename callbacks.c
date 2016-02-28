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
#include "serial_link/system/system.h"
#include "serial_link/protocol/transport.h"
#include "print.h"

static systime_t last_update = 0;

typedef struct {
    uint32_t test;
} test_object1_t;


SLAVE_TO_MASTER_OBJECT(slave_to_master, test_object1_t);

remote_object_t* test_remote_objects[] = {
    REMOTE_OBJECT(slave_to_master),
};

void post_keyboard_init(void) {
    visualizer_init();
    #define RGB_MODE PORTx_PCRn_SRE | PORTx_PCRn_DSE | PORTx_PCRn_MUX(4)

    PORTA->PCR[1] = PORTx_PCRn_PE | PORTx_PCRn_PS | PORTx_PCRn_PFE | PORTx_PCRn_MUX(2);
    PORTA->PCR[2] = PORTx_PCRn_DSE | PORTx_PCRn_SRE | PORTx_PCRn_MUX(2);
    PORTE->PCR[0] = PORTx_PCRn_PE | PORTx_PCRn_PS | PORTx_PCRn_PFE | PORTx_PCRn_MUX(3);
    PORTE->PCR[1] = PORTx_PCRn_DSE | PORTx_PCRn_SRE | PORTx_PCRn_MUX(3);

    init_transport(test_remote_objects, sizeof(test_remote_objects)/sizeof(remote_object_t*));
    init_serial_link();

}

void post_keyboard_task() {
    visualizer_set_state(default_layer_state, layer_state, host_keyboard_leds());
    systime_t current_time = chVTGetSystemTimeX();
    if (current_time - last_update > 1000) {
        test_object1_t* obj = begin_write_slave_to_master();
        obj->test = current_time;
        end_write_slave_to_master();
        xprintf("writing %d\n", current_time);
        last_update = current_time;
    }
    test_object1_t* obj = read_slave_to_master(0);
    if (obj) {
        xprintf("%d\n", obj->test);
    }
    obj = read_slave_to_master(1);
    if (obj) {
        xprintf("%d\n", obj->test);
    }
}
