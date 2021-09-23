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

void RFA_Client::switchToRootDir()
{
    //std::cout << current_dir_.root_name() << std::endl;
    //std::cout << current_dir_.root_directory() << std::endl;
    std::cout << current_dir_.root_path() << std::endl;
    current_dir_ /= current_dir_.root_path();
}

void RFA_Client::switchToDirName(const fs::path& dir)
{
    current_dir_ /= dir.string();
}

void RFA_Client::switchToParentDir()
{
    std::cout << current_dir_.parent_path() << std::endl;
    current_dir_ /= current_dir_.parent_path();
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

COMMANDS RFA_Client::getCommandFromServer()
{
    //возвращает значение перечисляемого типа
    //навигацией и удалением занимается один класс
    //а связью с сервером - другой
    //класс-связист инкапсулирует буст асио, получает аргументы от сервера и вызывает ф-ии класса RFA_Client
    //RFA_Client дб переименован тк RFA_Client это тот класс который взаимодействует с сервером комманд
}

void RFA_Client::serverHandler()
{
    while (1)
    {
        switch (getCommandFromServer())
        {
            case COMMANDS::EXIT:
            {
                 printf("Exit programm\n"); exit(0);
            }
            case COMMANDS::SHOW_DIR_CONTENT:
            {
                 break;
            }
            case COMMANDS::SHOW_CURRENT_DIR_CONTENT:
            {
                 break;
            }
            case COMMANDS::SHOW_CURRENT_DIR_INFO:
            {
                break;
            }
            case COMMANDS::SHOW_DIR_INFO:
            {
                break;
            }
            case COMMANDS::SHOW_FILE_INFO:
            {
                break;
            }
            case COMMANDS::SWITCH_TO_ROOT_DIR:
            {
                break;
            }
            case COMMANDS::SWITCH_TO_DIR:
            {
                break;
            }
            case COMMANDS::SWITCH_TO_PARENT_DIR:
            {
                break;
            }
            case COMMANDS::DOWNLOAD_FILE:
            {
                break;
            }
            case COMMANDS::UPLOAD_FILE:
            {
                break;
            }
            case COMMANDS::COPY_FILE:
            {
                break;
            }
            case COMMANDS::COPY_DIR:
            {
                break;
            }
            case COMMANDS::MOVE_OR_RENAME:
            {
                break;
            }
            case COMMANDS::DELETE_DIR:
            {
                break;
            }
            case COMMANDS::DELETE_FILE:
            {
                break;
            }

            default: break;
        }
    }

}
