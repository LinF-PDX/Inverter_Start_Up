/*
 * InverterStartupControl_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "InverterStartupControl".
 *
 * Model version              : 1.95
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Mar 22 19:03:21 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_InverterStartupControl_types_h_
#define RTW_HEADER_InverterStartupControl_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"
#ifndef DEFINED_TYPEDEF_FOR_MI_STATUSES_
#define DEFINED_TYPEDEF_FOR_MI_STATUSES_

typedef enum {
  UNKNOWN = 0,                         /* Default value */
  STS_INIT,
  STARTUP,
  RUNNING,
  SHUTDOWN,
  MI_STS_ERROR,
  OFF
} MI_STATUSES;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MI_CMD_
#define DEFINED_TYPEDEF_FOR_MI_CMD_

typedef enum {
  CMD_INIT = 0,                        /* Default value */
  IDLE,
  CMD_STARTUP,
  CMD_SHUTDOWN,
  ERR_RESET
} MI_CMD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ld12iMSSAH0saQuzCr50S_
#define DEFINED_TYPEDEF_FOR_struct_ld12iMSSAH0saQuzCr50S_

typedef struct {
  real_T AMK_bReserve;
  real_T AMK_ActualVelocity;
  real_T AMK_MagnetizingCurrent;
  real_T AMK_TorqueCurrent;
  real_T AMK_bDcOn;
  real_T AMK_bDerating;
  real_T AMK_bError;
  real_T AMK_bInverterOn;
  real_T AMK_bQuitDcOn;
  real_T AMK_bQuitInverterOn;
  real_T AMK_bSystemReady;
  real_T AMK_bWarn;
} struct_ld12iMSSAH0saQuzCr50S;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_wpFUE3qawfN6DIL1c858xG_
#define DEFINED_TYPEDEF_FOR_struct_wpFUE3qawfN6DIL1c858xG_

typedef struct {
  real_T AMK_ErrorInfo;
  real_T AMK_TempIGBT;
  real_T AMK_TempInverter;
  real_T AMK_TempMotor;
} struct_wpFUE3qawfN6DIL1c858xG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_RAdav281ZwKrAfZlrgLeL_
#define DEFINED_TYPEDEF_FOR_struct_RAdav281ZwKrAfZlrgLeL_

typedef struct {
  struct_ld12iMSSAH0saQuzCr50S ptCAN_AMK_ActualValues1_Right;
  struct_wpFUE3qawfN6DIL1c858xG ptCAN_AMK_ActualValues2_Right;
  struct_ld12iMSSAH0saQuzCr50S ptCAN_AMK_ActualValues1_Left;
  struct_wpFUE3qawfN6DIL1c858xG ptCAN_AMK_ActualValues2_Left;
} struct_RAdav281ZwKrAfZlrgLeL;

#endif

/* Custom Type definition for MATLABSystem: '<Root>/Analog Input' */
#include "MW_SVD.h"
#ifndef struct_tag_p5Oj7yF0nd6COoUgI0GAlG
#define struct_tag_p5Oj7yF0nd6COoUgI0GAlG

struct tag_p5Oj7yF0nd6COoUgI0GAlG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_p5Oj7yF0nd6COoUgI0GAlG */

#ifndef typedef_mbed_AnalogInput_InverterStar_T
#define typedef_mbed_AnalogInput_InverterStar_T

typedef struct tag_p5Oj7yF0nd6COoUgI0GAlG mbed_AnalogInput_InverterStar_T;

#endif                             /* typedef_mbed_AnalogInput_InverterStar_T */

/* Parameters (default storage) */
typedef struct P_InverterStartupControl_T_ P_InverterStartupControl_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_InverterStartupContro_T RT_MODEL_InverterStartupContr_T;

#endif                          /* RTW_HEADER_InverterStartupControl_types_h_ */
