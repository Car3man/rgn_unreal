#pragma once

#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Generated/RGN/Modules/Achievement/GetAchievementsResponse.h"
#include "../../../../Generated/RGN/Modules/Achievement/GetAchievementsWithUserDataResponse.h"
#include "../../../../Generated/RGN/Modules/Achievement/GetUserAchievementsResponse.h"
#include <string>
#include <algorithm>

namespace RGN { namespace Modules { namespace Achievement {
    class AchievementsModuleCustomImpl {
    public:
        static void GetForCurrentAppAsync(
            const std::function<void(std::vector<RGN::Modules::Achievement::AchievementData> result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            int32_t limit,
            std::string startAfter,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["appIds"] = { RGNCore::GetAppId() };
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Achievement::GetAchievementsResponse>(
                    "achievements-getByAppIds",
                    requestData,
                    [success](RGN::Modules::Achievement::GetAchievementsResponse result) {
                        success(result.achievements);
                    },
                    fail,
                    false, cancellationToken
                );
            };

        static void GetByAppIdsWithUserDataAsync(
            const std::function<void(std::vector<RGN::Modules::Achievement::AchievementWithUserData> result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::vector<string> appIds,
            int32_t limit,
            std::string startAfter,
            bool withHistory,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["appIds"] = appIds;
                bodyJson["limit"] = limit;
                bodyJson["startAfter"] = startAfter;
                bodyJson["withHistory"] = withHistory;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Achievement::GetAchievementsWithUserDataResponse>
                    ("achievements-getByAppIds", bodyJson, 
                    [success](RGN::Modules::Achievement::GetAchievementsWithUserDataResponse response) {
                        for (RGN::Modules::Achievement::AchievementWithUserData& achievement : response.achievements) {
                            for (RGN::Modules::Achievement::UserAchievement& userAchievement : response.userAchievements) {
                                if (achievement.id == userAchievement.id) {
                                    achievement._userAchievement = userAchievement;
                                    break;
                                }
                            }
                        }
                        success(response.achievements);
                    }, 
                fail,
                false, cancellationToken);
            };

        static void GetByTagsWithUserDataAsync(
            const std::function<void(std::vector<RGN::Modules::Achievement::AchievementWithUserData> result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::vector<std::string> tags,
            int32_t limit,
            int64_t startAfter,
            bool withHistory,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["tags"] = tags;
                bodyJson["limit"] = limit;
                bodyJson["startAfter"] = startAfter;
                bodyJson["withHistory"] = withHistory;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Achievement::GetAchievementsWithUserDataResponse>
                    ("achievements-getByTagsWithUserData", bodyJson,
                    [success](RGN::Modules::Achievement::GetAchievementsWithUserDataResponse response) {
                        for (RGN::Modules::Achievement::AchievementWithUserData& achievement : response.achievements) {
                            for (RGN::Modules::Achievement::UserAchievement& userAchievement : response.userAchievements) {
                                if (achievement.id == userAchievement.id) {
                                    achievement._userAchievement = userAchievement;
                                    break;
                                }
                            }
                        }
                        success(response.achievements);
                    },
                fail,
                false, cancellationToken);
            };

        static void GetForCurrentAppWithUserDataAsync(
            const std::function<void(std::vector<RGN::Modules::Achievement::AchievementWithUserData> result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            int32_t limit,
            std::string startAfter,
            CancellationToken cancellationToken = CancellationToken()) {
                GetByAppIdsWithUserDataAsync(success, fail, { RGNCore::GetAppId() }, limit, startAfter, false, cancellationToken);
            };

        static void GetUserAchievementsAsync(
            const std::function<void(std::vector<RGN::Modules::Achievement::UserAchievement> result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::string userId,
            bool withHistory,
            int64_t startAfter,
            int32_t limit,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["userId"] = userId;
                bodyJson["withHistory"] = withHistory;
                bodyJson["startAfter"] = startAfter;
                bodyJson["limit"] = limit;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Achievement::GetUserAchievementsResponse>
                    ("achievements-getUserAchievements", bodyJson,
                    [success](RGN::Modules::Achievement::GetUserAchievementsResponse response) {
                        success(response.userAchievements);
                    },
                fail,
                false, cancellationToken);
            };

        static void GetUserAchievementByIdAsync(
            const std::function<void(RGN::Modules::Achievement::UserAchievement result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::string achievementId,
            std::string userId,
            bool withHistory,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["achievementId"] = achievementId;
                bodyJson["userId"] = userId;
                bodyJson["withHistory"] = withHistory;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Achievement::UserAchievement>
                    ("achievements-getUserAchievementById", bodyJson,
                    [success](RGN::Modules::Achievement::UserAchievement response) {
                        success(response);
                    },
                fail,
                false, cancellationToken);
            };
    };
}}}
