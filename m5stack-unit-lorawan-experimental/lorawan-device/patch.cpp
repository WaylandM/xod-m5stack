#pragma XOD require "https://github.com/WaylandM/M5Stack_UNIT_LoRaWAN"

#include <M5Stack_UNIT_LoRaWAN.h>

node {
    meta {
        using Type = M5Stack_UNIT_LoRaWAN*;
    }

    M5Stack_UNIT_LoRaWAN LoRaWAN = M5Stack_UNIT_LoRaWAN();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        auto uart = getValue<input_UART>(ctx);

        LoRaWAN.Init(*(uart->toStream()));

        emitValue<output_DEV>(ctx, &LoRaWAN);
    }
}
