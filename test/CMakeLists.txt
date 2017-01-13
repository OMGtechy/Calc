CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

PROJECT(Calc)

ADD_EXECUTABLE(
    Calc
    source/tokenise.cpp
)

INCLUDE_DIRECTORIES(
    Calc
    include
    ../include
)

IF(NOT WIN32)
    TARGET_LINK_LIBRARIES(
        Calc
        pthread
    ) 

    IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
        TARGET_LINK_LIBRARIES(
	    Calc
	    gcov asan
	)
    ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)
ENDIF(NOT WIN32)

TARGET_COMPILE_FEATURES(
    Calc
    PRIVATE
    cxx_relaxed_constexpr
)

SET_PROPERTY(
    TARGET Calc 
    APPEND_STRING PROPERTY COMPILE_FLAGS
    "-Wall -Werror"
)

IF(NOT WIN32)
    IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
        SET_PROPERTY(
            TARGET Calc 
            APPEND_STRING PROPERTY COMPILE_FLAGS
            " -fsanitize=address --coverage"
        )
    ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)
ENDIF()

