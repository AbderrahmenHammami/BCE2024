/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_SwcLceMaster_Mock.h
 ********************************************************************/

#ifndef RTE_SWCLCEMASTER_MOCK_H_
#define RTE_SWCLCEMASTER_MOCK_H_

#include "Rte_SwcLceMaster_Interface.h"
#include <gmock/gmock.h>

/** Set delegation interface to mock. */
void Rte_SwcLceMaster_Mock_Set(Rte_SwcLceMaster_Interface* pRteMock);

// Mock class for RTE.
class Rte_SwcLceMaster_Mock : public Rte_SwcLceMaster_Interface
{
    public:
    Rte_SwcLceMaster_Mock();

    // Define destructor in cpp to speedup compilation.
    virtual ~Rte_SwcLceMaster_Mock();
    
    MOCK_METHOD1(Rte_Read_SwcLceMaster_Light_Ctrl_Inputs_ST_LP_LIN, Std_ReturnType(IComLight_Ctrl_Inputs_ST_LP_LIN_Type* ST_LP_LIN));
    
    MOCK_METHOD1(Rte_Read_SwcLceMaster_Brightness_Rain_Sensor_ST_RB_LIN, Std_ReturnType(IComBrightness_Rain_Sensor_ST_RB_LIN_Type* ST_RB_LIN));
    
    MOCK_METHOD1(Rte_Read_SwcLceMaster_Car_State_VEH_ST, Std_ReturnType(IComCar_State_VEH_ST_Type* VEH_ST));
    
    MOCK_METHOD1(Rte_Read_SwcLceMaster_Motor_Speed_Motor_Speed, Std_ReturnType(IComMotor_Speed_Motor_Speed_Type* Motor_Speed));
    
    virtual void reinitialize();
    
    protected:
    void connectIrvs();
    
    // Propagate inter runnable variable values to the readers.
    
};

#endif /* RTE_SWCLCEMASTER_MOCK_H_ */    