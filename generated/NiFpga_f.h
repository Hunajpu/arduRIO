/*
 * Generated with the FPGA Interface C API Generator 24.3
 * for NI-RIO 24.3 or later.
 */
#ifndef __NiFpga_f_h__
#define __NiFpga_f_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 243
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
static const char* const NiFpga_f_Signature = "DA32E0A795B19829BB1702578ECE03FD";

#if NiFpga_Cpp
extern "C"
{
#endif

typedef enum
{
   NiFpga_f_IndicatorI16_OUTPUT = 0x1800E
} NiFpga_f_IndicatorI16;

typedef enum
{
   NiFpga_f_ControlBool_ENABLE = 0x18006,
   NiFpga_f_ControlBool_RW = 0x18016
} NiFpga_f_ControlBool;

typedef enum
{
   NiFpga_f_ControlU8_INPUT = 0x18012,
   NiFpga_f_ControlU8_PIN = 0x18002
} NiFpga_f_ControlU8;

typedef enum
{
   NiFpga_f_ControlU16_OPERATION = 0x1800A
} NiFpga_f_ControlU16;


#if NiFpga_Cpp
}
#endif

#endif
