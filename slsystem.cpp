#include "slsystem.h"
#include <QDebug>
#include <cstdlib>
#include <QVector>
SLSystem::SLSystem(const std::string& ax,const std::vector<SRules>& rul) : axiom(ax), rules(rul)
{

}

void SLSystem::iterate(unsigned int steps)
{
    current.clear();
    current = axiom;
    float randoms[256];

	for (auto it = rules.begin(), end = rules.end(); it != end; ++it)
	{
		randoms[it->getA()] = 0;
	}

    for(auto it = rules.begin(), end = rules.end(); it != end; ++it)
    {
        randoms[it->getA()] += it->getChance();
    }

    for(unsigned int s = 0; s<steps; s++){
        std::string newResult;
        for(unsigned int i = 0; i<current.length(); i++)
        {
            char currLetter = current[i];
			std::string substitution;
			float maxrand;

            if(currLetter==' ') continue;
            maxrand = randoms[currLetter];
            
            substitution = currLetter;
            float rand = random(maxrand);
            float currRand = 0.0f;
            for(auto it = rules.begin(), end = rules.end(); it != end; ++it)
            {
                if(currLetter == it->getA())
                {
                    float chance = currRand + it->getChance();
                    if(currRand < rand){
                        if(rand <= chance){
                            substitution = it->getB();
                            break;
                        }
                    }
					currRand += it->getChance();
                }
                
            }
            newResult.append(substitution);
        }
        current = newResult;
    }
}

std::string SLSystem::getAxiom() const
{
    return axiom;
}

std::string SLSystem::getLSystem() const
{
    return current;
}

std::vector<SRules> SLSystem::getRules() const
{
    return rules;
}


float SLSystem::random(float upperbounds)
{
    return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/upperbounds));
}


