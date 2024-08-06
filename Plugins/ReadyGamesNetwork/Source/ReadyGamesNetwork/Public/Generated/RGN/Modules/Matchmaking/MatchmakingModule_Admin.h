#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Utility/CancellationToken.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace Matchmaking {
    class MatchmakingModule_Admin {
    public:
        static void DeleteMatchesByAppIdAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& appIdToRemoveTheMatchesFor,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["appIdToRemoveTheMatchesFor"] = appIdToRemoveTheMatchesFor;
                RGNCore::CallAPI<nlohmann::json>(
                    "matchmaking-deleteAllMatchesForApp",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
    };
}}}