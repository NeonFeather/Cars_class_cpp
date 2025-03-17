#pragma once
#include <iostream>
#include <list>

#include <Engines.h>
class TCar{
  protected:
    T_BaseEngine engine;
    char wd;
    std::string VIN;
    int maxSpeed;
    int mass;
  public:

    TCar(T_BaseEngine _engine, char _wd, int _maxSpeed, int _mass);
    ~TCar();

    T_BaseEngine        GetEngine();
    virtual char        GetWD();
    virtual std::string GetVIN();
    virtual int         GetMaxSpeed();
    
    void                ChangeEngine(T_BaseEngine _engine);
    virtual void        ChangeWD(char _wd);

    // friend std::ostream& operator <<(std::ostream& o, Tree& b);
    // friend std::istream& operator >>(std::istream& i, Tree& b);
};

