#include "MixedFraction.h"
#include <iostream>
MixedFraction::MixedFraction(const Fraction& frac) : Fraction(frac) {}
MixedFraction::~MixedFraction() {}
std::ostream& operator<<(std::ostream& os, const MixedFraction& mf) {
    int num = mf.getNumerator();
    int den = mf.getDenominator();

    int whole = num / den;
    int remainder = num % den;

    if (remainder == 0) {
        os << whole;
    } else if (whole == 0) {
        os << remainder << "/" << den;
    } else {
        os << whole << " " << remainder << "/" << den;
    }
    return os;
}