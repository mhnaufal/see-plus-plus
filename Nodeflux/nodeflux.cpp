#include "nodeflux.h"

void msgPackIntroduction() {
  std::cout << "msgpack version: " << MSGPACK_VERSION << std::endl;

  // create a data to be serialized
  msgpack::type::tuple<int, bool, std::string> src(1, true, "example");

  // serialize the data into a buffer
  std::stringstream buffer;
  msgpack::pack(buffer, src);
  std::cout << "buffer => " << buffer.str() << " src => " << src.size()
            << std::endl;

  // send the buffer
  buffer.seekg(0);

  // deserialize the buffer into msgpack::object instance
  std::string str = buffer.str();
  std::cout << "deserialize => " << str << std::endl;

  msgpack::object_handle oh = msgpack::unpack(str.data(), str.size());
  msgpack::object deserialized = oh.get();
  std::cout << "real des => " << deserialized << std::endl;
  assert((deserialized.as<decltype(src)>()) == src);
}

void libasyikIntroduction() {
  /*Initiate server*/
  auto asyik_server = asyik::make_service();
  auto server = asyik::make_http_server(asyik_server, "127.0.0.1", 8000);

  /*Serve HTTP request*/
  server->on_http_request("/", "GET", [](auto req, auto args) {
    req->response.body = "Hello mom!";
    req->response.result(200);
  });

  asyik_server->run();
}
