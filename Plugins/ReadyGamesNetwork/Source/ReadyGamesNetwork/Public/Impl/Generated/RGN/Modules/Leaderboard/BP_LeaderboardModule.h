#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardModule.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardData.h"
#include "BP_LeaderboardData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardsResponse.h"
#include "BP_GetLeaderboardsResponse.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardIdsResponseData.h"
#include "BP_GetLeaderboardIdsResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/IsLeaderboardAvailableResponseData.h"
#include "BP_IsLeaderboardAvailableResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/IsInPromoPeriodResponseData.h"
#include "BP_IsInPromoPeriodResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/IsInGracePeriodResponseData.h"
#include "BP_IsInGracePeriodResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/SetScoreResponseData.h"
#include "BP_SetScoreResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardEntry.h"
#include "BP_LeaderboardEntry.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardEntriesResponseData.h"
#include "BP_GetLeaderboardEntriesResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardResetsResponseData.h"
#include "BP_GetLeaderboardResetsResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardReset.h"
#include "BP_LeaderboardReset.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardResetResponseData.h"
#include "BP_GetLeaderboardResetResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_LeaderboardModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FLeaderboardModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetLeaderboardByIdAsyncResponse, const FBP_LeaderboardData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetLeaderboardByRequestNameAsyncResponse, const FBP_LeaderboardData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetLeaderboardByRequestNamesAsyncResponse, const TArray<FBP_LeaderboardData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetLeaderboardByAppIdsAsyncResponse, const TArray<FBP_LeaderboardData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetLeaderboardByTagsAsyncResponse, const TArray<FBP_LeaderboardData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetLeaderboardByIdsAsyncResponse, const TArray<FBP_LeaderboardData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetLeaderboardForCurrentAppAsyncResponse, const TArray<FBP_LeaderboardData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetLeaderboardIdsAsyncResponse, const TArray<FString>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleIsLeaderboardAvailableAsyncResponse, const FBP_IsLeaderboardAvailableResponseData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleIsInPromoPeriodAsyncResponse, const FBP_IsInPromoPeriodResponseData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleIsInGracePeriodAsyncResponse, const FBP_IsInGracePeriodResponseData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleSetScoreAsyncResponse, int32, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleAddScoreAsyncResponse, int32, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetUserEntryAsyncResponse, const FBP_LeaderboardEntry&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetEntriesAsyncResponse, const TArray<FBP_LeaderboardEntry>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetResetsAsyncResponse, const TArray<FBP_LeaderboardReset>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleGetResetAsyncResponse, const FBP_LeaderboardReset&, response);
DECLARE_DYNAMIC_DELEGATE(FLeaderboardModuleResetLeaderboardAsyncResponse);

