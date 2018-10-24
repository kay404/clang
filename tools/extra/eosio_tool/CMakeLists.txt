set(LLVM_LINK_COMPONENTS support)

include_directories(include)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/eosio-tool.cpp.in ${CMAKE_BINARY_DIR}/eosio-tool.cpp)

add_clang_executable(eosio-tool ${CMAKE_BINARY_DIR}/eosio-tool.cpp)
target_compile_options(eosio-tool PRIVATE -fexceptions)
target_include_directories(eosio-tool PUBLIC ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(eosio-tool PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tool_options.hpp.in ${CMAKE_BINARY_DIR}/tool_options.hpp)

install(FILES ${CMAKE_BINARY_DIR}/bin/eosio-tool DESTINATION ${CMAKE_INSTALL_BINDIR} PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
