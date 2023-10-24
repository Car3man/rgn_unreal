#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "RGNWallet.h"
#include "../../Model/Response/BaseResponseData.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace RGN { namespace Modules { namespace Wallets {
    struct GetUserWalletsResponseData : public RGN::Model::Response::BaseResponseData {
        vector<RGN::Modules::Wallets::RGNWallet> wallets;

        friend void to_json(nlohmann::json& nlohmann_json_j, const GetUserWalletsResponseData& nlohmann_json_t) {
            nlohmann_json_j["status"] = nlohmann_json_t.status;
            nlohmann_json_j["message"] = nlohmann_json_t.message;
            nlohmann_json_j["wallets"] = nlohmann_json_t.wallets;
        }

        friend void from_json(const nlohmann::json& nlohmann_json_j, GetUserWalletsResponseData& nlohmann_json_t) {
            if (nlohmann_json_j.contains("status")) {
                auto json_status = nlohmann_json_j.at("status");
                if (!json_status.is_null() && json_status.is_number()) {
                    json_status.get_to(nlohmann_json_t.status);
                }
            }
            if (nlohmann_json_j.contains("message")) {
                auto json_message = nlohmann_json_j.at("message");
                if (!json_message.is_null() && json_message.is_string()) {
                    json_message.get_to(nlohmann_json_t.message);
                }
            }
            if (nlohmann_json_j.contains("wallets")) {
                auto json_wallets = nlohmann_json_j.at("wallets");
                if (!json_wallets.is_null() && json_wallets.is_array()) {
                    json_wallets.get_to(nlohmann_json_t.wallets);
                }
            }
        }
    };
}}}