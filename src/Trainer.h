#pragma once
#include <memory>
#include <string>

#include "PC.h"
#include "Pokeball.h"
#include "Pokedex.h"
// A person that captures Pokemons and makes them fight.
class Trainer
{

public:
    Trainer(const std::string &name, PC &pc)
        : _name{name},
          _pc{pc}
    {
        for (int i = 0; i < 6; i++)
        {
            _balls.push_back(Pokeball());
        }
    }

    const std::vector<Pokeball> &pokeballs() const
    {
        return _balls;
    }

    std::string name() const
    {
        return _name;
    }

    void capture(PokemonPtr poke)
    {
        poke->set_trainer(*this);
        for (int i = 0; i < 6; i++)
        {
            if (_balls[i].empty())
            {
                _balls[i].store(std::move(poke));
                return;
            }
        }
        _pc.transfer(std::move(poke));
    }

    void store_in_pc(int poke)
    {
        _pc.transfer(std::move(_balls[poke].steal()));
    }

    void fetch_from_pc(const std::string name)
    {
        for (auto &pokeball : _balls)
        {
            if (pokeball.empty())
            {
                auto pokemon = _pc.steal(*this, name);
                if (pokemon != nullptr)
                {
                    pokeball.store(std::move(pokemon));
                }

                return;
            }
        }
    }

private:
    std::string _name{};
    PC &_pc;
    std::vector<Pokeball> _balls;
};