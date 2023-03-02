#pragma once

#include <string>
#include <iostream>
#include <memory>

// A creature that is cute and can fight other ones.
class Trainer;

class Pokemon
{
public:
    Pokemon(const std::string &name)
        : _name{name},
          _id{next_id++}
    {
    }

    Pokemon(const Pokemon &other)
        : _name{other._name},
          _id{other.next_id++}

    {
    }

    std::string name() const
    {
        return _name;
    }

    int id() const
    {
        return _id;
    }

    Pokemon &operator=(const Pokemon &other)
    {
        if (this != &other)
        {
            _name = other._name;
        }
        return *this;
    }

    const Trainer *trainer() const
    {
        return _trainer;
    }

    void set_trainer(const Trainer &trainer)
    {
        _trainer = &trainer;
    }

private:
    std::string _name;
    static inline int next_id = 0;
    int _id = 0;
    const Trainer *_trainer = nullptr;
};
using PokemonPtr = std::unique_ptr<Pokemon>;