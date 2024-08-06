#pragma once

#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Generated/RGN/Modules/Leaderboard/LeaderboardData.h"
#include "../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardsResponse.h"
#include <string>

namespace RGN { namespace Modules { namespace Leaderboard {
	class LeaderboardModuleCustomImpl {
	public:
        static void GetLeaderboardForCurrentAppAsync(
            const function<void(const vector<RGN::Modules::Leaderboard::LeaderboardData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            CancellationToken cancellationToken = CancellationToken()) {
            nlohmann::json requestData;
            requestData["appId"] = RGNCore::GetAppId();
            requestData["appIds"] = {RGNCore::GetAppId()};
            requestData["limit"] = limit;
            requestData["startAfter"] = startAfter;
            requestData["ignoreTimestamp"] = ignoreTimestamp;
            RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::GetLeaderboardsResponse>(
                "leaderboardV2-getByAppIds",
                requestData,
                [success](const RGN::Modules::Leaderboard::GetLeaderboardsResponse& result) {
                    success(result.leaderboards);
                },
                fail,
                false, cancellationToken);
            }
	};
}}}
