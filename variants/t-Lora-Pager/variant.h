
#define TFT_CS 38
#define LORA_CS 36
#define SD_CS 21
#define NFC_CS 39

#define SPI_MOSI 34
#define SPI_MISO 33
#define SPI_SCK 35

#ifndef HAS_TFT // for TFT-UI the definitions are in device-ui
#define BUTTON_PIN 0

// ST7796 TFT LCD
#define ST7796_CS TFT_CS
#define ST7796_RS 37 // DC
#define ST7796_SDA SPI_MOSI
#define ST7796_SCK SPI_SCK
#define ST7796_RESET -1
#define ST7796_MISO SPI_MISO
#define ST7796_BUSY -1
#define ST7796_BL 42
#define ST7796_SPI_HOST SPI2_HOST
#define TFT_BL 42
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 16000000
#define TFT_HEIGHT 480
#define TFT_WIDTH 222
#define TFT_OFFSET_X 49
#define TFT_OFFSET_Y 0
#define TFT_OFFSET_ROTATION 0
#define SCREEN_ROTATE
#define SCREEN_TRANSITION_FRAMERATE 5
#define BRIGHTNESS_DEFAULT 130 // Medium Low Brightness
#endif

#define USE_POWERSAVE
#define SLEEP_TIME 120

#ifndef HAS_TFT
#define BUTTON_PIN 0
// #define BUTTON_NEED_PULLUP
#endif
// #define GPS_DEFAULT_NOT_PRESENT 1
#define GPS_RX_PIN 44
#define GPS_TX_PIN 43

// Have SPI interface SD card slot
// #define HAS_SDCARD // --> needs to be in platform.ini for device-ui
// #define SPI_MOSI (34)
// #define SPI_SCK (35)
// #define SPI_MISO (33)
// #define SPI_CS (39)
#define SDCARD_CS SD_CS
#define SD_SPI_FREQUENCY 75000000U

#define BATTERY_PIN 4 // A battery voltage measurement pin, voltage divider connected here to measure battery voltage
// ratio of voltage divider = 2.0 (RD2=100k, RD3=100k)
#define ADC_MULTIPLIER 2.11 // 2.0 + 10% for correction of display undervoltage.
#define ADC_CHANNEL ADC1_GPIO4_CHANNEL

// keyboard
#define I2C_SDA 3 // I2C pins for this board
#define I2C_SCL 2
// #define KB_POWERON 10                  // must be set to HIGH needs changing to XL9555
#define KB_SLAVE_ADDRESS TDECK_KB_ADDR // 0x55
#define KB_BL_PIN 46                   // not used for now
#define CANNED_MESSAGE_MODULE_ENABLE 1

// microphone
#define ES7210_SCK 47
#define ES7210_DIN 14
#define ES7210_LRCK 21
#define ES7210_MCLK 48

// dac / amp
#define HAS_I2S
#define DAC_I2S_BCK 7
#define DAC_I2S_WS 5
#define DAC_I2S_DOUT 6
#define DAC_I2S_MCLK 21 // GPIO lrck mic

// LoRa
#define USE_SX1262
#define USE_SX1268

#define LORA_SCK SPI_SCK
#define LORA_MISO SPI_MISO
#define LORA_MOSI SPI_MOSI

#define LORA_DIO0 -1 // a No connect on the SX1262 module
#define LORA_RESET 47
#define LORA_DIO1 14 // SX1262 IRQ
#define LORA_DIO2 48 // SX1262 BUSY
#define LORA_DIO3    // Not connected on PCB, but internally on the TTGO SX1262, if DIO3 is high the TXCO is enabled

#define SX126X_CS LORA_CS // FIXME - we really should define LORA_CS instead
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
// Not really an E22 but TTGO seems to be trying to clone that
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
// Internally the TTGO module hooks the SX1262-DIO2 in to control the TX/RX switch (which is the default for the sx1262interface
// code)
