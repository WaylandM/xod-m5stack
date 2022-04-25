
node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto LoRaWAN = getValue<input_DEV>(ctx);

        emitValue<output_Conn>(ctx, LoRaWAN->checkDeviceConnect());
        emitValue<output_Done>(ctx, 1);
    }
}
