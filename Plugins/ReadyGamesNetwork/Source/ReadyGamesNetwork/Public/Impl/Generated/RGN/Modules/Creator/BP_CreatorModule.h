#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorModule.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSignupResponseData.h"
#include "BP_CreatorSignupResponseData.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSignupRequestData.h"
#include "BP_CreatorSignupRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "../VirtualItems/BP_VirtualItem.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSubmitItemResponseData.h"
#include "BP_CreatorSubmitItemResponseData.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorSubmitItemRequestData.h"
#include "BP_CreatorSubmitItemRequestData.h"
#include "../../../../../Generated/RGN/Modules/Creator/CreatorData.h"
#include "BP_CreatorData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/BP_BaseMigrationRequestData.h"
#include "../../../../../Generated/RGN/Modules/Currency/ClaimCurrencyResponseData.h"
#include "../Currency/BP_ClaimCurrencyResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_CreatorModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FCreatorModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FCreatorModuleBecomeACreatorAsyncResponse, const FBP_CreatorSignupResponseData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FCreatorModuleSubmitItemAsyncResponse, const FBP_CreatorSubmitItemResponseData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FCreatorModuleGetCreatorDataAsyncResponse, const FBP_CreatorData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FCreatorModuleClaimCurrenciesAsyncResponse, const FBP_ClaimCurrencyResponseData&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_CreatorModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    /**
     * Sends an asynchronous request to the backend to become a creator
     * @param cancellationToken - A token to cancel the operation.
     * @return FirebaseCreatorSignupResponseData.message = "Success" OR "Brand name already exists" OR "User is already enrolled in Creator Program" OR "Invalid BrandName";
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Creator", meta=(AutoCreateRefTerm="cancellationToken"))
    static void BecomeACreatorAsync(
        FCreatorModuleBecomeACreatorAsyncResponse onSuccess,
        FCreatorModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& brandName) {
            string cpp_brandName;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_brandName = string(TCHAR_TO_UTF8(*brandName));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Creator::CreatorModule::BecomeACreatorAsync(
                [onSuccess](RGN::Modules::Creator::CreatorSignupResponseData response) {
                    FBP_CreatorSignupResponseData bpResponse;
                    FBP_CreatorSignupResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_brandName,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Creator", meta=(AutoCreateRefTerm="cancellationToken"))
    static void SubmitItemAsync(
        FCreatorModuleSubmitItemAsyncResponse onSuccess,
        FCreatorModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FBP_VirtualItem& customizedItem) {
            RGN::Modules::VirtualItems::VirtualItem cpp_customizedItem;
            RGN::CancellationToken cpp_cancellationToken;
            FBP_VirtualItem::ConvertToCoreModel(customizedItem, cpp_customizedItem);
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Creator::CreatorModule::SubmitItemAsync(
                [onSuccess](RGN::Modules::Creator::CreatorSubmitItemResponseData response) {
                    FBP_CreatorSubmitItemResponseData bpResponse;
                    FBP_CreatorSubmitItemResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_customizedItem,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Creator", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetCreatorDataAsync(
        FCreatorModuleGetCreatorDataAsyncResponse onSuccess,
        FCreatorModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken) {
            RGN::CancellationToken cpp_cancellationToken;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Creator::CreatorModule::GetCreatorDataAsync(
                [onSuccess](RGN::Modules::Creator::CreatorData response) {
                    FBP_CreatorData bpResponse;
                    FBP_CreatorData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Creator", meta=(AutoCreateRefTerm="cancellationToken"))
    static void ClaimCurrenciesAsync(
        FCreatorModuleClaimCurrenciesAsyncResponse onSuccess,
        FCreatorModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken) {
            RGN::CancellationToken cpp_cancellationToken;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Creator::CreatorModule::ClaimCurrenciesAsync(
                [onSuccess](RGN::Modules::Currency::ClaimCurrencyResponseData response) {
                    FBP_ClaimCurrencyResponseData bpResponse;
                    FBP_ClaimCurrencyResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_cancellationToken);
    }
};
