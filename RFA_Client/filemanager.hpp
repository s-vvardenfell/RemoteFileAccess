#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

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

class RFA_Client final
{
public:
    RFA_Client();

    void showDirContent(const fs::path& dir) const;
    void showCurrDirContent() const; //показывать кол-во файлов и размер?
    void showCurrDirInfo() const;
    void showFileInfo(const fs::path& file) const;
    void showDirInfo(const fs::path& dir) const;

    void switchToRootDir();
    void switchToDirName(const fs::path& dir);
    void switchToParentDir();

    void downloadFile() const;
    void uploadFile() const;

    void copyFileOrDir(const fs::path& old_p, const fs::path& new_p) const;
    void moveOrRename(const fs::path& old_p, const fs::path& new_p, bool add_current_dir = true) const;

    void deleteFile(const fs::path& file, bool add_current_dir = true) const; //removes file or empty dir
    void deleteDir(const fs::path& dir, bool add_current_dir = true) const; //deletes dir and its content

private:
    void sendData(const int fd, const std::string& data);
    const std::string recvData(const int sockfd);
    void sendErrorMsg(const int sockfd, const std::string& msg);

    COMMANDS getCommandFromServer();
    void serverHandler();

    fs::path current_dir_ = "/home/chaginsergey/Downloads/test"; //for test

};

#endif // FILEMANAGER_H
