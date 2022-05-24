
node {

    
    
    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto LoRaWAN = getValue<input_DEV>(ctx);
        auto lpp = getValue<input_LPP>(ctx);
        uint8_t cfm = getValue<input_CFM>(ctx);
        uint8_t trials = getValue<input_Trials>(ctx);
        //size_t len = getValue<input_Length>(ctx);

        lpp->reset();
        lpp->addGPS(1, 42.3519, -87.9094, 10);

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