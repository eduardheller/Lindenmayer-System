#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <string>
#include <vector>
#include "rules.h"

class LSystem
{
public:
    LSystem(const std::string& axiom,const std::vector<Rules>& rules);
    void iterate(unsigned int steps = 1);
    std::string getAxiom() const;
    std::string getLSystem() const;
    std::vector<Rules> getRules() const;

private:
    unsigned int iteration;
    std::string current;
    std::vector<Rules> rules;
    std::string axiom;
};

#endif // LSYSTEM_H
