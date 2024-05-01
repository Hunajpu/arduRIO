#include "Arduino.h"

void pinMode(uint8_t pin, uint8_t mode){
    //PIN mode does not does anything in the cRIO.

}
void digitalWrite(uint8_t pin, uint8_t val){
    //Set digital operation
    NiFpga_MergeStatus(&status, NiFpga_WriteU16(session, NiFpga_f_ControlU16_OPERATION, DIGITAL_OP));
    //Set a write operation
    NiFpga_MergeStatus(&status, NiFpga_WriteBool(session, NiFpga_f_ControlBool_RW, NiFpga_True));
    // Set the cRIO pin
    NiFpga_MergeStatus(&status, NiFpga_WriteU8(session, NiFpga_f_ControlU8_PIN, pin));
    // Set the input value
    NiFpga_MergeStatus(&status, NiFpga_WriteU8(session, NiFpga_f_ControlU8_INPUT, val));

    //Enable
    NiFpga_MergeStatus(&status, NiFpga_WriteBool(session, NiFpga_f_ControlBool_ENABLE, NiFpga_True));
    NiFpga_MergeStatus(&status, NiFpga_WriteBool(session, NiFpga_f_ControlBool_ENABLE, NiFpga_False));
}

int digitalRead(uint8_t pin){
    int16_t* output;

    //Set digital operation
    NiFpga_MergeStatus(&status, NiFpga_WriteU16(session, NiFpga_f_ControlU16_OPERATION, DIGITAL_OP));
    //Set a read operation
    NiFpga_MergeStatus(&status, NiFpga_WriteBool(session, NiFpga_f_ControlBool_RW, NiFpga_False));
    // Set the cRIO pin
    NiFpga_MergeStatus(&status, NiFpga_WriteU8(session, NiFpga_f_ControlU8_PIN, pin));

    //Enable
    NiFpga_MergeStatus(&status, NiFpga_WriteBool(session, NiFpga_f_ControlBool_ENABLE, NiFpga_True));
    NiFpga_MergeStatus(&status, NiFpga_WriteBool(session, NiFpga_f_ControlBool_ENABLE, NiFpga_False));

    
    // Get the output value
    NiFpga_MergeStatus(&status, NiFpga_ReadI16(session, NiFpga_f_IndicatorI16_OUTPUT, output));

    return *output;
}