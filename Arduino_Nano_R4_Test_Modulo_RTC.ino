
#include "RTC.h"

void setup() {
  // Initialize serial communication and wait up to 2.5 seconds for a connection
  Serial.begin(115200);

  long start = millis() + 2500;

   while(!Serial && (millis() < start)) 
   delay(500);
  
  Serial.println("- Arduino Nano R4 - RTC Basic Example started...");
  Serial.println("- Initializing RTC...");
  
  // Initialize RTC
  RTC.begin();
  
  //Set initial time: January 15, 2025, 12:00:00 PM, Monday
  RTCTime startTime(23, Month::DECEMBER, 2025, 18, 29, 0, DayOfWeek::TUESDAY, SaveLight::SAVING_TIME_INACTIVE);
  RTC.setTime(startTime);
  
  //Serial.println("- RTC time has been set to January 15, 2025, 12:00:00 PM");
  Serial.println("- Current date and time will be displayed every second");
}

void loop() {
  // Get current time from RTC
  RTCTime currentTime;
  RTC.getTime(currentTime);
  
  // Get individual values
  int year = currentTime.getYear();
  int month = Month2int(currentTime.getMonth());
  int day = currentTime.getDayOfMonth();
  
  int hour = currentTime.getHour();
  int minute = currentTime.getMinutes();
  int second = currentTime.getSeconds();
  
  // Display date (YYYY/MM/DD)
  Serial.print("Date: ");
  Serial.print(year);
  Serial.print("/");
  if (month < 10) Serial.print("0");
  Serial.print(month);
  Serial.print("/");
  if (day < 10) Serial.print("0");
  Serial.print(day);
  
  // Display time (HH:MM:SS)
  Serial.print(" | Time: ");
  if (hour < 10) Serial.print("0");
  Serial.print(hour);
  Serial.print(":");
  if (minute < 10) Serial.print("0");
  Serial.print(minute);
  Serial.print(":");
  if (second < 10) Serial.print("0");
  Serial.print(second);
  
  // Display day of week
  Serial.print(" | Day: ");
  DayOfWeek dayOfWeek = currentTime.getDayOfWeek();
  
  switch (dayOfWeek){
  case DayOfWeek::MONDAY: Serial.println("Monday"); break;
  case DayOfWeek::TUESDAY: Serial.println("Tuesday"); break;
  case DayOfWeek::WEDNESDAY: Serial.println("Wednesday"); break;
  case DayOfWeek::THURSDAY: Serial.println("Thursday"); break;
  case DayOfWeek::FRIDAY: Serial.println("Friday"); break;
  case DayOfWeek::SATURDAY: Serial.println("Saturday"); break;
  case DayOfWeek::SUNDAY: Serial.println("Sunday"); break;
  }

  

  
  // Wait one second before next reading
  delay(1000);
}
