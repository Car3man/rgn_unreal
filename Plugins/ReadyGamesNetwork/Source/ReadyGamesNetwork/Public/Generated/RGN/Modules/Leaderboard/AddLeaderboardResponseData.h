#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "LeaderboardData.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace RGN { namespace Modules { namespace Leaderboard {
    struct AddLeaderboardResponseData {
        string leaderboardId;
        RGN::Modules::Leaderboard::LeaderboardData leaderboard;

        friend void to_json(nlohmann::json& nlohmann_json_j, const AddLeaderboardResponseData& nlohmann_json_t) {
            nlohmann_json_j["leaderboardId"] = nlohmann_json_t.leaderboardId;
            nlohmann_json_j["leaderboard"] = nlohmann_json_t.leaderboard;
        }

        friend void from_json(const nlohmann::json& nlohmann_json_j, AddLeaderboardResponseData& nlohmann_json_t) {
            if (nlohmann_json_j.contains("leaderboardId")) {
                auto json_leaderboardId = nlohmann_json_j.at("leaderboardId");
                if (!json_leaderboardId.is_null() && json_leaderboardId.is_string()) {
                    json_leaderboardId.get_to(nlohmann_json_t.leaderboardId);
                }
            }
            if (nlohmann_json_j.contains("leaderboard")) {
                auto json_leaderboard = nlohmann_json_j.at("leaderboard");
                if (!json_leaderboard.is_null()) {
                    json_leaderboard.get_to(nlohmann_json_t.leaderboard);
                }
            }
        }
    };
}}}