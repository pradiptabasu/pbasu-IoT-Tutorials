#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <fauxmoESP.h>
fauxmoESP fauxmo;
void setup() { 
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  if (connectWifi()) {
    // Setup fauxmo
     Serial.println("Adding Onboard Indicator device");
     fauxmo.setPort(80);  
     fauxmo.enable(true);
     fauxmo.addDevice("Onboard Indicator");   
  }
  
  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
        
        // Callback when a command from Alexa is received. 
        // You can use device_id or device_name to choose the element to perform an action onto (relay, LED,...)
        // State is a boolean (ON/OFF) and value a number from 0 to 255 (if you say "set kitchen light to 50%" you will receive a 128 here).
        // Just remember not to delay too much here, this is a callback, exit as soon as possible.
        // If you have to do something more involved here set a flag and process it in your main loop.
        
        Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);
 
        // Checking for device_id is simpler if you are certain about the order they are loaded and it does not change.
        // Otherwise comparing the device_name is safer.
 
        //if (strcmp(device_name, ID_YELLOW)==0) {
        //    digitalWrite(LED_YELLOW, state ? HIGH : LOW);
        //} else if (strcmp(device_name, ID_GREEN)==0) {
        //    digitalWrite(LED_GREEN, state ? HIGH : LOW);
        //} else if (strcmp(device_name, ID_BLUE)==0) {
        //    digitalWrite(LED_BLUE, state ? HIGH : LOW);
        //} else if (strcmp(device_name, ID_PINK)==0) {
        //    digitalWrite(LED_PINK, state ? HIGH : LOW);
        //} else if (strcmp(device_name, ID_WHITE)==0) {
        //    digitalWrite(LED_WHITE, state ? HIGH : LOW);
        //}
    
    
      if (strcmp(device_name, "Onboard Indicator")==0) {
        if(!state)
           digitalWrite(2, HIGH);
        else
          digitalWrite(2, LOW);
      }
 
    });
}


void loop() {
  fauxmo.handle();
}


boolean connectWifi() {
  // Let us connect to WiFi
  WiFi.begin("DarkangeLBB", "Wipro@123");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(".......");
  Serial.println("WiFi Connected....IP Address:");
  Serial.println(WiFi.localIP());
  return true;
}
