cmake_minimum_required(VERSION 2.8)

project(MedianFilterImage)

set(MedianFilter_SOURCE MedianFilter.cxx)

SEMMacroBuildCLI(
  NAME MedianFilterImage
  EXECUTABLE_ONLY
  TARGET_LIBRARIES ${ITK_LIBRARIES}
  )





