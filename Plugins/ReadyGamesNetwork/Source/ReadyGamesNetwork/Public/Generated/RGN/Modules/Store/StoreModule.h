#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../CustomImpl/RGN/Modules/Store/StoreModule.h"
#include "../../../../Utility/CancellationToken.h"
#include "BuyVirtualItemsResponse.h"
#include "PurchaseResult.h"
#include "BuyStoreOfferResponse.h"
#include "GetLootBoxesResponse.h"
#include "LootBox.h"
#include "LootboxIsAvailableResponse.h"
#include "PurchaseItem.h"
#include "../Inventory/InventoryItemData.h"
#include "StoreOffer.h"
#include "ImportStoreOffersFromCSVResponse.h"
#include "GetStoreOffersResponse.h"
#include "GetStoreOffersWithVirtualItemsDataResponse.h"
#include "GetStoreOfferTagsResponse.h"
#include "../VirtualItems/PriceInfo.h"
#include "SetPricesRequestData.h"
#include "../../Model/TimeInfo.h"
#include "SetTimeRequestData.h"
#include "../Leaderboard/IsStoreOfferAvailableResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace Store {
    class StoreModule {
    public:
        static void BuyVirtualItemsAsync(
            const function<void(const RGN::Modules::Store::PurchaseResult& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& itemIds,
            const vector<string>& currencies = vector<string>(),
            const string& offerId = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Store::StoreModuleCustomImpl::BuyVirtualItemsAsync(
                    success,
                    fail,
                    itemIds,
                    currencies,
                    offerId,
                    cancellationToken);
            };
        static void BuyStoreOfferAsync(
            const function<void(const RGN::Modules::Store::PurchaseResult& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& offerId,
            const vector<string>& currencies = vector<string>(),
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Store::StoreModuleCustomImpl::BuyStoreOfferAsync(
                    success,
                    fail,
                    offerId,
                    currencies,
                    cancellationToken);
            };
        static void GetLootBoxesByIdsAsync(
            const function<void(const vector<RGN::Modules::Store::LootBox>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& ids,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ids"] = ids;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetLootBoxesResponse>(
                    "storeV2-getLootBoxesByIds",
                    requestData,
                    [success] (const RGN::Modules::Store::GetLootBoxesResponse& result) {
                        success(result.lootBoxes);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves a list of lootBoxes from the Ready Games Network (RGN) store based on
         * the provided application identifiers.
         * @param appId - Application identifier used to filter the lootBoxes.
         * @param limit - An integer indicating the maximum number of store offers to retrieve.
         * @param startAfter - An optional parameter representing an store offer id after which to
         * start retrieving the store offers. The default is an empty string.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Result property of the Task returns a list of
         * T:RGN.Modules.Store.LootBox objects representing the lootBoxes that match the specified application identifiers,
         * limit and other optional parameters.
         * @throw: Thrown when the provided appId list is empty.
         */
        static void GetLootBoxesByAppIdAsync(
            const function<void(const vector<RGN::Modules::Store::LootBox>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& appId,
            const int32_t limit,
            const string& startAfter = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["requestedAppId"] = appId;
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetLootBoxesResponse>(
                    "storeV2-getLootBoxesByAppId",
                    requestData,
                    [success] (const RGN::Modules::Store::GetLootBoxesResponse& result) {
                        success(result.lootBoxes);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves a list of lootBoxes for the current application from the Ready Games Network (RGN) store.
         * @param limit - An integer indicating the maximum number of lootBoxes to retrieve.
         * @param startAfter - An optional parameter representing an lootBox id after which to
         * start retrieving the lootBoxes. The default is an empty string.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Result property of the Task returns a list
         * of T:RGN.Modules.Store.LootBox objects representing the lootBoxes that match the current application identifier,
         * limit and other optional parameters.
         * @throw: Thrown when the provided limit value is zero.
         */
        static void GetLootBoxesForCurrentAppAsync(
            const function<void(const vector<RGN::Modules::Store::LootBox>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const int32_t limit,
            const string& startAfter = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Store::StoreModuleCustomImpl::GetLootBoxesForCurrentAppAsync(
                    success,
                    fail,
                    limit,
                    startAfter,
                    cancellationToken);
            };
        /**
         * Asynchronously checks if a lootbox associated with the specified name is
         * available in the Ready Games Network (RGN) store.
         * The name specifies the virtual items that are included into the lootbox.
         * @param name - The unique identifier name associated with the lootbox to be checked.
         * Specifies the virtual items that are included into the lootbox.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Result property of the Task indicates whether
         * the lootbox is available (returns true) or not (returns false).
         * @throw: Thrown when the provided name is null or empty.
         */
        static void LootboxIsAvailableAsync(
            const function<void(const bool result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& name,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["name"] = name;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::LootboxIsAvailableResponse>(
                    "storeV2-lootBoxIsAvailable",
                    requestData,
                    [success] (const RGN::Modules::Store::LootboxIsAvailableResponse& result) {
                        success(result.isAvailable);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously gets the number of virtual items available for a lootbox
         * The name specifies the virtual items that are included into the lootbox.
         * @param name - The unique identifier name associated with the lootbox to be checked.
         * Specifies the virtual items that are included into the lootbox.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Result property of the Task returns
         * the amount of virtual items available in the loot box
         * @throw: Thrown when the provided name is null or empty.
         */
        static void GetAvailableLootBoxItemsCountAsync(
            const function<void(const int64_t result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& name,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["name"] = name;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::LootboxIsAvailableResponse>(
                    "storeV2-lootBoxIsAvailable",
                    requestData,
                    [success] (const RGN::Modules::Store::LootboxIsAvailableResponse& result) {
                        success(result.count);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously opens a lootbox associated with the specified name in the Ready Games Network (RGN) store.
         * The name specifies the virtual items that are included into the lootbox.
         * Randomly selects a virtual item to purchase. Goes with the selected virtual item through purchase process
         * !:BuyVirtualItemsAsync(List<string>, List<string>, string)
         * if the virtual item does not have price specified, it is added to users inventory for free
         * @param name - The unique identifier name associated with the lootbox to be opened.
         * Specifies the virtual items that are included into the lootbox.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Result property of the Task returns the
         * T:RGN.Modules.Inventory.InventoryItemData object representing the items obtained from the opened lootbox.
         * @throw: Thrown when the provided name is null or empty.
         */
        static void OpenLootboxAsync(
            const function<void(const RGN::Modules::Inventory::InventoryItemData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& name,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Store::StoreModuleCustomImpl::OpenLootboxAsync(
                    success,
                    fail,
                    name,
                    cancellationToken);
            };
        static void AddAsync(
            const function<void(const RGN::Modules::Store::StoreOffer& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& appIds,
            const vector<string>& itemIds,
            const vector<string>& tags = vector<string>(),
            const string& name = "",
            const string& description = "",
            const int32_t quantity = 1,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["appIds"] = appIds;
                requestData["itemIds"] = itemIds;
                requestData["name"] = name;
                requestData["description"] = description;
                requestData["tags"] = tags;
                requestData["quantity"] = quantity;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::StoreOffer>(
                    "storeV2-add",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously imports a list of store offers from a CSV formatted string to the Ready Games Network (RGN) store.
         * @param content - A string representing the CSV content that contains the store offers to be imported.
         * @param delimiter - A string representing the character used as a delimiter in the CSV content.
         * @param cancellationToken - An optional parameter for the CancellationToken that propagates a notification
         * that operations should be cancelled. The default value is None.
         * @return A Task representing the asynchronous operation. The Result property of the Task returns
         * a list of T:RGN.Modules.Store.StoreOffer objects representing the successfully imported store offers.
         * @throw: Thrown when the provided content string is null or empty.
         */
        static void ImportStoreOffersFromCSVAsync(
            const function<void(const vector<RGN::Modules::Store::StoreOffer>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& content,
            const string& delimiter,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["userId"] = RGNCore::GetUserId();
                requestData["csvUtf8String"] = content;
                requestData["delimiter"] = delimiter;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::ImportStoreOffersFromCSVResponse>(
                    "storeV2-importStoreOffersFromCSV",
                    requestData,
                    [success] (const RGN::Modules::Store::ImportStoreOffersFromCSVResponse& result) {
                        success(result.offers);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetByTagsAsync(
            const function<void(const vector<RGN::Modules::Store::StoreOffer>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& tags,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["tags"] = tags;
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                requestData["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetStoreOffersResponse>(
                    "storeV2-getByTags",
                    requestData,
                    [success] (const RGN::Modules::Store::GetStoreOffersResponse& result) {
                        success(result.offers);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves a list of store offers from the Ready Games Network (RGN) store based on a provided timestamp.
         * @param appId - The application identifier used for filtering the store offers.
         * @param timestamp - A long type argument representing the timestamp for filtering the store offers.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Result property of the Task returns a list
         * of T:RGN.Modules.Store.StoreOffer objects representing the store offers that match the specified appId and timestamp.
         * @throw: Thrown when the provided appId string is null or empty.
         */
        static void GetByTimestampAsync(
            const function<void(const vector<RGN::Modules::Store::StoreOffer>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& appId,
            const int64_t timestamp,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["requestedAppId"] = appId;
                requestData["timestamp"] = timestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetStoreOffersResponse>(
                    "storeV2-getByTimestamp",
                    requestData,
                    [success] (const RGN::Modules::Store::GetStoreOffersResponse& result) {
                        success(result.offers);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetByAppIdsAsync(
            const function<void(const vector<RGN::Modules::Store::StoreOffer>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& appIds,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["appIds"] = appIds;
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                requestData["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetStoreOffersResponse>(
                    "storeV2-getByAppIds",
                    requestData,
                    [success] (const RGN::Modules::Store::GetStoreOffersResponse& result) {
                        success(result.offers);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves a list of store offers for the current application from the Ready Games Network (RGN) store.
         * @param limit - An integer indicating the maximum number of store offers to retrieve.
         * @param startAfter - An optional parameter representing a store offer 'updatedAt' field after which start the retrieval
         * @param ignoreTimestamp - An optional parameter that indicates whether to ignore the timestamp in the store offers
         * retrieval process. The default is false.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Result property of the Task returns a list
         * of T:RGN.Modules.Store.StoreOffer objects representing the store offers that match the current application identifier,
         * limit and other optional parameters.
         * @throw: Thrown when the provided limit value is zero.
         */
        static void GetForCurrentAppAsync(
            const function<void(const vector<RGN::Modules::Store::StoreOffer>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Store::StoreModuleCustomImpl::GetForCurrentAppAsync(
                    success,
                    fail,
                    limit,
                    startAfter,
                    ignoreTimestamp,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves a list of store offers with their associated virtual items data for the current application
         * from the Ready Games Network (RGN) store.
         * @param limit - An integer indicating the maximum number of store offers to retrieve.
         * @param startAfter - An optional parameter representing a store offer 'updatedAt' field after which start the retrieval
         * @param ignoreTimestamp - An optional parameter that indicates whether to ignore the timestamp in the store
         * offers retrieval process. The default is false.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Result property of the Task returns a list of
         * T:RGN.Modules.Store.StoreOffer objects with their associated store offer items data that match the current application identifier,
         * limit and other optional parameters.
         * @throw: Thrown when the provided limit value is zero.
         */
        static void GetWithVirtualItemsDataForCurrentAppAsync(
            const function<void(const vector<RGN::Modules::Store::StoreOffer>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Store::StoreModuleCustomImpl::GetWithVirtualItemsDataForCurrentAppAsync(
                    success,
                    fail,
                    limit,
                    startAfter,
                    ignoreTimestamp,
                    cancellationToken);
            };
        static void GetWithVirtualItemsDataByAppIdsAsync(
            const function<void(const vector<RGN::Modules::Store::StoreOffer>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& appIds,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Store::StoreModuleCustomImpl::GetWithVirtualItemsDataByAppIdsAsync(
                    success,
                    fail,
                    appIds,
                    limit,
                    startAfter,
                    ignoreTimestamp,
                    cancellationToken);
            };
        static void GetByIdsAsync(
            const function<void(const vector<RGN::Modules::Store::StoreOffer>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& ids,
            const int32_t limit = 0,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = true,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ids"] = ids;
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                requestData["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetStoreOffersResponse>(
                    "storeV2-getByIds",
                    requestData,
                    [success] (const RGN::Modules::Store::GetStoreOffersResponse& result) {
                        success(result.offers);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves a list of tags associated with a specific store offer from the Ready Games Network (RGN) store.
         * @param offerId - The identifier of the store offer for which to retrieve tags.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Result property of the Task returns a list of tags
         * associated with the specified store offer.
         * @throw: Thrown when the provided offerId is null or empty.
         */
        static void GetTagsAsync(
            const function<void(const vector<string>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& offerId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["offerId"] = offerId;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Store::GetStoreOfferTagsResponse>(
                    "storeV2-getTags",
                    requestData,
                    [success] (const RGN::Modules::Store::GetStoreOfferTagsResponse& result) {
                        success(result.tags);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void SetTagsAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& offerId,
            const vector<string>& tags,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["offerId"] = offerId;
                requestData["tags"] = tags;
                RGNCore::CallAPI<nlohmann::json>(
                    "storeV2-setTags",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously sets the name for a specific store offer in the Ready Games Network (RGN) store.
         * @param offerId - The identifier of the store offer for which to set the name.
         * @param name - The new name to be set for the specified store offer.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The task result does not return a value.
         * @throw: Thrown when the provided offerId or name is null or empty.
         */
        static void SetNameAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& offerId,
            const string& name,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["offerId"] = offerId;
                requestData["name"] = name;
                RGNCore::CallAPI<nlohmann::json>(
                    "storeV2-setName",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously sets the description for a specific store offer in the Ready Games Network (RGN) store.
         * @param offerId - The identifier of the store offer for which to set the description.
         * @param description - The new description to be set for the specified store offer.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The task result does not return a value.
         * @throw: Thrown when the provided offerId or description is null or empty.
         */
        static void SetDescriptionAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& offerId,
            const string& description,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["offerId"] = offerId;
                requestData["description"] = description;
                RGNCore::CallAPI<nlohmann::json>(
                    "storeV2-setDescription",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void SetPricesAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& offerId,
            const vector<RGN::Modules::VirtualItems::PriceInfo>& prices,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Store::SetPricesRequestData requestData;
                requestData.offerId = offerId;
                requestData.prices = prices;
                RGNCore::CallAPI<RGN::Modules::Store::SetPricesRequestData>(
                    "storeV2-setPrices",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously sets the time information for a specific store offer in the Ready Games Network (RGN) store.
         * @param offerId - The identifier of the store offer for which to set the time information.
         * @param time - A TimeInfo object containing the time information to be set for the specified store offer.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The task result does not return a value.
         * @throw: Thrown when the provided offerId is null or empty or when the
         * provided TimeInfo object is null.
         */
        static void SetTimeAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& offerId,
            const RGN::Model::TimeInfo& time,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Store::SetTimeRequestData requestData;
                requestData.offerId = offerId;
                requestData.time = time;
                RGNCore::CallAPI<RGN::Modules::Store::SetTimeRequestData>(
                    "storeV2-setTime",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously sets the image URL for a specific store offer in the Ready Games Network (RGN) store.
         * @param offerId - The identifier of the store offer for which to set the image URL.
         * @param imageUrl - The URL of the image to be set for the specified store offer.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The task result does not return a value.
         * @throw: Thrown when the provided offerId or imageUrl is null or empty.
         */
        static void SetImageUrlAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& offerId,
            const string& imageUrl,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["offerId"] = offerId;
                requestData["imageUrl"] = imageUrl;
                RGNCore::CallAPI<nlohmann::json>(
                    "storeV2-setImageUrl",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously checks if the store offer meets all requirements to be available for the user.
         * The check is performed for the store offer specified F:RGN.Modules.Store.StoreOffer.time and
         * F:RGN.Modules.Store.StoreOffer.requiredToPurchase
         * @param storeOfferId - The identifier of the store offer.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Task result contains a T:RGN.Modules.Leaderboard.IsStoreOfferAvailableResponseData
         * value to indicate if the store offer is available
         * @throw: Thrown when the provided storeOfferId is null or empty.
         */
        static void IsAvailableAsync(
            const function<void(const RGN::Modules::Leaderboard::IsStoreOfferAvailableResponseData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& storeOfferId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["offerId"] = storeOfferId;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::IsStoreOfferAvailableResponseData>(
                    "storeV2-isAvailable",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves the properties of a specific store offer in the Ready Games Network (RGN) store.
         * @param storeOfferId - The identifier of the store offer whose properties are to be retrieved.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Task result contains a string that represents the JSON-formatted properties of the store offer.
         * @throw: Thrown when the provided storeOfferId is null or empty.
         */
        static void GetPropertiesAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& storeOfferId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["offerId"] = storeOfferId;
                RGNCore::CallAPI<nlohmann::json>(
                    "storeV2-getProperties",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously sets the properties of a specific store offer in the Ready Games Network (RGN) store.
         * @param storeOfferId - The identifier of the store offer whose properties are to be set.
         * @param json - A string containing the JSON representation of the properties to be set.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Task result contains a string confirmation of the properties' update.
         * @throw: Thrown when the provided storeOfferId or json is null or empty.
         */
        static void SetPropertiesAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& storeOfferId,
            const string& json,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["offerId"] = storeOfferId;
                requestData["json"] = json;
                RGNCore::CallAPI<nlohmann::json>(
                    "storeV2-setProperties",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
    };
}}}