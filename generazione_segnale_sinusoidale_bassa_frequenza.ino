/**
DAC Basic Output Example for the Arduino Nano R4 Board
Name: nano_r4_dac_basic.ino
Purpose: This sketch demonstrates how to use the DAC to generate
precise analog voltages on pin A0.

@author Arduino Product Experience Team
@version 1.0 01/06/25
Modificato da Ing. Di Filippo Gennaio 2026 
*/

void setup() {
   // Inizializzo il mdulo di comunicazione seriale
  Serial.begin(115200);
  long start = millis() + 2500; // Start a 2.5 secondi da adesso

   //Aspetto 2.5s prima che il monitor seriale risponda
   //Se la board non è collegata ad un PC il serial monitor non risponderà
   while(!Serial && (millis() < start)) 
   delay(500);
  

  // Set DAC resolution to 12-bit for maximum precision
  analogWriteResolution(12);
  
  Serial.println("- Arduino Nano R4 - DAC Basic Output Example started...");
  Serial.println("- Generating precise voltages on pin A0");
  Serial.println("- Connect a multimeter to A0 to measure output");
}

void loop() {
  // Generate different voltage levels
  // 0, +1.25, +2.5, +3.75 and +5 VDC
  int dacValues[] = {0, 1024, 2048, 3072, 4095}; 
  float voltages[] = {0.0, 1.25, 2.5, 3.75, 5.0};
  
  for (int i = 0; i < 5; i++) {
    analogWrite(DAC, dacValues[i]);
    
    Serial.print("- DAC Value: ");
    Serial.print(dacValues[i]);
    Serial.print(" | Target Voltage: ");
    Serial.print(voltages[i], 2);
    Serial.println(" VDC");
    
    // Hold each voltage for 2 seconds
    delay(2000);  
  }
  
  Serial.println("- Cycle completed, repeating...");
  delay(1000);
}
