#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Utility/CancellationToken.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace VirtualItems {
    class VirtualItemsModule_Admin {
    public:
        static void DeleteVirtualItemsByIdsAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& virtualItemIds,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["virtualItemIds"] = virtualItemIds;
                RGNCore::CallAPI<nlohmann::json>(
                    "virtualItemsV2-deleteVirtualItemsByIds",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void DeleteVirtualItemsByNameAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& itemName,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["itemName"] = itemName;
                RGNCore::CallAPI<nlohmann::json>(
                    "virtualItemsV2-deleteVirtualItemsByName",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void DeleteVirtualItemByAppIdAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& appId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["requestedAppId"] = appId;
                RGNCore::CallAPI<nlohmann::json>(
                    "virtualItemsV2-deleteVirtualItemByAppId",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void AddFromCSVWithBlockchainStubAsync(
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
                requestData["addBlockchainStub"] = true;
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
    };
}}}