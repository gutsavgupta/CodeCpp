#include "wordTrans.h"

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream input_dictionary("dict.txt");
    std::ifstream input_statement("stat.txt");
    
    ch11::word_transformation::transform engine(input_dictionary, input_statement);

    std::cout << engine() << std::endl;
    return 0;
}

