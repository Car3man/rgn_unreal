#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace RGN { namespace Modules { namespace Leaderboard {
    /**
     * A class that represents a leaderboard reward on Ready Games Network.
     */
    struct LeaderboardReward {
        /**
         * The place from users will be earned
         */
        int32_t placeFrom = 0;
        /**
         * The place to users will be earned
         */
        int32_t placeTo = 0;
        /**
         * Specifies reward, achievement contains virtual items reward, currency reward, etc
         */
        string achievementId;

        friend void to_json(nlohmann::json& nlohmann_json_j, const LeaderboardReward& nlohmann_json_t) {
            nlohmann_json_j["placeFrom"] = nlohmann_json_t.placeFrom;
            nlohmann_json_j["placeTo"] = nlohmann_json_t.placeTo;
            nlohmann_json_j["achievementId"] = nlohmann_json_t.achievementId;
        }

        friend void from_json(const nlohmann::json& nlohmann_json_j, LeaderboardReward& nlohmann_json_t) {
            if (nlohmann_json_j.contains("placeFrom")) {
                nlohmann_json_j.at("placeFrom").get_to(nlohmann_json_t.placeFrom);
            }
            if (nlohmann_json_j.contains("placeTo")) {
                nlohmann_json_j.at("placeTo").get_to(nlohmann_json_t.placeTo);
            }
            if (nlohmann_json_j.contains("achievementId")) {
                nlohmann_json_j.at("achievementId").get_to(nlohmann_json_t.achievementId);
            }
        }
    };
}}}