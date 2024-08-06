#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementsModule.h"
#include "../../../../../Generated/RGN/Modules/Achievement/GetAchievementsResponse.h"
#include "BP_GetAchievementsResponse.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementData.h"
#include "BP_AchievementData.h"
#include "../../../../../Generated/RGN/Modules/Achievement/GetAchievementsWithUserDataResponse.h"
#include "BP_GetAchievementsWithUserDataResponse.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementWithUserData.h"
#include "BP_AchievementWithUserData.h"
#include "../../../../../Generated/RGN/Modules/Achievement/TriggerAndClaimResponse.h"
#include "BP_TriggerAndClaimResponse.h"
#include "../../../../../Generated/RGN/Modules/Achievement/TriggerByIdRequestData.h"
#include "BP_TriggerByIdRequestData.h"
#include "../../../../../Generated/RGN/Modules/Achievement/TriggerByRequestNameRequestData.h"
#include "BP_TriggerByRequestNameRequestData.h"
#include "../../../../../Generated/RGN/Modules/Achievement/ClaimByIdRequestData.h"
#include "BP_ClaimByIdRequestData.h"
#include "../../../../../Generated/RGN/Modules/Achievement/ClaimByRequestNameRequestData.h"
#include "BP_ClaimByRequestNameRequestData.h"
#include "../../../../../Generated/RGN/Modules/Achievement/GetProjectAchievementsResponse.h"
#include "BP_GetProjectAchievementsResponse.h"
#include "../../../../../Generated/RGN/Modules/Achievement/GetUserAchievementsResponse.h"
#include "BP_GetUserAchievementsResponse.h"
#include "../../../../../Generated/RGN/Modules/Achievement/UserAchievement.h"
#include "BP_UserAchievement.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_AchievementsModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FAchievementsModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetByIdsAsyncResponse, const TArray<FBP_AchievementData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetByAppIdsAsyncResponse, const TArray<FBP_AchievementData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetByTagsAsyncResponse, const TArray<FBP_AchievementData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetForCurrentAppAsyncResponse, const TArray<FBP_AchievementData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetByAppIdsWithUserDataAsyncResponse, const TArray<FBP_AchievementWithUserData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetByTagsWithUserDataAsyncResponse, const TArray<FBP_AchievementWithUserData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetForCurrentAppWithUserDataAsyncResponse, const TArray<FBP_AchievementWithUserData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetByRequestNameAsyncResponse, const FBP_AchievementData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetByRequestNamesAsyncResponse, const TArray<FBP_AchievementData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleTriggerByIdAsyncResponse, const FBP_TriggerAndClaimResponse&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleTriggerByRequestNameAsyncResponse, const FBP_TriggerAndClaimResponse&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleClaimByIdAsyncResponse, const FBP_TriggerAndClaimResponse&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleClaimByRequestNameAsyncResponse, const FBP_TriggerAndClaimResponse&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetProjectAchievementsAsyncResponse, const FBP_GetProjectAchievementsResponse&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetUserAchievementsAsyncResponse, const TArray<FBP_UserAchievement>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleGetUserAchievementByIdAsyncResponse, const FBP_UserAchievement&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_AchievementsModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetByIdsAsync(
        FAchievementsModuleGetByIdsAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& ids) {
            vector<string> cpp_ids;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& ids_item : ids) {
                string cpp_ids_item;
                cpp_ids_item = string(TCHAR_TO_UTF8(*ids_item));
                cpp_ids.push_back(cpp_ids_item);
            }
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetByIdsAsync(
                [onSuccess](vector<RGN::Modules::Achievement::AchievementData> response) {
                    TArray<FBP_AchievementData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_AchievementData b_response_item;
                        FBP_AchievementData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_ids,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="startAfter, cancellationToken"))
    static void GetByAppIdsAsync(
        FAchievementsModuleGetByAppIdsAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& appIds,
        int32 limit,
        const FString& startAfter = "") {
            vector<string> cpp_appIds;
            int32_t cpp_limit;
            string cpp_startAfter;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& appIds_item : appIds) {
                string cpp_appIds_item;
                cpp_appIds_item = string(TCHAR_TO_UTF8(*appIds_item));
                cpp_appIds.push_back(cpp_appIds_item);
            }
            cpp_limit = limit;
            cpp_startAfter = string(TCHAR_TO_UTF8(*startAfter));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetByAppIdsAsync(
                [onSuccess](vector<RGN::Modules::Achievement::AchievementData> response) {
                    TArray<FBP_AchievementData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_AchievementData b_response_item;
                        FBP_AchievementData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_appIds,
                cpp_limit,
                cpp_startAfter,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="startAfter, cancellationToken"))
    static void GetByTagsAsync(
        FAchievementsModuleGetByTagsAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& tags,
        int32 limit,
        int64 startAfter = 0) {
            vector<string> cpp_tags;
            int32_t cpp_limit;
            int64_t cpp_startAfter;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& tags_item : tags) {
                string cpp_tags_item;
                cpp_tags_item = string(TCHAR_TO_UTF8(*tags_item));
                cpp_tags.push_back(cpp_tags_item);
            }
            cpp_limit = limit;
            cpp_startAfter = startAfter;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetByTagsAsync(
                [onSuccess](vector<RGN::Modules::Achievement::AchievementData> response) {
                    TArray<FBP_AchievementData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_AchievementData b_response_item;
                        FBP_AchievementData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_tags,
                cpp_limit,
                cpp_startAfter,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously retrieves a list of achievements for the current application from the Ready Games Network (RGN).
     * @param limit - An integer indicating the maximum number of achievements to retrieve.
     * @param startAfter - An optional parameter representing an achievement id after which to
     * start retrieving the achievements. The default is an empty string.
     * @param cancellationToken - A token to cancel the operation.
     * @return A Task representing the asynchronous operation. The Result property of the Task returns a list
     * of T:RGN.Modules.Achievement.AchievementData objects representing the achievements that match the current application identifier,
     * limit and other optional parameters.
     * @throw: Thrown when the provided limit value is zero.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="startAfter, cancellationToken"))
    static void GetForCurrentAppAsync(
        FAchievementsModuleGetForCurrentAppAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        int32 limit,
        const FString& startAfter = "") {
            int32_t cpp_limit;
            string cpp_startAfter;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_limit = limit;
            cpp_startAfter = string(TCHAR_TO_UTF8(*startAfter));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetForCurrentAppAsync(
                [onSuccess](vector<RGN::Modules::Achievement::AchievementData> response) {
                    TArray<FBP_AchievementData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_AchievementData b_response_item;
                        FBP_AchievementData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_limit,
                cpp_startAfter,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="startAfter, withHistory, cancellationToken"))
    static void GetByAppIdsWithUserDataAsync(
        FAchievementsModuleGetByAppIdsWithUserDataAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& appIds,
        int32 limit,
        const FString& startAfter = "",
        bool withHistory = false) {
            vector<string> cpp_appIds;
            int32_t cpp_limit;
            string cpp_startAfter;
            bool cpp_withHistory;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& appIds_item : appIds) {
                string cpp_appIds_item;
                cpp_appIds_item = string(TCHAR_TO_UTF8(*appIds_item));
                cpp_appIds.push_back(cpp_appIds_item);
            }
            cpp_limit = limit;
            cpp_startAfter = string(TCHAR_TO_UTF8(*startAfter));
            cpp_withHistory = withHistory;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetByAppIdsWithUserDataAsync(
                [onSuccess](vector<RGN::Modules::Achievement::AchievementWithUserData> response) {
                    TArray<FBP_AchievementWithUserData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_AchievementWithUserData b_response_item;
                        FBP_AchievementWithUserData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_appIds,
                cpp_limit,
                cpp_startAfter,
                cpp_withHistory,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="startAfter, withHistory, cancellationToken"))
    static void GetByTagsWithUserDataAsync(
        FAchievementsModuleGetByTagsWithUserDataAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& tags,
        int32 limit,
        int64 startAfter = 0,
        bool withHistory = false) {
            vector<string> cpp_tags;
            int32_t cpp_limit;
            int64_t cpp_startAfter;
            bool cpp_withHistory;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& tags_item : tags) {
                string cpp_tags_item;
                cpp_tags_item = string(TCHAR_TO_UTF8(*tags_item));
                cpp_tags.push_back(cpp_tags_item);
            }
            cpp_limit = limit;
            cpp_startAfter = startAfter;
            cpp_withHistory = withHistory;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetByTagsWithUserDataAsync(
                [onSuccess](vector<RGN::Modules::Achievement::AchievementWithUserData> response) {
                    TArray<FBP_AchievementWithUserData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_AchievementWithUserData b_response_item;
                        FBP_AchievementWithUserData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_tags,
                cpp_limit,
                cpp_startAfter,
                cpp_withHistory,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously retrieves a list of achievements for the current application from the Ready Games Network (RGN).
     * The user achievement data is also returned in case user made any progress with the given achievement
     * @param limit - An integer indicating the maximum number of achievements to retrieve.
     * @param startAfter - An optional parameter representing an achievement id after which to
     * start retrieving the achievements. The default is an empty string.
     * @param cancellationToken - A token to cancel the operation.
     * @return A Task representing the asynchronous operation. The Result property of the Task returns a list
     * of T:RGN.Modules.Achievement.AchievementWithUserData objects representing the achievements that match the current application identifier,
     * limit and other optional parameters.
     * @throw: Thrown when the provided limit value is zero.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="startAfter, cancellationToken"))
    static void GetForCurrentAppWithUserDataAsync(
        FAchievementsModuleGetForCurrentAppWithUserDataAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        int32 limit,
        const FString& startAfter = "") {
            int32_t cpp_limit;
            string cpp_startAfter;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_limit = limit;
            cpp_startAfter = string(TCHAR_TO_UTF8(*startAfter));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetForCurrentAppWithUserDataAsync(
                [onSuccess](vector<RGN::Modules::Achievement::AchievementWithUserData> response) {
                    TArray<FBP_AchievementWithUserData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_AchievementWithUserData b_response_item;
                        FBP_AchievementWithUserData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_limit,
                cpp_startAfter,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously retrieves a achievement from the Ready Games Network (RGN)
     * based on the provided achievement request name.
     * @param requestName - Request name to filter achievements.
     * @param cancellationToken - A token to cancel the operation.
     * @return A Task representing the asynchronous operation. The Result property of the Task returns a list of
     * T:RGN.Modules.Achievement.AchievementData objects representing the achievement that match the specified identifiers.
     * @throw: Thrown when the provided request name is null or empty.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetByRequestNameAsync(
        FAchievementsModuleGetByRequestNameAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& requestName) {
            string cpp_requestName;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_requestName = string(TCHAR_TO_UTF8(*requestName));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetByRequestNameAsync(
                [onSuccess](RGN::Modules::Achievement::AchievementData response) {
                    FBP_AchievementData bpResponse;
                    FBP_AchievementData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_requestName,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetByRequestNamesAsync(
        FAchievementsModuleGetByRequestNamesAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& requestNames) {
            vector<string> cpp_requestNames;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& requestNames_item : requestNames) {
                string cpp_requestNames_item;
                cpp_requestNames_item = string(TCHAR_TO_UTF8(*requestNames_item));
                cpp_requestNames.push_back(cpp_requestNames_item);
            }
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetByRequestNamesAsync(
                [onSuccess](vector<RGN::Modules::Achievement::AchievementData> response) {
                    TArray<FBP_AchievementData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_AchievementData b_response_item;
                        FBP_AchievementData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_requestNames,
                cpp_cancellationToken);
    }
    /**
     * Triggers the achievement by id to make achievement progress
     * @param id - The achievement id to trigger
     * @param progress - The achievement trigger progress delta
     * @param cancellationToken - A token to cancel the operation.
     * @return Trigger and Claim response data
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="progress, cancellationToken"))
    static void TriggerByIdAsync(
        FAchievementsModuleTriggerByIdAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& id,
        int32 progress = 1) {
            string cpp_id;
            int32_t cpp_progress;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_id = string(TCHAR_TO_UTF8(*id));
            cpp_progress = progress;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::TriggerByIdAsync(
                [onSuccess](RGN::Modules::Achievement::TriggerAndClaimResponse response) {
                    FBP_TriggerAndClaimResponse bpResponse;
                    FBP_TriggerAndClaimResponse::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_id,
                cpp_progress,
                cpp_cancellationToken);
    }
    /**
     * Triggers the achievement by request name to make achievement progress
     * @param requestName - The achievement request name to trigger
     * @param progress - The achievement trigger progress delta
     * @param cancellationToken - A token to cancel the operation.
     * @return Trigger and Claim response data
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="progress, cancellationToken"))
    static void TriggerByRequestNameAsync(
        FAchievementsModuleTriggerByRequestNameAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& requestName,
        int32 progress = 1) {
            string cpp_requestName;
            int32_t cpp_progress;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_requestName = string(TCHAR_TO_UTF8(*requestName));
            cpp_progress = progress;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::TriggerByRequestNameAsync(
                [onSuccess](RGN::Modules::Achievement::TriggerAndClaimResponse response) {
                    FBP_TriggerAndClaimResponse bpResponse;
                    FBP_TriggerAndClaimResponse::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_requestName,
                cpp_progress,
                cpp_cancellationToken);
    }
    /**
     * Claim the achievement to give rewards to the user
     * For more information about the rewards see T:RGN.Modules.Achievement.AchievementData class
     * @param achievementId - The achievement id to trigger
     * @param cancellationToken - A token to cancel the operation.
     * @return Trigger and Claim response data
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void ClaimByIdAsync(
        FAchievementsModuleClaimByIdAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& achievementId) {
            string cpp_achievementId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_achievementId = string(TCHAR_TO_UTF8(*achievementId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::ClaimByIdAsync(
                [onSuccess](RGN::Modules::Achievement::TriggerAndClaimResponse response) {
                    FBP_TriggerAndClaimResponse bpResponse;
                    FBP_TriggerAndClaimResponse::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementId,
                cpp_cancellationToken);
    }
    /**
     * Claim the achievement to give rewards to the user
     * For more information about the rewards see T:RGN.Modules.Achievement.AchievementData class
     * @param requestName - The achievement id to trigger
     * @param cancellationToken - A token to cancel the operation.
     * @return Trigger and Claim response data
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void ClaimByRequestNameAsync(
        FAchievementsModuleClaimByRequestNameAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& requestName) {
            string cpp_requestName;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_requestName = string(TCHAR_TO_UTF8(*requestName));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::ClaimByRequestNameAsync(
                [onSuccess](RGN::Modules::Achievement::TriggerAndClaimResponse response) {
                    FBP_TriggerAndClaimResponse bpResponse;
                    FBP_TriggerAndClaimResponse::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_requestName,
                cpp_cancellationToken);
    }
    /**
     * Retrieves currently active achievements for a project.
     * @param cancellationToken - A token to cancel the operation.
     * @return Project achievements setting for different events
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetProjectAchievementsAsync(
        FAchievementsModuleGetProjectAchievementsAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken) {
            RGN::CancellationToken cpp_cancellationToken;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetProjectAchievementsAsync(
                [onSuccess](RGN::Modules::Achievement::GetProjectAchievementsResponse response) {
                    FBP_GetProjectAchievementsResponse bpResponse;
                    FBP_GetProjectAchievementsResponse::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_cancellationToken);
    }
    /**
     * Gets in progress or completed user achievements
     * If the userId is provided, then it returns the completed achievements for provided userId
     * Supports pagination queries in case the startAfter and limit are provided
     * @param userId - User id to return the achievements
     * @param withHistory - Should populate returned achievements by completion history
     * @param startAfter - The time stamp to start the query after F:RGN.Modules.Achievement.UserAchievement.lastCompleteTime
     * @param limit - Maximal number of documents to return
     * @param cancellationToken - A token to cancel the operation.
     * @return Requested amount of achievements
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="userId, withHistory, startAfter, limit, cancellationToken"))
    static void GetUserAchievementsAsync(
        FAchievementsModuleGetUserAchievementsAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& userId = "",
        bool withHistory = false,
        int64 startAfter = 9223372036854775807,
        int32 limit = 2147483647) {
            string cpp_userId;
            bool cpp_withHistory;
            int64_t cpp_startAfter;
            int32_t cpp_limit;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_userId = string(TCHAR_TO_UTF8(*userId));
            cpp_withHistory = withHistory;
            cpp_startAfter = startAfter;
            cpp_limit = limit;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetUserAchievementsAsync(
                [onSuccess](vector<RGN::Modules::Achievement::UserAchievement> response) {
                    TArray<FBP_UserAchievement> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_UserAchievement b_response_item;
                        FBP_UserAchievement::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_userId,
                cpp_withHistory,
                cpp_startAfter,
                cpp_limit,
                cpp_cancellationToken);
    }
    /**
     * Gets in progress or completed user achievement by id
     * If the userId is provided, then it returns the completed achievement for provided userId
     * @param achievementId - Achievement id to return
     * @param userId - User id to return the achievement
     * @param withHistory - Should populate returned achievement by completion history
     * @param cancellationToken - A token to cancel the operation.
     * @return Requested user achievement
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="userId, withHistory, cancellationToken"))
    static void GetUserAchievementByIdAsync(
        FAchievementsModuleGetUserAchievementByIdAsyncResponse onSuccess,
        FAchievementsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& achievementId,
        const FString& userId = "",
        bool withHistory = false) {
            string cpp_achievementId;
            string cpp_userId;
            bool cpp_withHistory;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_achievementId = string(TCHAR_TO_UTF8(*achievementId));
            cpp_userId = string(TCHAR_TO_UTF8(*userId));
            cpp_withHistory = withHistory;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule::GetUserAchievementByIdAsync(
                [onSuccess](RGN::Modules::Achievement::UserAchievement response) {
                    FBP_UserAchievement bpResponse;
                    FBP_UserAchievement::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementId,
                cpp_userId,
                cpp_withHistory,
                cpp_cancellationToken);
    }
};
