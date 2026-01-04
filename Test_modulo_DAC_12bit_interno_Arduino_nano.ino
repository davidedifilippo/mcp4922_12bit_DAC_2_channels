
void setup() {
  // Inizializzo il mdulo di comunicazione seriale
  Serial.begin(115200);



  long start = millis() + 2500; // a 2.5 secondi da adesso

   //Aspetto 2.5s prima che il monitor seriale risponda
   //Se la board non è collegata ad un PC il serial monitor non risponderà
   while(!Serial && (millis() < start)) 
   delay(500);
  


  // Imposto la risoluzione del DAC a 12 bit (massima)
  analogWriteResolution(12);
  
  Serial.println("- Arduino Nano R4 - Test del modulo DAC ");
  Serial.println("- Generazione di tensioni precise sul pin A0");
  Serial.println("- Collegare un ultimetro al piedino per controllare la tensione generata dal modulo");
}

void loop() {
  // Genera differenti livelli incrementali di tensione
  int dacValues[] = {0, 1024, 2048, 3072, 4095}; 
  float voltages[] = {0.0, 1.25, 2.5, 3.75, 5.0};
  
  for (int i = 0; i < 5; i++) {
    analogWrite(DAC, dacValues[i]);
    
    Serial.print("- Valore digitale: ");
    Serial.print(dacValues[i]);
    Serial.print(" | Valore di tensione: ");
    Serial.print(voltages[i], 2);
    Serial.println(" VDC");
    
    // Mantiene costanti i livelli di tensione per 2 secondi
    delay(2000);  
  }
  
  Serial.println("- Ciclo completo.....");
  delay(2000);
}
