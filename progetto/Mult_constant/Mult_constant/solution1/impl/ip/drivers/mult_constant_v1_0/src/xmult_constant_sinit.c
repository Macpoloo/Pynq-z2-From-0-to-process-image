// ==============================================================
// File generated on Thu Mar 11 17:12:45 +0100 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmult_constant.h"

extern XMult_constant_Config XMult_constant_ConfigTable[];

XMult_constant_Config *XMult_constant_LookupConfig(u16 DeviceId) {
	XMult_constant_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMULT_CONSTANT_NUM_INSTANCES; Index++) {
		if (XMult_constant_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMult_constant_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMult_constant_Initialize(XMult_constant *InstancePtr, u16 DeviceId) {
	XMult_constant_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMult_constant_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMult_constant_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

