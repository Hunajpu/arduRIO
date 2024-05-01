/*
  main.cpp - Main loop for Arduino sketches
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Arduino.h>

NiFpga_Session session;
NiFpga_Status status;

// Declared weak in Arduino.h to allow user redefinitions.
int atexit(void (* /*func*/ )()) throw() { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() {
  printf("Initializing...\n");
  status = NiFpga_Initialize();
  if (NiFpga_IsNotError(status)) {
    /* opens a session, downloads the bitstream, and runs the FPGA */
    printf("Opening a session...\n");
    NiFpga_MergeStatus(&status, NiFpga_Open(NiFpga_f_Bitfile,
                                            NiFpga_f_Signature,
                                            "RIO0",
                                            NiFpga_OpenAttribute_NoRun,
                                            &session));
    if (NiFpga_IsNotError(status)) {
      printf("Running the FPGA...\n");
      NiFpga_MergeStatus(&status, NiFpga_Run(session, 0));
    }
  }
}

int fpgaErrorManagment(void){
  if(NiFpga_IsError(status)){
    printf("Error %d\n", status);
    printf("Closing the session...\n");
    NiFpga_MergeStatus(&status, NiFpga_Close(session, 0));
    printf("Finalizing..\n");
    NiFpga_MergeStatus(&status, NiFpga_Finalize());
    exit(EXIT_FAILURE);
  }
}

void setupUSB() __attribute__((weak));
void setupUSB() { }

int main(void)
{
	//init();

	initVariant();

	setup();
    
	while (NiFpga_IsNotError(status)) {
		loop();
	}

  fpgaErrorManagment();  
  
	return EXIT_SUCCESS;
}

