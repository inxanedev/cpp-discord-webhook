#pragma once
#include <curl/curl.h>
class DiscordWebhook {
    public:
        // Parameters:
        // - webhook_url: the discord webhook url
        DiscordWebhook(const char* webhook_url);
        ~DiscordWebhook();
        
        // Sends the specified message to the webhook.
        void send_message(const char* message);
    private:
        CURL* curl;
};
