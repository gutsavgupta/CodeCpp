#include "TextQuery.h"

#include <iostream>
#include <string>

int main()
{
    std::shared_ptr<DataBlock> dataBlock(new DataBlock);
    std::string filename, word;

    std::cin >> filename;
    TextParser textParser(filename, dataBlock);
    TextQuery  textQuery(dataBlock);

    // Parser the TextParser
    textParser.Parse();

    while(std::cin >> word && word!="q")
    {
        textQuery.Query(word);
    }

    return 0;
}
