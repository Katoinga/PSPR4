
#include "Departamentos.h"

class Piso {
public:
	void llenarPiso();
	Departamentos* dpts;
	std::string nomPis;
	int PromHabitD();//Promedio 
	void setNameP(std::string n);
	std::string getNameP();
	int totalP();//total de habitantes en un Piso
};

