#include "ChatRoom.hpp"
#include "Person.hpp"

int main() {
  ChatRoom room;
  Person john{"John"};
  Person jane{"Jane"};

  room.Join(&john);
  room.Join(&jane);
  john.Say("Hi there!");
  jane.Say("Hi John!!!");

  Person simon{"Simon"};
  room.Join(&simon);
  simon.Say("Hi everyone!");

  return 0;
}