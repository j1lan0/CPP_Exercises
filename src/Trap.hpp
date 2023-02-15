#pragma once
#include "Card.hpp"
enum class TrapType {
    Normal,Continuous,Counter
};

std::string to_string(TrapType card){
    switch(card){
        case TrapType::Normal : return "Normal"; break;
        case TrapType::Continuous : return "Continuous"; break;
        case TrapType::Counter : return "Counter"; break;
        default : return "";
    }
} 

class Trap : public Card
{
    public:
        Trap(std::string id,std::string name, TrapType type):
        Card {id,CardType::Trap},
        _type {type}
        {
            Card::set_name(name);
            Card::set_symbol(u8"罠");
        }

        TrapType get_trap_type() const {
            return _type;
        }

    private:
        TrapType _type;
};