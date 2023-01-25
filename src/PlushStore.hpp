#pragma once
#include <string>

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
        return invest + _experience;
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
};