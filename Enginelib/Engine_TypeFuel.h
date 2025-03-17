#pragma once

#include <BaseEngine.h>
#include <string>

class T_PetrolEngine: public T_BaseEngine
{
	protected:
		double  volume;   
		int 	typeFuel;
		int		typeBoost; //0-atmo, 1-compressor, 2-turbo, 3-biturbo
		std::string 	engineOil;
		std::string 	injectionType;
	public:

		T_PetrolEngine(const T_PetrolEngine &p);
		T_PetrolEngine();
		T_PetrolEngine(double _volume);
		T_PetrolEngine(double _volume, double _maxPower);
		T_PetrolEngine(double _volume, double _maxPower, int _typeFuel);
		T_PetrolEngine(double _volume, double _maxPower, int _typeFuel, std::string _engineOil);

		virtual double  GetVolume();
		virtual std::string   GetOil();
		virtual int   	GetTypeFuel();
				std::string GetInjectionType();
	
		virtual void	SetTypeBoost(int _typeBoost);
		virtual void 	SetTypeFuel(int _typeFuel);
		virtual void    ChangeOil(std::string _engineOil);
				void	SetInjectionType(std::string _inj);
		
};
class T_DieselEngine: public T_BaseEngine
{
	protected:
		double  volume;             //Объем двигателя
		std::string 	engineOil;            //Масло двигателя. Пример 0w20, 5w30, 5w20
		int		typeBoost; //0-atmo, 1-compressor, 2-turbo, 3-biturbo
		double 	carbonDeposits; 		//0 - 1
	public:
		T_DieselEngine(const T_DieselEngine &p);
		T_DieselEngine(double _volume);
		T_DieselEngine(double _volume, double _maxPower);
		T_DieselEngine(double _volume, double _maxPower, std::string _engineOil);

		virtual double  GetVolume();
		virtual std::string   GetOil();
		virtual double 	GetCarbonDeposits();
				double 	GetPower();

		virtual void	SetTypeBoost(int _typeBoost);
		virtual void 	ChangeOil(std::string _engineOil);
		virtual void 	CleanCarbonDeposits();
		 		void	AddMileage(int _mileage);

	
};
class T_ElectricEngine: public T_BaseEngine
{
	public:
		T_ElectricEngine(const T_ElectricEngine &p);
		T_ElectricEngine();
		T_ElectricEngine(double _maxPower);
		~T_ElectricEngine();
};