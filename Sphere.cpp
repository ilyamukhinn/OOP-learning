#include "Sphere.h"

void Sphere::In_Data(std::ifstream& ifst) 
{
    ifst >> Radius;
}

void Sphere::Out_Data(const double& Density, std::ofstream& ofst) 
{
    ofst << "It's a Sphere with Radius: " << Radius << std::endl;
    ofst << "Its Density is " << Density << std::endl << std::endl;
}

void Sphere::Out_Only_Sphere(const double& Density, std::ofstream& ofst)
{
    Out_Data(Density, ofst);
}