#ifndef SHE_PLUS_PLUS_BASIC_H
#define SHE_PLUS_PLUS_BASIC_H

#include <string>

void create_response();
void create_base_data(int capacity);
void read_file_to_string();
int append_to_file();
void print(const std::string &str);
void print(std::string &&str);
void print_name(const std::string
                    &name); // we add `const` so that we can use rvalue as the
                            // input argument. Instead, if we don't use the
                            // `const`, we need to input lvalue as the argument
void print_full_name(
    const std::string &&
        name); // this function accept "rvalue reference" as the input parameter

#endif // SHE_PLUS_PLUS_BASIC_H
