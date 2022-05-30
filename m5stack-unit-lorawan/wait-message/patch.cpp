#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    CStringView view;
    char* cString;
    size_t cap;
    
    void evaluate(Context ctx) {
        if (isSettingUp()) {
            cap = getValue<input_Size>(ctx) + 1;
            cString = new char[cap];
            view = CStringView(cString);
        }

        if (isInputDirty<input_UPD>(ctx)) {
            auto LoRaWAN = getValue<input_DEV>(ctx);
            String str = LoRaWAN->waitMsg(getValue<input_ms>(ctx));
            int strLen = str.length() + 1;
            str.toCharArray(cString, strLen);
            emitValue<output_Msg>(ctx, XString(&view));
            emitValue<output_Done>(ctx, 1);
        }

    }
}
