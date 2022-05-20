
node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto LoRaWAN = getValue<input_DEV>(ctx);

        LoRaWAN->startJoin();

        emitValue<output_Done>(ctx, 1);
    }
}
