#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassModule_Admin.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassData.h"
#include "BP_GamePassData.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassUserData.h"
#include "BP_GamePassUserData.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GetGamePassUserDataResponseData.h"
#include "BP_GetGamePassUserDataResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_GamePassModule_Admin.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FGamePassModule_AdminFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FGamePassModuleAdminAddAsyncResponse, const FBP_GamePassData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGamePassModuleAdminDeleteAsyncResponse, const FBP_GamePassData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGamePassModuleAdminAddToUserAsyncResponse, const FBP_GamePassUserData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGamePassModuleAdminDeleteFromUserAsyncResponse, const TArray<FBP_GamePassUserData>&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_GamePassModule_Admin : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GamePass", meta=(AutoCreateRefTerm="cancellationToken"))
    static void AddAsync(
        FGamePassModuleAdminAddAsyncResponse onSuccess,
        FGamePassModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FBP_GamePassData& gamepassData) {
            RGN::Modules::GamePass::GamePassData cpp_gamepassData;
            RGN::CancellationToken cpp_cancellationToken;
            FBP_GamePassData::ConvertToCoreModel(gamepassData, cpp_gamepassData);
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GamePass::GamePassModule_Admin::AddAsync(
                [onSuccess](RGN::Modules::GamePass::GamePassData response) {
                    FBP_GamePassData bpResponse;
                    FBP_GamePassData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_gamepassData,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GamePass", meta=(AutoCreateRefTerm="id, requestName, cancellationToken"))
    static void DeleteAsync(
        FGamePassModuleAdminDeleteAsyncResponse onSuccess,
        FGamePassModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& id = "",
        const FString& requestName = "") {
            string cpp_id;
            string cpp_requestName;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_id = string(TCHAR_TO_UTF8(*id));
            cpp_requestName = string(TCHAR_TO_UTF8(*requestName));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GamePass::GamePassModule_Admin::DeleteAsync(
                [onSuccess](RGN::Modules::GamePass::GamePassData response) {
                    FBP_GamePassData bpResponse;
                    FBP_GamePassData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_id,
                cpp_requestName,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GamePass", meta=(AutoCreateRefTerm="id, requestName, userId, cancellationToken"))
    static void AddToUserAsync(
        FGamePassModuleAdminAddToUserAsyncResponse onSuccess,
        FGamePassModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& id = "",
        const FString& requestName = "",
        const FString& userId = "") {
            string cpp_id;
            string cpp_requestName;
            string cpp_userId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_id = string(TCHAR_TO_UTF8(*id));
            cpp_requestName = string(TCHAR_TO_UTF8(*requestName));
            cpp_userId = string(TCHAR_TO_UTF8(*userId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GamePass::GamePassModule_Admin::AddToUserAsync(
                [onSuccess](RGN::Modules::GamePass::GamePassUserData response) {
                    FBP_GamePassUserData bpResponse;
                    FBP_GamePassUserData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_id,
                cpp_requestName,
                cpp_userId,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GamePass", meta=(AutoCreateRefTerm="id, requestName, userId, cancellationToken"))
    static void DeleteFromUserAsync(
        FGamePassModuleAdminDeleteFromUserAsyncResponse onSuccess,
        FGamePassModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& id = "",
        const FString& requestName = "",
        const FString& userId = "") {
            string cpp_id;
            string cpp_requestName;
            string cpp_userId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_id = string(TCHAR_TO_UTF8(*id));
            cpp_requestName = string(TCHAR_TO_UTF8(*requestName));
            cpp_userId = string(TCHAR_TO_UTF8(*userId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GamePass::GamePassModule_Admin::DeleteFromUserAsync(
                [onSuccess](vector<RGN::Modules::GamePass::GamePassUserData> response) {
                    TArray<FBP_GamePassUserData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_GamePassUserData b_response_item;
                        FBP_GamePassUserData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_id,
                cpp_requestName,
                cpp_userId,
                cpp_cancellationToken);
    }
};
