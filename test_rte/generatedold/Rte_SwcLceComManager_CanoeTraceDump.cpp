/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_SwcLceComManager_CanoeTraceDump.cpp
 ********************************************************************/
	
#include <algorithm> // sort
#include <ctime> //time, ctime
#include <stdexcept>
#include <sstream>

#include "Rte_SwcLceComManager_CanoeTraceDump.h"
#include "Rte_SwcLceComManager_TraceDecorator.h"

// Annonymous NS for internal stuff
namespace
{
    /** Transform number to string object. */
    template <typename T>
    std::string NumberToString (T Number)
    {
        std::ostringstream ss;
        if(sizeof(T) == 1)
            ss << static_cast<int>(Number);
        else
            ss << Number;
    
        return ss.str();
    };
    
    /** Transform number in hexadecimal string format, size is used for char signals (uint8...) that they are not written as chars. */
    template <typename T>
    std::string NumberToHexString (T Number)
    {
        std::ostringstream ss;
        if(sizeof(T) == 1)
            ss << std::uppercase << std::hex << static_cast<int>(Number);
        else
            ss << std::uppercase << std::hex << Number;
    
        // Check if length of string is consistent with datatype otherwise remove leading characters
        size_t actualStrSize = ss.str().size();
        unsigned int expectedStringSize = 2*sizeof(T);
        if (actualStrSize > expectedStringSize)
            return ss.str().substr(actualStrSize - expectedStringSize, actualStrSize);
        else
            return ss.str();
    };
} //end ns

Rte_SwcLceComManager_CanoeTraceDump::Rte_SwcLceComManager_CanoeTraceDump(const Rte_SwcLceComManager_TraceDecorator* trace, std::string fileName):
 _trace(trace)
 , _fileName(std::move(fileName))
 , _ascOutputFile()
 , _dbcOutputFile()
 , _dbcMap()
 , _sortedDbcEntries()
 ,_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr()
 ,_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr()
 ,_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr()
 ,_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr()
 ,_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr()
 ,_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr()
 ,_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr()
 ,_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr()
 ,_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr()
 ,_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr()
 ,_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr()
 ,_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr()
 ,_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr()
 ,_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr()
{
}

Rte_SwcLceComManager_CanoeTraceDump::~Rte_SwcLceComManager_CanoeTraceDump()
{
	closeLogFiles();
}

void Rte_SwcLceComManager_CanoeTraceDump::dumpTrace(){
    openLogFiles();
    if(!_dbcOutputFile.is_open() || !_ascOutputFile.is_open())
        throw std::runtime_error("Cannot open files for trace dump.");      
    generateDbcMap();  // lazy generated to avoid heavy constructor
    writeDbcData();
    writeAscData();
    closeLogFiles();
}

void Rte_SwcLceComManager_CanoeTraceDump::closeLogFiles()
{
    if(_dbcOutputFile.is_open()) 
       _dbcOutputFile.close();
    if(_ascOutputFile.is_open()) 
       _ascOutputFile.close();
}

void Rte_SwcLceComManager_CanoeTraceDump::openLogFiles()
{
    closeLogFiles();
    _ascOutputFile.open((_fileName + ".asc").c_str(), std::ofstream::out);
    _dbcOutputFile.open((_fileName + ".dbc").c_str(), std::ifstream::out);
}

void Rte_SwcLceComManager_CanoeTraceDump::writeDbcData()
{
	_dbcOutputFile << "VERSION \"DNNBNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN/4/%%%/4/'%**4NNN///\"\n";
    _dbcOutputFile << "\nNS_:\n\nBS_:\n\nBU_: GTEST\n\n"; 

    for(DbcEntries_t::const_iterator it=_sortedDbcEntries.begin(); it!=_sortedDbcEntries.end(); ++it)
    {
        char signedChar = it->second._isSigned? '-' : '+';
        _dbcOutputFile << "BO_ " << it->second._id << " " << it->first << ": " << it->second._size << " GTEST\n";
        _dbcOutputFile << " SG_ " << it->first << ": 7|" << 8 * it->second._size << "@0" << signedChar << " (1,0) [0|0] \"\" GTEST\n\n";
    }
}

