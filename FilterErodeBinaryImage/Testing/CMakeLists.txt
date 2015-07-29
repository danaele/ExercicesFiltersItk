

add_executable(ErodeFilterTest FilterErodeItkTest.cxx)
target_link_libraries(ErodeFilterTest FilterErodeItkLib)

#Data link 
list( APPEND ExternalData_URL_TEMPLATES 
"http://slicer.kitware.com/midas3/api/rest?method=midas.bitstream.download&checksum=%(hash)")

set( referenceImage DATA{Data/yingyang.png} )
set( ImageErodeR3 DATA{Data/yingyang-erode3.png} )
set( ImageErodeR4 DATA{Data/yingyang-erode4.png} )


# Test checking that the program cannot run without arguments
add_test(
    NAME TestsErodewithoutArg
    COMMAND $<TARGET_FILE:FilterErodeItk>
  )
set_tests_properties(TestsErodewithoutArg PROPERTIES WILL_FAIL true)

#Data directory 
set(TEMP_DIR ${CMAKE_BINARY_DIR}/Testing/Temporary )


# Tests checking that the output image is what is expected
ExternalData_Add_Test( ErodeData NAME TestsErode2Dradius3
				COMMAND $<TARGET_FILE:ErodeFilterTest>
				 --compare
					${ImageErodeR3}
					${TEMP_DIR}/yingyang3.png
				 ModuleEntryPoint
					${referenceImage}
					${TEMP_DIR}/yingyang3.png
					-r 3
)				

# Tests checking that the output image is what is expected
ExternalData_Add_Test( ErodeData NAME TestsErode2Dradius4
				COMMAND $<TARGET_FILE:ErodeFilterTest>
				 --compare
					${ImageErodeR4}
					${TEMP_DIR}/yingyang4.png
				 ModuleEntryPoint
					${referenceImage}
					${TEMP_DIR}/yingyang4.png
					-r 4
)
# Add a build target to populate the real data.
ExternalData_Add_Target( ErodeData )


