#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

std::map<std::string, std::string> trans;
std::vector<std::string> history;
std::set<std::string>
make_exit_commands()
{
    std::set<std::string> quit;
    quit.emplace("e");
    quit.emplace("quit");
    quit.emplace("q");
    quit.emplace("exit");
    return quit;
}


void add(std::string w1, std::string w2)
{
    trans.emplace(w1, w2);
    history.push_back("add " + w1 + " " + w2);
    std::cout << w1 << "=>" << w2 << std::endl;
}
bool run_command(std::istream& input){
    std::set<std::string> quit = make_exit_commands();
    auto command = std::string{};
    input >> command;
    if (command == "add")
    {
        auto w1 = std::string{};
        auto w2 = std::string{};
        input >> w1;
        input >> w2;
        add(w1, w2);
    }
    else if (command == "translate")
    {
        auto line = std::string{};
        getline(input, line);
        auto words = std::stringstream{};
        words << line;
        auto key = std::string{};
        while (words >> key)
        {
            const auto it = trans.find(key);
            std::cout << (it == trans.end() ? "???" : it->second) << std::endl;
        }
        std::cout << std::endl;
    }
    else if (command == "save")
    {
        auto name = std::string{};
        input >> name;
        auto file = std::ofstream{name};
        for (const auto &add : history)
        {
            file << add << "\n";
        }
    }
    else if (command == "print")
    {
        for (const auto &[key, value] : trans)
        {
            std::cout << key << " => " << value << std::endl;
        }
    }
    else if (command == "load")
    {
        auto name = std::string{};
        input >> name;
        auto file = std::ifstream{name};
        std::vector<std::string> tmp;
        while (!file.eof())
        {
            run_command(file);
        }

    }
    else if (command == "clear")
    {
        trans.clear();
        history.clear();

    }
    else if (command == "remove")
    {
        auto key = std::string{};
        input >> key;
        for (auto it = trans.begin(); it != trans.end();)
        {
            if (it->first == key || it->second == key)
            {
                std::cout << it->first << " " << it->second << std::endl;
                it = trans.erase(it);
            }
            else
            {
                ++it;
            }
        }
        history.push_back("remove " + key);
    }
    else if (quit.count(command) == 1)
    {
        return false;
    }
    return true;
}
int main()
{
    
    while (true)
    {
        if(!run_command(std::cin)){
            return 0;
        } 
    }

    return 0;
}