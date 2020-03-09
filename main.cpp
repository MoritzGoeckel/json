#include <iostream>
#include "json.h"

using Node = JsonNode;

int main(){
    std::cout << "test" << std::endl;

    Node value("test");
    std::cout << value << std::endl;

    Node list({Node("test"), Node("test2")});
    std::cout << list << std::endl;

    Node dict({
            {"key1", Node("test")}, 
            {"key2", Node("test2")}
    });
    std::cout << dict << std::endl;

    Node complicated({
            {"key1", Node("test")}, 
            {"key2", {Node("test"), Node("test2")}},
            {"key3", Node({
                {"key1", Node("test")}, 
                {"key2", Node("test2")}
            })}
    });
    std::cout << complicated << std::endl;
}
