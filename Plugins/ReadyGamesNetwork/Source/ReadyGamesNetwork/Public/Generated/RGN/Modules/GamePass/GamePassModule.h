#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Utility/CancellationToken.h"
#include "GamePassData.h"
#include "GetForCurrentAppResponseData.h"
#include "../../Model/Request/BaseRequestData.h"
#include "GetGamePassUserDataResponseData.h"
#include "GamePassUserData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace GamePass {
    class GamePassModule {
    public:
        /**
         * Retrieves a GamePassData instance asynchronously based on the provided identifier or request name.
         * @param id - The unique identifier for the game pass to retrieve. Optional.
         * @param requestName - The request name associated with the game pass to retrieve. Optional.
         * @param cancellationToken - A token to cancel the operation.
         * @return The requested GamePassData instance.
         */
        static void GetAsync(
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
                    "gamePass-get",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Retrieves a list of GamePassData instances for the current application asynchronously.
         * @param cancellationToken - A token to cancel the operation.
         * @return A list of GamePassData associated with the current application.
         */
        static void GetForCurrentAppAsync(
            const function<void(const vector<RGN::Modules::GamePass::GamePassData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Model::Request::BaseRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseRequestData, RGN::Modules::GamePass::GetForCurrentAppResponseData>(
                    "gamePass-getForApp",
                    requestData,
                    [success] (const RGN::Modules::GamePass::GetForCurrentAppResponseData& result) {
                        success(result.gamePasses);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Retrieves a list of GamePassUserData instances for a user based on the provided identifier or request name.
         * @param id - The game pass identifier to retrieve for the user. Optional.
         * @param requestName - The request name associated with the game pass. Optional.
         * @param userId - The identifier of the user to retrieve game passes for. Optional.
         * @param cancellationToken - A token to cancel the operation.
         * @return A list of GamePassUserData instances for the specified user.
         */
        static void GetForUserAsync(
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
                    "gamePass-getForUser",
                    requestData,
                    [success] (const RGN::Modules::GamePass::GetGamePassUserDataResponseData& result) {
                        success(result.gamePasses);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Retrieves all GamePassUserData instances for a specified user asynchronously.
         * @param userId - The identifier of the user to retrieve all game passes for. Optional.
         * @param cancellationToken - A token to cancel the operation.
         * @return A list of all GamePassUserData instances for the specified user.
         */
        static void GetAllForUserAsync(
            const function<void(const vector<RGN::Modules::GamePass::GamePassUserData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["userId"] = userId;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::GamePass::GetGamePassUserDataResponseData>(
                    "gamePass-getAllForUser",
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