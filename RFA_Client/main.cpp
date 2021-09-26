#include <iostream>

#include "client.hpp"

using namespace std;

int main()
{
    try
    {
        Client cl;
        cl.sendData("");
        cl.recvData();

    }
    catch (std::exception& e)
    {
      std::cerr << "Exception: " << e.what() << "\n";
    }

  return 0;
}
