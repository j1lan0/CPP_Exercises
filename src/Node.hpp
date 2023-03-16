#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
class Node;
using NodePtr = std::unique_ptr<Node>;
class IntLeaf;
class StringLeaf;
class ArrayNode;
class ObjectNode;
class Node : public InstanceCounter
{   
    private:
    const NodeKind _kind;

    protected:
        Node(NodeKind kind)
            : _kind(kind)
    {}
    public:
        virtual ~Node() = default;
        virtual std::string print() const = 0;
        virtual size_t height() const = 0;
        virtual size_t node_count() const = 0;
        NodeKind kind() const { return _kind; }
        IntLeaf* as_IntLeaf();
        StringLeaf* as_StringLeaf();
        ArrayNode* as_ArrayNode();
        ObjectNode* as_ObjectNode();
};