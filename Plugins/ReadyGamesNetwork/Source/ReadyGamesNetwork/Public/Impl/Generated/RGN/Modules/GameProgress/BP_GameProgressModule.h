#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/GameProgressModule.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/BP_Currency.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/OnGameCompleteResult.h"
#include "BP_OnGameCompleteResult.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/OnGameCompleteRequestData.h"
#include "BP_OnGameCompleteRequestData.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/GameProgress.h"
#include "BP_GameProgress.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/BP_BaseMigrationRequestData.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/AddUserLevelRequestData.h"
#include "BP_AddUserLevelRequestData.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/UpdateUserLevelResponseData.h"
#include "BP_UpdateUserLevelResponseData.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/UpdateUserLevelRequestData.h"
#include "BP_UpdateUserLevelRequestData.h"
#include "../../../../../Generated/RGN/Modules/GameProgress/GetPlayerLevelResponseData.h"
#include "BP_GetPlayerLevelResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_GameProgressModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FGameProgressModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FGameProgressModuleOnGameCompleteAsyncResponse, const FBP_OnGameCompleteResult&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGameProgressModuleGetGameProgressAsyncResponse, const FBP_GameProgress&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGameProgressModuleAddUserProgressAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGameProgressModuleUpdateUserProgressAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGameProgressModuleGetUserProgressAsyncResponse, const FString&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_GameProgressModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GameProgress", meta=(AutoCreateRefTerm="cancellationToken"))
    static void OnGameCompleteAsync(
        FGameProgressModuleOnGameCompleteAsyncResponse onSuccess,
        FGameProgressModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FBP_Currency>& reward) {
            vector<RGN::Modules::Currency::Currency> cpp_reward;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& reward_item : reward) {
                RGN::Modules::Currency::Currency cpp_reward_item;
                FBP_Currency::ConvertToCoreModel(reward_item, cpp_reward_item);
                cpp_reward.push_back(cpp_reward_item);
            }
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GameProgress::GameProgressModule::OnGameCompleteAsync(
                [onSuccess](RGN::Modules::GameProgress::OnGameCompleteResult response) {
                    FBP_OnGameCompleteResult bpResponse;
                    FBP_OnGameCompleteResult::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_reward,
                cpp_cancellationToken);
    }
    /**
     * Gets the current user level.
     * @param cancellationToken - A token to cancel the operation.
     * @return User level
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GameProgress", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetGameProgressAsync(
        FGameProgressModuleGetGameProgressAsyncResponse onSuccess,
        FGameProgressModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken) {
            RGN::CancellationToken cpp_cancellationToken;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GameProgress::GameProgressModule::GetGameProgressAsync(
                [onSuccess](RGN::Modules::GameProgress::GameProgress response) {
                    FBP_GameProgress bpResponse;
                    FBP_GameProgress::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GameProgress", meta=(AutoCreateRefTerm="cancellationToken"))
    static void AddUserProgressAsync(
        FGameProgressModuleAddUserProgressAsyncResponse onSuccess,
        FGameProgressModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& userProgressJson) {
            string cpp_userProgressJson;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_userProgressJson = string(TCHAR_TO_UTF8(*userProgressJson));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GameProgress::GameProgressModule::AddUserProgressAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_userProgressJson,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GameProgress", meta=(AutoCreateRefTerm="cancellationToken"))
    static void UpdateUserProgressAsync(
        FGameProgressModuleUpdateUserProgressAsyncResponse onSuccess,
        FGameProgressModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& userProgressJson,
        const TArray<FBP_Currency>& reward) {
            string cpp_userProgressJson;
            vector<RGN::Modules::Currency::Currency> cpp_reward;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_userProgressJson = string(TCHAR_TO_UTF8(*userProgressJson));
            for (const auto& reward_item : reward) {
                RGN::Modules::Currency::Currency cpp_reward_item;
                FBP_Currency::ConvertToCoreModel(reward_item, cpp_reward_item);
                cpp_reward.push_back(cpp_reward_item);
            }
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GameProgress::GameProgressModule::UpdateUserProgressAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_userProgressJson,
                cpp_reward,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GameProgress", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetUserProgressAsync(
        FGameProgressModuleGetUserProgressAsyncResponse onSuccess,
        FGameProgressModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken) {
            RGN::CancellationToken cpp_cancellationToken;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GameProgress::GameProgressModule::GetUserProgressAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_cancellationToken);
    }
};
