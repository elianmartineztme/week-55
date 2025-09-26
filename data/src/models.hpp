#pragma once
#include <string>
#include <nlohmann/json.hpp>

// A simple C++ struct we’ll serialize/deserialize.
struct User {
    std::string name;
    std::string email;
    int age{};
    bool active{};
};

// to_json / from_json let nlohmann::json convert this struct automatically.
inline void to_json(nlohmann::json& j, const User& u) {
    j = nlohmann::json{
        {"name", u.name},
        {"email", u.email},
        {"age", u.age},
        {"active", u.active}
    };
}

inline void from_json(const nlohmann::json& j, User& u) {
    j.at("name").get_to(u.name);
    j.at("email").get_to(u.email);
    j.at("age").get_to(u.age);
    j.at("active").get_to(u.active);
}
