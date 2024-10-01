# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("rfftw")

add_library("rfftw" STATIC 
	
frc_1.c frc_2.c frc_3.c frc_4.c frc_5.c frc_6.c frc_7.c frc_8.c frc_9.c frc_10.c frc_11.c frc_12.c frc_13.c frc_14.c frc_15.c frc_16.c frc_32.c frc_64.c frc_128.c
fhf_2.c fhf_3.c fhf_4.c fhf_5.c fhf_6.c fhf_7.c fhf_8.c fhf_9.c fhf_10.c fhf_16.c fhf_32.c
fcr_1.c fcr_2.c fcr_3.c fcr_4.c fcr_5.c fcr_6.c fcr_7.c fcr_8.c fcr_9.c fcr_10.c fcr_11.c fcr_12.c fcr_13.c fcr_14.c fcr_15.c fcr_16.c fcr_32.c fcr_64.c fcr_128.c
fhb_2.c fhb_3.c fhb_4.c fhb_5.c fhb_6.c fhb_7.c fhb_8.c fhb_9.c fhb_10.c fhb_16.c fhb_32.c
rconfig.c rplanner.c rexec.c rexec2.c rfftwnd.c rgeneric.c rfftwf77.c)



install(TARGETS fftw RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/lib")
include(GNUInstallDirs)
include(CPack)

#set_target_properties(fftw PROPERTIES PUBLIC_HEADER fftw.h)
#set_target_properties(fftw PROPERTIES PRIVATE_HEADER fftw-int.h)
#include(GNUInstallDirs)

#include(CPack)
#file(ARCHIVE_CREATE OUTPUT "fftw.zip" PATHS "${CMAKE_CURRENT_SOURCE_DIR}/lib/fftw.lib" FORMAT "zip")
#install(TARGETS fftw PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/fftw)
#install(FILE fftw.lib LIB DESTINATION ${CMAKE_INSTALL_LIBDIR}/fftw)

