#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto LoRaWAN = getValue<input_DEV>(ctx);
        auto lpp = getValue<input_LPP>(ctx);
        uint8_t cfm = getValue<input_CFM>(ctx);
        uint8_t trials = getValue<input_Trials>(ctx);

        int N=lpp->getSize();
        
        uint8_t* buff = lpp->getBuffer();

        // Convert byte array from lpp to String required for AT command to be sent to LoRa device
        static String payload;
        for (int i=0;i<N;i++) {
            payload += "0123456789ABCDEF"[*(buff+i) / 16];
            payload += "0123456789ABCDEF"[*(buff+i) % 16];
        }        

        LoRaWAN->sendMsg(cfm,
                        trials,
                        N,
                        payload);

        payload = "";
    
        emitValue<output_Done>(ctx, 1);
    }
}
