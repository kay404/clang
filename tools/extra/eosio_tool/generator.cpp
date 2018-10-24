#include "generator.hpp"

namespace eosio { namespace cdt {

   abigen_exception abigen_ex;

   DeclarationMatcher function_decl_matcher = cxxMethodDecl().bind("eosio");
   DeclarationMatcher record_decl_matcher   = cxxRecordDecl().bind("eosio");
   DeclarationMatcher typedef_decl_matcher  = typedefDecl().bind("eosio");
   DeclarationMatcher class_tmp_matcher     = classTemplateSpecializationDecl().bind("eosio");

   abigen& get_abigen_ref() {
      static abigen ag;
      return ag;
   }
}} //ns eosio::cdt
