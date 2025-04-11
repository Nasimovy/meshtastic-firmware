// #define BUTTON_NEED_PULLUP // if set we need to turn on the internal CPU pullup during sleep

#define I2C_SDA 21
#define I2C_SCL 22

// #define MESHTASTIC_EXCLUDE_WIFI 1
// #define MESHTASTIC_EXCLUDE_BLUETOOTH 1
// #define MESHTASTIC_EXCLUDE_AUDIO 1
// #define MESHTASTIC_EXCLUDE_DETECTIONSENSOR 1
// #define MESHTASTIC_EXCLUDE_ENVIRONMENTAL_SENSOR 1
// #define MESHTASTIC_EXCLUDE_POWER_TELEMETRY 1
// #define MESHTASTIC_EXCLUDE_ATAK 1

// Display ST7796 (TFT) --> addon
// #define SPI_FREQUENCY 40000000
// #define SPI_READ_FREQUENCY 16000000
// #define ST7796_SPI_HOST VSPI_HOST
// #define ST7796_SDA 14
// #define ST7796_SCK 15
// #define ST7796_CS 25
// #define ST7796_RS 13
// #define ST7796_RESET 2
// #define ST7796_BACKLIGHT_EN 4
// #define ST7796_BL 4
// #define TFT_BL 4
// #define TFT_HEIGHT 480
// #define TFT_WIDTH 222
// #define TFT_OFFSET_X 49
// #define TFT_OFFSET_Y 0
// #define TFT_OFFSET_ROTATION 0
// #define SCREEN_TRANSITION_FRAMERATE 5 // fps
// #define VIEW_480x222

// Display (TFT)
#define USE_ST7796
#define ST7796_NSS 25
#define ST7796_RS 13  // DC
#define ST7796_SDA 14 // MOSI
#define ST7796_SCK 15
#define ST7796_RESET 2
#define ST7796_MISO -1
#define ST7796_BUSY -1
#define VTFT_CTRL 7
#define VTFT_LEDA 4
#define TFT_BACKLIGHT_ON HIGH
#define ST7796_SPI_HOST VSPI_HOST
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 16000000
#define TFT_HEIGHT 222
#define TFT_WIDTH 480
#define TFT_OFFSET_X 0
#define TFT_OFFSET_Y 0
// #define TFT_OFFSET_ROTATION 0
// #define SCREEN_ROTATE
// #define SCREEN_TRANSITION_FRAMERATE 5
#define BRIGHTNESS_DEFAULT 100 // Medium Low Brightnes

// Touchscreen CST226SE (Capacitive) --> addon
// #define HAS_CST226SE

#define BUTTON_PIN 38 // The middle button GPIO on the T-Beam
// #define BUTTON_PIN_ALT 13 // Alternate GPIO for an external button if needed. Does anyone use this? It is not documented
//  anywhere.
// #define EXT_NOTIFY_OUT 13 // Default pin to use for Ext Notify Module.

// #define LED_STATE_ON 0 // State when LED is lit
// #define LED_PIN 4      // Newer tbeams (1.1) have an extra led on GPIO4

// TTGO uses a common pinout for their SX1262 vs RF95 modules - both can be enabled and we will probe at runtime for RF95 and if
// not found then probe for SX1262
// #define USE_RF95 // RFM95/SX127x
#define USE_SX1262
#define USE_SX1268

#define LORA_DIO0 26 // a No connect on the SX1262 module
#define LORA_RESET 23
#define LORA_DIO1 33 // SX1262 IRQ
#define LORA_DIO2 32 // SX1262 BUSY
#define LORA_DIO3    // Not connected on PCB, but internally on the TTGO SX1262, if DIO3 is high the TXCO is enabled

#ifdef USE_SX1262
#define SX126X_CS 18 // FIXME - we really should define LORA_CS instead
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
// Not really an E22 but TTGO seems to be trying to clone that
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
// Internally the TTGO module hooks the SX1262-DIO2 in to control the TX/RX switch (which is the default for the sx1262interface
// code)
#endif

// Leave undefined to disable our PMU IRQ handler.  DO NOT ENABLE THIS because the pmuirq can cause sperious interrupts
// and waking from light sleep
// #define PMU_IRQ 35
#define HAS_AXP192
#define GPS_UBLOX
#define GPS_RX_PIN 34
#define GPS_TX_PIN 12
// #define GPS_DEBUG