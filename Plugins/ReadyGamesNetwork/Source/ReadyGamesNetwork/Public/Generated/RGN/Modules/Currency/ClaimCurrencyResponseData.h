#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "Currency.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace RGN { namespace Modules { namespace Currency {
    struct ClaimCurrencyResponseData {
        bool isSuccess = false;
        vector<RGN::Modules::Currency::Currency> unclaimedCurrencies;
        vector<RGN::Modules::Currency::Currency> currencies;

        friend void to_json(nlohmann::json& nlohmann_json_j, const ClaimCurrencyResponseData& nlohmann_json_t) {
            nlohmann_json_j["isSuccess"] = nlohmann_json_t.isSuccess;
            nlohmann_json_j["unclaimedCurrencies"] = nlohmann_json_t.unclaimedCurrencies;
            nlohmann_json_j["currencies"] = nlohmann_json_t.currencies;
        }

        friend void from_json(const nlohmann::json& nlohmann_json_j, ClaimCurrencyResponseData& nlohmann_json_t) {
            if (nlohmann_json_j.contains("isSuccess")) {
                auto json_isSuccess = nlohmann_json_j.at("isSuccess");
                if (!json_isSuccess.is_null() && json_isSuccess.is_boolean()) {
                    json_isSuccess.get_to(nlohmann_json_t.isSuccess);
                }
            }
            if (nlohmann_json_j.contains("unclaimedCurrencies")) {
                auto json_unclaimedCurrencies = nlohmann_json_j.at("unclaimedCurrencies");
                if (!json_unclaimedCurrencies.is_null() && json_unclaimedCurrencies.is_array()) {
                    json_unclaimedCurrencies.get_to(nlohmann_json_t.unclaimedCurrencies);
                }
            }
            if (nlohmann_json_j.contains("currencies")) {
                auto json_currencies = nlohmann_json_j.at("currencies");
                if (!json_currencies.is_null() && json_currencies.is_array()) {
                    json_currencies.get_to(nlohmann_json_t.currencies);
                }
            }
        }
    };
}}}