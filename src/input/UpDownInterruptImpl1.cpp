#include "UpDownInterruptImpl1.h"
#include "InputBroker.h"

UpDownInterruptImpl1 *upDownInterruptImpl1;

UpDownInterruptImpl1::UpDownInterruptImpl1() : UpDownInterruptBase("upDown1") {}

bool UpDownInterruptImpl1::init()
{

    if (!moduleConfig.canned_message.updown1_enabled) {
        // Input device is disabled.
        return false;
    }

    uint8_t pinUp = moduleConfig.canned_message.inputbroker_pin_a;
    uint8_t pinDown = moduleConfig.canned_message.inputbroker_pin_b;
    uint8_t pinPress = moduleConfig.canned_message.inputbroker_pin_press;

    input_broker_event eventDown = INPUT_BROKER_DOWN;
    input_broker_event eventUp = INPUT_BROKER_UP;
    input_broker_event eventPressed = INPUT_BROKER_SELECT;

    UpDownInterruptBase::init(pinDown, pinUp, pinPress, eventDown, eventUp, eventPressed, UpDownInterruptImpl1::handleIntDown,
                              UpDownInterruptImpl1::handleIntUp, UpDownInterruptImpl1::handleIntPressed);
    inputBroker->registerSource(this);
    return true;
}

void UpDownInterruptImpl1::handleIntDown()
{
    upDownInterruptImpl1->intDownHandler();
}
void UpDownInterruptImpl1::handleIntUp()
{
    upDownInterruptImpl1->intUpHandler();
}
void UpDownInterruptImpl1::handleIntPressed()
{
    upDownInterruptImpl1->intPressHandler();
}