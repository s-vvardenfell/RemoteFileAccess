#include "rfa_client.hpp"

RFA_Client::RFA_Client()
{
    current_dir_ = fs::current_path();
}

void RFA_Client::showDirContent(const fs::path& dir) const
{
    if(fs::is_empty(dir))
        std::cout << "Directory is empty" << std::endl;
    else
    {
        for (const auto& entry : fs::directory_iterator(current_dir_))
            std::cout << entry.path().filename() << std::endl;//можно возвращать структуру с данными
    }
}

void RFA_Client::showCurrDirContent() const
{
    showDirContent(current_dir_);
}

void RFA_Client::showCurrDirInfo() const
{
    showDirInfo(current_dir_);
}

void RFA_Client::showFileInfo(const fs::path& file) const
{
    if(!fs::is_directory(current_dir_ / file)) //дб функц для файлов
    {
        //std::cout << (current_dir_ / file).filename() << std::endl; знаю и так
        std::cout << (current_dir_ / file).parent_path() << std::endl;
        std::cout << (current_dir_ / file).extension() << std::endl;
    }
    else
        std::cout << "Not a file" << std::endl;

}

void RFA_Client::showDirInfo(const fs::path& dir) const
{
    if(fs::is_directory(dir))
    {
        std::cout << dir.filename() << std::endl;
        std::cout << fs::current_path() << std::endl;
    }
    else
        std::cout << "Not a directory" << std::endl;
}

void RFA_Client::switchToRootDir() const
{
    std::cout << current_dir_.root_name() << std::endl;
}

void RFA_Client::switchToDirName(const fs::path& dir)
{
    current_dir_ /= dir.string();
}

void RFA_Client::switchToParentDir() const
{
    std::cout << current_dir_.parent_path() << std::endl;
}

void RFA_Client::downloadFile() const
{

}

void RFA_Client::uploadFile() const
{

}

void RFA_Client::copyFile() const
{

}

void RFA_Client::copyDir() const
{

}

void RFA_Client::moveOrRename(const fs::path& old_p, const fs::path& new_p, bool add_current_dir) const
{
    if (add_current_dir)
        fs::rename(current_dir_ / old_p, current_dir_ / new_p);
    else
        fs::rename(old_p, new_p);
}

void RFA_Client::deleteFile(const fs::path& file, bool add_current_dir) const
{
    if (add_current_dir)
    {
        std::uintmax_t n = fs::remove(current_dir_ / file);
        std::cout << "Deleted " << n << " files or directories" << std::endl;
    }
    else
    {
        std::uintmax_t n = fs::remove(file);
        std::cout << "Deleted " << n << " files or directories" << std::endl;
    }

}

void RFA_Client::deleteDir(const fs::path& dir, bool add_current_dir) const
{
    if (fs::is_directory(dir))
    {
        if (add_current_dir)
        {
            std::uintmax_t n = fs::remove_all(current_dir_ / dir);
            std::cout << "Deleted " << n << " files or directories" << std::endl;
        }
        else
        {

            std::uintmax_t n = fs::remove_all(dir);
            std::cout << "Deleted " << n << " files or directories" << std::endl;
        }
    }
    else
    {
        std::cout << "Not a directory" << std::endl;
    }

}
