#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

class Filemanager final
{
public:
    Filemanager();

    void showDirContent(const fs::path& dir) const;
    void showCurrDirContent() const; //показывать кол-во файлов и размер?
    void showCurrDirInfo() const;
    void showFileInfo(const fs::path& file) const;
    void showDirInfo(const fs::path& dir) const;

    void switchToRootDir();
    void switchToDirName(const fs::path& dir);
    void switchToParentDir();

    void copyFileOrDir(const fs::path& old_p, const fs::path& new_p) const;
    void moveOrRename(const fs::path& old_p, const fs::path& new_p, bool add_current_dir = true) const;

    void deleteFile(const fs::path& file, bool add_current_dir = true) const; //removes file or empty dir
    void deleteDir(const fs::path& dir, bool add_current_dir = true) const; //deletes dir and its content

    fs::path current_dir_ = "/home/chaginsergey/Downloads/test"; //for test
};

#endif // FILEMANAGER_H
