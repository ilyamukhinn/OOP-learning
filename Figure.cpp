#include "Figure.h"
#include "Sphere.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"

Figure* Figure::In(std::ifstream& ifst) 
{
    Figure* F;
    std::string str_id = "";
    std::getline(ifst, str_id);

    if ((str_id != "1") && (str_id != "2") && (str_id != "3") && (str_id != ""))
    {
        std::cout << "Incorrect data" << std::endl;
        exit(1);
    }

    int id = atoi(str_id.c_str());

    switch (id)
    {
    case 1:
        F = new Sphere;
        break;
    case 2:
        F = new Parallelepiped;
        break;
	case 3:
        F = new Tetrahedron;
        break;
    default:
        return 0;
    }

    F->In_Data(ifst);
    std::string str_parameter = "";
    std::getline(ifst, str_parameter); //Read density
    if (!(F->is_Number(str_parameter, false)))
    {
        std::cout << "Incorrect data" << std::endl;
        exit(1);
    }
    else
    {
        F->Density = atoi(str_parameter.c_str());
    }
	
	std::getline(ifst, str_parameter); //Read temperature
    if (!(F->is_Number(str_parameter, true)))
    {
        std::cout << "Incorrect data" << std::endl;
        exit(1);
    }
    else
    {
        F->Temperature = atoi(str_parameter.c_str());
    }

    return F;
}

double Figure::Get_Density()
{
    return Density;
}

int Figure::Get_Temperature()
{
    return Temperature;
}

bool Figure::Compare(Figure* other) 
{
    return Volume() > other->Volume();
}

void Figure::Out_Only_Sphere(const double& Density, const int& Temperature, std::ofstream& ofst)
{
    ofst << std::endl;
}

bool Figure::is_Number(const std::string& str_num, const bool& check_Integer)
{
    int num_size = str_num.size();
    switch (num_size)
    {
    case 0:
        return false;
        break;
    case 1:
        if (!(isdigit(str_num[0])))
        {
            return false;
        }
        break;
    default:
        if (!(isdigit(str_num[0])) && (str_num[0] != '-'))
        {
            return false;
        }

        if (check_Integer)
        {
            for (int i = 1; i < num_size; i++)
            {
                if (!(isdigit(str_num[i])))
                {
                    return false;
                }
            }
        }
        else
        {
            int sep_amount = 0;
            for (int i = 1; i < num_size; i++)
            {
                if (!(isdigit(str_num[i])))
                {
                    if ((str_num[i] != '.') && (str_num[i] != ',') && (sep_amount > 1))
                    {
                        return false;
                    }
                    else
                    {
                        sep_amount++;
                    }
                }
            }
        }

        break;
    }

    return true;
}