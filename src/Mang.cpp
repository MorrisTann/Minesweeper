#include "Mang.h"
#include <iostream>
#include <sstream>

Mang::Mang(int read, int veerud, int miinid)
    : _laud(read, veerud, miinid)
{}

int Mang::käivita()
{
    std::cout << "Tere tulemast mängima Miinivälja!\n"
                 "Käsud:\n"
                 "  o R C   - ava ruut (R, C)\n"
                 "  f R C   - lülita lipp ruudul (R, C)\n"
                 "Reanumbrid ja veerunumbrid algavad nullist.\n"
                 "Sisesta oma käsk ja vajuta Enter!\n\n"; // ← uus teade

    while (true)
    {
        _laud.prindi();
        std::cout << "> ";
        std::string rida;
        if (!std::getline(std::cin, rida) || rida.empty())
            continue;
        if (!töötleSisend(rida))
            break;
        std::cout << "\n"; // ← ilus vahe pärast igat käsku
    }

    if (_laud.kasVõit())
    {
        std::cout << "Palju õnne, võitsid!\n";
        return 0;
    }
    else
    {
        std::cout << "Kahjuks avasid miini.\n";
        _laud.prindi(true);
        return 1;
    }
}

bool Mang::töötleSisend(const std::string& rida)
{
    std::istringstream ss(rida);
    char käsk;
    int r, c;
    if (!(ss >> käsk >> r >> c))
    {
        std::cout << "Vigane sisend. Kasuta näiteks: o 3 4 või f 2 5\n";
        return true;
    }

    switch (käsk)
    {
        case 'o':
        case 'O':
            if (!_laud.avaRuut(r, c))
                return false;         // avas miini, mäng läbi
        if (_laud.kasVõit())
            return false;         // kõik ruudud avatud, võit
        break;

        case 'f':
        case 'F':
            _laud.lülitaLipp(r, c);
        break;

        default:
            std::cout << "Tundmatu käsk. Kasuta 'o' (ava) või 'f' (lipp).\n";
        break;
    }

    return true;
}
