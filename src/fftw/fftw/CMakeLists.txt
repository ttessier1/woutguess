# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("fftw")

add_library("fftw" STATIC 
	fn_1.c fn_2.c fn_3.c fn_4.c fn_5.c fn_6.c fn_7.c fn_8.c fn_9.c fn_10.c fn_11.c fn_12.c fn_13.c fn_14.c fn_15.c fn_16.c fn_32.c fn_64.c
	ftw_2.c ftw_3.c ftw_4.c ftw_5.c ftw_6.c ftw_7.c ftw_8.c ftw_9.c ftw_10.c ftw_16.c ftw_32.c ftw_64.c
	fni_1.c fni_2.c fni_3.c fni_4.c fni_5.c fni_6.c fni_7.c fni_8.c fni_9.c fni_10.c fni_11.c fni_12.c fni_13.c fni_14.c fni_15.c fni_16.c fni_32.c fni_64.c
	ftwi_2.c ftwi_3.c ftwi_4.c ftwi_5.c ftwi_6.c ftwi_7.c ftwi_8.c ftwi_9.c ftwi_10.c ftwi_16.c ftwi_32.c ftwi_64.c
	timer.c config.c planner.c twiddle.c executor.c generic.c fftwnd.c malloc.c wisdom.c wisdomio.c putils.c rader.c fftwf77.c )
IF (!WIN32)
target_link_libraries("fftw" PUBLIC m)
ENDIF()
install(TARGETS fftw RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/lib")
include(GNUInstallDirs)
include(CPack)

#nstall(TARGETS fftw RUNTIME DESTINATION "lib")


#set_target_properties(fftw PROPERTIES PUBLIC_HEADER fftw.h)
#set_target_properties(fftw PROPERTIES PRIVATE_HEADER fftw-int.h)
#include(GNUInstallDirs)

#include(CPack)
#file(ARCHIVE_CREATE OUTPUT "fftw.zip" PATHS "${CMAKE_CURRENT_SOURCE_DIR}/lib/fftw.lib" FORMAT "zip")
#install(TARGETS fftw PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/fftw)
#install(FILE fftw.lib LIB DESTINATION ${CMAKE_INSTALL_LIBDIR}/fftw)

