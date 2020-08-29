#pragma once
#include <string>
#include <iostream>
#include <string>

class Protection{
protected:
    virtual std::string string_protection(){
    };
    int int_protection();
    int int_protection(int from, int to);
};
