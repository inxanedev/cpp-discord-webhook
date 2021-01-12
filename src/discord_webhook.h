#pragma once
#include <curl/curl.h>
class DiscordWebhook {
    public:
        DiscordWebhook(const char* webhook_url);
        ~DiscordWebhook();

        void send_message(const char* message);
    private:
        CURL* curl;
};
