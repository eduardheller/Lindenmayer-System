#include "lsystem.h"
#include <QDebug>


LSystem::LSystem(const std::string& ax,const std::vector<Rules>& rul) : axiom(ax), rules(rul){}


void LSystem::iterate(unsigned int steps)
{
    current.clear();
    current = axiom;
    for(unsigned int s = 0; s<steps; s++){
        std::string newResult;
        for(unsigned int i = 0; i<current.length(); i++)
        {
            char currLetter = current[i];
            if(currLetter==' ') continue;
            std::string substitution;
            substitution = currLetter;

            for(auto it = rules.begin(), end = rules.end(); it != end; ++it)
            {
                if(currLetter == it->getA())
                {
                    substitution = it->getB();
                    break;
                }
            }
            newResult.append(substitution);
        }
        current = newResult;
    }
}

std::string LSystem::getAxiom() const
{
    return axiom;
}

std::string LSystem::getLSystem() const
{
    return current;
}

std::vector<Rules> LSystem::getRules() const
{
    return rules;
}



