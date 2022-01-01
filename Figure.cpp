#include "Figure.h"
#include "Sphere.h"
#include "Parallelepiped.h"

Figure* Figure::In(std::ifstream& ifst) 
{
    Figure* F;
    int id;

    ifst >> id;

    switch (id)
    {
    case 1:
        F = new Sphere;
        break;
    case 2:
        F = new Parallelepiped;
        break;
    default:
        return 0;
    }

    F->In_Data(ifst);
    ifst >> F->Density;

    return F;
}

double Figure::Get_Density()
{
    return Density;
}

void Figure::Out_Only_Sphere(const double& Density, std::ofstream& ofst)
{
    ofst << std::endl;
}