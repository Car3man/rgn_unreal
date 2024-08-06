#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Utility/CancellationToken.h"
#include "GamePassData.h"
#include "GamePassUserData.h"
#include "GetGamePassUserDataResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace GamePass {
    class GamePassModule_Admin {
    public:
        static void AddAsync(
            const function<void(const RGN::Modules::GamePass::GamePassData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const RGN::Modules::GamePass::GamePassData& gamepassData,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::GamePass::GamePassData requestData;
                RGNCore::CallAPI<RGN::Modules::GamePass::GamePassData, RGN::Modules::GamePass::GamePassData>(
                    "gamePass-add",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void DeleteAsync(
            const function<void(const RGN::Modules::GamePass::GamePassData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& id = "",
            const string& requestName = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["id"] = id;
                requestData["requestName"] = requestName;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::GamePass::GamePassData>(
                    "gamePass-delete",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void AddToUserAsync(
            const function<void(const RGN::Modules::GamePass::GamePassUserData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& id = "",
            const string& requestName = "",
            const string& userId = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["id"] = id;
                requestData["requestName"] = requestName;
                requestData["userId"] = userId;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::GamePass::GamePassUserData>(
                    "gamePass-addToUser",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void DeleteFromUserAsync(
            const function<void(const vector<RGN::Modules::GamePass::GamePassUserData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& id = "",
            const string& requestName = "",
            const string& userId = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["id"] = id;
                requestData["requestName"] = requestName;
                requestData["userId"] = userId;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::GamePass::GetGamePassUserDataResponseData>(
                    "gamePass-deleteFromUser",
                    requestData,
                    [success] (const RGN::Modules::GamePass::GetGamePassUserDataResponseData& result) {
                        success(result.gamePasses);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
    };
}}}