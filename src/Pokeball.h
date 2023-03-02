#pragma once

#include "Pokemon.h"
// A ball where a Pokemon sleeps.
#include <vector>
#include <memory>
class Pokeball
{
public:
    Pokeball()
    {
    }
    bool empty() const
    {
        return _poke == nullptr;
    }

    void store(PokemonPtr pokemon)
    {
        _poke = std::move(pokemon);
    }

    Pokemon &pokemon() const
    {
        return *_poke;
    }

    PokemonPtr steal()
    {
        return std::move(_poke);
    }

private:
    PokemonPtr _poke;
};