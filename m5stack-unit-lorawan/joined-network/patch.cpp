#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto LoRaWAN = getValue<input_DEV>(ctx);

        emitValue<output_Joined>(ctx, LoRaWAN->checkJoinStatus());
        emitValue<output_Done>(ctx, 1);
    }
}
