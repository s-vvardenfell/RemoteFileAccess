#ifndef RFA_CLIENT_HPP
#define RFA_CLIENT_HPP

#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

class RFA_Client final
{
public:
    RFA_Client();

    void showDirContent(const fs::path& dir) const;
    void showCurrDirContent() const; //показывать кол-во файлов и размер?
    void showCurrDirInfo() const;
    void showFileInfo(const fs::path& file) const;
    void showDirInfo(const fs::path& dir) const;

    void switchToRootDir() const;
    void switchToDirName(const fs::path& dir);
    void switchToParentDir() const;

    void downloadFile() const;
    void uploadFile() const;

    void copyFile() const;
    void copyDir() const;
    void moveOrRename() const;

    void deleteFile(const fs::path& file) const; //removes file or empty dir
    void deleteDir(const fs::path& dir) const; //deletes dir and its content

private:
    void sendData(const int fd, const std::string& data);
    const std::string recvData(const int sockfd);
    void sendErrorMsg(const int sockfd, const std::string& msg);
    void serverHandler();

    fs::path current_dir_ = "/home/chaginsergey/Downloads/test"; //for test

};

#endif // RFA_CLIENT_HPP
