/*
 * Generated with the FPGA Interface C API Generator 23.0
 * for NI-RIO 23.0 or later.
 */
#ifndef __NiFpga_f_h__
#define __NiFpga_f_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 230
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_f_Bitfile;
 */
#define NiFpga_f_Bitfile "NiFpga_f.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_f_Signature = "FD4865090FEAA72B0BE366FCF6BE236E";

#if NiFpga_Cpp
extern "C"
{
#endif

typedef enum
{
   NiFpga_f_IndicatorBool_DIGITAL_OUTPUT_VALUE = 0x1800A
} NiFpga_f_IndicatorBool;

typedef enum
{
   NiFpga_f_IndicatorI16_ANALOG_OUTPUT_VALUE = 0x18022
} NiFpga_f_IndicatorI16;

typedef enum
{
   NiFpga_f_ControlBool_ANALOG_DIGITAL_SELECTOR = 0x1801A,
   NiFpga_f_ControlBool_ENABLE = 0x18006,
   NiFpga_f_ControlBool_PIN_MODE = 0x18016,
   NiFpga_f_ControlBool_PIN_MODE_EN = 0x18012,
   NiFpga_f_ControlBool_VALUE = 0x1800E
} NiFpga_f_ControlBool;

typedef enum
{
   NiFpga_f_ControlI16_VALUE = 0x1801E
} NiFpga_f_ControlI16;

typedef enum
{
   NiFpga_f_ControlU16_PIN = 0x18002
} NiFpga_f_ControlU16;


#if NiFpga_Cpp
}
#endif

#endif
