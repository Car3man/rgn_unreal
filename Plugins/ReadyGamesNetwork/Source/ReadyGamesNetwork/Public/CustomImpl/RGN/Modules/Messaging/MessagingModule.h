#pragma once

#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Generated/RGN/Modules/Messaging/IMessageReceiver.h"
#include <string>

namespace RGN { namespace Modules { namespace Messaging {
	class MessagingModuleCustomImpl {
	public:
        static void Subscribe(
            std::string topic,
            RGN::Modules::Messaging::IMessageReceiver messageReceiver) {
                // Not implemented
            };
        static void Unsubscribe(
            std::string topic,
            RGN::Modules::Messaging::IMessageReceiver messageReceiver) {
                // Not implemented
            };
        static void SendMessageByUserId(
            const std::function<void(void)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::string appId,
            std::string userId,
            std::string payload,
            std::string title,
            std::string text,
            const CancellationToken& cancellationToken = CancellationToken()) {
                nlohmann::json requestData;
                requestData["appId"] = appId;
                requestData["userId"] = userId;
                requestData["payload"] = payload;
                requestData["title"] = title;
                requestData["text"] = text;
                RGNCore::CallAPI<nlohmann::json>("messaging-sendMessageByUserId", requestData, success, fail, false, cancellationToken);
            };
	};
}}}
