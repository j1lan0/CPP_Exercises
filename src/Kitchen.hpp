#pragma once
#include "../lib/Unit.hpp"
#include <string>
#include <set>

struct UnitCompare{

    using is_transparent = bool;
    bool operator()(const Unit& u1, const Unit& u2) const { return u1.name < u2.name; }
    bool operator()(const Unit& unit, const std::string& name) const { return unit.name < name; }
    bool operator()(const std::string& name, const Unit& unit) const { return name < unit.name; }
};

class Kitchen
{
    public:
        const Unit& register_unit(Unit unit){
           return *_units.emplace(unit).first; 
        }

        const Unit* find_unit(const std::string& name) const {
            const auto it = _units.find(name);
            return it != _units.end() ? &(*it) : nullptr;
        }




    private:
        std::set<Unit,UnitCompare> _units;
};

