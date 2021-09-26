#include "filemanager.hpp"

Filemanager::Filemanager()
{
//    current_dir_ = fs::current_path();
}

void Filemanager::showDirContent(const fs::path& dir) const
{
    if(fs::is_empty(dir))
        std::cout << "Directory is empty" << std::endl;
    else
    {
        for (const auto& entry : fs::directory_iterator(current_dir_))
            std::cout << entry.path().filename() << std::endl;//можно возвращать структуру с данными
    }
}

void Filemanager::showCurrDirContent() const
{
    showDirContent(current_dir_);
}

void Filemanager::showCurrDirInfo() const
{
    showDirInfo(current_dir_);
}

void Filemanager::showFileInfo(const fs::path& file) const
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

void Filemanager::showDirInfo(const fs::path& dir) const
{
    if(fs::is_directory(dir))
    {
        std::cout << dir.filename() << std::endl;
        std::cout << fs::current_path() << std::endl;
    }
    else
        std::cout << "Not a directory" << std::endl;
}

void Filemanager::switchToRootDir()
{
    //std::cout << current_dir_.root_name() << std::endl;
    //std::cout << current_dir_.root_directory() << std::endl;
    std::cout << current_dir_.root_path() << std::endl;
    current_dir_ /= current_dir_.root_path();
}

void Filemanager::switchToDirName(const fs::path& dir)
{
    current_dir_ /= dir.string();
}

void Filemanager::switchToParentDir()
{
    std::cout << current_dir_.parent_path() << std::endl;
    current_dir_ /= current_dir_.parent_path();
}

void Filemanager::copyFileOrDir(const fs::path& old_p, const fs::path& new_p) const
{
//    const auto copyOptions = fs::copy_options::update_existing
//                           | fs::copy_options::recursive
//                           | fs::copy_options::directories_only;

//    fs::copy(old_p, new_p, copyOptions);
    fs::copy(old_p, new_p);

}

void Filemanager::moveOrRename(const fs::path& old_p, const fs::path& new_p, bool add_current_dir) const
{
    if (add_current_dir)
        fs::rename(current_dir_ / old_p, current_dir_ / new_p);
    else
        fs::rename(old_p, new_p);
}

void Filemanager::deleteFile(const fs::path& file, bool add_current_dir) const
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

void Filemanager::deleteDir(const fs::path& dir, bool add_current_dir) const
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
