cmake_minimum_required(VERSION 2.8)
if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif()

project(Filters)

#For tests 
include(CTest)
#For collect external data
include(ExternalData)

# Find SlicerExecutionModel
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

option(Erode_Filter_Binary_Image "Erode Filter Binary Image - with SEM" OFF)
option(Median_Filter_Image "Median Filter  - with SEM" OFF)
option(Own_Filter "Own Filter - with SEM" ON)
option(HelloWorld "HelloWorld - without SEM" ON)

if(Erode_Filter_Binary_Image)
  add_subdirectory(FilterErodeBinaryImage)
endif()
if(Median_Filter_Image)
  add_subdirectory(MedianFilterImage)
endif()
if(Own_Filter)
  add_subdirectory(OwnFilter)
endif()
if(HelloWorld)
  add_subdirectory(NotSEM)
endif()

