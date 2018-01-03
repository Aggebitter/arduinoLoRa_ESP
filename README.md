# arduinoLoRa_ESP
Fork and update on Libelium arduinoLoRa driver, Modified for ESP family 32/8266 and arduino IDE 1.8.5
http://www.libelium.com 



## Initialization and basic functions:

| Function | Description |
| --- | --- |
|**ON();**  |resets and sets the SX127x basic LoRa mode |
| `returns` | uint8_t |
|**OFF();**  |just reset SX127x LoRa module (for compability) |
| `returns` | uint8_t |
|**readRegister();**  |Reads the indicated internal register |
| `returns` | uint8_t |
|**writeRegister()**  |Writes the indicated internal register |
| `returns` | uint8_t |
|**clearFlags();**  |Clears the interruption flags |
| `returns` | uint8_t |


## Configuration functions:

| Function | Description |
| --- | --- |
|**setLORA();**  |Sets the module in LoRa mode |
| `returns` | It stores in global _LORA variable 1 returns uint8_t |
|**setMode();**  |Sets the BW, CR and SF of the LoRa modulation |
| `returns` | uint8_t |
|**setHeaderON();**  |Sets the module in explicit header mode (header is sent) |
| `returns` | uint8_t |
|**setHeaderOFF();**  |Sets the module in implicit header mode (header is not sent) |
| `returns` | uint8_t |
|**setCRC_ON();**  |Sets the module with CRC on |
| `returns` | uint8_t |
|**setChannel();**  |Sets the indicated frequency channel in the module |
| `returns` | uint8_t |
|**setFrequency(uint32_t);**  |Sets the indicated frequency in the module ***added 2017-12-30 by Agge*** |
| `returns` | uint8_t |
|**serCR();**  |Sets the indicated Coding Rate in the module |
| `returns` | uint8_t |
|**setSF(uint8_t);**  |Sets the indicated Spreading Factor in the module |
| `returns` | uint8_t |
|**setBW(uint16_t);**  |Sets the indicated BandWidth in the module |
| `returns` | uint8_t |
|**setPower()**  |Sets the signal power indicated in the module |
| `returns` | uint8_t |
|**setPowerNum();**  |Sets the signal power indicated in the module |
| `returns` | uint8_t |
|**setPreambleLength();**  |Sets the preamble length in the module |
| `returns` | uint8_t |
|**setPacketLength();**  |Sets the packet length in the module |
| `returns` | uint8_t |
|**setNodeAddress();**  |Sets the node address in the module |
| `returns` | uint8_t |
|**setRetries();**  |Sets the maximum number of retries |
| `returns` | uint8_t |
|**setMaxCurrent();**  |Limits the current supply of the internal power amplifier |
| `returns` | uint8_t |
|**setDio0Map(uint8_t);**  |Sets DIO0 Mapping use number 0-3 ***added 2017-12-30 by Agge***|
| `returns` | nothing |
|**setDio2Map(uint8_t);**  |Sets DIO2 Mapping use number 0-3 ***added 2017-12-30 by Agge*** |
| `returns` | nothing |
|**getTemp();**  |Gets the temperature from the measurement block module |
| `returns` | uint8_t |
|**getRegs();**  |Gets the content of different registers |
| `returns` | uint8_t |


## Link information functions:

| Function | Description |
| --- | --- |
|**getSNR();**  |Gets the SNR value in LoRa mod |
| `returns` | uint8_t |
|**getRSSI()**  |Gets the current value of RSSI from the channel |
| `returns` | uint8_t |
|**getRSSIpacket();**  |Gets the RSSI of the last packet received in LoRa mode |
| `returns` | uint8_t |


## Sending and receiving functions:

| Function | Description |
| --- | --- |
|**sendPacketTimeout();**  |Sends a packet to the specified destination before a timeout expires |
| `returns` | uint8_t |
|**sendPacketMaxTimeout()**  |Same as previous function with maximum timeout |
| `returns` | uint8_t |
|**sendPacketTimeoutACK();**  |Sends a packet to a destination before a timeout and wait for an ACK response |
| `returns` | uint8_t |
|**sendPacketMaxTimeoutACK();**  |Same as previous function with maximum timeout |
| `returns` | uint8_t |
|**sendPacketTimeoutACKRetries();**  |Sends a packet to a destination before a timeout, wait for an ACK response and retry to send the packet if ACK is lost |
| `returns` | uint8_t |
|**sendPacketMaxTimeoutACKRetries();**  |Same as previous function with maximum timeout |
| `returns` | uint8_t |
|**receivePacketTimeout();**  |Receives information before a timeout expires |
| `returns` | uint8_t |
|**receivePacketMAXTimeout();**  |Same as previous function with maximum timeout |
| `returns` | uint8_t |
|**receivePacketTimeoutACK();**  |Receives information before a timeout expires and responds with ACK |
| `returns` | uint8_t |
|**receivePacketMAXTimeoutACK();**  |Same as previous function with maximum timeout |
| `returns` | uint8_t |
|**receiveAll();**  |Receives all the information on air with maximum timeout |
| `returns` | uint8_t |
|**getExtIRQ()**  |Gets the interrupt register/s and clear it/them ***added 2017-12-30 by Agge***  |
| `returns` | uint16_t |
