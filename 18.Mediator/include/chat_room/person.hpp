#pragma once
#include <string>
#include <vector>

struct ChatRoom;

struct Person {
  std::string name;
  std::vector<std::string> chat_log;
  ChatRoom* room{nullptr};
  Person(const std::string& name);
  void Say(const std::string& name) const;
  void PrivateMessage(const std::string& who, const std::string& message) const;
  void Receive(const std::string& origin, const std::string& message);
  bool operator==(const Person& p) const;
  bool operator!=(const Person& p) const;
};