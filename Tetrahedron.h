#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Figure.h"
#include <fstream>

class Tetrahedron : public Figure {
    int A;
public:
    void In_Data(std::ifstream& ifst);
    void Out_Data(const double& Density, const int& Temperature, std::ofstream& ofst);
	double Volume();
    Tetrahedron() {};
};

#endif // TETRAHEDRON_H
