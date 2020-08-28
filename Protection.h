#pragma once
#include <iostream>
#include <string>

class Protection{
protected:
    virtual std::string string_protection();
    virtual int int_protection();
    virtual int int_protection(int from, int to);
};
