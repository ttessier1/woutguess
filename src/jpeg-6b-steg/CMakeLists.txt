


# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

add_library(jpeg6b jcapimin.c jcapistd.c jccoefct.c jccolor.c jcdctmgr.c jchuff.c 
        jcinit.c jcmainct.c jcmarker.c jcmaster.c jcomapi.c jcparam.c 
        jcphuff.c jcprepct.c jcsample.c jctrans.c jdapimin.c jdapistd.c 
        jdatadst.c jdatasrc.c jdcoefct.c jdcolor.c jddctmgr.c jdhuff.c 
        jdinput.c jdmainct.c jdmarker.c jdmaster.c jdmerge.c jdphuff.c 
        jdpostct.c jdsample.c jdtrans.c jerror.c jfdctflt.c jfdctfst.c 
        jfdctint.c jidctflt.c jidctfst.c jidctint.c jidctred.c jquant1.c 
        jquant2.c jutils.c jmemmgr.c jmemnobs.c "config.h")

install(TARGETS fftw RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/lib")
include(GNUInstallDirs)
include(CPack)