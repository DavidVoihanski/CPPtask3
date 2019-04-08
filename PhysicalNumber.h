#include "Unit.h"
#pragma once
#include <iostream>
namespace ariel{
    class PhysicalNumber{
        public:
        PhysicalNumber(int num, Unit unit);
        //arithmetics
        const PhysicalNumber operator+(const PhysicalNumber& other) const;
        const PhysicalNumber operator+=(const PhysicalNumber& other) const;
        const PhysicalNumber operator-(const PhysicalNumber& other) const;
        const PhysicalNumber operator-=(const PhysicalNumber& other) const;
        const PhysicalNumber operator-() const;
        void operator--();
        void operator++();

        //compare
        const bool operator>(const PhysicalNumber& other)const;
        const bool operator<(const PhysicalNumber& other)const;
        const bool operator==(const PhysicalNumber& other)const;
        const bool operator<=(const PhysicalNumber& other)const;
        const bool operator>=(const PhysicalNumber& other)const;
        const bool operator!=(const PhysicalNumber& other)const;
        //input output
        friend std::ostream &operator<<(std::ostream &os, PhysicalNumber const &m);
        friend std::istream &operator>>(std::istream &is, PhysicalNumber const &m);
    };
}