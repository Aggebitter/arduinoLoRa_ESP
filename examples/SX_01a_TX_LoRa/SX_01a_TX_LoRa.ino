/*  
 *  LoRa 433 / 868 / 915MHz SX1272/76/78/79 LoRa module
 *  
 *  Based on driver from libelium ported to ESP32 
 *
 *  Libelium part starts here: 
 *  
 *  Copyright (C) Libelium Comunicaciones Distribuidas S.L. 
 *  http://www.libelium.com 
 *  
 *  This program is free software: you can redistribute it and/or modify 
 *  it under the terms of the GNU General Public License as published by 
 *  the Free Software Foundation, either version 3 of the License, or 
 *  (at your option) any later version. 
 *  
 *  This program is distributed in the hope that it will be useful, 
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License 
 *  along with this program.  If not, see http://www.gnu.org/licenses/. 
 *  
 *  Version:           1.2
 *  Design:            David Gascón
 *  Implementation:    Covadonga Albiñana, Victor Boria, Ruben Martin
 *  
 *  Libelium ends here
 *  
 *  Version 1.3
 *  Implementation: Agge Bitter
 *  
 *  Port to ESP-32/8266 and newer Arduino IDE, tested on 1.8.5
 */

// Debugger 

//#include <Wire.h>

// Cooking API libraries
//#include <arduinoUtils.h>

// Include the SX1272 and SPI library:
#include "arduinoLoRa.h"
#include <SPI.h>

const char* register_name_lora[]={
"RegFifo","RegOpMode","Unused","Unused",
"Unused","Unused","RegFrfMsb","RegFrfMid",
"RegFrfLsb","RegPaConfig","RegPaRamp","RegOcp",
"RegLna","RegFifoAddrPtr","RegFifoTxBaseAddr","RegFifoRxBaseAddr",
"FifoRxCurrentAddr","RegIrqFlagsMask","RegIrqFlags","RegRxNbBytes",
"RegRxHeaderCntValueMsb","RegRxHeaderCntValueLsb","RegRxPacketCntValueMsb","RegRxPacketCntValueLsb",
"RegModemStat","RegPktSnrValue","RegPktRssiValue","RegRssiValue",
"RegHopChannel","RegModemConfig1","RegModemConfig2","RegSymbTimeoutLsb",
"RegPreambleMsb","RegPreambleLsb","RegPayloadLength","RegMaxPayloadLength",
"RegHopPeriod","RegFifoRxByteAddr","RegModemConfig3","RESERVED",
"RegFeiMsb","RegFeiMid","RegFeiLsb","RESERVED",
"RegRssiWideband","RESERVED","RESERVED","RESERVED",
"RESERVED","RegDetectOptimize","RESERVED","RegInvertIQ",
"RESERVED","RESERVED","RESERVED","RegDetectionThreshold",
"RESERVED","RegSyncWord","RESERVED","RESERVED",
"RESERVED","RESERVED","RESERVED","RESERVED",
"RegDioMapping1","RegDioMapping2","RegVersion","No documentation",
"Unused","No documentation","No documentation","No documentation",
"No documentation","No documentation","No documentation","RegTcxo",
"No documentation","RegPaDac","No documentation","No documentation",
"No documentation","No documentation","No documentation","No documentation",
"No documentation","No documentation","No documentation","No documentation",
"No documentation","No documentation","No documentation","RegFormerTemp",
"No documentation","No documentation","Unused","No documentation",
"No documentation","No documentation","RegAgcRef","RegAgcThresh1",
"RegAgcThresh2","RegAgcThresh3","No documentation","No documentation",
"No documentation","No documentation","No documentation","No documentation",
"No documentation","No documentation","No documentation","No documentation",
"No documentation","RegPllLf","RegTest Do not write","RegTest Do not write",
"RegTest Do not write","RegTest Do not write","RegTest Do not write","RegTest Do not write",
"RegTest Do not write","RegTest Do not write","RegTest Do not write","RegTest Do not write",
"RegTest Do not write","RegTest Do not write","RegTest Do not write","RegTest Do not write",
"RegTest Do not write"
};


int e;

char message1 [] = "Packet 1, wanting to see if received packet is the same as sent packet";
char message2 [] = "Packet 2, broadcast test";

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  /*
   // just a snippet to generate hex for channel settings
    uint32_t frf = 433575000 / (32000000.0 /524288);
    Serial.println(frf, HEX);
  */
  
  // Print a start message
  Serial.println(F("SX1272 module and Arduino: send packets without ACK"));
  
  // Power ON the module
  e = sx1272.ON();
  Serial.print(F("Setting power ON: state "));
  Serial.println(e, DEC);
  
  // Check register OP Mode
  e |= sx1272.readRegister(0x01);
  Serial.print(F("Reading OP Mode: state "));
  Serial.println(e, BIN);
  
  // Set transmission mode and print the result
  e |= sx1272.setMode(4);
  Serial.print(F("Setting Mode: state "));
  Serial.println(e, BIN);

  // Check register OP Mode
    e |= sx1272.readRegister(0x01);
  Serial.print(F("Reading OP Mode: state "));
  Serial.println(e, BIN);
  // Set header
  e |= sx1272.setHeaderON();
  Serial.print(F("Setting Header ON: state "));
  Serial.println(e, DEC);
  
  // Select frequency channel
  e |= sx1272.setChannel(CH_00_433);
  Serial.print(F("Setting Channel: state "));
  Serial.println(e, DEC);
  
  // Set CRC
  e |= sx1272.setCRC_ON();
  Serial.print(F("Setting CRC ON: state "));
  Serial.println(e, DEC);
  
  // Select output power (Max, High or Low)
  e |= sx1272.setPower('L');
  Serial.print(F("Setting Power: state "));
  Serial.println(e, DEC);
  
  // Set the node address and print the result
  e |= sx1272.setNodeAddress(3);
  Serial.print(F("Setting node address: state "));
  Serial.println(e, DEC);
  
  // Print a success message
  if (e == 0)
    Serial.println(F("SX1272 successfully configured"));
  else
    Serial.println(F("SX1272 initialization failed"));

// Read all registers
    Serial.println(F("-< dumping all registers >-"));
    for (int address = 0 ; address <= 0x70 ; address++ ){
        Serial.print(register_name_lora[address]);
        Serial.print(": ");
        sx1272.readRegister(address);
    }
}

void loop(void)
{
  // Send message1 and print the result
  e = sx1272.sendPacketTimeout(8, message1);
  Serial.print(F("Packet sent, state "));
  Serial.println(e, DEC);
    e |= sx1272.readRegister(0x01);
  Serial.print(F("Reading OP Mode: state "));
  Serial.println(e, BIN);
  delay(4000);  

  // Send message2 broadcast and print the result
  e = sx1272.sendPacketTimeout(0, message2);
  Serial.print(F("Packet sent, state "));
  Serial.println(e, DEC);
    e |= sx1272.readRegister(0x01);
  Serial.print(F("Reading OP Mode: state "));
  Serial.println(e, BIN);
  delay(4000);  
}