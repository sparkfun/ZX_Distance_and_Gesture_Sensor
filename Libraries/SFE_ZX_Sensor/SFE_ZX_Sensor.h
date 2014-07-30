/**
 * @file    SFE_ZX_Sensor.h
 * @brief   Library for the SparkFun/GestureSense ZX Sensor
 * @author  Shawn Hymel (SparkFun Electronics)
 *
 * @copyright	This code is public domain but you buy me a beer if you use
 * this and we meet someday (Beerware license).
 *
 * This library interfaces the XYZ Interactive ZX Sensor to Arduino over I2C.
 * The library relies on the Arduino Wire (I2C) library. To use the library,
 * instantiate a ZX_Sensor object, call init(), and call the desired
 * functions.
 */
 
#ifndef SFE_ZX_SENSOR_H
#define SFE_ZX_SENSOR_H

#include <Arduino.h>

/* Debug */
#define DEBUG               1

/* ZX Sensor I2C address */
#define ZX_ADDR             0x10

/* Acceptable ZX Sensor version */
#define ZX_MODEL_VER        0x00

/* Acceptable ZX Sensor register map */
#define ZX_REG_MAP_VER      0x00

/* ZX Sensor register addresses */
#define ZX_STATUS           0x00
#define ZX_DRE              0x01
#define ZX_DRCFG            0x02
#define ZX_GESTURE          0x04
#define ZX_GSPEED           0x05
#define ZX_DCM              0x06
#define ZX_XPOS             0x08
#define ZX_ZPOS             0x0A
#define ZX_LRNG             0x0C
#define ZX_RRNG             0x0E
#define ZX_REGVER           0xFE
#define ZX_MODEL            0xFF

/* Constants */
#define ZX_ERROR            0xFF
#define MAX_X               240
#define MAX_Z               240

/* ZX Sensor Class */
class SFE_ZX_Sensor {
public:

    /* Initialization */
    SFE_ZX_Sensor();
    ~SFE_ZX_Sensor();
    bool init();
    
    /* Data available */
    bool positionAvailable();
    bool swipeAvailable();
    bool hoverAvailable();
    bool hoverMoveAvailable();
    
    /* Sensor data read */
    uint8_t readX();
    uint8_t readZ();
    
private:

    /* Raw I2C reads and writes */
    bool wireWriteByte(uint8_t val);
    bool wireWriteDataByte(uint8_t reg, uint8_t val);
    bool wireReadDataByte(uint8_t reg, uint8_t &val);
};

#endif