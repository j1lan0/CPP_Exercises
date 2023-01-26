#pragma once
#include <string>
#include <iostream>
#include <PlushStore.hpp>
#include <Plush.hpp>
class Kid
{
public:
    Kid(const std::string &name, int money) : _name{name}, _money{money}
    {
    }

    std::string get_name() const {
        return _name;
    }
    
    int get_money() const {
        return _money;
    }
    std::optional<Plush> buy_plush(PlushStore &plushstore){
        std::optional<Plush> kid_plush = plushstore.buy(_money);
        if (kid_plush.has_value()){
            _money -= kid_plush.value().get_cost();
        }
        return kid_plush;
    }
    

private:
    std::string _name{};
    int _money = 0;
};

std::ostream& operator<<(std::ostream& stream,const Kid& kid){
    return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
}