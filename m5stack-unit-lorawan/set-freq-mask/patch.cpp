
node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto LoRaWAN = getValue<input_DEV>(ctx);
        auto xMask = getValue<input_Mask>(ctx);

        int N=length(xMask)+1;
        char cMask[N];
        for(int i=0;i<N;i++)
            cMask[i]=0;
        dump(xMask, cMask);

        LoRaWAN->setFreqMask(cMask);

        emitValue<output_Done>(ctx, 1);
    }
}
