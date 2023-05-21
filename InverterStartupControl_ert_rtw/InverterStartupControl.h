/*
 * InverterStartupControl.h
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

#ifndef RTW_HEADER_InverterStartupControl_h_
#define RTW_HEADER_InverterStartupControl_h_
#ifndef InverterStartupControl_COMMON_INCLUDES_
#define InverterStartupControl_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_MbedPinInterface.h"
#include "hostlib_vntcan.h"
#include "can_message.h"
#endif                             /* InverterStartupControl_COMMON_INCLUDES_ */

#include "InverterStartupControl_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  CAN_DATATYPE CANReceive_o2;          /* '<Root>/CAN Receive' */
  CAN_DATATYPE AMK0_SetPoints1;        /* '<S2>/CAN Pack' */
  CAN_DATATYPE TmpSignalConversionAtCANTransmi[2];/* '<Root>/AMK_Output' */
  int32_T bitParams[4];
  int32_T idMaskParams[4];
  int32_T bitParams_m[4];
  real_T ManualSwitch2;                /* '<S3>/Manual Switch2' */
  real_T AMK_ActualVelocity;           /* '<S1>/CAN Unpack' */
  real_T AMK_MagnetizingCurrent;       /* '<S1>/CAN Unpack' */
  real_T AMK_TorqueCurrent;            /* '<S1>/CAN Unpack' */
  real_T AMK_bDcOn;                    /* '<S1>/CAN Unpack' */
  real_T AMK_bDerating;                /* '<S1>/CAN Unpack' */
  real_T AMK_bError;                   /* '<S1>/CAN Unpack' */
  real_T AMK_bInverterOn;              /* '<S1>/CAN Unpack' */
  real_T AMK_bQuitDcOn;                /* '<S1>/CAN Unpack' */
  real_T AMK_bQuitInverterOn;          /* '<S1>/CAN Unpack' */
  real_T AMK_bSystemReady;             /* '<S1>/CAN Unpack' */
  real_T AMK_bWarn;                    /* '<S1>/CAN Unpack' */
  real_T AMK_ErrorInfo;                /* '<S1>/CAN Unpack1' */
  real_T AMK_TempIGBT;                 /* '<S1>/CAN Unpack1' */
  real_T AMK_TempInverter;             /* '<S1>/CAN Unpack1' */
  real_T AMK_TempMotor;                /* '<S1>/CAN Unpack1' */
  real_T AMK_ActualVelocity_i;         /* '<S1>/CAN Unpack2' */
  real_T AMK_MagnetizingCurrent_o;     /* '<S1>/CAN Unpack2' */
  real_T AMK_TorqueCurrent_g;          /* '<S1>/CAN Unpack2' */
  real_T AMK_bDcOn_p;                  /* '<S1>/CAN Unpack2' */
  real_T AMK_bDerating_m;              /* '<S1>/CAN Unpack2' */
  real_T AMK_bError_h;                 /* '<S1>/CAN Unpack2' */
  real_T AMK_bInverterOn_e;            /* '<S1>/CAN Unpack2' */
  real_T AMK_bQuitDcOn_l;              /* '<S1>/CAN Unpack2' */
  real_T AMK_bQuitInverterOn_l;        /* '<S1>/CAN Unpack2' */
  real_T AMK_bSystemReady_e;           /* '<S1>/CAN Unpack2' */
  real_T AMK_bWarn_a;                  /* '<S1>/CAN Unpack2' */
  real_T AMK_ErrorInfo_g;              /* '<S1>/CAN Unpack3' */
  real_T AMK_TempIGBT_i;               /* '<S1>/CAN Unpack3' */
  real_T AMK_TempInverter_i;           /* '<S1>/CAN Unpack3' */
  real_T AMK_TempMotor_g;              /* '<S1>/CAN Unpack3' */
  real_T AMK_bReserve;                 /* '<S1>/Constant' */
  real_T AMK_bReserve_e;               /* '<S1>/Constant' */
  real_T AMK_bReserve_d;               /* '<S1>/Constant1' */
  real_T AMK_bReserve_ew;              /* '<S1>/Constant1' */
  real32_T CastToSingle;               /* '<S3>/Cast To Single' */
  real32_T CastToSingle1;              /* '<S3>/Cast To Single1' */
  real32_T CastToSingle2;              /* '<S3>/Cast To Single2' */
  real32_T TmpRTBAtLEFT_MOTORInport18;
  real32_T CastToSingle4;              /* '<S3>/Cast To Single4' */
  real32_T CastToSingle5;              /* '<S3>/Cast To Single5' */
  real32_T CastToSingle3;              /* '<S3>/Cast To Single3' */
  real32_T AMK_TargetVelocity;         /* '<S5>/RIGHT_MOTOR' */
  real32_T AMK_TorqueLimitPositiv;     /* '<S5>/RIGHT_MOTOR' */
  real32_T AMK_TorqueLimitNegativ;     /* '<S5>/RIGHT_MOTOR' */
  MI_CMD GOV_e_miCmd;                  /* '<S3>/Chart' */
  uint8_T AMK_bInverterOn_tx;          /* '<S5>/RIGHT_MOTOR' */
  uint8_T AMK_bDcOn_tx;                /* '<S5>/RIGHT_MOTOR' */
  uint8_T AMK_bEnable;                 /* '<S5>/RIGHT_MOTOR' */
  uint8_T AMK_bErrorReset;             /* '<S5>/RIGHT_MOTOR' */
} B_InverterStartupControl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_AnalogInput_InverterStar_T obj; /* '<Root>/Analog Input' */
  real_T CANReceive_CANReceive[137];   /* '<Root>/CAN Receive' */
  real_T CANTransmit_CANTransmit[137]; /* '<Root>/CAN Transmit' */
  real32_T TmpRTBAtLEFT_MOTORInport18_Buff;/* synthesized block */
  int32_T clockTickCounter;            /* '<S3>/Pulse Generator1' */
  int32_T sfEvent;                     /* '<S5>/RIGHT_MOTOR' */
  int32_T sfEvent_l;                   /* '<S5>/LEFT_MOTOR' */
  int32_T sfEvent_k;                   /* '<S3>/Chart' */
  uint32_T is_c3_motor_interface_lib;  /* '<S5>/RIGHT_MOTOR' */
  uint32_T is_AMK_startup;             /* '<S5>/RIGHT_MOTOR' */
  uint32_T is_AMK_errorReset;          /* '<S5>/RIGHT_MOTOR' */
  uint32_T is_AMK_shutdown;            /* '<S5>/RIGHT_MOTOR' */
  uint32_T is_c1_motor_interface_lib;  /* '<S5>/LEFT_MOTOR' */
  uint32_T is_AMK_startup_o;           /* '<S5>/LEFT_MOTOR' */
  uint32_T is_AMK_errorReset_c;        /* '<S5>/LEFT_MOTOR' */
  uint32_T is_AMK_shutdown_j;          /* '<S5>/LEFT_MOTOR' */
  uint32_T is_c1_InverterStartupControl;/* '<S3>/Chart' */
  int_T CANPack_ModeSignalID;          /* '<S2>/CAN Pack' */
  int_T CANTransmit_PortWidth;         /* '<Root>/CAN Transmit' */
  int_T CANUnpack_ModeSignalID;        /* '<S1>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<S1>/CAN Unpack' */
  int_T CANUnpack1_ModeSignalID;       /* '<S1>/CAN Unpack1' */
  int_T CANUnpack1_StatusPortID;       /* '<S1>/CAN Unpack1' */
  int_T CANUnpack2_ModeSignalID;       /* '<S1>/CAN Unpack2' */
  int_T CANUnpack2_StatusPortID;       /* '<S1>/CAN Unpack2' */
  int_T CANUnpack3_ModeSignalID;       /* '<S1>/CAN Unpack3' */
  int_T CANUnpack3_StatusPortID;       /* '<S1>/CAN Unpack3' */
  int8_T AMK_Input_SubsysRanBC;        /* '<Root>/AMK_Input' */
  uint8_T is_active_c3_motor_interface_li;/* '<S5>/RIGHT_MOTOR' */
  uint8_T temporalCounter_i1;          /* '<S5>/RIGHT_MOTOR' */
  uint8_T is_active_c1_motor_interface_li;/* '<S5>/LEFT_MOTOR' */
  uint8_T temporalCounter_i1_b;        /* '<S5>/LEFT_MOTOR' */
  uint8_T is_active_c1_InverterStartupCon;/* '<S3>/Chart' */
  boolean_T CANTransmit_BlockDisabled; /* '<Root>/CAN Transmit' */
  boolean_T doneDoubleBufferReInit;    /* '<S5>/RIGHT_MOTOR' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S5>/LEFT_MOTOR' */
  boolean_T objisempty;                /* '<Root>/Analog Input' */
} DW_InverterStartupControl_T;

