#include "nodeflux.h"
#include <iostream>
#include <msgpack.hpp>
#include <string>
#include <vector>

void MsgPackMain() {
  std::cout << "msgpack version: " << MSGPACK_VERSION << std::endl;

  // create a data in the server
  std::vector<std::string> vec1 = {"Hello", "mom!"};

  // serialize the data before send it to client
  msgpack::sbuffer sbuf;
  msgpack::pack(sbuf, vec1);

  // when the data is received in client, deserialize it
  msgpack::object_handle oh = msgpack::unpack(sbuf.data(), sbuf.size());
  std::cout << "msgpack vector data: " << oh.get() << std::endl;
}