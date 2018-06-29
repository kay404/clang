set(LLVM_LINK_COMPONENTS support)

find_package(Boost 1.67.0 REQUIRED system filesystem)
if(Boost_FOUND)
   include_directories (SYSTEM ${Boost_INCLUDE_DIR})
endif()

include_directories(include)

add_clang_executable(eosio.abigen ${CMAKE_CURRENT_SOURCE_DIR}/abi_generator.cpp)
target_compile_options(eosio.abigen PRIVATE -fexceptions)

target_link_libraries(eosio.abigen PRIVATE
  clangASTMatchers
  clangRewrite
  clangTooling
  clangToolingCore
  clangFrontend
  clangDriver
  clangSerialization
  clangParse
  clangSema
  clangAnalysis
  clangAST
  clangBasic
  clangEdit
  clangLex
  ${fc})

#install(FILES ${CMAKE_BINARY_DIR}/bin/eosio.cpp DESTINATION ${CMAKE_INSTALL_BINDIR} PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
#install(FILES ${CMAKE_BINARY_DIR}/bin/eosio.cc DESTINATION ${CMAKE_INSTALL_BINDIR} PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
