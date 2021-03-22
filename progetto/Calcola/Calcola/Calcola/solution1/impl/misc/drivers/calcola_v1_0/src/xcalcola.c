// ==============================================================
// File generated on Thu Mar 11 17:05:44 +0100 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xcalcola.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XCalcola_CfgInitialize(XCalcola *InstancePtr, XCalcola_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XCalcola_Set_a(XCalcola *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCalcola_WriteReg(InstancePtr->Axilites_BaseAddress, XCALCOLA_AXILITES_ADDR_A_DATA, Data);
}

u32 XCalcola_Get_a(XCalcola *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCalcola_ReadReg(InstancePtr->Axilites_BaseAddress, XCALCOLA_AXILITES_ADDR_A_DATA);
    return Data;
}

void XCalcola_Set_b(XCalcola *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCalcola_WriteReg(InstancePtr->Axilites_BaseAddress, XCALCOLA_AXILITES_ADDR_B_DATA, Data);
}

u32 XCalcola_Get_b(XCalcola *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCalcola_ReadReg(InstancePtr->Axilites_BaseAddress, XCALCOLA_AXILITES_ADDR_B_DATA);
    return Data;
}

void XCalcola_Set_o(XCalcola *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCalcola_WriteReg(InstancePtr->Axilites_BaseAddress, XCALCOLA_AXILITES_ADDR_O_DATA, Data);
}

u32 XCalcola_Get_o(XCalcola *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCalcola_ReadReg(InstancePtr->Axilites_BaseAddress, XCALCOLA_AXILITES_ADDR_O_DATA);
    return Data;
}

u32 XCalcola_Get_c(XCalcola *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCalcola_ReadReg(InstancePtr->Axilites_BaseAddress, XCALCOLA_AXILITES_ADDR_C_DATA);
    return Data;
}

u32 XCalcola_Get_c_vld(XCalcola *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCalcola_ReadReg(InstancePtr->Axilites_BaseAddress, XCALCOLA_AXILITES_ADDR_C_CTRL);
    return Data & 0x1;
}

