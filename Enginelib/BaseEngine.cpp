#pragma once

#include <BaseEngine.h>

T_BaseEngine::T_BaseEngine(){
    SetPower(0);
    this->engineOdometr = 0;
}

T_BaseEngine::T_BaseEngine(double _maxPower){
    SetPower(_maxPower);
    this->engineOdometr = 0;
}

T_BaseEngine::~T_BaseEngine(){}

double T_BaseEngine::GetPower(){
    return maxPower;
}

void T_BaseEngine::SetPower(double _maxPower){
    if (_maxPower>=0)
        this->maxPower = _maxPower;
    else throw "Error NegativePower";
}

int T_BaseEngine::GetMileage(){
    return engineOdometr;
}

void T_BaseEngine::AddMileage(int _mileage){
    if (_mileage>=0)
        this->engineOdometr+=_mileage;
    else
        throw "U can't add negative mileage";
}
