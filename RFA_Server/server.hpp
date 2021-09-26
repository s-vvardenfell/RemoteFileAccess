#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

static const constexpr int max_length = 1024;

class Server
{
public:
    Server();
    void start();
    void session(tcp::socket sock);

private:
    boost::asio::io_context io_context_;
    const int port_;
};

#endif // SERVER_HPP
