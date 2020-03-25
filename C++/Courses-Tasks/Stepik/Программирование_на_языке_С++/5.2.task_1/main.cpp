#include <iostream>

struct Rational {
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    Rational & operator+=(Rational rational)
    {
        (*this).add(rational);
        return *this;
    }
    Rational & operator-=(Rational rational)
    {
        (*this).sub(rational);
        return *this;
    }
    Rational & operator*=(Rational rational)
    {
        (*this).mul(rational);
        return *this;
    }
    Rational & operator/=(Rational rational)
    {
        (*this).div(rational);
        return *this;
    }
    Rational & operator-()
    {
        (*this).neg();
        return (*this);
    }

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double) denominator_;
    }


    int numerator_;
    int denominator_;
};


int main() {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3(5);
    r1 /= 2;
    std::cout << r1.numerator_ << ' ' << r1.denominator_;
}
