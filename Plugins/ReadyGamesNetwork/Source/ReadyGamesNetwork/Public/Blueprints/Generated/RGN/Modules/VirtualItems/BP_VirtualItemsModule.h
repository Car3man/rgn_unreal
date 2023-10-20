#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Core/BP_CancellationToken.h"
#include "../../../../../Core/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItemsModule.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItem.h"
#include "BP_VirtualItem.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/AddVirtualItemResponseData.h"
#include "BP_AddVirtualItemResponseData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/AddToVirtualItemsRequestData.h"
#include "BP_AddToVirtualItemsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/UpdateVirtualItemsRequestData.h"
#include "BP_UpdateVirtualItemsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/VirtualItemsResponseData.h"
#include "BP_VirtualItemsResponseData.h"
#include "../../../../../Generated/RGN/Model/Request/BaseMigrationRequestData.h"
#include "../../Model/Request/BP_BaseMigrationRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/GetAllVirtualItemsByAppIdsRequestData.h"
#include "BP_GetAllVirtualItemsByAppIdsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/GetVirtualItemsByIdsRequestData.h"
#include "BP_GetVirtualItemsByIdsRequestData.h"
#include "../../../../../Generated/RGN/Modules/VirtualItems/GetVirtualItemTagsResponse.h"
#include "BP_GetVirtualItemTagsResponse.h"
#include "../../../../../Generated/RGN/Model/ImageSize.h"
#include "../../Model/BP_ImageSize.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_VirtualItemsModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FVirtualItemsModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleAddVirtualItemAsyncResponse, const FBP_VirtualItem&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleAddFromCSVAsyncResponse, const TArray<FString>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleUpdateVirtualItemAsyncResponse, const FBP_VirtualItem&, response);
DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleDeleteVirtualItemAsyncResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleGetVirtualItemsAsyncResponse, const TArray<FBP_VirtualItem>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleGetVirtualItemsByIdsAsyncResponse, const TArray<FBP_VirtualItem>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleGetByTagsAsyncResponse, const TArray<FBP_VirtualItem>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleGetTagsAsyncResponse, const TArray<FString>&, response);
DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleSetTagsAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleSetNameAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FVirtualItemsModuleSetDescriptionAsyncResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleGetPropertiesAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleSetPropertiesAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleUploadImageAsyncResponse, bool, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FVirtualItemsModuleDownloadImageAsyncResponse, const TArray<uint8>&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_VirtualItemsModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void AddVirtualItemAsync(
        const FBP_VirtualItem& virtualItem,
        FVirtualItemsModuleAddVirtualItemAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            RGN::Modules::VirtualItems::VirtualItem cpp_virtualItem;
			FBP_VirtualItem::ConvertToCoreModel(virtualItem, cpp_virtualItem);
            RGN::Modules::VirtualItems::VirtualItemsModule::AddVirtualItemAsync(
                cpp_virtualItem,
                [onSuccess](RGN::Modules::VirtualItems::VirtualItem response) {
                    FBP_VirtualItem bpResponse;
					FBP_VirtualItem::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void AddFromCSVAsync(
        const FString& virtualItemName,
        const FString& csvContent,
        const FString& csvDelimiter,
        const FBP_CancellationToken& cancellationToken,
        FVirtualItemsModuleAddFromCSVAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_virtualItemName;
            string cpp_csvContent;
            string cpp_csvDelimiter;
            CancellationToken cpp_cancellationToken;
			cpp_virtualItemName = string(TCHAR_TO_UTF8(*virtualItemName));
			cpp_csvContent = string(TCHAR_TO_UTF8(*csvContent));
			cpp_csvDelimiter = string(TCHAR_TO_UTF8(*csvDelimiter));
			FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::AddFromCSVAsync(
                cpp_virtualItemName,
                cpp_csvContent,
                cpp_csvDelimiter,
                cpp_cancellationToken,
                [onSuccess](vector<string> response) {
                    TArray<FString> bpResponse;
					for (const auto& response_item : response) {
						FString b_response_item;
						b_response_item = FString(response_item.c_str());
						bpResponse.Add(b_response_item);
					}
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void UpdateVirtualItemAsync(
        const FString& itemId,
        const FBP_VirtualItem& virtualItem,
        FVirtualItemsModuleUpdateVirtualItemAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_itemId;
            RGN::Modules::VirtualItems::VirtualItem cpp_virtualItem;
			cpp_itemId = string(TCHAR_TO_UTF8(*itemId));
			FBP_VirtualItem::ConvertToCoreModel(virtualItem, cpp_virtualItem);
            RGN::Modules::VirtualItems::VirtualItemsModule::UpdateVirtualItemAsync(
                cpp_itemId,
                cpp_virtualItem,
                [onSuccess](RGN::Modules::VirtualItems::VirtualItem response) {
                    FBP_VirtualItem bpResponse;
					FBP_VirtualItem::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void DeleteVirtualItemAsync(
        const FString& itemId,
        FVirtualItemsModuleDeleteVirtualItemAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_itemId;
			cpp_itemId = string(TCHAR_TO_UTF8(*itemId));
            RGN::Modules::VirtualItems::VirtualItemsModule::DeleteVirtualItemAsync(
                cpp_itemId,
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void GetVirtualItemsAsync1(
        FVirtualItemsModuleGetVirtualItemsAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            RGN::Modules::VirtualItems::VirtualItemsModule::GetVirtualItemsAsync(
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    TArray<FBP_VirtualItem> bpResponse;
					for (const auto& response_item : response) {
						FBP_VirtualItem b_response_item;
						FBP_VirtualItem::ConvertToUnrealModel(response_item, b_response_item);
						bpResponse.Add(b_response_item);
					}
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void GetVirtualItemsAsync2(
        int32 limit,
        const FString& startAfter,
        FVirtualItemsModuleGetVirtualItemsAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            int32_t cpp_limit;
            string cpp_startAfter;
			cpp_limit = limit;
			cpp_startAfter = string(TCHAR_TO_UTF8(*startAfter));
            RGN::Modules::VirtualItems::VirtualItemsModule::GetVirtualItemsAsync(
                cpp_limit,
                cpp_startAfter,
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    TArray<FBP_VirtualItem> bpResponse;
					for (const auto& response_item : response) {
						FBP_VirtualItem b_response_item;
						FBP_VirtualItem::ConvertToUnrealModel(response_item, b_response_item);
						bpResponse.Add(b_response_item);
					}
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void GetVirtualItemsByIdsAsync(
        const TArray<FString>& virtualItemsIds,
        FVirtualItemsModuleGetVirtualItemsByIdsAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            vector<string> cpp_virtualItemsIds;
			for (const auto& virtualItemsIds_item : virtualItemsIds) {
				string cpp_virtualItemsIds_item;
				cpp_virtualItemsIds_item = string(TCHAR_TO_UTF8(*virtualItemsIds_item));
				cpp_virtualItemsIds.push_back(cpp_virtualItemsIds_item);
			}
            RGN::Modules::VirtualItems::VirtualItemsModule::GetVirtualItemsByIdsAsync(
                cpp_virtualItemsIds,
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    TArray<FBP_VirtualItem> bpResponse;
					for (const auto& response_item : response) {
						FBP_VirtualItem b_response_item;
						FBP_VirtualItem::ConvertToUnrealModel(response_item, b_response_item);
						bpResponse.Add(b_response_item);
					}
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void GetByTagsAsync(
        const TArray<FString>& tags,
        const FString& appId,
        FVirtualItemsModuleGetByTagsAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            vector<string> cpp_tags;
            string cpp_appId;
			for (const auto& tags_item : tags) {
				string cpp_tags_item;
				cpp_tags_item = string(TCHAR_TO_UTF8(*tags_item));
				cpp_tags.push_back(cpp_tags_item);
			}
			cpp_appId = string(TCHAR_TO_UTF8(*appId));
            RGN::Modules::VirtualItems::VirtualItemsModule::GetByTagsAsync(
                cpp_tags,
                cpp_appId,
                [onSuccess](vector<RGN::Modules::VirtualItems::VirtualItem> response) {
                    TArray<FBP_VirtualItem> bpResponse;
					for (const auto& response_item : response) {
						FBP_VirtualItem b_response_item;
						FBP_VirtualItem::ConvertToUnrealModel(response_item, b_response_item);
						bpResponse.Add(b_response_item);
					}
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void GetTagsAsync(
        const FString& virtualItemId,
        FVirtualItemsModuleGetTagsAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_virtualItemId;
			cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            RGN::Modules::VirtualItems::VirtualItemsModule::GetTagsAsync(
                cpp_virtualItemId,
                [onSuccess](vector<string> response) {
                    TArray<FString> bpResponse;
					for (const auto& response_item : response) {
						FString b_response_item;
						b_response_item = FString(response_item.c_str());
						bpResponse.Add(b_response_item);
					}
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void SetTagsAsync(
        const FString& virtualItemId,
        const TArray<FString>& tags,
        const FString& appId,
        FVirtualItemsModuleSetTagsAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_virtualItemId;
            vector<string> cpp_tags;
            string cpp_appId;
			cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
			for (const auto& tags_item : tags) {
				string cpp_tags_item;
				cpp_tags_item = string(TCHAR_TO_UTF8(*tags_item));
				cpp_tags.push_back(cpp_tags_item);
			}
			cpp_appId = string(TCHAR_TO_UTF8(*appId));
            RGN::Modules::VirtualItems::VirtualItemsModule::SetTagsAsync(
                cpp_virtualItemId,
                cpp_tags,
                cpp_appId,
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void SetNameAsync(
        const FString& virtualItemId,
        const FString& name,
        FVirtualItemsModuleSetNameAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_virtualItemId;
            string cpp_name;
			cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
			cpp_name = string(TCHAR_TO_UTF8(*name));
            RGN::Modules::VirtualItems::VirtualItemsModule::SetNameAsync(
                cpp_virtualItemId,
                cpp_name,
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void SetDescriptionAsync(
        const FString& virtualItemId,
        const FString& description,
        FVirtualItemsModuleSetDescriptionAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_virtualItemId;
            string cpp_description;
			cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
			cpp_description = string(TCHAR_TO_UTF8(*description));
            RGN::Modules::VirtualItems::VirtualItemsModule::SetDescriptionAsync(
                cpp_virtualItemId,
                cpp_description,
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void GetPropertiesAsync(
        const FString& virtualItemId,
        FVirtualItemsModuleGetPropertiesAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_virtualItemId;
			cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
            RGN::Modules::VirtualItems::VirtualItemsModule::GetPropertiesAsync(
                cpp_virtualItemId,
                [onSuccess](string response) {
                    FString bpResponse;
					bpResponse = FString(response.c_str());
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void SetPropertiesAsync(
        const FString& virtualItemId,
        const FString& json,
        FVirtualItemsModuleSetPropertiesAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_virtualItemId;
            string cpp_json;
			cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
			cpp_json = string(TCHAR_TO_UTF8(*json));
            RGN::Modules::VirtualItems::VirtualItemsModule::SetPropertiesAsync(
                cpp_virtualItemId,
                cpp_json,
                [onSuccess](string response) {
                    FString bpResponse;
					bpResponse = FString(response.c_str());
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void UploadImageAsync(
        const FString& virtualItemId,
        const TArray<uint8>& thumbnailTextureBytes,
        const FBP_CancellationToken& cancellationToken,
        FVirtualItemsModuleUploadImageAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_virtualItemId;
            vector<uint8_t> cpp_thumbnailTextureBytes;
            CancellationToken cpp_cancellationToken;
			cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
			for (const auto& thumbnailTextureBytes_item : thumbnailTextureBytes) {
				uint8_t cpp_thumbnailTextureBytes_item;
				cpp_thumbnailTextureBytes_item = thumbnailTextureBytes_item;
				cpp_thumbnailTextureBytes.push_back(cpp_thumbnailTextureBytes_item);
			}
			FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::UploadImageAsync(
                cpp_virtualItemId,
                cpp_thumbnailTextureBytes,
                cpp_cancellationToken,
                [onSuccess](bool response) {
                    bool bpResponse;
					bpResponse = response;
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | VirtualItems")
    static void DownloadImageAsync(
        const FString& virtualItemId,
        const EBP_ImageSize& size,
        const FBP_CancellationToken& cancellationToken,
        FVirtualItemsModuleDownloadImageAsyncResponse onSuccess, FVirtualItemsModuleFailResponse onFail) {
            string cpp_virtualItemId;
            RGN::Model::ImageSize cpp_size;
            CancellationToken cpp_cancellationToken;
			cpp_virtualItemId = string(TCHAR_TO_UTF8(*virtualItemId));
			cpp_size = static_cast<RGN::Model::ImageSize>(size);
			FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::VirtualItems::VirtualItemsModule::DownloadImageAsync(
                cpp_virtualItemId,
                cpp_size,
                cpp_cancellationToken,
                [onSuccess](vector<uint8_t> response) {
                    TArray<uint8> bpResponse;
					for (const auto& response_item : response) {
						uint8 b_response_item;
						b_response_item = response_item;
						bpResponse.Add(b_response_item);
					}
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
};
