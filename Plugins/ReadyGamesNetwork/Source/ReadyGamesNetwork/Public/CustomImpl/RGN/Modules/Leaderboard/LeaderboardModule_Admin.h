#pragma once

#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Generated/RGN/Modules/Leaderboard/LeaderboardData.h"
#include <string>

namespace RGN { namespace Modules { namespace Leaderboard {
	class LeaderboardModule_AdminCustomImpl {
	public:
        static void AddLeaderboardAsync(
            const function<void(const RGN::Modules::Leaderboard::LeaderboardData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const RGN::Modules::Leaderboard::LeaderboardData& leaderboardData,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["data"] = leaderboardData;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "leaderboardV2-add",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["result"]["leaderboard"].template get<RGN::Modules::Leaderboard::LeaderboardData>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
	};
}}}
