#include <iostream>
#include <nlohmann/json.hpp>
#include "models.hpp"

int main() {
    // Create a C++ struct and turn it into JSON
    User u{"Ada Lovelace", "ada@example.com", 36, true};
    nlohmann::json j = u; // uses to_json

    std::cout << "User as JSON:\n" << j.dump(2) << "\n\n";

    // Build JSON by hand
    nlohmann::json prefs = {
        {"theme", "dark"},
        {"notifications", {{"email", true}, {"sms", false}}},
        {"tags", {"c++", "json", "demo"}}
    };
    std::cout << "Prefs:\n" << prefs.dump(2) << "\n\n";

    // Convert JSON back to struct
    nlohmann::json j2 = {
        {"name", "Grace Hopper"},
        {"email", "grace@example.com"},
        {"age", 85},
        {"active", false}
    };
    User u2 = j2.get<User>(); // uses from_json
    std::cout << "Deserialized User: " << u2.name << " <" << u2.email << ">, age "
              << u2.age << ", active=" << std::boolalpha << u2.active << "\n";

    return 0;
}
