#include "esphome.h"
#include "Keypad.h"

class KeypadSensor : public Component, public TextSensor {

    public:

    static const byte n_rows = 4;
    static const byte n_cols = 4;
    
    char keys[n_rows][n_cols] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
    };
    
    byte colPins[n_cols] = {D4, D3, D2, D1};
    byte rowPins[n_rows] = {D8, D7, D6, D5};
    
    Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols); 

    void setup() override {
    // This will be called by App.setup()
    }
    void loop() override {
    // This will be called by App.loop()
        char key[] = { keypad.getKey() };
        if (strlen(key) != 0){
		        publish_state(key);
        }
    }
};
