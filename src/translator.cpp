#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
map<string, string> trans;
vector<string> history;
set<std::string>
make_exit_commands()
{
    set<std::string> quit;
    quit.emplace("e");
    quit.emplace("quit");
    quit.emplace("q");
    quit.emplace("exit");
    return quit;
}

void add(string w1, string w2)
{
    trans.emplace(w1, w2);
    history.push_back("add " + w1 + " " + w2);
    cout << w1 << "=>" << w2 << endl;
}
int main()
{
    set<string> quit = make_exit_commands();
    while (true)
    {
        cout << "This is a translator, but it does nothing for now..." << endl;
        string tmp;
        auto command = string{};
        cin >> command;
        if (command == "add")
        {
            auto w1 = string{};
            auto w2 = string{};
            cin >> w1;
            cin >> w2;
            add(w1, w2);
        }
        else if (command == "translate")
        {
            auto line = std::string{};
            getline(cin, line);
            auto words = std::stringstream{};
            words << line;
            while (!words.eof())
            {
                auto key = string{};
                words >> key;
                const auto it = trans.find(key);
                std::cout << (it == trans.end() ? "???" : it->second) << endl;
            }
            std::cout << std::endl;
        }
        else if (command == "save")
        {
            auto name = string{};
            cin >> name;
            auto file = ofstream{name};
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
            auto name = string{};
            cin >> name;
            auto file = ifstream{name};
            vector<string> tmp;
            while (!file.eof())
            {
                auto key = string{};
                file >> key;
                if (key == "add")
                {
                    if (tmp.size() == 2)
                    {
                        add(tmp[0], tmp[1]);
                        while (!tmp.empty())
                        {
                            tmp.pop_back();
                        }
                    }
                    continue;
                }
                else if (tmp.size() < 2)
                {
                    tmp.emplace_back(key);
                }
            }
            if (tmp.size() == 2)
            {
                add(tmp[0], tmp[1]);
                while (!tmp.empty())
                {
                    tmp.pop_back();
                }
            }
        }
        else if (command == "clear")
        {
            trans.clear();
        }
        else if (command == "remove")
        {
            auto key = string{};
            cin >> key;
            for (auto it = trans.begin(); it != trans.end();)
            {
                if (it->first == key || it->second == key)
                {
                    cout << it->first << " " << it->second << endl;
                    it = trans.erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }
        else if (quit.count(tmp) == 1)
        {
            return 0;
        }
    }

    return 0;
}