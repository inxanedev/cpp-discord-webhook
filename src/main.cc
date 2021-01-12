#include <iostream>
#include <string>
#include "discord_webhook.h"

int main() {
    std::cout << "Welcome to C++ Discord Webhook Client!" << std::endl;
    std::cout << "Input webhook url: ";
    std::string url;
    std::getline(std::cin, url);

    DiscordWebhook webhook(url.c_str());
    std::cout << "Discord webhook initialized!" << std::endl;
    std::string input;
    std::cout << "Type in your messages and hit enter to send." << std::endl;
    std::cout << "Type in 'quit' to quit the program!" << std::endl;
    while (true) {
        std::cout << "Input message: ";
        std::getline(std::cin, input);
        if (input == "quit")
            break;

        webhook.send_message(input.c_str());
        std::cout << "[+] Message posted!" << std::endl;
    }
    std::cout << "Bye bye!" << std::endl;
}
