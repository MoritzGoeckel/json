#include <iostream>
#include <map>
#include <vector>
#include <string>

class JsonNode{
    public:
    enum class NodeType{
        DICT,
        LIST,
        VALUE
    };

    NodeType _type;
    std::map<std::string, JsonNode> _dict;
    std::vector<JsonNode> _list;
    std::string _value;

    JsonNode(const std::string& value) : _type(NodeType::VALUE), _value(value){}
    JsonNode(std::initializer_list<JsonNode> nodes) : _type(NodeType::LIST), _list(nodes){}
    JsonNode(const std::map<std::string, JsonNode>& value) : _type(NodeType::DICT), _dict(value){}
};

std::ostream& operator<<(std::ostream& os, const JsonNode& node){
    if(node._type == JsonNode::NodeType::VALUE){
        os << '"' << node._value << '"';
    }
    else if(node._type == JsonNode::NodeType::LIST){
        os << "[";
        for(auto i = node._list.begin(); i != node._list.end(); ++i){
            os << *i;
            if(std::next(i) != node._list.end()){ os << ", "; }
        }
        os << "]";
    }
    else if(node._type == JsonNode::NodeType::DICT){
        os << "{";
        for(auto i = node._dict.begin(); i != node._dict.end(); ++i){
            os << '"' << i->first << "\":" << i->second;
            if(std::next(i) != node._dict.end()){ os << ", "; }
        }
        os << "}";
    }
    return os;
}
