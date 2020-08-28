#pragma once
#include <iostream>
#include <string>

class Protection{
protected:
    // EDIT: virtual functions have no override in child classes. There is no reason to put a virtual modifier here.
    virtual std::string string_protection();
    virtual int int_protection();
    virtual int int_protection(int from, int to);
};
