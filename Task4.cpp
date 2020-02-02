#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::string s;
    std::vector<std::string> str;
    std::ifstream input;
    std::ofstream output;
    input.open("input.txt");
    while(std::getline(input, s))
    {
        str.push_back(s);
    }
    
    input.close();
    output.open("input.txt");
    output.clear();
    
    s.clear();
    for(int i = 0; i < str.size(); ++i)
    {
        for(int j = 0; j < str[i].length(); ++j)
        {
            if(str[i][j] != ' ' && !std::isdigit(str[i][j]))
            {
                s += str[i][j];
            }
        }
        str[i].clear();
        str[i] = s;
        s.clear();
        output << str[i] << std::endl;
    }

    output.close();
    return 0;
}
