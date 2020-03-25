#include <iostream>

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

struct Number : Expression
{
    double evaluate() const { return value; }

    Number(double value)
        : value(value)
    {}
private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right){}

    double evaluate() const{
        switch(op){
        case '*': return left->evaluate() * right->evaluate();
        case '+': return left->evaluate() + right->evaluate();
        case '-': return left->evaluate() - right->evaluate();
        case '/': return left->evaluate() / right->evaluate();
        }
    }

    ~BinaryOperation(){
        delete right;
        delete left;
    }

private:
    Expression const * left;
    char op;
    Expression const * right;
};
struct ScopedPtr
{
    explicit ScopedPtr(Expression *ptr = 0)
        : ptr_(ptr) {}
    ~ScopedPtr() { delete ptr; }
private:
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};
int main()
{
    std::cout << NULL << endl;
    return 0;
}
