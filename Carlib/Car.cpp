#pragma once

#include <Car.h>
#include <list>

TCar::TCar(T_BaseEngine _engine, char _wd, int _maxSpeed, int _mass){
    this->engine = _engine;
    if (_wd == 'R' || _wd == 'A' || _wd == 'F') this->wd = _wd; else throw "Error WD";
    if (_maxSpeed<0) throw "Error negative MaxSpeed";
    this->maxSpeed = _maxSpeed;
    if (_mass<0) throw "Error negative Mass";
    this->mass = _mass;
    this->VIN = "RANDOMVIN_MNE_LEN_DELAT";
}

TCar::~TCar(){}

T_BaseEngine TCar::GetEngine(){
    return engine;
}


char TCar::GetWD(){
    return wd;
}


std::string TCar::GetVIN(){
    return VIN;
}


int TCar::GetMaxSpeed(){
    return maxSpeed;
}


void TCar::ChangeEngine(T_BaseEngine _engine){
    this->maxSpeed = (_engine.GetPower()*this->maxSpeed/this->engine.GetPower());
    this->engine = _engine;
}

void TCar::ChangeWD(char _wd){
    if (_wd == 'R' || _wd == 'A' || _wd == 'F') this->wd = _wd; else throw "Error WD";
}

