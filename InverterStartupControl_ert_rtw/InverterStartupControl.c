/*
 * InverterStartupControl.c
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
#include "rtwtypes.h"
#include "InverterStartupControl_types.h"
#include "can_message.h"
#include "InverterStartupControl_private.h"
#include <string.h>

/* Named constants for Chart: '<S3>/Chart' */
#define InverterStar_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define InverterStartupCont_IN_Shutdown (5U)
#define InverterStartupContr_CALL_EVENT (-1)
#define InverterStartupContro_IN_Error0 (1U)
#define InverterStartupContro_IN_Error1 (2U)
#define InverterStartupControl_IN_Init (3U)
#define InverterStartupControl_IN_Run  (4U)

/* Named constants for Chart: '<S5>/LEFT_MOTOR' */
#define Inver_IN_enforceSetpointsZero_d (1U)
#define Inver_IN_motorOff_waitingForGov (6U)
#define Inverte_IN_enforceSetpointsZero (2U)
#define InverterSt_IN_AMK_errorDetected (1U)
#define InverterSta_IN_waiting_sysReady (4U)
#define InverterStart_IN_AMK_errorReset (2U)
#define InverterStartupC_IN_AMK_running (3U)
#define InverterStartupC_IN_AMK_startup (5U)
#define InverterStartupC_IN_toggleReset (4U)
#define InverterStartupCo_IN_commandOff (1U)
#define InverterStartupCo_IN_toggleDCon (3U)
#define InverterStartupCon_IN_commandOn (1U)
#define InverterStartupCon_IN_sendReset (2U)
#define InverterStartup_IN_AMK_shutdown (4U)
#define InverterStartup_IN_toggleEnable (3U)

/* Block signals (default storage) */
B_InverterStartupControl_T InverterStartupControl_B;

/* Block states (default storage) */
DW_InverterStartupControl_T InverterStartupControl_DW;