/* Parameters (default storage) */
struct P_InverterStartupControl_T_ {
  struct_RAdav281ZwKrAfZlrgLeL Input_Y0;/* Computed Parameter: Input_Y0
                                         * Referenced by: '<S1>/Input'
                                         */
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant5'
                                        */
  real_T Constant9_Value;              /* Expression: 100
                                        * Referenced by: '<S3>/Constant9'
                                        */
  real_T Constant10_Value;             /* Expression: 1
                                        * Referenced by: '<S3>/Constant10'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant11'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 1000
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Constant1_Value_f;            /* Expression: 50
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: -50
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant7'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 200
                                        * Referenced by: '<S3>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<S3>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<S3>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S3>/Pulse Generator1'
                                        */
  real32_T TmpRTBAtLEFT_MOTORInport18_Init;
                          /* Computed Parameter: TmpRTBAtLEFT_MOTORInport18_Init
                           * Referenced by:
                           */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<S3>/Manual Switch2'
                              */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S3>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S3>/Manual Switch1'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_InverterStartupContro_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint16_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_InverterStartupControl_T InverterStartupControl_P;

/* Block signals (default storage) */
extern B_InverterStartupControl_T InverterStartupControl_B;

/* Block states (default storage) */
extern DW_InverterStartupControl_T InverterStartupControl_DW;

/* External function called from main */
extern void InverterStartupControl_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void InverterStartupControl_initialize(void);
extern void InverterStartupControl_step0(void);
extern void InverterStartupControl_step1(void);
extern void InverterStartupControl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_InverterStartupContr_T *const InverterStartupControl_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S5>/Constant1' : Unused code path elimination
 * Block '<S5>/Delay' : Unused code path elimination
 * Block '<S5>/GreaterThan' : Unused code path elimination
 * Block '<S5>/OR' : Unused code path elimination
 * Block '<S5>/Switch' : Unused code path elimination
 * Block '<S5>/motorErrorActive' : Unused code path elimination
 * Block '<S5>/motorErrorActive1' : Unused code path elimination
 * Block '<S5>/overallMotorState' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'InverterStartupControl'
 * '<S1>'   : 'InverterStartupControl/AMK_Input'
 * '<S2>'   : 'InverterStartupControl/AMK_Output'
 * '<S3>'   : 'InverterStartupControl/Control'
 * '<S4>'   : 'InverterStartupControl/Control/Chart'
 * '<S5>'   : 'InverterStartupControl/Control/motor_interface'
 * '<S6>'   : 'InverterStartupControl/Control/motor_interface/LEFT_MOTOR'
 * '<S7>'   : 'InverterStartupControl/Control/motor_interface/RIGHT_MOTOR'
 */
#endif                                /* RTW_HEADER_InverterStartupControl_h_ */
