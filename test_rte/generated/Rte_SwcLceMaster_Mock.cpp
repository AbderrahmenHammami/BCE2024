/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_SwcLceMaster_Mock.cpp
 ********************************************************************/

#include "Rte_SwcLceMaster_Mock.h"
#include "gmock/gmock.h"

using ::testing::_;

Rte_SwcLceMaster_Mock::Rte_SwcLceMaster_Mock() : Rte_SwcLceMaster_Interface()
{
    Rte_SwcLceMaster_Mock::reinitialize();
}
Rte_SwcLceMaster_Mock::~Rte_SwcLceMaster_Mock() 
{
}
void Rte_SwcLceMaster_Mock::reinitialize()
{
    connectIrvs();
}

void Rte_SwcLceMaster_Mock::connectIrvs()
{
    // connect IRV writers to reader methods:
}