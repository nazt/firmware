// Custom SX1280 2.4GHz Board Variant for ESP32-S3
// ESP32-S3 with SX1280 LoRa module
// Designed for LORA_24 (2400-2483.5 MHz) operation

// Fix Serial definition for ESP32-S3
#define Serial Serial0

// Disable features not present on this board
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// No display on this board
#define HAS_SCREEN 0

// I2C configuration (standard ESP32-S3 pins)
#define I2C_SDA 8
#define I2C_SCL 9

// Multiple LED configuration for status indication
#define LED_PIN 35          // Primary status LED
#define LED_PIN_2 36        // Secondary LED
#define LED_PIN_3 37        // Third LED  
#define LED_PIN_4 38        // Fourth LED
#define LED_PIN_5 7         // Fifth LED

// Button configuration (using boot button)
#define BUTTON_PIN 0
#define BUTTON_NEED_PULLUP

// Battery monitoring disabled for now
#undef BATTERY_PIN
#undef ADC_CHANNEL

// SX1280 2.4GHz LoRa configuration
#define USE_SX1280

// SPI configuration for ESP32-S3
// Using HSPI (SPI2) pins that don't conflict
#define LORA_SCK 12         // SPI Clock
#define LORA_MISO 13        // SPI MISO
#define LORA_MOSI 11        // SPI MOSI
#define LORA_CS 10          // Chip Select (NSS)

// SX1280 specific control pins as specified by user
#define SX128X_CS 10        // NSS pin (Chip Select)
#define SX128X_DIO1 18      // DIO1/IRQ pin
#define SX128X_BUSY 17      // BUSY pin
#define SX128X_RESET 16     // NRST pin

// RF Switch configuration for TX/RX control
#define SX128X_RXEN 14      // RF switch RX enable
#define SX128X_TXEN 15      // RF switch TX enable

// Power configuration
// SX1280 max power for 2.4GHz
#define SX128X_MAX_POWER 10  // 10 dBm as per LORA_24 spec

// No power enable pin on this board
#undef SX128X_POWER_EN

// Serial configuration for ESP32-S3 native USB
#define SERIAL0_RX_GPIO 44  // USB_D- (for reference, handled by USB CDC)
#define SERIAL0_TX_GPIO 43  // USB_D+ (for reference, handled by USB CDC)

// Enable USB CDC for serial console
#define USE_USB_CDC
#define ARDUINO_USB_MODE 1
#define ARDUINO_USB_CDC_ON_BOOT 1