#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#define MW_MULTI_TASKING_MODE 1
#include "stm32f7xx.h"
#include "MW_MbedPinInterface.h"
#include "stm32f7xx_init_board.h"
#include "SysTickScheduler.h"
#include "arm_cortex_m_multitasking.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE STM32 Nucleo F767ZI
#define MW_CONNECTIONINFO_SERIAL_BAUDRATE 115200
#define MW_CONNECTIONINFO_SERIAL_COMPORT COM5
#define MW_CONNECTIONINFO_SERIAL_VERBOSE 1
#define MW_EXTMODE_CONFIGURATION serial
#define MW_EXTMODE_SIGNALBUFFERSIZE 2000.000000
#define MW_EXTMODE_USEREALTIMESTAMPLOGGING 1
#define MW_EXTMODE_RUNNING on
#define MW_RTOS Baremetal
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 1
#define MW_HOSTDRIVE_SET_HOST_DRIVE 0
#define MW_HOSTDRIVE_DRIVE F:
#define MW_HOSTCOMPORT_COM_PORT_NUMBER COM5
#define MW_SIMULINKIO_TRANSPORTLAYERTYPE 0
#define MW_SIMULINKIO_MODELTRANSPORTDATAFCN codertarget.simulinkIO.stmnucleo.getModelTransportInfo
#define MW_SIMULINKIO_SERVERDEPLOYFCN codertarget.simulinkIO.stmnucleo.updateServer
#define MW_CLOCKING_CPUCLOCKRATEMHZ 216
#define MW_ETHERNET_DHCPENABLED 1
#define MW_ETHERNET_HOSTNAME DIS_F746NG
#define MW_ETHERNET_LOCALIPADDRESS 192.168.1.10
#define MW_ETHERNET_SUBNETMASK 255.255.255.0
#define MW_ETHERNET_GATEWAY 192.168.1.1
#define MW_ETHERNET_MACADDR 00-80-E1-00-00-00
#define MW_CAN1_APB1CLOCK 54.000000
#define MW_CAN1_PRESCALER 6
#define MW_CAN1_TIMEQUANTUM 111.111111
#define MW_CAN1_BS1 13
#define MW_CAN1_BS2 2
#define MW_CAN1_BAUDRATE 500000.000000
#define MW_CAN1_SJW 0
#define MW_CAN1_RXPIN 0
#define MW_CAN1_TXPIN 0
#define MW_CAN1_OPTEST 0
#define MW_CAN1_ACCEPTALLMESSAGES 1
#define MW_CAN1_FILTERBANKNUMBER 0
#define MW_CAN1_ENABLEFILTERBANK00 0
#define MW_CAN1_SCALE00 0
#define MW_CAN1_MODE00 0
#define MW_CAN1_FIFOASSIGNMENT00 0
#define MW_CAN1_IDTYPE00 0
#define MW_CAN1_ID1_00 0
#define MW_CAN1_MASK1_00 0
#define MW_CAN1_ID2_00 0
#define MW_CAN1_MASK2_00 0
#define MW_CAN1_ID3_00 0
#define MW_CAN1_ID4_00 0
#define MW_CAN1_ENABLEFILTERBANK01 0
#define MW_CAN1_SCALE01 0
#define MW_CAN1_MODE01 0
#define MW_CAN1_FIFOASSIGNMENT01 0
#define MW_CAN1_IDTYPE01 0
#define MW_CAN1_ID1_01 0
#define MW_CAN1_MASK1_01 0
#define MW_CAN1_ID2_01 0
#define MW_CAN1_MASK2_01 0
#define MW_CAN1_ID3_01 0
#define MW_CAN1_ID4_01 0
#define MW_CAN1_ENABLEFILTERBANK02 0
#define MW_CAN1_SCALE02 0
#define MW_CAN1_MODE02 0
#define MW_CAN1_FIFOASSIGNMENT02 0
#define MW_CAN1_IDTYPE02 0
#define MW_CAN1_ID1_02 0
#define MW_CAN1_MASK1_02 0
#define MW_CAN1_ID2_02 0
#define MW_CAN1_MASK2_02 0
#define MW_CAN1_ID3_02 0
#define MW_CAN1_ID4_02 0
#define MW_CAN1_ENABLEFILTERBANK03 0
#define MW_CAN1_SCALE03 0
#define MW_CAN1_MODE03 0
#define MW_CAN1_FIFOASSIGNMENT03 0
#define MW_CAN1_IDTYPE03 0
#define MW_CAN1_ID1_03 0
#define MW_CAN1_MASK1_03 0
#define MW_CAN1_ID2_03 0
#define MW_CAN1_MASK2_03 0
#define MW_CAN1_ID3_03 0
#define MW_CAN1_ID4_03 0
#define MW_CAN1_ENABLEFILTERBANK04 0
#define MW_CAN1_SCALE04 0
#define MW_CAN1_MODE04 0
#define MW_CAN1_FIFOASSIGNMENT04 0
#define MW_CAN1_IDTYPE04 0
#define MW_CAN1_ID1_04 0
#define MW_CAN1_MASK1_04 0
#define MW_CAN1_ID2_04 0
#define MW_CAN1_MASK2_04 0
#define MW_CAN1_ID3_04 0
#define MW_CAN1_ID4_04 0
#define MW_CAN1_ENABLEFILTERBANK05 0
#define MW_CAN1_SCALE05 0
#define MW_CAN1_MODE05 0
#define MW_CAN1_FIFOASSIGNMENT05 0
#define MW_CAN1_IDTYPE05 0
#define MW_CAN1_ID1_05 0
#define MW_CAN1_MASK1_05 0
#define MW_CAN1_ID2_05 0
#define MW_CAN1_MASK2_05 0
#define MW_CAN1_ID3_05 0
#define MW_CAN1_ID4_05 0
#define MW_CAN1_ENABLEFILTERBANK06 0
#define MW_CAN1_SCALE06 0
#define MW_CAN1_MODE06 0
#define MW_CAN1_FIFOASSIGNMENT06 0
#define MW_CAN1_IDTYPE06 0
#define MW_CAN1_ID1_06 0
#define MW_CAN1_MASK1_06 0
#define MW_CAN1_ID2_06 0
#define MW_CAN1_MASK2_06 0
#define MW_CAN1_ID3_06 0
#define MW_CAN1_ID4_06 0
#define MW_CAN1_ENABLEFILTERBANK07 0
#define MW_CAN1_SCALE07 0
#define MW_CAN1_MODE07 0
#define MW_CAN1_FIFOASSIGNMENT07 0
#define MW_CAN1_IDTYPE07 0
#define MW_CAN1_ID1_07 0
#define MW_CAN1_MASK1_07 0
#define MW_CAN1_ID2_07 0
#define MW_CAN1_MASK2_07 0
#define MW_CAN1_ID3_07 0
#define MW_CAN1_ID4_07 0
#define MW_CAN1_ENABLEFILTERBANK08 0
#define MW_CAN1_SCALE08 0
#define MW_CAN1_MODE08 0
#define MW_CAN1_FIFOASSIGNMENT08 0
#define MW_CAN1_IDTYPE08 0
#define MW_CAN1_ID1_08 0
#define MW_CAN1_MASK1_08 0
#define MW_CAN1_ID2_08 0
#define MW_CAN1_MASK2_08 0
#define MW_CAN1_ID3_08 0
#define MW_CAN1_ID4_08 0
#define MW_CAN1_ENABLEFILTERBANK09 0
#define MW_CAN1_SCALE09 0
#define MW_CAN1_MODE09 0
#define MW_CAN1_FIFOASSIGNMENT09 0
#define MW_CAN1_IDTYPE09 0
#define MW_CAN1_ID1_09 0
#define MW_CAN1_MASK1_09 0
#define MW_CAN1_ID2_09 0
#define MW_CAN1_MASK2_09 0
#define MW_CAN1_ID3_09 0
#define MW_CAN1_ID4_09 0
#define MW_CAN1_ENABLEFILTERBANK10 0
#define MW_CAN1_SCALE10 0
#define MW_CAN1_MODE10 0
#define MW_CAN1_FIFOASSIGNMENT10 0
#define MW_CAN1_IDTYPE10 0
#define MW_CAN1_ID1_10 0
#define MW_CAN1_MASK1_10 0
#define MW_CAN1_ID2_10 0
#define MW_CAN1_MASK2_10 0
#define MW_CAN1_ID3_10 0
#define MW_CAN1_ID4_10 0
#define MW_CAN1_ENABLEFILTERBANK11 0
#define MW_CAN1_SCALE11 0
#define MW_CAN1_MODE11 0
#define MW_CAN1_FIFOASSIGNMENT11 0
#define MW_CAN1_IDTYPE11 0
#define MW_CAN1_ID1_11 0
#define MW_CAN1_MASK1_11 0
#define MW_CAN1_ID2_11 0
#define MW_CAN1_MASK2_11 0
#define MW_CAN1_ID3_11 0
#define MW_CAN1_ID4_11 0
#define MW_CAN1_ENABLEFILTERBANK12 0
#define MW_CAN1_SCALE12 0
#define MW_CAN1_MODE12 0
#define MW_CAN1_FIFOASSIGNMENT12 0
#define MW_CAN1_IDTYPE12 0
#define MW_CAN1_ID1_12 0
#define MW_CAN1_MASK1_12 0
#define MW_CAN1_ID2_12 0
#define MW_CAN1_MASK2_12 0
#define MW_CAN1_ID3_12 0
#define MW_CAN1_ID4_12 0
#define MW_CAN1_ENABLEFILTERBANK13 0
#define MW_CAN1_SCALE13 0
#define MW_CAN1_MODE13 0
#define MW_CAN1_FIFOASSIGNMENT13 0
#define MW_CAN1_IDTYPE13 0
#define MW_CAN1_ID1_13 0
#define MW_CAN1_MASK1_13 0
#define MW_CAN1_ID2_13 0
#define MW_CAN1_MASK2_13 0
#define MW_CAN1_ID3_13 0
#define MW_CAN1_ID4_13 0
#define MW_CAN2_APB1CLOCK 54.000000
#define MW_CAN2_PRESCALER 6
#define MW_CAN2_TIMEQUANTUM 111.111111
#define MW_CAN2_BS1 5
#define MW_CAN2_BS2 2
#define MW_CAN2_BAUDRATE 900000.000000
#define MW_CAN2_SJW 0
#define MW_CAN2_RXPIN 0
#define MW_CAN2_TXPIN 0
#define MW_CAN2_OPTEST 0
#define MW_CAN2_ACCEPTALLMESSAGES 1
#define MW_CAN2_FILTERBANKNUMBER 0
#define MW_CAN2_ENABLEFILTERBANK00 0
#define MW_CAN2_SCALE00 0
#define MW_CAN2_MODE00 0
#define MW_CAN2_FIFOASSIGNMENT00 0
#define MW_CAN2_IDTYPE00 0
#define MW_CAN2_ID1_00 0
#define MW_CAN2_MASK1_00 0
#define MW_CAN2_ID2_00 0
#define MW_CAN2_MASK2_00 0
#define MW_CAN2_ID3_00 0
#define MW_CAN2_ID4_00 0
#define MW_CAN2_ENABLEFILTERBANK01 0
#define MW_CAN2_SCALE01 0
#define MW_CAN2_MODE01 0
#define MW_CAN2_FIFOASSIGNMENT01 0
#define MW_CAN2_IDTYPE01 0
#define MW_CAN2_ID1_01 0
#define MW_CAN2_MASK1_01 0
#define MW_CAN2_ID2_01 0
#define MW_CAN2_MASK2_01 0
#define MW_CAN2_ID3_01 0
#define MW_CAN2_ID4_01 0
#define MW_CAN2_ENABLEFILTERBANK02 0
#define MW_CAN2_SCALE02 0
#define MW_CAN2_MODE02 0
#define MW_CAN2_FIFOASSIGNMENT02 0
#define MW_CAN2_IDTYPE02 0
#define MW_CAN2_ID1_02 0
#define MW_CAN2_MASK1_02 0
#define MW_CAN2_ID2_02 0
#define MW_CAN2_MASK2_02 0
#define MW_CAN2_ID3_02 0
#define MW_CAN2_ID4_02 0
#define MW_CAN2_ENABLEFILTERBANK03 0
#define MW_CAN2_SCALE03 0
#define MW_CAN2_MODE03 0
#define MW_CAN2_FIFOASSIGNMENT03 0
#define MW_CAN2_IDTYPE03 0
#define MW_CAN2_ID1_03 0
#define MW_CAN2_MASK1_03 0
#define MW_CAN2_ID2_03 0
#define MW_CAN2_MASK2_03 0
#define MW_CAN2_ID3_03 0
#define MW_CAN2_ID4_03 0
#define MW_CAN2_ENABLEFILTERBANK04 0
#define MW_CAN2_SCALE04 0
#define MW_CAN2_MODE04 0
#define MW_CAN2_FIFOASSIGNMENT04 0
#define MW_CAN2_IDTYPE04 0
#define MW_CAN2_ID1_04 0
#define MW_CAN2_MASK1_04 0
#define MW_CAN2_ID2_04 0
#define MW_CAN2_MASK2_04 0
#define MW_CAN2_ID3_04 0
#define MW_CAN2_ID4_04 0
#define MW_CAN2_ENABLEFILTERBANK05 0
#define MW_CAN2_SCALE05 0
#define MW_CAN2_MODE05 0
#define MW_CAN2_FIFOASSIGNMENT05 0
#define MW_CAN2_IDTYPE05 0
#define MW_CAN2_ID1_05 0
#define MW_CAN2_MASK1_05 0
#define MW_CAN2_ID2_05 0
#define MW_CAN2_MASK2_05 0
#define MW_CAN2_ID3_05 0
#define MW_CAN2_ID4_05 0
#define MW_CAN2_ENABLEFILTERBANK06 0
#define MW_CAN2_SCALE06 0
#define MW_CAN2_MODE06 0
#define MW_CAN2_FIFOASSIGNMENT06 0
#define MW_CAN2_IDTYPE06 0
#define MW_CAN2_ID1_06 0
#define MW_CAN2_MASK1_06 0
#define MW_CAN2_ID2_06 0
#define MW_CAN2_MASK2_06 0
#define MW_CAN2_ID3_06 0
#define MW_CAN2_ID4_06 0
#define MW_CAN2_ENABLEFILTERBANK07 0
#define MW_CAN2_SCALE07 0
#define MW_CAN2_MODE07 0
#define MW_CAN2_FIFOASSIGNMENT07 0
#define MW_CAN2_IDTYPE07 0
#define MW_CAN2_ID1_07 0
#define MW_CAN2_MASK1_07 0
#define MW_CAN2_ID2_07 0
#define MW_CAN2_MASK2_07 0
#define MW_CAN2_ID3_07 0
#define MW_CAN2_ID4_07 0
#define MW_CAN2_ENABLEFILTERBANK08 0
#define MW_CAN2_SCALE08 0
#define MW_CAN2_MODE08 0
#define MW_CAN2_FIFOASSIGNMENT08 0
#define MW_CAN2_IDTYPE08 0
#define MW_CAN2_ID1_08 0
#define MW_CAN2_MASK1_08 0
#define MW_CAN2_ID2_08 0
#define MW_CAN2_MASK2_08 0
#define MW_CAN2_ID3_08 0
#define MW_CAN2_ID4_08 0
#define MW_CAN2_ENABLEFILTERBANK09 0
#define MW_CAN2_SCALE09 0
#define MW_CAN2_MODE09 0
#define MW_CAN2_FIFOASSIGNMENT09 0
#define MW_CAN2_IDTYPE09 0
#define MW_CAN2_ID1_09 0
#define MW_CAN2_MASK1_09 0
#define MW_CAN2_ID2_09 0
#define MW_CAN2_MASK2_09 0
#define MW_CAN2_ID3_09 0
#define MW_CAN2_ID4_09 0
#define MW_CAN2_ENABLEFILTERBANK10 0
#define MW_CAN2_SCALE10 0
#define MW_CAN2_MODE10 0
#define MW_CAN2_FIFOASSIGNMENT10 0
#define MW_CAN2_IDTYPE10 0
#define MW_CAN2_ID1_10 0
#define MW_CAN2_MASK1_10 0
#define MW_CAN2_ID2_10 0
#define MW_CAN2_MASK2_10 0
#define MW_CAN2_ID3_10 0
#define MW_CAN2_ID4_10 0
#define MW_CAN2_ENABLEFILTERBANK11 0
#define MW_CAN2_SCALE11 0
#define MW_CAN2_MODE11 0
#define MW_CAN2_FIFOASSIGNMENT11 0
#define MW_CAN2_IDTYPE11 0
#define MW_CAN2_ID1_11 0
#define MW_CAN2_MASK1_11 0
#define MW_CAN2_ID2_11 0
#define MW_CAN2_MASK2_11 0
#define MW_CAN2_ID3_11 0
#define MW_CAN2_ID4_11 0
#define MW_CAN2_ENABLEFILTERBANK12 0
#define MW_CAN2_SCALE12 0
#define MW_CAN2_MODE12 0
#define MW_CAN2_FIFOASSIGNMENT12 0
#define MW_CAN2_IDTYPE12 0
#define MW_CAN2_ID1_12 0
#define MW_CAN2_MASK1_12 0
#define MW_CAN2_ID2_12 0
#define MW_CAN2_MASK2_12 0
#define MW_CAN2_ID3_12 0
#define MW_CAN2_ID4_12 0
#define MW_CAN2_ENABLEFILTERBANK13 0
#define MW_CAN2_SCALE13 0
#define MW_CAN2_MODE13 0
#define MW_CAN2_FIFOASSIGNMENT13 0
#define MW_CAN2_IDTYPE13 0
#define MW_CAN2_ID1_13 0
#define MW_CAN2_MASK1_13 0
#define MW_CAN2_ID2_13 0
#define MW_CAN2_MASK2_13 0
#define MW_CAN2_ID3_13 0
#define MW_CAN2_ID4_13 0
#define MW_CAN3_APB1CLOCK 54.000000
#define MW_CAN3_PRESCALER 6
#define MW_CAN3_TIMEQUANTUM 111.111111
#define MW_CAN3_BS1 5
#define MW_CAN3_BS2 2
#define MW_CAN3_BAUDRATE 900000.000000
#define MW_CAN3_SJW 0
#define MW_CAN3_RXPIN 0
#define MW_CAN3_TXPIN 0
#define MW_CAN3_OPTEST 0
#define MW_CAN3_ACCEPTALLMESSAGES 1
#define MW_CAN3_FILTERBANKNUMBER 0
#define MW_CAN3_ENABLEFILTERBANK00 0
#define MW_CAN3_SCALE00 0
#define MW_CAN3_MODE00 0
#define MW_CAN3_FIFOASSIGNMENT00 0
#define MW_CAN3_IDTYPE00 0
#define MW_CAN3_ID1_00 0
#define MW_CAN3_MASK1_00 0
#define MW_CAN3_ID2_00 0
#define MW_CAN3_MASK2_00 0
#define MW_CAN3_ID3_00 0
#define MW_CAN3_ID4_00 0
#define MW_CAN3_ENABLEFILTERBANK01 0
#define MW_CAN3_SCALE01 0
#define MW_CAN3_MODE01 0
#define MW_CAN3_FIFOASSIGNMENT01 0
#define MW_CAN3_IDTYPE01 0
#define MW_CAN3_ID1_01 0
#define MW_CAN3_MASK1_01 0
#define MW_CAN3_ID2_01 0
#define MW_CAN3_MASK2_01 0
#define MW_CAN3_ID3_01 0
#define MW_CAN3_ID4_01 0
#define MW_CAN3_ENABLEFILTERBANK02 0
#define MW_CAN3_SCALE02 0
#define MW_CAN3_MODE02 0
#define MW_CAN3_FIFOASSIGNMENT02 0
#define MW_CAN3_IDTYPE02 0
#define MW_CAN3_ID1_02 0
#define MW_CAN3_MASK1_02 0
#define MW_CAN3_ID2_02 0
#define MW_CAN3_MASK2_02 0
#define MW_CAN3_ID3_02 0
#define MW_CAN3_ID4_02 0
#define MW_CAN3_ENABLEFILTERBANK03 0
#define MW_CAN3_SCALE03 0
#define MW_CAN3_MODE03 0
#define MW_CAN3_FIFOASSIGNMENT03 0
#define MW_CAN3_IDTYPE03 0
#define MW_CAN3_ID1_03 0
#define MW_CAN3_MASK1_03 0
#define MW_CAN3_ID2_03 0
#define MW_CAN3_MASK2_03 0
#define MW_CAN3_ID3_03 0
#define MW_CAN3_ID4_03 0
#define MW_CAN3_ENABLEFILTERBANK04 0
#define MW_CAN3_SCALE04 0
#define MW_CAN3_MODE04 0
#define MW_CAN3_FIFOASSIGNMENT04 0
#define MW_CAN3_IDTYPE04 0
#define MW_CAN3_ID1_04 0
#define MW_CAN3_MASK1_04 0
#define MW_CAN3_ID2_04 0
#define MW_CAN3_MASK2_04 0
#define MW_CAN3_ID3_04 0
#define MW_CAN3_ID4_04 0
#define MW_CAN3_ENABLEFILTERBANK05 0
#define MW_CAN3_SCALE05 0
#define MW_CAN3_MODE05 0
#define MW_CAN3_FIFOASSIGNMENT05 0
#define MW_CAN3_IDTYPE05 0
#define MW_CAN3_ID1_05 0
#define MW_CAN3_MASK1_05 0
#define MW_CAN3_ID2_05 0
#define MW_CAN3_MASK2_05 0
#define MW_CAN3_ID3_05 0
#define MW_CAN3_ID4_05 0
#define MW_CAN3_ENABLEFILTERBANK06 0
#define MW_CAN3_SCALE06 0
#define MW_CAN3_MODE06 0
#define MW_CAN3_FIFOASSIGNMENT06 0
#define MW_CAN3_IDTYPE06 0
#define MW_CAN3_ID1_06 0
#define MW_CAN3_MASK1_06 0
#define MW_CAN3_ID2_06 0
#define MW_CAN3_MASK2_06 0
#define MW_CAN3_ID3_06 0
#define MW_CAN3_ID4_06 0
#define MW_CAN3_ENABLEFILTERBANK07 0
#define MW_CAN3_SCALE07 0
#define MW_CAN3_MODE07 0
#define MW_CAN3_FIFOASSIGNMENT07 0
#define MW_CAN3_IDTYPE07 0
#define MW_CAN3_ID1_07 0
#define MW_CAN3_MASK1_07 0
#define MW_CAN3_ID2_07 0
#define MW_CAN3_MASK2_07 0
#define MW_CAN3_ID3_07 0
#define MW_CAN3_ID4_07 0
#define MW_CAN3_ENABLEFILTERBANK08 0
#define MW_CAN3_SCALE08 0
#define MW_CAN3_MODE08 0
#define MW_CAN3_FIFOASSIGNMENT08 0
#define MW_CAN3_IDTYPE08 0
#define MW_CAN3_ID1_08 0
#define MW_CAN3_MASK1_08 0
#define MW_CAN3_ID2_08 0
#define MW_CAN3_MASK2_08 0
#define MW_CAN3_ID3_08 0
#define MW_CAN3_ID4_08 0
#define MW_CAN3_ENABLEFILTERBANK09 0
#define MW_CAN3_SCALE09 0
#define MW_CAN3_MODE09 0
#define MW_CAN3_FIFOASSIGNMENT09 0
#define MW_CAN3_IDTYPE09 0
#define MW_CAN3_ID1_09 0
#define MW_CAN3_MASK1_09 0
#define MW_CAN3_ID2_09 0
#define MW_CAN3_MASK2_09 0
#define MW_CAN3_ID3_09 0
#define MW_CAN3_ID4_09 0
#define MW_CAN3_ENABLEFILTERBANK10 0
#define MW_CAN3_SCALE10 0
#define MW_CAN3_MODE10 0
#define MW_CAN3_FIFOASSIGNMENT10 0
#define MW_CAN3_IDTYPE10 0
#define MW_CAN3_ID1_10 0
#define MW_CAN3_MASK1_10 0
#define MW_CAN3_ID2_10 0
#define MW_CAN3_MASK2_10 0
#define MW_CAN3_ID3_10 0
#define MW_CAN3_ID4_10 0
#define MW_CAN3_ENABLEFILTERBANK11 0
#define MW_CAN3_SCALE11 0
#define MW_CAN3_MODE11 0
#define MW_CAN3_FIFOASSIGNMENT11 0
#define MW_CAN3_IDTYPE11 0
#define MW_CAN3_ID1_11 0
#define MW_CAN3_MASK1_11 0
#define MW_CAN3_ID2_11 0
#define MW_CAN3_MASK2_11 0
#define MW_CAN3_ID3_11 0
#define MW_CAN3_ID4_11 0
#define MW_CAN3_ENABLEFILTERBANK12 0
#define MW_CAN3_SCALE12 0
#define MW_CAN3_MODE12 0
#define MW_CAN3_FIFOASSIGNMENT12 0
#define MW_CAN3_IDTYPE12 0
#define MW_CAN3_ID1_12 0
#define MW_CAN3_MASK1_12 0
#define MW_CAN3_ID2_12 0
#define MW_CAN3_MASK2_12 0
#define MW_CAN3_ID3_12 0
#define MW_CAN3_ID4_12 0
#define MW_CAN3_ENABLEFILTERBANK13 0
#define MW_CAN3_SCALE13 0
#define MW_CAN3_MODE13 0
#define MW_CAN3_FIFOASSIGNMENT13 0
#define MW_CAN3_IDTYPE13 0
#define MW_CAN3_ID1_13 0
#define MW_CAN3_MASK1_13 0
#define MW_CAN3_ID2_13 0
#define MW_CAN3_MASK2_13 0
#define MW_CAN3_ID3_13 0
#define MW_CAN3_ID4_13 0
#define MW_I2C0_BUSSPEEDHZ 100000
#define MW_I2C0_SCL_INDEX 0
#define MW_I2C0_SDA_INDEX 0
#define MW_I2C0_SCL D15
#define MW_I2C0_SDA D14
#define MW_I2C2_BUSSPEEDHZ 100000
#define MW_I2C2_SCL_INDEX 0
#define MW_I2C2_SDA_INDEX 0
#define MW_I2C2_SCL PB_10
#define MW_I2C2_SDA PB_11
#define MW_I2C3_BUSSPEEDHZ 100000
#define MW_I2C3_SCL_INDEX 0
#define MW_I2C3_SDA_INDEX 0
#define MW_I2C3_SCL PA_8
#define MW_I2C3_SDA PC_9
#define MW_I2C4_BUSSPEEDHZ 100000
#define MW_I2C4_SCL_INDEX 0
#define MW_I2C4_SDA_INDEX 0
#define MW_I2C4_SCL PF_14
#define MW_I2C4_SDA PF_15
#define MW_SPI0_BUSSPEEDHZ 1000000
#define MW_SPI0_MOSIPIN_INDEX 0
#define MW_SPI0_MISOPIN_INDEX 0
#define MW_SPI0_SCKPIN_INDEX 0
#define MW_SPI0_MOSIPIN D11
#define MW_SPI0_MISOPIN D12
#define MW_SPI0_SCKPIN D13
#define MW_SPI2_BUSSPEEDHZ 1000000
#define MW_SPI2_MOSIPIN_INDEX 0
#define MW_SPI2_MISOPIN_INDEX 0
#define MW_SPI2_SCKPIN_INDEX 0
#define MW_SPI2_MOSIPIN PB_15
#define MW_SPI2_MISOPIN PC_2
#define MW_SPI2_SCKPIN PB_13
#define MW_SPI3_BUSSPEEDHZ 1000000
#define MW_SPI3_MOSIPIN_INDEX 0
#define MW_SPI3_MISOPIN_INDEX 0
#define MW_SPI3_SCKPIN_INDEX 0
#define MW_SPI3_MOSIPIN PC_12
#define MW_SPI3_MISOPIN PC_11
#define MW_SPI3_SCKPIN PC_10
#define MW_SPI4_BUSSPEEDHZ 1000000
#define MW_SPI4_MOSIPIN_INDEX 0
#define MW_SPI4_MISOPIN_INDEX 0
#define MW_SPI4_SCKPIN_INDEX 0
#define MW_SPI4_MOSIPIN PE_14
#define MW_SPI4_MISOPIN D3
#define MW_SPI4_SCKPIN PE_12
#define MW_SCI1_BAUDRATE 115200
#define MW_SCI1_RXPIN_INDEX 0
#define MW_SCI1_TXPIN_INDEX 0
#define MW_SCI1_DATABITS 8
#define MW_SCI1_PARITY 0.000000
#define MW_SCI1_STOPBITS 1.000000
#define MW_SCI1_RXPIN PB_15
#define MW_SCI1_TXPIN PB_6
#define MW_SCI2_BAUDRATE 115200
#define MW_SCI2_RXPIN_INDEX 0
#define MW_SCI2_TXPIN_INDEX 0
#define MW_SCI2_DATABITS 8
#define MW_SCI2_PARITY 0.000000
#define MW_SCI2_STOPBITS 1.000000
#define MW_SCI2_RXPIN PD_6
#define MW_SCI2_TXPIN PD_5
#define MW_SCI0_BAUDRATE 115200
#define MW_SCI0_RXPIN_INDEX 1
#define MW_SCI0_TXPIN_INDEX 2
#define MW_SCI0_DATABITS 8
#define MW_SCI0_PARITY 0.000000
#define MW_SCI0_STOPBITS 1.000000
#define MW_SCI0_RXPIN PD_9
#define MW_SCI0_TXPIN PD_8
#define MW_SCI4_BAUDRATE 115200
#define MW_SCI4_RXPIN_INDEX 0
#define MW_SCI4_TXPIN_INDEX 0
#define MW_SCI4_DATABITS 8
#define MW_SCI4_PARITY 0.000000
#define MW_SCI4_STOPBITS 1.000000
#define MW_SCI4_RXPIN PC_11
#define MW_SCI4_TXPIN PA_0
#define MW_SCI5_BAUDRATE 115200
#define MW_SCI5_RXPIN_INDEX 0
#define MW_SCI5_TXPIN_INDEX 0
#define MW_SCI5_DATABITS 8
#define MW_SCI5_PARITY 0.000000
#define MW_SCI5_STOPBITS 1.000000
#define MW_SCI5_RXPIN PD_2
#define MW_SCI5_TXPIN PC_12
#define MW_SCI6_BAUDRATE 115200
#define MW_SCI6_RXPIN_INDEX 1
#define MW_SCI6_TXPIN_INDEX 1
#define MW_SCI6_DATABITS 8
#define MW_SCI6_PARITY 0.000000
#define MW_SCI6_STOPBITS 1.000000
#define MW_SCI6_RXPIN D0
#define MW_SCI6_TXPIN D1
#define MW_SCI7_BAUDRATE 115200
#define MW_SCI7_RXPIN_INDEX 0
#define MW_SCI7_TXPIN_INDEX 0
#define MW_SCI7_DATABITS 8
#define MW_SCI7_PARITY 0.000000
#define MW_SCI7_STOPBITS 1.000000
#define MW_SCI7_RXPIN PF_6
#define MW_SCI7_TXPIN PF_7
#define MW_SCI8_BAUDRATE 115200
#define MW_SCI8_RXPIN_INDEX 0
#define MW_SCI8_TXPIN_INDEX 0
#define MW_SCI8_DATABITS 8
#define MW_SCI8_PARITY 0.000000
#define MW_SCI8_STOPBITS 1.000000
#define MW_SCI8_RXPIN PE_0
#define MW_SCI8_TXPIN PE_1
#define MW_RS485_RS485_SERIAL 0
#define MW_RS485_RS485_DEPIN 8
#define MW_RS485_RS485_REPIN 9
#define MW_MODBUS_MODBUS_COMMS 0
#define MW_MODBUS_MODBUS_MODE 0
#define MW_MODBUS_MODBUS_SERVERID 1
#define MW_MODBUS_MODBUS_CONFIGCOIL 49
#define MW_MODBUS_MODBUS_COILADDR 0
#define MW_MODBUS_MODBUS_COILNUM 1
#define MW_MODBUS_MODBUS_CONFIGINPUT 49
#define MW_MODBUS_MODBUS_INPUTADDR 0
#define MW_MODBUS_MODBUS_INPUTNUM 1
#define MW_MODBUS_MODBUS_CONFIGHOLDINGREG 49
#define MW_MODBUS_MODBUS_HOLDINGREGADDR 0
#define MW_MODBUS_MODBUS_HOLDINGREGNUM 1
#define MW_MODBUS_MODBUS_CONFIGINPUTREG 49
#define MW_MODBUS_MODBUS_INPUTREGADDR 0
#define MW_MODBUS_MODBUS_INPUTREGNUM 1
#define MW_MODBUS_MODBUS_CLIENTTIMEOUT 100
#define MW_THINGSPEAK_CONNECTTIMEOUT 3
#define MW_THINGSPEAK_WRITEBLOCKSRESPONSETIMEOUT 1
#define MW_THINGSPEAK_READBLOCKSRESPONSETIMEOUT 5
#define MW_PIL_INTERFACE 0
#define MW_PIL_COMPORT COM2
#define MW_SENSOR_FILELOCATION codertarget.mbed.internal
#define MW_DATAVERSION 2016.02
#define MW_IOBLOCKSMODE deployed

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
