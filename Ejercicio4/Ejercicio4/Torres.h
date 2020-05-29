
#include "Pisos.h"

class Torre {
public:
	void llenarTorre();
	Piso* piso;
	std::string nomT;
	int PromHabitP();//promedio 
	int totalT();//total de habitantes en la Torre
	void setNameT(std::string n);
	std::string getNameT();
};


