#pragma once

#include <stddef.h>
#include <stdint.h>

class ScanI2C
{
  public:
    typedef enum DeviceType {
        NONE,
        SCREEN_SSD1306,     // 0x3C
        SCREEN_SH1106,      // 0x3C
        SCREEN_UNKNOWN,     // 0x3C --> same address as the two above but does not respond to the same commands
        SCREEN_ST7567,      // 0x3F
        RTC_RV3028,         // 0x52
        RTC_PCF8563,        // 0x51
        CARDKB,             // 0x5F --> same as RAK14004 but different register values
        TDECKKB,            // 0x55 --> same as BQ27220
        BBQ10KB,            // 0x1F
        RAK14004,           // 0x5F --> same as CARDKB but different register values
        PMU_AXP192_AXP2101, // 0x34 --> same as TCA8418KB
        BME_680,            // 0x76 or 0x77
        BME_280,            // 0x76 or 0x77
        BMP_280,            // 0x76 or 0x77
        BMP_085,            // 0x76 or 0x77
        BMP_3XX,            // 0x76 or 0x77
        INA260,             // 0x40 or 0x41 or 0x43
        INA219,             // 0x40 or 0x41 or 0x43
        INA3221,            // 0x42
        MAX17048,           // 0x36
        MCP9808,            // 0x18 --> same as LIS3DH and ES8311 and STK8BAXX
        SHT31,              // 0x44 or 0x45
        SHT4X,              // 0x44 or 0x45
        SHTC3,              // 0x70
        LPS22HB,            // 0x5C or 0x5D
        QMC6310,            // 0x1C
        QMI8658,            // 0x6B
        QMC5883L,           // 0x0D
        HMC5883L,           // 0x1E
        PMSA0031,           // 0x12 --> same as QMA6100P
        QMA6100P,           // 0x12 --> same as PMSA0031
        MPU6050,            // 0x68
        LIS3DH,             // 0x18 or 0x19 --> same as MCP9808 and ES8311 and STK8BAXX
        BMA423,             // 0x19
        BQ24295,            // 0x6B --> same as QMI8658 and BQ25896
        LSM6DS3,            // 0x6A
        TCA9535,            // 0x20 --> same as XL9555
        TCA9555,            // 0x26
        VEML7700,           // 0x10
        RCWL9620,           // 0x10
        NCP5623,            // 0x38
        LP5562,             // 0x30
        TSL2591,            // 0x29
        OPT3001,            // 0x45 or 0x44
        MLX90632,           // 0x3A
        MLX90614,           // 0x5A --> same as MPR121KB
        AHT10,              // 0x38
        BMX160,             // 0x69
        DFROBOT_LARK,       // 0x42
        NAU7802,            // 0x2A
        FT6336U,            // 0x48
        STK8BAXX,           // 0x18
        ICM20948,           // 0x69 or 0x68
        MAX30102,           // 0x57
        TPS65233,           // 0x60
        MPR121KB,           // 0x5A --> same as MLX90614
        CGRADSENS,          // 0x66
        INA226,             // 0x40
        NXP_SE050,          // 0x48
        DFROBOT_RAIN,       // 0x1d
        DPS310,             // 0x77
        LTR390UV,           // 0x53
        TCA8418KB,          // 0x34 --> same as PMU_AXP192_AXP2101
        PCT2075,            // 0x37
        BHI260AP,           // 0x28
        XL9555,             // 0x20 --> same as TCA9535
        BQ25896,            // 0x6B --> same as QMI8658 and BQ24295 and LSM6DS3
        BQ27220,            // 0x55 --> same as TDECKKB
        ES8311,             // 0x18 --> same as MCP9808 and LIS3DH and STK8BAXX
    } DeviceType;

    // typedef uint8_t DeviceAddress;
    typedef enum I2CPort {
        NO_I2C,
        WIRE,
        WIRE1,
    } I2CPort;

    typedef struct DeviceAddress {
        // set default values for ADDRESS_NONE
        I2CPort port = I2CPort::NO_I2C;
        uint8_t address = 0;

        explicit DeviceAddress(I2CPort port, uint8_t address);
        DeviceAddress();

        bool operator<(const DeviceAddress &other) const;
    } DeviceAddress;

    static const DeviceAddress ADDRESS_NONE;

    typedef uint8_t RegisterAddress;

    typedef struct FoundDevice {
        DeviceType type;
        DeviceAddress address;

        explicit FoundDevice(DeviceType = DeviceType::NONE, DeviceAddress = ADDRESS_NONE);
    } FoundDevice;

    static const FoundDevice DEVICE_NONE;

  public:
    ScanI2C();

    virtual void scanPort(ScanI2C::I2CPort);
    virtual void scanPort(ScanI2C::I2CPort, uint8_t *, uint8_t);

    /*
     * A bit of a hack, this tells the scanner not to tell later systems there is a screen to avoid enabling it.
     */
    void setSuppressScreen();

    FoundDevice firstScreen() const;

    FoundDevice firstRTC() const;

    FoundDevice firstKeyboard() const;

    FoundDevice firstAccelerometer() const;

    FoundDevice firstRGBLED() const;

    virtual FoundDevice find(DeviceType) const;

    virtual bool exists(DeviceType) const;

    virtual size_t countDevices() const;

  protected:
    virtual FoundDevice firstOfOrNONE(size_t, DeviceType[]) const;

  private:
    bool shouldSuppressScreen = false;
};
