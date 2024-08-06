#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Utility/CancellationToken.h"
#include "AchievementData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace Achievement {
    class AchievementsModule_Admin {
    public:
        static void AddAchievementAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const RGN::Modules::Achievement::AchievementData& achievementData,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["data"] = achievementData;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "achievements-add",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["result"]["id"].template get<string>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void UpdateAchievementAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const RGN::Modules::Achievement::AchievementData& achievementData,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["data"] = achievementData;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "achievements-update",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["result"]["id"].template get<string>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void DeleteAchievementAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& achievementId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["id"] = achievementId;
                RGNCore::CallAPI<nlohmann::json>(
                    "achievements-delete",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void AddLoginDaysInRowAchievementAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& achievementId,
            const int32_t daysInRow,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["achievementId"] = achievementId;
                RGNCore::CallAPI<nlohmann::json>(
                    "achievements-addLoginDaysInRowAchievement",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void AddLoginDaysInRowAchievementAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const RGN::Modules::Achievement::AchievementData& achievementData,
            const int32_t daysInRow,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["achievementData"] = achievementData;
                RGNCore::CallAPI<nlohmann::json>(
                    "achievements-addLoginDaysInRowAchievement",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void DeleteLoginDaysInRowGameConstRecordAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& achievementId,
            const int32_t daysInRow,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["achievementId"] = achievementId;
                RGNCore::CallAPI<nlohmann::json>(
                    "achievements-deleteLoginDaysInRowGameConstRecord",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void AddPlayerProgressAchievementAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& achievementId,
            const string& playerProgressFieldName,
            const int64_t playerProgressFieldValueToReach,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["achievementId"] = achievementId;
                requestData["playerProgressFieldName"] = playerProgressFieldName;
                requestData["playerProgressFieldValueToReach"] = playerProgressFieldValueToReach;
                RGNCore::CallAPI<nlohmann::json>(
                    "achievements-addPlayerProgressAchievement",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void AddPlayerProgressAchievementAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const RGN::Modules::Achievement::AchievementData& achievementData,
            const string& playerProgressFieldName,
            const int64_t playerProgressFieldValueToReach,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["achievementData"] = achievementData;
                requestData["playerProgressFieldName"] = playerProgressFieldName;
                requestData["playerProgressFieldValueToReach"] = playerProgressFieldValueToReach;
                RGNCore::CallAPI<nlohmann::json>(
                    "achievements-addPlayerProgressAchievement",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void DeletePlayerProgressAchievementAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& achievementId,
            const string& playerProgressFieldName,
            const int64_t playerProgressFieldValueToReach,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["achievementId"] = achievementId;
                requestData["playerProgressFieldName"] = playerProgressFieldName;
                requestData["playerProgressFieldValueToReach"] = playerProgressFieldValueToReach;
                RGNCore::CallAPI<nlohmann::json>(
                    "achievements-deletePlayerProgressGameConstRecord",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void AddPurchaseAchievementAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const RGN::Modules::Achievement::AchievementData& achievementData,
            const string& virtualItemTag,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["achievementData"] = achievementData;
                requestData["virtualItemTag"] = virtualItemTag;
                RGNCore::CallAPI<nlohmann::json>(
                    "achievements-addPurchaseAchievement",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void DeletePurchaseGameConstRecordAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& achievementId,
            const string& virtualItemTag,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["achievementId"] = achievementId;
                requestData["virtualItemTag"] = virtualItemTag;
                RGNCore::CallAPI<nlohmann::json>(
                    "achievements-deletePurchaseGameConstRecord",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
    };
}}}