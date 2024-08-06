#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../CustomImpl/RGN/Modules/VirtualItems/VirtualItemsModule.h"
#include "../../../../Utility/CancellationToken.h"
#include "../../Model/Request/BaseMigrationRequestData.h"
#include "VirtualItem.h"
#include "AddVirtualItemResponseData.h"
#include "AddToVirtualItemsRequestData.h"
#include "UpdateVirtualItemsRequestData.h"
#include "VirtualItemsResponseData.h"
#include "GetAllVirtualItemsByAppIdsRequestData.h"
#include "GetVirtualItemsByIdsRequestData.h"
#include "GetVirtualItemTagsResponse.h"
#include "../../Model/ImageSize.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace VirtualItems {
    class VirtualItemsModule {
    public:
        /**
         * Add a virtual item
         * @param cancellationToken - A token to cancel the operation.
         */
        static void AddVirtualItemAsync(
            const function<void(const RGN::Modules::VirtualItems::VirtualItem& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const RGN::Modules::VirtualItems::VirtualItem& virtualItem,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::VirtualItems::AddToVirtualItemsRequestData requestData;
                requestData.virtualItem = virtualItem;
                RGNCore::CallAPI<RGN::Modules::VirtualItems::AddToVirtualItemsRequestData, RGN::Modules::VirtualItems::AddVirtualItemResponseData>(
                    "virtualItemsV2-add",
                    requestData,
                    [success] (const RGN::Modules::VirtualItems::AddVirtualItemResponseData& result) {
                        success(result.virtualItem);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously adds a list of virtual items from a CSV content string to the Ready Games Network.
         * @param virtualItemName - The name of the virtual item.
         * @param csvContent - The content of the CSV file as a string.
         * @param csvDelimiter - The delimiter used in the CSV file (defaults to ',').
         * @param cancellationToken - A CancellationToken to observe while waiting for the task to complete.
         * @return A Task that represents the asynchronous operation. The Task result contains a list of strings, which are the item IDs of the added virtual items.
         * @throw: Thrown when 'virtualItemName', 'csvContent', or 'csvDelimiter' is null or empty.
         */
        static void AddFromCSVAsync(
            const function<void(const vector<string>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& virtualItemName,
            const string& csvContent,
            const string& csvDelimiter = ",",
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemName"] = virtualItemName;
                requestData["csvFileString"] = csvContent;
                requestData["delimiter"] = csvDelimiter;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "virtualItemsV2-addFromCSV",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["newVirtualItemIds"].template get<vector<string>>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously updates a specific virtual item in the Ready Games Network.
         * @param itemId - The ID of the virtual item to be updated.
         * @param virtualItem - A VirtualItem object containing the new data for the virtual item.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The result of the Task is the updated VirtualItem.
         */
        static void UpdateVirtualItemAsync(
            const function<void(const RGN::Modules::VirtualItems::VirtualItem& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& itemId,
            const RGN::Modules::VirtualItems::VirtualItem& virtualItem,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::VirtualItems::UpdateVirtualItemsRequestData requestData;
                requestData.itemId = itemId;
                requestData.virtualItem = virtualItem;
                RGNCore::CallAPI<RGN::Modules::VirtualItems::UpdateVirtualItemsRequestData, RGN::Modules::VirtualItems::AddVirtualItemResponseData>(
                    "virtualItemsV2-update",
                    requestData,
                    [success] (const RGN::Modules::VirtualItems::AddVirtualItemResponseData& result) {
                        success(result.virtualItem);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously deletes a specific virtual item from the Ready Games Network.
         * @param itemId - The ID of the virtual item to be deleted.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation.
         * @throw: Thrown when 'itemId' is null or empty.
         */
        static void DeleteVirtualItemAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& itemId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["itemId"] = itemId;
                RGNCore::CallAPI<nlohmann::json>(
                    "virtualItemsV2-deleteVirtualItem",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Getting all virtual items releated to your game
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetVirtualItemsAsync(
            const function<void(const vector<RGN::Modules::VirtualItems::VirtualItem>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Model::Request::BaseMigrationRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseMigrationRequestData, RGN::Modules::VirtualItems::VirtualItemsResponseData>(
                    "virtualItemsV2-getByAppId",
                    requestData,
                    [success] (const RGN::Modules::VirtualItems::VirtualItemsResponseData& result) {
                        success(result.virtualItems);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Returns a limited list of virtual items for your game.
         * @param limit - Maximal count of items to return
         * @param startAfter - The item id to start after
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetVirtualItemsAsync(
            const function<void(const vector<RGN::Modules::VirtualItems::VirtualItem>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const int32_t limit,
            const string& startAfter = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::VirtualItems::GetAllVirtualItemsByAppIdsRequestData requestData;
                requestData.appIds = vector<string>{ RGNCore::GetAppId() };
                requestData.limit = limit;
                requestData.startAfter = startAfter;
                RGNCore::CallAPI<RGN::Modules::VirtualItems::GetAllVirtualItemsByAppIdsRequestData, RGN::Modules::VirtualItems::VirtualItemsResponseData>(
                    "virtualItemsV2-getByAppIds",
                    requestData,
                    [success] (const RGN::Modules::VirtualItems::VirtualItemsResponseData& result) {
                        success(result.virtualItems);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetVirtualItemsByIdsAsync(
            const function<void(const vector<RGN::Modules::VirtualItems::VirtualItem>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& virtualItemsIds,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::VirtualItems::GetVirtualItemsByIdsRequestData requestData;
                requestData.ids = virtualItemsIds;
                RGNCore::CallAPI<RGN::Modules::VirtualItems::GetVirtualItemsByIdsRequestData, RGN::Modules::VirtualItems::VirtualItemsResponseData>(
                    "virtualItemsV2-getByIds",
                    requestData,
                    [success] (const RGN::Modules::VirtualItems::VirtualItemsResponseData& result) {
                        success(result.virtualItems);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetByTagsAsync(
            const function<void(const vector<RGN::Modules::VirtualItems::VirtualItem>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& tags,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["tags"] = tags;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::VirtualItems::VirtualItemsResponseData>(
                    "virtualItemsV2-getByTags",
                    requestData,
                    [success] (const RGN::Modules::VirtualItems::VirtualItemsResponseData& result) {
                        success(result.virtualItems);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Returns all tags for specific virtual item
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetTagsAsync(
            const function<void(const vector<string>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& virtualItemId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::VirtualItems::GetVirtualItemTagsResponse>(
                    "virtualItemsV2-getTags",
                    requestData,
                    [success] (const RGN::Modules::VirtualItems::GetVirtualItemTagsResponse& result) {
                        success(result.tags);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void SetTagsAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& virtualItemId,
            const vector<string>& tags,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["tags"] = tags;
                RGNCore::CallAPI<nlohmann::json>(
                    "virtualItemsV2-setTags",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Sets the name for a specific virtual item
         * @param cancellationToken - A token to cancel the operation.
         */
        static void SetNameAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& virtualItemId,
            const string& name,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["name"] = name;
                RGNCore::CallAPI<nlohmann::json>(
                    "virtualItemsV2-setName",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Sets the description for a specific virtual item
         * @param cancellationToken - A token to cancel the operation.
         */
        static void SetDescriptionAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& virtualItemId,
            const string& description,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["description"] = description;
                RGNCore::CallAPI<nlohmann::json>(
                    "virtualItemsV2-setDescription",
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
            const string& virtualItemId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "virtualItemsV2-getProperties",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["properties"].template get<string>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Set json on a given virtualItemId.
         * @param cancellationToken - A token to cancel the operation.
         * @return Returns json as string
         */
        static void SetPropertiesAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& virtualItemId,
            const string& json,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemId"] = virtualItemId;
                requestData["json"] = json;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "virtualItemsV2-setProperties",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["properties"].template get<string>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Uploads an image thumbnail for a virtual item to the RGNCore backend.
         * @param virtualItemId - The ID of the virtual item to upload the thumbnail for.
         * @param thumbnailTextureBytes - The byte array of the thumbnail texture image to upload.
         * @param cancellationToken - A token to cancel the operation.
         * @return A boolean indicating whether the upload was successful.
         */
        static void UploadImageAsync(
            const function<void(const bool result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& virtualItemId,
            const vector<uint8_t>& thumbnailTextureBytes,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::VirtualItems::VirtualItemsModuleCustomImpl::UploadImageAsync(
                    success,
                    fail,
                    virtualItemId,
                    thumbnailTextureBytes,
                    cancellationToken);
            };
        /**
         * Downloads an image asynchronously from a specified virtual item ID.
         * @param virtualItemId - The ID of the virtual item to download the image from.
         * @param size - The size type of virtual item image to download.
         * @param cancellationToken - A cancellation token that can be used to cancel the asynchronous operation.
         * @return A byte array containing the image data.
         */
        static void DownloadImageAsync(
            const function<void(const vector<uint8_t>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& virtualItemId,
            const RGN::Model::ImageSize& size,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::VirtualItems::VirtualItemsModuleCustomImpl::DownloadImageAsync(
                    success,
                    fail,
                    virtualItemId,
                    size,
                    cancellationToken);
            };
    };
}}}