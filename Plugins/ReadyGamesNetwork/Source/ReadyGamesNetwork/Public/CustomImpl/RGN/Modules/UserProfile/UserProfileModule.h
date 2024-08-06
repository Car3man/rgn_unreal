#pragma once

#include "../../../../json.hpp"
#include "../../../../base64.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Http/Http.h"
#include "../../../../Generated/RGN/Modules/UserProfile/GetUserProfileRequestData.h"
#include "../../../../Generated/RGN/Modules/UserProfile/UserData.h"
#include "../../../../Generated/RGN/Modules/UserProfile/UserProfilePicture.h"
#include "../../../../Generated/RGN/Model/ImageSize.h"
#include "../../../../Generated/RGN/Modules/UserProfile/UserCustomClaims.h"
#include <string>

namespace RGN { namespace Modules { namespace UserProfile {
	class UserProfileModuleCustomImpl {
	public:
        static void GetProfileAsync(
            const function<void(RGN::Modules::UserProfile::UserData result)>& success,
            const function<void(int httpCode, string error)>& fail,
            CancellationToken cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::GetUserProfileRequestData requestData;
                requestData.userId = RGNCore::GetUserId();
                RGNCore::CallAPI<RGN::Modules::UserProfile::GetUserProfileRequestData, RGN::Modules::UserProfile::UserData>(
                    "user-getProfile",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken
                );
            };
        static void GetFullUserProfileAsync(
            const function<void(string result)>& success,
            const function<void(int httpCode, string error)>& fail,
            CancellationToken cancellationToken = CancellationToken()) {
                GetFullUserProfileAsync(success, fail, RGNCore::GetUserId(), cancellationToken);
            };
        static void GetFullUserProfileAsync(
            const function<void(string result)>& success,
            const function<void(int httpCode, string error)>& fail,
            string userId,
            CancellationToken cancellationToken = CancellationToken()) {
                RGN::Modules::UserProfile::GetUserProfileRequestData requestData;
                requestData.userId = userId;
                RGNCore::CallAPI<RGN::Modules::UserProfile::GetUserProfileRequestData, string>(
                    "user-getFullProfile",
                    requestData,
                    [success](string result) {
                        success(result);
                    },
                    fail,
                    false, cancellationToken
                );
            };
        static void UploadAvatarImageAsync(
            const function<void(bool result)>& success,
            const function<void(int httpCode, string error)>& fail,
            vector<uint8_t> bytes,
            CancellationToken cancellationToken) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["base64String"] = RGN::Base64::base64_encode(&bytes[0], bytes.size());
                RGNCore::CallAPI<nlohmann::json>(
                    "user-uploadProfilePicture",
                    requestData,
                    [success]() {
                        success(true);
                    },
                    fail,
                    false,
                    cancellationToken
                );
            };
        static void DownloadAvatarImageAsync(
            const std::function<void(std::vector<uint8_t> result)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::string userId,
            RGN::Model::ImageSize size,
            CancellationToken cancellationToken) {
                GetProfileAsync([success, fail, size]
                (RGN::Modules::UserProfile::UserData userData) {
                    RGN::Modules::UserProfile::UserProfilePicture userProfilePicture = userData.profilePicture;

                    std::string pictureUrl = "";
                    switch (size) {
                    case RGN::Model::ImageSize::Large:
                        pictureUrl = userProfilePicture.source;
                        break;
                    case RGN::Model::ImageSize::Medium:
                        pictureUrl = userProfilePicture.source;
                        break;
                    case RGN::Model::ImageSize::Small:
                        pictureUrl = userProfilePicture.source;
                        break;
                    default:
                        pictureUrl = userProfilePicture.source;
                        break;
                    }

                    HttpHeaders headers;
                    headers.add("Content-type", "application/json");
                    Http::Request(pictureUrl, HttpMethod::GET, headers, "", [success, fail](HttpResponse httpResponse) {
                        int httpResponseCode = httpResponse.getResponseCode();
                        std::string httpResponseBody = httpResponse.getResponseBody();

                        if (httpResponseCode != 200) {
                            fail(httpResponseCode, httpResponseBody);
                            return;
                        }

                        std::vector<uint8_t> byteVector;
                        for (char strChar : httpResponseBody) {
                            byteVector.push_back(static_cast<uint8_t>(strChar));
                        }
                        success(byteVector);
                    });
                }, fail, cancellationToken);
            };
        static void ChangeAdminStatusByEmailAsync(
            const function<void(RGN::Modules::UserProfile::UserCustomClaims result)>& success,
            const function<void(int httpCode, string error)>& fail,
            string email,
            bool isAdmin,
            int32_t accessLevel,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["email"] = email;
                bodyJson["isAdmin"] = isAdmin;
                bodyJson["accessLevel"] = accessLevel;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>
                ("user-changeAdminStatusByEmail", bodyJson,
                    [success](nlohmann::json response) {
                        RGN::Modules::UserProfile::UserCustomClaims userCustomClaims;
                        userCustomClaims.claims = response.template get<std::unordered_map<std::string, std::string>>();
                        success(userCustomClaims);
                    },
                    fail, false, cancellationToken
                );
            };
        static void ChangeAdminStatusByUserIdAsync(
            const function<void(RGN::Modules::UserProfile::UserCustomClaims result)>& success,
            const function<void(int httpCode, string error)>& fail,
            string userId,
            bool isAdmin,
            int32_t accessLevel,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["userId"] = userId;
                bodyJson["isAdmin"] = isAdmin;
                bodyJson["accessLevel"] = accessLevel;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>
                ("user-changeAdminStatusByUserId", bodyJson,
                    [success](nlohmann::json response) {
                        RGN::Modules::UserProfile::UserCustomClaims userCustomClaims;
                        userCustomClaims.claims = response.template get<std::unordered_map<std::string, std::string>>();
                        success(userCustomClaims);
                    },
                    fail, false, cancellationToken
                );
            };
        static void GetUserCustomClaimsByUserIdAsync(
            const function<void(RGN::Modules::UserProfile::UserCustomClaims result)>& success,
            const function<void(int httpCode, string error)>& fail,
            string userId,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["userId"] = userId;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>
                ("user-getUserCustomClaimsByUserId", bodyJson,
                    [success](nlohmann::json response) {
                        RGN::Modules::UserProfile::UserCustomClaims userCustomClaims;
                        userCustomClaims.claims = response.template get<std::unordered_map<std::string, std::string>>();
                        success(userCustomClaims);
                    },
                    fail, false, cancellationToken
                );
            };
        static void GetUserCustomClaimsByEmailAsync(
            const function<void(RGN::Modules::UserProfile::UserCustomClaims result)>& success,
            const function<void(int httpCode, string error)>& fail,
            string email,
            CancellationToken cancellationToken = CancellationToken()) {
                nlohmann::json bodyJson;
                bodyJson["email"] = email;
                RGNCore::CallAPI<nlohmann::json, nlohmann::json>
                ("user-getUserCustomClaimsByEmail", bodyJson,
                    [success](nlohmann::json response) {
                        RGN::Modules::UserProfile::UserCustomClaims userCustomClaims;
                        userCustomClaims.claims = response.template get<std::unordered_map<std::string, std::string>>();
                        success(userCustomClaims);
                    },
                    fail, false, cancellationToken
                );
            };
        static void SuspendAsync(
            const function<void(void)>& success,
            const function<void(int httpCode, string error)>& fail) {
                RGNCore::CallAPI("userStatuses-suspend", success, fail, false);
            };
	};
}}}
