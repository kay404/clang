set(EOSIO_VER_MAJOR "1")
set(EOSIO_VER_MINOR "0")
set(EOSIO_VER_REVISION "0")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/fc/CMakeModules")
set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.67.0 REQUIRED system filesystem)
if(Boost_FOUND)
   include_directories (SYSTEM ${Boost_INCLUDE_DIR})
endif()

add_subdirectory(fc)

target_compile_options(fc PRIVATE -fexceptions)

add_subdirectory(eosio_c_tool)
add_subdirectory(eosio_ld_tool)
add_subdirectory(abi_gen_tool)

set(EOSIO_STACK_SIZE "8192")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/compiler_options.ipp.in ${CMAKE_BINARY_DIR}/compiler_options.ipp)


