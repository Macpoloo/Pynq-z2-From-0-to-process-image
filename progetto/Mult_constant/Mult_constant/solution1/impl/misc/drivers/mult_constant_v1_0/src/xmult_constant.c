// ==============================================================
// File generated on Thu Mar 11 17:12:45 +0100 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmult_constant.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMult_constant_CfgInitialize(XMult_constant *InstancePtr, XMult_constant_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMult_constant_Set_constant_V(XMult_constant *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMult_constant_WriteReg(InstancePtr->Axilites_BaseAddress, XMULT_CONSTANT_AXILITES_ADDR_CONSTANT_V_DATA, Data);
}

u32 XMult_constant_Get_constant_V(XMult_constant *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMult_constant_ReadReg(InstancePtr->Axilites_BaseAddress, XMULT_CONSTANT_AXILITES_ADDR_CONSTANT_V_DATA);
    return Data;
}

