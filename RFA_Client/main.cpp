#include <iostream>
using namespace std;

#include "rfa_client.hpp"

//fs::exists

int main()
{

//    fs::path dir = "/home/chaginsergey/Downloads/test";

//    fs::recursive_directory_iterator iter(dir);

//    cout<<iter->path()<<endl;
//    ++iter;
//    cout<<iter->path()<<endl;


    RFA_Client client;

    client.showCurrDirInfo();
    client.showCurrDirContent();

//    client.deleteFile("page (copy).txt");

//    client.showCurrDirInfo();
//    client.showCurrDirContent();

    return 0;
}
