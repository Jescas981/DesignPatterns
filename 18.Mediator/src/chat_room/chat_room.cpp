#include <chat_room/chat_room.hpp>
#include <chat_room/person.hpp>

void ChatRoom::BroadCast(const std::string& origin,
                         const std::string& message) {
  for (auto& p : people) {
    if (p->name != origin) p->Receive(origin, message);
  }
}

void ChatRoom::Join(Person* p) {
  std::string join_msg = p->name + " joints the chat";
  BroadCast("room", join_msg);
  p->room = this;
  people.push_back(p);
}

void ChatRoom::Message(const std::string& origin, const std::string& who,
                       const std::string& message) {
  auto target = std::find_if(people.begin(), people.end(),
                             [&](const Person* p) { return p->name == who; });
  if (target != people.end()) {
    (*target)->Receive(origin, message);
  }
}