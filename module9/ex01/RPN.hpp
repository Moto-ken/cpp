
#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <climits>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
   public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    long evaluate(const std::string& expr);

   private:
    std::stack<long, std::list<long> > _stack;
    static bool isOperator(const std::string& token);
    void applyOperator(char op);
};

#endif
