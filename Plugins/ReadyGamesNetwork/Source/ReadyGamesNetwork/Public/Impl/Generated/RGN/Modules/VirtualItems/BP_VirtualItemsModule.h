#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItemsModule.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "BP_VirtualItem.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/AddVirtualItemResponseData.h"
#include "BP_AddVirtualItemResponseData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/AddToVirtualItemsRequestData.h"
#include "BP_AddToVirtualItemsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/UpdateVirtualItemsRequestData.h"
#include "BP_UpdateVirtualItemsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItemsResponseData.h"
#include "BP_VirtualItemsResponseData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/BP_BaseMigrationRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/GetAllVirtualItemsByAppIdsRequestData.h"
#include "BP_GetAllVirtualItemsByAppIdsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/GetVirtualItemsByIdsRequestData.h"
#include "BP_GetVirtualItemsByIdsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/GetVirtualItemTagsResponse.h"
#include "BP_GetVirtualItemTagsResponse.h"
#include "../../../../../Generated/RGN/Model/ImageSize.h"
#include "../../Model/BP_ImageSize.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_VirtualItemsModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FVirtualItemsModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleAddVirtualItemAsyncResponse, const FBP_VirtualItem&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleAddFromCSVAsyncResponse, const TArray<FString>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleUpdateVirtualItemAsyncResponse, const FBP_VirtualItem&, response);
DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleDeleteVirtualItemAsyncResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleGetVirtualItemsAsyncResponse, const TArray<FBP_VirtualItem>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleGetVirtualItemsByIdsAsyncResponse, const TArray<FBP_VirtualItem>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleGetByTagsAsyncResponse, const TArray<FBP_VirtualItem>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleGetTagsAsyncResponse, const TArray<FString>&, response);
DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleSetTagsAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleSetNameAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleSetDescriptionAsyncResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleGetPropertiesAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleSetPropertiesAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleUploadImageAsyncResponse, bool, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleDownloadImageAsyncResponse, const TArray<uint8>&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_VirtualItemsModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    /**
     * Add a virtual item
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void AddVirtualItemAsync(
        FVirtualItemsModuleAddVirtualItemAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FBP_VirtualItem& virtualItem) {
            RGN::Modules::VirtualItems::VirtualItem cpp_virtualItem;
            RGN::CancellationToken cpp_cancellationToken;
            FBP_VirtualItem::ConvertToCoreModel(virtualItem, cpp_virtualItem);
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::AddVirtualItemAsync(
                [onSuccess](RGN::Modules::VirtualItems::VirtualItem response) {
                    FBP_VirtualItem bpResponse;
                    FBP_VirtualItem::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItem,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously adds a list of virtual items from a CSV content string to the Ready Games Network.
     * @param virtualItemName - The name of the virtual item.
     * @param csvContent - The content of the CSV file as a string.
     * @param csvDelimiter - The delimiter used in the CSV file (defaults to ',').
     * @param cancellationToken - A CancellationToken to observe while waiting for the task to complete.
     * @return A Task that represents the asynchronous operation. The Task result contains a list of strings, which are the item IDs of the added virtual items.
     * @throw: Thrown when 'virtualItemName', 'csvContent', or 'csvDelimiter' is null or empty.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="csvDelimiter, cancellationToken"))
    static void AddFromCSVAsync(
        FVirtualItemsModuleAddFromCSVAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
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
            RGN::Modules::VirtualItems::VirtualItemsModule::AddFromCSVAsync(
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
    /**
     * Asynchronously updates a specific virtual item in the Ready Games Network.
     * @param itemId - The ID of the virtual item to be updated.
     * @param virtualItem - A VirtualItem object containing the new data for the virtual item.
     * @param cancellationToken - A token to cancel the operation.
     * @return A Task representing the asynchronous operation. The result of the Task is the updated VirtualItem.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void UpdateVirtualItemAsync(
        FVirtualItemsModuleUpdateVirtualItemAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& itemId,
        const FBP_VirtualItem& virtualItem) {
            string cpp_itemId;
            RGN::Modules::VirtualItems::VirtualItem cpp_virtualItem;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_itemId = string(TCHAR_TO_UTF8(*itemId));
            FBP_VirtualItem::ConvertToCoreModel(virtualItem, cpp_virtualItem);
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::UpdateVirtualItemAsync(
                [onSuccess](RGN::Modules::VirtualItems::VirtualItem response) {
                    FBP_VirtualItem bpResponse;
                    FBP_VirtualItem::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_itemId,
                cpp_virtualItem,
                cpp_cancellationToken);
    }
    /**
     * Asynchronously deletes a specific virtual item from the Ready Games Network.
     * @param itemId - The ID of the virtual item to be deleted.
     * @param cancellationToken - A token to cancel the operation.
     * @return A Task representing the asynchronous operation.
     * @throw: Thrown when 'itemId' is null or empty.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeleteVirtualItemAsync(
        FVirtualItemsModuleDeleteVirtualItemAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& itemId) {
            string cpp_itemId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_itemId = string(TCHAR_TO_UTF8(*itemId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::DeleteVirtualItemAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_itemId,
                cpp_cancellationToken);
    }
    /**
     * Getting all virtual items releated to your game
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetVirtualItemsAsync_CancellationToken(
        FVirtualItemsModuleGetVirtualItemsAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken) {
            RGN::CancellationToken cpp_cancellationToken;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::GetVirtualItemsAsync(
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    TArray<FBP_VirtualItem> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_VirtualItem b_response_item;
                        FBP_VirtualItem::ConvertToUnrealModel(response_item, b_response_item);
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
     * Returns a limited list of virtual items for your game.
     * @param limit - Maximal count of items to return
     * @param startAfter - The item id to start after
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="startAfter, cancellationToken"))
    static void GetVirtualItemsAsync_Limit_StartAfter_CancellationToken(
        FVirtualItemsModuleGetVirtualItemsAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        int32 limit,
        const FString& startAfter = "") {
            int32_t cpp_limit;
            string cpp_startAfter;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_limit = limit;
            cpp_startAfter = string(TCHAR_TO_UTF8(*startAfter));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::GetVirtualItemsAsync(
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    TArray<FBP_VirtualItem> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_VirtualItem b_response_item;
                        FBP_VirtualItem::ConvertToUnrealModel(response_item, b_response_item);
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
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetVirtualItemsByIdsAsync(
        FVirtualItemsModuleGetVirtualItemsByIdsAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& virtualItemsIds) {
            vector<string> cpp_virtualItemsIds;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& virtualItemsIds_item : virtualItemsIds) {
                string cpp_virtualItemsIds_item;
                cpp_virtualItemsIds_item = string(TCHAR_TO_UTF8(*virtualItemsIds_item));
                cpp_virtualItemsIds.push_back(cpp_virtualItemsIds_item);
            }
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::GetVirtualItemsByIdsAsync(
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    TArray<FBP_VirtualItem> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_VirtualItem b_response_item;
                        FBP_VirtualItem::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemsIds,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetByTagsAsync(
        FVirtualItemsModuleGetByTagsAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const TArray<FString>& tags) {
            vector<string> cpp_tags;
            RGN::CancellationToken cpp_cancellationToken;
            for (const auto& tags_item : tags) {
                string cpp_tags_item;
                cpp_tags_item = string(TCHAR_TO_UTF8(*tags_item));
                cpp_tags.push_back(cpp_tags_item);
            }
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::GetByTagsAsync(
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    TArray<FBP_VirtualItem> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_VirtualItem b_response_item;
                        FBP_VirtualItem::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_tags,
                cpp_cancellationToken);
    }
    /**
     * Returns all tags for specific virtual item
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetTagsAsync(
        FVirtualItemsModuleGetTagsAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& virtualItemId) {
            string cpp_virtualItemId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::GetTagsAsync(
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
                cpp_virtualItemId,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void SetTagsAsync(
        FVirtualItemsModuleSetTagsAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& virtualItemId,
        const TArray<FString>& tags) {
            string cpp_virtualItemId;
            vector<string> cpp_tags;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            for (const auto& tags_item : tags) {
                string cpp_tags_item;
                cpp_tags_item = string(TCHAR_TO_UTF8(*tags_item));
                cpp_tags.push_back(cpp_tags_item);
            }
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::SetTagsAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemId,
                cpp_tags,
                cpp_cancellationToken);
    }
    /**
     * Sets the name for a specific virtual item
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void SetNameAsync(
        FVirtualItemsModuleSetNameAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& virtualItemId,
        const FString& name) {
            string cpp_virtualItemId;
            string cpp_name;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            cpp_name = string(TCHAR_TO_UTF8(*name));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::SetNameAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemId,
                cpp_name,
                cpp_cancellationToken);
    }
    /**
     * Sets the description for a specific virtual item
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void SetDescriptionAsync(
        FVirtualItemsModuleSetDescriptionAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& virtualItemId,
        const FString& description) {
            string cpp_virtualItemId;
            string cpp_description;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            cpp_description = string(TCHAR_TO_UTF8(*description));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::SetDescriptionAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemId,
                cpp_description,
                cpp_cancellationToken);
    }
    /**
     * Returns json string or throws an exception if there are no json for virtual item
     * @param cancellationToken - A token to cancel the operation.
     * @return Returns json as string
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void GetPropertiesAsync(
        FVirtualItemsModuleGetPropertiesAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& virtualItemId) {
            string cpp_virtualItemId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::GetPropertiesAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemId,
                cpp_cancellationToken);
    }
    /**
     * Set json on a given virtualItemId.
     * @param cancellationToken - A token to cancel the operation.
     * @return Returns json as string
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void SetPropertiesAsync(
        FVirtualItemsModuleSetPropertiesAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& virtualItemId,
        const FString& json) {
            string cpp_virtualItemId;
            string cpp_json;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            cpp_json = string(TCHAR_TO_UTF8(*json));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::SetPropertiesAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemId,
                cpp_json,
                cpp_cancellationToken);
    }
    /**
     * Uploads an image thumbnail for a virtual item to the RGNCore backend.
     * @param virtualItemId - The ID of the virtual item to upload the thumbnail for.
     * @param thumbnailTextureBytes - The byte array of the thumbnail texture image to upload.
     * @param cancellationToken - A token to cancel the operation.
     * @return A boolean indicating whether the upload was successful.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void UploadImageAsync(
        FVirtualItemsModuleUploadImageAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& virtualItemId,
        const TArray<uint8>& thumbnailTextureBytes) {
            string cpp_virtualItemId;
            vector<uint8_t> cpp_thumbnailTextureBytes;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            for (const auto& thumbnailTextureBytes_item : thumbnailTextureBytes) {
                uint8_t cpp_thumbnailTextureBytes_item;
                cpp_thumbnailTextureBytes_item = thumbnailTextureBytes_item;
                cpp_thumbnailTextureBytes.push_back(cpp_thumbnailTextureBytes_item);
            }
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::UploadImageAsync(
                [onSuccess](bool response) {
                    bool bpResponse;
                    bpResponse = response;
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemId,
                cpp_thumbnailTextureBytes,
                cpp_cancellationToken);
    }
    /**
     * Downloads an image asynchronously from a specified virtual item ID.
     * @param virtualItemId - The ID of the virtual item to download the image from.
     * @param size - The size type of virtual item image to download.
     * @param cancellationToken - A cancellation token that can be used to cancel the asynchronous operation.
     * @return A byte array containing the image data.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DownloadImageAsync(
        FVirtualItemsModuleDownloadImageAsyncResponse onSuccess,
        FVirtualItemsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& virtualItemId,
        const EBP_ImageSize& size) {
            string cpp_virtualItemId;
            RGN::Model::ImageSize cpp_size;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            cpp_size = static_cast<RGN::Model::ImageSize>(size);
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::DownloadImageAsync(
                [onSuccess](vector<uint8_t> response) {
                    TArray<uint8> bpResponse;
                    for (const auto& response_item : response) {
                        uint8 b_response_item;
                        b_response_item = response_item;
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemId,
                cpp_size,
                cpp_cancellationToken);
    }
};
