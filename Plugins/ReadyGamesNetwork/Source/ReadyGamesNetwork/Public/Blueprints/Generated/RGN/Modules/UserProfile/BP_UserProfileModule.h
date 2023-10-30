#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Core/BP_CancellationToken.h"
#include "../../../../../Core/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserProfileModule.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserData.h"
#include "BP_UserData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserProfileRequestData.h"
#include "BP_GetUserProfileRequestData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/SearchUsersRequestData.h"
#include "BP_SearchUsersRequestData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/BP_Currency.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/BP_BaseRequestData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserIdByShortUIDRequestData.h"
#include "BP_GetUserIdByShortUIDRequestData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UpdateUserProfileRequestData.h"
#include "BP_UpdateUserProfileRequestData.h"
#include "../../../../../Generated/RGN/Model/ImageSize.h"
#include "../../Model/BP_ImageSize.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserCustomClaims.h"
#include "BP_UserCustomClaims.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/SetInvisibleStatusRequestData.h"
#include "BP_SetInvisibleStatusRequestData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserStatusResponseData.h"
#include "BP_GetUserStatusResponseData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserStatusRequestData.h"
#include "BP_GetUserStatusRequestData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_UserProfileModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FUserProfileModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleGetProfileAsyncResponse, const FBP_UserData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleGetFullUserProfileAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleSearchUsersAsyncResponse, const TArray<FBP_UserData>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleGetUserCurrenciesAsyncResponse, const TArray<FBP_Currency>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleGetUserIdByShortUIDAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleSetDisplayNameAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleSetBioAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleSetDisplayNameAndBioAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleUploadAvatarImageAsyncResponse, bool, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleDownloadAvatarImageAsyncResponse, const TArray<uint8>&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleChangeAdminStatusByEmailAsyncResponse, const FBP_UserCustomClaims&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleChangeAdminStatusByUserIdAsyncResponse, const FBP_UserCustomClaims&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleGetUserCustomClaimsByUserIdAsyncResponse, const FBP_UserCustomClaims&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleGetUserCustomClaimsByEmailAsyncResponse, const FBP_UserCustomClaims&, response);
DECLARE_DYNAMIC_DELEGATE(FUserProfileModuleSetInvisibleStatusAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FUserProfileModulePingAsyncResponse);
DECLARE_DYNAMIC_DELEGATE(FUserProfileModuleSuspendAsyncResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserProfileModuleGetUserStateAsyncResponse, const FBP_GetUserStatusResponseData&, response);

