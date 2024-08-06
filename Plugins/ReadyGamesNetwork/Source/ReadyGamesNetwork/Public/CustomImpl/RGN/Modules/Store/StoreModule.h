#pragma once

#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Generated/RGN/Modules/Store/BuyVirtualItemsResponse.h"
#include "../../../../Generated/RGN/Modules/Store/BuyStoreOfferResponse.h"
#include "../../../../Generated/RGN/Modules/Store/GetLootBoxesResponse.h"
#include "../../../../Generated/RGN/Modules/Store/GetStoreOffersResponse.h"
#include "../../../../Generated/RGN/Modules/Store/GetStoreOffersWithVirtualItemsDataResponse.h"
#include "../../../../Generated/RGN/Modules/Store/PurchaseItem.h"
#include "../../../../Generated/RGN/Modules/Store/PurchaseResult.h"
#include "../../../../Generated/RGN/Modules/Store/StoreOffer.h"
#include "../../../../Generated/RGN/Modules/Inventory/InventoryItemData.h"
#include <string>

namespace RGN { namespace Modules { namespace Store {
	class StoreModuleCustomImpl {
	public:
        static void GetLootBoxesForCurrentAppAsync(
            const function<void(vector<RGN::Modules::Store::LootBox> result)>& success,
            const function<void(int httpCode, string error)>& fail,
            int32_t limit,
            string startAfter,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetLootBoxesResponse>(
                    "storeV2-getLootBoxesByAppId",
                    requestData,
                    [success](RGN::Modules::Store::GetLootBoxesResponse result) {
                        success(result.lootBoxes);
                    },
                    fail,
                    false,
                    cancellationToken
                );
            };
        static void OpenLootboxAsync(
            const function<void(RGN::Modules::Inventory::InventoryItemData result)>& success,
            const function<void(int httpCode, string error)>& fail,
            string name,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["name"] = name;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::PurchaseItem>(
                    "storeV2-openLootBox",
                    requestData,
                    [success](RGN::Modules::Store::PurchaseItem result) {
                        RGN::Modules::Inventory::InventoryItemData inventoryItemData;
                        inventoryItemData.id = result.inventoryItem.id;
                        inventoryItemData.virtualItemId = result.virtualItem.id;
                        inventoryItemData.appIds = result.inventoryItem.appIds;
                        inventoryItemData.tags = result.inventoryItem.tags;
                        inventoryItemData.quantity = result.inventoryItem.quantity;
                        inventoryItemData.status = result.inventoryItem.status;
                        inventoryItemData.itemUpgrades = result.inventoryItem.itemUpgrades;
                        inventoryItemData.properties = result.inventoryItem.properties;
                        inventoryItemData.virtualItem = result.virtualItem;
                        success(inventoryItemData);
                    },
                fail,
                false, cancellationToken);
            };
        static void GetForCurrentAppAsync(
            const function<void(vector<RGN::Modules::Store::StoreOffer> result)>& success,
            const function<void(int httpCode, string error)>& fail,
            int32_t limit,
            int64_t startAfter,
            bool ignoreTimestamp,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["appIds"] = { RGNCore::GetAppId() };
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                requestData["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetStoreOffersResponse>(
                    "storeV2-getByAppIds",
                    requestData,
                    [success](RGN::Modules::Store::GetStoreOffersResponse result) {
                        success(result.offers);
                    },
                    fail,
                    false,
                    cancellationToken
                );
            };
        static void GetWithVirtualItemsDataForCurrentAppAsync(
            const function<void(vector<RGN::Modules::Store::StoreOffer> result)>& success,
            const function<void(int httpCode, string error)>& fail,
            int32_t limit,
            int64_t startAfter,
            bool ignoreTimestamp,
            CancellationToken cancellationToken = CancellationToken()) {
                GetWithVirtualItemsDataByAppIdsAsync(
                    success,
                    fail,
                    { RGNCore::GetAppId() },
                    limit,
                    startAfter,
                    ignoreTimestamp,
                    cancellationToken
                );
            };
        static void GetWithVirtualItemsDataByAppIdsAsync(
            const std::function<void(std::vector<RGN::Modules::Store::StoreOffer> result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::vector<std::string> appIds,
            int32_t limit,
            int64_t startAfter,
            bool ignoreTimestamp,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["appIds"] = appIds;
                bodyJson["limit"] = limit;
                bodyJson["startAfter"] = startAfter;
                bodyJson["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetStoreOffersWithVirtualItemsDataResponse>
                ("storeV2-getWithVirtualItemsDataByAppIds", bodyJson,
                    [success](RGN::Modules::Store::GetStoreOffersWithVirtualItemsDataResponse response) {
                        std::vector<RGN::Modules::Store::StoreOffer> queriedOffers = response.offers;
                        std::vector<RGN::Modules::VirtualItems::VirtualItem> virtualItems = response.virtualItems;
                        for (StoreOffer& storeOffer : queriedOffers) {
                            std::vector<RGN::Modules::VirtualItems::VirtualItem> items;
                            for (std::string& itemId : storeOffer.itemIds) {
                                for (RGN::Modules::VirtualItems::VirtualItem& item : items) {
                                    if (item.id == itemId) {
                                        items.push_back(item);
                                        break;
                                    }
                                }
                            }
                            storeOffer.virtualItems = items;
                        }
                        success(queriedOffers);
                    },
                    fail,
                    false, cancellationToken
                );
            };
        static void BuyVirtualItemsAsync(
            const std::function<void(RGN::Modules::Store::PurchaseResult result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::vector<string> itemIds,
            std::vector<string> currencies,
            std::string offerId,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["itemIds"] = itemIds;
                bodyJson["currencies"] = currencies;
                bodyJson["offerId"] = offerId;
                bodyJson["version"] = 2;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::BuyVirtualItemsResponse>
                    ("storeV2-buyVirtualItems", bodyJson,
                    [offerId, success](RGN::Modules::Store::BuyVirtualItemsResponse response) {
                        std::vector<RGN::Modules::Inventory::InventoryItemData> inventoryItems;
                        for (RGN::Modules::Store::PurchaseItem& purchaseItem : response.purchasedItems) {
                            RGN::Modules::Inventory::InventoryItemData inventoryItem;
                            inventoryItem.id = purchaseItem.inventoryItem.id;
                            inventoryItem.virtualItemId = purchaseItem.virtualItem.id;
                            inventoryItem.appIds = purchaseItem.inventoryItem.appIds;
                            inventoryItem.tags = purchaseItem.inventoryItem.tags;
                            inventoryItem.quantity = purchaseItem.inventoryItem.quantity;
                            inventoryItem.status = purchaseItem.inventoryItem.status;
                            inventoryItem.itemUpgrades = purchaseItem.inventoryItem.itemUpgrades;
                            inventoryItem.properties = purchaseItem.inventoryItem.properties;
                            inventoryItem.virtualItem = purchaseItem.virtualItem;
                            inventoryItems.push_back(inventoryItem);
                        }
                        RGN::Modules::Store::PurchaseResult purchaseResult;
                        purchaseResult.offerId = offerId;
                        purchaseResult.items = inventoryItems;
                        purchaseResult.updatedCurrencies = response.updatedCurrencies;
                        success(purchaseResult);
                    },
                fail,
                false, cancellationToken);
            };
        static void BuyStoreOfferAsync(
            const std::function<void(RGN::Modules::Store::PurchaseResult result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::string offerId,
            std::vector<std::string> currencies,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["appId"] = RGNCore::GetAppId();
                bodyJson["offerId"] = offerId;
                bodyJson["currencies"] = currencies;
                bodyJson["version"] = 2;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::BuyStoreOfferResponse>
                    ("storeV2-buyStoreOffer", bodyJson,
                    [offerId, success](RGN::Modules::Store::BuyStoreOfferResponse response) {
                        std::vector<RGN::Modules::Inventory::InventoryItemData> inventoryItems;
                        for (RGN::Modules::Store::PurchaseItem& purchaseItem : response.purchasedItems) {
                            RGN::Modules::Inventory::InventoryItemData inventoryItem;
                            inventoryItem.id = purchaseItem.inventoryItem.id;
                            inventoryItem.virtualItemId = purchaseItem.virtualItem.id;
                            inventoryItem.appIds = purchaseItem.inventoryItem.appIds;
                            inventoryItem.tags = purchaseItem.inventoryItem.tags;
                            inventoryItem.quantity = purchaseItem.inventoryItem.quantity;
                            inventoryItem.status = purchaseItem.inventoryItem.status;
                            inventoryItem.itemUpgrades = purchaseItem.inventoryItem.itemUpgrades;
                            inventoryItem.properties = purchaseItem.inventoryItem.properties;
                            inventoryItem.virtualItem = purchaseItem.virtualItem;
                            inventoryItems.push_back(inventoryItem);
                        }
                        RGN::Modules::Store::PurchaseResult purchaseResult;
                        purchaseResult.offerId = offerId;
                        purchaseResult.items = inventoryItems;
                        purchaseResult.updatedCurrencies = response.updatedCurrencies;
                        success(purchaseResult);
                    },
                fail,
                false, cancellationToken);
            };
	};
}}}