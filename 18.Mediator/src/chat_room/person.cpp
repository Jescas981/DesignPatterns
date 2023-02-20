#include <iostream>
#include <chat_room/person.hpp>
#include <chat_room/chat_room.hpp>

Person::Person(const std::string& name) : name(name) {}

void Person::Say(const std::string& message) const {
  room->BroadCast(name, message);
}

void Person::PrivateMessage(const std::string& who,
                            const std::string& message) const {
  room->Message(name, who, message);
}

void Person::Receive(const std::string& origin, const std::string& message) {
  std::string s{origin + ": \"" + message + "\""};
  std::cout << "[" << name << "'s chat session]" << s << "\n";
  chat_log.emplace_back(s);
}

bool Person::operator==(const Person& p) const { return name == p.name; }

bool Person::operator!=(const Person& p) const { return name != p.name; }