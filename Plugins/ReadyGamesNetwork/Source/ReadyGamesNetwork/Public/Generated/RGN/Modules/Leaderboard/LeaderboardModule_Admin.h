#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../CustomImpl/RGN/Modules/Leaderboard/LeaderboardModule_Admin.h"
#include "../../../../Utility/CancellationToken.h"
#include "LeaderboardData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace Leaderboard {
    class LeaderboardModule_Admin {
    public:
        static void AddLeaderboardAsync(
            const function<void(const RGN::Modules::Leaderboard::LeaderboardData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const RGN::Modules::Leaderboard::LeaderboardData& leaderboardData,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Leaderboard::LeaderboardModule_AdminCustomImpl::AddLeaderboardAsync(
                    success,
                    fail,
                    leaderboardData,
                    cancellationToken);
            };
        static void UpdateLeaderboardAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const RGN::Modules::Leaderboard::LeaderboardData& leaderboardData,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["data"] = leaderboardData;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "leaderboardV2-update",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["result"]["leaderboardId"].template get<string>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void DeleteLeaderboardAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["id"] = leaderboardId;
                RGNCore::CallAPI<nlohmann::json>(
                    "leaderboardV2-delete",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
    };
}}}