#pragma once
#include "Fraction.h"

class MixedFraction : public Fraction {
public:
    ~MixedFraction();
    MixedFraction(const Fraction& frac);
    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mf);
};