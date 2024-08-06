#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Wallets/WalletsModule.h"
#include "../../../../../Generated/RGN/Modules/Wallets/IsUserHasBlockchainRequirementResponseData.h"
#include "BP_IsUserHasBlockchainRequirementResponseData.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_WalletsModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FWalletsModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE_OneParam(FWalletsModuleIsUserHasBlockchainRequirementAsyncResponse, bool, response);

UCLASS()
class READYGAMESNETWORK_API UBP_WalletsModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    /**
     * Checks if the user has a blockchain requirement
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Wallets", meta=(AutoCreateRefTerm="cancellationToken"))
    static void IsUserHasBlockchainRequirementAsync(
        FWalletsModuleIsUserHasBlockchainRequirementAsyncResponse onSuccess,
        FWalletsModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken) {
            RGN::CancellationToken cpp_cancellationToken;
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Wallets::WalletsModule::IsUserHasBlockchainRequirementAsync(
                [onSuccess](bool response) {
                    bool bpResponse;
                    bpResponse = response;
                    onSuccess.ExecuteIfBound(bpResponse);
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_cancellationToken);
    }
};
