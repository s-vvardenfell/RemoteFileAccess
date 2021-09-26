#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <filesystem>
#include <iostream>
#include <string>
#include <memory>

#include "filemanager.hpp"

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

private:
    COMMANDS getCommandFromServer();

    void downloadFile() const;
    void uploadFile() const;

    void sendData(const int fd, const std::string& data);
    const std::string recvData(const int sockfd);
    void sendErrorMsg(const int sockfd, const std::string& msg);

    std::unique_ptr<Filemanager> fmptr_;
};

#endif // CLIENT_HPP
