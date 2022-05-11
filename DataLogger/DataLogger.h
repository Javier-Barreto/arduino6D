#define MICROSD_PIN 5
#define EXTENSION ".json"
#include <ArduinoJson.h>
#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <RTClib.h>
RTC_DS1307 rtc;

File MicroSD_File;

#include "RTC.h"
DS1307_RTC RRTC;

#include "MicroSD.h"
MicroSD MSD;
