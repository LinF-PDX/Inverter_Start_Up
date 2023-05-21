/*
 * InverterStartupControl_data.c
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

#include "InverterStartupControl.h"

/* Block parameters (default storage) */
P_InverterStartupControl_T InverterStartupControl_P = {
  /* Computed Parameter: Input_Y0
   * Referenced by: '<S1>/Input'
   */
  {
    {
      0.0,                             /* AMK_bReserve */
      0.0,                             /* AMK_ActualVelocity */
      0.0,                             /* AMK_MagnetizingCurrent */
      0.0,                             /* AMK_TorqueCurrent */
      0.0,                             /* AMK_bDcOn */
      0.0,                             /* AMK_bDerating */
      0.0,                             /* AMK_bError */
      0.0,                             /* AMK_bInverterOn */
      0.0,                             /* AMK_bQuitDcOn */
      0.0,                             /* AMK_bQuitInverterOn */
      0.0,                             /* AMK_bSystemReady */
      0.0                              /* AMK_bWarn */
    },                                 /* ptCAN_AMK_ActualValues1_Right */

    {
      0.0,                             /* AMK_ErrorInfo */
      0.0,                             /* AMK_TempIGBT */
      0.0,                             /* AMK_TempInverter */
      0.0                              /* AMK_TempMotor */
    },                                 /* ptCAN_AMK_ActualValues2_Right */

    {
      0.0,                             /* AMK_bReserve */
      0.0,                             /* AMK_ActualVelocity */
      0.0,                             /* AMK_MagnetizingCurrent */
      0.0,                             /* AMK_TorqueCurrent */
      0.0,                             /* AMK_bDcOn */
      0.0,                             /* AMK_bDerating */
      0.0,                             /* AMK_bError */
      0.0,                             /* AMK_bInverterOn */
      0.0,                             /* AMK_bQuitDcOn */
      0.0,                             /* AMK_bQuitInverterOn */
      0.0,                             /* AMK_bSystemReady */
      0.0                              /* AMK_bWarn */
    },                                 /* ptCAN_AMK_ActualValues1_Left */

    {
      0.0,                             /* AMK_ErrorInfo */
      0.0,                             /* AMK_TempIGBT */
      0.0,                             /* AMK_TempInverter */
      0.0                              /* AMK_TempMotor */
    }                                  /* ptCAN_AMK_ActualValues2_Left */
  },

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant5'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S3>/Constant9'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant10'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S3>/Gain'
   */
  1000.0,

  /* Expression: 50
   * Referenced by: '<S3>/Constant1'
   */
  50.0,

  /* Expression: -50
   * Referenced by: '<S3>/Constant2'
   */
  -50.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant7'
   */
  0.0,

  /* Expression: 200
   * Referenced by: '<S3>/Pulse Generator1'
   */
  200.0,

  /* Computed Parameter: PulseGenerator1_Period
   * Referenced by: '<S3>/Pulse Generator1'
   */
  2.0,

  /* Computed Parameter: PulseGenerator1_Duty
   * Referenced by: '<S3>/Pulse Generator1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Pulse Generator1'
   */
  0.0,

  /* Computed Parameter: TmpRTBAtLEFT_MOTORInport18_Init
   * Referenced by:
   */
  0.0F,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<S3>/Manual Switch2'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S3>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S3>/Manual Switch1'
   */
  1U
};