void Rte_SwcLceComManager_CanoeTraceDump::writeAscDataFormatted(std::string signalName, unsigned int numberBytes, unsigned timestamp, std::string hexValue)
{
	if(_ascOutputFile.is_open())
    {
        _ascOutputFile 
            << "  " << formatTimestamp(timestamp) 
            << " " << _trace->getChannelId()
            << "  " << getSignalId(std::move(signalName)) 
            << "     " << "Rx"  
            << "   " << "d" 
            << " " << numberBytes 
            << " " << formatDataBytes(numberBytes, std::move(hexValue)) << std::endl;
    }
}
void Rte_SwcLceComManager_CanoeTraceDump::writeAscData()
{
	 std::time_t result = _trace->getStartTime();
    _ascOutputFile << "date " << std::ctime(&result);
    _ascOutputFile << "base hex   timestamps absolute\n";
    _ascOutputFile << std::endl;
	    
    _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_Trace_Begin();
    _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_Trace_Begin();
    _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_Trace_Begin();
    _Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr = _trace->Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_Trace_Begin();
    _Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr = _trace->Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_Trace_Begin();
    _Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr = _trace->Rte_Read_SwcLceComManager_comCar_State_VEH_ST_Trace_Begin();
    _Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr = _trace->Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_Trace_Begin();
    _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_ReturnValue_Begin();
    _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_ReturnValue_Begin();
    _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_ReturnValue_Begin();
    _Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr = _trace->Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_ReturnValue_Begin();
    _Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr = _trace->Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_ReturnValue_Begin();
    _Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr = _trace->Rte_Read_SwcLceComManager_comCar_State_VEH_ST_ReturnValue_Begin();
    _Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr = _trace->Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_ReturnValue_Begin();
	    
    // Step through all milliseconds and dump written data for each
    for (unsigned time = 0; time <= _trace->getMaxTime(); ++time)
    {
    	writeAscData_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_Trace(time);
    	writeAscData_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_Trace(time);
    	writeAscData_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_Trace(time);
    	writeAscData_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_Trace(time);
    	writeAscData_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_Trace(time);
    	writeAscData_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_Trace(time);
    	writeAscData_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_Trace(time);
    }
    // Dump the last value at max time to have continous lines
    if(_trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_Trace_End() != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_Trace_Begin())
    {
    	_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_Trace_End();
    	--_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr;
    	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr->second < _trace->getMaxTime())
    	{
    		writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_Trace", 
    		sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr->first),_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr->first));   
    		}
    }
    if(_trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_Trace_End() != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_Trace_Begin())
    {
    	_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_Trace_End();
    	--_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr;
    	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr->second < _trace->getMaxTime())
    	{
    		writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_Trace", 
    		sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr->first),_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr->first));   
    		}
    }
    if(_trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_Trace_End() != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_Trace_Begin())
    {
    	_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_Trace_End();
    	--_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr;
    	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr->second < _trace->getMaxTime())
    	{
    		writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_Trace", 
    		sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr->first),_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr->first));   
    		}
    }
    if(_trace->Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_Trace_End() != _trace->Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_Trace_Begin())
    {
    	_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr = _trace->Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_Trace_End();
    	--_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr;
    	if(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr->second < _trace->getMaxTime())
    	{
    		writeAscDataFormatted("Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_Trace", 
    		sizeof(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr->first),_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr->first));   
    		}
    }
    if(_trace->Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_Trace_End() != _trace->Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_Trace_Begin())
    {
    	_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr = _trace->Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_Trace_End();
    	--_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr;
    	if(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr->second < _trace->getMaxTime())
    	{
    		writeAscDataFormatted("Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_Trace", 
    		sizeof(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr->first),_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr->first));   
    		}
    }
    if(_trace->Rte_Read_SwcLceComManager_comCar_State_VEH_ST_Trace_End() != _trace->Rte_Read_SwcLceComManager_comCar_State_VEH_ST_Trace_Begin())
    {
    	_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr = _trace->Rte_Read_SwcLceComManager_comCar_State_VEH_ST_Trace_End();
    	--_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr;
    	if(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr->second < _trace->getMaxTime())
    	{
    		writeAscDataFormatted("Rte_Read_SwcLceComManager_comCar_State_VEH_ST_Trace", 
    		sizeof(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr->first),_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr->first));   
    		}
    }
    if(_trace->Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_Trace_End() != _trace->Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_Trace_Begin())
    {
    	_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr = _trace->Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_Trace_End();
    	--_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr;
    	if(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr->second < _trace->getMaxTime())
    	{
    		writeAscDataFormatted("Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_Trace", 
    		sizeof(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr->first),_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr->first));   
    		}
    }
    /*
    */
    if(_trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_ReturnValue_End() != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_ReturnValue_Begin())
    {
    	_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_ReturnValue_End();
    	--_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr;
    	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr->second < _trace->getMaxTime()){
    		writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_ReturnValue", 
    		sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr->first),
    		_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr->first));  
    	}
    }
    if(_trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_ReturnValue_End() != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_ReturnValue_Begin())
    {
    	_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_ReturnValue_End();
    	--_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr;
    	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr->second < _trace->getMaxTime()){
    		writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_ReturnValue", 
    		sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr->first),
    		_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr->first));  
    	}
    }
    if(_trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_ReturnValue_End() != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_ReturnValue_Begin())
    {
    	_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr = _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_ReturnValue_End();
    	--_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr;
    	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr->second < _trace->getMaxTime()){
    		writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_ReturnValue", 
    		sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr->first),
    		_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr->first));  
    	}
    }
    if(_trace->Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_ReturnValue_End() != _trace->Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_ReturnValue_Begin())
    {
    	_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr = _trace->Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_ReturnValue_End();
    	--_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr;
    	if(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr->second < _trace->getMaxTime()){
    		writeAscDataFormatted("Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_ReturnValue", 
    		sizeof(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr->first),
    		_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr->first));  
    	}
    }
    if(_trace->Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_ReturnValue_End() != _trace->Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_ReturnValue_Begin())
    {
    	_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr = _trace->Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_ReturnValue_End();
    	--_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr;
    	if(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr->second < _trace->getMaxTime()){
    		writeAscDataFormatted("Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_ReturnValue", 
    		sizeof(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr->first),
    		_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr->first));  
    	}
    }
    if(_trace->Rte_Read_SwcLceComManager_comCar_State_VEH_ST_ReturnValue_End() != _trace->Rte_Read_SwcLceComManager_comCar_State_VEH_ST_ReturnValue_Begin())
    {
    	_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr = _trace->Rte_Read_SwcLceComManager_comCar_State_VEH_ST_ReturnValue_End();
    	--_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr;
    	if(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr->second < _trace->getMaxTime()){
    		writeAscDataFormatted("Rte_Read_SwcLceComManager_comCar_State_VEH_ST_ReturnValue", 
    		sizeof(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr->first),
    		_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr->first));  
    	}
    }
    if(_trace->Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_ReturnValue_End() != _trace->Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_ReturnValue_Begin())
    {
    	_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr = _trace->Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_ReturnValue_End();
    	--_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr;
    	if(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr->second < _trace->getMaxTime()){
    		writeAscDataFormatted("Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_ReturnValue", 
    		sizeof(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr->first),
    		_trace->getMaxTime(), 
    		NumberToHexString(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr->first));  
    	}
    }
 }   

