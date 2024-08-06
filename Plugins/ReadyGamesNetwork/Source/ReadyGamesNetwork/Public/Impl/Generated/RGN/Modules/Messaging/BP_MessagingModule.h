#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "../../../../Utility/BP_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Messaging/MessagingModule.h"
#include "../../../../../Generated/RGN/Modules/Messaging/IMessageReceiver.h"
#include "BP_IMessageReceiver.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "BP_MessagingModule.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_TwoParams(FMessagingModuleFailResponse, int32, code, const FString&, message);

DECLARE_DYNAMIC_DELEGATE(FMessagingModuleSubscribeResponse);
DECLARE_DYNAMIC_DELEGATE(FMessagingModuleUnsubscribeResponse);
DECLARE_DYNAMIC_DELEGATE(FMessagingModuleSendMessageByUserIdResponse);

UCLASS()
class READYGAMESNETWORK_API UBP_MessagingModule : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    /**
     * Subscribes the  to the provided "
     * @param topic - Not null topic string to subscribe
     * @param messageReceiver - Not null message receiver class instance to subsribe to the topic
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Messaging")
    static void Subscribe(
        FMessagingModuleSubscribeResponse onSuccess,
        FMessagingModuleFailResponse onFail,
        const FString& topic,
        const FBP_IMessageReceiver& messageReceiver) {
            string cpp_topic;
            RGN::Modules::Messaging::IMessageReceiver cpp_messageReceiver;
            cpp_topic = string(TCHAR_TO_UTF8(*topic));
            FBP_IMessageReceiver::ConvertToCoreModel(messageReceiver, cpp_messageReceiver);
            RGN::Modules::Messaging::MessagingModule::Subscribe(
                cpp_topic,
                cpp_messageReceiver);
    }
    /**
     * Unsubscribes the  from the provided "
     * @param topic - Not null topic string
     * @param messageReceiver - Not null message receiver class instance
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Messaging")
    static void Unsubscribe(
        FMessagingModuleUnsubscribeResponse onSuccess,
        FMessagingModuleFailResponse onFail,
        const FString& topic,
        const FBP_IMessageReceiver& messageReceiver) {
            string cpp_topic;
            RGN::Modules::Messaging::IMessageReceiver cpp_messageReceiver;
            cpp_topic = string(TCHAR_TO_UTF8(*topic));
            FBP_IMessageReceiver::ConvertToCoreModel(messageReceiver, cpp_messageReceiver);
            RGN::Modules::Messaging::MessagingModule::Unsubscribe(
                cpp_topic,
                cpp_messageReceiver);
    }
    /**
     * Sends a message to provided user.
     * This method works only for admin users.
     * If the title and text are null or empty it will send a data message.
     * Data messages do not appear in the device system tray.
     * If the title and/or the text are provided, the ht
     * @param appId - The project id to send the message
     * @param userId - The user id to send the message to
     * @param payload - Any string (preferable json) with custom data
     * that will be attached to the message
     * @param title - Optional. If provided, the message will appear in system tray
     * in case the application is in background
     * @param text - Optional. If provided, the message will appear in system tray
     * in case the application is in background
     * @param cancellationToken - A token to cancel the operation.
     */
    UFUNCTION(BlueprintCallable, Category = "ReadyGamesNetwork | Messaging", meta=(AutoCreateRefTerm="cancellationToken"))
    static void SendMessageByUserId(
        FMessagingModuleSendMessageByUserIdResponse onSuccess,
        FMessagingModuleFailResponse onFail,
        const FBP_CancellationToken& cancellationToken,
        const FString& appId,
        const FString& userId,
        const FString& payload,
        const FString& title,
        const FString& text) {
            string cpp_appId;
            string cpp_userId;
            string cpp_payload;
            string cpp_title;
            string cpp_text;
            RGN::CancellationToken cpp_cancellationToken;
            cpp_appId = string(TCHAR_TO_UTF8(*appId));
            cpp_userId = string(TCHAR_TO_UTF8(*userId));
            cpp_payload = string(TCHAR_TO_UTF8(*payload));
            cpp_title = string(TCHAR_TO_UTF8(*title));
            cpp_text = string(TCHAR_TO_UTF8(*text));
            FBP_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Messaging::MessagingModule::SendMessageByUserId(
                [onSuccess]() {
                    onSuccess.ExecuteIfBound();
                },
                [onFail](int code, std::string message) {
                     onFail.ExecuteIfBound(static_cast<int32>(code), FString(message.c_str()));
                },
                cpp_appId,
                cpp_userId,
                cpp_payload,
                cpp_title,
                cpp_text,
                cpp_cancellationToken);
    }
};
