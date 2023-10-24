#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "CompletedAchievementHistoryEntry.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace RGN { namespace Modules { namespace Achievement {
    /**
     * Represents completed achievement data from the users data
     * If the achievement is  then
     * this document can contain more that one
     */
    struct UserAchievement {
        /**
         * Achievement document id
         */
        string id;
        /**
         * Current progress value of the achievement
         */
        int32_t value = 0;
        /**
         * Value which should be reached to complete the achievement when
         * the achievement was triggered
         */
        int32_t valueToReach = 0;
        /**
         * Shows if the achievement was completed
         */
        bool isCompleted = false;
        /**
         * Shows if the achievement was claimed
         */
        bool isClaimed = false;
        /**
         * Time when the achievement was last time completed
         * in milliseconds since midnight, January 1, 1970 UTC.
         * Refer to T:RGN.Utility.DateTimeUtility for helper methods.
         * This field is automatically populated by the backend
         */
        int64_t lastCompleteTime = 0;
        /**
         * Represents all times the user completed this achievement
         * This collection can contain more than 1 item in case the
         * F:RGN.Modules.Achievement.AchievementData.repeatable is true
         */
        vector<RGN::Modules::Achievement::CompletedAchievementHistoryEntry> history;

        friend void to_json(nlohmann::json& nlohmann_json_j, const UserAchievement& nlohmann_json_t) {
            nlohmann_json_j["id"] = nlohmann_json_t.id;
            nlohmann_json_j["value"] = nlohmann_json_t.value;
            nlohmann_json_j["valueToReach"] = nlohmann_json_t.valueToReach;
            nlohmann_json_j["isCompleted"] = nlohmann_json_t.isCompleted;
            nlohmann_json_j["isClaimed"] = nlohmann_json_t.isClaimed;
            nlohmann_json_j["lastCompleteTime"] = nlohmann_json_t.lastCompleteTime;
            nlohmann_json_j["history"] = nlohmann_json_t.history;
        }

        friend void from_json(const nlohmann::json& nlohmann_json_j, UserAchievement& nlohmann_json_t) {
            if (nlohmann_json_j.contains("id")) {
                auto json_id = nlohmann_json_j.at("id");
                if (!json_id.is_null() && json_id.is_string()) {
                    json_id.get_to(nlohmann_json_t.id);
                }
            }
            if (nlohmann_json_j.contains("value")) {
                auto json_value = nlohmann_json_j.at("value");
                if (!json_value.is_null() && json_value.is_number()) {
                    json_value.get_to(nlohmann_json_t.value);
                }
            }
            if (nlohmann_json_j.contains("valueToReach")) {
                auto json_valueToReach = nlohmann_json_j.at("valueToReach");
                if (!json_valueToReach.is_null() && json_valueToReach.is_number()) {
                    json_valueToReach.get_to(nlohmann_json_t.valueToReach);
                }
            }
            if (nlohmann_json_j.contains("isCompleted")) {
                auto json_isCompleted = nlohmann_json_j.at("isCompleted");
                if (!json_isCompleted.is_null() && json_isCompleted.is_boolean()) {
                    json_isCompleted.get_to(nlohmann_json_t.isCompleted);
                }
            }
            if (nlohmann_json_j.contains("isClaimed")) {
                auto json_isClaimed = nlohmann_json_j.at("isClaimed");
                if (!json_isClaimed.is_null() && json_isClaimed.is_boolean()) {
                    json_isClaimed.get_to(nlohmann_json_t.isClaimed);
                }
            }
            if (nlohmann_json_j.contains("lastCompleteTime")) {
                auto json_lastCompleteTime = nlohmann_json_j.at("lastCompleteTime");
                if (!json_lastCompleteTime.is_null() && json_lastCompleteTime.is_number()) {
                    json_lastCompleteTime.get_to(nlohmann_json_t.lastCompleteTime);
                }
            }
            if (nlohmann_json_j.contains("history")) {
                auto json_history = nlohmann_json_j.at("history");
                if (!json_history.is_null() && json_history.is_array()) {
                    json_history.get_to(nlohmann_json_t.history);
                }
            }
        }
    };
}}}