#pragma once
#ifndef _TOUCHSCREEN_CST226_H_
#define _TOUCHSCREEN_CST226_H_

#include <TouchDrvCSTXXX.hpp>
#include <Wire.h>

// class BMA423Sensor : public MotionSensor
class TouchDrvCSTXXX : public DrvTouch
{
  private:
    // SensorBMA423 sensor;

    volatile bool BMA_IRQ = false;

  public:
    // explicit BMA423Sensor(ScanI2C::FoundDevice foundDevice);
    explicit TouchDrvCSTXXX(ScanI2C::FoundDevice foundDevice);
    virtual bool init() override;
    virtual int32_t runOnce() override;
};

#endif