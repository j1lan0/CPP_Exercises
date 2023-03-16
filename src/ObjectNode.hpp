#pragma once
#include "Node.hpp"
#include <vector>
#include <map>
class ObjectNode : public Node
{
    private:
        std::map<std::string,NodePtr> _data;
    public:
        ObjectNode()
            : Node(NodeKind::OBJECT)
        {}
        std::string print() const override {
            std::string result = "{";
            bool first = true;
            for (auto const& el : _data){
                if(first){
                    first = false;
                }
                else
                {
                    result += ",";
                }
                result+='"' + el.first + "\":";
                result+=el.second->print();
            }
            result += "}";
            return result;
        } 
        static std::unique_ptr<ObjectNode>make_ptr(){
            return std::make_unique<ObjectNode>();
        }
         size_t child_count() const {
            return _data.size();
        }

        void insert(std::string key, NodePtr value) {
            _data.emplace(key,std::move(value));
        }
        size_t height() const override{
            if (this->child_count() == 0)
                return 0u;
            size_t result = 0;
            for (const auto& child : _data)
            {
                size_t child_height = child.second->height();
                if (child_height > result)
                result = child_height;
            }
            return result + 1;
        }
        size_t node_count() const override{
            size_t result = 1;
            for (const auto& child : _data)
            {
            result += child.second->node_count();
            }
            return result;
        }

        bool  has_child(const std::string& key){
            return _data.count(key);
        }
        Node* at(const std::string& key){
            if(has_child(key)){
                return _data.at(key).get();
            }
            else{
                return nullptr;
            }
        }

        
 

};