void Rte_SwcLceComManager_CanoeTraceDump::writeAscData_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_Trace(unsigned time)
{
	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_Trace_End() && _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr->second == time)
	 {
	 	writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_Trace", 
	 	sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr->first),
	 	_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr->second, 
	 	NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr->first));
	 	++_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_BufItr;
	 }
	
	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_ReturnValue_End() && _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr->second == time)
	{
		writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_ReturnValue", 
		sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr->first),
		_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr->second, 
		NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr->first));
		++_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_returnValueItr;
	}
}
void Rte_SwcLceComManager_CanoeTraceDump::writeAscData_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_Trace(unsigned time)
{
	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_Trace_End() && _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr->second == time)
	 {
	 	writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_Trace", 
	 	sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr->first),
	 	_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr->second, 
	 	NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr->first));
	 	++_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_BufItr;
	 }
	
	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_ReturnValue_End() && _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr->second == time)
	{
		writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_ReturnValue", 
		sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr->first),
		_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr->second, 
		NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr->first));
		++_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_returnValueItr;
	}
}
void Rte_SwcLceComManager_CanoeTraceDump::writeAscData_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_Trace(unsigned time)
{
	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_Trace_End() && _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr->second == time)
	 {
	 	writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_Trace", 
	 	sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr->first),
	 	_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr->second, 
	 	NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr->first));
	 	++_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_BufItr;
	 }
	
	if(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr != _trace->Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_ReturnValue_End() && _Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr->second == time)
	{
		writeAscDataFormatted("Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_ReturnValue", 
		sizeof(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr->first),
		_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr->second, 
		NumberToHexString(_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr->first));
		++_Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_returnValueItr;
	}
}
void Rte_SwcLceComManager_CanoeTraceDump::writeAscData_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_Trace(unsigned time)
{
	if(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr != _trace->Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_Trace_End() && _Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr->second == time)
	 {
	 	writeAscDataFormatted("Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_Trace", 
	 	sizeof(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr->first),
	 	_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr->second, 
	 	NumberToHexString(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr->first));
	 	++_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_BufItr;
	 }
	
	if(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr != _trace->Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_ReturnValue_End() && _Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr->second == time)
	{
		writeAscDataFormatted("Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_ReturnValue", 
		sizeof(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr->first),
		_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr->second, 
		NumberToHexString(_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr->first));
		++_Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_returnValueItr;
	}
}
void Rte_SwcLceComManager_CanoeTraceDump::writeAscData_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_Trace(unsigned time)
{
	if(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr != _trace->Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_Trace_End() && _Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr->second == time)
	 {
	 	writeAscDataFormatted("Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_Trace", 
	 	sizeof(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr->first),
	 	_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr->second, 
	 	NumberToHexString(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr->first));
	 	++_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_BufItr;
	 }
	
	if(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr != _trace->Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_ReturnValue_End() && _Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr->second == time)
	{
		writeAscDataFormatted("Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_ReturnValue", 
		sizeof(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr->first),
		_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr->second, 
		NumberToHexString(_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr->first));
		++_Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_returnValueItr;
	}
}
void Rte_SwcLceComManager_CanoeTraceDump::writeAscData_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_Trace(unsigned time)
{
	if(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr != _trace->Rte_Read_SwcLceComManager_comCar_State_VEH_ST_Trace_End() && _Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr->second == time)
	 {
	 	writeAscDataFormatted("Rte_Read_SwcLceComManager_comCar_State_VEH_ST_Trace", 
	 	sizeof(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr->first),
	 	_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr->second, 
	 	NumberToHexString(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr->first));
	 	++_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_BufItr;
	 }
	
	if(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr != _trace->Rte_Read_SwcLceComManager_comCar_State_VEH_ST_ReturnValue_End() && _Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr->second == time)
	{
		writeAscDataFormatted("Rte_Read_SwcLceComManager_comCar_State_VEH_ST_ReturnValue", 
		sizeof(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr->first),
		_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr->second, 
		NumberToHexString(_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr->first));
		++_Rte_Read_SwcLceComManager_comCar_State_VEH_ST_returnValueItr;
	}
}
void Rte_SwcLceComManager_CanoeTraceDump::writeAscData_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_Trace(unsigned time)
{
	if(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr != _trace->Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_Trace_End() && _Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr->second == time)
	 {
	 	writeAscDataFormatted("Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_Trace", 
	 	sizeof(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr->first),
	 	_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr->second, 
	 	NumberToHexString(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr->first));
	 	++_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_BufItr;
	 }
	
	if(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr != _trace->Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_ReturnValue_End() && _Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr->second == time)
	{
		writeAscDataFormatted("Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_ReturnValue", 
		sizeof(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr->first),
		_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr->second, 
		NumberToHexString(_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr->first));
		++_Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_returnValueItr;
	}
}
// trace bodies for structs
// writers

