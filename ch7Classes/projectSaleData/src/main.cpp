#include <MySaleData.h>

#include <exception>
#include <iostream>
#include <string>

int main()
{
    sale::saleData s[2];
    
    try
    {
        // read first book in first object
        s[0].read(std::cin);

        // iterate till input available
        while(s[1].read(std::cin))
        {
            if (!s[0].combine(s[1]))
            {
                s[0].dump(std::cout);
                s[0] = s[1];
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
