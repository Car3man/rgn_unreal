#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItemsModule_Admin.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_VirtualItemsModule_Admin.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FVirtualItemsModule_AdminFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleAdminDeleteVirtualItemsByIdsAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleAdminDeleteVirtualItemsByNameAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleAdminDeleteVirtualItemByAppIdAsyncResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleAdminAddFromCSVWithBlockchainStubAsyncResponse, const TArray<FString>&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_VirtualItemsModule_Admin : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeleteVirtualItemsByIdsAsync(
        FVirtualItemsModuleAdminDeleteVirtualItemsByIdsAsyncResponse onSuccess,
        FVirtualItemsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& virtualItemIds) {
            vector<string> cpp_virtualItemIds;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& virtualItemIds_item : virtualItemIds) {
                string cpp_virtualItemIds_item;
                cpp_virtualItemIds_item = string(TCHAR_TO_UTF8(*virtualItemIds_item));
                cpp_virtualItemIds.push_back(cpp_virtualItemIds_item);
            }
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule_Admin::DeleteVirtualItemsByIdsAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemIds,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeleteVirtualItemsByNameAsync(
        FVirtualItemsModuleAdminDeleteVirtualItemsByNameAsyncResponse onSuccess,
        FVirtualItemsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& itemName) {
            string cpp_itemName;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_itemName = string(TCHAR_TO_UTF8(*itemName));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule_Admin::DeleteVirtualItemsByNameAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_itemName,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeleteVirtualItemByAppIdAsync(
        FVirtualItemsModuleAdminDeleteVirtualItemByAppIdAsyncResponse onSuccess,
        FVirtualItemsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& appId) {
            string cpp_appId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_appId = string(TCHAR_TO_UTF8(*appId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule_Admin::DeleteVirtualItemByAppIdAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_appId,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="csvDelimiter, cancellationToken"))
    static void AddFromCSVWithBlockchainStubAsync(
        FVirtualItemsModuleAdminAddFromCSVWithBlockchainStubAsyncResponse onSuccess,
        FVirtualItemsModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& virtualItemName,
        const FString& csvContent,
        const FString& csvDelimiter = ",") {
            string cpp_virtualItemName;
            string cpp_csvContent;
            string cpp_csvDelimiter;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_virtualItemName = string(TCHAR_TO_UTF8(*virtualItemName));
            cpp_csvContent = string(TCHAR_TO_UTF8(*csvContent));
            cpp_csvDelimiter = string(TCHAR_TO_UTF8(*csvDelimiter));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule_Admin::AddFromCSVWithBlockchainStubAsync(
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
                cpp_virtualItemName,
                cpp_csvContent,
                cpp_csvDelimiter,
                cpp_cancellationToken);
    }
};
