#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementData.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementReward.h"
#include "BP_AchievementReward.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/BP_BaseRequestData.h"
#include <string>
#include <vector>
#include <unordered_map>
#include "BP_AchievementData.generated.h"

/**
 * Represents achievement data from the backend
 */
USTRUCT(BlueprintType)
struct READYGAMESNETWORK_API FBP_AchievementData : public FBP_BaseRequestData {
    GENERATED_BODY()

    /**
     * Achievement document id. To trigger an achievement the id is needed
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    FString id;
    /**
     * List of application ids where this achievement is used
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    TArray<FString> appIds;
    /**
     * List of tags to filter the achievements
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    TArray<FString> tags;
    /**
     * Achievement request name. This value can be used to query or trigger achievements
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    FString requestName;
    /**
     * Achievement name. This value can be null or empty
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    FString name;
    /**
     * Achievement description. This value can be null or empty
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    FString description;
    /**
     * Define who can trigger/claim the achievement. 'server' or 'client'
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    FString setBy;
    /**
     * Should the achievement be claim manually
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    bool isClaimable;
    /**
     * Value which should be reached to complete the achievement
     * Default is 1
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    int32 valueToReach;
    /**
     * Achievement ids which should be completed before this achievement can be triggered
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    TArray<FString> completedAchievementsToUnlock;
    /**
     * Can this achievement be applied multiple times to the same user account
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    bool repeatable;
    /**
     * If this is provided, the the trigger for this achievement will work no more
     * often that the specified cron string.
     * 
     * *    *    *    *    *    *
     * ┬    ┬    ┬    ┬    ┬    ┬
     * │    │    │    │    │    │
     * │    │    │    │    │    └ day of week(0 - 7, 1L - 7L) (0 or 7 is Sun)
     * │    │    │    │    └───── month(1 - 12)
     * │    │    │    └────────── day of month(1 - 31, L)
     * │    │    └─────────────── hour(0 - 23)
     * │    └──────────────────── minute(0 - 59)
     * └───────────────────────── second(0 - 59, optional)
     * 
     * You can use the https://crontab.guru/ to create cron settings
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    FString repeatNoMoreOftenThanCron;
    /**
     * Start time of the achievement, when it can be available for users
     * in milliseconds since midnight, January 1, 1970 UTC.
     * Refer to T:RGN.Utility.DateTimeUtility for helper methods.
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    int64 startTime;
    /**
     * End time of the achievement, when it becomes unavailable for users
     * in milliseconds since midnight, January 1, 1970 UTC.
     * Refer to T:RGN.Utility.DateTimeUtility for helper methods.
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    int64 endTime;
    /**
     * Define cron value when the achievement should reset. This parameter is used
     * to update the F:RGN.Modules.Achievement.AchievementData.startTime and F:RGN.Modules.Achievement.AchievementData.endTime values.
     * 
     * *    *    *    *    *    *
     * ┬    ┬    ┬    ┬    ┬    ┬
     * │    │    │    │    │    │
     * │    │    │    │    │    └ day of week(0 - 7, 1L - 7L) (0 or 7 is Sun)
     * │    │    │    │    └───── month(1 - 12)
     * │    │    │    └────────── day of month(1 - 31, L)
     * │    │    └─────────────── hour(0 - 23)
     * │    └──────────────────── minute(0 - 59)
     * └───────────────────────── second(0 - 59, optional)
     * 
     * You can use the https://crontab.guru/ to create cron settings
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    FString resetTimeLimitEvery;
    /**
     * Achievement rewards ids and quantity rewards to add to users when
     * the achievement is triggered
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    TArray<FBP_AchievementReward> rewards;
    /**
     * Time when the achievement was created
     * in milliseconds since midnight, January 1, 1970 UTC.
     * Refer to T:RGN.Utility.DateTimeUtility for helper methods.
     * This field is automatically populated by the backend
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    int64 createdAt;
    /**
     * Time when the achievement was updated
     * in milliseconds since midnight, January 1, 1970 UTC.
     * Refer to T:RGN.Utility.DateTimeUtility for helper methods.
     * This field is automatically populated by the backend
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    int64 updatedAt;
    /**
     * Creator user id
     * This field is automatically populated by the backend
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    FString createdBy;
    /**
     * Updater user id
     * This field is automatically populated by the backend
     */
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Achievement")
    FString updatedBy;

