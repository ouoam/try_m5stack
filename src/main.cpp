#include <Arduino.h>
#include <M5Stack.h>
// #include <WiFi.h>
// #include "AudioFileSourceSD.h"
// #include "AudioGeneratorWAV.h"
// #include "AudioOutputI2S.h"

// AudioGeneratorWAV *wav;
// AudioFileSourceSD *file;
// AudioOutputI2S *out;

float gain = 1.0;

void setup()
{
  M5.begin();

  // M5.Lcd.setTextFont(2);
  // M5.Lcd.printf("Sample WAV playback begins...\n");
  // Serial.printf("Sample WAV playback begins...\n");

  // // pno_cs from https://ccrma.stanford.edu/~jos/pasp/Sound_Examples.html
  // file = new AudioFileSourceSD("/Shelter.wav");
  // out = new AudioOutputI2S(0, 1); // Output to builtInDAC
  // out->SetOutputModeMono(true);
  // wav = new AudioGeneratorWAV();
  // wav->begin(file, out);
}

void changeGain()
{
  if (gain <= 1)
    gain = 1;
  if (gain >= 10)
    gain = 10;
  // out->SetGain(gain);
  M5.Speaker.setVolume(gain);
  M5.Lcd.printf("Change gain to %.1f\n", gain);
}

unsigned long nextCanClickA = 0;
unsigned long nextCanClickC = 0;

void loop()
{
  M5.update();
  if (M5.BtnA.isPressed() && millis() > nextCanClickA)
  {
    gain--;
    changeGain();
    nextCanClickA = millis() + 100;
  }
  if (M5.BtnC.isPressed() && millis() > nextCanClickC)
  {
    gain++;
    changeGain();
    nextCanClickC = millis() + 100;
  }

  if (M5.BtnB.isPressed())
  {
    M5.Speaker.beep();
  }

  // if (wav->isRunning())
  // {
  //   if (!wav->loop())
  //     wav->stop();
  // }
  // else
  // {
  //   Serial.printf("WAV done\n");
  //   delay(1000);
  // }
}