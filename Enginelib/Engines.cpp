#pragma once
#include "Engines.h"

TSI::TSI(const TSI &p) : T_PetrolEngine(p){}

TSI::TSI(double _volume, double _maxPower) : T_PetrolEngine(_volume, _maxPower)
{
    this->injectionType = "Stratified";
    SetTypeBoost(2);
}
TSI::TSI(double _volume, double _maxPower, int _typeFuel) : T_PetrolEngine(_volume, _maxPower, _typeFuel){
    SetTypeBoost(2);
    this->injectionType = "Stratified";
}

TSI::~TSI(){}

Gamma::Gamma(const Gamma &p) : T_PetrolEngine(p){
    this->injectionType = "MSI";
}

Gamma::Gamma(double _volume, double _maxPower) : T_PetrolEngine(_volume, _maxPower){
    this->injectionType = "MSI";
}
Gamma::~Gamma(){}

TDI::TDI(const TDI &p) : T_DieselEngine(p){}

TDI::TDI(double _volume, double _maxPower) : T_DieselEngine(_volume, _maxPower){
    SetTypeBoost(2);
}

TDI::~TDI(){}



D4::D4(double _volume, double _maxPower) : T_DieselEngine(_volume, _maxPower)
{
    SetTypeBoost(2);
}

D4::~D4(){}

ElectricAsync::ElectricAsync(const ElectricAsync &p)
{
}

ElectricAsync::ElectricAsync(double _maxPower): T_ElectricEngine(_maxPower){}

ElectricAsync::~ElectricAsync(){}

ElectricMag::ElectricMag(double _powermag) : T_ElectricEngine(){
    SetPower(_powermag*0.9);
}