	static void ConvertToUnrealModel(const RGN::Modules::Achievement::AchievementData& source, FBP_AchievementData& target) {
        target.id = FString(UTF8_TO_TCHAR(source.id.c_str()));
        for (const auto& source_appIds_item : source.appIds) {
            FString b_source_appIds_item;
            b_source_appIds_item = FString(UTF8_TO_TCHAR(source_appIds_item.c_str()));
            target.appIds.Add(b_source_appIds_item);
        }
        for (const auto& source_tags_item : source.tags) {
            FString b_source_tags_item;
            b_source_tags_item = FString(UTF8_TO_TCHAR(source_tags_item.c_str()));
            target.tags.Add(b_source_tags_item);
        }
        target.requestName = FString(UTF8_TO_TCHAR(source.requestName.c_str()));
        target.name = FString(UTF8_TO_TCHAR(source.name.c_str()));
        target.description = FString(UTF8_TO_TCHAR(source.description.c_str()));
        target.setBy = FString(UTF8_TO_TCHAR(source.setBy.c_str()));
        target.isClaimable = source.isClaimable;
        target.valueToReach = source.valueToReach;
        for (const auto& source_completedAchievementsToUnlock_item : source.completedAchievementsToUnlock) {
            FString b_source_completedAchievementsToUnlock_item;
            b_source_completedAchievementsToUnlock_item = FString(UTF8_TO_TCHAR(source_completedAchievementsToUnlock_item.c_str()));
            target.completedAchievementsToUnlock.Add(b_source_completedAchievementsToUnlock_item);
        }
        target.repeatable = source.repeatable;
        target.repeatNoMoreOftenThanCron = FString(UTF8_TO_TCHAR(source.repeatNoMoreOftenThanCron.c_str()));
        target.startTime = source.startTime;
        target.endTime = source.endTime;
        target.resetTimeLimitEvery = FString(UTF8_TO_TCHAR(source.resetTimeLimitEvery.c_str()));
        for (const auto& source_rewards_item : source.rewards) {
            FBP_AchievementReward b_source_rewards_item;
            FBP_AchievementReward::ConvertToUnrealModel(source_rewards_item, b_source_rewards_item);
            target.rewards.Add(b_source_rewards_item);
        }
        target.createdAt = source.createdAt;
        target.updatedAt = source.updatedAt;
        target.createdBy = FString(UTF8_TO_TCHAR(source.createdBy.c_str()));
        target.updatedBy = FString(UTF8_TO_TCHAR(source.updatedBy.c_str()));
		FBP_BaseRequestData::ConvertToUnrealModel(source, target);
	}

	static void ConvertToCoreModel(const FBP_AchievementData& source, RGN::Modules::Achievement::AchievementData& target) {
        target.id = string(TCHAR_TO_UTF8(*source.id));
        for (const auto& source_appIds_item : source.appIds) {
            string cpp_source_appIds_item;
            cpp_source_appIds_item = string(TCHAR_TO_UTF8(*source_appIds_item));
            target.appIds.push_back(cpp_source_appIds_item);
        }
        for (const auto& source_tags_item : source.tags) {
            string cpp_source_tags_item;
            cpp_source_tags_item = string(TCHAR_TO_UTF8(*source_tags_item));
            target.tags.push_back(cpp_source_tags_item);
        }
        target.requestName = string(TCHAR_TO_UTF8(*source.requestName));
        target.name = string(TCHAR_TO_UTF8(*source.name));
        target.description = string(TCHAR_TO_UTF8(*source.description));
        target.setBy = string(TCHAR_TO_UTF8(*source.setBy));
        target.isClaimable = source.isClaimable;
        target.valueToReach = source.valueToReach;
        for (const auto& source_completedAchievementsToUnlock_item : source.completedAchievementsToUnlock) {
            string cpp_source_completedAchievementsToUnlock_item;
            cpp_source_completedAchievementsToUnlock_item = string(TCHAR_TO_UTF8(*source_completedAchievementsToUnlock_item));
            target.completedAchievementsToUnlock.push_back(cpp_source_completedAchievementsToUnlock_item);
        }
        target.repeatable = source.repeatable;
        target.repeatNoMoreOftenThanCron = string(TCHAR_TO_UTF8(*source.repeatNoMoreOftenThanCron));
        target.startTime = source.startTime;
        target.endTime = source.endTime;
        target.resetTimeLimitEvery = string(TCHAR_TO_UTF8(*source.resetTimeLimitEvery));
        for (const auto& source_rewards_item : source.rewards) {
            RGN::Modules::Achievement::AchievementReward cpp_source_rewards_item;
            FBP_AchievementReward::ConvertToCoreModel(source_rewards_item, cpp_source_rewards_item);
            target.rewards.push_back(cpp_source_rewards_item);
        }
        target.createdAt = source.createdAt;
        target.updatedAt = source.updatedAt;
        target.createdBy = string(TCHAR_TO_UTF8(*source.createdBy));
        target.updatedBy = string(TCHAR_TO_UTF8(*source.updatedBy));
		FBP_BaseRequestData::ConvertToCoreModel(source, target);
	}
};
