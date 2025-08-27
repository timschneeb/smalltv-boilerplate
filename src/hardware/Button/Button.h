#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON2_HAS_STD_FUNCTION

#include <Button2.h>
#include <OneButton.h>

#ifndef TOUCH_PIN
#define TOUCH_PIN 9
#endif
/**
 * @class button
 * @brief Button class derived from OneButton to manage touch sensor input.
 * @details This class provides functionality for handling button presses,
 *          including single, double, and long presses.
 * @note The default pin for the touch sensor is defined as TOUCH_PIN (GPIO 16).
 * @ingroup Hardware
 */

class button {
private:
    Button2 button2;
    int threshold = 1500; // ESP32S3
    byte buttonState = HIGH;
    callbackFunction onClick;
    callbackFunction onLongPress;

public:
    button();
    void tick(void);

    // save function for click event
    void attachClick(callbackFunction newFunction);

    void attachLongPressStart(callbackFunction newFunction);

    bool touchdetected = false;
};

extern button Button;

#endif // BUTTON_H
