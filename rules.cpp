#include "rules.h"

Rules::Rules(char a, const std::string& b) : A(a), B(b)
{
}

void Rules::setA(char a)
{
    this->A = a;
}

void Rules::setB(const std::string& b)
{
    this->B = b;
}

char Rules::getA() const
{
    return this->A;
}

std::string Rules::getB() const
{
    return this->B;
}
