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


class VarExprAST: public ExprAST {
    std::string name;

public:
    VarExprAST(std::string name) : name(std::move(name)) {}
    
};