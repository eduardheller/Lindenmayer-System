#ifndef RULES_H
#define RULES_H

#include <string>

class Rules
{
public:
    Rules(char letter, const std::string& production);
    void setA(char);
    void setB(const std::string&);
    char getA() const;
    std::string getB() const;

private:
    char A;
    std::string B;
};

#endif // RULES_H
