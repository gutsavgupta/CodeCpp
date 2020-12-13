#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string word;
    std::vector<std::string> words;

    auto compareLength = [](const std::string& str) {
        return (str.length() >= 1 && str.length() <= 10);
    };

    auto printString = [](const std::string& str) { std::cout << str << ","; };

    while (std::getline(std::cin, word, ' ')) {
        compareLength(word) && std::all_of(word.cbegin(), word.cend(), isalnum)
            ? (void)(words.push_back(word))
            : (void)0;
    }

    std::for_each(words.cbegin(), words.cend(), printString);
    std::cout << std::endl;
    return 0;
}
