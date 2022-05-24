
node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto LoRaWAN = getValue<input_DEV>(ctx);
        auto xString = getValue<input_MSG>(ctx);
        uint8_t cfm = getValue<input_CFM>(ctx);
        uint8_t trials = getValue<input_Trials>(ctx);
        
        int N=length(xString)+1;
        char cString[N];
        for(int i=0;i<N;i++)
            cString[i]=0;
        dump(xString, cString);
        //LoRaWAN->sendMsg(1, 15, 7, "4d35535441434b");
        // uint8_t confirm, uint8_t nbtrials, size_t length, String data
        LoRaWAN->sendMsg(cfm,
                         trials,
                         N-1,
                         cString);

        emitValue<output_Done>(ctx, 1);
    }
}
