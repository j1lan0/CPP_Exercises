#pragma once

#include <string>
#include <iostream>
#include <memory>


// A creature that is cute and can fight other ones.
class Pokemon
{
    public:
        Pokemon(const std::string &name):
        _name {name},
        _id {_new_id++}
        {   
        }

        Pokemon(const Pokemon &other):
        _name {other._name},
        _id {other._new_id++}
        {   
        }

        const std::string &name() const{
            return _name;
        }

        int id() const {
            return _id;
        }

        Pokemon& operator=(const Pokemon& other)
        {
            if (this != &other)
            {   
                _name = other._name;
            }

            return *this;
        }



    private:
    std::string _name;
    int _id;
    static inline int _new_id = 0;
};

using PokemonPtr = std::unique_ptr<Pokemon>;