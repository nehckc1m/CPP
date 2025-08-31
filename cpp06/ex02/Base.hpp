#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstddef>

class Base{
    public:
        virtual ~Base();
    private:


};
Base * generate();
void identify(Base* p);
void identify(Base& p);