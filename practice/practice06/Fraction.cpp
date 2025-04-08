#include "Fraction.h"
#include <iostream>
Fraction::Fraction() {
    num = 0;
    den = 1;
}
Fraction::Fraction(int fNum, int fDen) {
    num = fNum;
    if (fDen == 0) {
        den = 1;
    }
    else {
        den = fDen;
    }
}
Fraction::~Fraction() {
    delete &num;
    delete &den;
}
int Fraction::getNumerator() const {
    return num;
}
int Fraction::getDenominator() const {
    return den;
}
void Fraction::setNumerator(int n) {
    num = n;
}
void Fraction::setDenominator(int d) {
    if (d == 0) {
        std::cout << "not a valid denominator" << std::endl;
    }
    else {
        den = d;
    }
}
void Fraction::simplify() {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");

    // Compute GCD using Euclidean algorithm
    int a = num, b = den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a; // GCD is stored in 'a' after loop exits

    // Simplify the fraction
    num /= gcd;
    den /= gcd;
}
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int n = lhs.getNumerator() * rhs.getDenominator() + rhs.getNumerator() * lhs.getDenominator();
    int d = lhs.getDenominator() * rhs.getDenominator();
    return Fraction(n, d);
}
Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int n = lhs.getNumerator() * rhs.getDenominator() - rhs.getNumerator() * lhs.getDenominator();
    int d = lhs.getDenominator() * rhs.getDenominator();
    return Fraction(n, d);
}
Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    int n = lhs.getNumerator() * rhs.getNumerator();
    int d = lhs.getDenominator() * rhs.getDenominator();
    return Fraction(n, d);
}
Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (lhs.getDenominator() == 0 || rhs.getDenominator() == 0) {
        std::cout << "Invalid Fraction." << std::endl;
        return lhs;
    }
    else {
        int n = lhs.getNumerator() * rhs.getDenominator();
        int d = lhs.getDenominator() * rhs.getNumerator();
        return Fraction(n, d);
    }
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj) {
    os << obj.getNumerator() << "/" << obj.getDenominator();
    return os;
}
