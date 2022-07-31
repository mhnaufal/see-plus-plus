#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

void create_response() {
  std::map<std::string, std::string> new_response{
      {"status", "SUCCESS"}, {"message", "successfully get all data"}};

  std::cout << "status: " << new_response.at("status") << "  "
            << "message: " << new_response.at("message") << std::endl;

  //  create unordered_map type alias
  using Payload = std::unordered_map<std::string, std::string>;
  Payload payload;
  payload.emplace("total", std::to_string(123));
  payload.emplace("positive", std::to_string(99));

  //  Option 1 to iterate over a map
  for (const auto &[key, value] : payload) {
    std::cout << key << ":  " << value << "  " << std::endl;
  }

  //  Option 2 to iterate over a map
  for (const auto &pair : payload) {
    std::cout << pair.first << ":  " << pair.second << "  " << std::endl;
  }
}

void create_base_data(int capacity) {
  std::vector<int> unoptimize_data;

  for (int i = 0; i < capacity; ++i) {
    unoptimize_data.emplace_back(i);
  }

  std::cout << "size: " << unoptimize_data.size()
            << " capacity: " << unoptimize_data.capacity() << std::endl;

  std::vector<int> data;
  data.reserve(capacity); // to optimize our vector capacity so that is not
                          // automatically expand its capacity

  for (int i = 0; i < capacity; ++i) {
    data.emplace_back(i);
  }

  std::cout << "size: " << data.size() << " capacity: " << data.capacity()
            << std::endl;
}
