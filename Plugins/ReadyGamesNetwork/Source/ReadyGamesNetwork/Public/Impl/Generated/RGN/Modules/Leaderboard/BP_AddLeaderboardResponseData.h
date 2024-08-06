#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/AddLeaderboardResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardData.h"
#include "BP_LeaderboardData.h"
#include <string>
#include <vector>
#include <unordered_map>
#include "BP_AddLeaderboardResponseData.generated.h"

USTRUCT(BlueprintType)
struct READYGAMESNETWORK_API FBP_AddLeaderboardResponseData {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Leaderboard")
    FString leaderboardId;
    UPROPERTY(BlueprintReadWrite, Category = "ReadyGamesNetwork | Leaderboard")
    FBP_LeaderboardData leaderboard;

	static void ConvertToUnrealModel(const RGN::Modules::Leaderboard::AddLeaderboardResponseData& source, FBP_AddLeaderboardResponseData& target) {
        target.leaderboardId = FString(UTF8_TO_TCHAR(source.leaderboardId.c_str()));
        FBP_LeaderboardData::ConvertToUnrealModel(source.leaderboard, target.leaderboard);
	}

	static void ConvertToCoreModel(const FBP_AddLeaderboardResponseData& source, RGN::Modules::Leaderboard::AddLeaderboardResponseData& target) {
        target.leaderboardId = string(TCHAR_TO_UTF8(*source.leaderboardId));
        FBP_LeaderboardData::ConvertToCoreModel(source.leaderboard, target.leaderboard);
	}
};
