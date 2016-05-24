/*
Copyright 2016 Fred Sundvik <fsundvik@gmail.com>
Jun Wako <wakojun@gmail.com>

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

#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // layer 0 : default
        // left hand
        GRV, 1,   2,   3,   4,   5,   BSLS,
        TAB, Q,   W,   E,   R,   T,   FN0,
        LCTL,A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   FN0,
        ESC ,LALT,BSLS,LEFT,FN0,
                                            LCTL, LALT,
                                                  HOME,
                                      LGUI, BSPC, END,
        // right hand
             LBRC, 6, 7, 8,    9,   0,    MINS,
             RBRC, Y, U, I,    O,   P,    BSPC,
                   H, J, K,    L,   SCLN, QUOT,
             FN0,  N, M, COMM, DOT, SLSH, RSFT,
                       SPC, FN0, DOWN, UP, ENT,
        RALT,RCTL,
        PGUP,
        PGDN,ENT,RGUI
    ),

    KEYMAP(  // layer 1 : function and symbol keys
        /*// left hand*/
        BTLD, F1,   F2,   F3,   F4,   F5,   F11,
        FN10, FN11, FN12, FN13, FN14, FN15, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        BTLD, TRNS, TRNS, TRNS, TRNS,
                                      TRNS, TRNS,
                                            TRNS,
                                TRNS, TRNS, TRNS,
        // right hand
             F12,  F6,   F7,   F8,   F9,   F10,  TRNS,
             TRNS, FN16, FN17, FN18, FN19, FN20, EQL,
                   TRNS, LEFT, DOWN, UP,   RGHT, BSLS,
             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
                         TRNS, TRNS, TRNS, TRNS, BTLD,
        TRNS, TRNS,
        TRNS,
        TRNS, TRNS, TRNS
    ),

    /*KEYMAP(  // layer 2 : keyboard functions*/
        /*// left hand*/
        /*BTLD,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, FN3,*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,*/
                                      /*TRNS,TRNS,*/
                                           /*TRNS,*/
                                 /*TRNS,TRNS,TRNS,*/
        /*// right hand*/
             /*TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,BTLD,*/
             /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,*/
                  /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,*/
             /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,*/
                       /*TRNS,TRNS,TRNS,TRNS,TRNS,*/
        /*TRNS,TRNS,*/
        /*TRNS,*/
        /*TRNS,TRNS,TRNS*/
    /*),*/

    /*KEYMAP(  // layer 3: numpad*/
        /*// left hand*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,*/
        /*TRNS,TRNS,TRNS,TRNS,TRNS,*/
                                      /*TRNS,TRNS,*/
                                           /*TRNS,*/
                                 /*TRNS,TRNS,TRNS,*/
        /*// right hand*/
             /*TRNS,NLCK,PSLS,PAST,PAST,PMNS,BSPC,*/
             /*TRNS,NO,  P7,  P8,  P9,  PMNS,BSPC,*/
                  /*NO,  P4,  P5,  P6,  PPLS,PENT,*/
             /*TRNS,NO,  P1,  P2,  P3,  PPLS,PENT,*/
                       /*P0,  PDOT,SLSH,PENT,PENT,*/
        /*TRNS,TRNS,*/
        /*TRNS,*/
        /*TRNS,TRNS,TRNS*/
    /*),*/
};
const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),                      // FN0 - switch to Layer1
    [1] = ACTION_LAYER_SET(2, ON_PRESS),                  // FN1 - set Layer2
    [2] = ACTION_LAYER_TOGGLE(3),                         // FN2 - toggle Layer3 aka Numpad layer
    [3] = ACTION_LAYER_SET(0, ON_PRESS),                  // FN3 - set Layer0

    [10] = SHIFT(KC_GRV),
    [11] = SHIFT(KC_1),
    [12] = SHIFT(KC_2),
    [13] = SHIFT(KC_3),
    [14] = SHIFT(KC_4),
    [15] = SHIFT(KC_5),
    [16] = SHIFT(KC_6),
    [17] = SHIFT(KC_7),
    [18] = SHIFT(KC_8),
    [19] = SHIFT(KC_9),
    [20] = SHIFT(KC_0),
};
