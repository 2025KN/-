includes Test;
configuration TestAppC
{
}
implementation
{
        components TestC, MainC;
        components  LedsC, new TimerMilliC();

        components ActiveMessageC as AMC;
        components new AMSenderC(AM_TEST_DATA_MSG) as AMSC;

        TestC.Boot -> MainC;
        TestC.Leds -> LedsC;
        TestC.MilliTimer -> TimerMilliC;

        TestC.RadioControl -> AMC;
        TestC.RadioSend -> AMSC;

        components new SensirionSht11C() as Sht11ChOC;
        TestC.Temp -> Sht11ChOC.Temperature;
        TestC.Humi -> Sht11ChOC.Humidity;

        components new IlluAdcC() as Illu;
        TestC.Illu -> Illu;

        components BatteryC;
        TestC.Battery -> BatteryC;
}
