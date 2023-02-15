#pragma once
#include "Card.hpp"
#include <string>
enum class Attribute {
    Dark,Divine,Earth,Fire,Light,Water,Wind
};

std::string to_symbol(Attribute monster){
    switch(monster){
        case Attribute::Dark : return u8"闇"; break;
        case Attribute::Divine : return u8"神"; break;
        case Attribute::Earth : return u8"地"; break;
        case Attribute::Fire : return u8"炎"; break;
        case Attribute::Light : return  u8"光"; break;
        case Attribute::Water : return u8"水"; break;
        case Attribute::Wind : return u8"風"; break;
        default : return "";
    }
} 

class Monster : public Card
{
    public:
        Monster(std::string id,std::string name,Attribute attribut,std::string description,int atk,int def)
        : Card {id,CardType::Monster},
        _attribut {attribut},
        _atk {atk},
        _def {def},
        _type_monster {description}
        {
            Card::set_name(name);
            Card::set_symbol(to_symbol(attribut));
        }

        Attribute get_attribute() const {
            return _attribut;
        }

        int get_atk() const{
            return _atk;
        }

        int get_def() const{
            return _def;
        }

        std::string get_description() const{
            return "[" +_type_monster +"]" + "\n" + Card::get_description() + "\n" + "ATK/"+ std::to_string(_atk) + " " + "DEF/" +std::to_string(_def);
        }



    private:
        Attribute _attribut;
        int _atk = 0;
        int _def = 0;
        std::string _type_monster = "";
};