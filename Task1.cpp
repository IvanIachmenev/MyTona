#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string str, s;
    char a;

    std::cin >> str;
    std::cin >> a;
    
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] != a)
        {
            s += str[i];
        }
        else
        {
            std::cout << s << std::endl;
            s.clear();
        }
        
    }
    if(s.length() > 1)
    {
        std::cout << s << std::endl;
    }
    return 0;
}
