#include "Parallelepiped.h"

void Parallelepiped::In_Data(std::ifstream& ifst) 
{
    std::string str_side = "";
    for (int i = 0; i < 3; i++)
    {
        std::getline(ifst, str_side); //Read current side
        if (!(is_Number(str_side, true)))
        {
            std::cout << "Incorrect data" << std::endl;
            exit(1);
        }
        else
        {
            switch (i)
            {
            case 0:
                A = atoi(str_side.c_str());
                break;
            case 1:
                B = atoi(str_side.c_str());
                break;
            case 2:
                C = atoi(str_side.c_str());
                break;
            default:
                break;
            }
        }
    }
}

void Parallelepiped::Out_Data(const double& Density, const int& Temperature, std::ofstream& ofst) 
{
    ofst << "It's a Parallelepiped with Edges: " << A << ", " << B
        << ", " << C << std::endl;
    ofst << "Its Density is " << Density << std::endl;
	ofst << "Its Temperature of melting/burning is " << Temperature << std::endl << std::endl;
}

double Parallelepiped::Volume() 
{
    return (A * B * C);
}