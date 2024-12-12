/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_SwcLceMaster_TraceDecorator.cpp
 ********************************************************************/
	
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <limits>

#include "Rte_SwcLceMaster_TraceDecorator.h"
	
Rte_SwcLceMaster_TraceDecorator::Rte_SwcLceMaster_TraceDecorator(Rte_SwcLceMaster_Interface* component, unsigned channelId) :
	Rte_SwcLceMaster_Interface()
	,_tracing(false)
	,_startTime(std::time_t(0))
	,_currentTime(0)
	,_channelId(channelId)
	,_component(component)
	,_Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Trace()
	,_Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue()
	,_Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Trace()
	,_Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue()
	,_Rte_Read_SwcLceMaster_Car_State_VEH_ST_Trace()
	,_Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue()
	,_Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Trace()
	,_Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue()
{
}
Std_ReturnType Rte_SwcLceMaster_TraceDecorator::Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN(IComLight_Ctrl_Inputs_ST_LP_LIN_Type* ST_LP_LIN)
{
	Std_ReturnType returnVal = _component->Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN(ST_LP_LIN);
	if(_tracing)
	{
		if(_Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Trace.empty() || _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Trace.back().first != *ST_LP_LIN
		)
			_Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Trace.push_back(std::make_pair(*ST_LP_LIN
			, _currentTime));
		if(_Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue.empty() || _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue.back().first != returnVal)
			_Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue.push_back(std::make_pair(returnVal, _currentTime));
	}
	return returnVal;
} 
Std_ReturnType Rte_SwcLceMaster_TraceDecorator::Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN(IComBrightness_Rain_Sensor_ST_RB_LIN_Type* ST_RB_LIN)
{
	Std_ReturnType returnVal = _component->Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN(ST_RB_LIN);
	if(_tracing)
	{
		if(_Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Trace.empty() || _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Trace.back().first != *ST_RB_LIN
		)
			_Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Trace.push_back(std::make_pair(*ST_RB_LIN
			, _currentTime));
		if(_Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue.empty() || _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue.back().first != returnVal)
			_Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue.push_back(std::make_pair(returnVal, _currentTime));
	}
	return returnVal;
} 
Std_ReturnType Rte_SwcLceMaster_TraceDecorator::Rte_Read_SwcLceMaster_Car_State_VEH_ST(IComCar_State_VEH_ST_Type* VEH_ST)
{
	Std_ReturnType returnVal = _component->Rte_Read_SwcLceMaster_Car_State_VEH_ST(VEH_ST);
	if(_tracing)
	{
		if(_Rte_Read_SwcLceMaster_Car_State_VEH_ST_Trace.empty() || _Rte_Read_SwcLceMaster_Car_State_VEH_ST_Trace.back().first != *VEH_ST
		)
			_Rte_Read_SwcLceMaster_Car_State_VEH_ST_Trace.push_back(std::make_pair(*VEH_ST
			, _currentTime));
		if(_Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue.empty() || _Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue.back().first != returnVal)
			_Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue.push_back(std::make_pair(returnVal, _currentTime));
	}
	return returnVal;
} 
Std_ReturnType Rte_SwcLceMaster_TraceDecorator::Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed(IComMotor_Speed_Motor_Speed_Type* Motor_Speed)
{
	Std_ReturnType returnVal = _component->Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed(Motor_Speed);
	if(_tracing)
	{
		if(_Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Trace.empty() || _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Trace.back().first != *Motor_Speed
		)
			_Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Trace.push_back(std::make_pair(*Motor_Speed
			, _currentTime));
		if(_Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue.empty() || _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue.back().first != returnVal)
			_Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue.push_back(std::make_pair(returnVal, _currentTime));
	}
	return returnVal;
} 
// end of trace decorators
// forwarding methods
	//	[]
// forwarding methods2		
// forwarding PIM methods
// virtual methods irv
// the end