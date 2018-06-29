#pragma once

//#include <eosio/chain/authority.hpp>
//#include <eosio/chain/chain_config.hpp>
//#include <eosio/chain/config.hpp>
#include "types.hpp"

namespace eosio { namespace chain {

using action_name    = eosio::chain::action_name;

struct newaccount {
   account_name                     creator;
   account_name                     name;
   authority                        owner;
   authority                        active;
};

struct setcode {
   account_name                     account;
   uint8_t                          vmtype = 0;
   uint8_t                          vmversion = 0;
   bytes                            code;
};

struct setabi {
   account_name                     account;
   bytes                            abi;
};


struct updateauth {
   account_name                      account;
   permission_name                   permission;
   permission_name                   parent;
   authority                         auth;
};

struct deleteauth {
   account_name                      account;
   permission_name                   permission;
};

struct linkauth {
   account_name                      account;
   account_name                      code;
   action_name                       type;
   permission_name                   requirement;
};

struct unlinkauth {
   account_name                      account;
   account_name                      code;
   action_name                       type;
};

struct canceldelay {
   permission_level      canceling_auth;
   transaction_id_type   trx_id;
};

struct onerror {
   uint128_t      sender_id;
   bytes          sent_trx;
};

} } /// namespace eosio::chain

FC_REFLECT( eosio::chain::newaccount                       , (creator)(name)(owner)(active) )
FC_REFLECT( eosio::chain::setcode                          , (account)(vmtype)(vmversion)(code) )
FC_REFLECT( eosio::chain::setabi                           , (account)(abi) )
FC_REFLECT( eosio::chain::updateauth                       , (account)(permission)(parent)(auth) )
FC_REFLECT( eosio::chain::deleteauth                       , (account)(permission) )
FC_REFLECT( eosio::chain::linkauth                         , (account)(code)(type)(requirement) )
FC_REFLECT( eosio::chain::unlinkauth                       , (account)(code)(type) )
FC_REFLECT( eosio::chain::canceldelay                      , (canceling_auth)(trx_id) )
FC_REFLECT( eosio::chain::onerror                          , (sender_id)(sent_trx) )
