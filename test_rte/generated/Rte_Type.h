/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_Type.h
 ********************************************************************/

#ifndef RTE_TYPE_H
#define RTE_TYPE_H


#include "Rte.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/**************************** datatypes ******************************/

typedef unsigned char IComLight_Ctrl_Inputs_CTR_FN_DR_Type;
typedef unsigned char IComLight_Ctrl_Inputs_CTR_FN_POS_Type;
typedef unsigned char IComLight_Ctrl_Inputs_CTR_FN_PAR_Type;
typedef unsigned char IComCar_CTR_FN_LCU_Type;
typedef unsigned char IComCar_CTR_FN_BRS_Type;
typedef float IComBCE_Voltage_Type;
typedef unsigned char IComLight_Ctrl_Inputs_ST_LP_LIN_Type;
typedef unsigned char IComBrightness_Rain_Sensor_ST_RB_LIN_Type;
typedef unsigned char IComCar_State_VEH_ST_Type;
typedef unsigned char IComMotor_Speed_Motor_Speed_Type;
typedef unsigned char IComLight_Ctrl_Inputs_CTR_FN_POS_Type;
typedef unsigned char IComLight_Ctrl_Inputs_CTR_FN_PAR_Type;
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef unsigned long uint8_least;
typedef unsigned long uint16_least;
typedef unsigned long uint32_least;
typedef signed long sint8_least;
typedef signed long sint16_least;
typedef signed long sint32_least;
typedef float float32;
typedef double float64;
typedef unsigned char Boolean;
typedef signed char SInt1;
typedef signed short SInt10;
typedef signed short SInt11;
typedef signed short SInt12;
typedef signed short SInt13;
typedef signed short SInt14;
typedef signed short SInt15;
typedef signed short SInt16;
typedef signed long SInt17;
typedef signed long SInt18;
typedef signed long SInt19;
typedef signed char SInt2;
typedef signed long SInt20;
typedef signed long SInt21;
typedef signed long SInt22;
typedef signed long SInt23;
typedef signed long SInt24;
typedef signed long SInt25;
typedef signed long SInt26;
typedef signed long SInt27;
typedef signed long SInt28;
typedef signed long SInt29;
typedef signed char SInt3;
typedef signed long SInt30;
typedef signed long SInt31;
typedef signed long SInt32;
typedef signed char SInt4;
typedef signed char SInt5;
typedef signed char SInt6;
typedef signed char SInt7;
typedef signed char SInt8;
typedef signed short SInt9;
typedef unsigned char UInt1;
typedef unsigned short UInt10;
typedef unsigned short UInt11;
typedef unsigned short UInt12;
typedef unsigned short UInt13;
typedef unsigned short UInt14;
typedef unsigned short UInt15;
typedef unsigned short UInt16;
typedef unsigned long UInt17;
typedef unsigned long UInt18;
typedef unsigned long UInt19;
typedef unsigned char UInt2;
typedef unsigned long UInt20;
typedef unsigned long UInt21;
typedef unsigned long UInt22;
typedef unsigned long UInt23;
typedef unsigned long UInt24;
typedef unsigned long UInt25;
typedef unsigned long UInt26;
typedef unsigned long UInt27;
typedef unsigned long UInt28;
typedef unsigned long UInt29;
typedef unsigned char UInt3;
typedef unsigned long UInt30;
typedef unsigned long UInt31;
typedef unsigned long UInt32;
typedef unsigned long long UInt64;
typedef unsigned char UInt4;
typedef unsigned char UInt5;
typedef unsigned char UInt6;
typedef unsigned char UInt7;
typedef unsigned char UInt8;
typedef unsigned short UInt9;
typedef UInt8 UcArray8[8];
typedef UInt8 Array8[8];
typedef UInt8 ByteArray8[8];
typedef UInt8 ByteArray1[1];
typedef UInt8 ByteArray2[2];
typedef UInt8 ByteArray3[3];
typedef UInt8 ByteArray5[5];
typedef UInt8 ByteArray6[6];
typedef UInt8 ByteArray7[7];
typedef UInt8 UcArray16[16];
typedef UInt32 UlArray80[80];
typedef UInt8 ByteArray128[128];
typedef UInt8 ByteArray132[132];
typedef UInt8 ByteArray20[20];
typedef UInt8 ByteArray26[26];
typedef UInt8 ByteArray4[4];
typedef UInt8 ByteArray72[72];
typedef UInt8 ByteArray19[19];
typedef UInt8 ByteArray9[9];
typedef UInt8 ByteArray64[64];
typedef UInt8 ByteArray65[65];
typedef UInt8 ByteArray264[264];
typedef UInt8 ByteArray40[40];
typedef UInt8 ByteArray42[42];
typedef UInt8 ByteArray50[50];
typedef UInt8 ByteArray60[60];
typedef UInt8 ByteArray146[146];
typedef UInt8 UcArray3[3];
typedef SInt8 CArray8[8];
typedef UInt8 UcArray2[2];
typedef UInt8 UcArray4[4];
typedef SInt8 CArray3[3];
typedef UInt8 ByteArray32[32];
typedef UInt8 ByteArray112[112];
typedef UInt8 ByteArray82[82];
typedef UInt8 ByteArray12[12];
typedef UInt8 ByteArray48[48];
typedef UInt16 SIArray1[1];
typedef UInt8 ByteArray10[10];
typedef UInt8 ByteArray16[16];
typedef UInt8 ByteArray17[17];
typedef UInt8 ByteArray25[25];
typedef UInt8 ByteArray34[34];
typedef UInt16 SIArray25[25];
typedef UInt8 ByteArray14[14];
typedef UInt8 ByteArray100[100];
typedef UInt8 ByteArray21[21];
typedef UInt32 UlArray5[5];
typedef UInt8 ByteArray92[92];
typedef UInt8 ByteArray24[24];
typedef UInt8 ByteArray129[129];
typedef UInt8 ByteArray11[11];
typedef UInt8 ByteArray516[516];
typedef UInt8 ByteArray124[124];
typedef UInt8 ByteArray13[13];


/********************* mode declaration groups ***********************/


/********************** per instance memories ************************/


/******************* implicit buffer declaration *********************/


/********************** port data structures *************************/


/******************** component data structures **********************/

/*********************************************************************
 * component data structure for SWC: SwcLceComManager 
 *********************************************************************/
typedef struct Rte_CDS_SwcLceComManager
{
    /* Data Handles section*/
    /* Per-Instance Memory Handles section*/
    /* Inter-runnable Variable Handles section*/
    /* Calibration Parameter Handles section*/
    /* Exclusive-area Handles section*/
    /* Port API Handles section*/
    /* Inter Runnable Variable API Handles section*/
    /* dummy value*/
    uint8 _dummy;
} Rte_CDS_SwcLceComManager;

/*********************************************************************
 * component data structure for SWC: SwcLceMaster 
 *********************************************************************/
typedef struct Rte_CDS_SwcLceMaster
{
    /* Data Handles section*/
    /* Per-Instance Memory Handles section*/
    /* Inter-runnable Variable Handles section*/
    /* Calibration Parameter Handles section*/
    /* Exclusive-area Handles section*/
    /* Port API Handles section*/
    /* Inter Runnable Variable API Handles section*/
    /* dummy value*/
    uint8 _dummy;
} Rte_CDS_SwcLceMaster;


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_TYPE_H */
