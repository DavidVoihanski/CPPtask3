#include "PhysicalNumber.h"
using namespace ariel;

PhysicalNumber::PhysicalNumber(double num, ariel::Unit unit){
    this->value = num;
    this->unit = unit;
}

void PhysicalNumber::operator++(){

}

void PhysicalNumber::operator--(){

}
const PhysicalNumber PhysicalNumber::operator+=(const PhysicalNumber &other) const{
    PhysicalNumber temp(1,ariel::Unit::KM);
    return temp;
}
const PhysicalNumber PhysicalNumber::operator-() const{
    PhysicalNumber temp(1,ariel::Unit::KM);
    return temp;
}

const PhysicalNumber PhysicalNumber::operator-=(const PhysicalNumber &other) const{
    PhysicalNumber temp(1,ariel::Unit::KM);
    return temp;
}
const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &other) const{
    PhysicalNumber temp(1,ariel::Unit::KM);
    return temp;
}
const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &other) const{
    PhysicalNumber temp(1,ariel::Unit::KM);
    return temp;
}
const bool PhysicalNumber::operator>(const PhysicalNumber& other)const{
    return false;
}
const bool PhysicalNumber::operator<(const PhysicalNumber& other)const{
    return false;
}
const bool PhysicalNumber::operator>=(const PhysicalNumber& other)const{
    return false;
}
const bool PhysicalNumber::operator<=(const PhysicalNumber& other)const{
    return false;
}
const bool PhysicalNumber::operator==(const PhysicalNumber& other)const{
    return false;
}
const bool PhysicalNumber::operator!=(const PhysicalNumber& other)const{
    return false;
}
std::ostream &ariel::operator<<(std::ostream &os, PhysicalNumber const &m){
    return os;
}
std::istream &ariel::operator>>(std::istream &is, PhysicalNumber const &m){
    return is;
}