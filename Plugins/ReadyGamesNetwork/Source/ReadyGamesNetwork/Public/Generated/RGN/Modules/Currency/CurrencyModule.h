#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../random.hpp"
#include "../../../../Utility/CancellationToken.h"
#include "RGNCoinEconomy.h"
#include "../../Model/Request/BaseRequestData.h"
#include "PurchaseRGNCoinRequestData.h"
#include "Currency.h"
#include "CurrencyProductsData.h"
#include "../../Model/Request/BaseMigrationRequestData.h"
#include "PurchaseCurrencyProductRequestData.h"
#include "AddUserCurrenciesResponseData.h"
#include "GetUserCurrenciesResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace Currency {
    class CurrencyModule {
    public:
        /**
         * Gets the information for rgn-coin prices
         * You need to use the in-app purchase process to sell rgn-coin
         * rgn-coin is used for purchasing NFT virtual items
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetRGNCoinEconomyAsync(
            const function<void(const RGN::Modules::Currency::RGNCoinEconomy& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Model::Request::BaseRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseRequestData, RGN::Modules::Currency::RGNCoinEconomy>(
                    "currency-getRGNCoinEconomy",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Adds the rgn-coin currency to the user in
         * in-app purchase plugin callback after verifying the reciept locally
         * 1. Start in-app purchase process
         * 2. Wait for the user to make the in-app purchase transaction
         * 3. Verify locally on device the reciept after successful purchase
         * 4. Call this method with the appropriate in-app item id (M:RGN.Modules.Currency.CurrencyModule.GetRGNCoinEconomyAsync(System.Threading.CancellationToken))
         * Note: this method requires valid ApiKey in your RGN credentials.
         * @param iapUUID - Unique id of the rgn-coin pack that was returned by the M:RGN.Modules.Currency.CurrencyModule.GetRGNCoinEconomyAsync(System.Threading.CancellationToken) method
         * @param iapTransactionId - The transaction id of the in-app purchase
         * @param iapReceipt - The receipt of the in-app purchase
         * @param cancellationToken - A token to cancel the operation.
         */
        static void PurchaseRGNCoinAsync(
            const function<void(const vector<RGN::Modules::Currency::Currency>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& iapUUID,
            const string& iapTransactionId,
            const string& iapReceipt,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Currency::PurchaseRGNCoinRequestData requestData;
                requestData.iapUUID = iapUUID;
                requestData.requestId = RGN::Random::generate_uuid_v4();
                requestData.iapTransactionId = iapTransactionId;
                requestData.iapReceipt = iapReceipt;
                RGNCore::CallAPI<RGN::Modules::Currency::PurchaseRGNCoinRequestData, nlohmann::json>(
                    "currency-purchaseRGNCoinV2",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["userCurrencies"].template get<vector<RGN::Modules::Currency::Currency>>());
                    },
                    fail,
                    true,
                    cancellationToken);
            };
        /**
         * Gets all available currency product from Ready backend
         * The list can contain any game specific currencies
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetInAppPurchaseCurrencyDataAsync(
            const function<void(const RGN::Modules::Currency::CurrencyProductsData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Model::Request::BaseMigrationRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseMigrationRequestData, RGN::Modules::Currency::CurrencyProductsData>(
                    "currency-getProducts",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Adds any project specific currency to the users profile.
         * You can also use this method without going to the in-app purchase process if you want to give the player a currencies
         * @param cancellationToken - A token to cancel the operation.
         */
        static void PurchaseCurrencyProductAsync(
            const function<void(const vector<RGN::Modules::Currency::Currency>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& productId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Currency::PurchaseCurrencyProductRequestData requestData;
                requestData.productId = productId;
                RGNCore::CallAPI<RGN::Modules::Currency::PurchaseCurrencyProductRequestData, vector<RGN::Modules::Currency::Currency>>(
                    "currency-purchaseProduct",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void AddUserCurrenciesAsync(
            const function<void(const vector<RGN::Modules::Currency::Currency>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<RGN::Modules::Currency::Currency>& currencies,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["currencies"] = currencies;
                requestData["version"] = 3;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Currency::AddUserCurrenciesResponseData>(
                    "currency-addUserCurrencies",
                    requestData,
                    [success] (const RGN::Modules::Currency::AddUserCurrenciesResponseData& result) {
                        success(result.userCurrencies);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Returns a list of the user currencies for your app.
         * @param cancellationToken - A token to cancel the operation.
         * @return List of user currencies
         */
        static void GetUserCurrenciesAsync(
            const function<void(const vector<RGN::Modules::Currency::Currency>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Currency::GetUserCurrenciesResponseData>(
                    "currency-getUserCurrencies",
                    requestData,
                    [success] (const RGN::Modules::Currency::GetUserCurrenciesResponseData& result) {
                        success(result.userCurrencies);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
    };
}}}