
node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto LoRaWAN = getValue<input_DEV>(ctx);
        auto xDevEUI = getValue<input_D_EUI>(ctx);
        auto xAppEUI = getValue<input_A_EUI>(ctx);
        auto xAppKey = getValue<input_A_Key>(ctx);
        auto xMode = getValue<input_Mode>(ctx);

        N=length(xDevEUI);
        N +=1;
        char cDevEUI[N];
        for(int i=0;i<N;i++)
            cDevEUI[i]=0;
        dump(xDevEUI, cDevEUI);

        N=length(xAppEUI);
        N +=1;
        char cAppEUI[N];
        for(int i=0;i<N;i++)
            cAppEUI[i]=0;
        dump(xAppEUI, cAppEUI);

        N=length(xAppKey);
        N +=1;
        char cAppKey[N];
        for(int i=0;i<N;i++)
            cAppKey[i]=0;
        dump(xAppKey, cAppKey);

        N=length(xMode);
        N +=1;
        char cMode[N];
        for(int i=0;i<N;i++)
            cMode[i]=0;
        dump(xMode, cMode);

        LoRaWAN->configOTTA(cDevEUI, cAppEUI, cAppKey, cMode);

        emitValue<output_Done>(ctx, 1);
    }
}
