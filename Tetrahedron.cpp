#include  "Tetrahedron.h"
#include <math.h>

void Tetrahedron::In_Data(std::ifstream& ifst) 
{
    std::string str_side = "";
    std::getline(ifst, str_side); //Read side
    if (!(is_Number(str_side, true)))
    {
        std::cout << "Incorrect data" << std::endl;
        exit(1);
    }
    else
    {
        A = atoi(str_side.c_str());
    }
}

void Tetrahedron::Out_Data(const double& Density, const int& Temperature, std::ofstream& ofst) 
{
    ofst << "It's a Tetrahedron with Side length: " << A << std::endl;
    ofst << "Its Density is " << Density << std::endl;
    ofst << "Its Temperature of melting/burning is " << Temperature << std::endl << std::endl;
}

double Tetrahedron::Volume() 
{
	return (pow((double)A, 3) * sqrt(2) / 12);
}