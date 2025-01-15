# Define the core library
add_library(MSAFCore)

# Add the public headers as an include directory
target_include_directories(MSAFCore
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${MSAF_INSTALL_INCLUDE_DIR}>
)

set_target_properties(MSAFCore PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Get the source files (i.e. all *.c/*.cpp files) for SVF's subprojects and add them to SvfCore
file(GLOB_RECURSE MSAF_CORE_SOURCES lib/*.cpp)
target_sources(MSAFCore PRIVATE ${MSAF_CORE_SOURCES})

# Get all of the public header files (i.e. all *.h/*.hpp files) for SVF's subprojects and add them
file(GLOB_RECURSE MSAF_CORE_HEADERS include/*.h include/*.hpp)

target_sources(MSAFCore
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES ${MSAF_CORE_HEADERS}
)

# Install the headers and compiled libraries (associate MSAFCore with the package's targets)
install(
    TARGETS MSAFCore
    EXPORT MSAFTargets
    RUNTIME DESTINATION ${MSAF_INSTALL_BIN_DIR}
    LIBRARY DESTINATION ${MSAF_INSTALL_LIB_DIR}
    ARCHIVE DESTINATION ${MSAF_INSTALL_LIB_DIR}
    FILE_SET HEADERS DESTINATION ${MSAF_INSTALL_INCLUDE_DIR}
)
