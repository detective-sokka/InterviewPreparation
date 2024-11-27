class SmartLampSDK {

public:
   // Constructor
   SmartLampSDK();

   // Powers on the Smart Lamp. Returns true if successful, false otherwise.
   bool powerOn();

   // Powers off the Smart Lamp. Returns true if successful, false otherwise.
   bool powerOff();

   // Sets the brightness level (0-100). Returns true if successful, false otherwise.
   bool setBrightness(int level);

private:
   bool isPoweredOn;
   int currentBrightness;
};

SmartLampSDK::SmartLampSDK(){

    this->isPoweredOn = false;
}

bool SmartLampSDK::powerOn(){

    if (this->isPoweredOn) // already on
        return false;

    this->isPoweredOn = true;
    return true;
}

bool SmartLampSDK::powerOff(){

    if (!this->isPoweredOn) // already off
        return false;

    this->isPoweredOn = false;    
    this->currentBrightness = 0;    
    return true;
}

bool SmartLampSDK::setBrightness(int level){

    if (level < 0 || level > 100)
        return false;

    if (!this->isPoweredOn)
        return false;
    
    this->currentBrightness = level;
    return true;

}

int main()
{
    return 0;
}