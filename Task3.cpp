#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::string Protocol(std::string s)
{
    std::string str;
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == ':' && s[i+1] == '/' && s[i+2] == '/')
        {
            for(int j = 0; j < i; ++j)
            {
                str += s[j];
            }
            break;
        }
    }

    if(str != "")
    {
        return str;
    }
    else
    {
        return "http";
    }
    
}

std::string Port(std::string s)
{
    std::string str;
    for(int i = 0; i < s.length(); ++i)
    {
        if(std::isdigit(s[i]))
        {
            if(s[i-1] == ':')
            {
                for(int j = i; j < s.length(); ++j)
                {
                    if(s[j] != '/')
                    {
                        str += s[j];
                    }
                    else
                    {
                        break;
                    }
                }
                break;
            }
        }
    }

    if(str != "")
    {
        return str;
    }
    else
    {
        return "80";    
    }
    
}

std::string Page(std::string s)
{
    std::string str;
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '/' && s[i+1] != '/' && s[i-1] != '/')
        {
            for(int j = i; j < s.length(); ++j)
            {
                str += s[j];
            }
            break;
        }
    }

    if(str != "")
    {
        return str;
    }
    else
    {
        return "/";
    }
    
}

std::string Host(std::string s)
{
    if(Port(s) == "80" && Page(s) == "/" && Protocol(s) == "http")
    {
        return s;
    }
    
    std::string str;
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '/' && s[i+1] == '/' && s[i-1] == ':')
        {
            for(int j = i+2; j < s.length(); ++j)
            {
                if(s[j] != ':' && s[j] != '/')
                {
                    str += s[j];
                }
                else
                {
                    break;
                }
            }
            break;
        }

    }
    
    return str;
}

int main()
{
    std::vector<std::string> urls, u;
    urls.push_back("http://mytona.com/index.html");
    urls.push_back("https://mytona.com:8080/");
    urls.push_back("mytona.com");
    urls.push_back("https://vk.com/feed");

    std::vector<std::string> protocol, host, port, page;

    for(int i = 0; i < urls.size(); ++i)
    {
        protocol.push_back(Protocol(urls[i]));
        port.push_back(Port(urls[i]));
        page.push_back(Page(urls[i]));
        host.push_back(Host(urls[i]));
        std::cout << "Protocol: " << protocol[i] << " " << "Host: " << host[i] << " " << "Prt: " << port[i] << " " << "Page: " << page[i] << std::endl;
    }

    return 0;
}