/* Real-time model */
static RT_MODEL_InverterStartupContr_T InverterStartupControl_M_;
RT_MODEL_InverterStartupContr_T *const InverterStartupControl_M =
  &InverterStartupControl_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void InverterStartupControl_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(InverterStartupControl_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  InverterStartupControl_M->Timing.RateInteraction.TID0_1 =
    (InverterStartupControl_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (InverterStartupControl_M->Timing.TaskCounters.TID[1])++;
  if ((InverterStartupControl_M->Timing.TaskCounters.TID[1]) > 399) {/* Sample time: [2.0s, 0.0s] */
    InverterStartupControl_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void InverterStartupControl_step0(void) /* Sample time: [0.005s, 0.0s] */
{
  real_T rtb_AnalogInput_0;
  int32_T isMsgAvailable;
  int32_T isMsgReceived;
  char_T *sErr;
  void *outputMsgRef;

  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(InverterStartupControl_DW.AMK_Input_SubsysRanBC);

  /* S-Function (svntcanreceive): '<Root>/CAN Receive' */
  sErr = GetErrorBuffer(&InverterStartupControl_DW.CANReceive_CANReceive[0U]);
  isMsgAvailable = 1;
  isMsgReceived = 0;

  /* S-Function (svntcanreceive): '<Root>/CAN Receive' */
  outputMsgRef = &InverterStartupControl_B.CANReceive_o2;

  /* End of Outputs for S-Function (svntcanreceive): '<Root>/CAN Receive' */
  while (isMsgAvailable == 1) {
    LibOutputs_CANReceive(&InverterStartupControl_DW.CANReceive_CANReceive[0U],
                          outputMsgRef, 2, &isMsgReceived, &isMsgAvailable);
    if (*sErr != 0) {
      rtmSetErrorStatus(InverterStartupControl_M, sErr);
      rtmSetStopRequested(InverterStartupControl_M, 1);
    }

    if (isMsgReceived == 1) {
      isMsgReceived = 0;

      /* Outputs for Function Call SubSystem: '<Root>/AMK_Input' */
      /* S-Function (scanunpack): '<S1>/CAN Unpack' */
      {
        /* S-Function (scanunpack): '<S1>/CAN Unpack' */
        if ((8 == InverterStartupControl_B.CANReceive_o2.Length) &&
            (InverterStartupControl_B.CANReceive_o2.ID != INVALID_CAN_ID) ) {
          if ((644 == InverterStartupControl_B.CANReceive_o2.ID) && (0U ==
               InverterStartupControl_B.CANReceive_o2.Extended) ) {
            {
              /* --------------- START Unpacking signal 0 ------------------
               *  startBit                = 16
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[2]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[3]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_ActualVelocity = result;
                }
              }

              /* --------------- START Unpacking signal 1 ------------------
               *  startBit                = 48
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[6]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[7]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_MagnetizingCurrent = result;
                }
              }

              /* --------------- START Unpacking signal 2 ------------------
               *  startBit                = 32
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[4]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[5]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_TorqueCurrent = result;
                }
              }

              /* --------------- START Unpacking signal 3 ------------------
               *  startBit                = 12
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x10U)) >> 4);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bDcOn = result;
                }
              }

              /* --------------- START Unpacking signal 4 ------------------
               *  startBit                = 15
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x80U)) >> 7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bDerating = result;
                }
              }

              /* --------------- START Unpacking signal 5 ------------------
               *  startBit                = 9
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x2U)) >> 1);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bError = result;
                }
              }

              /* --------------- START Unpacking signal 6 ------------------
               *  startBit                = 14
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x40U)) >> 6);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bInverterOn = result;
                }
              }

              /* --------------- START Unpacking signal 7 ------------------
               *  startBit                = 11
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x8U)) >> 3);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bQuitDcOn = result;
                }
              }

              /* --------------- START Unpacking signal 8 ------------------
               *  startBit                = 13
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x20U)) >> 5);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bQuitInverterOn = result;
                }
              }

              /* --------------- START Unpacking signal 9 ------------------
               *  startBit                = 8
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x1U));
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bSystemReady = result;
                }
              }

              /* --------------- START Unpacking signal 10 ------------------
               *  startBit                = 10
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x4U)) >> 2);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bWarn = result;
                }
              }
            }
          }
        }
      }

      /* S-Function (scanunpack): '<S1>/CAN Unpack1' */
      {
        /* S-Function (scanunpack): '<S1>/CAN Unpack1' */
        if ((8 == InverterStartupControl_B.CANReceive_o2.Length) &&
            (InverterStartupControl_B.CANReceive_o2.ID != INVALID_CAN_ID) ) {
          if ((646 == InverterStartupControl_B.CANReceive_o2.ID) && (0U ==
               InverterStartupControl_B.CANReceive_o2.Extended) ) {
            {
              /* --------------- START Unpacking signal 0 ------------------
               *  startBit                = 32
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[4]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[5]) << 8);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_ErrorInfo = result;
                }
              }

              /* --------------- START Unpacking signal 1 ------------------
               *  startBit                = 48
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 0.1
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[6]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[7]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.1;
                  InverterStartupControl_B.AMK_TempIGBT = result;
                }
              }

              /* --------------- START Unpacking signal 2 ------------------
               *  startBit                = 16
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 0.1
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[2]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[3]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.1;
                  InverterStartupControl_B.AMK_TempInverter = result;
                }
              }

              /* --------------- START Unpacking signal 3 ------------------
               *  startBit                = 0
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 0.1
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[0]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.1;
                  InverterStartupControl_B.AMK_TempMotor = result;
                }
              }
            }
          }
        }
      }

      /* S-Function (scanunpack): '<S1>/CAN Unpack2' */
      {
        /* S-Function (scanunpack): '<S1>/CAN Unpack2' */
        if ((8 == InverterStartupControl_B.CANReceive_o2.Length) &&
            (InverterStartupControl_B.CANReceive_o2.ID != INVALID_CAN_ID) ) {
          if ((645 == InverterStartupControl_B.CANReceive_o2.ID) && (0U ==
               InverterStartupControl_B.CANReceive_o2.Extended) ) {
            {
              /* --------------- START Unpacking signal 0 ------------------
               *  startBit                = 16
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[2]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[3]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_ActualVelocity_i = result;
                }
              }

              /* --------------- START Unpacking signal 1 ------------------
               *  startBit                = 48
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[6]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[7]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_MagnetizingCurrent_o = result;
                }
              }

              /* --------------- START Unpacking signal 2 ------------------
               *  startBit                = 32
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[4]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[5]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_TorqueCurrent_g = result;
                }
              }

              /* --------------- START Unpacking signal 3 ------------------
               *  startBit                = 12
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x10U)) >> 4);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bDcOn_p = result;
                }
              }

              /* --------------- START Unpacking signal 4 ------------------
               *  startBit                = 15
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x80U)) >> 7);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bDerating_m = result;
                }
              }

              /* --------------- START Unpacking signal 5 ------------------
               *  startBit                = 9
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x2U)) >> 1);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bError_h = result;
                }
              }

              /* --------------- START Unpacking signal 6 ------------------
               *  startBit                = 14
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x40U)) >> 6);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bInverterOn_e = result;
                }
              }

              /* --------------- START Unpacking signal 7 ------------------
               *  startBit                = 11
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x8U)) >> 3);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bQuitDcOn_l = result;
                }
              }

              /* --------------- START Unpacking signal 8 ------------------
               *  startBit                = 13
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x20U)) >> 5);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bQuitInverterOn_l = result;
                }
              }

              /* --------------- START Unpacking signal 9 ------------------
               *  startBit                = 8
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x1U));
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bSystemReady_e = result;
                }
              }

              /* --------------- START Unpacking signal 10 ------------------
               *  startBit                = 10
               *  length                  = 1
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) &
                        (uint8_T)(0x4U)) >> 2);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_bWarn_a = result;
                }
              }
            }
          }
        }
      }

      /* S-Function (scanunpack): '<S1>/CAN Unpack3' */
      {
        /* S-Function (scanunpack): '<S1>/CAN Unpack3' */
        if ((8 == InverterStartupControl_B.CANReceive_o2.Length) &&
            (InverterStartupControl_B.CANReceive_o2.ID != INVALID_CAN_ID) ) {
          if ((647 == InverterStartupControl_B.CANReceive_o2.ID) && (0U ==
               InverterStartupControl_B.CANReceive_o2.Extended) ) {
            {
              /* --------------- START Unpacking signal 0 ------------------
               *  startBit                = 32
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[4]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[5]) << 8);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  InverterStartupControl_B.AMK_ErrorInfo_g = result;
                }
              }

              /* --------------- START Unpacking signal 1 ------------------
               *  startBit                = 48
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 0.1
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[6]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[7]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.1;
                  InverterStartupControl_B.AMK_TempIGBT_i = result;
                }
              }

              /* --------------- START Unpacking signal 2 ------------------
               *  startBit                = 16
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 0.1
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[2]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[3]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.1;
                  InverterStartupControl_B.AMK_TempInverter_i = result;
                }
              }

              /* --------------- START Unpacking signal 3 ------------------
               *  startBit                = 0
               *  length                  = 16
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = SIGNED
               *  factor                  = 0.1
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  int16_T unpackedValue = 0;

                  {
                    uint16_T tempValue = (uint16_T) (0);
                    int16_T* tempValuePtr = (int16_T*)&tempValue;

                    {
                      tempValue = tempValue | (uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[0]);
                      tempValue = tempValue | (uint16_T)((uint16_T)
                        (InverterStartupControl_B.CANReceive_o2.Data[1]) << 8);
                    }

                    unpackedValue = *tempValuePtr;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.1;
                  InverterStartupControl_B.AMK_TempMotor_g = result;
                }
              }
            }
          }
        }
      }

      /* Constant: '<S1>/Constant' */
      InverterStartupControl_B.AMK_bReserve =
        InverterStartupControl_P.Constant_Value;

      /* SignalConversion generated from: '<S1>/Constant' */
      InverterStartupControl_B.AMK_bReserve_e =
        InverterStartupControl_B.AMK_bReserve;

      /* Constant: '<S1>/Constant1' */
      InverterStartupControl_B.AMK_bReserve_d =
        InverterStartupControl_P.Constant1_Value;

      /* SignalConversion generated from: '<S1>/Constant1' */
      InverterStartupControl_B.AMK_bReserve_ew =
        InverterStartupControl_B.AMK_bReserve_d;
      InverterStartupControl_DW.AMK_Input_SubsysRanBC = 4;

      /* End of Outputs for SubSystem: '<Root>/AMK_Input' */
    }
  }

  /* End of Outputs for S-Function (svntcanreceive): '<Root>/CAN Receive' */

  /* ManualSwitch: '<S3>/Manual Switch2' */
  if (InverterStartupControl_P.ManualSwitch2_CurrentSetting == 1) {
    /* ManualSwitch: '<S3>/Manual Switch2' incorporates:
     *  Constant: '<S3>/Constant10'
     */
    InverterStartupControl_B.ManualSwitch2 =
      InverterStartupControl_P.Constant10_Value;
  } else {
    /* ManualSwitch: '<S3>/Manual Switch2' incorporates:
     *  Constant: '<S3>/Constant11'
     */
    InverterStartupControl_B.ManualSwitch2 =
      InverterStartupControl_P.Constant11_Value;
  }

  /* End of ManualSwitch: '<S3>/Manual Switch2' */

  /* Chart: '<S3>/Chart' */
  InverterStartupControl_DW.sfEvent_k = InverterStartupContr_CALL_EVENT;
  if (InverterStartupControl_DW.is_active_c1_InverterStartupCon == 0U) {
    InverterStartupControl_DW.is_active_c1_InverterStartupCon = 1U;
    InverterStartupControl_DW.is_c1_InverterStartupControl =
      InverterStartupControl_IN_Init;
    InverterStartupControl_B.GOV_e_miCmd = CMD_INIT;
  } else {
    switch (InverterStartupControl_DW.is_c1_InverterStartupControl) {
     case InverterStartupContro_IN_Error0:
      InverterStartupControl_B.GOV_e_miCmd = ERR_RESET;
      if (InverterStartupControl_B.AMK_bError == 0.0) {
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupControl_IN_Run;
        InverterStartupControl_B.GOV_e_miCmd = CMD_STARTUP;
      }
      break;

     case InverterStartupContro_IN_Error1:
      InverterStartupControl_B.GOV_e_miCmd = ERR_RESET;
      if (InverterStartupControl_B.AMK_bError_h == 0.0) {
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupControl_IN_Run;
        InverterStartupControl_B.GOV_e_miCmd = CMD_STARTUP;
      }
      break;

     case InverterStartupControl_IN_Init:
      InverterStartupControl_B.GOV_e_miCmd = CMD_INIT;
      if ((InverterStartupControl_B.AMK_bSystemReady == 1.0) &&
          (InverterStartupControl_B.AMK_bSystemReady_e == 1.0) &&
          (InverterStartupControl_B.ManualSwitch2 == 0.0)) {
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupControl_IN_Run;
        InverterStartupControl_B.GOV_e_miCmd = CMD_STARTUP;
      }
      break;

     case InverterStartupControl_IN_Run:
      InverterStartupControl_B.GOV_e_miCmd = CMD_STARTUP;
      if (InverterStartupControl_B.AMK_bError == 1.0) {
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupContro_IN_Error0;
        InverterStartupControl_B.GOV_e_miCmd = ERR_RESET;
      } else if (InverterStartupControl_B.ManualSwitch2 == 1.0) {
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupCont_IN_Shutdown;
        InverterStartupControl_B.GOV_e_miCmd = CMD_SHUTDOWN;
      } else if (InverterStartupControl_B.AMK_bError_h == 1.0) {
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupContro_IN_Error1;
        InverterStartupControl_B.GOV_e_miCmd = ERR_RESET;
      }
      break;

     default:
      /* case IN_Shutdown: */
      InverterStartupControl_B.GOV_e_miCmd = CMD_SHUTDOWN;
      if (InverterStartupControl_B.ManualSwitch2 == 0.0) {
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupControl_IN_Init;
        InverterStartupControl_B.GOV_e_miCmd = CMD_INIT;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* MATLABSystem: '<Root>/Analog Input' */
  if (InverterStartupControl_DW.obj.SampleTime !=
      InverterStartupControl_P.AnalogInput_SampleTime) {
    InverterStartupControl_DW.obj.SampleTime =
      InverterStartupControl_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(InverterStartupControl_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(InverterStartupControl_DW.obj.MW_ANALOGIN_HANDLE,
    &rtb_AnalogInput_0, 7);

  /* ManualSwitch: '<S3>/Manual Switch' */
  if (InverterStartupControl_P.ManualSwitch_CurrentSetting == 1) {
    /* DataTypeConversion: '<S3>/Cast To Single' incorporates:
     *  Constant: '<S3>/Constant'
     */
    InverterStartupControl_B.CastToSingle = (real32_T)
      InverterStartupControl_P.Constant_Value_j;
  } else {
    /* DataTypeConversion: '<S3>/Cast To Single' incorporates:
     *  Gain: '<S3>/Gain'
     *  MATLABSystem: '<Root>/Analog Input'
     */
    InverterStartupControl_B.CastToSingle = (real32_T)
      (InverterStartupControl_P.Gain_Gain * rtb_AnalogInput_0);
  }

  /* End of ManualSwitch: '<S3>/Manual Switch' */

  /* DataTypeConversion: '<S3>/Cast To Single1' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  InverterStartupControl_B.CastToSingle1 = (real32_T)
    InverterStartupControl_P.Constant1_Value_f;

  /* DataTypeConversion: '<S3>/Cast To Single2' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  InverterStartupControl_B.CastToSingle2 = (real32_T)
    InverterStartupControl_P.Constant2_Value;

  /* Chart: '<S5>/RIGHT_MOTOR' */
  if (InverterStartupControl_DW.temporalCounter_i1 < 255U) {
    InverterStartupControl_DW.temporalCounter_i1++;
  }

  InverterStartupControl_DW.sfEvent = InverterStartupContr_CALL_EVENT;
  if (InverterStartupControl_DW.is_active_c3_motor_interface_li == 0U) {
    InverterStartupControl_DW.is_active_c3_motor_interface_li = 1U;
    InverterStartupControl_DW.is_c3_motor_interface_lib =
      Inver_IN_motorOff_waitingForGov;
    InverterStartupControl_B.AMK_bInverterOn_tx = 0U;
    InverterStartupControl_B.AMK_bDcOn_tx = 0U;
    InverterStartupControl_B.AMK_bEnable = 0U;
    InverterStartupControl_B.AMK_bErrorReset = 0U;
    InverterStartupControl_B.AMK_TargetVelocity = 0.0F;
    InverterStartupControl_B.AMK_TorqueLimitPositiv = 0.0F;
    InverterStartupControl_B.AMK_TorqueLimitNegativ = 0.0F;
  } else {
    switch (InverterStartupControl_DW.is_c3_motor_interface_lib) {
     case InverterSt_IN_AMK_errorDetected:
      if (InverterStartupControl_B.GOV_e_miCmd == ERR_RESET) {
        InverterStartupControl_DW.is_c3_motor_interface_lib =
          InverterStart_IN_AMK_errorReset;
        InverterStartupControl_DW.is_AMK_errorReset =
          Inver_IN_enforceSetpointsZero_d;
        InverterStartupControl_B.AMK_TargetVelocity = 0.0F;
        InverterStartupControl_B.AMK_TorqueLimitPositiv = 0.0F;
        InverterStartupControl_B.AMK_TorqueLimitNegativ = 0.0F;
        InverterStartupControl_B.AMK_bInverterOn_tx = 0U;
      }
      break;

     case InverterStart_IN_AMK_errorReset:
      switch (InverterStartupControl_DW.is_AMK_errorReset) {
       case Inver_IN_enforceSetpointsZero_d:
        InverterStartupControl_B.AMK_bInverterOn_tx = 0U;
        if (InverterStartupControl_B.AMK_bInverterOn == 0.0) {
          InverterStartupControl_DW.is_AMK_errorReset =
            InverterStartup_IN_toggleEnable;
          InverterStartupControl_DW.temporalCounter_i1 = 0U;
          InverterStartupControl_B.AMK_bEnable = 0U;
        }
        break;

       case InverterStartupCon_IN_sendReset:
        InverterStartupControl_B.AMK_bErrorReset = 1U;
        if (InverterStartupControl_DW.temporalCounter_i1 >= 100U) {
          InverterStartupControl_DW.is_AMK_errorReset =
            InverterStartupC_IN_toggleReset;
          InverterStartupControl_B.AMK_bErrorReset = 0U;
        }
        break;

       case InverterStartup_IN_toggleEnable:
        InverterStartupControl_B.AMK_bEnable = 0U;
        if (InverterStartupControl_DW.temporalCounter_i1 >= 100U) {
          InverterStartupControl_DW.is_AMK_errorReset =
            InverterStartupCon_IN_sendReset;
          InverterStartupControl_DW.temporalCounter_i1 = 0U;
          InverterStartupControl_B.AMK_bErrorReset = 1U;
        }
        break;

       default:
        /* case IN_toggleReset: */
        InverterStartupControl_B.AMK_bErrorReset = 0U;
        if (InverterStartupControl_B.AMK_bSystemReady == 1.0) {
          InverterStartupControl_DW.is_AMK_errorReset =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c3_motor_interface_lib =
            Inver_IN_motorOff_waitingForGov;
          InverterStartupControl_B.AMK_bInverterOn_tx = 0U;
          InverterStartupControl_B.AMK_bDcOn_tx = 0U;
          InverterStartupControl_B.AMK_bEnable = 0U;
          InverterStartupControl_B.AMK_bErrorReset = 0U;
          InverterStartupControl_B.AMK_TargetVelocity = 0.0F;
          InverterStartupControl_B.AMK_TorqueLimitPositiv = 0.0F;
          InverterStartupControl_B.AMK_TorqueLimitNegativ = 0.0F;
        }
        break;
      }
      break;

     case InverterStartupC_IN_AMK_running:
      if (InverterStartupControl_B.AMK_bError == 1.0) {
        InverterStartupControl_DW.is_c3_motor_interface_lib =
          InverterSt_IN_AMK_errorDetected;
      } else if (InverterStartupControl_B.GOV_e_miCmd == CMD_SHUTDOWN) {
        InverterStartupControl_DW.is_c3_motor_interface_lib =
          InverterStartup_IN_AMK_shutdown;
        InverterStartupControl_DW.is_AMK_shutdown =
          Inverte_IN_enforceSetpointsZero;
        InverterStartupControl_B.AMK_TargetVelocity = 0.0F;
        InverterStartupControl_B.AMK_TorqueLimitPositiv = 0.0F;
        InverterStartupControl_B.AMK_TorqueLimitNegativ = 0.0F;
        InverterStartupControl_B.AMK_bInverterOn_tx = 0U;
      } else {
        InverterStartupControl_B.AMK_TargetVelocity =
          InverterStartupControl_B.CastToSingle;
        InverterStartupControl_B.AMK_TorqueLimitPositiv =
          InverterStartupControl_B.CastToSingle1;
        InverterStartupControl_B.AMK_TorqueLimitNegativ =
          InverterStartupControl_B.CastToSingle2;
      }
      break;

     case InverterStartup_IN_AMK_shutdown:
      switch (InverterStartupControl_DW.is_AMK_shutdown) {
       case InverterStartupCo_IN_commandOff:
        InverterStartupControl_B.AMK_bEnable = 0U;
        if (InverterStartupControl_B.AMK_bQuitInverterOn == 0.0) {
          InverterStartupControl_DW.is_AMK_shutdown =
            InverterStartupCo_IN_toggleDCon;
          InverterStartupControl_B.AMK_bDcOn_tx = 0U;
        } else if (InverterStartupControl_B.AMK_bError == 1.0) {
          InverterStartupControl_DW.is_AMK_shutdown =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c3_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;

       case Inverte_IN_enforceSetpointsZero:
        InverterStartupControl_B.AMK_bInverterOn_tx = 0U;
        if (InverterStartupControl_B.AMK_bInverterOn == 0.0) {
          InverterStartupControl_DW.is_AMK_shutdown =
            InverterStartupCo_IN_commandOff;
          InverterStartupControl_B.AMK_bEnable = 0U;
        } else if (InverterStartupControl_B.AMK_bError == 1.0) {
          InverterStartupControl_DW.is_AMK_shutdown =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c3_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;

       default:
        /* case IN_toggleDCon: */
        InverterStartupControl_B.AMK_bDcOn_tx = 0U;
        if ((InverterStartupControl_B.AMK_bDcOn == 0.0) &&
            (InverterStartupControl_B.AMK_bQuitDcOn == 0.0)) {
          InverterStartupControl_DW.is_AMK_shutdown =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c3_motor_interface_lib =
            Inver_IN_motorOff_waitingForGov;
          InverterStartupControl_B.AMK_bInverterOn_tx = 0U;
          InverterStartupControl_B.AMK_bDcOn_tx = 0U;
          InverterStartupControl_B.AMK_bEnable = 0U;
          InverterStartupControl_B.AMK_bErrorReset = 0U;
          InverterStartupControl_B.AMK_TargetVelocity = 0.0F;
          InverterStartupControl_B.AMK_TorqueLimitPositiv = 0.0F;
          InverterStartupControl_B.AMK_TorqueLimitNegativ = 0.0F;
        } else if (InverterStartupControl_B.AMK_bError == 1.0) {
          InverterStartupControl_DW.is_AMK_shutdown =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c3_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;
      }
      break;

     case InverterStartupC_IN_AMK_startup:
      switch (InverterStartupControl_DW.is_AMK_startup) {
       case InverterStartupCon_IN_commandOn:
        InverterStartupControl_B.AMK_bEnable = 1U;
        InverterStartupControl_B.AMK_bInverterOn_tx = 1U;
        if ((InverterStartupControl_B.AMK_bInverterOn == 1.0) &&
            (InverterStartupControl_B.AMK_bQuitInverterOn == 1.0)) {
          InverterStartupControl_DW.is_AMK_startup =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c3_motor_interface_lib =
            InverterStartupC_IN_AMK_running;
        } else if (InverterStartupControl_B.AMK_bError == 1.0) {
          InverterStartupControl_DW.is_AMK_startup =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c3_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;

       case Inverte_IN_enforceSetpointsZero:
        if (InverterStartupControl_DW.temporalCounter_i1 >= 200U) {
          InverterStartupControl_DW.is_AMK_startup =
            InverterStartupCon_IN_commandOn;
          InverterStartupControl_B.AMK_bEnable = 1U;
          InverterStartupControl_B.AMK_bInverterOn_tx = 1U;
        } else if (InverterStartupControl_B.AMK_bError == 1.0) {
          InverterStartupControl_DW.is_AMK_startup =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c3_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;

       case InverterStartupCo_IN_toggleDCon:
        InverterStartupControl_B.AMK_bDcOn_tx = 1U;
        if ((InverterStartupControl_B.AMK_bDcOn == 1.0) &&
            (InverterStartupControl_B.AMK_bQuitDcOn == 1.0)) {
          InverterStartupControl_DW.is_AMK_startup =
            Inverte_IN_enforceSetpointsZero;
          InverterStartupControl_DW.temporalCounter_i1 = 0U;
          InverterStartupControl_B.AMK_TargetVelocity = 0.0F;
          InverterStartupControl_B.AMK_TorqueLimitPositiv = 0.0F;
          InverterStartupControl_B.AMK_TorqueLimitNegativ = 0.0F;
        } else if (InverterStartupControl_B.AMK_bError == 1.0) {
          InverterStartupControl_DW.is_AMK_startup =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c3_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;

       default:
        /* case IN_waiting_sysReady: */
        if (InverterStartupControl_B.AMK_bSystemReady == 1.0) {
          InverterStartupControl_DW.is_AMK_startup =
            InverterStartupCo_IN_toggleDCon;
          InverterStartupControl_B.AMK_bDcOn_tx = 1U;
        } else if (InverterStartupControl_B.AMK_bError == 1.0) {
          InverterStartupControl_DW.is_AMK_startup =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c3_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;
      }
      break;

     default:
      /* case IN_motorOff_waitingForGov: */
      InverterStartupControl_B.AMK_bInverterOn_tx = 0U;
      InverterStartupControl_B.AMK_bDcOn_tx = 0U;
      InverterStartupControl_B.AMK_bEnable = 0U;
      InverterStartupControl_B.AMK_bErrorReset = 0U;
      if (InverterStartupControl_B.GOV_e_miCmd == CMD_STARTUP) {
        InverterStartupControl_DW.is_c3_motor_interface_lib =
          InverterStartupC_IN_AMK_startup;
        InverterStartupControl_DW.is_AMK_startup =
          InverterSta_IN_waiting_sysReady;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/RIGHT_MOTOR' */

  /* S-Function (scanpack): '<S2>/CAN Pack' */
  /* S-Function (scanpack): '<S2>/CAN Pack' */
  InverterStartupControl_B.AMK0_SetPoints1.ID = 389U;
  InverterStartupControl_B.AMK0_SetPoints1.Length = 8U;
  InverterStartupControl_B.AMK0_SetPoints1.Extended = 0U;
  InverterStartupControl_B.AMK0_SetPoints1.Remote = 0;
  InverterStartupControl_B.AMK0_SetPoints1.Data[0] = 0;
  InverterStartupControl_B.AMK0_SetPoints1.Data[1] = 0;
  InverterStartupControl_B.AMK0_SetPoints1.Data[2] = 0;
  InverterStartupControl_B.AMK0_SetPoints1.Data[3] = 0;
  InverterStartupControl_B.AMK0_SetPoints1.Data[4] = 0;
  InverterStartupControl_B.AMK0_SetPoints1.Data[5] = 0;
  InverterStartupControl_B.AMK0_SetPoints1.Data[6] = 0;
  InverterStartupControl_B.AMK0_SetPoints1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = InverterStartupControl_B.AMK_TargetVelocity;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        int16_T packedValue;
        int32_T scaledValue;
        if (outValue > 2147483647.0) {
          scaledValue = 2147483647;
        } else if (outValue < -2147483648.0) {
          scaledValue = -2147483647 - 1;
        } else {
          scaledValue = (int32_T) outValue;
        }

        if (scaledValue > (int32_T) (32767)) {
          packedValue = 32767;
        } else if (scaledValue < (int32_T)((-(32767)-1))) {
          packedValue = (-(32767)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            InverterStartupControl_B.AMK0_SetPoints1.Data[2] =
              InverterStartupControl_B.AMK0_SetPoints1.Data[2] | (uint8_T)
              ((uint16_T)(tempValue & (uint16_T)0xFFU));
            InverterStartupControl_B.AMK0_SetPoints1.Data[3] =
              InverterStartupControl_B.AMK0_SetPoints1.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(tempValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = InverterStartupControl_B.AMK_TorqueLimitNegativ;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        int16_T packedValue;
        int32_T scaledValue;
        if (outValue > 2147483647.0) {
          scaledValue = 2147483647;
        } else if (outValue < -2147483648.0) {
          scaledValue = -2147483647 - 1;
        } else {
          scaledValue = (int32_T) outValue;
        }

        if (scaledValue > (int32_T) (32767)) {
          packedValue = 32767;
        } else if (scaledValue < (int32_T)((-(32767)-1))) {
          packedValue = (-(32767)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            InverterStartupControl_B.AMK0_SetPoints1.Data[6] =
              InverterStartupControl_B.AMK0_SetPoints1.Data[6] | (uint8_T)
              ((uint16_T)(tempValue & (uint16_T)0xFFU));
            InverterStartupControl_B.AMK0_SetPoints1.Data[7] =
              InverterStartupControl_B.AMK0_SetPoints1.Data[7] | (uint8_T)
              ((uint16_T)((uint16_T)(tempValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = InverterStartupControl_B.AMK_TorqueLimitPositiv;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        int16_T packedValue;
        int32_T scaledValue;
        if (outValue > 2147483647.0) {
          scaledValue = 2147483647;
        } else if (outValue < -2147483648.0) {
          scaledValue = -2147483647 - 1;
        } else {
          scaledValue = (int32_T) outValue;
        }

        if (scaledValue > (int32_T) (32767)) {
          packedValue = 32767;
        } else if (scaledValue < (int32_T)((-(32767)-1))) {
          packedValue = (-(32767)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            InverterStartupControl_B.AMK0_SetPoints1.Data[4] =
              InverterStartupControl_B.AMK0_SetPoints1.Data[4] | (uint8_T)
              ((uint16_T)(tempValue & (uint16_T)0xFFU));
            InverterStartupControl_B.AMK0_SetPoints1.Data[5] =
              InverterStartupControl_B.AMK0_SetPoints1.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(tempValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 9
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (InverterStartupControl_B.AMK_bDcOn_tx);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(1)) {
          packedValue = (uint8_T) 1;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            InverterStartupControl_B.AMK0_SetPoints1.Data[1] =
              InverterStartupControl_B.AMK0_SetPoints1.Data[1] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 1));
          }
        }
      }
    }

    /* --------------- START Packing signal 4 ------------------
     *  startBit                = 10
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (InverterStartupControl_B.AMK_bEnable);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(1)) {
          packedValue = (uint8_T) 1;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            InverterStartupControl_B.AMK0_SetPoints1.Data[1] =
              InverterStartupControl_B.AMK0_SetPoints1.Data[1] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 2));
          }
        }
      }
    }

    /* --------------- START Packing signal 5 ------------------
     *  startBit                = 11
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (InverterStartupControl_B.AMK_bErrorReset);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(1)) {
          packedValue = (uint8_T) 1;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            InverterStartupControl_B.AMK0_SetPoints1.Data[1] =
              InverterStartupControl_B.AMK0_SetPoints1.Data[1] | (uint8_T)
              ((uint8_T)((uint8_T)(packedValue & (uint8_T)0x1U) << 3));
          }
        }
      }
    }

    /* --------------- START Packing signal 6 ------------------
     *  startBit                = 8
     *  length                  = 1
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T)
          (InverterStartupControl_B.AMK_bInverterOn_tx);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        if (packingValue > (uint8_T)(1)) {
          packedValue = (uint8_T) 1;
        } else {
          packedValue = (uint8_T) (packingValue);
        }

        {
          {
            InverterStartupControl_B.AMK0_SetPoints1.Data[1] =
              InverterStartupControl_B.AMK0_SetPoints1.Data[1] | (uint8_T)
              ((uint8_T)(packedValue & (uint8_T)0x1U));
          }
        }
      }
    }
  }

  /* SignalConversion generated from: '<Root>/CAN Transmit' */
  InverterStartupControl_B.TmpSignalConversionAtCANTransmi[0] =
    InverterStartupControl_B.AMK0_SetPoints1;
  InverterStartupControl_B.TmpSignalConversionAtCANTransmi[1] =
    CAN_DATATYPE_GROUND;

  /* S-Function (svntcantransmit): '<Root>/CAN Transmit' incorporates:
   *  SignalConversion generated from: '<Root>/CAN Transmit'
   */
  sErr = GetErrorBuffer(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U]);
  outputMsgRef = &InverterStartupControl_B.TmpSignalConversionAtCANTransmi[0U];
  LibOutputs_CANTransmit(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U],
    outputMsgRef, 2);
  if (*sErr != 0) {
    rtmSetErrorStatus(InverterStartupControl_M, sErr);
    rtmSetStopRequested(InverterStartupControl_M, 1);
  }

  /* End of S-Function (svntcantransmit): '<Root>/CAN Transmit' */
  /* RateTransition generated from: '<S5>/LEFT_MOTOR' */
  if (InverterStartupControl_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S5>/LEFT_MOTOR' */
    InverterStartupControl_B.TmpRTBAtLEFT_MOTORInport18 =
      InverterStartupControl_DW.TmpRTBAtLEFT_MOTORInport18_Buff;
  }

  /* End of RateTransition generated from: '<S5>/LEFT_MOTOR' */

  /* DataTypeConversion: '<S3>/Cast To Single4' incorporates:
   *  Constant: '<S3>/Constant6'
   */
  InverterStartupControl_B.CastToSingle4 = (real32_T)
    InverterStartupControl_P.Constant6_Value;

  /* DataTypeConversion: '<S3>/Cast To Single5' incorporates:
   *  Constant: '<S3>/Constant7'
   */
  InverterStartupControl_B.CastToSingle5 = (real32_T)
    InverterStartupControl_P.Constant7_Value;

  /* Chart: '<S5>/LEFT_MOTOR' */
  if (InverterStartupControl_DW.temporalCounter_i1_b < 255U) {
    InverterStartupControl_DW.temporalCounter_i1_b++;
  }

  InverterStartupControl_DW.sfEvent_l = InverterStartupContr_CALL_EVENT;
  if (InverterStartupControl_DW.is_active_c1_motor_interface_li == 0U) {
    InverterStartupControl_DW.is_active_c1_motor_interface_li = 1U;
    InverterStartupControl_DW.is_c1_motor_interface_lib =
      Inver_IN_motorOff_waitingForGov;
  } else {
    switch (InverterStartupControl_DW.is_c1_motor_interface_lib) {
     case InverterSt_IN_AMK_errorDetected:
      if (InverterStartupControl_B.GOV_e_miCmd == ERR_RESET) {
        InverterStartupControl_DW.is_c1_motor_interface_lib =
          InverterStart_IN_AMK_errorReset;
        InverterStartupControl_DW.is_AMK_errorReset_c =
          Inver_IN_enforceSetpointsZero_d;
      }
      break;

     case InverterStart_IN_AMK_errorReset:
      switch (InverterStartupControl_DW.is_AMK_errorReset_c) {
       case Inver_IN_enforceSetpointsZero_d:
        if (InverterStartupControl_B.AMK_bInverterOn_e == 0.0) {
          InverterStartupControl_DW.is_AMK_errorReset_c =
            InverterStartup_IN_toggleEnable;
          InverterStartupControl_DW.temporalCounter_i1_b = 0U;
        }
        break;

       case InverterStartupCon_IN_sendReset:
        if (InverterStartupControl_DW.temporalCounter_i1_b >= 100U) {
          InverterStartupControl_DW.is_AMK_errorReset_c =
            InverterStartupC_IN_toggleReset;
        }
        break;

       case InverterStartup_IN_toggleEnable:
        if (InverterStartupControl_DW.temporalCounter_i1_b >= 100U) {
          InverterStartupControl_DW.is_AMK_errorReset_c =
            InverterStartupCon_IN_sendReset;
          InverterStartupControl_DW.temporalCounter_i1_b = 0U;
        }
        break;

       default:
        /* case IN_toggleReset: */
        if (InverterStartupControl_B.AMK_bSystemReady_e == 1.0) {
          InverterStartupControl_DW.is_AMK_errorReset_c =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c1_motor_interface_lib =
            Inver_IN_motorOff_waitingForGov;
        }
        break;
      }
      break;

     case InverterStartupC_IN_AMK_running:
      if (InverterStartupControl_B.AMK_bError_h == 1.0) {
        InverterStartupControl_DW.is_c1_motor_interface_lib =
          InverterSt_IN_AMK_errorDetected;
      } else if (InverterStartupControl_B.GOV_e_miCmd == CMD_SHUTDOWN) {
        InverterStartupControl_DW.is_c1_motor_interface_lib =
          InverterStartup_IN_AMK_shutdown;
        InverterStartupControl_DW.is_AMK_shutdown_j =
          Inverte_IN_enforceSetpointsZero;
      }
      break;

     case InverterStartup_IN_AMK_shutdown:
      switch (InverterStartupControl_DW.is_AMK_shutdown_j) {
       case InverterStartupCo_IN_commandOff:
        if (InverterStartupControl_B.AMK_bQuitInverterOn_l == 0.0) {
          InverterStartupControl_DW.is_AMK_shutdown_j =
            InverterStartupCo_IN_toggleDCon;
        } else if (InverterStartupControl_B.AMK_bError_h == 1.0) {
          InverterStartupControl_DW.is_AMK_shutdown_j =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c1_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;

       case Inverte_IN_enforceSetpointsZero:
        if (InverterStartupControl_B.AMK_bInverterOn_e == 0.0) {
          InverterStartupControl_DW.is_AMK_shutdown_j =
            InverterStartupCo_IN_commandOff;
        } else if (InverterStartupControl_B.AMK_bError_h == 1.0) {
          InverterStartupControl_DW.is_AMK_shutdown_j =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c1_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;

       default:
        /* case IN_toggleDCon: */
        if ((InverterStartupControl_B.AMK_bDcOn_p == 0.0) &&
            (InverterStartupControl_B.AMK_bQuitDcOn_l == 0.0)) {
          InverterStartupControl_DW.is_AMK_shutdown_j =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c1_motor_interface_lib =
            Inver_IN_motorOff_waitingForGov;
        } else if (InverterStartupControl_B.AMK_bError_h == 1.0) {
          InverterStartupControl_DW.is_AMK_shutdown_j =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c1_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;
      }
      break;

     case InverterStartupC_IN_AMK_startup:
      switch (InverterStartupControl_DW.is_AMK_startup_o) {
       case InverterStartupCon_IN_commandOn:
        if ((InverterStartupControl_B.AMK_bInverterOn_e == 1.0) &&
            (InverterStartupControl_B.AMK_bQuitInverterOn_l == 1.0)) {
          InverterStartupControl_DW.is_AMK_startup_o =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c1_motor_interface_lib =
            InverterStartupC_IN_AMK_running;
        } else if (InverterStartupControl_B.AMK_bError_h == 1.0) {
          InverterStartupControl_DW.is_AMK_startup_o =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c1_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;

       case Inverte_IN_enforceSetpointsZero:
        if (InverterStartupControl_DW.temporalCounter_i1_b >= 200U) {
          InverterStartupControl_DW.is_AMK_startup_o =
            InverterStartupCon_IN_commandOn;
        } else if (InverterStartupControl_B.AMK_bError_h == 1.0) {
          InverterStartupControl_DW.is_AMK_startup_o =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c1_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;

       case InverterStartupCo_IN_toggleDCon:
        if ((InverterStartupControl_B.AMK_bDcOn_p == 1.0) &&
            (InverterStartupControl_B.AMK_bQuitDcOn_l == 1.0)) {
          InverterStartupControl_DW.is_AMK_startup_o =
            Inverte_IN_enforceSetpointsZero;
          InverterStartupControl_DW.temporalCounter_i1_b = 0U;
        } else if (InverterStartupControl_B.AMK_bError_h == 1.0) {
          InverterStartupControl_DW.is_AMK_startup_o =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c1_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;

       default:
        /* case IN_waiting_sysReady: */
        if (InverterStartupControl_B.AMK_bSystemReady_e == 1.0) {
          InverterStartupControl_DW.is_AMK_startup_o =
            InverterStartupCo_IN_toggleDCon;
        } else if (InverterStartupControl_B.AMK_bError_h == 1.0) {
          InverterStartupControl_DW.is_AMK_startup_o =
            InverterStar_IN_NO_ACTIVE_CHILD;
          InverterStartupControl_DW.is_c1_motor_interface_lib =
            InverterSt_IN_AMK_errorDetected;
        }
        break;
      }
      break;

     default:
      /* case IN_motorOff_waitingForGov: */
      if (InverterStartupControl_B.GOV_e_miCmd == CMD_STARTUP) {
        InverterStartupControl_DW.is_c1_motor_interface_lib =
          InverterStartupC_IN_AMK_startup;
        InverterStartupControl_DW.is_AMK_startup_o =
          InverterSta_IN_waiting_sysReady;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/LEFT_MOTOR' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++InverterStartupControl_M->Timing.clockTick0)) {
    ++InverterStartupControl_M->Timing.clockTickH0;
  }

  InverterStartupControl_M->Timing.taskTime0 =
    InverterStartupControl_M->Timing.clockTick0 *
    InverterStartupControl_M->Timing.stepSize0 +
    InverterStartupControl_M->Timing.clockTickH0 *
    InverterStartupControl_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void InverterStartupControl_step1(void) /* Sample time: [2.0s, 0.0s] */
{
  real_T rtb_PulseGenerator1;

  /* DiscretePulseGenerator: '<S3>/Pulse Generator1' */
  rtb_PulseGenerator1 = (InverterStartupControl_DW.clockTickCounter <
    InverterStartupControl_P.PulseGenerator1_Duty) &&
    (InverterStartupControl_DW.clockTickCounter >= 0) ?
    InverterStartupControl_P.PulseGenerator1_Amp : 0.0;
  if (InverterStartupControl_DW.clockTickCounter >=
      InverterStartupControl_P.PulseGenerator1_Period - 1.0) {
    InverterStartupControl_DW.clockTickCounter = 0;
  } else {
    InverterStartupControl_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S3>/Pulse Generator1' */

  /* ManualSwitch: '<S3>/Manual Switch1' */
  if (InverterStartupControl_P.ManualSwitch1_CurrentSetting == 1) {
    /* DataTypeConversion: '<S3>/Cast To Single3' incorporates:
     *  Constant: '<S3>/Constant5'
     */
    InverterStartupControl_B.CastToSingle3 = (real32_T)
      InverterStartupControl_P.Constant5_Value;
  } else {
    /* DataTypeConversion: '<S3>/Cast To Single3' incorporates:
     *  Constant: '<S3>/Constant9'
     *  Sum: '<S3>/Subtract1'
     */
    InverterStartupControl_B.CastToSingle3 = (real32_T)(rtb_PulseGenerator1 -
      InverterStartupControl_P.Constant9_Value);
  }

  /* End of ManualSwitch: '<S3>/Manual Switch1' */

  /* RateTransition generated from: '<S5>/LEFT_MOTOR' */
  InverterStartupControl_DW.TmpRTBAtLEFT_MOTORInport18_Buff =
    InverterStartupControl_B.CastToSingle3;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 2.0, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  InverterStartupControl_M->Timing.clockTick1++;
  if (!InverterStartupControl_M->Timing.clockTick1) {
    InverterStartupControl_M->Timing.clockTickH1++;
  }
}

/* Model initialize function */
void InverterStartupControl_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)InverterStartupControl_M, 0,
                sizeof(RT_MODEL_InverterStartupContr_T));
  rtmSetTFinal(InverterStartupControl_M, -1);
  InverterStartupControl_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  InverterStartupControl_M->Sizes.checksums[0] = (2570512009U);
  InverterStartupControl_M->Sizes.checksums[1] = (2728239203U);
  InverterStartupControl_M->Sizes.checksums[2] = (2013117591U);
  InverterStartupControl_M->Sizes.checksums[3] = (4250560257U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    InverterStartupControl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &InverterStartupControl_DW.AMK_Input_SubsysRanBC;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(InverterStartupControl_M->extModeInfo,
      &InverterStartupControl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(InverterStartupControl_M->extModeInfo,
                        InverterStartupControl_M->Sizes.checksums);
    rteiSetTPtr(InverterStartupControl_M->extModeInfo, rtmGetTPtr
                (InverterStartupControl_M));
  }

  /* block I/O */
  (void) memset(((void *) &InverterStartupControl_B), 0,
                sizeof(B_InverterStartupControl_T));

  {
    InverterStartupControl_B.CANReceive_o2 = CAN_DATATYPE_GROUND;
    InverterStartupControl_B.AMK0_SetPoints1 = CAN_DATATYPE_GROUND;
    InverterStartupControl_B.TmpSignalConversionAtCANTransmi[0] =
      CAN_DATATYPE_GROUND;
    InverterStartupControl_B.TmpSignalConversionAtCANTransmi[1] =
      CAN_DATATYPE_GROUND;
    InverterStartupControl_B.GOV_e_miCmd = CMD_INIT;
  }

  /* states (dwork) */
  (void) memset((void *)&InverterStartupControl_DW, 0,
                sizeof(DW_InverterStartupControl_T));

  {
    MW_AnalogIn_TriggerSource_Type trigger_val;
    uint32_T pinname;
    mbed_AnalogInput_InverterStar_T *obj;
    real_T stdIDsEnd;
    real_T stdIDsStart;
    uint32_T extIDs;
    uint32_T stdIDs;
    char_T *sErr;

    /* Start for S-Function (svntcanreceive): '<Root>/CAN Receive' incorporates:
     *  SubSystem: '<Root>/AMK_Input'
     */
    /* Start for S-Function (scanunpack): '<S1>/CAN Unpack' */

    /*-----------S-Function Block: <S1>/CAN Unpack -----------------*/

    /* Start for S-Function (scanunpack): '<S1>/CAN Unpack1' */

    /*-----------S-Function Block: <S1>/CAN Unpack1 -----------------*/

    /* Start for S-Function (scanunpack): '<S1>/CAN Unpack2' */

    /*-----------S-Function Block: <S1>/CAN Unpack2 -----------------*/

    /* Start for S-Function (scanunpack): '<S1>/CAN Unpack3' */

    /*-----------S-Function Block: <S1>/CAN Unpack3 -----------------*/
    sErr = GetErrorBuffer(&InverterStartupControl_DW.CANReceive_CANReceive[0U]);
    CreateHostLibrary("slhostlibcanreceive.dll",
                      &InverterStartupControl_DW.CANReceive_CANReceive[0U]);
    if (*sErr == 0) {
      InverterStartupControl_B.bitParams[0U] = 1;
      InverterStartupControl_B.bitParams[1U] = 4;
      InverterStartupControl_B.bitParams[2U] = 3;
      InverterStartupControl_B.bitParams[3U] = 1;
      stdIDs = MAX_uint32_T;
      extIDs = MAX_uint32_T;
      stdIDsStart = 0.0;
      stdIDsEnd = 0.0;
      InverterStartupControl_B.idMaskParams[0U] = 0;
      InverterStartupControl_B.idMaskParams[1U] = 2047;
      InverterStartupControl_B.idMaskParams[2U] = 0;
      InverterStartupControl_B.idMaskParams[3U] = 536870911;
      LibCreate_CANReceive(&InverterStartupControl_DW.CANReceive_CANReceive[0U],
                           "kvaser", "slkvaserwrapper.dll",
                           "Kvaser USBcan Light 2xHS", 19428, 72, 1, 1,
                           "canslconverter", "kvasercanlibplugin", 500000.0,
                           &InverterStartupControl_B.bitParams[0U], 0, 0,
                           &stdIDs, 1, 0, &extIDs, 1, &stdIDsStart, &stdIDsEnd,
                           1, &InverterStartupControl_B.idMaskParams[0U], 0);
    }

    if (*sErr == 0) {
      LibStart(&InverterStartupControl_DW.CANReceive_CANReceive[0U]);
    }

    if (*sErr != 0) {
      rtmSetErrorStatus(InverterStartupControl_M, sErr);
      rtmSetStopRequested(InverterStartupControl_M, 1);
    }

    /* End of Start for S-Function (svntcanreceive): '<Root>/CAN Receive' */

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    InverterStartupControl_DW.obj.matlabCodegenIsDeleted = false;
    InverterStartupControl_DW.objisempty = true;
    InverterStartupControl_DW.obj.SampleTime =
      InverterStartupControl_P.AnalogInput_SampleTime;
    obj = &InverterStartupControl_DW.obj;
    InverterStartupControl_DW.obj.isInitialized = 1;
    pinname = A0;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(pinname);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource
      (InverterStartupControl_DW.obj.MW_ANALOGIN_HANDLE, trigger_val, 0U);
    InverterStartupControl_DW.obj.isSetupComplete = true;

    /* Start for S-Function (svntcantransmit): '<Root>/CAN Transmit' */
    sErr = GetErrorBuffer(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U]);
    CreateHostLibrary("slhostlibcantransmit.dll",
                      &InverterStartupControl_DW.CANTransmit_CANTransmit[0U]);
    if (*sErr == 0) {
      InverterStartupControl_B.bitParams_m[0U] = 1;
      InverterStartupControl_B.bitParams_m[1U] = 4;
      InverterStartupControl_B.bitParams_m[2U] = 3;
      InverterStartupControl_B.bitParams_m[3U] = 1;
      LibCreate_CANTransmit(&InverterStartupControl_DW.CANTransmit_CANTransmit
                            [0U], "kvaser", "slkvaserwrapper.dll",
                            "Kvaser USBcan Light 2xHS", 19428, 72, 1, 1,
                            "canslconverter", "kvasercanlibplugin", 500000.0,
                            &InverterStartupControl_B.bitParams_m[0U], 0, 1, 0,
                            0.01, 0);
    }

    if (*sErr == 0) {
      LibStart(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U]);
    }

    if (*sErr != 0) {
      rtmSetErrorStatus(InverterStartupControl_M, sErr);
      rtmSetStopRequested(InverterStartupControl_M, 1);
    }

    /* End of Start for S-Function (svntcantransmit): '<Root>/CAN Transmit' */
    /* Start for RateTransition generated from: '<S5>/LEFT_MOTOR' */
    InverterStartupControl_B.TmpRTBAtLEFT_MOTORInport18 =
      InverterStartupControl_P.TmpRTBAtLEFT_MOTORInport18_Init;

    /* Start for DiscretePulseGenerator: '<S3>/Pulse Generator1' */
    InverterStartupControl_DW.clockTickCounter = 0;
  }

  /* InitializeConditions for RateTransition generated from: '<S5>/LEFT_MOTOR' */
  InverterStartupControl_DW.TmpRTBAtLEFT_MOTORInport18_Buff =
    InverterStartupControl_P.TmpRTBAtLEFT_MOTORInport18_Init;

  /* SystemInitialize for S-Function (svntcanreceive): '<Root>/CAN Receive' incorporates:
   *  SubSystem: '<Root>/AMK_Input'
   */
  /* SystemInitialize for SignalConversion generated from: '<S1>/Constant' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bReserve_e =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_bReserve;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_ActualVelocity =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_ActualVelocity;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_MagnetizingCurrent =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_MagnetizingCurrent;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_TorqueCurrent =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_TorqueCurrent;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bDcOn =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_bDcOn;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bDerating =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_bDerating;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bError =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_bError;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bInverterOn =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_bInverterOn;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bQuitDcOn =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_bQuitDcOn;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bQuitInverterOn =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_bQuitInverterOn;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bSystemReady =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_bSystemReady;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bWarn =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Right.AMK_bWarn;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack1' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_ErrorInfo =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues2_Right.AMK_ErrorInfo;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack1' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_TempIGBT =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues2_Right.AMK_TempIGBT;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack1' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_TempInverter =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues2_Right.AMK_TempInverter;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack1' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_TempMotor =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues2_Right.AMK_TempMotor;

  /* SystemInitialize for SignalConversion generated from: '<S1>/Constant1' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bReserve_ew =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_bReserve;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_ActualVelocity_i =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_ActualVelocity;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_MagnetizingCurrent_o =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_MagnetizingCurrent;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_TorqueCurrent_g =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_TorqueCurrent;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bDcOn_p =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_bDcOn;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bDerating_m =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_bDerating;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bError_h =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_bError;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bInverterOn_e =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_bInverterOn;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bQuitDcOn_l =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_bQuitDcOn;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bQuitInverterOn_l =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_bQuitInverterOn;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bSystemReady_e =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_bSystemReady;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack2' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_bWarn_a =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues1_Left.AMK_bWarn;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack3' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_ErrorInfo_g =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues2_Left.AMK_ErrorInfo;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack3' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_TempIGBT_i =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues2_Left.AMK_TempIGBT;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack3' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_TempInverter_i =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues2_Left.AMK_TempInverter;

  /* SystemInitialize for S-Function (scanunpack): '<S1>/CAN Unpack3' incorporates:
   *  Outport: '<S1>/Input'
   */
  InverterStartupControl_B.AMK_TempMotor_g =
    InverterStartupControl_P.Input_Y0.ptCAN_AMK_ActualValues2_Left.AMK_TempMotor;

  /* End of SystemInitialize for S-Function (svntcanreceive): '<Root>/CAN Receive' */

  /* SystemInitialize for Chart: '<S3>/Chart' */
  InverterStartupControl_DW.sfEvent_k = InverterStartupContr_CALL_EVENT;
  InverterStartupControl_DW.is_active_c1_InverterStartupCon = 0U;
  InverterStartupControl_DW.is_c1_InverterStartupControl =
    InverterStar_IN_NO_ACTIVE_CHILD;
  InverterStartupControl_B.GOV_e_miCmd = CMD_INIT;

  /* SystemInitialize for Chart: '<S5>/LEFT_MOTOR' incorporates:
   *  Chart: '<S3>/Chart'
   */
  InverterStartupControl_DW.sfEvent_l = InverterStartupContr_CALL_EVENT;
  InverterStartupControl_DW.is_AMK_errorReset_c =
    InverterStar_IN_NO_ACTIVE_CHILD;
  InverterStartupControl_DW.is_AMK_shutdown_j = InverterStar_IN_NO_ACTIVE_CHILD;
  InverterStartupControl_DW.is_AMK_startup_o = InverterStar_IN_NO_ACTIVE_CHILD;
  InverterStartupControl_DW.temporalCounter_i1_b = 0U;
  InverterStartupControl_DW.is_active_c1_motor_interface_li = 0U;
  InverterStartupControl_DW.is_c1_motor_interface_lib =
    InverterStar_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S5>/RIGHT_MOTOR' incorporates:
   *  Chart: '<S3>/Chart'
   */
  InverterStartupControl_DW.sfEvent = InverterStartupContr_CALL_EVENT;
  InverterStartupControl_DW.is_AMK_errorReset = InverterStar_IN_NO_ACTIVE_CHILD;
  InverterStartupControl_DW.is_AMK_shutdown = InverterStar_IN_NO_ACTIVE_CHILD;
  InverterStartupControl_DW.is_AMK_startup = InverterStar_IN_NO_ACTIVE_CHILD;
  InverterStartupControl_DW.temporalCounter_i1 = 0U;
  InverterStartupControl_DW.is_active_c3_motor_interface_li = 0U;
  InverterStartupControl_DW.is_c3_motor_interface_lib =
    InverterStar_IN_NO_ACTIVE_CHILD;
  InverterStartupControl_B.AMK_bInverterOn_tx = 0U;
  InverterStartupControl_B.AMK_bDcOn_tx = 0U;
  InverterStartupControl_B.AMK_bEnable = 0U;
  InverterStartupControl_B.AMK_bErrorReset = 0U;
  InverterStartupControl_B.AMK_TargetVelocity = 0.0F;
  InverterStartupControl_B.AMK_TorqueLimitPositiv = 0.0F;
  InverterStartupControl_B.AMK_TorqueLimitNegativ = 0.0F;

  {
    char_T *sErr;

    /* Enable for S-Function (svntcantransmit): '<Root>/CAN Transmit' */
    sErr = GetErrorBuffer(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U]);
    LibReset(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U]);
    LibStart(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U]);
    if (*sErr != 0) {
      rtmSetErrorStatus(InverterStartupControl_M, sErr);
      rtmSetStopRequested(InverterStartupControl_M, 1);
    }

    InverterStartupControl_DW.CANTransmit_BlockDisabled = false;

    /* End of Enable for S-Function (svntcantransmit): '<Root>/CAN Transmit' */
  }
}

/* Model terminate function */
void InverterStartupControl_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (svntcanreceive): '<Root>/CAN Receive' */
  sErr = GetErrorBuffer(&InverterStartupControl_DW.CANReceive_CANReceive[0U]);
  LibTerminate(&InverterStartupControl_DW.CANReceive_CANReceive[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(InverterStartupControl_M, sErr);
    rtmSetStopRequested(InverterStartupControl_M, 1);
  }

  LibDestroy(&InverterStartupControl_DW.CANReceive_CANReceive[0U], 0);
  DestroyHostLibrary(&InverterStartupControl_DW.CANReceive_CANReceive[0U]);

  /* End of Terminate for S-Function (svntcanreceive): '<Root>/CAN Receive' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!InverterStartupControl_DW.obj.matlabCodegenIsDeleted) {
    InverterStartupControl_DW.obj.matlabCodegenIsDeleted = true;
    if ((InverterStartupControl_DW.obj.isInitialized == 1) &&
        InverterStartupControl_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(InverterStartupControl_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(InverterStartupControl_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for S-Function (svntcantransmit): '<Root>/CAN Transmit' */
  sErr = GetErrorBuffer(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U]);
  LibTerminate(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(InverterStartupControl_M, sErr);
    rtmSetStopRequested(InverterStartupControl_M, 1);
  }

  LibDestroy(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U], 0);
  DestroyHostLibrary(&InverterStartupControl_DW.CANTransmit_CANTransmit[0U]);

  /* End of Terminate for S-Function (svntcantransmit): '<Root>/CAN Transmit' */
}
