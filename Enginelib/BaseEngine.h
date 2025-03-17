#pragma once
#include <iostream>

class T_BaseEngine
{
  protected:
  
    //Неизменяемые характеристики
    double  maxPower;           //Мощность

    int engineOdometr;
  
  public:
    T_BaseEngine();
    T_BaseEngine(double _maxPower);
    ~T_BaseEngine();

    virtual double  GetPower();
    virtual void    SetPower(double _maxPower);
    virtual int     GetMileage();
    virtual void    AddMileage(int _mileage);

    // friend std::ostream& operator <<(std::ostream& o, Tree& b);
    // friend std::istream& operator >>(std::istream& i, Tree& b);
};