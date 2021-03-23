// ==============================================================
// File generated on Thu Mar 11 17:05:44 +0100 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xcalcola.h"

extern XCalcola_Config XCalcola_ConfigTable[];

XCalcola_Config *XCalcola_LookupConfig(u16 DeviceId) {
	XCalcola_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XCALCOLA_NUM_INSTANCES; Index++) {
		if (XCalcola_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XCalcola_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XCalcola_Initialize(XCalcola *InstancePtr, u16 DeviceId) {
	XCalcola_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XCalcola_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XCalcola_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

