#include "client.hpp"

Client::Client() : fmptr_(nullptr), sock_(io_context_), resolver_(io_context_)
{
    fmptr_ = std::make_unique<Filemanager>();

    boost::asio::connect(sock_, resolver_.resolve(host, port));
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

void Client::sendData(const std::string &data)
{
    std::cout << "Enter message: ";
    char request[max_length];
    std::cin.getline(request, max_length);
    request_length_ = std::strlen(request);
    boost::asio::write(sock_, boost::asio::buffer(request, request_length_));
}

const std::string Client::recvData()
{
    char reply[max_length];
    size_t reply_length = boost::asio::read(sock_, boost::asio::buffer(reply, request_length_));
    std::cout << "Reply is: ";
    std::cout.write(reply, reply_length);
    std::cout << "\n";
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

