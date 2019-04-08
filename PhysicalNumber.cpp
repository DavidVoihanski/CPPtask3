#include "PhysicalNumber.h"
using namespace ariel;

PhysicalNumber::PhysicalNumber(double num, Unit unit){

}

void PhysicalNumber::operator++(){

}

void PhysicalNumber::operator--(){

}
const PhysicalNumber PhysicalNumber::operator+=(const PhysicalNumber &other) const{
    
}
const PhysicalNumber PhysicalNumber::operator-() const{

}

const PhysicalNumber PhysicalNumber::operator-=(const PhysicalNumber &other) const{

}
const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &other) const{

}
const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &other) const{

}
const bool PhysicalNumber::operator>(const PhysicalNumber& other)const{

}
const bool PhysicalNumber::operator<(const PhysicalNumber& other)const{
    
}
const bool PhysicalNumber::operator>=(const PhysicalNumber& other)const{
    
}
const bool PhysicalNumber::operator<=(const PhysicalNumber& other)const{
    
}
const bool PhysicalNumber::operator==(const PhysicalNumber& other)const{
    
}
const bool PhysicalNumber::operator!=(const PhysicalNumber& other)const{
    
}
std::ostream &ariel::operator<<(std::ostream &os, PhysicalNumber const &m){
    return os;
}
std::istream &ariel::operator>>(std::istream &is, PhysicalNumber const &m){
    return is;
}