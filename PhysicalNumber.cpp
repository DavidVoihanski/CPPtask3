#include "PhysicalNumber.h"
using namespace ariel;

PhysicalNumber::PhysicalNumber(double num, ariel::Unit unit){
    this->value = num;
    this->unit = unit;
}
PhysicalNumber::~PhysicalNumber(){
    
}
std::string PhysicalNumber::toString() const{
    double value = this->getValue();
    int arrayIndex = (int)this->getUnit();
    std::string unitString = this->units[arrayIndex];
    std::string retString = std::to_string(value) + '[' + unitString + ']';
    return retString;
}
//getters and setters
Unit PhysicalNumber::getUnit() const{
    return this->unit;
}
double PhysicalNumber::getValue() const{
    return this->value;
}
void PhysicalNumber::setValue(double x){
    this->value = x;
}
void PhysicalNumber::setUnit(Unit u){
    this->unit = u;
}
//prefix
PhysicalNumber& PhysicalNumber::operator++(){
    double temp = this->getValue();
    temp++;
    this->setValue(temp);
    return *this;
}
//postfix
PhysicalNumber PhysicalNumber::operator++(int){
    double temp = this->getValue();
    PhysicalNumber returned(temp, this->getUnit());
    temp++;
    this->setValue(temp);
    return returned;
}
//prefix
PhysicalNumber& PhysicalNumber::operator--(){
    double temp = this->getValue();
    temp--;
    this->setValue(temp);
    return *this;
}
//postfix
PhysicalNumber PhysicalNumber::operator--(int){
    double newValue = this->getValue();
    PhysicalNumber returned(newValue, this->getUnit());
    newValue--;
    this->setValue(newValue);
    return returned;
}
//continue here********#@!$#@%@$%$%
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &other){
    if(!areSameType(other)) throw std::invalid_argument("types not compatible!");
    PhysicalNumber calcTemp = this->convertNumber(other);
    double newValue = this->getValue() + calcTemp.getValue();
    this->setValue(newValue);
    return *this;
}

PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber &other){
    if(!areSameType(other)) throw std::invalid_argument("types not compatible!");
    PhysicalNumber calcTemp = this->convertNumber(other);
    double newValue = this->getValue() - calcTemp.getValue();
    this->setValue(newValue);
    return *this;
}

PhysicalNumber PhysicalNumber::operator-() const{
    double newValue = -this->getValue();
    PhysicalNumber toReturn(newValue, this->getUnit());
    return toReturn;
}
PhysicalNumber PhysicalNumber::operator+() const{
    double newValue = this->getValue();
    PhysicalNumber toReturn(newValue, this->getUnit());
    return toReturn;
}

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &other) const{
    if(!areSameType(other)) throw std::invalid_argument("types not compatible!");
    PhysicalNumber toReturn = this->convertNumber(other);
    double newValue = this->getValue() + toReturn.getValue();
    toReturn.setValue(newValue);
    return toReturn;
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &other) const{
    if(!areSameType(other)) throw std::invalid_argument("types not compatible!");
    PhysicalNumber toReturn = this->convertNumber(other);
    double newValue = this->getValue() - toReturn.getValue();
    toReturn.setValue(newValue);
    return toReturn;
}

bool PhysicalNumber::operator>(const PhysicalNumber& other)const{
    if(!areSameType(other)) throw std::invalid_argument("types not compatible!");
    PhysicalNumber calcTemp = this->convertNumber(other);
    double thisValue = this->getValue();
    double otherValue = calcTemp.getValue();
    return thisValue > otherValue;
}

bool PhysicalNumber::operator<(const PhysicalNumber& other)const{
    if(!areSameType(other)) throw std::invalid_argument("types not compatible!");
    PhysicalNumber calcTemp = this->convertNumber(other);
    double thisValue = this->getValue();
    double otherValue = calcTemp.getValue();
    return thisValue < otherValue;
}

bool PhysicalNumber::operator>=(const PhysicalNumber& other)const{
    if(!areSameType(other)) throw std::invalid_argument("types not compatible!");
    PhysicalNumber calcTemp = this->convertNumber(other);
    double thisValue = this->getValue();
    double otherValue = calcTemp.getValue();
    return thisValue >= otherValue;
}

bool PhysicalNumber::operator<=(const PhysicalNumber& other)const{
    if(!areSameType(other)) throw std::invalid_argument("types not compatible!");
    PhysicalNumber calcTemp = this->convertNumber(other);
    double thisValue = this->getValue();
    double otherValue = calcTemp.getValue();
    return thisValue <= otherValue;
}

bool PhysicalNumber::operator==(const PhysicalNumber& other)const{
    if(!areSameType(other)) throw std::invalid_argument("types not compatible!");
    PhysicalNumber calcTemp = this->convertNumber(other);
    double thisValue = this->getValue();
    double otherValue = calcTemp.getValue();
    return thisValue == otherValue;
}

bool PhysicalNumber::operator!=(const PhysicalNumber& other)const{
    if(!areSameType(other)) throw std::invalid_argument("types not compatible!");
    PhysicalNumber calcTemp = this->convertNumber(other);
    double thisValue = this->getValue();
    double otherValue = calcTemp.getValue();
    return thisValue != otherValue;
}

