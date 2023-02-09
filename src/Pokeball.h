#pragma once

#include "Pokemon.h"
// A ball where a Pokemon sleeps.
class Pokeball
{

    public:
        Pokeball()
    {    
    }
        bool empty() const{
            return _empty;
        }

        void store(PokemonPtr pokemon){
            _pokemon = std::move(pokemon);
            _empty = false;
        }

        const Pokemon& pokemon() const
        {
            return *_pokemon;
        }

    private:
        bool _empty = true; 
        PokemonPtr _pokemon;
};
