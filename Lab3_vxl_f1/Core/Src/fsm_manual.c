#include "fsm_manual.h"

void fsm_manual() {
    // 1. Handle manual user intervention to change system modes
    if (isPressed(0)) {
        button0_value++;
        
        // Wrap around from Mode 4 back to Mode 1[cite: 21]
        if (button0_value > 4) {
            button0_value = 1; 
            fsm_automatic_init(); // Reset automatic countdowns
        }
    }

    // 2. Route to the correct sub-module based on the current mode[cite: 21]
    switch (button0_value) {
        case 1:
            // Mode 1: Normal Mode[cite: 21]
            fsm_automatic();
            break;
        case 2:
            // Mode 2: Modify Red LEDs[cite: 21]
            fsm_setting(SETTING_0);
            break;
        case 3:
            // Mode 3: Modify Amber LEDs[cite: 21]
            fsm_setting(SETTING_1);
            break;
        case 4:
            // Mode 4: Modify Green LEDs[cite: 21]
            fsm_setting(SETTING_2);
            break;
        default:
            button0_value = 1;
            break;
    }
}