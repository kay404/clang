set(LLVM_LINK_COMPONENTS
  Support
  )

add_clang_unittest(SyntaxTests
  TreeTest.cpp
  TokensTest.cpp
)

clang_target_link_libraries(SyntaxTests
  PRIVATE
  clangAST
  clangBasic
  clangFrontend
  clangLex
  clangSerialization
  clangTooling
  clangToolingSyntax
  )

target_link_libraries(SyntaxTests
  PRIVATE
  LLVMTestingSupport
)
