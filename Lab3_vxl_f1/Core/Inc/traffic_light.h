#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include <stdint.h>
#include "Led7Seg_Display.h"
#include "software_timer.h"
#include "global.h"

void decoder_Led(int);
void update_value_7segment();
void updateClockBuffer(uint16_t value_7seg0, uint16_t value_7seg1);
void scan_led();
void blink_Led(int index, int index1);
#endif /* INC_TRAFFIC_LIGHT_H_ */
