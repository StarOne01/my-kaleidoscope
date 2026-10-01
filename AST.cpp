#include <string>

class ExprAST
{
public:
   virtual ~ExprAST() = default;
};

class NumExprAST: public ExprAST {
    double Val;

public:
    NumExprAST(double Val) : Val(Val) {}

};
