# arduinoLoRa_ESP
Fork and update on Libelium arduinoLoRa driver, Modified for ESP family 32/8266 and arduino IDE 1.8.5
http://www.libelium.com 

## Initialization and basic functions:

#### ON();                     
Opens the SPI and switches the SX1272 LoRa module ON.
#### OFF();                   
Closes the SPI and switches the SX1272 LoRa module OFF.
#### readRegister();           
Reads the indicated internal register.
#### writeRegister();           
Writes the indicated internal register.
#### clearFlags();             
Clears the interruption flags.


## Configuration functions:

#### setLORA();                 
Sets the module in LoRa transmission mode.
#### setMode();                 
Sets the BW, CR and SF of the LoRa modulation.
#### setHeaderON();             
Sets the module in explicit header mode (header is sent).
#### setHeaderOFF();            
Sets the module in implicit header mode (header is not sent).
#### setCRC_ON();               
Sets the module with CRC on.
#### setCRC_OFF();              
Sets the module with CRC off.
#### setChannel();              
Sets the indicated frequency channel in the module.
#### setFrequency();              
Sets the indicated frequency in the module. New function  added 2017-12-30 by Agge 
#### setPower();                
Sets the signal power indicated in the module.
#### setPowerNum();            
Sets the signal power indicated in the module.
#### setPreambleLength();       
Sets the preamble length in the module.
#### setPacketLength();         
Sets the packet length in the module.
#### setNodeAddress();          
Sets the node address in the module.
#### setRetries();              
Sets the maximum number of retries.
#### setMaxCurrent();           
Limits the current supply of the internal power amplifier.
#### getTemp();                 
Gets the temperature from the measurement block module.
#### getRegs();               
Gets the content of different registers.


## Link information functions:

#### getSNR();                
Gets the SNR value in LoRa mode.
#### getRSSI();                
Gets the current value of RSSI from the channel.
#### getRSSIpacket();          
Gets the RSSI of the last packet received in LoRa mode.


## Sending and receiving functions:

#### sendPacketTimeout();     
Sends a packet to the specified destination before a timeout expires.
#### sendPacketMaxTimeout();
Same as previous function with maximum timeout.
#### sendPacketTimeoutACK();
Sends a packet to a destination before a timeout and wait for an ACK response.
#### sendPacketMaxTimeoutACK();
ame as previous function with maximum timeout.
#### sendPacketTimeoutACKRetries();    
Sends a packet to a destination before a timeout, 
wait for an ACK response and retry to send the packet if ACK is lost.
#### sendPacketMaxTimeoutACKRetries();
Same as previous function with maximum timeout.
#### receivePacketTimeout();
Receives information before a timeout expires.     
#### receivePacketMAXTimeout();
Same as previous function with maximum timeout.
#### receivePacketTimeoutACK();
Receives information before a timeout expires and responds with ACK.
#### receivePacketMAXTimeoutACK();
Same as previous function with maximum timeout.
#### receiveAll();
Receives all the information on air with maximum timeout.
