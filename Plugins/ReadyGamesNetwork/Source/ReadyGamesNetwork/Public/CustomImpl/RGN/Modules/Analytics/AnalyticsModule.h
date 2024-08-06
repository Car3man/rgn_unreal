#pragma once

#include "../../../../json.hpp"
#include "../../../../Core/RGNCore.h"
#include "../../../../Analytics/Analytics.h"
#include "../../../../Generated/RGN/Modules/Analytics/AnalyticsModule.h"
#include <string>

namespace RGN { namespace Modules { namespace Analytics {
	class AnalyticsModuleCustomImpl {
	public:
        static void LogEventAsync(
            const std::function<void(void)>& success,
            const std::function<void(int httpCode, std::string error)>& fail,
            std::string eventName,
            std::string eventParameters,
            CancellationToken cancellationToken) {
                nlohmann::json bodyJson;
                bodyJson["eventName"] = eventName;
                bodyJson["projectId"] = RGNCore::GetAppId();
                bodyJson["userId"] = RGNCore::GetUserId();
                bodyJson["userPseudoId"] = RGN::Analytics::GetAnalyticsId();
                bodyJson["sessionId"] = RGN::Analytics::GetSessionId();
                bodyJson["eventParameters"] = eventParameters;
                RGNCore::CallAPI<nlohmann::json>("analytics-logEvent", bodyJson, success, fail, false, cancellationToken);
            };
	};
}}}
