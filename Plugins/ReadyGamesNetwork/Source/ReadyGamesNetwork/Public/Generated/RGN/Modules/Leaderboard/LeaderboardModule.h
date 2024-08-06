#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../CustomImpl/RGN/Modules/Leaderboard/LeaderboardModule.h"
#include "../../../../Utility/CancellationToken.h"
#include "LeaderboardData.h"
#include "GetLeaderboardsResponse.h"
#include "GetLeaderboardIdsResponseData.h"
#include "IsLeaderboardAvailableResponseData.h"
#include "IsInPromoPeriodResponseData.h"
#include "IsInGracePeriodResponseData.h"
#include "SetScoreResponseData.h"
#include "LeaderboardEntry.h"
#include "GetLeaderboardEntriesResponseData.h"
#include "GetLeaderboardResetsResponseData.h"
#include "LeaderboardReset.h"
#include "GetLeaderboardResetResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;

namespace RGN { namespace Modules { namespace Leaderboard {
    class LeaderboardModule {
    public:
        /**
         * Asynchronous method that retrieves leaderboard data.
         * Resulting Data contains leaderboard description fields like id, name, type, etc.
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetLeaderboardByIdAsync(
            const function<void(const RGN::Modules::Leaderboard::LeaderboardData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& id,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["id"] = id;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::LeaderboardData>(
                    "leaderboardV2-getById",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronous method that retrieves leaderboard data.
         * Resulting Data contains leaderboard description fields like id, name, type, etc.
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetLeaderboardByRequestNameAsync(
            const function<void(const RGN::Modules::Leaderboard::LeaderboardData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& requestName,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["requestName"] = requestName;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::LeaderboardData>(
                    "leaderboardV2-getByRequestName",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetLeaderboardByRequestNamesAsync(
            const function<void(const vector<RGN::Modules::Leaderboard::LeaderboardData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& requestNames,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["requestNames"] = requestNames;
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                requestData["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::GetLeaderboardsResponse>(
                    "leaderboardV2-getByRequestNames",
                    requestData,
                    [success] (const RGN::Modules::Leaderboard::GetLeaderboardsResponse& result) {
                        success(result.leaderboards);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetLeaderboardByAppIdsAsync(
            const function<void(const vector<RGN::Modules::Leaderboard::LeaderboardData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& appIds,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["appIds"] = appIds;
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                requestData["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::GetLeaderboardsResponse>(
                    "leaderboardV2-getByAppIds",
                    requestData,
                    [success] (const RGN::Modules::Leaderboard::GetLeaderboardsResponse& result) {
                        success(result.leaderboards);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetLeaderboardByTagsAsync(
            const function<void(const vector<RGN::Modules::Leaderboard::LeaderboardData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& tags,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["tags"] = tags;
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                requestData["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::GetLeaderboardsResponse>(
                    "leaderboardV2-getByTags",
                    requestData,
                    [success] (const RGN::Modules::Leaderboard::GetLeaderboardsResponse& result) {
                        success(result.leaderboards);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        static void GetLeaderboardByIdsAsync(
            const function<void(const vector<RGN::Modules::Leaderboard::LeaderboardData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const vector<string>& ids,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ids"] = ids;
                requestData["limit"] = limit;
                requestData["startAfter"] = startAfter;
                requestData["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::GetLeaderboardsResponse>(
                    "leaderboardV2-getByIds",
                    requestData,
                    [success] (const RGN::Modules::Leaderboard::GetLeaderboardsResponse& result) {
                        success(result.leaderboards);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves a list of leaderboards for the current application from the Ready Games Network (RGN).
         * @param limit - An integer indicating the maximum number of leaderboards to retrieve.
         * @param startAfter - An optional parameter representing a leaderboard 'updatedAt' field after which start the retrieval
         * @param ignoreTimestamp - An optional parameter that indicates whether to ignore the timestamp in the leaderboard
         * retrieval process. The default is false.
         * @param cancellationToken - A token to cancel the operation.
         * @return A Task representing the asynchronous operation. The Result property of the Task returns a list
         * of T:RGN.Modules.Leaderboard.LeaderboardData objects representing the leaderboards that match the current application identifier,
         * limit and other optional parameters.
         * @throw: Thrown when the provided limit value is zero.
         */
        static void GetLeaderboardForCurrentAppAsync(
            const function<void(const vector<RGN::Modules::Leaderboard::LeaderboardData>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const int32_t limit,
            const int64_t startAfter = 0,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Leaderboard::LeaderboardModuleCustomImpl::GetLeaderboardForCurrentAppAsync(
                    success,
                    fail,
                    limit,
                    startAfter,
                    ignoreTimestamp,
                    cancellationToken);
            };
        /**
         * Method to retrieve leaderboard ids defined for current project
         * @param ignoreTimestamp - An optional parameter that indicates whether to ignore the timestamp in the leaderboard
         * retrieval process. The default is false.
         * @param cancellationToken - A token to cancel the operation.
         */
        static void GetLeaderboardIdsAsync(
            const function<void(const vector<string>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const bool ignoreTimestamp = false,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["ignoreTimestamp"] = ignoreTimestamp;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::GetLeaderboardIdsResponseData>(
                    "leaderboardV2-getIds",
                    requestData,
                    [success] (const RGN::Modules::Leaderboard::GetLeaderboardIdsResponseData& result) {
                        success(result.ids);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Method to retrieve available status of leaderboard
         * @param leaderboardId - The ID of the leaderboard which status will be checked.
         * @param cancellationToken - A token to cancel the operation.
         */
        static void IsLeaderboardAvailableAsync(
            const function<void(const RGN::Modules::Leaderboard::IsLeaderboardAvailableResponseData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["leaderboardId"] = leaderboardId;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::IsLeaderboardAvailableResponseData>(
                    "leaderboardV2-isAvailable",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Method to retrieve available status of leaderboard
         * @param leaderboardId - The ID of the leaderboard which status will be checked.
         * @param cancellationToken - A token to cancel the operation.
         */
        static void IsInPromoPeriodAsync(
            const function<void(const RGN::Modules::Leaderboard::IsInPromoPeriodResponseData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["leaderboardId"] = leaderboardId;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::IsInPromoPeriodResponseData>(
                    "leaderboardV2-isInPromoPeriod",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Method to retrieve available status of leaderboard
         * @param leaderboardId - The ID of the leaderboard which status will be checked.
         * @param cancellationToken - A token to cancel the operation.
         */
        static void IsInGracePeriodAsync(
            const function<void(const RGN::Modules::Leaderboard::IsInGracePeriodResponseData& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["leaderboardId"] = leaderboardId;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::IsInGracePeriodResponseData>(
                    "leaderboardV2-isInGracePeriod",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously sets the player's score on the specified leaderboard.
         * @param leaderboardId - The ID of the leaderboard where the score will be set.
         * @param score - The score to be set on the leaderboard.
         * @param extraData - (Optional) Extra data associated with the score. Defaults to an empty string if not provided.
         * @param cancellationToken - A token to cancel the operation.
         * @return A task that represents the asynchronous operation. The task result contains the player's place after setting the score.
         */
        static void SetScoreAsync(
            const function<void(const int32_t result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const int32_t score,
            const string& extraData = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["leaderboardId"] = leaderboardId;
                requestData["score"] = score;
                requestData["extraData"] = extraData;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::SetScoreResponseData>(
                    "leaderboardV2-setScore",
                    requestData,
                    [success] (const RGN::Modules::Leaderboard::SetScoreResponseData& result) {
                        success(result.place);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously adds the player's score on the specified leaderboard.
         * @param leaderboardId - The ID of the leaderboard where the score will be added.
         * @param score - The score to be added on the leaderboard.
         * @param extraData - (Optional) Extra data associated with the score. Defaults to an empty string if not provided.
         * @param cancellationToken - A token to cancel the operation.
         * @return A task that represents the asynchronous operation. The task result contains the player's place after setting the score.
         */
        static void AddScoreAsync(
            const function<void(const int32_t result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const int32_t score,
            const string& extraData = "",
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["leaderboardId"] = leaderboardId;
                requestData["score"] = score;
                requestData["extraData"] = extraData;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::SetScoreResponseData>(
                    "leaderboardV2-addScore",
                    requestData,
                    [success] (const RGN::Modules::Leaderboard::SetScoreResponseData& result) {
                        success(result.place);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves the player's entry on the specified leaderboard.
         * @param leaderboardId - The ID of the leaderboard from which the entry will be retrieved.
         * @param cancellationToken - A token to cancel the operation.
         * @return A task that represents the asynchronous operation. The task result contains the player's entry data on the leaderboard.
         */
        static void GetUserEntryAsync(
            const function<void(const RGN::Modules::Leaderboard::LeaderboardEntry& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["leaderboardId"] = leaderboardId;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::LeaderboardEntry>(
                    "leaderboardV2-getUserEntry",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves a specified number of top entries and entries around the user from the specified leaderboard.
         * @param leaderboardId - The ID of the leaderboard from which the entries will be retrieved.
         * @param quantityTop - The number of top entries to retrieve from the leaderboard.
         * @param includeUser - Whether to include the user's entry in the retrieved entries.
         * @param quantityAroundUser - The number of entries to retrieve around the user's entry.
         * @param cancellationToken - A token to cancel the operation.
         * @return A task that represents the asynchronous operation. The task result contains a list of the retrieved leaderboard entries.
         */
        static void GetEntriesAsync(
            const function<void(const vector<RGN::Modules::Leaderboard::LeaderboardEntry>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const int32_t quantityTop,
            const bool includeUser,
            const int32_t quantityAroundUser,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["leaderboardId"] = leaderboardId;
                requestData["includeUser"] = includeUser;
                requestData["quantityAroundUser"] = quantityAroundUser;
                requestData["quantityTop"] = quantityTop;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::GetLeaderboardEntriesResponseData>(
                    "leaderboardV2-getEntries",
                    requestData,
                    [success] (const RGN::Modules::Leaderboard::GetLeaderboardEntriesResponseData& result) {
                        success(result.entries);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves leaderboard resets. Every time the leaderboard resets the results are stored in the history.
         * This method allows to retreive the history of the leaderboard resets.
         * @param leaderboardId - The ID of the leaderboard from which the entries will be retrieved.
         * @param withEntries - Flag to include user entries in the response.
         * @param startAfter - The start time in milliseconds since midnight, January 1, 1970 UTC, based on 'resetAt'.
         * @param limit - The maximum number of resets to retrieve.
         * @param orderDirection - The order direction for the resets. Accepted values 'asc' or 'desc'.
         * @param cancellationToken - A token to cancel the operation.
         * @return A task that represents the asynchronous operation. The task result contains a list of the retrieved leaderboard resets.
         */
        static void GetResetsAsync(
            const function<void(const vector<RGN::Modules::Leaderboard::LeaderboardReset>& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const bool withEntries,
            const int64_t startAfter = -1,
            const int32_t limit = -1,
            const string& orderDirection = "asc",
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["leaderboardId"] = leaderboardId;
                requestData["withEntries"] = withEntries;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::GetLeaderboardResetsResponseData>(
                    "leaderboardV2-getResets",
                    requestData,
                    [success] (const RGN::Modules::Leaderboard::GetLeaderboardResetsResponseData& result) {
                        success(result.resets);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Asynchronously retrieves leaderboard reset by leaderboard and reset IDs. The result includes the user entries.
         * @param leaderboardId - The ID of the leaderboard from which the reset user entries will be retrieved.
         * @param resetId - The unique reset ID of the leaderboard
         * @param startAfter - The start after based on 'place'.
         * @param limit - The maximum number of user entries to retrieve.
         * @param orderDirection - The order direction for the user entries. Accepted values 'asc' or 'desc'.
         * @param cancellationToken - A token to cancel the operation.
         * @return A task that represents the asynchronous operation. The task result contains the retrieved leaderboard reset with user entries.
         */
        static void GetResetAsync(
            const function<void(const RGN::Modules::Leaderboard::LeaderboardReset& result)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const string& resetId,
            const int64_t startAfter = 0,
            const int32_t limit = 0,
            const string& orderDirection = "asc",
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["leaderboardId"] = leaderboardId;
                requestData["resetId"] = resetId;
                RGNCore::CallAPI<nlohmann::json, RGN::Modules::Leaderboard::GetLeaderboardResetResponseData>(
                    "leaderboardV2-getReset",
                    requestData,
                    [success] (const RGN::Modules::Leaderboard::GetLeaderboardResetResponseData& result) {
                        success(result.reset);
                    },
                    fail,
                    false,
                    cancellationToken);
            };
        /**
         * Reset leaderboard. Gives the rewards to the users and resets the leaderboard.
         * Requires project admin access.
         * @param leaderboardId - The ID of the leaderboard to reset.
         * @param cancellationToken - A token to cancel the operation.
         */
        static void ResetLeaderboardAsync(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& leaderboardId,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = RGNCore::GetAppId();
                requestData["id"] = leaderboardId;
                RGNCore::CallAPI<nlohmann::json>(
                    "leaderboardV2-resetLeaderboard",
                    requestData,
                    success,
                    fail,
                    false,
                    cancellationToken);
            };
    };
}}}