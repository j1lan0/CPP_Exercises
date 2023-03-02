#pragma once
#include <vector>
#include "Pokemon.h"
#include "Pokeball.h"
#include <algorithm>
// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    PC()
    {
    }
    std::vector<PokemonPtr> &pokemons()
    {
        return _pokemons;
    }

    void transfer(PokemonPtr poke)
    {
        if (poke != nullptr)
        {
            _pokemons.push_back(std::move(poke));
        }
    }

    PokemonPtr steal(Trainer &trainer, const std::string &name)
    {
        auto it = std::find_if(_pokemons.begin(), _pokemons.end(), [&name](const auto &pokemon)
                               { return pokemon->name() == name; });
        if (it != _pokemons.end() && (*it)->trainer() == &trainer)
        {
            auto pokemon = std::move(*it);
            _pokemons.erase(it);
            return pokemon;
        }

        return nullptr;
    }

private:
    std::vector<PokemonPtr> _pokemons;
};