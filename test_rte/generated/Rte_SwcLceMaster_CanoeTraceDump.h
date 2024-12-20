/********************************************************************
 * Automatically generated by ARUnit
 * Filename: RTE_SwcLceMasterCanoeTraceDump.h
 ********************************************************************/

#ifndef ZSG_RTE_SWCLCEMASTER_CanoeTraceDump_h__
#define ZSG_RTE_SWCLCEMASTER_CanoeTraceDump_h__

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <utility>

#include "Rte_Type.h"

class Rte_SwcLceMaster_TraceDecorator;

/**
 * Logger to write asc/dbc files for CARMEN/CANalyzer...
 *
 * This class logs data as CAN traces to a asc file and creates the appropriate database file(dbc).
 * The data can then be analyzed as if it were a recorded bus trace of an ECU.
 *
 * Currently only Rte sender/reciever are traced (and no record/array).
 */
 
 class Rte_SwcLceMaster_CanoeTraceDump{
 	public:
 		Rte_SwcLceMaster_CanoeTraceDump(const Rte_SwcLceMaster_TraceDecorator* trace, std::string fileName);
 		~Rte_SwcLceMaster_CanoeTraceDump();
 	
 	void dumpTrace();
 	protected:
 		/** Type is used for mapping from signal name to signal attributes. */
 		typedef struct DbcAttributesType
 		{
 	DbcAttributesType() : 
 	_id(0), _size(0), _isSigned(false) 
 		{};
 		DbcAttributesType(unsigned int id, unsigned int size, bool isSigned) : 
 		_id(id), _size(size), _isSigned(isSigned) 
 		{};
 		unsigned int _id;
 		unsigned int _size;
 		bool _isSigned;
 		} DbcAttributesType;
 		   	
 		typedef std::pair<std::string, DbcAttributesType> DbcMapEntry_t;
 		typedef std::vector<DbcMapEntry_t> DbcEntries_t;
 		typedef std::map<std::string, DbcAttributesType> DbcMap_t;
 		   	
 		const Rte_SwcLceMaster_TraceDecorator* _trace;
 		 std::string _fileName;
 		 /** The file stream for asc file output. */
 		 std::ofstream _ascOutputFile; 
 		 /** The file stream for dbc file output. */
 		 std::ofstream _dbcOutputFile; 
 		 /** The mapping from signals to id/dataTypeSize/signedness, used for dbc file creation. */
 		 DbcMap_t _dbcMap; 
 		 DbcEntries_t _sortedDbcEntries;
 		// trace standard ports   	 
 		std::vector<std::pair<IComLight_Ctrl_Inputs_ST_LP_LIN_Type,unsigned> >::const_iterator _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_BufItr;
 		std::vector<std::pair<IComBrightness_Rain_Sensor_ST_RB_LIN_Type,unsigned> >::const_iterator _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_BufItr;
 		std::vector<std::pair<IComCar_State_VEH_ST_Type,unsigned> >::const_iterator _Rte_Read_SwcLceMaster_Car_State_VEH_ST_BufItr;
 		std::vector<std::pair<IComMotor_Speed_Motor_Speed_Type,unsigned> >::const_iterator _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_BufItr;
 		// trace structures
		// return type functions
		std::vector<std::pair<Std_ReturnType, unsigned> >::const_iterator _Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_returnValueItr;
		std::vector<std::pair<Std_ReturnType, unsigned> >::const_iterator _Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_returnValueItr;
		std::vector<std::pair<Std_ReturnType, unsigned> >::const_iterator _Rte_Read_SwcLceMaster_Car_State_VEH_ST_returnValueItr;
		std::vector<std::pair<Std_ReturnType, unsigned> >::const_iterator _Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_returnValueItr;
		// return only functions for structs
	
	 // Write methods
		void openLogFiles();
		void closeLogFiles();
		void writeDbcData();
		void writeAscDataFormatted(std::string signalName, unsigned int numberBytes, unsigned timestamp, std::string hexValue);
		void writeAscData();
    
		void writeAscData_Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN_Trace(unsigned time);
		void writeAscData_Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN_Trace(unsigned time);
		void writeAscData_Rte_Read_SwcLceMaster_Car_State_VEH_ST_Trace(unsigned time);
		void writeAscData_Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed_Trace(unsigned time);
    
		void generateDbcMap();
    
		/** Formats the timestamp from integer value e.g. 120 (milliseconds) to format 0.120 (in seconds). */
		std::string formatTimestamp(unsigned timestamp) const;
    
		/** Format databytes to be in the format "1A 10 03" with separating spaces between the bytes and leading zeros (according to numberBytes). */
		std::string formatDataBytes(unsigned int numberBytes, std::string hexValue) const;
    
		/** Get signal id in string as hexadecimal format (e.g. signalA --> 1A). */
		std::string getSignalId(const std::string& signalName) const;
 };
 
#endif // ZSG_RTE_SWCLCEMASTER_CanoeTraceDump_h__
