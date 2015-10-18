/* Example Sketch for the GY-87 (Adafruit 10DOF clone board).

Compiled by James Muirhead http://www.james-muirhead.com

2014-08-18 - Initial compilation of 3 example files for 3 different chipsets found on board.

*/

#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include <HMC5883L.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp = Adafruit_BMP085(10085);

HMC5883L compass;

MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup()
{
  Wire.begin();
  Serial.begin(38400);
  
  // Initialisation of MPU6050 Accelerometer / Gyroscope Unit.
  Serial.println("Initializing Accellerometer/Gyroscope...");
    accelgyro.initialize();
  Serial.println("Testing Acc/Gyr connection...");
  if ( accelgyro.testConnection() )
        Serial.println( "MPU6050 connection successful" );
    else
        Serial.println( "MPU6050 connection failed" );
        
  // Initialisation of HMC5883L Megnetometer.
  compass = HMC5883L(); // Construct a new HMC5883 compass.
  int error = compass.SetScale(1.3); // Set the scale of the compass.
  if(error != 0) // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
  error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
  if(error != 0) // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));      
        
  // Initialise the Air Pressure Module.
  if(!bmp.begin())
  {
    Serial.print("no BMP085 detected.");
    while(1);
  } 
  Serial.println( "Accellerometer xyz\t\tGyroscope xyz\t\t\tMagnetometer xyzh\t\t\t\tAirPressure,temp,alt" ); 
}

void AccGyr()
{
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // these methods (and a few others) are also available
  //accelgyro.getAcceleration(&ax, &ay, &az);
  //accelgyro.getRotation(&gx, &gy, &gz);

  // display tab-separated accel/gyro x/y/z values
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print("*\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.print(gz);
}

void Magnet()
{
  MagnetometerRaw raw = compass.ReadRawAxis();
  MagnetometerScaled scaled = compass.ReadScaledAxis();
  int MilliGauss_OnThe_XAxis = scaled.XAxis;
  float heading = atan2(scaled.YAxis, scaled.XAxis);
  float declinationAngle = 0.0457;
  heading += declinationAngle;
  if(heading < 0)
      heading += 2*PI;
  if(heading > 2*PI)
      heading -= 2*PI;
  float headingDegrees = heading * 180/M_PI;
  
  // Outputs Raw Sensor Data
  //Serial.print("Raw:\t");
  //Serial.print(raw.XAxis);
  //Serial.print("   ");   
  //Serial.print(raw.YAxis);
  //Serial.print("   ");   
  //Serial.print(raw.ZAxis);
  //Serial.print("   \tScaled:\t");
  
  // Outputs Scaled Sensor Data 
  Serial.print("\t*\t");
  Serial.print(scaled.XAxis);
  Serial.print("\t");   
  Serial.print(scaled.YAxis);
  Serial.print("\t");   
  Serial.print(scaled.ZAxis);

  // Outputs Heading in Radians and Degrees.
  Serial.print("\tHeading:");
  //Serial.print(heading);
  //Serial.print(" Radians   \t");
  Serial.print(headingDegrees);
  //Serial.print("\t Degrees   \t");
  Serial.print( char(176) );
  Serial.print( "\t" );
}

void AirPressure()
{
    sensors_event_t event;
    bmp.getEvent(&event);
    if (event.pressure)
  {
    /* Display atmospheric pressue in hPa */
    //Serial.print("Pressure:    ");
    Serial.print("*\t");
    Serial.print(event.pressure);
    Serial.print("hPa\t");
    float temperature;
    bmp.getTemperature(&temperature);
    //Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print( char(176) );
    Serial.print("C\t");

    /* Then convert the atmospheric pressure, SLP and temp to altitude    */
    /* Update this next line with the current SLP for better results      */
    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    //Serial.print("Altitude:    "); 
    Serial.print(bmp.pressureToAltitude(seaLevelPressure,
                                        event.pressure,
                                        temperature)); 
    Serial.println("m");
    //Serial.println("");
  }
  else
  {
    Serial.println("Sensor error");
  } 
}

void loop()
{

  AccGyr();
  Magnet();
  AirPressure();
}
        
        
        
        
        
        
        
        
        
