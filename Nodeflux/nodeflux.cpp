#include "nodeflux.h"

void msgPackIntroduction() {
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

// void pytorchCppFrontend() {
//   torch::Tensor tensor = torch::eye(3);
//   std::cout << tensor << std::endl;
// }

// int add(int i, int j) {
//   return i + j;
// }
//
// PYBIND11_MODULE(example_module, handle) {
//   handle.doc() = "pybind11 example plugin"; // optional module docstring
//
//   handle.def("add", &add, "A function that adds two numbers");
// }
