#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../CustomImpl/RGN/Modules/UserProfile/UserProfileModule.h"
#include "../../../../Utility/CancellationToken.h"
#include "../../Model/Request/BaseMigrationRequestData.h"
#include "UserData.h"
#include "GetUserProfileRequestData.h"
#include "SearchUsersRequestData.h"
#include "../../Model/Request/BaseRequestData.h"
#include "../Currency/Currency.h"
#include "GetUserIdByShortUIDRequestData.h"
#include "UpdateUserProfileRequestData.h"
#include "../../Model/ImageSize.h"
#include "UserCustomClaims.h"
#include "SetInvisibleStatusRequestData.h"
#include "GetUserStatusResponseData.h"
#include "GetUserStatusRequestData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace UserProfile {
    class UserProfileModule {
    public:
        /**
         * Returns user data for current authenticated user.
         * @param cancellationToken - A token to cancel the operation.
         * @return Basic user data
         */
        static void GetProfileAsync(
            const function<void(const RGN::Modules::UserProfile::UserData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::UserProfileModuleCustomImpl::GetProfileAsync(
                    success,
                    fail,
                    cancellationToken);
            };
        /**
         * Returns user data for provided user id. The base data contains some basic user info
         * In case you want to request more information (like user coins) please use the
         * !:GetFullUserProfileAsync<TFullProfileData>(string) method
         * @param userId - User Id to get the data
         * @param cancellationToken - A token to cancel the operation.
         * @return Basic user data
         */
        static void GetProfileAsync(
            const function<void(const RGN::Modules::UserProfile::UserData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::GetUserProfileRequestData requestData;
                requestData.userId = userId;
                RGNCore::CallAPI<RGN::Modules::UserProfile::GetUserProfileRequestData, RGN::Modules::UserProfile::UserData>(
                    "user-getProfile",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetFullUserProfileAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::UserProfileModuleCustomImpl::GetFullUserProfileAsync(
                    success,
                    fail,
                    cancellationToken);
            };
        static void GetFullUserProfileAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::UserProfileModuleCustomImpl::GetFullUserProfileAsync(
                    success,
                    fail,
                    userId,
                    cancellationToken);
            };
        /**
         * Searches for users by their nickname.
         * @param nicknameQuery - The query string to search for in user nicknames.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing a List of UserData objects representing the matching users.
         */
        static void SearchUsersAsync(
            const function<void(const vector<RGN::Modules::UserProfile::UserData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& nicknameQuery,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::SearchUsersRequestData requestData;
                requestData.nicknameQuery = nicknameQuery;
                RGNCore::CallAPI<RGN::Modules::UserProfile::SearchUsersRequestData, vector<RGN::Modules::UserProfile::UserData>>(
                    "user-searchUsers",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Gets a list of the currencies owned by the current user.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing a List of Currency objects representing the user's currencies.
         */
        static void GetUserCurrenciesAsync(
            const function<void(const vector<RGN::Modules::Currency::Currency>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Model::Request::BaseRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseRequestData, vector<RGN::Modules::Currency::Currency>>(
                    "user-getUserCurrenciesV2",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Gets the user ID associated with a short UID.
         * @param shortUID - The short UID to get the associated user ID for.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing the user ID associated with the short UID.
         */
        static void GetUserIdByShortUIDAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& shortUID,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::GetUserIdByShortUIDRequestData requestData;
                requestData.shortUID = shortUID;
                RGNCore::CallAPI<RGN::Modules::UserProfile::GetUserIdByShortUIDRequestData>(
                    "user-getUserIdByShortUID",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Sets the display name of the user.
         * @param displayName - The new display name of the user.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing the new display name of the user.
         */
        static void SetDisplayNameAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& displayName,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["displayName"] = displayName;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "user-updateDisplayName",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["displayName"].template get<string>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Sets the bio of the user.
         * @param bio - The new bio of the user.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing the new bio of the user.
         */
        static void SetBioAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& bio,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["bio"] = bio;
                requestData["version"] = RGN::Model::Request::BaseMigrationRequestData().version;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>(
                    "user-updateBio",
                    requestData,
                    [success] (const nlohmann::json& result) {
                        success(result["bio"].template get<string>());
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Sets the display name and bio of the user.
         * @param displayName - The new display name of the user.
         * @param bio - The new bio of the user.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing the new display name of the user.
         */
        static void SetDisplayNameAndBioAsync(
            const function<void(const string& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& displayName,
            const string& bio = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::UpdateUserProfileRequestData requestData;
                requestData.displayName = displayName;
                requestData.bio = bio;
                RGNCore::CallAPI<RGN::Modules::UserProfile::UpdateUserProfileRequestData>(
                    "user-updateProfile",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Uploads a user's avatar image to the RGNCore backend.
         * @param bytes - The byte array of the avatar image to upload.
         * @param cancellationToken - The cancellation token.
         * @return A boolean indicating whether the upload was successful.
         */
        static void UploadAvatarImageAsync(
            const function<void(const bool result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<uint8_t>& bytes,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::UserProfileModuleCustomImpl::UploadAvatarImageAsync(
                    success,
                    fail,
                    bytes,
                    cancellationToken);
            };
        /**
         * Downloads the avatar image of a user as a byte array from Firebase storage.
         * @param userId - The ID of the user whose avatar image to download.
         * @param size - The size type of avatar image to download.
         * @param cancellationToken - A cancellation token that can be used to cancel the download operation.
         * @return A byte array containing the avatar image, or null if the download fails.
         */
        static void DownloadAvatarImageAsync(
            const function<void(const vector<uint8_t>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId,
            const RGN::Model::ImageSize& size,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::UserProfileModuleCustomImpl::DownloadAvatarImageAsync(
                    success,
                    fail,
                    userId,
                    size,
                    cancellationToken);
            };
        /**
         * Changes the admin status and access level of a user by their email.
         * @param email - The email of the user to modify.
         * @param isAdmin - True if the user should be made an admin, false otherwise.
         * @param accessLevel - The new access level for the user.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing a Dictionary of key-value pairs representing the updated user data.
         */
        static void ChangeAdminStatusByEmailAsync(
            const function<void(const RGN::Modules::UserProfile::UserCustomClaims& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& email,
            const bool isAdmin,
            const int32_t accessLevel,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::UserProfileModuleCustomImpl::ChangeAdminStatusByEmailAsync(
                    success,
                    fail,
                    email,
                    isAdmin,
                    accessLevel,
                    cancellationToken);
            };
        /**
         * Changes the admin status and access level of a user by their user ID.
         * @param userId - The user ID of the user to modify.
         * @param isAdmin - True if the user should be made an admin, false otherwise.
         * @param accessLevel - The new access level for the user.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing a Dictionary of key-value pairs representing the updated user data.
         */
        static void ChangeAdminStatusByUserIdAsync(
            const function<void(const RGN::Modules::UserProfile::UserCustomClaims& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId,
            const bool isAdmin,
            const int32_t accessLevel,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::UserProfileModuleCustomImpl::ChangeAdminStatusByUserIdAsync(
                    success,
                    fail,
                    userId,
                    isAdmin,
                    accessLevel,
                    cancellationToken);
            };
        /**
         * Gets the custom claims for a user by their user ID.
         * @param userId - The user ID of the user to retrieve custom claims for.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing a Dictionary of key-value pairs representing the user's custom claims.
         */
        static void GetUserCustomClaimsByUserIdAsync(
            const function<void(const RGN::Modules::UserProfile::UserCustomClaims& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::UserProfileModuleCustomImpl::GetUserCustomClaimsByUserIdAsync(
                    success,
                    fail,
                    userId,
                    cancellationToken);
            };
        /**
         * Gets the custom claims for a user by their email.
         * @param email - The email of the user to retrieve custom claims for.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing a Dictionary of key-value pairs representing the user's custom claims.
         */
        static void GetUserCustomClaimsByEmailAsync(
            const function<void(const RGN::Modules::UserProfile::UserCustomClaims& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& email,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::UserProfileModuleCustomImpl::GetUserCustomClaimsByEmailAsync(
                    success,
                    fail,
                    email,
                    cancellationToken);
            };
        /**
         * Sets the invisible status for the current user.
         * @param invisibleStatus - True if the user should be invisible, false otherwise.
         */
        static void SetInvisibleStatusAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const bool invisibleStatus) {
                RGN::Modules::UserProfile::SetInvisibleStatusRequestData requestData;
                requestData.invisibleStatus = invisibleStatus;
                RGNCore::CallAPI<RGN::Modules::UserProfile::SetInvisibleStatusRequestData>(
                    "userStatuses-setInvisibleStatus",
                    requestData,
                    success,
                    fail,
                    false);
            };
        static void PingAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail) {
                RGN::Model::Request::BaseRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseRequestData>(
                    "userStatuses-ping",
                    requestData,
                    success,
                    fail,
                    false);
            };
        static void SuspendAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail) {
                RGN::Modules::UserProfile::UserProfileModuleCustomImpl::SuspendAsync(
                    success,
                    fail);
            };
        /**
         * Retrieves the status of a user with the specified user ID.
         * @param userId - The user ID of the user whose status to retrieve.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task containing the status of the user as a GetUserStatusResponseData object.
         */
        static void GetUserStateAsync(
            const function<void(const RGN::Modules::UserProfile::GetUserStatusResponseData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& userId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::GetUserStatusRequestData requestData;
                requestData.userId = userId;
                RGNCore::CallAPI<RGN::Modules::UserProfile::GetUserStatusRequestData, RGN::Modules::UserProfile::GetUserStatusResponseData>(
                    "userStatuses-getUserState",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Deletes the user's account.
         * @param cancellationToken - A token to cancel the operation.
         */
        static void DeleteUser(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Model::Request::BaseRequestData requestData;
                RGNCore::CallAPI<RGN::Model::Request::BaseRequestData>(
                    "user-deleteUser",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
    };
}}}