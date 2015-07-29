cmake_minimum_required(VERSION 2.8)

project(MultiThreadImageFilter) 

set(MultiThreadImageFilter_SOURCE MultiThreadImageFilterr.cxx)

SEMMacroBuildCLI(
  NAME MultiThreadImageFilter
  EXECUTABLE_ONLY
  TARGET_LIBRARIES ${ITK_LIBRARIES}
  )





