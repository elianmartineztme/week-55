#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

int main() {
    std::ifstream in("data/sample.json");
    if (!in) {
        std::cerr << "Could not open data/sample.json (run from repo root)\n";
        return 1;
    }
    nlohmann::json j;
    in >> j;

    // Pretty print
    std::cout << "Loaded JSON:\n" << j.dump(2) << "\n\n";

    // Access fields safely
    std::string app = j.value("app", "unknown");
    bool debug = j.value("debug", false);
    int timeout = j.value("timeoutSeconds", 0);

    std::cout << "App: " << app << "\n";
    std::cout << "Debug: " << std::boolalpha << debug << "\n";
    std::cout << "TimeoutSeconds: " << timeout << "\n\n";

    // Nested object + array iteration
    if (j.contains("owner") && j["owner"].is_object()) {
        auto owner = j["owner"];
        std::cout << "Owner: " << owner.value("name", "N/A")
                  << " <" << owner.value("email", "N/A") << ">\n";
    }

    if (j.contains("features") && j["features"].is_array()) {
        std::cout << "Features:\n";
        for (const auto& f : j["features"]) std::cout << "  - " << f.get<std::string>() << "\n";
    }

    return 0;
}
