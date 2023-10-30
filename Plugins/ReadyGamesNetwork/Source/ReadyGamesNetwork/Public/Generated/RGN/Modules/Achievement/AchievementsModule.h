#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../CustomImpl/RGN/Modules/Achievement/AchievementsModule.h"
#include "GetAchievementsResponse.h"
#include "AchievementData.h"
#include "GetAchievementsWithUserDataResponse.h"
#include "AchievementWithUserData.h"
#include "TriggerAndClaimResponse.h"
#include "TriggerByIdRequestData.h"
#include "TriggerByRequestNameRequestData.h"
#include "ClaimByIdRequestData.h"
#include "ClaimByRequestNameRequestData.h"
#include "GetUserAchievementsResponse.h"
#include "UserAchievement.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace Achievement {
    class AchievementsModule {
    public:
        static void GetByIdsAsync(
            vector<string>& ids,
            const function<void(vector<RGN::Modules::Achievement::AchievementData> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ids"] = ids;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Achievement::GetAchievementsResponse>(
                    "achievements-getByIds",
                    requestData,
                    [complete] (RGN::Modules::Achievement::GetAchievementsResponse result) {
                        complete(result.achievements);
                    },
                    fail);
            };
        static void GetByAppIdsAsync(
            vector<string>& appIds,
            int32_t limit,
            string& startAfter,
            const function<void(vector<RGN::Modules::Achievement::AchievementData> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["appIds"] = appIds;
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Achievement::GetAchievementsResponse>(
                    "achievements-getByAppIds",
                    requestData,
                    [complete] (RGN::Modules::Achievement::GetAchievementsResponse result) {
                        complete(result.achievements);
                    },
                    fail);
            };
        static void GetForCurrentAppAsync(
            int32_t limit,
            string& startAfter,
            const function<void(vector<RGN::Modules::Achievement::AchievementData> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Achievement::AchievementsModuleCustomImpl::GetForCurrentAppAsync(
                    limit,
                    startAfter,
                    complete,
                    fail);
            };
        static void GetByAppIdsWithUserDataAsync(
            vector<string>& appIds,
            int32_t limit,
            string& startAfter,
            bool withHistory,
            const function<void(vector<RGN::Modules::Achievement::AchievementWithUserData> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Achievement::AchievementsModuleCustomImpl::GetByAppIdsWithUserDataAsync(
                    appIds,
                    limit,
                    startAfter,
                    withHistory,
                    complete,
                    fail);
            };
        static void GetForCurrentAppWithUserDataAsync(
            int32_t limit,
            string& startAfter,
            const function<void(vector<RGN::Modules::Achievement::AchievementWithUserData> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Achievement::AchievementsModuleCustomImpl::GetForCurrentAppWithUserDataAsync(
                    limit,
                    startAfter,
                    complete,
                    fail);
            };
        static void GetByRequestNameAsync(
            string& requestName,
            const function<void(RGN::Modules::Achievement::AchievementData result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["requestName"] = requestName;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Achievement::AchievementData>(
                    "achievements-getByRequestName",
                    requestData,
                    complete,
                    fail);
            };
        static void GetByRequestNamesAsync(
            vector<string>& requestNames,
            const function<void(vector<RGN::Modules::Achievement::AchievementData> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["requestNames"] = requestNames;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Achievement::GetAchievementsResponse>(
                    "achievements-getByRequestNames",
                    requestData,
                    [complete] (RGN::Modules::Achievement::GetAchievementsResponse result) {
                        complete(result.achievements);
                    },
                    fail);
            };
        static void TriggerByIdAsync(
            string& id,
            int32_t progress,
            const function<void(RGN::Modules::Achievement::TriggerAndClaimResponse result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Achievement::TriggerByIdRequestData requestData;
                requestData.id = id;
                requestData.progress = progress;
                RGNCore::CallAPI<RGN::Modules::Achievement::TriggerByIdRequestData, RGN::Modules::Achievement::TriggerAndClaimResponse>(
                    "achievements-triggerById",
                    requestData,
                    complete,
                    fail);
            };
        static void TriggerByRequestNameAsync(
            string& requestName,
            int32_t progress,
            const function<void(RGN::Modules::Achievement::TriggerAndClaimResponse result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Achievement::TriggerByRequestNameRequestData requestData;
                requestData.requestName = requestName;
                requestData.progress = progress;
                RGNCore::CallAPI<RGN::Modules::Achievement::TriggerByRequestNameRequestData, RGN::Modules::Achievement::TriggerAndClaimResponse>(
                    "achievements-triggerByRequestName",
                    requestData,
                    complete,
                    fail);
            };
        static void ClaimByIdAsync(
            string& achievementId,
            const function<void(RGN::Modules::Achievement::TriggerAndClaimResponse result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Achievement::ClaimByIdRequestData requestData;
                requestData.id = achievementId;
                RGNCore::CallAPI<RGN::Modules::Achievement::ClaimByIdRequestData, RGN::Modules::Achievement::TriggerAndClaimResponse>(
                    "achievements-claimById",
                    requestData,
                    complete,
                    fail);
            };
        static void ClaimByRequestNameAsync(
            string& requestName,
            const function<void(RGN::Modules::Achievement::TriggerAndClaimResponse result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Achievement::ClaimByRequestNameRequestData requestData;
                requestData.requestName = requestName;
                RGNCore::CallAPI<RGN::Modules::Achievement::ClaimByRequestNameRequestData, RGN::Modules::Achievement::TriggerAndClaimResponse>(
                    "achievements-claimByRequestName",
                    requestData,
                    complete,
                    fail);
            };
        static void GetUserAchievementsAsync(
            string& userId,
            int64_t startAfter,
            int32_t limit,
            const function<void(vector<RGN::Modules::Achievement::UserAchievement> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Achievement::AchievementsModuleCustomImpl::GetUserAchievementsAsync(
                    userId,
                    startAfter,
                    limit,
                    complete,
                    fail);
            };
    };
}}}