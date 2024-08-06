#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "UserAchievement.h"
#include "AchievementData.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace RGN { namespace Modules { namespace Achievement {
    /**
     * Represents achievement data from the backend
     */
    struct AchievementWithUserData : public RGN::Modules::Achievement::AchievementData {
        /**
         * The user achievement data. Please use the M:RGN.Modules.Achievement.AchievementWithUserData.GetUserAchievement method instead.
         */
        RGN::Modules::Achievement::UserAchievement _userAchievement;

        friend void to_json(nlohmann::json& nlohmann_json_j, const AchievementWithUserData& nlohmann_json_t) {
            nlohmann_json_j["id"] = nlohmann_json_t.id;
            nlohmann_json_j["appIds"] = nlohmann_json_t.appIds;
            nlohmann_json_j["tags"] = nlohmann_json_t.tags;
            nlohmann_json_j["requestName"] = nlohmann_json_t.requestName;
            nlohmann_json_j["name"] = nlohmann_json_t.name;
            nlohmann_json_j["description"] = nlohmann_json_t.description;
            nlohmann_json_j["setBy"] = nlohmann_json_t.setBy;
            nlohmann_json_j["isClaimable"] = nlohmann_json_t.isClaimable;
            nlohmann_json_j["valueToReach"] = nlohmann_json_t.valueToReach;
            nlohmann_json_j["completedAchievementsToUnlock"] = nlohmann_json_t.completedAchievementsToUnlock;
            nlohmann_json_j["repeatable"] = nlohmann_json_t.repeatable;
            nlohmann_json_j["repeatNoMoreOftenThanCron"] = nlohmann_json_t.repeatNoMoreOftenThanCron;
            nlohmann_json_j["startTime"] = nlohmann_json_t.startTime;
            nlohmann_json_j["endTime"] = nlohmann_json_t.endTime;
            nlohmann_json_j["resetTimeLimitEvery"] = nlohmann_json_t.resetTimeLimitEvery;
            nlohmann_json_j["rewards"] = nlohmann_json_t.rewards;
            nlohmann_json_j["createdAt"] = nlohmann_json_t.createdAt;
            nlohmann_json_j["updatedAt"] = nlohmann_json_t.updatedAt;
            nlohmann_json_j["createdBy"] = nlohmann_json_t.createdBy;
            nlohmann_json_j["updatedBy"] = nlohmann_json_t.updatedBy;
            nlohmann_json_j["appPackageName"] = nlohmann_json_t.appPackageName;
            nlohmann_json_j["_userAchievement"] = nlohmann_json_t._userAchievement;
        }

        friend void from_json(const nlohmann::json& nlohmann_json_j, AchievementWithUserData& nlohmann_json_t) {
            if (nlohmann_json_j.contains("id")) {
                auto json_id = nlohmann_json_j.at("id");
                if (!json_id.is_null() && json_id.is_string()) {
                    json_id.get_to(nlohmann_json_t.id);
                }
            }
            if (nlohmann_json_j.contains("appIds")) {
                auto json_appIds = nlohmann_json_j.at("appIds");
                if (!json_appIds.is_null() && json_appIds.is_array()) {
                    json_appIds.get_to(nlohmann_json_t.appIds);
                }
            }
            if (nlohmann_json_j.contains("tags")) {
                auto json_tags = nlohmann_json_j.at("tags");
                if (!json_tags.is_null() && json_tags.is_array()) {
                    json_tags.get_to(nlohmann_json_t.tags);
                }
            }
            if (nlohmann_json_j.contains("requestName")) {
                auto json_requestName = nlohmann_json_j.at("requestName");
                if (!json_requestName.is_null() && json_requestName.is_string()) {
                    json_requestName.get_to(nlohmann_json_t.requestName);
                }
            }
            if (nlohmann_json_j.contains("name")) {
                auto json_name = nlohmann_json_j.at("name");
                if (!json_name.is_null() && json_name.is_string()) {
                    json_name.get_to(nlohmann_json_t.name);
                }
            }
            if (nlohmann_json_j.contains("description")) {
                auto json_description = nlohmann_json_j.at("description");
                if (!json_description.is_null() && json_description.is_string()) {
                    json_description.get_to(nlohmann_json_t.description);
                }
            }
            if (nlohmann_json_j.contains("setBy")) {
                auto json_setBy = nlohmann_json_j.at("setBy");
                if (!json_setBy.is_null() && json_setBy.is_string()) {
                    json_setBy.get_to(nlohmann_json_t.setBy);
                }
            }
            if (nlohmann_json_j.contains("isClaimable")) {
                auto json_isClaimable = nlohmann_json_j.at("isClaimable");
                if (!json_isClaimable.is_null() && json_isClaimable.is_boolean()) {
                    json_isClaimable.get_to(nlohmann_json_t.isClaimable);
                }
            }
            if (nlohmann_json_j.contains("valueToReach")) {
                auto json_valueToReach = nlohmann_json_j.at("valueToReach");
                if (!json_valueToReach.is_null() && json_valueToReach.is_number()) {
                    json_valueToReach.get_to(nlohmann_json_t.valueToReach);
                }
            }
            if (nlohmann_json_j.contains("completedAchievementsToUnlock")) {
                auto json_completedAchievementsToUnlock = nlohmann_json_j.at("completedAchievementsToUnlock");
                if (!json_completedAchievementsToUnlock.is_null() && json_completedAchievementsToUnlock.is_array()) {
                    json_completedAchievementsToUnlock.get_to(nlohmann_json_t.completedAchievementsToUnlock);
                }
            }
            if (nlohmann_json_j.contains("repeatable")) {
                auto json_repeatable = nlohmann_json_j.at("repeatable");
                if (!json_repeatable.is_null() && json_repeatable.is_boolean()) {
                    json_repeatable.get_to(nlohmann_json_t.repeatable);
                }
            }
            if (nlohmann_json_j.contains("repeatNoMoreOftenThanCron")) {
                auto json_repeatNoMoreOftenThanCron = nlohmann_json_j.at("repeatNoMoreOftenThanCron");
                if (!json_repeatNoMoreOftenThanCron.is_null() && json_repeatNoMoreOftenThanCron.is_string()) {
                    json_repeatNoMoreOftenThanCron.get_to(nlohmann_json_t.repeatNoMoreOftenThanCron);
                }
            }
            if (nlohmann_json_j.contains("startTime")) {
                auto json_startTime = nlohmann_json_j.at("startTime");
                if (!json_startTime.is_null() && json_startTime.is_number()) {
                    json_startTime.get_to(nlohmann_json_t.startTime);
                }
            }
            if (nlohmann_json_j.contains("endTime")) {
                auto json_endTime = nlohmann_json_j.at("endTime");
                if (!json_endTime.is_null() && json_endTime.is_number()) {
                    json_endTime.get_to(nlohmann_json_t.endTime);
                }
            }
            if (nlohmann_json_j.contains("resetTimeLimitEvery")) {
                auto json_resetTimeLimitEvery = nlohmann_json_j.at("resetTimeLimitEvery");
                if (!json_resetTimeLimitEvery.is_null() && json_resetTimeLimitEvery.is_string()) {
                    json_resetTimeLimitEvery.get_to(nlohmann_json_t.resetTimeLimitEvery);
                }
            }
            if (nlohmann_json_j.contains("rewards")) {
                auto json_rewards = nlohmann_json_j.at("rewards");
                if (!json_rewards.is_null() && json_rewards.is_array()) {
                    json_rewards.get_to(nlohmann_json_t.rewards);
                }
            }
            if (nlohmann_json_j.contains("createdAt")) {
                auto json_createdAt = nlohmann_json_j.at("createdAt");
                if (!json_createdAt.is_null() && json_createdAt.is_number()) {
                    json_createdAt.get_to(nlohmann_json_t.createdAt);
                }
            }
            if (nlohmann_json_j.contains("updatedAt")) {
                auto json_updatedAt = nlohmann_json_j.at("updatedAt");
                if (!json_updatedAt.is_null() && json_updatedAt.is_number()) {
                    json_updatedAt.get_to(nlohmann_json_t.updatedAt);
                }
            }
            if (nlohmann_json_j.contains("createdBy")) {
                auto json_createdBy = nlohmann_json_j.at("createdBy");
                if (!json_createdBy.is_null() && json_createdBy.is_string()) {
                    json_createdBy.get_to(nlohmann_json_t.createdBy);
                }
            }
            if (nlohmann_json_j.contains("updatedBy")) {
                auto json_updatedBy = nlohmann_json_j.at("updatedBy");
                if (!json_updatedBy.is_null() && json_updatedBy.is_string()) {
                    json_updatedBy.get_to(nlohmann_json_t.updatedBy);
                }
            }
            if (nlohmann_json_j.contains("appPackageName")) {
                auto json_appPackageName = nlohmann_json_j.at("appPackageName");
                if (!json_appPackageName.is_null() && json_appPackageName.is_string()) {
                    json_appPackageName.get_to(nlohmann_json_t.appPackageName);
                }
            }
            if (nlohmann_json_j.contains("_userAchievement")) {
                auto json__userAchievement = nlohmann_json_j.at("_userAchievement");
                if (!json__userAchievement.is_null()) {
                    json__userAchievement.get_to(nlohmann_json_t._userAchievement);
                }
            }
        }
    };
}}}