#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../CustomImpl/RGN/Modules/Inventory/InventoryModule.h"
#include "../../../../Utility/CancellationToken.h"
#include "../../Model/Request/BaseMigrationRequestData.h"
#include "../VirtualItems/Properties.h"
#include "AddToInventoryResponseData.h"
#include "InventoryItemData.h"
#include "AddVirtualItemToUserInventoryRequestData.h"
#include "RemoveByVirtualItemIdResponseData.h"
#include "RemoveByOwnedIdResponseData.h"
#include "UpgradesResponseData.h"
#include "../Currency/Currency.h"
#include "VirtualItemUpgrade.h"
#include "InventoryItemsWithVirtualItemsData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace Inventory {
    class InventoryModule {
    public:
        /**
         * Asynchronously adds a specified quantity of a virtual item to the current logged in user's inventory.
         * @param virtualItemId - The unique identifier of the virtual item to be added to the inventory.
         * @param quantity - The quantity of the virtual item to be added. The default value is 1.
         * @param properties - Optional additional properties associated with the item. The default is null.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task that represents the asynchronous operation.
         * The task result contains an T:RGN.Modules.Inventory.AddToInventoryResponseData object which holds the response data of the operation.
         * @throw: Thrown when the user is not logged in.
         */
        static void AddToInventoryAsync(
            const function<void(const RGN::Modules::Inventory::AddToInventoryResponseData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& virtualItemId,
            const int32_t quantity = 1,
            const RGN::Modules::VirtualItems::Properties& properties = RGN::Modules::VirtualItems::Properties(),
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Inventory::InventoryModuleCustomImpl::AddToInventoryAsync(
                    success,
                    fail,
                    virtualItemId,
                    quantity,
                    properties,
                    cancellationToken);
            };
        /**
         * Asynchronously adds a specified quantity of a virtual item to the inventory for a specified user.
         * @param userId - The unique identifier of the user whose inventory will be updated.
         * @param virtualItemId - The unique identifier of the virtual item to be added to the user's inventory.
         * @param quantity - The quantity of the virtual item to be added. The default value is 1.
         * @param properties - Optional additional properties associated with the item. The default is null.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task that represents the asynchronous operation.
         * The task result contains an T:RGN.Modules.Inventory.AddToInventoryResponseData object which holds the response data of the operation.
         * @throw: Thrown when the ownedItemId is null or empty.
         */
        static void AddToInventoryAsync(
            const function<void(const RGN::Modules::Inventory::AddToInventoryResponseData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId,
            const string& virtualItemId,
            const int32_t quantity = 1,
            const RGN::Modules::VirtualItems::Properties& properties = RGN::Modules::VirtualItems::Properties(),
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Inventory::InventoryModuleCustomImpl::AddToInventoryAsync(
                    success,
                    fail,
                    userId,
                    virtualItemId,
                    quantity,
                    properties,
                    cancellationToken);
            };
        /**
         * Asynchronously adds a specified inventory item to the inventory for a specified user.
         * @param userId - The unique identifier of the user whose inventory will be updated.
         * @param inventoryData - The data of the inventory item to be added to the user's inventory. Includes item's unique identifier, quantity and optional additional properties.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task that represents the asynchronous operation.
         * The task result contains an T:RGN.Modules.Inventory.AddToInventoryResponseData object which holds the response data of the operation.
         * @throw: Thrown when the userId or inventoryData.ownedItemId is null or empty.
         */
        static void AddToInventoryAsync(
            const function<void(const RGN::Modules::Inventory::AddToInventoryResponseData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId,
            const RGN::Modules::Inventory::InventoryItemData& inventoryData,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Inventory::AddVirtualItemToUserInventoryRequestData requestData;
                requestData.userId = userId;
                requestData.virtualItemInventoryData = inventoryData;
                RGNCore::CallAPI<RGN::Modules::Inventory::AddVirtualItemToUserInventoryRequestData, RGN::Modules::Inventory::AddToInventoryResponseData>(
                    "inventoryV2-addToInventory",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously removes a specified quantity of a virtual item from a user's inventory by its unique identifier.
         * @param userId - The unique identifier of the user whose inventory to modify.
         * @param virtualItemId - The unique identifier of the virtual item to remove.
         * @param quantity - The quantity of the virtual item to remove. Must be a positive number.
         * @param cancellationToken - A token to cancel the operation.
         * @return A task that represents the asynchronous operation.
         * The task result contains a T:RGN.Modules.Inventory.RemoveByVirtualItemIdResponseData object which holds the server's response data.
         * @throw: Thrown when virtualItemId is null or empty.
         */
        static void RemoveByVirtualItemIdAsync(
            const function<void(const RGN::Modules::Inventory::RemoveByVirtualItemIdResponseData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId,
            const string& virtualItemId,
            const int32_t quantity,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["userId"] = userId;
                requestData["virtualItemId"] = virtualItemId;
                requestData["quantity"] = quantity;
                requestData["version"] = 2;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Inventory::RemoveByVirtualItemIdResponseData>(
                    "inventoryV2-removeByVirtualItemId",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously removes a specified quantity of a virtual item from a user's inventory by its owned item identifier.
         * @param userId - The unique identifier of the user whose inventory to modify.
         * @param ownedItemId - The unique identifier of the owned item to remove.
         * @param quantity - The quantity of the owned item to remove. Must be a positive number. Default is 1.
         * @param cancellationToken - A token to cancel the operation.
         * @return A task that represents the asynchronous operation.
         * The task result contains a T:RGN.Modules.Inventory.RemoveByOwnedIdResponseData object which holds the server's response data.
         * @throw: Thrown when ownedItemId is null or empty.
         */
        static void RemoveByInventoryItemIdAsync(
            const function<void(const RGN::Modules::Inventory::RemoveByOwnedIdResponseData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId,
            const string& ownedItemId,
            const int32_t quantity = 1,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["userId"] = userId;
                requestData["ownedItemId"] = ownedItemId;
                requestData["quantity"] = quantity;
                requestData["version"] = 2;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Inventory::RemoveByOwnedIdResponseData>(
                    "inventoryV2-removeByInventoryItemId",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Returns json string or throws an exception if there are no json for virtual item
         * @param cancellationToken - A token to cancel the operation.
         * @return Returns json as string
         */
        static void GetPropertiesAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& ownedItemId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ownedItemId"] = ownedItemId;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-getProperties",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["properties"].template get<string>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Set json on a given ownedItemId.
         * @param cancellationToken - A token to cancel the operation.
         * @return Returns json as string
         */
        static void SetPropertiesAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& ownedItemId,
            const string& json,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ownedItemId"] = ownedItemId;
                requestData["json"] = json;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-setProperties",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["properties"].template get<string>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Get user owned item upgrades, returns all upgrades for all owned items for virtual item ownedItemId
         * @param ownedItemId - The ownedItemId of the virtual item to search in inventory for
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetUpgradesAsync(
            const function<void(const vector<RGN::Modules::Inventory::UpgradesResponseData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& ownedItemId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ownedItemId"] = ownedItemId;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-getUpgrades",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["upgrades"].template get<vector<RGN::Modules::Inventory::UpgradesResponseData>>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void UpgradeAsync(
            const function<void(const vector<RGN::Modules::Inventory::VirtualItemUpgrade>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& ownedItemId,
            const int32_t newUpgradeLevel,
            const vector<RGN::Modules::Currency::Currency>& upgradePrice = vector<RGN::Modules::Currency::Currency>(),
            const string& upgradeId = string(),
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ownedItemId"] = ownedItemId;
                requestData["newUpgradeLevel"] = newUpgradeLevel;
                requestData["upgradeId"] = upgradeId;
                requestData["upgradePrice"] = upgradePrice;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-upgrade",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["upgrades"].template get<vector<RGN::Modules::Inventory::VirtualItemUpgrade>>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Get single owned virtual item inventory data by ownedItemId
         * @param ownedItemId - The id of the owned item in users inventory
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetByIdAsync(
            const function<void(const RGN::Modules::Inventory::InventoryItemData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& ownedItemId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ownedItemId"] = ownedItemId;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-getById",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["inventoryItem"].template get<RGN::Modules::Inventory::InventoryItemData>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetByIdsAsync(
            const function<void(const vector<RGN::Modules::Inventory::InventoryItemData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& ownedItemIds,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ownedItemIds"] = ownedItemIds;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-getByIds",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["inventoryItems"].template get<vector<RGN::Modules::Inventory::InventoryItemData>>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetByVirtualItemIdsAsync(
            const function<void(const vector<RGN::Modules::Inventory::InventoryItemData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& virtualItemIds,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["virtualItemIds"] = virtualItemIds;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-getByVirtualItemIds",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["inventoryItems"].template get<vector<RGN::Modules::Inventory::InventoryItemData>>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Get multiple owned virtual items inventory data for current app
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetAllForCurrentAppAsync(
            const function<void(const vector<RGN::Modules::Inventory::InventoryItemData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-getByAppId",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["inventoryItems"].template get<vector<RGN::Modules::Inventory::InventoryItemData>>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetByAppIdsAsync(
            const function<void(const vector<RGN::Modules::Inventory::InventoryItemData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& appIds,
            const int64_t startAfter = 0,
            const int32_t limit = 100,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appIds"] = appIds;
                requestData["startAfter"] = startAfter;
                requestData["limit"] = limit;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-getByAppIds",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["inventoryItems"].template get<vector<RGN::Modules::Inventory::InventoryItemData>>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Get multiple owned virtual items inventory data for current app with the Virtual Item data included
         * @param startAfter - An optional parameter representing an inventory items 'updatedAt' field after which start the retrieval
         * @param limit - The maximum number of items to return
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetWithVirtualItemsDataForCurrentAppAsync(
            const function<void(const vector<RGN::Modules::Inventory::InventoryItemData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const int64_t startAfter = 0,
            const int32_t limit = 100,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Inventory::InventoryModuleCustomImpl::GetWithVirtualItemsDataForCurrentAppAsync(
                    success,
                    fail,
                    startAfter,
                    limit,
                    cancellationToken);
            };
        static void GetWithVirtualItemsDataByAppIdsAsync(
            const function<void(const vector<RGN::Modules::Inventory::InventoryItemData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& appIds,
            const int64_t startAfter = 0,
            const int32_t limit = 100,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Inventory::InventoryModuleCustomImpl::GetWithVirtualItemsDataByAppIdsAsync(
                    success,
                    fail,
                    appIds,
                    startAfter,
                    limit,
                    cancellationToken);
            };
        /**
         * Parses a JSON string representation of an T:RGN.Modules.Inventory.InventoryItemData object.
         * @param json - The JSON string representation of an T:RGN.Modules.Inventory.InventoryItemData object.
         * @return An T:RGN.Modules.Inventory.InventoryItemData object represented by the JSON string. 
         * Returns null if the JSON string does not represent a valid T:RGN.Modules.Inventory.InventoryItemData object.
         * @throw: Thrown when json is null or empty.
         */
        static RGN::Modules::Inventory::InventoryItemData ParseInventoryItemData(
const string& json) {
                return RGN::Modules::Inventory::InventoryModuleCustomImpl::ParseInventoryItemData(
                    json);
            };
        /**
         * Parses a JSON string representation of a list of T:RGN.Modules.Inventory.InventoryItemData objects.
         * @param json - The JSON string representation of a list of T:RGN.Modules.Inventory.InventoryItemData objects.
         * @return A list of T:RGN.Modules.Inventory.InventoryItemData objects represented by the JSON string.
         * Returns null if the JSON string does not represent a valid list of T:RGN.Modules.Inventory.InventoryItemData objects.
         * @throw: Thrown when json is null or empty.
         */
        static vector<RGN::Modules::Inventory::InventoryItemData> ParseInventoryItemsData(
const string& json) {
                return RGN::Modules::Inventory::InventoryModuleCustomImpl::ParseInventoryItemsData(
                    json);
            };
        static void GetByTagsAsync(
            const function<void(const vector<RGN::Modules::Inventory::InventoryItemData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& tags,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["tags"] = tags;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-getByTags",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["inventoryItems"].template get<vector<RGN::Modules::Inventory::InventoryItemData>>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves the tags of an owned item in the inventory by its identifier for current logged in user
         * @param ownedItemId - The unique identifier of the owned item for which to retrieve tags.
         * @param cancellationToken - A token to cancel the operation.
         * @return A task that represents the asynchronous operation.
         * The task result contains a list of tags associated with the owned item.
         * @throw: Thrown when ownedItemId is null or empty.
         */
        static void GetTagsAsync(
            const function<void(const vector<string>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& ownedItemId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ownedItemId"] = ownedItemId;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-getTags",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["tags"].template get<vector<string>>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void SetTagsAsync(
            const function<void(const vector<string>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& ownedItemId,
            const vector<string>& tags,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ownedItemId"] = ownedItemId;
                requestData["tags"] = tags;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "inventoryV2-setTags",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["tags"].template get<vector<string>>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
    };
}}}