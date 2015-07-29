cmake_minimum_required(VERSION 2.8)

project(FilterErodeItk)

set(FilterErodeItk FilterErodeItk.cxx)

SEMMacroBuildCLI(
  NAME FilterErodeItk
  EXECUTABLE_ONLY
  TARGET_LIBRARIES ${ITK_LIBRARIES}
  )

#add_library(FilterErodeItkLib2 FilterErodeItk.cxx ${CMAKE_CURRENT_BINARY_DIR}/FilterErodeItkCLP.h )
#target_link_libraries(FilterErodeItkLib2 ${ITK_LIBRARIES})
#set_target_properties(FilterErodeItkLib2 PROPERTIES COMPILE_FLAGS "-Dmain=ModuleEntryPoint")

option(BUILD_TESTING "Build the testing tree" ON)

IF(BUILD_TESTING)
  add_subdirectory(Testing)
ENDIF(BUILD_TESTING)


