#include "server.hpp"

Server::Server() : port_(8080)
{

}

void Server::start()
{
    tcp::acceptor acc(io_context_, tcp::endpoint(tcp::v4(), port_));

    while(true)
    {
      std::thread(&Server::session, this, acc.accept()).detach();
    }
}

void Server::session(tcp::socket sock)
{
  try
  {
    while(true)
    {
      char data[max_length];

      boost::system::error_code error;

      size_t length = sock.read_some(boost::asio::buffer(data), error);

      if (error == boost::asio::error::eof)
        break; // Connection closed cleanly by peer.
      else if (error)
        throw boost::system::system_error(error);

      std::cout << "Msg is: ";
      std::cout.write(data, length);
      std::cout << "\n";

      char *p = data;
      while (*p != '\0')
      {
          *p = toupper(*p);
          p++;
      }

      boost::asio::write(sock, boost::asio::buffer(data, length));
    }
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception in thread: " << e.what() << "\n";
  }
}
