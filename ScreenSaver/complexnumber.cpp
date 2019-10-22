#include "complexnumber.h"
#include<cmath>

ComplexNumber::ComplexNumber() {
    realPart = 0;
    imaginaryPart = 0;
}

ComplexNumber::ComplexNumber(double r, double i) {
    realPart = r;
    imaginaryPart = i;
}


ComplexNumber ComplexNumber::plus(ComplexNumber cn) {
    return ComplexNumber (getRealPart() + cn.getRealPart(),
                          getImaginaryPart() + cn.getImaginaryPart());
}

ComplexNumber ComplexNumber::times(double n) {
    return ComplexNumber(n*getRealPart(), n*getImaginaryPart());
}

ComplexNumber ComplexNumber::put(ComplexNumber cn) {
    return plus(cn);
}

ComplexNumber ComplexNumber::minus(ComplexNumber cn){
    return plus(ComplexNumber(-cn.getRealPart(), -cn.getImaginaryPart()));
}

double ComplexNumber::getRealPart() {
    return realPart;
}

double ComplexNumber::getImaginaryPart() {
    return imaginaryPart;
}


void ComplexNumber::setRealPart(double rp) {
    realPart = rp;
}

void ComplexNumber::setImaginaryPart(double ip) {
    imaginaryPart = ip;
}

ComplexNumber ComplexNumber::rotate(ComplexNumber c) {
    int xx = (int) (c.getRealPart()*cos(M_PI/2) + c.getImaginaryPart()*sin(M_PI/2));
    int yy = (int) (-c.getRealPart()*sin(M_PI/2) - c.getImaginaryPart()*cos(M_PI/2));

    return ComplexNumber(xx, yy);
}

ComplexNumber ComplexNumber::rotate(std::pair<ComplexNumber, ComplexNumber> c) {
    return ComplexNumber::rotate(c.second.minus(c.first));
}
