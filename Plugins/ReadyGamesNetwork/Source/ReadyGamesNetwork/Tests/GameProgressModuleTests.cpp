#include "Misc/AutomationTest.h"
#include "../Public/Impl/Core/BP_RGNCore.h"
#include "../Public/Impl/Generated/RGN/Modules/GameProgress/BP_GameProgressModule.h"
#include "FRGNAutomationTestBase.h"
#include "UTestHelper.h"

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FAddUserProgressAsyncTest, FRGNAutomationTestBase, "ReadyGamesNetwork.Tests.GameProgress.AddUserProgressAsync", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FAddUserProgressAsyncTest::RunTest(const FString& Parameters)
{
    FRGNAutomationTestBase::RunTest(Parameters);

    FGameProgressModuleAddUserProgressAsyncResponse onSuccess;
    onSuccess.BindUFunction(TestHelper, FName("HandleSuccess"));
    FGameProgressModuleFailResponse onFail;
    onFail.BindUFunction(TestHelper, FName("HandleFailure"));

    FString userProgressJson = TEXT("{\"progress\": 50}");
    UBP_GameProgressModule::AddUserProgressAsync(onSuccess, onFail, FBP_CancellationToken(), userProgressJson);

    return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(FOnGameCompleteAsyncTest, FRGNAutomationTestBase, "ReadyGamesNetwork.Tests.GameProgress.OnGameCompleteAsync", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FOnGameCompleteAsyncTest::RunTest(const FString& Parameters)
{
    FRGNAutomationTestBase::RunTest(Parameters);

    FGameProgressModuleOnGameCompleteAsyncResponse onSuccess;
    onSuccess.BindUFunction(TestHelper, FName("HandleSuccess"));
    FGameProgressModuleFailResponse onFail;
    onFail.BindUFunction(TestHelper, FName("HandleFailure"));

    UBP_GameProgressModule::OnGameCompleteAsync(onSuccess, onFail, FBP_CancellationToken(), {});

    return true;
}