#ifndef SPHERE_H
#define SPHERE_H

#include "Figure.h"

//a special case of the base class (geometric shapes) is a sphere with its own parameter - radius
class Sphere : public Figure 
{
    int Radius;
public:
    void In_Data(std::ifstream& ifst);
    void Out_Data(const double& Density, const int& Temperature, std::ofstream& ofst); 
	double Volume();
	void Out_Only_Sphere(const double& Density, const int& Temperature, std::ofstream& ofst);
    Sphere() {};
};

#endif // SPHERE_H
