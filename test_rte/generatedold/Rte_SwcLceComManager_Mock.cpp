/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_SwcLceComManager_Mock.cpp
 ********************************************************************/

#include "Rte_SwcLceComManager_Mock.h"
#include "gmock/gmock.h"

using ::testing::_;

Rte_SwcLceComManager_Mock::Rte_SwcLceComManager_Mock() : Rte_SwcLceComManager_Interface()
{
    Rte_SwcLceComManager_Mock::reinitialize();
}
Rte_SwcLceComManager_Mock::~Rte_SwcLceComManager_Mock() 
{
}
void Rte_SwcLceComManager_Mock::reinitialize()
{
    connectIrvs();
}

void Rte_SwcLceComManager_Mock::connectIrvs()
{
    // connect IRV writers to reader methods:
}
