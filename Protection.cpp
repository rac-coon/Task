#include "Protection.h"

int Protection::int_protection(){
    int value;
    while (!(std::cin >> value) || (std::cin.peek() != '\n')){
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "incorrect integer value" << std::endl;
    }
    return value;
}

int Protection::int_protection(int from, int to){
    if (from > to){
        std::cout << "Protection error: To less then From" << std::endl; // debug
    }
    int range_value = 0;
    while((range_value < from) || (range_value > to)){
        std::cout << "Enter an integer value from " << from << " to " << to << std::endl;
        range_value = int_protection();
    }
    return range_value;
}

std::string string_protection(){
    std::string name;
    while (name.size() < 5){
        std::cin.clear();
        std::cin >> name;
        std::cout << "Incorrect value, try again" << std::endl;
    }
    return name;
}