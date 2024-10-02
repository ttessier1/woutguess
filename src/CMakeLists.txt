# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()



add_subdirectory("fftw")

add_subdirectory("jpeg-6b-steg")

project("woutguess" C)

set(JPEG6_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/src/jpeg-6b-steg")
set(FFTW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/src/fftw/fftw")
set(RFFTW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/src/fftw/rfftw")

set(HEADER_FILES ${JPEG6_INCLUDE_DIR}/jpeglib.h ${FFTW_INCLUDE_DIR}/fftw.h ${RFFTW_INCLUDE_DIR}/rfftw.h)

add_executable(woutguess outguess.c outguess.h pnm.c pnm.h md5.c md5.h jpg.c jpg.h iterator.c iterator.h golay.h golay.c fourier.c fourier.h err.c err.h arc.c arc.h util.c util.h "config.h" ${HEADER_FILES})

add_executable(histogram histogram.c outguess.h pnm.c pnm.h md5.c md5.h jpg.c jpg.h iterator.c iterator.h golay.h golay.c fourier.c fourier.h err.c err.h arc.c arc.h util.c util.h "config.h" ${HEADER_FILES})

#add_library(fftw STATIC IMPORTED) # or STATIC instead of SHARED
#set_target_properties(fftw PROPERTIES 
# IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/fftw.lib"
#INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include"
# )
#add_library(jpeg6b STATIC IMPORTED) # or STATIC instead of SHARED
#set_target_properties(jpeg6b PROPERTIES 
#IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/jpeg6b.lib"
#INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include"
#)

#add_library(rfftw STATIC IMPORTED) # or STATIC instead of SHARED
#set_target_properties(rfftw PROPERTIES 
#IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/rfftw.lib"
#INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include"
#)

target_link_libraries(woutguess fftw)
#target_link_libraries(woutguess rfftw)
target_link_libraries(woutguess jpeg6b)
IF (!WIN32)
target_link_libraries("woutguess" PUBLIC m)
ENDIF()

target_link_libraries(histogram fftw)
#target_link_libraries(histogram rfftw)
target_link_libraries(histogram jpeg6b)

target_include_directories(woutguess PRIVATE ${JPEG6_INCLUDE_DIR} ${FFTW_INCLUDE_DIR} ${RFFTW_INCLUDE_DIR})

target_include_directories(histogram PRIVATE ${JPEG6_INCLUDE_DIR} ${FFTW_INCLUDE_DIR} ${RFFTW_INCLUDE_DIR})

message(CMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}")
message(JPEG6_INCLUDE_DIR="${JPEG6_INCLUDE_DIR}")
message(FFTW_INCLUDE_DIR="${FFTW_INCLUDE_DIR}")
message(RFFTW_INCLUDE_DIR="${RFFTW_INCLUDE_DIR}")
message(HEADER_FILES="${HEADER_FILES}")