void Rte_SwcLceComManager_CanoeTraceDump::generateDbcMap()
{
 	_dbcMap.clear();
 	unsigned int functionId = 0;
 // standard trace DBCs
	_dbcMap["Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_Trace"] = 
		 DbcAttributesType(++functionId, sizeof(IComLight_Ctrl_Inputs_CTR_FN_DR_Type), std::numeric_limits<IComLight_Ctrl_Inputs_CTR_FN_DR_Type>::is_signed);
	_dbcMap["Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_Trace"] = 
		 DbcAttributesType(++functionId, sizeof(IComLight_Ctrl_Inputs_CTR_FN_POS_Type), std::numeric_limits<IComLight_Ctrl_Inputs_CTR_FN_POS_Type>::is_signed);
	_dbcMap["Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_Trace"] = 
		 DbcAttributesType(++functionId, sizeof(IComLight_Ctrl_Inputs_CTR_FN_PAR_Type), std::numeric_limits<IComLight_Ctrl_Inputs_CTR_FN_PAR_Type>::is_signed);
	_dbcMap["Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_Trace"] = 
		 DbcAttributesType(++functionId, sizeof(IComLight_Ctrl_Inputs_ST_LP_LIN_Type), std::numeric_limits<IComLight_Ctrl_Inputs_ST_LP_LIN_Type>::is_signed);
	_dbcMap["Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_Trace"] = 
		 DbcAttributesType(++functionId, sizeof(IComBrightness_Rain_Sensor_ST_RB_LIN_Type), std::numeric_limits<IComBrightness_Rain_Sensor_ST_RB_LIN_Type>::is_signed);
	_dbcMap["Rte_Read_SwcLceComManager_comCar_State_VEH_ST_Trace"] = 
		 DbcAttributesType(++functionId, sizeof(IComCar_State_VEH_ST_Type), std::numeric_limits<IComCar_State_VEH_ST_Type>::is_signed);
	_dbcMap["Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_Trace"] = 
		 DbcAttributesType(++functionId, sizeof(IComMotor_Speed_Motor_Speed_Type), std::numeric_limits<IComMotor_Speed_Motor_Speed_Type>::is_signed);
 // array trace DBCs
 // record trace DBCs


// 
// standard trace RVs
	_dbcMap["Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_DR_ReturnValue"] = 
		DbcAttributesType(++functionId, sizeof(Std_ReturnType), std::numeric_limits<Std_ReturnType>::is_signed);
	_dbcMap["Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_POS_ReturnValue"] = 
		DbcAttributesType(++functionId, sizeof(Std_ReturnType), std::numeric_limits<Std_ReturnType>::is_signed);
	_dbcMap["Rte_Write_SwcLceComManager_comCTR_EL_F_CTR_FN_PAR_ReturnValue"] = 
		DbcAttributesType(++functionId, sizeof(Std_ReturnType), std::numeric_limits<Std_ReturnType>::is_signed);
	_dbcMap["Rte_Read_SwcLceComManager_comLight_Ctrl_Inputs_ST_LP_LIN_ReturnValue"] = 
		DbcAttributesType(++functionId, sizeof(Std_ReturnType), std::numeric_limits<Std_ReturnType>::is_signed);
	_dbcMap["Rte_Read_SwcLceComManager_comBrightness_Rain_Sensor_ST_RB_LIN_ReturnValue"] = 
		DbcAttributesType(++functionId, sizeof(Std_ReturnType), std::numeric_limits<Std_ReturnType>::is_signed);
	_dbcMap["Rte_Read_SwcLceComManager_comCar_State_VEH_ST_ReturnValue"] = 
		DbcAttributesType(++functionId, sizeof(Std_ReturnType), std::numeric_limits<Std_ReturnType>::is_signed);
	_dbcMap["Rte_Read_SwcLceComManager_comMotor_Speed_Motor_Speed_ReturnValue"] = 
		DbcAttributesType(++functionId, sizeof(Std_ReturnType), std::numeric_limits<Std_ReturnType>::is_signed);
// array trace RVs
// record trace RVs
 
	_sortedDbcEntries.clear();
	for(DbcMap_t::const_iterator it=_dbcMap.begin(); it!=_dbcMap.end(); ++it)
			_sortedDbcEntries.push_back(std::make_pair(it->first, it->second));

	std::sort(_sortedDbcEntries.begin(), _sortedDbcEntries.end(), 
	[](const DbcMapEntry_t& d1, const DbcMapEntry_t& d2) { return d1.second._id < d2.second._id; });
}

        std::string Rte_SwcLceComManager_CanoeTraceDump::formatTimestamp(unsigned timestamp) const
        {
            //Append leading zeros to timestamp to have at least seconds
            std::string s = NumberToString(timestamp);
            std::size_t length = s.size();
            if(length < 4)
            {
                for (int i = 4 - length; i > 0; --i)
                    s = "0" + s;
            }
            // Add second dot
            s.insert(static_cast<int>(s.size()) - 3, ".");
            return s;
        }
        std::string Rte_SwcLceComManager_CanoeTraceDump::formatDataBytes(unsigned int numberBytes, std::string hexValue) const
        {
            //Append leading zeros to have correct number of bytes
            int difference = (2*numberBytes) - static_cast<int>(hexValue.size());
            if (difference > 0)
            {
                for (int i = difference; i > 0; --i)
                {
                    hexValue = "0" + hexValue;
                }
            }
        
            // Add space after each byte
            int stringLength = static_cast<int>(hexValue.size());
            for (int sizeIndex = stringLength; sizeIndex >= 2; --sizeIndex)
            {
                if (sizeIndex != stringLength && sizeIndex % 2 == 0)
                {
                    hexValue.insert(sizeIndex, " ");
                } 
            }
            return hexValue;
        }

std::string Rte_SwcLceComManager_CanoeTraceDump::getSignalId(const std::string& signalName) const
{
    std::string signalID;
    DbcMap_t::const_iterator fcnIt = _dbcMap.find(signalName);
    if (fcnIt != _dbcMap.end())
        signalID = NumberToHexString(fcnIt->second._id);
    return signalID;
}

