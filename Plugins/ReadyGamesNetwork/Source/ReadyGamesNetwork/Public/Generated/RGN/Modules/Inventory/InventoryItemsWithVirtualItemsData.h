#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "InventoryItemData.h"
#include "../VirtualItems/VirtualItem.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace RGN { namespace Modules { namespace Inventory {
    struct InventoryItemsWithVirtualItemsData {
        vector<RGN::Modules::Inventory::InventoryItemData> items;
        vector<RGN::Modules::VirtualItems::VirtualItem> virtualItems;

        friend void to_json(nlohmann::json& nlohmann_json_j, const InventoryItemsWithVirtualItemsData& nlohmann_json_t) {
            nlohmann_json_j["items"] = nlohmann_json_t.items;
            nlohmann_json_j["virtualItems"] = nlohmann_json_t.virtualItems;
        }

        friend void from_json(const nlohmann::json& nlohmann_json_j, InventoryItemsWithVirtualItemsData& nlohmann_json_t) {
            if (nlohmann_json_j.contains("items")) {
                auto json_items = nlohmann_json_j.at("items");
                if (!json_items.is_null() && json_items.is_array()) {
                    json_items.get_to(nlohmann_json_t.items);
                }
            }
            if (nlohmann_json_j.contains("virtualItems")) {
                auto json_virtualItems = nlohmann_json_j.at("virtualItems");
                if (!json_virtualItems.is_null() && json_virtualItems.is_array()) {
                    json_virtualItems.get_to(nlohmann_json_t.virtualItems);
                }
            }
        }
    };
}}}