#add include to directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
#set the proper macros
set(LIBRARY_NAME libMathOwn)
set(SRC_FILES libMathOwn.c)
set(INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../include/libMathOwn.h)
#add the library
add_library(${LIBRARY_NAME} SHARED ${SRC_FILES} ${INCLUDE_FILES})
#installing the library
install (TARGETS ${LIBRARY_NAME} DESTINATION lib)
install (FILES ${INCLUDE_FILES} DESTINATION include)
