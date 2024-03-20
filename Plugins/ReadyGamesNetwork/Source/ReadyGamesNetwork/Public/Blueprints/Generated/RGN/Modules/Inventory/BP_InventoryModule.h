#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryModule.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/Properties.h"
#include "../VirtualItems/BP_Properties.h"
#include "../../../../../Generated/RGN/Modules/Inventory/AddToInventoryResponseData.h"
#include "BP_AddToInventoryResponseData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemData.h"
#include "BP_InventoryItemData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/AddVirtualItemToUserInventoryRequestData.h"
#include "BP_AddVirtualItemToUserInventoryRequestData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/RemoveByVirtualItemIdResponseData.h"
#include "BP_RemoveByVirtualItemIdResponseData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/RemoveByOwnedIdResponseData.h"
#include "BP_RemoveByOwnedIdResponseData.h"
#include "../../../../../Generated/RGN/Modules/Inventory/UpgradesResponseData.h"
#include "BP_UpgradesResponseData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/BP_Currency.h"
#include "../../../../../Generated/RGN/Modules/Inventory/VirtualItemUpgrade.h"
#include "BP_VirtualItemUpgrade.h"
#include "../../../../../Generated/RGN/Modules/Inventory/InventoryItemsWithVirtualItemsData.h"
#include "BP_InventoryItemsWithVirtualItemsData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_InventoryModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FInventoryModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleAddToInventoryAsyncResponse, const FBP_AddToInventoryResponseData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleRemoveByVirtualItemIdAsyncResponse, const FBP_RemoveByVirtualItemIdResponseData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleRemoveByInventoryItemIdAsyncResponse, const FBP_RemoveByOwnedIdResponseData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetPropertiesAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleSetPropertiesAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetUpgradesAsyncResponse, const TArray<FBP_UpgradesResponseData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleUpgradeAsyncResponse, const TArray<FBP_VirtualItemUpgrade>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetByIdAsyncResponse, const FBP_InventoryItemData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetByIdsAsyncResponse, const TArray<FBP_InventoryItemData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetByVirtualItemIdsAsyncResponse, const TArray<FBP_InventoryItemData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetAllForCurrentAppAsyncResponse, const TArray<FBP_InventoryItemData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetByAppIdsAsyncResponse, const TArray<FBP_InventoryItemData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetWithVirtualItemsDataForCurrentAppAsyncResponse, const TArray<FBP_InventoryItemData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetWithVirtualItemsDataByAppIdsAsyncResponse, const TArray<FBP_InventoryItemData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleParseInventoryItemDataResponse, const FBP_InventoryItemData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleParseInventoryItemsDataResponse, const TArray<FBP_InventoryItemData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetByTagsAsyncResponse, const TArray<FBP_InventoryItemData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleGetTagsAsyncResponse, const TArray<FString>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FInventoryModuleSetTagsAsyncResponse, const TArray<FString>&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_InventoryModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    /**
     * Asynchronously adds a specified quantity of a virtual item to the current logged in user's inventory.
     * @param virtualItemId - The unique identifier of the virtual item to be added to the inventory.
     * @param quantity - The quantity of the virtual item to be added. The default value is 1.
     * @param properties - Optional additional properties associated with the item. The default is null.
     * @return A Task that represents the asynchronous operation.
     * The task result contains an T:RGN.Modules.Inventory.AddToInventoryResponseData object which holds the response data of the operation.
     * @throw: Thrown when the user is not logged in.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory", meta=(AutoCreateRefTerm="quantity, properties"))
    static void AddToInventoryAsync_VirtualItemId_Quantity_Properties(
        FInventoryModuleAddToInventoryAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& virtualItemId,
        int32 quantity = 1,
        const FBP_Properties& properties = FBP_Properties()) {
            string cpp_virtualItemId;
            int32_t cpp_quantity;
            RGN::Modules::VirtualItems::Properties cpp_properties;
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            cpp_quantity = quantity;
            FBP_Properties::ConvertToCoreModel(properties, cpp_properties);
            RGN::Modules::Inventory::InventoryModule::AddToInventoryAsync(
                [onSuccess](RGN::Modules::Inventory::AddToInventoryResponseData response) {
                    FBP_AddToInventoryResponseData bpResponse;
                    FBP_AddToInventoryResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemId,
                cpp_quantity,
                cpp_properties);
    }
    /**
     * Asynchronously adds a specified quantity of a virtual item to the inventory for a specified user.
     * @param userId - The unique identifier of the user whose inventory will be updated.
     * @param virtualItemId - The unique identifier of the virtual item to be added to the user's inventory.
     * @param quantity - The quantity of the virtual item to be added. The default value is 1.
     * @param properties - Optional additional properties associated with the item. The default is null.
     * @return A Task that represents the asynchronous operation.
     * The task result contains an T:RGN.Modules.Inventory.AddToInventoryResponseData object which holds the response data of the operation.
     * @throw: Thrown when the ownedItemId is null or empty.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory", meta=(AutoCreateRefTerm="quantity, properties"))
    static void AddToInventoryAsync_UserId_VirtualItemId_Quantity_Properties(
        FInventoryModuleAddToInventoryAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& userId,
        const FString& virtualItemId,
        int32 quantity = 1,
        const FBP_Properties& properties = FBP_Properties()) {
            string cpp_userId;
            string cpp_virtualItemId;
            int32_t cpp_quantity;
            RGN::Modules::VirtualItems::Properties cpp_properties;
            cpp_userId = string(TCHAR_TO_UTF8(*userId));
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            cpp_quantity = quantity;
            FBP_Properties::ConvertToCoreModel(properties, cpp_properties);
            RGN::Modules::Inventory::InventoryModule::AddToInventoryAsync(
                [onSuccess](RGN::Modules::Inventory::AddToInventoryResponseData response) {
                    FBP_AddToInventoryResponseData bpResponse;
                    FBP_AddToInventoryResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_userId,
                cpp_virtualItemId,
                cpp_quantity,
                cpp_properties);
    }
    /**
     * Asynchronously adds a specified inventory item to the inventory for a specified user.
     * @param userId - The unique identifier of the user whose inventory will be updated.
     * @param inventoryData - The data of the inventory item to be added to the user's inventory. Includes item's unique identifier, quantity and optional additional properties.
     * @return A Task that represents the asynchronous operation.
     * The task result contains an T:RGN.Modules.Inventory.AddToInventoryResponseData object which holds the response data of the operation.
     * @throw: Thrown when the userId or inventoryData.ownedItemId is null or empty.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void AddToInventoryAsync_UserId_InventoryData(
        FInventoryModuleAddToInventoryAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& userId,
        const FBP_InventoryItemData& inventoryData) {
            string cpp_userId;
            RGN::Modules::Inventory::InventoryItemData cpp_inventoryData;
            cpp_userId = string(TCHAR_TO_UTF8(*userId));
            FBP_InventoryItemData::ConvertToCoreModel(inventoryData, cpp_inventoryData);
            RGN::Modules::Inventory::InventoryModule::AddToInventoryAsync(
                [onSuccess](RGN::Modules::Inventory::AddToInventoryResponseData response) {
                    FBP_AddToInventoryResponseData bpResponse;
                    FBP_AddToInventoryResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_userId,
                cpp_inventoryData);
    }
    /**
     * Asynchronously removes a specified quantity of a virtual item from a user's inventory by its unique identifier.
     * @param userId - The unique identifier of the user whose inventory to modify.
     * @param virtualItemId - The unique identifier of the virtual item to remove.
     * @param quantity - The quantity of the virtual item to remove. Must be a positive number.
     * @return A task that represents the asynchronous operation.
     * The task result contains a T:RGN.Modules.Inventory.RemoveByVirtualItemIdResponseData object which holds the server's response data.
     * @throw: Thrown when virtualItemId is null or empty.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void RemoveByVirtualItemIdAsync(
        FInventoryModuleRemoveByVirtualItemIdAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& userId,
        const FString& virtualItemId,
        int32 quantity) {
            string cpp_userId;
            string cpp_virtualItemId;
            int32_t cpp_quantity;
            cpp_userId = string(TCHAR_TO_UTF8(*userId));
            cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            cpp_quantity = quantity;
            RGN::Modules::Inventory::InventoryModule::RemoveByVirtualItemIdAsync(
                [onSuccess](RGN::Modules::Inventory::RemoveByVirtualItemIdResponseData response) {
                    FBP_RemoveByVirtualItemIdResponseData bpResponse;
                    FBP_RemoveByVirtualItemIdResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_userId,
                cpp_virtualItemId,
                cpp_quantity);
    }
    /**
     * Asynchronously removes a specified quantity of a virtual item from a user's inventory by its owned item identifier.
     * @param userId - The unique identifier of the user whose inventory to modify.
     * @param ownedItemId - The unique identifier of the owned item to remove.
     * @param quantity - The quantity of the owned item to remove. Must be a positive number. Default is 1.
     * @return A task that represents the asynchronous operation.
     * The task result contains a T:RGN.Modules.Inventory.RemoveByOwnedIdResponseData object which holds the server's response data.
     * @throw: Thrown when ownedItemId is null or empty.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory", meta=(AutoCreateRefTerm="quantity"))
    static void RemoveByInventoryItemIdAsync(
        FInventoryModuleRemoveByInventoryItemIdAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& userId,
        const FString& ownedItemId,
        int32 quantity = 1) {
            string cpp_userId;
            string cpp_ownedItemId;
            int32_t cpp_quantity;
            cpp_userId = string(TCHAR_TO_UTF8(*userId));
            cpp_ownedItemId = string(TCHAR_TO_UTF8(*ownedItemId));
            cpp_quantity = quantity;
            RGN::Modules::Inventory::InventoryModule::RemoveByInventoryItemIdAsync(
                [onSuccess](RGN::Modules::Inventory::RemoveByOwnedIdResponseData response) {
                    FBP_RemoveByOwnedIdResponseData bpResponse;
                    FBP_RemoveByOwnedIdResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_userId,
                cpp_ownedItemId,
                cpp_quantity);
    }
    /**
     * Returns json string or throws an exception if there are no json for virtual item
     * @return Returns json as string
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void GetPropertiesAsync(
        FInventoryModuleGetPropertiesAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& ownedItemId) {
            string cpp_ownedItemId;
            cpp_ownedItemId = string(TCHAR_TO_UTF8(*ownedItemId));
            RGN::Modules::Inventory::InventoryModule::GetPropertiesAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_ownedItemId);
    }
    /**
     * Set json on a given ownedItemId.
     * @return Returns json as string
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void SetPropertiesAsync(
        FInventoryModuleSetPropertiesAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& ownedItemId,
        const FString& json) {
            string cpp_ownedItemId;
            string cpp_json;
            cpp_ownedItemId = string(TCHAR_TO_UTF8(*ownedItemId));
            cpp_json = string(TCHAR_TO_UTF8(*json));
            RGN::Modules::Inventory::InventoryModule::SetPropertiesAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_ownedItemId,
                cpp_json);
    }
    /**
     * Get user owned item upgrades, returns all upgrades for all owned items for virtual item ownedItemId
     * @param ownedItemId - The ownedItemId of the virtual item to search in inventory for
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void GetUpgradesAsync(
        FInventoryModuleGetUpgradesAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& ownedItemId) {
            string cpp_ownedItemId;
            cpp_ownedItemId = string(TCHAR_TO_UTF8(*ownedItemId));
            RGN::Modules::Inventory::InventoryModule::GetUpgradesAsync(
                [onSuccess](vector<RGN::Modules::Inventory::UpgradesResponseData> response) {
                    TArray<FBP_UpgradesResponseData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_UpgradesResponseData b_response_item;
                        FBP_UpgradesResponseData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_ownedItemId);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory", meta=(AutoCreateRefTerm="upgradePrice, upgradeId"))
    static void UpgradeAsync(
        FInventoryModuleUpgradeAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& ownedItemId,
        int32 newUpgradeLevel,
        const TArray<FBP_Currency>& upgradePrice,
        const FString& upgradeId = "") {
            string cpp_ownedItemId;
            int32_t cpp_newUpgradeLevel;
            vector<RGN::Modules::Currency::Currency> cpp_upgradePrice;
            string cpp_upgradeId;
            cpp_ownedItemId = string(TCHAR_TO_UTF8(*ownedItemId));
            cpp_newUpgradeLevel = newUpgradeLevel;
            for (const auto& upgradePrice_item : upgradePrice) {
                RGN::Modules::Currency::Currency cpp_upgradePrice_item;
                FBP_Currency::ConvertToCoreModel(upgradePrice_item, cpp_upgradePrice_item);
                cpp_upgradePrice.push_back(cpp_upgradePrice_item);
            }
            cpp_upgradeId = string(TCHAR_TO_UTF8(*upgradeId));
            RGN::Modules::Inventory::InventoryModule::UpgradeAsync(
                [onSuccess](vector<RGN::Modules::Inventory::VirtualItemUpgrade> response) {
                    TArray<FBP_VirtualItemUpgrade> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_VirtualItemUpgrade b_response_item;
                        FBP_VirtualItemUpgrade::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_ownedItemId,
                cpp_newUpgradeLevel,
                cpp_upgradePrice,
                cpp_upgradeId);
    }
    /**
     * Get single owned virtual item inventory data by ownedItemId
     * @param ownedItemId - The id of the owned item in users inventory
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void GetByIdAsync(
        FInventoryModuleGetByIdAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& ownedItemId) {
            string cpp_ownedItemId;
            cpp_ownedItemId = string(TCHAR_TO_UTF8(*ownedItemId));
            RGN::Modules::Inventory::InventoryModule::GetByIdAsync(
                [onSuccess](RGN::Modules::Inventory::InventoryItemData response) {
                    FBP_InventoryItemData bpResponse;
                    FBP_InventoryItemData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_ownedItemId);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void GetByIdsAsync(
        FInventoryModuleGetByIdsAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const TArray<FString>& ownedItemIds) {
            vector<string> cpp_ownedItemIds;
            for (const auto& ownedItemIds_item : ownedItemIds) {
                string cpp_ownedItemIds_item;
                cpp_ownedItemIds_item = string(TCHAR_TO_UTF8(*ownedItemIds_item));
                cpp_ownedItemIds.push_back(cpp_ownedItemIds_item);
            }
            RGN::Modules::Inventory::InventoryModule::GetByIdsAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    TArray<FBP_InventoryItemData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_InventoryItemData b_response_item;
                        FBP_InventoryItemData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_ownedItemIds);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void GetByVirtualItemIdsAsync(
        FInventoryModuleGetByVirtualItemIdsAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const TArray<FString>& virtualItemIds) {
            vector<string> cpp_virtualItemIds;
            for (const auto& virtualItemIds_item : virtualItemIds) {
                string cpp_virtualItemIds_item;
                cpp_virtualItemIds_item = string(TCHAR_TO_UTF8(*virtualItemIds_item));
                cpp_virtualItemIds.push_back(cpp_virtualItemIds_item);
            }
            RGN::Modules::Inventory::InventoryModule::GetByVirtualItemIdsAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    TArray<FBP_InventoryItemData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_InventoryItemData b_response_item;
                        FBP_InventoryItemData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_virtualItemIds);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void GetAllForCurrentAppAsync(
        FInventoryModuleGetAllForCurrentAppAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail) {
            RGN::Modules::Inventory::InventoryModule::GetAllForCurrentAppAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    TArray<FBP_InventoryItemData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_InventoryItemData b_response_item;
                        FBP_InventoryItemData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                });
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void GetByAppIdsAsync(
        FInventoryModuleGetByAppIdsAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const TArray<FString>& appIds) {
            vector<string> cpp_appIds;
            for (const auto& appIds_item : appIds) {
                string cpp_appIds_item;
                cpp_appIds_item = string(TCHAR_TO_UTF8(*appIds_item));
                cpp_appIds.push_back(cpp_appIds_item);
            }
            RGN::Modules::Inventory::InventoryModule::GetByAppIdsAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    TArray<FBP_InventoryItemData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_InventoryItemData b_response_item;
                        FBP_InventoryItemData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_appIds);
    }
    /**
     * Get multiple owned virtual items inventory data for current app with the Virtual Item data included
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory", meta=(AutoCreateRefTerm="startAfter, limit"))
    static void GetWithVirtualItemsDataForCurrentAppAsync(
        FInventoryModuleGetWithVirtualItemsDataForCurrentAppAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& startAfter = "",
        int32 limit = 100) {
            string cpp_startAfter;
            int32_t cpp_limit;
            cpp_startAfter = string(TCHAR_TO_UTF8(*startAfter));
            cpp_limit = limit;
            RGN::Modules::Inventory::InventoryModule::GetWithVirtualItemsDataForCurrentAppAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    TArray<FBP_InventoryItemData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_InventoryItemData b_response_item;
                        FBP_InventoryItemData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_startAfter,
                cpp_limit);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory", meta=(AutoCreateRefTerm="startAfter, limit"))
    static void GetWithVirtualItemsDataByAppIdsAsync(
        FInventoryModuleGetWithVirtualItemsDataByAppIdsAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const TArray<FString>& appIds,
        const FString& startAfter = "",
        int32 limit = 100) {
            vector<string> cpp_appIds;
            string cpp_startAfter;
            int32_t cpp_limit;
            for (const auto& appIds_item : appIds) {
                string cpp_appIds_item;
                cpp_appIds_item = string(TCHAR_TO_UTF8(*appIds_item));
                cpp_appIds.push_back(cpp_appIds_item);
            }
            cpp_startAfter = string(TCHAR_TO_UTF8(*startAfter));
            cpp_limit = limit;
            RGN::Modules::Inventory::InventoryModule::GetWithVirtualItemsDataByAppIdsAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    TArray<FBP_InventoryItemData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_InventoryItemData b_response_item;
                        FBP_InventoryItemData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_appIds,
                cpp_startAfter,
                cpp_limit);
    }
    /**
     * Parses a JSON string representation of an T:RGN.Modules.Inventory.InventoryItemData object.
     * @param json - The JSON string representation of an T:RGN.Modules.Inventory.InventoryItemData object.
     * @return An T:RGN.Modules.Inventory.InventoryItemData object represented by the JSON string. 
     * Returns null if the JSON string does not represent a valid T:RGN.Modules.Inventory.InventoryItemData object.
     * @throw: Thrown when json is null or empty.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void ParseInventoryItemData(
        FInventoryModuleParseInventoryItemDataResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& json) {
            string cpp_json;
            cpp_json = string(TCHAR_TO_UTF8(*json));
            RGN::Modules::Inventory::InventoryModule::ParseInventoryItemData(
                cpp_json);
    }
    /**
     * Parses a JSON string representation of a list of T:RGN.Modules.Inventory.InventoryItemData objects.
     * @param json - The JSON string representation of a list of T:RGN.Modules.Inventory.InventoryItemData objects.
     * @return A list of T:RGN.Modules.Inventory.InventoryItemData objects represented by the JSON string.
     * Returns null if the JSON string does not represent a valid list of T:RGN.Modules.Inventory.InventoryItemData objects.
     * @throw: Thrown when json is null or empty.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void ParseInventoryItemsData(
        FInventoryModuleParseInventoryItemsDataResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& json) {
            string cpp_json;
            cpp_json = string(TCHAR_TO_UTF8(*json));
            RGN::Modules::Inventory::InventoryModule::ParseInventoryItemsData(
                cpp_json);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory", meta=(AutoCreateRefTerm="appId"))
    static void GetByTagsAsync(
        FInventoryModuleGetByTagsAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const TArray<FString>& tags,
        const FString& appId = "") {
            vector<string> cpp_tags;
            string cpp_appId;
            for (const auto& tags_item : tags) {
                string cpp_tags_item;
                cpp_tags_item = string(TCHAR_TO_UTF8(*tags_item));
                cpp_tags.push_back(cpp_tags_item);
            }
            cpp_appId = string(TCHAR_TO_UTF8(*appId));
            RGN::Modules::Inventory::InventoryModule::GetByTagsAsync(
                [onSuccess](vector<RGN::Modules::Inventory::InventoryItemData> response) {
                    TArray<FBP_InventoryItemData> bpResponse;
                    for (const auto& response_item : response) {
                        FBP_InventoryItemData b_response_item;
                        FBP_InventoryItemData::ConvertToUnrealModel(response_item, b_response_item);
                        bpResponse.Add(b_response_item);
                    }
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_tags,
                cpp_appId);
    }
    /**
     * Asynchronously retrieves the tags of an owned item in the inventory by its identifier for current logged in user
     * @param ownedItemId - The unique identifier of the owned item for which to retrieve tags.
     * @return A task that represents the asynchronous operation.
     * The task result contains a list of tags associated with the owned item.
     * @throw: Thrown when ownedItemId is null or empty.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory")
    static void GetTagsAsync(
        FInventoryModuleGetTagsAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& ownedItemId) {
            string cpp_ownedItemId;
            cpp_ownedItemId = string(TCHAR_TO_UTF8(*ownedItemId));
            RGN::Modules::Inventory::InventoryModule::GetTagsAsync(
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
                cpp_ownedItemId);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Inventory", meta=(AutoCreateRefTerm="appId"))
    static void SetTagsAsync(
        FInventoryModuleSetTagsAsyncResponse onSuccess,
        FInventoryModuleFailResponse onFail,
        const FString& ownedItemId,
        const TArray<FString>& tags,
        const FString& appId = "") {
            string cpp_ownedItemId;
            vector<string> cpp_tags;
            string cpp_appId;
            cpp_ownedItemId = string(TCHAR_TO_UTF8(*ownedItemId));
            for (const auto& tags_item : tags) {
                string cpp_tags_item;
                cpp_tags_item = string(TCHAR_TO_UTF8(*tags_item));
                cpp_tags.push_back(cpp_tags_item);
            }
            cpp_appId = string(TCHAR_TO_UTF8(*appId));
            RGN::Modules::Inventory::InventoryModule::SetTagsAsync(
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
                cpp_ownedItemId,
                cpp_tags,
                cpp_appId);
    }
};
