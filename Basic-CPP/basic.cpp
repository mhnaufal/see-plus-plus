#include <iostream>
#include <map>

void create_response() {
  std::map<std::string, std::string> new_response{
      {"status", "SUCCESS"}, {"message", "successfully get all data"}};
  std::cout << "status: " << new_response.at("status") << "  "
            << "message: " << new_response.at("message") << std::endl;
}
