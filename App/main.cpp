#include <iostream>
#include "Car.h"
#include "Engines.h"

int main()
{
  T_PetrolEngine** array = new T_PetrolEngine*[4];
  array[0] = new TSI(1.4, 131);
  array[1] = new TSI(1.6, 151);
  array[2] = new Gamma(1.4, 104);
  array[3] = new Gamma(1.6, 123);

  for(int i = 0; i<4; i++){
    std::cout << array[i]->GetInjectionType() << std::endl;
  }
  Gamma G4FC(1.6,123);
  Gamma G4FD(2.0,140);
  TCar c(G4FC,'F',198,1200);
  std::cout << c.GetMaxSpeed() << std::endl;
  c.ChangeEngine(G4FD);
  std::cout << c.GetMaxSpeed() << std::endl;

}
