/*
  Balloon Pilot
  
 Authors: 	Andy Kirby andy@kirbyand.co.uk
		Your Namehere, Namehere@yourdomain.etc
 Libraries: Arduino, 
 
 A Firmware for piloting High Altitude Balloon FLights using either an ATMega644 or AMega1284.
 
 
 WishList:
   Gondola Temperature
   Gondola Humidity
   Gondola Barometric Pressure
   GPS Position Fixing
   Datalogging to SD card
   Telemetry Tx
   Battery Monitoring and charging
   Mission Abort
   Sleep/Power Save Mode
   Watch Dog Timer Protection
   Brown Out Detection

 
 Pin Allocation:-
 
 644, Sanguino,  BPilot, 	Author.
 --------------------------------------
 1,   Reset,     Reset.		System, AK
 2,   RX/D0,     Serial RX.	System, AK
 3,   TX/D1,     Serial TX.	System, AK
 4,   D2,        
 5,   D3/PWM,    
 6,   D4,        
 7,   Vcc,       +5V		System, AK
 8,   Gnd,       Gnd		System, AK
 9,   Xtal,      Xtal		System, AK
 10,  Xtal,      Xtal		System, AK
 11,  D5/PWM,    
 12,  D6/PWM,    
 13,  D7,        
 14,  D8,        
 15,  D9/PWM,    
 16,  D10/PWM,   
 17,  D11/PWM/mosi, 
 18,  D12/miso, 
 19,  D13/sck,
 20,  Vcc,       
 21,  ARef,      
 22,  Gnd,       
 23,  A0/D14,    
 24,  A1/D15,    
 25,  A2/D16,    
 26,  A3, 
 27,  A4/SDA,    
 28,  A5/SCL,    
 29,
 30,
 31,
 32,
 33,
 34,
 35,
 36,
 37,
 38,
 39,
 40,

When you add code that uses pins, note them here along with their purpose 
and your initials so no one else atempts to double use them. System means 
the pins is used for esseential uControler stuff and cannot be reused for
something else.
 

 Notes:
 * If you are writing a task that may take more than one slot time write it as a re-entrant state machine then call it often enough by adding it to as many slots as is neccesary.
 * Avoid busy waits as much as possible, always wait on a condition not a time. Timing should all be taken care of by the scheduler and then spare can contribute towards sleep/power saving.

*/


/* includes */


/* Constants */
#define DebugPin 14  // Digital Pin LED is connected to
#define SpkrPin 9    // Digital Pin Piezo SPeaker is connected to
#define Slots 20     // Number of shedukling slots per second for multitasking
#define WDTTime	2     // Watch Dog Timer value in slots


// Globals
unsigned long slottime; // how much time each slot gets
unsigned long nextturn; // variable that holds the terminal millis count for a slot
char SlotCounter = 0;   // Current slot indicator



// Main setup routines
void setup() {
   // initialize the debug pin as an output and make sure it is off.
   pinMode(DebugPin, OUTPUT);

   // setup essential values for slots
   slottime = 1000000/Slots;
   
   // Enable brown out detection

   // Setup watchgdog timer for around WDTTimer slot times
     
   // Calculate when the first loops interval should finish ie
   // interval microseconds from now
   nextturn = micros() + slottime; 
}


// Main Loop or body of application
void loop() {
   // Tasks to carry out every cycle assumes a 1 second epoch divided into 1/Slot cycles
      // detect if we are here courtesy of BOD, and action something if we are
      // detect if we are here courtesy of WDT timeout, and action something if we are
  
   // Tasks to carry out on the nth cycle. Not every task needs to run every cycle
   // the tasks are best spread out to keep the loop duration evenly short
   switch(slotcounter++) {
      case 0:
         // Do slot 0 tasks here
         break;
      case 1:
         // Do slot 1 tasks here
         // Example Twice_a_second_task(); etc
            Twice_a_second_task();    
         break;
      case 2:
         // Do slot whatever tasks here  
         break;    
      case 3:
         // Do slot whatever tasks here
         break;
      case 4:
         // Do slot whatever tasks here
         break;    
      case 5:
         // Do slot whatever tasks here
         break;    
      case 6:
         // Do slot whatever tasks here
         break;    
      case 7:
         // Do slot whatever tasks here
         break;    
      case 8:
         // Do slot whatever tasks here
         break;    
      case 9:
          // Do slot whatever tasks here
         break;    
      case 10:
         // Do slot whatever tasks here
         break;    
      case 11:
         // Do slot whatever tasks here
         // Example Twice_a_second_task(); etc
            Twice_a_second_task();    
         break;    
      case 12:
         // Do slot whatever tasks here
         break;    
      case 13:
          // Do slot whatever tasks here
         break;    
      case 14:
         // Do slot whatever tasks here
         break;
      case 15:
         // Do slot whatever tasks here        
         break;
      case 16:
          // Do slot whatever tasks here    
         break;
      case 17:
         // Do slot whatever tasks here
         break;    
      case 18:
         // Do slot whatever tasks here
         break;       
      case 19:
         slotcounter = 0; // reset the scheduling counter
         break;       
      default: // Should never actualy do this one unless we have screwed up...
         break;
  }

  // Turn off debug LED to ignore waiting part of loop  
  digitalWrite(DebugPin, LOW); 

  // Busy wait for what ever is left of this loop's interval to expire
  while( nextturn - micros() < Interval ) {
     // If doing power save use power down sleep instructions here
  }

  // Turn on debug LED to time active part of loop with a scope
  digitalWrite(DebugPin, HIGH); 
  
  // Calculate end of next cycle time  
  nextturn += slottime;

  // Kick Watch Dog, ie reset the watch dog timer
}


// Example twice a second task, note it appears twice in the schedule evenly spaced.
void Twice_a_second_task() {
   return;
}    



