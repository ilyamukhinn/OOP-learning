#include "Container.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "incorrect command line! "
            "Waited: command in_file out_file"
            << std::endl;
        exit(1);
    }

    std::ifstream ifst(argv[1]);
    std::ofstream ofst(argv[2]);

    std::cout << "Start" << std::endl;

    Container C;

    C.In(ifst);
	C.Sort();

    ofst << "Filled container. " << std::endl;
    C.Out(ofst);

    C.Clear();

    ofst << "Empty container. " << std::endl;
    C.Out(ofst);

    std::cout << "Stop" << std::endl;

    system("pause");
    return 0;
}