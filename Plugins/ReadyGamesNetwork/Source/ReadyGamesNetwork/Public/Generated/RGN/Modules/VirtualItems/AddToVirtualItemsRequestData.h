#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "VirtualItem.h"
#include "../../Model/Request/BaseRequestData.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace RGN { namespace Modules { namespace VirtualItems {
    struct AddToVirtualItemsRequestData : public RGN::Model::Request::BaseRequestData {
        RGN::Modules::VirtualItems::VirtualItem virtualItem;

        friend void to_json(nlohmann::json& nlohmann_json_j, const AddToVirtualItemsRequestData& nlohmann_json_t) {
            nlohmann_json_j["appPackageName"] = nlohmann_json_t.appPackageName;
            nlohmann_json_j["virtualItem"] = nlohmann_json_t.virtualItem;
        }

        friend void from_json(const nlohmann::json& nlohmann_json_j, AddToVirtualItemsRequestData& nlohmann_json_t) {
            if (nlohmann_json_j.contains("appPackageName")) {
                nlohmann_json_j.at("appPackageName").get_to(nlohmann_json_t.appPackageName);
            }
            if (nlohmann_json_j.contains("virtualItem")) {
                nlohmann_json_j.at("virtualItem").get_to(nlohmann_json_t.virtualItem);
            }
        }
    };
}}}