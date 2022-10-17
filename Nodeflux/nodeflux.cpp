#include "nodeflux.h"

void msgPackIntroduction() {
  std::cout << "msgpack version: " << MSGPACK_VERSION << std::endl;

  // create a data to be serialized
  msgpack::type::tuple<int, bool, std::string> src(1, true, "example");
  std::array<int, 5> src2{1, 2, 3, 4, 5};

  // serialize the data into a buffer
  std::stringstream buffer;   // create a container for the packed data
  msgpack::pack(buffer, src); // serialize the data
  std::cout << "buffer => " << buffer.str() << " src => " << src.size()
            << std::endl;

  // send the buffer
  buffer.seekg(0);

  // deserialize the buffer into msgpack::object instance
  std::string str = buffer.str(); // get the buffer string
  std::cout << "deserialize => " << str << std::endl;

  msgpack::object_handle oh =
      msgpack::unpack(str.data(), str.size()); // unpack the buffer string
  msgpack::object deserialized = oh.get();     // get the unpacked data
  std::cout << "real des => " << deserialized << std::endl;
  assert((deserialized.as<decltype(src)>()) == src);

  // convert object to the original type
  msgpack::type::tuple<int, bool, std::string> dst;
  deserialized.convert(dst);
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

void zeroMQIntroduction() {
  zmq::context_t ctx;
  std::cout << "ctx: " << ctx.handle() << std::endl;

  zmq::socket_t sckt(ctx, zmq::socket_type::push);
  std::cout << "socket: " << sckt << std::endl;

  sckt.bind("inproc://test");
  const std::string_view msg = "Hello, World from ZeroMQ!";
  std::cout << "message: " << msg << std::endl;

  sckt.send(zmq::buffer(msg), zmq::send_flags::dontwait);
}

int zeroMQMultipartMessage() {
  // prepare sockets and context
  zmq::context_t ctx;
  zmq::socket_t sock1(ctx, zmq::socket_type::push);
  zmq::socket_t sock2(ctx, zmq::socket_type::pull);

  // prepare the "push" (server) connection to port 7000
  sock1.bind("tcp://127.0.0.1:7000");

  // connect to the server
  const std::string last_endpoint = sock1.get(zmq::sockopt::last_endpoint);
  std::cout << "connecting to " << last_endpoint << std::endl;
  sock2.connect(last_endpoint);

  // send the messages
  std::array<zmq::const_buffer, 2> send_msgs = {zmq::str_buffer("foo!"),
                                                zmq::str_buffer("bar!")};
  if (!zmq::send_multipart(sock1, send_msgs))
    return 1;

  // let the sock2 receive the messages
  std::vector<zmq::message_t> recv_msgs;
  const auto ret = zmq::recv_multipart(sock2, std::back_inserter(recv_msgs));
  if (!ret)
    return 1;

  std::cout << "Got: " << ret.value() << " " << *ret
            << " messages: " << recv_msgs.data() << std::endl;

  return 0;
}

int zeroMQReqRep() {
  std::cout << "starting zeromq server" << std::endl;
  zmq::context_t ctx(2);
  zmq::socket_t socket(ctx, zmq::socket_type::rep); // create SERVER type socket
  socket.bind("tcp://*:5555"); // binds the server to port 5555
  std::cout << "starting zeromq server..." << std::endl;

  // CLIENT request goes here!
  for (int i = 0; i < 10; ++i) {
    zmq::message_t request;

    // socket server is waiting for the next request from client
    socket.recv(request, zmq::recv_flags::none);
    std::cout << "Received Hello" << std::endl;

    // do some 'work'
    sleep(1);

    // send reply to the client
    zmq::message_t reply(5);
    memcpy(reply.data(), "World", 5);
    socket.send(reply, zmq::send_flags::none);
    //    zmq_msg_t reply;
    //    zmq_msg_init_size(&reply, 5);
    //    memcpy(zmq_msg_data(&reply), "World", 5);
    //    zmq_msg_send(&reply, socket, 0);
    //    zmq_msg_close(&reply);
  }

  return 0;
}
