/*
 * Program to transform the given statements
 * into an newly formed output statement, by replacing
 * words in the given statement with a mapping provided
 * by another file
 *
 * author: utsav
 * date: 22 sept 2019
 * fun(!)
 *
 */

#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

namespace ch11 {
namespace word_transformation {

class transform
{
    public:
        transform(std::ifstream& input_dictionary,
                  std::ifstream& input_statement)
            : _input_dictionary(input_dictionary),
              _input_statement(input_statement)
        {
           // build map
           this->init_map();
        }

        void init_map()
        {
            // clear the map
            _dictionary.clear();

            std::string _first_word;
            std::string _second_word;

            while (_input_dictionary)
            {
                std::getline(_input_dictionary, _first_word, ' ');
                std::getline(_input_dictionary, _second_word, '\n');

                // emplace the strings in the map
                _dictionary.emplace(_first_word, _second_word);
            }
        }

        std::string operator() ()
        {
            std::string result{};
            std::string line{};
            std::string word{};
            
            while (std::getline(_input_statement, line))
            {
                std::stringstream ss(line);
                while (ss >> word)
                {
                    if (_dictionary.find(word) != _dictionary.end())
                    {
                        word = _dictionary[word];
                    }
                    
                    result += word + ( !ss.eof() ? " " : "");
                }

                result.push_back( !_input_statement.eof() ? '\n' : '\0');
            }
            
            return result;
        }

    private:
        // data memebers
        std::ifstream& _input_dictionary;
        std::ifstream& _input_statement;

        std::unordered_map<std::string, std::string> _dictionary;
};

} // namespace word_transformation
} // namespace ch11