UCLASS()
class READYGAMESNETWORK_API UBP_UserProfileModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void GetProfileAsync(
        FUserProfileModuleGetProfileAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            RGN::Modules::UserProfile::UserProfileModule::GetProfileAsync(
                [onSuccess](RGN::Modules::UserProfile::UserData response) {
                    FBP_UserData bpResponse;
					FBP_UserData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    /**
     * Returns user data for provided user id. The base data contains some basic user info
     * In case you want to request more information (like user coins) please use the
     * M:RGN.Modules.UserProfile.UserProfileModule.GetFullUserProfileAsync``1(System.String) method
     * @param userId - User Id to get the data
     * @return Basic user data
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void GetProfileAsync_UserId(
        const FString& userId,
        FUserProfileModuleGetProfileAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_userId;
			cpp_userId = string(TCHAR_TO_UTF8(*userId));
            RGN::Modules::UserProfile::UserProfileModule::GetProfileAsync(
                cpp_userId,
                [onSuccess](RGN::Modules::UserProfile::UserData response) {
                    FBP_UserData bpResponse;
					FBP_UserData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void GetFullUserProfileAsync(
        FUserProfileModuleGetFullUserProfileAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            RGN::Modules::UserProfile::UserProfileModule::GetFullUserProfileAsync(
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
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void GetFullUserProfileAsync_UserId(
        const FString& userId,
        FUserProfileModuleGetFullUserProfileAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_userId;
			cpp_userId = string(TCHAR_TO_UTF8(*userId));
            RGN::Modules::UserProfile::UserProfileModule::GetFullUserProfileAsync(
                cpp_userId,
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
    /**
     * Searches for users by their nickname.
     * @param nicknameQuery - The query string to search for in user nicknames.
     * @return A Task containing a List of UserData objects representing the matching users.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void SearchUsersAsync(
        const FString& nicknameQuery,
        FUserProfileModuleSearchUsersAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_nicknameQuery;
			cpp_nicknameQuery = string(TCHAR_TO_UTF8(*nicknameQuery));
            RGN::Modules::UserProfile::UserProfileModule::SearchUsersAsync(
                cpp_nicknameQuery,
                [onSuccess](vector<RGN::Modules::UserProfile::UserData> response) {
                    TArray<FBP_UserData> bpResponse;
					for (const auto& response_item : response) {
						FBP_UserData b_response_item;
						FBP_UserData::ConvertToUnrealModel(response_item, b_response_item);
						bpResponse.Add(b_response_item);
					}
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void GetUserCurrenciesAsync(
        FUserProfileModuleGetUserCurrenciesAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            RGN::Modules::UserProfile::UserProfileModule::GetUserCurrenciesAsync(
                [onSuccess](vector<RGN::Modules::Currency::Currency> response) {
                    TArray<FBP_Currency> bpResponse;
					for (const auto& response_item : response) {
						FBP_Currency b_response_item;
						FBP_Currency::ConvertToUnrealModel(response_item, b_response_item);
						bpResponse.Add(b_response_item);
					}
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    /**
     * Gets the user ID associated with a short UID.
     * @param shortUID - The short UID to get the associated user ID for.
     * @return A Task containing the user ID associated with the short UID.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void GetUserIdByShortUIDAsync(
        const FString& shortUID,
        FUserProfileModuleGetUserIdByShortUIDAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_shortUID;
			cpp_shortUID = string(TCHAR_TO_UTF8(*shortUID));
            RGN::Modules::UserProfile::UserProfileModule::GetUserIdByShortUIDAsync(
                cpp_shortUID,
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
    /**
     * Sets the display name of the user.
     * @param displayName - The new display name of the user.
     * @return A Task containing the new display name of the user.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void SetDisplayNameAsync(
        const FString& displayName,
        FUserProfileModuleSetDisplayNameAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_displayName;
			cpp_displayName = string(TCHAR_TO_UTF8(*displayName));
            RGN::Modules::UserProfile::UserProfileModule::SetDisplayNameAsync(
                cpp_displayName,
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
    /**
     * Sets the bio of the user.
     * @param bio - The new bio of the user.
     * @return A Task containing the new bio of the user.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void SetBioAsync(
        const FString& bio,
        FUserProfileModuleSetBioAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_bio;
			cpp_bio = string(TCHAR_TO_UTF8(*bio));
            RGN::Modules::UserProfile::UserProfileModule::SetBioAsync(
                cpp_bio,
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
    /**
     * Sets the display name and bio of the user.
     * @param displayName - The new display name of the user.
     * @param bio - The new bio of the user.
     * @return A Task containing the new display name of the user.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void SetDisplayNameAndBioAsync(
        const FString& displayName,
        const FString& bio,
        FUserProfileModuleSetDisplayNameAndBioAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_displayName;
            string cpp_bio;
			cpp_displayName = string(TCHAR_TO_UTF8(*displayName));
			cpp_bio = string(TCHAR_TO_UTF8(*bio));
            RGN::Modules::UserProfile::UserProfileModule::SetDisplayNameAndBioAsync(
                cpp_displayName,
                cpp_bio,
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
    /**
     * Uploads a user's avatar image to the RGNCore backend.
     * @param bytes - The byte array of the avatar image to upload.
     * @param cancellationToken - The cancellation token.
     * @return A boolean indicating whether the upload was successful.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void UploadAvatarImageAsync(
        const TArray<uint8>& bytes,
        const FBP_CancellationToken& cancellationToken,
        FUserProfileModuleUploadAvatarImageAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            vector<uint8_t> cpp_bytes;
            CancellationToken cpp_cancellationToken;
			for (const auto& bytes_item : bytes) {
				uint8_t cpp_bytes_item;
				cpp_bytes_item = bytes_item;
				cpp_bytes.push_back(cpp_bytes_item);
			}
			FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::UserProfile::UserProfileModule::UploadAvatarImageAsync(
                cpp_bytes,
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
    /**
     * Downloads the avatar image of a user as a byte array from Firebase storage.
     * @param userId - The ID of the user whose avatar image to download.
     * @param size - The size type of avatar image to download.
     * @param cancellationToken - A cancellation token that can be used to cancel the download operation.
     * @return A byte array containing the avatar image, or null if the download fails.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void DownloadAvatarImageAsync(
        const FString& userId,
        const EBP_ImageSize& size,
        const FBP_CancellationToken& cancellationToken,
        FUserProfileModuleDownloadAvatarImageAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_userId;
            RGN::Model::ImageSize cpp_size;
            CancellationToken cpp_cancellationToken;
			cpp_userId = string(TCHAR_TO_UTF8(*userId));
			cpp_size = static_cast<RGN::Model::ImageSize>(size);
			FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::UserProfile::UserProfileModule::DownloadAvatarImageAsync(
                cpp_userId,
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
    /**
     * Changes the admin status and access level of a user by their email.
     * @param email - The email of the user to modify.
     * @param isAdmin - True if the user should be made an admin, false otherwise.
     * @param accessLevel - The new access level for the user.
     * @return A Task containing a Dictionary of key-value pairs representing the updated user data.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void ChangeAdminStatusByEmailAsync(
        const FString& email,
        bool isAdmin,
        int32 accessLevel,
        FUserProfileModuleChangeAdminStatusByEmailAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_email;
            bool cpp_isAdmin;
            int32_t cpp_accessLevel;
			cpp_email = string(TCHAR_TO_UTF8(*email));
			cpp_isAdmin = isAdmin;
			cpp_accessLevel = accessLevel;
            RGN::Modules::UserProfile::UserProfileModule::ChangeAdminStatusByEmailAsync(
                cpp_email,
                cpp_isAdmin,
                cpp_accessLevel,
                [onSuccess](RGN::Modules::UserProfile::UserCustomClaims response) {
                    FBP_UserCustomClaims bpResponse;
					FBP_UserCustomClaims::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    /**
     * Changes the admin status and access level of a user by their user ID.
     * @param userId - The user ID of the user to modify.
     * @param isAdmin - True if the user should be made an admin, false otherwise.
     * @param accessLevel - The new access level for the user.
     * @return A Task containing a Dictionary of key-value pairs representing the updated user data.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void ChangeAdminStatusByUserIdAsync(
        const FString& userId,
        bool isAdmin,
        int32 accessLevel,
        FUserProfileModuleChangeAdminStatusByUserIdAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_userId;
            bool cpp_isAdmin;
            int32_t cpp_accessLevel;
			cpp_userId = string(TCHAR_TO_UTF8(*userId));
			cpp_isAdmin = isAdmin;
			cpp_accessLevel = accessLevel;
            RGN::Modules::UserProfile::UserProfileModule::ChangeAdminStatusByUserIdAsync(
                cpp_userId,
                cpp_isAdmin,
                cpp_accessLevel,
                [onSuccess](RGN::Modules::UserProfile::UserCustomClaims response) {
                    FBP_UserCustomClaims bpResponse;
					FBP_UserCustomClaims::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    /**
     * Gets the custom claims for a user by their user ID.
     * @param userId - The user ID of the user to retrieve custom claims for.
     * @return A Task containing a Dictionary of key-value pairs representing the user's custom claims.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void GetUserCustomClaimsByUserIdAsync(
        const FString& userId,
        FUserProfileModuleGetUserCustomClaimsByUserIdAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_userId;
			cpp_userId = string(TCHAR_TO_UTF8(*userId));
            RGN::Modules::UserProfile::UserProfileModule::GetUserCustomClaimsByUserIdAsync(
                cpp_userId,
                [onSuccess](RGN::Modules::UserProfile::UserCustomClaims response) {
                    FBP_UserCustomClaims bpResponse;
					FBP_UserCustomClaims::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    /**
     * Gets the custom claims for a user by their email.
     * @param email - The email of the user to retrieve custom claims for.
     * @return A Task containing a Dictionary of key-value pairs representing the user's custom claims.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void GetUserCustomClaimsByEmailAsync(
        const FString& email,
        FUserProfileModuleGetUserCustomClaimsByEmailAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_email;
			cpp_email = string(TCHAR_TO_UTF8(*email));
            RGN::Modules::UserProfile::UserProfileModule::GetUserCustomClaimsByEmailAsync(
                cpp_email,
                [onSuccess](RGN::Modules::UserProfile::UserCustomClaims response) {
                    FBP_UserCustomClaims bpResponse;
					FBP_UserCustomClaims::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    /**
     * Sets the invisible status for the current user.
     * @param invisibleStatus - True if the user should be invisible, false otherwise.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void SetInvisibleStatusAsync(
        bool invisibleStatus,
        FUserProfileModuleSetInvisibleStatusAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            bool cpp_invisibleStatus;
			cpp_invisibleStatus = invisibleStatus;
            RGN::Modules::UserProfile::UserProfileModule::SetInvisibleStatusAsync(
                cpp_invisibleStatus,
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void PingAsync(
        FUserProfileModulePingAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            RGN::Modules::UserProfile::UserProfileModule::PingAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void SuspendAsync(
        FUserProfileModuleSuspendAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            RGN::Modules::UserProfile::UserProfileModule::SuspendAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
    /**
     * Retrieves the status of a user with the specified user ID.
     * @param userId - The user ID of the user whose status to retrieve.
     * @return A Task containing the status of the user as a GetUserStatusResponseData object.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | UserProfile")
    static void GetUserStateAsync(
        const FString& userId,
        FUserProfileModuleGetUserStateAsyncResponse onSuccess, FUserProfileModuleFailResponse onFail) {
            string cpp_userId;
			cpp_userId = string(TCHAR_TO_UTF8(*userId));
            RGN::Modules::UserProfile::UserProfileModule::GetUserStateAsync(
                cpp_userId,
                [onSuccess](RGN::Modules::UserProfile::GetUserStatusResponseData response) {
                    FBP_GetUserStatusResponseData bpResponse;
					FBP_GetUserStatusResponseData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                }
            );
    }
};
