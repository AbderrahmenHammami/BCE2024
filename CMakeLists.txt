include(${CMAKE_CURRENT_LIST_DIR}/lib/gtest/CMakeLists.txt)

## Add library for SwcLceComManager
include(${PROJECT_SOURCE_DIR}/apps/light/lce/swc_lce_com_manager/CMakeSourceLists.txt)
add_library(gtest_swc_lce_com_manager_sut STATIC ${SwcLceComManager_headerFiles} ${SwcLceComManager_sourceFiles})
include(./CMakeSourceLists.txt)
add_library(gmock_rte_SwcLceComManager STATIC ${SwcLceComManager_TestRTE_headerFiles} ${SwcLceComManager_TestRTE_sourceFiles})
target_link_libraries(gtest_swc_lce_com_manager_sut PUBLIC gmock_rte_SwcLceComManager)

## Add library for SwcLceMaster
include(${PROJECT_SOURCE_DIR}/apps/light/lce/swc_lce_master/CMakeSourceLists.txt)
add_library(gtest_swc_lce_master_sut STATIC ${SwcLceMaster_headerFiles} ${SwcLceMaster_sourceFiles})
include(./CMakeSourceLists.txt)
add_library(gmock_rte_SwcLceMaster STATIC ${SwcLceMaster_TestRTE_headerFiles} ${SwcLceMaster_TestRTE_sourceFiles})
target_link_libraries(gtest_swc_lce_master_sut PUBLIC gmock_rte_SwcLceMaster)


include_directories(
include
${PROJECT_SOURCE_DIR}/test_rte/generated
)