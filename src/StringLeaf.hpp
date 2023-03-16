#pragma once
#include "Leaf.hpp"
#include "Node.hpp"
#include <string>
class StringLeaf : public Leaf
{
    public:
        StringLeaf(std::string value)
        :Leaf {NodeKind::STRING}
        ,_value {value}
        {

        }

        const std::string& data() const { return _value;}

        std::string print() const override { return "\"" +_value + "\"";};
        static std::unique_ptr<StringLeaf>make_ptr(std::string data){
            return std::make_unique<StringLeaf>(data);
        }

    private:
        std::string _value;
};