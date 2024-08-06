#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementsModule_Admin.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementData.h"
#include "BP_AchievementData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_AchievementsModule_Admin.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FAchievementsModule_AdminFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleAdminAddAchievementAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAchievementsModuleAdminUpdateAchievementAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE(FAchievementsModuleAdminDeleteAchievementAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FAchievementsModuleAdminAddLoginDaysInRowAchievementAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FAchievementsModuleAdminDeleteLoginDaysInRowGameConstRecordAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FAchievementsModuleAdminAddPlayerProgressAchievementAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FAchievementsModuleAdminDeletePlayerProgressAchievementAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FAchievementsModuleAdminAddPurchaseAchievementAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FAchievementsModuleAdminDeletePurchaseGameConstRecordAsyncResponse);

UCLASS()
class READYGAMESNETWORK_API UBP_AchievementsModule_Admin : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void AddAchievementAsync(
        FAchievementsModuleAdminAddAchievementAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FBP_AchievementData& achievementData) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            RGN::CancellationToken cpp_cancellationToken;
            FBP_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::AddAchievementAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementData,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void UpdateAchievementAsync(
        FAchievementsModuleAdminUpdateAchievementAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FBP_AchievementData& achievementData) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            RGN::CancellationToken cpp_cancellationToken;
            FBP_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::UpdateAchievementAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementData,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeleteAchievementAsync(
        FAchievementsModuleAdminDeleteAchievementAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& achievementId) {
            string cpp_achievementId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_achievementId = string(TCHAR_TO_UTF8(*achievementId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::DeleteAchievementAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementId,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void AddLoginDaysInRowAchievementAsync_AchievementId_DaysInRow_CancellationToken(
        FAchievementsModuleAdminAddLoginDaysInRowAchievementAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& achievementId,
        int32 daysInRow) {
            string cpp_achievementId;
            int32_t cpp_daysInRow;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_achievementId = string(TCHAR_TO_UTF8(*achievementId));
            cpp_daysInRow = daysInRow;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::AddLoginDaysInRowAchievementAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementId,
                cpp_daysInRow,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void AddLoginDaysInRowAchievementAsync_AchievementData_DaysInRow_CancellationToken(
        FAchievementsModuleAdminAddLoginDaysInRowAchievementAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FBP_AchievementData& achievementData,
        int32 daysInRow) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            int32_t cpp_daysInRow;
            RGN::CancellationToken cpp_cancellationToken;
            FBP_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            cpp_daysInRow = daysInRow;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::AddLoginDaysInRowAchievementAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementData,
                cpp_daysInRow,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeleteLoginDaysInRowGameConstRecordAsync(
        FAchievementsModuleAdminDeleteLoginDaysInRowGameConstRecordAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& achievementId,
        int32 daysInRow) {
            string cpp_achievementId;
            int32_t cpp_daysInRow;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_achievementId = string(TCHAR_TO_UTF8(*achievementId));
            cpp_daysInRow = daysInRow;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::DeleteLoginDaysInRowGameConstRecordAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementId,
                cpp_daysInRow,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void AddPlayerProgressAchievementAsync_AchievementId_PlayerProgressFieldName_PlayerProgressFieldValueToReach_CancellationToken(
        FAchievementsModuleAdminAddPlayerProgressAchievementAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& achievementId,
        const FString& playerProgressFieldName,
        int64 playerProgressFieldValueToReach) {
            string cpp_achievementId;
            string cpp_playerProgressFieldName;
            int64_t cpp_playerProgressFieldValueToReach;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_achievementId = string(TCHAR_TO_UTF8(*achievementId));
            cpp_playerProgressFieldName = string(TCHAR_TO_UTF8(*playerProgressFieldName));
            cpp_playerProgressFieldValueToReach = playerProgressFieldValueToReach;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::AddPlayerProgressAchievementAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementId,
                cpp_playerProgressFieldName,
                cpp_playerProgressFieldValueToReach,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void AddPlayerProgressAchievementAsync_AchievementData_PlayerProgressFieldName_PlayerProgressFieldValueToReach_CancellationToken(
        FAchievementsModuleAdminAddPlayerProgressAchievementAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FBP_AchievementData& achievementData,
        const FString& playerProgressFieldName,
        int64 playerProgressFieldValueToReach) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            string cpp_playerProgressFieldName;
            int64_t cpp_playerProgressFieldValueToReach;
            RGN::CancellationToken cpp_cancellationToken;
            FBP_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            cpp_playerProgressFieldName = string(TCHAR_TO_UTF8(*playerProgressFieldName));
            cpp_playerProgressFieldValueToReach = playerProgressFieldValueToReach;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::AddPlayerProgressAchievementAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementData,
                cpp_playerProgressFieldName,
                cpp_playerProgressFieldValueToReach,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeletePlayerProgressAchievementAsync(
        FAchievementsModuleAdminDeletePlayerProgressAchievementAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& achievementId,
        const FString& playerProgressFieldName,
        int64 playerProgressFieldValueToReach) {
            string cpp_achievementId;
            string cpp_playerProgressFieldName;
            int64_t cpp_playerProgressFieldValueToReach;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_achievementId = string(TCHAR_TO_UTF8(*achievementId));
            cpp_playerProgressFieldName = string(TCHAR_TO_UTF8(*playerProgressFieldName));
            cpp_playerProgressFieldValueToReach = playerProgressFieldValueToReach;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::DeletePlayerProgressAchievementAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementId,
                cpp_playerProgressFieldName,
                cpp_playerProgressFieldValueToReach,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void AddPurchaseAchievementAsync(
        FAchievementsModuleAdminAddPurchaseAchievementAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FBP_AchievementData& achievementData,
        const FString& virtualItemTag) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            string cpp_virtualItemTag;
            RGN::CancellationToken cpp_cancellationToken;
            FBP_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            cpp_virtualItemTag = string(TCHAR_TO_UTF8(*virtualItemTag));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::AddPurchaseAchievementAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementData,
                cpp_virtualItemTag,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Achievement", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeletePurchaseGameConstRecordAsync(
        FAchievementsModuleAdminDeletePurchaseGameConstRecordAsyncResponse onSuccess,
        FAchievementsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& achievementId,
        const FString& virtualItemTag) {
            string cpp_achievementId;
            string cpp_virtualItemTag;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_achievementId = string(TCHAR_TO_UTF8(*achievementId));
            cpp_virtualItemTag = string(TCHAR_TO_UTF8(*virtualItemTag));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Achievement::AchievementsModule_Admin::DeletePurchaseGameConstRecordAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_achievementId,
                cpp_virtualItemTag,
                cpp_cancellationToken);
    }
};
