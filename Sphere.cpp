#include "Sphere.h"

void Sphere::In_Data(std::ifstream& ifst) 
{
    ifst >> Radius;
}

void Sphere::Out_Data(const double& Density, const int& Temperature, std::ofstream& ofst) 
{
    ofst << "It's a Sphere with Radius: " << Radius << std::endl;
    ofst << "Its Density is " << Density << std::endl;
    ofst << "Its Temperature of melting/burning is " << Temperature << std::endl << std::endl;
}