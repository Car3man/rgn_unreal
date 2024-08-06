#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Utility/CancellationToken.h"
#include "../Currency/Currency.h"
#include "OnGameCompleteResult.h"
#include "OnGameCompleteRequestData.h"
#include "GameProgress.h"
#include "../../Model/Request/BaseMigrationRequestData.h"
#include "AddUserLevelRequestData.h"
#include "UpdateUserLevelRequestData.h"
#include "UpdateUserLevelResponseData.h"
#include "GetPlayerLevelResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace GameProgress {
    class GameProgressModule {
    public:
        static void OnGameCompleteAsync(
            const function<void(const RGN::Modules::GameProgress::OnGameCompleteResult& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<RGN::Modules::Currency::Currency>& reward,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::GameProgress::OnGameCompleteRequestData requestData;
                requestData.reward = reward;
                RGNCore::CallAPI<RGN::Modules::GameProgress::OnGameCompleteRequestData, RGN::Modules::GameProgress::OnGameCompleteResult>(
                    "game-onGameComplete",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Gets the current user level.
         * @param cancellationToken - A token to cancel the operation.
         * @return User level
         */
        static void GetGameProgressAsync(
            const function<void(const RGN::Modules::GameProgress::GameProgress& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Model::Request::BaseMigrationRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseMigrationRequestData, RGN::Modules::GameProgress::GameProgress>(
                    "game-getGameProgress",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void AddUserProgressAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userProgressJson,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::GameProgress::AddUserLevelRequestData requestData;
                requestData.playerProgress = userProgressJson;
                RGNCore::CallAPI<RGN::Modules::GameProgress::AddUserLevelRequestData>(
                    "game-addPlayerProgress",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void UpdateUserProgressAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userProgressJson,
            const vector<RGN::Modules::Currency::Currency>& reward,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::GameProgress::UpdateUserLevelRequestData requestData;
                requestData.playerProgress = userProgressJson;
                requestData.reward = reward;
                RGNCore::CallAPI<RGN::Modules::GameProgress::UpdateUserLevelRequestData>(
                    "game-updatePlayerProgress",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetUserProgressAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Model::Request::BaseMigrationRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseMigrationRequestData>(
                    "game-getPlayerProgress",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
    };
}}}