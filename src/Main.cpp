#include "Mang.h"
#include <cstdlib>

int main(int argc, char* argv[])
{
    // Vaikimisi 9×9 ja 10 miini (klassikaline „beginner“)
    int read   = 9;
    int veerud = 9;
    int miinid = 10;

    if (argc == 4)
    {
        read   = std::atoi(argv[1]);
        veerud = std::atoi(argv[2]);
        miinid = std::atoi(argv[3]);
    }

    Mang mäng(read, veerud, miinid);
    return mäng.käivita();
}
