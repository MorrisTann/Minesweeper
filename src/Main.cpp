#include "Mang.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
    int read = 5;
    int veerud = 5;
    int miinid = 8;


    //käsurealt saab ka muuta väärtusi
    if (argc == 4) {
        read = std::atoi(argv[1]);
        veerud = std::atoi(argv[2]);
        miinid = std::atoi(argv[3]);
    }

    //Esialgu rohkem põhjalikku kontrolli ei tee
    if (read < 0 || veerud < 0 || miinid < 0) {
        std::cout << "Negatiivseid arve ei tohi panna tottu. Programm lõpetab töö";
        return 0;
    }
    if ((read * veerud) < miinid) {
        std::cout << "Miine on rohkem kui kaste, muuda programmi. Programm lõpetab töö.\n";
        return 0;
    }

    Mang mäng(read, veerud, miinid);
    return mäng.käivita();
}
