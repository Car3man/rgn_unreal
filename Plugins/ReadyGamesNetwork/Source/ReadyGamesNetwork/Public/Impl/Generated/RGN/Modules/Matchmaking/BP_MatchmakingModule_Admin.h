#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Matchmaking/MatchmakingModule_Admin.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_MatchmakingModule_Admin.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FMatchmakingModule_AdminFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE(FMatchmakingModuleAdminDeleteMatchesByAppIdAsyncResponse);

UCLASS()
class READYGAMESNETWORK_API UBP_MatchmakingModule_Admin : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Matchmaking", meta=(AutoCreateRefTerm="cancellationToken"))
    static void DeleteMatchesByAppIdAsync(
        FMatchmakingModuleAdminDeleteMatchesByAppIdAsyncResponse onSuccess,
        FMatchmakingModule_AdminFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& appIdToRemoveTheMatchesFor) {
            string cpp_appIdToRemoveTheMatchesFor;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_appIdToRemoveTheMatchesFor = string(TCHAR_TO_UTF8(*appIdToRemoveTheMatchesFor));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule_Admin::DeleteMatchesByAppIdAsync(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_appIdToRemoveTheMatchesFor,
                cpp_cancellationToken);
    }
};
