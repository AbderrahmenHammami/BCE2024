/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_SwcLceMaster_BufferDecorator.h
 ********************************************************************/

#ifndef RTE_SWCLCEMASTER_BUFFERDECORATOR_H_
#define RTE_SWCLCEMASTER_BUFFERDECORATOR_H_

#include <algorithm>
#include "Rte_Type.h"
#include "Rte_SwcLceMaster_Interface.h"

//Buffer class for RTE.


class Rte_SwcLceMaster_BufferDecorator : public Rte_SwcLceMaster_Interface
{
public:
	Rte_SwcLceMaster_BufferDecorator (Rte_SwcLceMaster_Interface* component);
	
	 IComLight_Ctrl_Inputs_ST_LP_LIN_Type get_Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Buf() const;
	 IComBrightness_Rain_Sensor_ST_RB_LIN_Type get_Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Buf() const;
	 IComCar_State_VEH_ST_Type get_Rte_Read_SwcLceMaster_Car_State_VEH_ST_Buf() const;
	 IComMotor_Speed_Motor_Speed_Type get_Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Buf() const;
	Std_ReturnType get_Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue() const;
	Std_ReturnType get_Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue() const;
	Std_ReturnType get_Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue() const;
	Std_ReturnType get_Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue() const;
			
/////////////////////////////////////////
// Overwritten mock functions. Delegates and writes buffer values.

	virtual Std_ReturnType Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN (IComLight_Ctrl_Inputs_ST_LP_LIN_Type* ST_LP_LIN);
	virtual Std_ReturnType Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN (IComBrightness_Rain_Sensor_ST_RB_LIN_Type* ST_RB_LIN);
	virtual Std_ReturnType Rte_Read_SwcLceMaster_Car_State_VEH_ST (IComCar_State_VEH_ST_Type* VEH_ST);
	virtual Std_ReturnType Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed (IComMotor_Speed_Motor_Speed_Type* Motor_Speed);
	
	private:
		Rte_SwcLceMaster_Interface* _component; //component to decorate

	IComLight_Ctrl_Inputs_ST_LP_LIN_Type _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Buf;
	IComBrightness_Rain_Sensor_ST_RB_LIN_Type _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Buf;
	IComCar_State_VEH_ST_Type _Rte_Read_SwcLceMaster_Car_State_VEH_ST_Buf;
	IComMotor_Speed_Motor_Speed_Type _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Buf;

	Std_ReturnType _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue;
	Std_ReturnType _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue;
	Std_ReturnType _Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue;
	Std_ReturnType _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue;
};
#endif /* RTE_SwcLceMaster_BUFFERDECORATOR_H_ */
