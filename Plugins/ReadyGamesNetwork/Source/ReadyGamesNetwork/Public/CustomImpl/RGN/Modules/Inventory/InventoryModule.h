#pragma once

#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Generated/RGN/Modules/Inventory/AddVirtualItemToUserInventoryRequestData.h"
#include "../../../../Generated/RGN/Modules/Inventory/AddToInventoryResponseData.h"
#include "../../../../Generated/RGN/Modules/Inventory/InventoryItemsWithVirtualItemsData.h"
#include "../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include <string>

namespace RGN { namespace Modules { namespace Inventory {
	class InventoryModuleCustomImpl {
	public:
        static void AddToInventoryAsync(
            const std::function<void(RGN::Modules::Inventory::AddToInventoryResponseData result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::string virtualItemId,
            int32_t quantity,
            RGN::Modules::VirtualItems::Properties properties,
            CancellationToken cancellationToken = CancellationToken()) {
                AddToInventoryAsync(success, fail, RGNCore::GetUserId(), virtualItemId, quantity, properties, cancellationToken);
            };

        static void AddToInventoryAsync(
            const std::function<void(RGN::Modules::Inventory::AddToInventoryResponseData result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::string userId,
            std::string virtualItemId,
            int32_t quantity,
            RGN::Modules::VirtualItems::Properties properties,
            CancellationToken cancellationToken = CancellationToken()) {
                RGN::Modules::Inventory::InventoryItemData inventoryItemData;
                inventoryItemData.virtualItemId = virtualItemId;
                inventoryItemData.appIds = { RGNCore::GetAppId() };
                inventoryItemData.quantity = quantity;
                inventoryItemData.properties = { properties };
                AddToInventoryAsync(
                    success,
                    fail,
                    userId,
                    inventoryItemData,
                    cancellationToken);
            };
        static void AddToInventoryAsync(
            const function<void(RGN::Modules::Inventory::AddToInventoryResponseData result)>& success,
            const function<void(int httpCode, string error)>& fail,
            string userId,
            RGN::Modules::Inventory::InventoryItemData inventoryData,
            CancellationToken cancellationToken = CancellationToken()) {
                RGN::Modules::Inventory::AddVirtualItemToUserInventoryRequestData requestData;
                requestData.userId = userId;
                requestData.virtualItemInventoryData = inventoryData;
                RGNCore::CallAPI<RGN::Modules::Inventory::AddVirtualItemToUserInventoryRequestData, RGN::Modules::Inventory::AddToInventoryResponseData>(
                    "inventoryV2-addToInventory",
                    requestData,
                    success,
                    fail,
                    false, cancellationToken);
            };
        static void GetWithVirtualItemsDataForCurrentAppAsync(
            const std::function<void(std::vector<RGN::Modules::Inventory::InventoryItemData> result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            int64_t startAfter,
            int32_t limit,
            CancellationToken cancellationToken = CancellationToken()) {
                GetWithVirtualItemsDataByAppIdsAsync(success, fail, {RGNCore::GetAppId()}, startAfter, limit, cancellationToken);
            };

        static void GetWithVirtualItemsDataByAppIdsAsync(
            const std::function<void(std::vector<RGN::Modules::Inventory::InventoryItemData> result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::vector<string> appIds,
            int64_t startAfter,
            int32_t limit,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["startAfter"] = startAfter;
                bodyJson["limit"] = limit;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Inventory::InventoryItemsWithVirtualItemsData>
                    ("inventoryV2-getWithVirtualItemsDataByAppIds", bodyJson,
                    [success](RGN::Modules::Inventory::InventoryItemsWithVirtualItemsData response) {
                        for (RGN::Modules::Inventory::InventoryItemData& item : response.items) {
                            for (RGN::Modules::VirtualItems::VirtualItem& virtualItem : response.virtualItems) {
                                if (item.id == virtualItem.id) {
                                    item.virtualItem = virtualItem;
                                    break;
                                }
                            }
                        }
                        success(response.items);
                    },
                fail,
                false, cancellationToken);
            };

        static RGN::Modules::Inventory::InventoryItemData ParseInventoryItemData(string json) {
                nlohmann::json result = json;
                return result.template get<RGN::Modules::Inventory::InventoryItemData>();
            };
        static vector<RGN::Modules::Inventory::InventoryItemData> ParseInventoryItemsData(string json) {
                nlohmann::json result = json;
                return result.template get<vector<RGN::Modules::Inventory::InventoryItemData>>();
            };
	};
}}}
