
node {

    void evaluate(Context ctx) {

        LoRaWAN->writeCMD("AT+CWORKMODE=2\r\n");
        //LoRaWAN->setRxWindow("869525000");
        LoRaWAN->startJoin

    }
}
