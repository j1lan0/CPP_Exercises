#pragma once

#include "Node.hpp"
#include <vector>
class ArrayNode : public Node
{
    private:
        std::vector<NodePtr> _data;
    public:
        ArrayNode()
            : Node(NodeKind::ARRAY)
        {}
        std::string print() const override {
            std::string result = "[";
            for(unsigned i = 0;i < _data.size();i++){
                if(i > 0){
                    result += ",";
                }
                result += _data[i]->print();
            }
            result += "]";
            return result;
        }  
        static std::unique_ptr<ArrayNode>make_ptr(){
            return std::make_unique<ArrayNode>();
        }

        size_t child_count() const {
            return _data.size();
        }

        void push_back(NodePtr node ){
            _data.push_back(std::move(node));
        }

        size_t height() const override
        {
            if (this->child_count() == 0)
                return 0u;
            size_t result = 0;
            for (const auto& child : _data)
            {
                size_t child_height = child->height();
                if (child_height > result)
                    result = child_height;
            }
            return result + 1;
        }
        size_t node_count() const override{
            size_t result = 1;
            for (const auto& child : _data)
            {
                result += child->node_count();
            }
            return result;
        }
        std::vector<NodePtr>::iterator begin() { return _data.begin(); }
        std::vector<NodePtr>::iterator end() { return _data.end(); }


};