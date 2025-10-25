/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

// Custom SERIAL_PIN Selection due to hardware failure
#undef SOFT_SERIAL_PIN
#define SERIAL_USART_TX_PIN GP10


// Select Handedness of the Keyboard
#define MASTER_LEFT // The USB connection has to be on the physical left half to function correctly


//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100
#define TAPPING_TERM 200
