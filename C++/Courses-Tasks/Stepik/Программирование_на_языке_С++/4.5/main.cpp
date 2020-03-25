#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * binary) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual ~Expression() {}
    virtual void visit(Visitor * visitor) const  = 0;
};

struct Number : Expression
{
    Number(double value)
        : value(value) {}

    double get_value() const { return value; }
    void visit(Visitor * visitor) const { visitor->visitNumber(this); }
private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right){}
    ~BinaryOperation(){
        delete right;
        delete left;
    }

    Expression const * get_left()  const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const * left;
    char op;
    Expression const * right;
};

struct PrintVisitor : Visitor {

    void visitNumber(Number const * number)
    {
        std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        std::cout << '(';
        bop->get_left()->visit(this);
        std::cout << " " << bop->get_op() << " ";
        bop->get_right()->visit(this);
        std::cout << ')';
    }
};

int main()
{
    const Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    const Expression * expr = new BinaryOperation(new Number(3), '+', sube);
    PrintVisitor visitor;
    expr->visit(&visitor);
}
