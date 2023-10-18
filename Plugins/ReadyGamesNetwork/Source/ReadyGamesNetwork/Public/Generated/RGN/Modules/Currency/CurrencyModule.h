#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "RGNCoinEconomy.h"
#include "../../Model/Request/BaseRequestData.h"
#include "PurchaseRGNCoinRequestData.h"
#include "Currency.h"
#include "CurrencyProductsData.h"
#include "../../Model/Request/BaseMigrationRequestData.h"
#include "PurchaseCurrencyProductRequestData.h"
#include "AddUserCurrenciesResponseData.h"
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace Currency {
    class CurrencyModule {
    public:
        static void GetRGNCoinEconomyAsync(
            const function<void(RGN::Modules::Currency::RGNCoinEconomy result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Model::Request::BaseRequestData requestData;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Currency::RGNCoinEconomy>(
                    "currency-getRGNCoinEconomy",
                    requestData,
                    complete,
                    fail);
            };
        static void PurchaseRGNCoinAsync(
            string iapUUID,
            string iapTransactionId,
            string iapReceipt,
            const function<void(vector<RGN::Modules::Currency::Currency> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Currency::PurchaseRGNCoinRequestData requestData;
                requestData.iapUUID = iapUUID;
                requestData.requestId = System.Guid.NewGuid().ToString("N");
                requestData.iapTransactionId = iapTransactionId;
                requestData.iapReceipt = iapReceipt;
                RGNCore::CallAPI(
                    "currency-purchaseRGNCoinV2",
                    requestData,
                    [complete] (nlohmann::json result) {
                        complete(result["userCurrencies"]);
                    },
                    fail);
            };
        static void GetInAppPurchaseCurrencyDataAsync(
            const function<void(RGN::Modules::Currency::CurrencyProductsData result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Model::Request::BaseMigrationRequestData requestData;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Currency::CurrencyProductsData>(
                    "currency-getProducts",
                    requestData,
                    complete,
                    fail);
            };
        static void PurchaseCurrencyProductAsync(
            string productId,
            const function<void(vector<RGN::Modules::Currency::Currency> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Currency::PurchaseCurrencyProductRequestData requestData;
                requestData.productId = productId;
                RGNCore::CallAPI<nlohmann::json, vector<RGN::Modules::Currency::Currency>>(
                    "currency-purchaseProduct",
                    requestData,
                    [complete] (vector<RGN::Modules::Currency::Currency> result) {
                        complete(result);
                    },
                    fail);
            };
        static void AddUserCurrenciesAsync(
            vector<RGN::Modules::Currency::Currency> currencies,
            const function<void(vector<RGN::Modules::Currency::Currency> result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["currencies"] = currencies;
                requestData["version"] = 3;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Currency::AddUserCurrenciesResponseData>(
                    "currency-addUserCurrencies",
                    requestData,
                    [complete] (RGN::Modules::Currency::AddUserCurrenciesResponseData result) {
                        complete(result.userCurrencies);
                    },
                    fail);
            };
    };
}}}