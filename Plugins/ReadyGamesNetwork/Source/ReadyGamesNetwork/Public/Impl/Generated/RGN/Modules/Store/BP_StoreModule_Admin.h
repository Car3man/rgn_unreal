#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Store/StoreModule_Admin.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/PriceInfo.h"
#include "../VirtualItems/BP_PriceInfo.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_StoreModule_Admin.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FStoreModule_AdminFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FStoreModuleAdminCreateLootBoxAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FStoreModuleAdminDeleteLootBoxAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE(FStoreModuleAdminDeleteStoreOfferAsyncResponse);

UCLASS()
class READYGAMESNETWORK_API UBP_StoreModule_Admin : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Store", meta=(AutoCreateRefTerm="prices, cancellationToken"))
    static void CreateLootBoxAsync(
        FStoreModuleAdminCreateLootBoxAsyncResponse onSuccess,
        FStoreModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& lootBoxName,
        const TArray<FString>& virtualItemTags,
        const TArray<FBP_PriceInfo>& prices) {
            string cpp_lootBoxName;
            vector<string> cpp_virtualItemTags;
            vector<RGN::Modules::VirtualItems::PriceInfo> cpp_prices;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_lootBoxName = string(TCHAR_TO_UTF8(*lootBoxName));
            for (const auto& virtualItemTags_item : virtualItemTags) {
                string cpp_virtualItemTags_item;
                cpp_virtualItemTags_item = string(TCHAR_TO_UTF8(*virtualItemTags_item));
                cpp_virtualItemTags.push_back(cpp_virtualItemTags_item);
            }
            for (const auto& prices_item : prices) {
                RGN::Modules::VirtualItems::PriceInfo cpp_prices_item;
                FBP_PriceInfo::ConvertToCoreModel(prices_item, cpp_prices_item);
                cpp_prices.push_back(cpp_prices_item);
            }
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Store::StoreModule_Admin::CreateLootBoxAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_lootBoxName,
                cpp_virtualItemTags,
                cpp_prices,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Store", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeleteLootBoxAsync(
        FStoreModuleAdminDeleteLootBoxAsyncResponse onSuccess,
        FStoreModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& lootBoxId) {
            string cpp_lootBoxId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_lootBoxId = string(TCHAR_TO_UTF8(*lootBoxId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Store::StoreModule_Admin::DeleteLootBoxAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_lootBoxId,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Store", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeleteStoreOfferAsync(
        FStoreModuleAdminDeleteStoreOfferAsyncResponse onSuccess,
        FStoreModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& offerId) {
            string cpp_offerId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_offerId = string(TCHAR_TO_UTF8(*offerId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Store::StoreModule_Admin::DeleteStoreOfferAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_offerId,
                cpp_cancellationToken);
    }
};
