/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_SwcLceComManager.h
 ********************************************************************/

#ifndef RTE_SWCLCECOMMANAGER_H
#define RTE_SWCLCECOMMANAGER_H

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#include "Rte_SwcLceComManager_Type.h"

/************************* Indirect API ***************************/

/*
* Indirect API Calls
*/





/************************* instance handle ***************************/

extern const Rte_CDS_SwcLceComManager * const Rte_Inst_SwcLceComManager;

/************************ application errors *************************/


/*************************** init values *****************************/


/****************** per instance memory definition *******************/


/************************* exclusive areas ***************************/


/************************* RTE API mapping ***************************/

/*****************************************************
 * Port:        comCTR_EL_F
 * Interface:   IComCTR_EL_F
 * DataElement: CTR_FN_DR
 *****************************************************/
extern Std_ReturnType Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR(IComLight_Ctrl_Inputs_CTR_FN_DR_Type CTR_FN_DR);
#ifndef IN_RTE_C
#define Rte_Write_comCTR_EL_F_CTR_FN_DR(RTEData) \
    Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR(RTEData)
#endif


/*****************************************************
 * Port:        comCTR_EL_F
 * Interface:   IComCTR_EL_F
 * DataElement: CTR_FN_POS
 *****************************************************/
extern Std_ReturnType Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS(IComLight_Ctrl_Inputs_CTR_FN_POS_Type CTR_FN_POS);
#ifndef IN_RTE_C
#define Rte_Write_comCTR_EL_F_CTR_FN_POS(RTEData) \
    Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS(RTEData)
#endif


/*****************************************************
 * Port:        comCTR_EL_F
 * Interface:   IComCTR_EL_F
 * DataElement: CTR_FN_PAR
 *****************************************************/
extern Std_ReturnType Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR(IComLight_Ctrl_Inputs_CTR_FN_PAR_Type CTR_FN_PAR);
#ifndef IN_RTE_C
#define Rte_Write_comCTR_EL_F_CTR_FN_PAR(RTEData) \
    Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR(RTEData)
#endif


/*****************************************************
 * Port:        comLight_Ctrl_Inputs
 * Interface:   IComLight_Ctrl_Inputs
 * DataElement: ST_LP_LIN
 *****************************************************/
extern Std_ReturnType Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN(IComLight_Ctrl_Inputs_ST_LP_LIN_Type* ST_LP_LIN);
#ifndef IN_RTE_C
#define Rte_Read_comLight_Ctrl_Inputs_ST_LP_LIN(RTEData) \
    Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN(RTEData)
#endif


/*****************************************************
 * Port:        comBrightness_Rain_Sensor
 * Interface:   IComBrightness_Rain_Sensor
 * DataElement: ST_RB_LIN
 *****************************************************/
extern Std_ReturnType Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN(IComBrightness_Rain_Sensor_ST_RB_LIN_Type* ST_RB_LIN);
#ifndef IN_RTE_C
#define Rte_Read_comBrightness_Rain_Sensor_ST_RB_LIN(RTEData) \
    Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN(RTEData)
#endif


/*****************************************************
 * Port:        comCar_State
 * Interface:   IComCar_State
 * DataElement: VEH_ST
 *****************************************************/
extern Std_ReturnType Rte_Read_SwcLceComManager_comCar_State_VEH_ST(IComCar_State_VEH_ST_Type* VEH_ST);
#ifndef IN_RTE_C
#define Rte_Read_comCar_State_VEH_ST(RTEData) \
    Rte_Read_SwcLceComManager_comCar_State_VEH_ST(RTEData)
#endif


/*****************************************************
 * Port:        comMotor_Speed
 * Interface:   IComMotor_Speed
 * DataElement: Motor_Speed
 *****************************************************/
extern Std_ReturnType Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed(IComMotor_Speed_Motor_Speed_Type* Motor_Speed);
#ifndef IN_RTE_C
#define Rte_Read_comMotor_Speed_Motor_Speed(RTEData) \
    Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed(RTEData)
#endif



/**************** event triggered runnable entities *******************/

/*****************************************************
 * Runnable: 	RTERunnable_SwcLceComManager_RunComMngr_10msTask
 * Period:		0.01
 *****************************************************/
extern void RTERunnable_SwcLceComManager_RunComMngr_10msTask(void);



#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_SWCLCECOMMANAGER_H */
