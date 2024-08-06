#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../CustomImpl/RGN/Modules/Messaging/MessagingModule.h"
#include "../../../../Utility/CancellationToken.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "IMessageReceiver.h"
using namespace std;

namespace RGN { namespace Modules { namespace Messaging {
    class MessagingModule {
    public:
        /**
         * Subscribes the  to the provided "
         * @param topic - Not null topic string to subscribe
         * @param messageReceiver - Not null message receiver class instance to subsribe to the topic
         */
        static void Subscribe(
            const string& topic,
            const RGN::Modules::Messaging::IMessageReceiver& messageReceiver) {
                RGN::Modules::Messaging::MessagingModuleCustomImpl::Subscribe(
                    topic,
                    messageReceiver);
            };
        /**
         * Unsubscribes the  from the provided "
         * @param topic - Not null topic string
         * @param messageReceiver - Not null message receiver class instance
         */
        static void Unsubscribe(
            const string& topic,
            const RGN::Modules::Messaging::IMessageReceiver& messageReceiver) {
                RGN::Modules::Messaging::MessagingModuleCustomImpl::Unsubscribe(
                    topic,
                    messageReceiver);
            };
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
        static void SendMessageByUserId(
            const function<void(void)>& success,
            const function<void(const int httpCode, const string& error)>& fail,
            const string& appId,
            const string& userId,
            const string& payload,
            const string& title,
            const string& text,
            const CancellationToken& cancellationToken = CancellationToken()) {
                RGN::Modules::Messaging::MessagingModuleCustomImpl::SendMessageByUserId(
                    success,
                    fail,
                    appId,
                    userId,
                    payload,
                    title,
                    text,
                    cancellationToken);
            };
    };
}}}