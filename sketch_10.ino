#include <KiwisIoT.h>



const char* ssid = "Your WiFi Name";

const char* pass = "Your WiFi Password";

const char* topic = "Your Dashboard Topic";



KiwisIoT kiwisiot(ssid, pass, topic);



#define LED_PIN D2



void onControl(String ch, String val) {



Serial.print("Channel: ");

Serial.print(ch);



Serial.print(" | Value: ");

Serial.println(val);



if (ch != "0") return;



if (val == "1") {

digitalWrite(LED_PIN, HIGH);

Serial.println("LED ON");

}

else if (val == "0") {

digitalWrite(LED_PIN, LOW);

Serial.println("LED OFF");

}

}



void setup() {



Serial.begin(115200);



pinMode(LED_PIN, OUTPUT);

digitalWrite(LED_PIN, LOW);



kiwisiot.begin();

kiwisiot.onReceive(onControl);



Serial.println("KiwisIoT LED Control Ready");

}



void loop() {

kiwisiot.run();

}