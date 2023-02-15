#pragma once
#include <string>
enum class CardType {
    Monster,Spell,Trap
};

std::string to_string(CardType card){
    switch(card){
        case CardType::Monster : return "Monster"; break;
        case CardType::Spell : return "Spell"; break;
        case CardType::Trap : return "Trap"; break;
        default : return "";
    }
} 
class Card{
    protected: 
        std::string _symbol = "";
    public:
        Card(std::string id,CardType card):
        _id {id},
        _cardType { card }
        {

        }
        void set_symbol(std::string symbol){
            _symbol = symbol;
        }
        std::string get_symbol() const{
            return _symbol;
        }
        std::string get_id() const{
            return _id;
        }
        CardType get_type() const{
            return _cardType;
        }

        std::string get_name() const{
            return _name;
        }
        std::string get_description() const{
            return _description;
        } 

        void set_name(std::string name){
            _name = name;
        }
        void set_description(std::string description){
            _description = description;
        }

    private:
        std::string _id = "";
        CardType _cardType;
        std::string _name = "";
        std::string _description = "";
};

