#include "discord_webhook.h"
#include <curl/curl.h>
#include <iostream>
#include <string>
DiscordWebhook::DiscordWebhook(const char* webhook_url) {
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, webhook_url);
        curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    } else {
        std::cerr << "Error: curl_easy_init() returned NULL pointer" << std::endl;
    }
}

DiscordWebhook::~DiscordWebhook() {
    curl_global_cleanup();
    curl_easy_cleanup(curl);
}

void DiscordWebhook::send_message(const char* message) {
    std::string json = std::string("{\"content\": \"") + message + "\"}";
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json.c_str());

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Error: curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }
}
