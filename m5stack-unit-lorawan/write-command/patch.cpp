
node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto LoRaWAN = getValue<input_DEV>(ctx);
        auto xString = getValue<input_CMD>(ctx);
        
        int N=length(xString)+1;
        char cString[N];
        for(int i=0;i<N;i++)
            cString[i]=0;
        dump(xString, cString);

        LoRaWAN->writeCMD(cString);

        emitValue<output_Done>(ctx, 1);
    }
}
