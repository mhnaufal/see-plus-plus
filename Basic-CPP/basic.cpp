#include "basic.h"
#include <fstream>
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

  std::cout << std::endl;
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

  std::cout << std::endl;
}

void read_file_to_string() {
  std::string line;
  std::ifstream input_file("../Basic-CPP/mom.txt");

  if (input_file.is_open()) {
    while (getline(input_file, line)) {
      std::cout << "FROM FILE: " << line << std::endl;
    }
    std::cout << std::endl;
  }
  input_file.close();
}

int append_to_file() {
  std::string file_name = "../Basic-CPP/mom.txt";
  std::ofstream out_file(file_name, std::ios_base::app);

  if (!out_file.is_open()) {
    return EXIT_FAILURE;
  }

  out_file << "\nHello Mom :)" << std::endl;
  return EXIT_SUCCESS;
}

void print(const std::string &str) {
  std::cout << "lvalue: " << str << std::endl;
}

void print(std::string &&str) { std::cout << "rvalue: " << str << std::endl; }

void print_name(const std::string &name) { std::cout << name << std::endl; }

void print_full_name(const std::string &&name) {
  std::cout << name << std::endl;
}
