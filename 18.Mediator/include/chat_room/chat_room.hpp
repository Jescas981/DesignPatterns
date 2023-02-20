#pragma once
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>

struct Person;

struct ChatRoom {
  std::vector<Person*> people;

  void BroadCast(const std::string& origin, const std::string& message);
  void Join(Person* p);
  void Message(const std::string& origin, const std::string& who,
               const std::string& message);
};