#include "Sphere.h"
#define _USE_MATH_DEFINES
#include <math.h>

void Sphere::In_Data(std::ifstream& ifst) 
{
    std::string str_radius = "";
    std::getline(ifst, str_radius); //Read radius
    if (!(is_Number(str_radius, true)))
    {
        std::cout << "Incorrect data" << std::endl;
        exit(1);
    }
    else
    {
        Radius = atoi(str_radius.c_str());
    }
}

void Sphere::Out_Data(const double& Density, const int& Temperature, std::ofstream& ofst) 
{
    ofst << "It's a Sphere with Radius: " << Radius << std::endl;
    ofst << "Its Density is " << Density << std::endl;
    ofst << "Its Temperature of melting/burning is " << Temperature << std::endl << std::endl;
}

double Sphere::Volume() 
{
    return (M_PI * pow((double)Radius, 3) / 3);
}

void Sphere::Out_Only_Sphere(const double& Density, const int& Temperature, std::ofstream& ofst)
{
    Out_Data(Density, Temperature, ofst);
}