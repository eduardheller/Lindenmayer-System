#ifndef SRULES_H
#define SRULES_H

#include <string>
#include "rules.h"
class SRules : public Rules
{
public:
    SRules(char a, const std::string& b, float c) : Rules(a,b)  { chance = c; }
    void setChance(float c);
    float getChance() const;

private:
    float chance;
};

#endif // SRULES_H