//io*****************************************************************************************************************
std::ostream &ariel::operator<<(std::ostream &os, PhysicalNumber const &m){

    std::string unitString = m.units[(int)m.getUnit()];
    return os << m.getValue() << "[" <<unitString << "]";
}

std::istream &ariel::operator>>(std::istream &is, PhysicalNumber &m){
    std::string temp;
    is >> temp;
    const std::string input = temp;
    std::string unitString = m.parseUnit(input);
    double value = m.parseValue(input);
    int unitIndex = m.findUnitIndex(unitString);
    Unit unit = (Unit)unitIndex;
    m.setValue(value);
    m.setUnit(unit);
    return is;
}

//private functions**************************************************************************************************

bool PhysicalNumber::areSameType(const PhysicalNumber &other) const{
    Unit thisUnit = this->getUnit();
    Unit otherUnit = other.getUnit();
    if(thisUnit == Unit::KM || thisUnit == Unit::M || thisUnit == Unit::CM){
        return (otherUnit == Unit::KM || otherUnit == Unit::M || otherUnit == Unit::CM);
    }
    else if(thisUnit == Unit::HOUR || thisUnit == Unit::MIN || thisUnit == Unit::SEC){
        return (otherUnit == Unit::HOUR || otherUnit == Unit::MIN || otherUnit == Unit::SEC);
    }
    else if(thisUnit == Unit::TON || thisUnit == Unit::KG || thisUnit == Unit::G){
        return (otherUnit == Unit::TON || otherUnit == Unit::KG || otherUnit == Unit::G);
    }
    //we covered every possible option, we mustn't get here
    std::cout << "got here, not good" << std::endl;
    return false;
}
//assumes same type, i.e km and m
bool PhysicalNumber::areSameScope(const PhysicalNumber &other) const{
    Unit thisUnit = this->getUnit();
    Unit otherUnit = other.getUnit();
    return thisUnit == otherUnit;
}

//converts other to be the same scope as this
const PhysicalNumber PhysicalNumber::convertNumber(const PhysicalNumber &other) const{
    Unit thisUnit = this->getUnit();
    Unit otherUnit = other.getUnit();
    int thisInt = (int)thisUnit;
    int otherInt = (int)otherUnit;
    int diff = otherInt - thisInt; //shows us which way sould we 'go' and how many steps should range from -2 to 2
    double newValue;
    if(this->areSameScope(other)) return other; //if there is no need to convert
    if(thisUnit == Unit::KM || thisUnit == Unit::M || thisUnit == Unit::CM){
        newValue = other.convertDistanceValue(diff);
    }
    else if(thisUnit == Unit::HOUR || thisUnit == Unit::MIN || thisUnit == Unit::SEC){
        newValue = other.convertTimeValue(diff);
    }
    else if(thisUnit == Unit::TON || thisUnit == Unit::KG || thisUnit == Unit::G){
        newValue = other.convertMassValue(diff);
    }
    PhysicalNumber toReturn(newValue, thisUnit);
    return toReturn;
}
double PhysicalNumber::convertDistanceValue(int diff) const{
    double newValue = this->getValue();
    Unit unit = this->getUnit();
    switch (diff)
        {
            case -2://this is cm and other is km
                newValue = newValue*1000*100;
                break;

            case -1:
                if(unit == Unit::KM){
                    newValue = newValue*1000;
                    break;
                }
                else{
                    newValue = newValue*100;
                    break;
                }

            case 1:
                if(unit == Unit::M){
                    newValue = newValue/1000;
                }
                else newValue = newValue/100;
                break;

            case 2:
                newValue = newValue/100/1000;
                break;
        }
        return newValue;
}

double PhysicalNumber::convertTimeValue(int diff) const{
    double newValue = this->getValue();
    Unit unit = this->getUnit();
    switch (diff)
        {
            case -2://this is sec and other is hour
                newValue = newValue*60*60;
                break;

            case -1:
                newValue = newValue*60;
                break;

            case 1:
                newValue = newValue/60;
                break;

            case 2:
                newValue = newValue/60/60;
                break;
        }
        return newValue;
}

double PhysicalNumber::convertMassValue(int diff) const{
    double newValue = this->getValue();
    Unit unit = this->getUnit();
    switch (diff)
        {
            case -2://this is g and other is ton
                newValue = newValue*1000*1000;
                break;

            case -1:
                newValue = newValue*1000;
                break;

            case 1:
                newValue = newValue/1000;
                break;

            case 2:
                newValue = newValue/1000/1000;
                break;
        }
        return newValue;
}

double PhysicalNumber::parseValue(std::string input) const{
    std::string delimiter = "[";
    std::string valueString = input.substr(0, input.find(delimiter));
    std::string::size_type sz;
    double value = std::stod (valueString,&sz);
    return value;
}

std::string PhysicalNumber::parseUnit(std::string input) const{
    std::string delimiter = "[";
    int start = input.find(delimiter) + 1;
    delimiter = "]";
    int end = input.find(delimiter);
    int length = end - start;
    std::string valueString = input.substr(start, length);
    return valueString;
}

//returns -1 if unit doesn't exist
int PhysicalNumber::findUnitIndex(std::string unitString) const{
    for(int i =0; i<9; i++)
        if(this->units[i].compare(unitString) == 0) return i;
    return -1;
}