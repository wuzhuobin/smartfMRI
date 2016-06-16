cmake_minimum_required(VERSION 2.8.11)
project(SmartfMRI)

find_package(Qt5 COMPONENTS Widgets
)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SOURCES 
	main.cpp
	keyconfirm.cpp
	MacEncoding.cpp
	iphelper/getmacadd.cpp
	smartfmri.cpp
	experiment.cpp
	experimentmanager.cpp
	experimentmap.cpp
	experimentmodel.cpp
	experimentstatus.cpp
	logfiledata.cpp
	statusthread.cpp
	qcopydirrecursively.cpp
	scanparameters.cpp
	scanparametersmodel.cpp	
	smartfMRI.rc
)

#qt5_wrap_cpp( WC ${SOURCES})

qt5_wrap_ui(WRAP_UI
	experimentstatus.ui
	experimentmanager.ui
	smartfmri.ui
	keyconfirm.ui
)
qt5_add_resources(RESOUCES smartfmri.qrc)


include_directories(${Qt5Widgets_INCLUDES})
add_definitions(${Qt5Widgets_DEFINITIONS})

add_executable(SmartfMRI WIN32 ${SOURCES} ${WRAP_UI} ${RESOUCES})

target_link_libraries(SmartfMRI
	${Qt5Widgets_LIBRARIES}
	IPHLPAPI.LIB
	)
	
IF(WIN32) # Check if we are on Windows
  if(MSVC) # Check if we are using the Visual Studio compiler
   set_target_properties(SmartfMRI PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
   set_target_properties(SmartfMRI PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
   set_target_properties(SmartfMRI PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
   set_target_properties(SmartfMRI PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS")
  elseif(CMAKE_COMPILER_IS_GNUCXX)
    # SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
  else()
    message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
  endif()
elseif(UNIX)
  # Nothing special required
else()
  message(SEND_ERROR "You are on an unsupported platform! (Not Win32 or Unix)")
ENDIF()
	
	
#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

