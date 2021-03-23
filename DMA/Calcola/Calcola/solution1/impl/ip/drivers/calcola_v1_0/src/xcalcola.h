// ==============================================================
// File generated on Thu Mar 11 17:05:44 +0100 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XCALCOLA_H
#define XCALCOLA_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xcalcola_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XCalcola_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XCalcola;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XCalcola_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XCalcola_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XCalcola_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XCalcola_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XCalcola_Initialize(XCalcola *InstancePtr, u16 DeviceId);
XCalcola_Config* XCalcola_LookupConfig(u16 DeviceId);
int XCalcola_CfgInitialize(XCalcola *InstancePtr, XCalcola_Config *ConfigPtr);
#else
int XCalcola_Initialize(XCalcola *InstancePtr, const char* InstanceName);
int XCalcola_Release(XCalcola *InstancePtr);
#endif


void XCalcola_Set_a(XCalcola *InstancePtr, u32 Data);
u32 XCalcola_Get_a(XCalcola *InstancePtr);
void XCalcola_Set_b(XCalcola *InstancePtr, u32 Data);
u32 XCalcola_Get_b(XCalcola *InstancePtr);
void XCalcola_Set_o(XCalcola *InstancePtr, u32 Data);
u32 XCalcola_Get_o(XCalcola *InstancePtr);
u32 XCalcola_Get_c(XCalcola *InstancePtr);
u32 XCalcola_Get_c_vld(XCalcola *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
