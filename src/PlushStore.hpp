#pragma once
#include <string>
#include <optional>
#include <Plush.hpp>
#include <vector>
#include <iostream>

class PlushStore
{
public:
    PlushStore(const std::string &name) : _name{name}
    {
    }
    const std::string &get_name() const
    {
        return _name;
    }
    int get_wealth_amount() const
    {
        return _money;
    }
    int get_stock_size() const
    {
        return _stock;
    }
    void loan(int cost)
    {
        _money += cost;
        _debt += cost * 1.1;
    }
    int get_debt_amount() const
    {
        return _debt;
    }
    int make_plush(int cost)
    {
        int invest = 0;
        if (_money < cost)
        {
            invest = _money;
        }
        invest = cost;
        if (_money == 0)
        {
            return 0;
        }
        _money -= cost;
        if (_money <= 0)
        {
            _money = 0;
        }
        _stock += 1;
        _experience += 1;
        
        _plush.push_back({invest + _experience});
        return invest + _experience;
    }
    std::optional<Plush> buy(int money){
        if(get_stock_size() == 0){
            return {};
        }
        Plush min = _plush[0];
        int indice = 0;
        for (int i = 0; i < get_stock_size(); i++)
            {   
                if(_plush[i].get_cost() < min.get_cost()){
                    min = _plush[i];
                    indice = i;
                }
            }

        if(min.get_cost() > money){
            return {};
        }
        _stock -= 1;
        _money += min.get_cost();
        _plush.erase(_plush.begin() + indice);
        return min;
    }

    int get_experience() const
    {
        return _experience;
    }

private:
    std::string _name{};
    int _money = 0;
    int _stock = 0;
    int _debt = 0;
    int _experience = 0;
    std::vector<Plush> _plush = {}; 
};