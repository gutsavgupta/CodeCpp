/* Text query program
 * aims to have two classes, TextParser and TextQueries
 * Since We want to share data between them, we will have 
 * another class DataBlock for storing the parsed d
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <cctype>
#include <algorithm>
#include <unordered_map>

struct DataBlock
{
    // data struct for storing each line
    std::vector<std::string> m_lines;

    // data struct for storing words and file line mapping
    std::unordered_map<std::string, std::vector<int>> m_wordDict;
    std::unordered_map<std::string, int> m_wordCount;
};

class TextParser
{
public:
    // constructors
    TextParser(const std::string& _fileName)
        : m_fileName(_fileName)
        , m_dataBlock(new DataBlock())
    {
    }
    
    TextParser(const std::string& _fileName, std::shared_ptr<DataBlock> _dataBlock)
        : m_fileName(_fileName)
        , m_dataBlock(_dataBlock)
    {
    }

    // accesors
    auto& GetFileName() const {return m_fileName;}
    auto& GetDataBlock() const {return m_dataBlock;}

    void Parse()
    {
        if (m_isParsed) return;

        std::ifstream file(m_fileName.c_str());
        std::string line;
        int lineCount{0};

        while(getline(file,line))
        {
            m_dataBlock->m_lines.push_back(line);

            std::string word;
            std::istringstream ss(line);

            while(getline(ss,word,' '))
            {
                word.erase(std::remove_if(word.begin(), word.end(), ispunct),word.end());

                auto& listLine = m_dataBlock->m_wordDict[word];
                auto& wordCount  = m_dataBlock->m_wordCount;
                
                if (not wordCount.emplace(word,1).second)
                {
                    ++wordCount[word];
                }

                if (listLine.empty() || listLine.back() != lineCount)
                {
                    listLine.push_back(lineCount);
                }
            }

            // increment lineCount
            ++lineCount;
        }
    }
        
private:
    std::shared_ptr<DataBlock> m_dataBlock;
    std::string                m_fileName;

    bool m_isParsed{false};
};

class TextQuery
{
public:
    // constructor
    TextQuery(const std::shared_ptr<DataBlock> _dataBlock)
        : m_dataBlock(_dataBlock)
    {
    }

    void Query(const std::string& queryWord, std::ostream& out = std::cout)
    {
        if (not m_dataBlock)
        {
            out << __func__ << ":: Invalid, data corruption" << std::endl;
            return;
        }

        // search in map
        auto& wordDict  = m_dataBlock->m_wordDict;
        auto& wordCount = m_dataBlock->m_wordCount;
        auto& linesVec  = m_dataBlock->m_lines;

        if (wordDict.find(queryWord) == wordDict.end() 
            || wordCount.find(queryWord) == wordCount.end())
        {
            out << __func__ << ":: word[" << queryWord <<"] not found, data dictionary" << std::endl;
            return;
        }

        auto count = wordCount[queryWord];
        out << queryWord << " count is:" << count << std::endl;

        for(auto& lineNum : wordDict[queryWord])
        {
            out << "line " << (lineNum) << " " << linesVec.at(lineNum) << std::endl; 
        }
    }

private:
    const std::shared_ptr<DataBlock> m_dataBlock;
};
