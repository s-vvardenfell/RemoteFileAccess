#include <iostream>
#include <cstring>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>

#include "client.hpp"

using namespace std;
using boost::asio::ip::tcp;

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

enum { max_length = 1024 };

int main()
{
    try
    {

      const char* host = "127.0.0.1";
      const char* port = "8080";
      boost::asio::io_context io_context;

      tcp::socket s(io_context);
      tcp::resolver resolver(io_context);
      boost::asio::connect(s, resolver.resolve(host, port));

      std::cout << "Enter message: ";
      char request[max_length];
      std::cin.getline(request, max_length);
      size_t request_length = std::strlen(request);
      boost::asio::write(s, boost::asio::buffer(request, request_length));

      char reply[max_length];
      size_t reply_length = boost::asio::read(s,
          boost::asio::buffer(reply, request_length));
      std::cout << "Reply is: ";
      std::cout.write(reply, reply_length);
      std::cout << "\n";
    }
    catch (std::exception& e)
    {
      std::cerr << "Exception: " << e.what() << "\n";
    }

  return 0;
}