UCLASS()
class READYGAMESNETWORK_API UBP_LeaderboardModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    /**
     * Asynchronous method that retrieves leaderboard data.
     * Resulting Data contains leaderboard description fields like id, name, type, etc.
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetLeaderboardByIdAsync(
        FLeaderboardModuleGetLeaderboardByIdAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& id) {
            string cpp_id;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_id = string(TCHAR_TO_UTF8(*id));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByIdAsync(
                [onSuccess](RGN::Modules::Leaderboard::LeaderboardData response) {
                    FBP_LeaderboardData bpResponse;
                    FBP_LeaderboardData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_id,
                cpp_cancellationToken);
    }
    /**
     * Asynchronous method that retrieves leaderboard data.
     * Resulting Data contains leaderboard description fields like id, name, type, etc.
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetLeaderboardByRequestNameAsync(
        FLeaderboardModuleGetLeaderboardByRequestNameAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& requestName) {
            string cpp_requestName;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_requestName = string(TCHAR_TO_UTF8(*requestName));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByRequestNameAsync(
                [onSuccess](RGN::Modules::Leaderboard::LeaderboardData response) {
                    FBP_LeaderboardData bpResponse;
                    FBP_LeaderboardData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_requestName,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="startAfter, ignoreTimestamp, cancellationToken"))
    static void GetLeaderboardByRequestNamesAsync(
        FLeaderboardModuleGetLeaderboardByRequestNamesAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& requestNames,
        int32 limit,
        int64 startAfter = 0,
        bool ignoreTimestamp = false) {
            vector<string> cpp_requestNames;
            int32_t cpp_limit;
            int64_t cpp_startAfter;
            bool cpp_ignoreTimestamp;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& requestNames_item : requestNames) {
                string cpp_requestNames_item;
                cpp_requestNames_item = string(TCHAR_TO_UTF8(*requestNames_item));
                cpp_requestNames.push_back(cpp_requestNames_item);
            }
            cpp_limit = limit;
            cpp_startAfter = startAfter;
            cpp_ignoreTimestamp = ignoreTimestamp;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByRequestNamesAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardData> response) {
                    TArray<FBP_LeaderboardData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_LeaderboardData b_response_item;
                        FBP_LeaderboardData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_requestNames,
                cpp_limit,
                cpp_startAfter,
                cpp_ignoreTimestamp,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="startAfter, ignoreTimestamp, cancellationToken"))
    static void GetLeaderboardByAppIdsAsync(
        FLeaderboardModuleGetLeaderboardByAppIdsAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& appIds,
        int32 limit,
        int64 startAfter = 0,
        bool ignoreTimestamp = false) {
            vector<string> cpp_appIds;
            int32_t cpp_limit;
            int64_t cpp_startAfter;
            bool cpp_ignoreTimestamp;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& appIds_item : appIds) {
                string cpp_appIds_item;
                cpp_appIds_item = string(TCHAR_TO_UTF8(*appIds_item));
                cpp_appIds.push_back(cpp_appIds_item);
            }
            cpp_limit = limit;
            cpp_startAfter = startAfter;
            cpp_ignoreTimestamp = ignoreTimestamp;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByAppIdsAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardData> response) {
                    TArray<FBP_LeaderboardData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_LeaderboardData b_response_item;
                        FBP_LeaderboardData::ConvertToUnrealModel(response_item, b_response_item);
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
                cpp_ignoreTimestamp,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="startAfter, ignoreTimestamp, cancellationToken"))
    static void GetLeaderboardByTagsAsync(
        FLeaderboardModuleGetLeaderboardByTagsAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& tags,
        int32 limit,
        int64 startAfter = 0,
        bool ignoreTimestamp = false) {
            vector<string> cpp_tags;
            int32_t cpp_limit;
            int64_t cpp_startAfter;
            bool cpp_ignoreTimestamp;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& tags_item : tags) {
                string cpp_tags_item;
                cpp_tags_item = string(TCHAR_TO_UTF8(*tags_item));
                cpp_tags.push_back(cpp_tags_item);
            }
            cpp_limit = limit;
            cpp_startAfter = startAfter;
            cpp_ignoreTimestamp = ignoreTimestamp;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByTagsAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardData> response) {
                    TArray<FBP_LeaderboardData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_LeaderboardData b_response_item;
                        FBP_LeaderboardData::ConvertToUnrealModel(response_item, b_response_item);
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
                cpp_ignoreTimestamp,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="startAfter, ignoreTimestamp, cancellationToken"))
    static void GetLeaderboardByIdsAsync(
        FLeaderboardModuleGetLeaderboardByIdsAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& ids,
        int32 limit,
        int64 startAfter = 0,
        bool ignoreTimestamp = false) {
            vector<string> cpp_ids;
            int32_t cpp_limit;
            int64_t cpp_startAfter;
            bool cpp_ignoreTimestamp;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& ids_item : ids) {
                string cpp_ids_item;
                cpp_ids_item = string(TCHAR_TO_UTF8(*ids_item));
                cpp_ids.push_back(cpp_ids_item);
            }
            cpp_limit = limit;
            cpp_startAfter = startAfter;
            cpp_ignoreTimestamp = ignoreTimestamp;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByIdsAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardData> response) {
                    TArray<FBP_LeaderboardData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_LeaderboardData b_response_item;
                        FBP_LeaderboardData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_ids,
                cpp_limit,
                cpp_startAfter,
                cpp_ignoreTimestamp,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously retrieves a list of leaderboards for the current application from the Ready Games Network (RGN).
     * @param limit - An integer indicating the maximum number of leaderboards to retrieve.
     * @param startAfter - An optional parameter representing a leaderboard 'updatedAt' field after which start the retrieval
     * @param ignoreTimestamp - An optional parameter that indicates whether to ignore the timestamp in the leaderboard
     * retrieval process. The default is false.
     * @param cancellationToken - A token to cancel the operation.
     * @return A Task representing the asynchronous operation. The Result property of the Task returns a list
     * of T:RGN.Modules.Leaderboard.LeaderboardData objects representing the leaderboards that match the current application identifier,
     * limit and other optional parameters.
     * @throw: Thrown when the provided limit value is zero.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="startAfter, ignoreTimestamp, cancellationToken"))
    static void GetLeaderboardForCurrentAppAsync(
        FLeaderboardModuleGetLeaderboardForCurrentAppAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        int32 limit,
        int64 startAfter = 0,
        bool ignoreTimestamp = false) {
            int32_t cpp_limit;
            int64_t cpp_startAfter;
            bool cpp_ignoreTimestamp;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_limit = limit;
            cpp_startAfter = startAfter;
            cpp_ignoreTimestamp = ignoreTimestamp;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardForCurrentAppAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardData> response) {
                    TArray<FBP_LeaderboardData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_LeaderboardData b_response_item;
                        FBP_LeaderboardData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_limit,
                cpp_startAfter,
                cpp_ignoreTimestamp,
                cpp_cancellationToken);
    }
    /**
     * Method to retrieve leaderboard ids defined for current project
     * @param ignoreTimestamp - An optional parameter that indicates whether to ignore the timestamp in the leaderboard
     * retrieval process. The default is false.
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="ignoreTimestamp, cancellationToken"))
    static void GetLeaderboardIdsAsync(
        FLeaderboardModuleGetLeaderboardIdsAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        bool ignoreTimestamp = false) {
            bool cpp_ignoreTimestamp;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_ignoreTimestamp = ignoreTimestamp;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardIdsAsync(
                [onSuccess](vector<string> response) {
                    TArray<FString> bpResponse;
                    for (const auto& response_item : response) {
                        FString b_response_item;
                        b_response_item = FString(UTF8_TO_TCHAR(response_item.c_str()));
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_ignoreTimestamp,
                cpp_cancellationToken);
    }
    /**
     * Method to retrieve available status of leaderboard
     * @param leaderboardId - The ID of the leaderboard which status will be checked.
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void IsLeaderboardAvailableAsync(
        FLeaderboardModuleIsLeaderboardAvailableAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId) {
            string cpp_leaderboardId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::IsLeaderboardAvailableAsync(
                [onSuccess](RGN::Modules::Leaderboard::IsLeaderboardAvailableResponseData response) {
                    FBP_IsLeaderboardAvailableResponseData bpResponse;
                    FBP_IsLeaderboardAvailableResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_cancellationToken);
    }
    /**
     * Method to retrieve available status of leaderboard
     * @param leaderboardId - The ID of the leaderboard which status will be checked.
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void IsInPromoPeriodAsync(
        FLeaderboardModuleIsInPromoPeriodAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId) {
            string cpp_leaderboardId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::IsInPromoPeriodAsync(
                [onSuccess](RGN::Modules::Leaderboard::IsInPromoPeriodResponseData response) {
                    FBP_IsInPromoPeriodResponseData bpResponse;
                    FBP_IsInPromoPeriodResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_cancellationToken);
    }
    /**
     * Method to retrieve available status of leaderboard
     * @param leaderboardId - The ID of the leaderboard which status will be checked.
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void IsInGracePeriodAsync(
        FLeaderboardModuleIsInGracePeriodAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId) {
            string cpp_leaderboardId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::IsInGracePeriodAsync(
                [onSuccess](RGN::Modules::Leaderboard::IsInGracePeriodResponseData response) {
                    FBP_IsInGracePeriodResponseData bpResponse;
                    FBP_IsInGracePeriodResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously sets the player's score on the specified leaderboard.
     * @param leaderboardId - The ID of the leaderboard where the score will be set.
     * @param score - The score to be set on the leaderboard.
     * @param extraData - (Optional) Extra data associated with the score. Defaults to an empty string if not provided.
     * @param cancellationToken - A token to cancel the operation.
     * @return A task that represents the asynchronous operation. The task result contains the player's place after setting the score.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="extraData, cancellationToken"))
    static void SetScoreAsync(
        FLeaderboardModuleSetScoreAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId,
        int32 score,
        const FString& extraData = "") {
            string cpp_leaderboardId;
            int32_t cpp_score;
            string cpp_extraData;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            cpp_score = score;
            cpp_extraData = string(TCHAR_TO_UTF8(*extraData));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::SetScoreAsync(
                [onSuccess](int32_t response) {
                    int32 bpResponse;
                    bpResponse = response;
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_score,
                cpp_extraData,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously adds the player's score on the specified leaderboard.
     * @param leaderboardId - The ID of the leaderboard where the score will be added.
     * @param score - The score to be added on the leaderboard.
     * @param extraData - (Optional) Extra data associated with the score. Defaults to an empty string if not provided.
     * @param cancellationToken - A token to cancel the operation.
     * @return A task that represents the asynchronous operation. The task result contains the player's place after setting the score.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="extraData, cancellationToken"))
    static void AddScoreAsync(
        FLeaderboardModuleAddScoreAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId,
        int32 score,
        const FString& extraData = "") {
            string cpp_leaderboardId;
            int32_t cpp_score;
            string cpp_extraData;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            cpp_score = score;
            cpp_extraData = string(TCHAR_TO_UTF8(*extraData));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::AddScoreAsync(
                [onSuccess](int32_t response) {
                    int32 bpResponse;
                    bpResponse = response;
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_score,
                cpp_extraData,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously retrieves the player's entry on the specified leaderboard.
     * @param leaderboardId - The ID of the leaderboard from which the entry will be retrieved.
     * @param cancellationToken - A token to cancel the operation.
     * @return A task that represents the asynchronous operation. The task result contains the player's entry data on the leaderboard.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetUserEntryAsync(
        FLeaderboardModuleGetUserEntryAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId) {
            string cpp_leaderboardId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetUserEntryAsync(
                [onSuccess](RGN::Modules::Leaderboard::LeaderboardEntry response) {
                    FBP_LeaderboardEntry bpResponse;
                    FBP_LeaderboardEntry::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously retrieves a specified number of top entries and entries around the user from the specified leaderboard.
     * @param leaderboardId - The ID of the leaderboard from which the entries will be retrieved.
     * @param quantityTop - The number of top entries to retrieve from the leaderboard.
     * @param includeUser - Whether to include the user's entry in the retrieved entries.
     * @param quantityAroundUser - The number of entries to retrieve around the user's entry.
     * @param cancellationToken - A token to cancel the operation.
     * @return A task that represents the asynchronous operation. The task result contains a list of the retrieved leaderboard entries.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetEntriesAsync(
        FLeaderboardModuleGetEntriesAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId,
        int32 quantityTop,
        bool includeUser,
        int32 quantityAroundUser) {
            string cpp_leaderboardId;
            int32_t cpp_quantityTop;
            bool cpp_includeUser;
            int32_t cpp_quantityAroundUser;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            cpp_quantityTop = quantityTop;
            cpp_includeUser = includeUser;
            cpp_quantityAroundUser = quantityAroundUser;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetEntriesAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardEntry> response) {
                    TArray<FBP_LeaderboardEntry> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_LeaderboardEntry b_response_item;
                        FBP_LeaderboardEntry::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_quantityTop,
                cpp_includeUser,
                cpp_quantityAroundUser,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously retrieves leaderboard resets. Every time the leaderboard resets the results are stored in the history.
     * This method allows to retreive the history of the leaderboard resets.
     * @param leaderboardId - The ID of the leaderboard from which the entries will be retrieved.
     * @param withEntries - Flag to include user entries in the response.
     * @param startAfter - The start time in milliseconds since midnight, January 1, 1970 UTC, based on 'resetAt'.
     * @param limit - The maximum number of resets to retrieve.
     * @param orderDirection - The order direction for the resets. Accepted values 'asc' or 'desc'.
     * @param cancellationToken - A token to cancel the operation.
     * @return A task that represents the asynchronous operation. The task result contains a list of the retrieved leaderboard resets.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="startAfter, limit, orderDirection, cancellationToken"))
    static void GetResetsAsync(
        FLeaderboardModuleGetResetsAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId,
        bool withEntries,
        int64 startAfter = -1,
        int32 limit = -1,
        const FString& orderDirection = "asc") {
            string cpp_leaderboardId;
            bool cpp_withEntries;
            int64_t cpp_startAfter;
            int32_t cpp_limit;
            string cpp_orderDirection;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            cpp_withEntries = withEntries;
            cpp_startAfter = startAfter;
            cpp_limit = limit;
            cpp_orderDirection = string(TCHAR_TO_UTF8(*orderDirection));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetResetsAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardReset> response) {
                    TArray<FBP_LeaderboardReset> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_LeaderboardReset b_response_item;
                        FBP_LeaderboardReset::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_withEntries,
                cpp_startAfter,
                cpp_limit,
                cpp_orderDirection,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously retrieves leaderboard reset by leaderboard and reset IDs. The result includes the user entries.
     * @param leaderboardId - The ID of the leaderboard from which the reset user entries will be retrieved.
     * @param resetId - The unique reset ID of the leaderboard
     * @param startAfter - The start after based on 'place'.
     * @param limit - The maximum number of user entries to retrieve.
     * @param orderDirection - The order direction for the user entries. Accepted values 'asc' or 'desc'.
     * @param cancellationToken - A token to cancel the operation.
     * @return A task that represents the asynchronous operation. The task result contains the retrieved leaderboard reset with user entries.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="startAfter, limit, orderDirection, cancellationToken"))
    static void GetResetAsync(
        FLeaderboardModuleGetResetAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId,
        const FString& resetId,
        int64 startAfter = 0,
        int32 limit = 0,
        const FString& orderDirection = "asc") {
            string cpp_leaderboardId;
            string cpp_resetId;
            int64_t cpp_startAfter;
            int32_t cpp_limit;
            string cpp_orderDirection;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            cpp_resetId = string(TCHAR_TO_UTF8(*resetId));
            cpp_startAfter = startAfter;
            cpp_limit = limit;
            cpp_orderDirection = string(TCHAR_TO_UTF8(*orderDirection));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::GetResetAsync(
                [onSuccess](RGN::Modules::Leaderboard::LeaderboardReset response) {
                    FBP_LeaderboardReset bpResponse;
                    FBP_LeaderboardReset::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_resetId,
                cpp_startAfter,
                cpp_limit,
                cpp_orderDirection,
                cpp_cancellationToken);
    }
    /**
     * Reset leaderboard. Gives the rewards to the users and resets the leaderboard.
     * Requires project admin access.
     * @param leaderboardId - The ID of the leaderboard to reset.
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void ResetLeaderboardAsync(
        FLeaderboardModuleResetLeaderboardAsyncResponse onSuccess,
        FLeaderboardModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId) {
            string cpp_leaderboardId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule::ResetLeaderboardAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_cancellationToken);
    }
};
