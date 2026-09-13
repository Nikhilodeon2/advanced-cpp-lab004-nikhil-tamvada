#include "Person.h"

#include <utility>

Person::Person() : Person("Unknown", "Unknown", "unknown@example.com") {}

Person::Person(std::string name, std::string id, std::string email)
    : name_(std::move(name)), id_(std::move(id)), email_(std::move(email)) {
    if (name_.empty() || id_.empty() || email_.empty() || email_.find('@') == std::string::npos) {
        throw std::invalid_argument("name, id, and a valid email are required");
    }
}

const std::string& Person::getName() const noexcept { return name_; }
void Person::setName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("name cannot be empty");
    }
    name_ = name;
}


const std::string& Person::getId() const noexcept { return id_; }
void Person::setId(const std::string& id) {
    if (id.empty()) {
        throw std::invalid_argument("id cannot be empty");
    }
    id_ = id;
}

const std::string& Person::getEmail() const noexcept { return email_; }
void Person::setEmail(const std::string& email) {
    if (email.empty() || email.find('@') == std::string::npos) {
        throw std::invalid_argument("email must be valid");
    }
    email_ = email;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.getName() << " (" << person.getId() << ")";
    return os;
}
