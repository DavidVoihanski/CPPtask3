#include "Unit.h"
#pragma once
#include <iostream>
#include<string>
namespace ariel{
    class PhysicalNumber{
        private:
        double value;
        ariel::Unit unit;
        bool areSameType(const PhysicalNumber& other) const;
        bool areSameScope(const PhysicalNumber &other) const; //km and m, tom and kg, not kg and km
        const PhysicalNumber convertNumber(const PhysicalNumber &other) const;
        double convertDistanceValue(int diff) const;
        double convertTimeValue(int diff) const;
        double convertMassValue(int diff) const;
        public:
        //std::string units[9] = {"KM","M","CM","HOUR","MIN","SEC","TON", "KG", "G"};
        PhysicalNumber(double num, Unit unit);
        ~PhysicalNumber();
        //getters and setters
        double getValue() const;
        Unit getUnit() const;
        void setValue(double x);
        void setUnit(Unit u);
        //arithmetics
        PhysicalNumber operator+(const PhysicalNumber& other) const;
        PhysicalNumber& operator+=(const PhysicalNumber& other);
        PhysicalNumber operator-(const PhysicalNumber& other) const;
        PhysicalNumber& operator-=(const PhysicalNumber& other);
        PhysicalNumber operator-() const;
        PhysicalNumber operator+() const;
        PhysicalNumber& operator--();
        PhysicalNumber operator--(int);
        PhysicalNumber& operator++();
        PhysicalNumber operator++(int);
        //compare
        bool operator>(const PhysicalNumber& other)const;
        bool operator<(const PhysicalNumber& other)const;
        bool operator==(const PhysicalNumber& other)const;
        bool operator<=(const PhysicalNumber& other)const;
        bool operator>=(const PhysicalNumber& other)const;
        bool operator!=(const PhysicalNumber& other)const;
        //input output
        friend std::ostream &operator<<(std::ostream &os, PhysicalNumber const &m);
        friend std::istream &operator>>(std::istream &is, PhysicalNumber const &m);
    };
}