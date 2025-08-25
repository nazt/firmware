// Custom SX1280 2.4GHz Board Variant
// ESP32 with SX1280 LoRa module
// Designed for LORA_24 (2400-2483.5 MHz) operation

// Disable features not present on this board
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// No display on this board
#define HAS_SCREEN 0

// I2C configuration (standard ESP32 pins)
#define I2C_SDA 21
#define I2C_SCL 22

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

// SPI configuration for SX1280
// Using standard ESP32 SPI pins
#define LORA_SCK 18         // SPI Clock
#define LORA_MISO 19        // SPI MISO
#define LORA_MOSI 23        // SPI MOSI
#define LORA_CS 10          // Chip Select (NSS)

// SX1280 specific control pins
#define SX128X_CS 10        // NSS pin (Chip Select)
#define SX128X_DIO1 18      // DIO1/IRQ pin - WAIT! This conflicts with LORA_SCK
// Fix the conflict - DIO1 should use the correct pin from user's spec
#undef SX128X_DIO1
#define SX128X_DIO1 5       // Changed to avoid conflict with SCK
// Actually, user specified pin 18 for DIO1, need to use different SCK
#undef LORA_SCK
#define LORA_SCK 14         // Move SCK to avoid conflict

// Wait, let me reconsider the pin mappings based on user's working code
// User's code shows: Module(10, 18, 16, 17) = (NSS, DIO1, RESET, BUSY)
// And RF switch on 14, 15
// So let's use standard ESP32 SPI pins that don't conflict

// Corrected SPI configuration
#undef LORA_SCK
#undef LORA_MISO
#undef LORA_MOSI
#define LORA_SCK 5          // SPI Clock (avoid conflicts)
#define LORA_MISO 19        // SPI MISO (standard)
#define LORA_MOSI 27        // SPI MOSI (avoid conflicts)

// SX1280 control pins as specified by user
#define SX128X_CS 10        // NSS pin
#define SX128X_DIO1 18      // DIO1/IRQ pin (as user specified)
#define SX128X_BUSY 17      // BUSY pin
#define SX128X_RESET 16     // NRST pin

// RF Switch configuration for TX/RX control
#define SX128X_RXEN 14      // RF switch RX enable
#define SX128X_TXEN 15      // RF switch TX enable

// Power configuration
// SX1280 max power for 2.4GHz
// Start conservative, can increase if needed
#define SX128X_MAX_POWER 10  // 10 dBm as per LORA_24 spec

// No power enable pin on this board
#undef SX128X_POWER_EN

// Serial configuration
#define SERIAL0_RX_GPIO 3
#define SERIAL0_TX_GPIO 1