#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace RGN { namespace Modules { namespace Wallets {
    struct CreateWalletResponseData {
        string address;
        bool wallet_created = false;
        bool success = false;
        string error;

        friend void to_json(nlohmann::json& nlohmann_json_j, const CreateWalletResponseData& nlohmann_json_t) {
            nlohmann_json_j["address"] = nlohmann_json_t.address;
            nlohmann_json_j["wallet_created"] = nlohmann_json_t.wallet_created;
            nlohmann_json_j["success"] = nlohmann_json_t.success;
            nlohmann_json_j["error"] = nlohmann_json_t.error;
        }

        friend void from_json(const nlohmann::json& nlohmann_json_j, CreateWalletResponseData& nlohmann_json_t) {
            if (nlohmann_json_j.contains("address")) {
                auto json_address = nlohmann_json_j.at("address");
                if (!json_address.is_null() && json_address.is_string()) {
                    json_address.get_to(nlohmann_json_t.address);
                }
            }
            if (nlohmann_json_j.contains("wallet_created")) {
                auto json_wallet_created = nlohmann_json_j.at("wallet_created");
                if (!json_wallet_created.is_null() && json_wallet_created.is_boolean()) {
                    json_wallet_created.get_to(nlohmann_json_t.wallet_created);
                }
            }
            if (nlohmann_json_j.contains("success")) {
                auto json_success = nlohmann_json_j.at("success");
                if (!json_success.is_null() && json_success.is_boolean()) {
                    json_success.get_to(nlohmann_json_t.success);
                }
            }
            if (nlohmann_json_j.contains("error")) {
                auto json_error = nlohmann_json_j.at("error");
                if (!json_error.is_null() && json_error.is_string()) {
                    json_error.get_to(nlohmann_json_t.error);
                }
            }
        }
    };
}}}