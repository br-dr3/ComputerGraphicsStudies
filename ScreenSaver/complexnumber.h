#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <list>
#include  <cmath>

class ComplexNumber
{
    double realPart;
    double imaginaryPart;

public:
    ComplexNumber();
    ComplexNumber(double r, double i);

    ComplexNumber plus(ComplexNumber cn);
    ComplexNumber minus(ComplexNumber cn);
    ComplexNumber put(ComplexNumber cn);
    ComplexNumber times(double n);
    double getRealPart();
    double getImaginaryPart();
    void setRealPart(double);
    void setImaginaryPart(double);

    static ComplexNumber rotate(std::pair<ComplexNumber, ComplexNumber> p);
    static ComplexNumber rotate(ComplexNumber p);
};

#endif // COMPLEXNUMBER_H
