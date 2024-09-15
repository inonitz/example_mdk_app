#include <awc2/awc2.hpp>
#include <awc2/entry.hpp>


namespace AIN = AWC2::Input;


inline void custom_mousebutton_callback(AWC2::user_callback_mousebutton_struct const* data)
{
    u8 state = (
        AIN::mouseButton::RIGHT == data->button &&
        AIN::inputState::PRESS  == data->action
    );
    if(state)
        AIN::setCursorMode(AIN::cursorMode::SCREEN_BOUND);
    else
        AIN::setCursorMode(AIN::cursorMode::NORMAL);


    return;
}


int main() {

    AWC2::init();

    auto id = AWC2::createContext();
    AWC2::initializeContext(id, 1920, 1080, AWC2::WindowDescriptor{});
    AWC2::setContextUserCallback(id, &custom_mousebutton_callback);


    while(!AWC2::getContextStatus(id)) {
        AWC2::newFrame();
    }
    AWC2::destroy();
    return 0;
}