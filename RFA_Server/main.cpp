#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include <boost/asio.hpp>

#include "server.hpp"

using namespace std;

int main()
{
    try {


    Server serv;
    serv.start();



    }
    catch (std::exception& e)
    {
      std::cerr << "Exception: " << e.what() << "\n";
    }






    return 0;
}
