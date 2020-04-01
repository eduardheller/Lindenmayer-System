#ifndef SLSYSTEM_H
#define SLSYSTEM_H


#include <string>
#include <vector>
#include "srules.h"

class SLSystem
{
public:
    SLSystem(const std::string& axiom,const std::vector<SRules>& rules);
    void iterate(unsigned int steps = 1);
    std::string getAxiom() const;
    std::string getLSystem() const;
    std::vector<SRules> getRules() const;

private:
    unsigned int iteration;
    std::string current;
    std::vector<SRules> rules;
    std::string axiom;
    float random(float upperbounds);
};


#endif // SLSYSTEM_H
