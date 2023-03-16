#pragma once
#include "Leaf.hpp"
#include "Node.hpp"
class IntLeaf : public Leaf
{
    public:
        IntLeaf(int value)
        :Leaf { NodeKind::INT }
        ,_value {value}
        
            {

            }
        inline const int& data() const { return _value; }

        std::string print() const override { return std::to_string(_value); }
        
        static std::unique_ptr<IntLeaf>make_ptr(int data){
            return std::make_unique<IntLeaf>(data);
        }
    private:
        int _value = 0;

};