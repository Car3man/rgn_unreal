#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardModule_Admin.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardData.h"
#include "BP_LeaderboardData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_LeaderboardModule_Admin.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FLeaderboardModule_AdminFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleAdminAddLeaderboardAsyncResponse, const FBP_LeaderboardData&, response);
DECLARE_DYNAMIC_DELEGATE_OneParam(FLeaderboardModuleAdminUpdateLeaderboardAsyncResponse, const FString&, response);
DECLARE_DYNAMIC_DELEGATE(FLeaderboardModuleAdminDeleteLeaderboardAsyncResponse);

UCLASS()
class READYGAMESNETWORK_API UBP_LeaderboardModule_Admin : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void AddLeaderboardAsync(
        FLeaderboardModuleAdminAddLeaderboardAsyncResponse onSuccess,
        FLeaderboardModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FBP_LeaderboardData& leaderboardData) {
            RGN::Modules::Leaderboard::LeaderboardData cpp_leaderboardData;
            RGN::CancellationToken cpp_cancellationToken;
            FBP_LeaderboardData::ConvertToCoreModel(leaderboardData, cpp_leaderboardData);
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule_Admin::AddLeaderboardAsync(
                [onSuccess](RGN::Modules::Leaderboard::LeaderboardData response) {
                    FBP_LeaderboardData bpResponse;
                    FBP_LeaderboardData::ConvertToUnrealModel(response, bpResponse);
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardData,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void UpdateLeaderboardAsync(
        FLeaderboardModuleAdminUpdateLeaderboardAsyncResponse onSuccess,
        FLeaderboardModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FBP_LeaderboardData& leaderboardData) {
            RGN::Modules::Leaderboard::LeaderboardData cpp_leaderboardData;
            RGN::CancellationToken cpp_cancellationToken;
            FBP_LeaderboardData::ConvertToCoreModel(leaderboardData, cpp_leaderboardData);
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule_Admin::UpdateLeaderboardAsync(
                [onSuccess](string response) {
                    FString bpResponse;
                    bpResponse = FString(UTF8_TO_TCHAR(response.c_str()));
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardData,
                cpp_cancellationToken);
    }
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Leaderboard", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeleteLeaderboardAsync(
        FLeaderboardModuleAdminDeleteLeaderboardAsyncResponse onSuccess,
        FLeaderboardModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& leaderboardId) {
            string cpp_leaderboardId;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_leaderboardId = string(TCHAR_TO_UTF8(*leaderboardId));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Leaderboard::LeaderboardModule_Admin::DeleteLeaderboardAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_leaderboardId,
                cpp_cancellationToken);
    }
};
