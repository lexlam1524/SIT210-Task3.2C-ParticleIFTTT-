
#include "BH1750.h"
BH1750 sensor(0x23, Wire);

void setup()
{
  sensor.begin();

  sensor.set_sensor_mode(BH1750::forced_mode_high_res2);

  Serial.begin();
}

void loop()
{
  sensor.make_forced_measurement();
 float lightLevel = 1;
 if (lightLevel > 0 ) {
        Particle.publish("light_present", "light_present", PRIVATE);
    }
    else if (lightLevel <= 0) 
    {
        Particle.publish("light_absent", "light_absent", PRIVATE);
    }
    else{
        
    }
  Serial.println(String::format("%f", sensor.get_light_level()));
  
  delay(30000);
}
