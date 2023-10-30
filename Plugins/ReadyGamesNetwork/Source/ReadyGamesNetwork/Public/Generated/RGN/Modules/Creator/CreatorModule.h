#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "CreatorSignupResponseData.h"
#include "CreatorSignupRequestData.h"
#include "../VirtualItems/VirtualItem.h"
#include "CreatorSubmitItemResponseData.h"
#include "CreatorSubmitItemRequestData.h"
#include "CreatorData.h"
#include "../../Model/Request/BaseMigrationRequestData.h"
#include "../Currency/ClaimCurrencyResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace Creator {
    class CreatorModule {
    public:
        static void BecomeACreatorAsync(
            string& brandName,
            const function<void(RGN::Modules::Creator::CreatorSignupResponseData result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Creator::CreatorSignupRequestData requestData;
                requestData.brandName = brandName;
                RGNCore::CallAPI<RGN::Modules::Creator::CreatorSignupRequestData, RGN::Modules::Creator::CreatorSignupResponseData>(
                    "creator-signup",
                    requestData,
                    complete,
                    fail);
            };
        static void SubmitItemAsync(
            RGN::Modules::VirtualItems::VirtualItem& customizedItem,
            const function<void(RGN::Modules::Creator::CreatorSubmitItemResponseData result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Modules::Creator::CreatorSubmitItemRequestData requestData;
                requestData.customizedItem = customizedItem;
                RGNCore::CallAPI<RGN::Modules::Creator::CreatorSubmitItemRequestData, RGN::Modules::Creator::CreatorSubmitItemResponseData>(
                    "creator-addItem",
                    requestData,
                    complete,
                    fail);
            };
        static void GetCreatorDataAsync(
            const function<void(RGN::Modules::Creator::CreatorData result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Model::Request::BaseMigrationRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseMigrationRequestData, RGN::Modules::Creator::CreatorData>(
                    "creator-getCreatorData",
                    requestData,
                    complete,
                    fail);
            };
        static void ClaimCurrenciesAsync(
            const function<void(RGN::Modules::Currency::ClaimCurrencyResponseData result)>& complete,
            const function<void(int httpCode, string error)>& fail) {
                RGN::Model::Request::BaseMigrationRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseMigrationRequestData, RGN::Modules::Currency::ClaimCurrencyResponseData>(
                    "creator-claimCurrency",
                    requestData,
                    complete,
                    fail);
            };
    };
}}}