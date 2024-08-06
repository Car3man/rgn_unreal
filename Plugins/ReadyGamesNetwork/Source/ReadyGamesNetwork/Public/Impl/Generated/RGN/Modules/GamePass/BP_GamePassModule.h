#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassModule.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassData.h"
#include "BP_GamePassData.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GetForCurrentAppResponseData.h"
#include "BP_GetForCurrentAppResponseData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/BP_BaseRequestData.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GetGamePassUserDataResponseData.h"
#include "BP_GetGamePassUserDataResponseData.h"
#include "../../../../../Generated/RGN/Modules/GamePass/GamePassUserData.h"
#include "BP_GamePassUserData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_GamePassModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FGamePassModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FGamePassModuleGetAsyncResponse, const FBP_GamePassData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGamePassModuleGetForCurrentAppAsyncResponse, const TArray<FBP_GamePassData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGamePassModuleGetForUserAsyncResponse, const TArray<FBP_GamePassUserData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGamePassModuleGetAllForUserAsyncResponse, const TArray<FBP_GamePassUserData>&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_GamePassModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    /**
     * Retrieves a GamePassData instance asynchronously based on the provided identifier or request name.
     * @param id - The unique identifier for the game pass to retrieve. Optional.
     * @param requestName - The request name associated with the game pass to retrieve. Optional.
     * @param cancellationToken - A token to cancel the operation.
     * @return The requested GamePassData instance.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GamePass", meta=(AutoCreateRefTerm="id, requestName, cancellationToken"))
    static void GetAsync(
        FGamePassModuleGetAsyncResponse onSuccess,
        FGamePassModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& id = "",
        const FString& requestName = "") {
            string cpp_id;
            string cpp_requestName;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_id = string(TCHAR_TO_UTF8(*id));
            cpp_requestName = string(TCHAR_TO_UTF8(*requestName));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GamePass::GamePassModule::GetAsync(
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
    /**
     * Retrieves a list of GamePassData instances for the current application asynchronously.
     * @param cancellationToken - A token to cancel the operation.
     * @return A list of GamePassData associated with the current application.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GamePass", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetForCurrentAppAsync(
        FGamePassModuleGetForCurrentAppAsyncResponse onSuccess,
        FGamePassModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken) {
            RGN::CancellationToken cpp_cancellationToken;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GamePass::GamePassModule::GetForCurrentAppAsync(
                [onSuccess](vector<RGN::Modules::GamePass::GamePassData> response) {
                    TArray<FBP_GamePassData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_GamePassData b_response_item;
                        FBP_GamePassData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_cancellationToken);
    }
    /**
     * Retrieves a list of GamePassUserData instances for a user based on the provided identifier or request name.
     * @param id - The game pass identifier to retrieve for the user. Optional.
     * @param requestName - The request name associated with the game pass. Optional.
     * @param userId - The identifier of the user to retrieve game passes for. Optional.
     * @param cancellationToken - A token to cancel the operation.
     * @return A list of GamePassUserData instances for the specified user.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GamePass", meta=(AutoCreateRefTerm="id, requestName, userId, cancellationToken"))
    static void GetForUserAsync(
        FGamePassModuleGetForUserAsyncResponse onSuccess,
        FGamePassModuleFailResponse onFail,
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
            RGN::Modules::GamePass::GamePassModule::GetForUserAsync(
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
    /**
     * Retrieves all GamePassUserData instances for a specified user asynchronously.
     * @param userId - The identifier of the user to retrieve all game passes for. Optional.
     * @param cancellationToken - A token to cancel the operation.
     * @return A list of all GamePassUserData instances for the specified user.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | GamePass", meta=(AutoCreateRefTerm="userId, cancellationToken"))
    static void GetAllForUserAsync(
        FGamePassModuleGetAllForUserAsyncResponse onSuccess,
        FGamePassModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& userId = "") {
            string cpp_userId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_userId = string(TCHAR_TO_UTF8(*userId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::GamePass::GamePassModule::GetAllForUserAsync(
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
                cpp_userId,
                cpp_cancellationToken);
    }
};
