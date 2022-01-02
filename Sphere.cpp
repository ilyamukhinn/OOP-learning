#include "Sphere.h"
#define _USE_MATH_DEFINES
#include <math.h>

void Sphere::In_Data(std::ifstream& ifst) 
{
    ifst >> Radius;
}

void Sphere::Out_Data(const double& Density, std::ofstream& ofst) 
{
    ofst << "It's a Sphere with Radius: " << Radius << std::endl;
    ofst << "Its Density is " << Density << std::endl << std::endl;
}

double Sphere::Volume() 
{
    return (M_PI * pow((double)Radius, 3) / 3);
}