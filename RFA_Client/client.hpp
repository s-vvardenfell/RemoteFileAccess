#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <filesystem>
#include <iostream>
#include <string>
#include <memory>

#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>

#include "filemanager.hpp"

using boost::asio::ip::tcp;

static const constexpr int max_length = 1024;

enum class COMMANDS
{
    EXIT,
    SHOW_DIR_CONTENT,
    SHOW_CURRENT_DIR_CONTENT,
    SHOW_CURRENT_DIR_INFO,
    SHOW_DIR_INFO,
    SHOW_FILE_INFO,
    SWITCH_TO_ROOT_DIR,
    SWITCH_TO_DIR,
    SWITCH_TO_PARENT_DIR,
    DOWNLOAD_FILE,
    UPLOAD_FILE,
    COPY_FILE_OR_DIR,
    MOVE_OR_RENAME,
    DELETE_DIR,
    DELETE_FILE
};

class Client final
{
public:
    Client();

    void serverHandler();

    //temporary public
    void sendData(const std::string& data);
    const std::string recvData();
    void sendErrorMsg(const int sockfd, const std::string& msg);

private:
    COMMANDS getCommandFromServer();

    void downloadFile() const;
    void uploadFile() const;

    std::unique_ptr<Filemanager> fmptr_;

    const char* host = "127.0.0.1";
    const char* port = "8080";
    size_t request_length_; //temporary

    boost::asio::io_context io_context_;
    tcp::socket sock_;
    tcp::resolver resolver_;
};

#endif // CLIENT_HPP
