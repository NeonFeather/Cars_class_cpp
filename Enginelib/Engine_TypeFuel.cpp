#pragma once

#include <BaseEngine.h>
#include <Engine_TypeFuel.h>

T_PetrolEngine::T_PetrolEngine(const T_PetrolEngine &p) :T_BaseEngine(p){}

T_PetrolEngine::T_PetrolEngine()
{
    this->volume = 0;
    SetPower(0);
    ChangeOil("0w20");
    SetTypeFuel(92);
    SetTypeBoost(0);
}

// Petrol
T_PetrolEngine::T_PetrolEngine(double _volume){
    if (_volume >0)
        this->volume = _volume;
    else
        throw "Negative volume";
    SetPower(0);
    ChangeOil("0w20");
    SetTypeFuel(92);
    SetTypeBoost(0);
}

T_PetrolEngine::T_PetrolEngine(double _volume, double _maxPower):T_PetrolEngine::T_PetrolEngine(_volume){
    SetPower(_maxPower);
}

T_PetrolEngine::T_PetrolEngine(double _volume, double _maxPower, int _typeFuel): T_PetrolEngine::T_PetrolEngine(_volume, _maxPower){
    SetTypeFuel(_typeFuel);
}

T_PetrolEngine::T_PetrolEngine(double _volume, double _maxPower, int _typeFuel,std::string _engineOil):T_PetrolEngine::T_PetrolEngine(_volume, _maxPower, _typeFuel){
    ChangeOil(_engineOil);
}

double T_PetrolEngine::GetVolume(){
    return volume;
}

std::string T_PetrolEngine::GetOil(){
    return engineOil;
}

int T_PetrolEngine::GetTypeFuel(){
    return typeFuel;
}

std::string T_PetrolEngine::GetInjectionType(){
    return injectionType;
}

void T_PetrolEngine::SetTypeBoost(int _typeBoost){
    if(_typeBoost>=0 && _typeBoost<=3)
        this->typeBoost = _typeBoost;
    else throw "Error TypeBoost";
}

void T_PetrolEngine::SetTypeFuel(int _typeFuel)
{
    if (_typeFuel>40 && _typeFuel<200)
        this->typeFuel = _typeFuel;
    else
        throw "Error TypeFuel";
}

void T_PetrolEngine::ChangeOil(std::string _engineOil){
    std::string oils[] = {"0w20","0w30","0w40","5w20","5w30","5w40"};
    int c;
    for(int i = 0; i<6; i++){
        c=1;
        for(int j = 0; j<4; j++)
            if(_engineOil[j]!=oils[i][j])
                c=0;
        if(c==1){
            this->engineOil = _engineOil;
            return;
        }
    }
    throw "Error Oil";
}

void T_PetrolEngine::SetInjectionType(std::string _inj){
    this->injectionType = _inj;
}

T_DieselEngine::T_DieselEngine(const T_DieselEngine &p) : T_BaseEngine(p){}

// Diesel
T_DieselEngine::T_DieselEngine(double _volume){
    if (_volume >0)
        this->volume = _volume;
    else
        throw "Negative volume";
    SetPower(0);
    ChangeOil("0w20");
    this->carbonDeposits = 0;
}

T_DieselEngine::T_DieselEngine(double _volume, double _maxPower):T_DieselEngine::T_DieselEngine(_volume){
    SetPower(_maxPower);
}

T_DieselEngine::T_DieselEngine(double _volume, double _maxPower, std::string _engineOil):T_DieselEngine::T_DieselEngine(_volume, _maxPower){
    ChangeOil(_engineOil);
}

double T_DieselEngine::GetVolume(){
    return volume;
}

std::string T_DieselEngine::GetOil(){
    return engineOil;
}

double T_DieselEngine::GetCarbonDeposits(){
    return carbonDeposits;
}

double T_DieselEngine::GetPower(){
    return maxPower*(1-carbonDeposits);
}

void T_DieselEngine::SetTypeBoost(int _typeBoost){
    if(_typeBoost>=0 && _typeBoost<=3)
        this->typeBoost = _typeBoost;
    else throw "Error TypeBoost";
}

void T_DieselEngine::ChangeOil(std::string _engineOil)
{
    std::string oils[] = {"0w20","0w30","0w40","5w20","5w30","5w40"};
    int c;
    for(int i = 0; i<6; i++){
        c=1;
        for(int j = 0; j<4; j++)
            if(_engineOil[j]!=oils[i][j])
                c=0;
        if(c==1){
            this->engineOil = _engineOil;
            return;
        }
    }
    throw "Error Oil";
}

void T_DieselEngine::CleanCarbonDeposits(){
    this->carbonDeposits = 0;
}
void T_DieselEngine::AddMileage(int _mileage){
    if (_mileage>=0){    
        this->engineOdometr+=_mileage;
        this->carbonDeposits+=(_mileage/100000.0);
    }
    else
        throw "U can't add negative mileage";
}

T_ElectricEngine::T_ElectricEngine(const T_ElectricEngine &p) : T_BaseEngine(p){}

T_ElectricEngine::T_ElectricEngine() : T_BaseEngine::T_BaseEngine() {}
T_ElectricEngine::T_ElectricEngine(double _maxPower) : T_BaseEngine::T_BaseEngine(_maxPower){}

T_ElectricEngine::~T_ElectricEngine(){}
