#pragma once
#include "Card.hpp"
enum class SpellType {
    Normal,Equip,Continuous,QuickPlay,Field
};

std::string to_string(SpellType card){
    switch(card){
        case SpellType::Normal : return "Normal"; break;
        case SpellType::Equip : return "Equip"; break;
        case SpellType::Continuous : return "Continuous"; break;
        case SpellType:: QuickPlay : return "Quick-Play"; break;
        case SpellType:: Field : return "Field"; break;
        default : return "";
    }
} 

class Spell : public Card
{
    public:
        Spell(std::string id,std::string name, SpellType type):
        Card {id,CardType::Spell},
        _type {type}
        {
            Card::set_name(name);
            Card::set_symbol(u8"魔");
        }

        SpellType get_spell_type() const {
            return _type;
        }

    private:
        SpellType _type;
};