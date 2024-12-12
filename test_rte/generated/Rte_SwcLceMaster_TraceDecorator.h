/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_SwcLceMaster_TraceDecorator.h
 ********************************************************************/

#ifndef RTE_SWCLCEMASTER_TRACEDECORATOR_H_
#define RTE_SWCLCEMASTER_TRACEDECORATOR_H_

#include <ctime>
#include <map>
#include <string>
#include <vector>
#include <utility>

#include "Rte_Type.h"	
#include "Rte_SwcLceMaster_Interface.h"

/** Creates traces of the simple RTE sender/reciever, but no record and arrays.
 *
* To be used as a decorator over the Mock. I.e. set an instance of this class as mock,
* and this class will delegate all mocked calls while tracing the values. Only for Read and Writes
*
*/

class Rte_SwcLceMaster_TraceDecorator: public Rte_SwcLceMaster_Interface
{
public:
	explicit Rte_SwcLceMaster_TraceDecorator(Rte_SwcLceMaster_Interface* component, unsigned channelId = 1);
	
	virtual void start() { _tracing = true; }
	virtual void stop() { _tracing = false; }
	virtual std::time_t getStartTime() const { return _startTime; }
	virtual void setStartTime(std::time_t time) { _startTime = time; }
	virtual void setTime(unsigned time) { _currentTime = time; }
	virtual unsigned getMaxTime() const { return _currentTime; }
	virtual unsigned getChannelId() const { return _channelId; }
	virtual void setChannelId(unsigned channelId) { _channelId = channelId; }	
	
	std::vector<std::pair<IComLight_Ctrl_Inputs_ST_LP_LIN_Type,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Trace_Begin() const { return _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Trace.begin(); }
	std::vector<std::pair<IComLight_Ctrl_Inputs_ST_LP_LIN_Type,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Trace_End() const { return _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Trace.end(); }
	std::vector<std::pair<Std_ReturnType,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue_Begin() const { return _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue.begin(); }
	std::vector<std::pair<Std_ReturnType,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue_End() const { return _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue.end(); }
	std::vector<std::pair<IComBrightness_Rain_Sensor_ST_RB_LIN_Type,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Trace_Begin() const { return _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Trace.begin(); }
	std::vector<std::pair<IComBrightness_Rain_Sensor_ST_RB_LIN_Type,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Trace_End() const { return _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Trace.end(); }
	std::vector<std::pair<Std_ReturnType,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue_Begin() const { return _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue.begin(); }
	std::vector<std::pair<Std_ReturnType,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue_End() const { return _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue.end(); }
	std::vector<std::pair<IComCar_State_VEH_ST_Type,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Car_State_VEH_ST_Trace_Begin() const { return _Rte_Read_SwcLceMaster_Car_State_VEH_ST_Trace.begin(); }
	std::vector<std::pair<IComCar_State_VEH_ST_Type,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Car_State_VEH_ST_Trace_End() const { return _Rte_Read_SwcLceMaster_Car_State_VEH_ST_Trace.end(); }
	std::vector<std::pair<Std_ReturnType,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue_Begin() const { return _Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue.begin(); }
	std::vector<std::pair<Std_ReturnType,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue_End() const { return _Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue.end(); }
	std::vector<std::pair<IComMotor_Speed_Motor_Speed_Type,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Trace_Begin() const { return _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Trace.begin(); }
	std::vector<std::pair<IComMotor_Speed_Motor_Speed_Type,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Trace_End() const { return _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Trace.end(); }
	std::vector<std::pair<Std_ReturnType,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue_Begin() const { return _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue.begin(); }
	std::vector<std::pair<Std_ReturnType,unsigned> >::const_iterator
	Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue_End() const { return _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue.end(); }
	
	/////////////////////////////////////////
	// Overwritten mock functions. Delegates and writes buffer values.
	virtual Std_ReturnType Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN (IComLight_Ctrl_Inputs_ST_LP_LIN_Type* ST_LP_LIN);
	virtual Std_ReturnType Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN (IComBrightness_Rain_Sensor_ST_RB_LIN_Type* ST_RB_LIN);
	virtual Std_ReturnType Rte_Read_SwcLceMaster_Car_State_VEH_ST (IComCar_State_VEH_ST_Type* VEH_ST);
	virtual Std_ReturnType Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed (IComMotor_Speed_Motor_Speed_Type* Motor_Speed);
	
	protected:
	bool _tracing;
	std::time_t _startTime;
	unsigned _currentTime;
	unsigned _channelId;
	Rte_SwcLceMaster_Interface* _component;

	std::vector<std::pair<IComLight_Ctrl_Inputs_ST_LP_LIN_Type,unsigned> > _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Trace;
	std::vector<std::pair<Std_ReturnType,unsigned> > _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_ReturnValue;
	std::vector<std::pair<IComBrightness_Rain_Sensor_ST_RB_LIN_Type,unsigned> > _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Trace;
	std::vector<std::pair<Std_ReturnType,unsigned> > _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_ReturnValue;
	std::vector<std::pair<IComCar_State_VEH_ST_Type,unsigned> > _Rte_Read_SwcLceMaster_Car_State_VEH_ST_Trace;
	std::vector<std::pair<Std_ReturnType,unsigned> > _Rte_Read_SwcLceMaster_Car_State_VEH_ST_ReturnValue;
	std::vector<std::pair<IComMotor_Speed_Motor_Speed_Type,unsigned> > _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Trace;
	std::vector<std::pair<Std_ReturnType,unsigned> > _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_ReturnValue;



};
#endif /*RTE_SWCLCEMASTER_TRACEDECORATOR_H_*/