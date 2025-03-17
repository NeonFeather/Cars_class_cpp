#pragma once

#include <string>
#include <Engine_TypeFuel.h>

class TSI: public T_PetrolEngine
{
	public:
		TSI(const TSI &p);
        TSI(double _volume, double _maxPower);
        TSI(double _volume, double _maxPower, int _typeFuel);
        ~TSI();
};

class Gamma: public T_PetrolEngine
{
	public:
	Gamma(const Gamma &p);
	Gamma(double _volume, double _maxPower);
	~Gamma();
};

class TDI: public T_DieselEngine
{
	public:
	TDI(const TDI &p);
	TDI(double _volume, double _maxPower);
	~TDI();
};
class D4: public T_DieselEngine
{
	public:
	D4(const TDI &p);
	D4(double _volume, double _maxPower);
	~D4();
};
class ElectricAsync: public T_ElectricEngine{
	public:
	ElectricAsync(const ElectricAsync &p);
	ElectricAsync(double _maxPower);
	~ElectricAsync();
};
class ElectricMag: public T_ElectricEngine{
	public:
	ElectricMag(const ElectricMag &p);
	ElectricMag(double _powermag);
	~ElectricMag();
};