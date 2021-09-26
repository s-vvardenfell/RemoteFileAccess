#include "client.hpp"

Client::Client() : fmptr_(nullptr)
{
    fmptr_ = std::make_unique<Filemanager>();
}

COMMANDS Client::getCommandFromServer()
{

}

void Client::downloadFile() const
{

}

void Client::uploadFile() const
{

}

void Client::sendData(const int fd, const std::string &data)
{

}

const std::string Client::recvData(const int sockfd)
{

}

void Client::sendErrorMsg(const int sockfd, const std::string &msg)
{

}

void Client::serverHandler()
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
                fmptr_->showCurrDirContent();
                break;
            }
            case COMMANDS::SHOW_CURRENT_DIR_INFO:
            {
                fmptr_->showCurrDirInfo();
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
                fmptr_->switchToRootDir();
                break;
            }
            case COMMANDS::SWITCH_TO_DIR:
            {
                break;
            }
            case COMMANDS::SWITCH_TO_PARENT_DIR:
            {
                fmptr_->switchToParentDir();
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
            case COMMANDS::COPY_FILE_OR_DIR:
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

