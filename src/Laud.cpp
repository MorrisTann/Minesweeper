#include "Laud.h"

#include <iomanip>
#include <iostream>
#include <random>
#include <queue>

Laud::Laud(int read, int veerud, int miinid)
    : read(read), veerud(veerud), miinid(miinid),
      ruudud(read, std::vector<Ruut>(veerud)) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randomR(0, read - 1);
    std::uniform_int_distribution<> randomV(0, veerud - 1);

    int paigutatud = 0;
    while (paigutatud < miinid) {
        int r = randomR(gen);
        int v = randomV(gen);
        if (!ruudud[r][v].onMiin()) {
            ruudud[r][v].seaMiin();
            ++paigutatud;
        }
    }
    arvutaNaabrid();
}

bool Laud::piirides(int r, int v) const {
    return r >= 0 && r < read && v >= 0 && v < veerud;
}

void Laud::arvutaNaabrid() {
    constexpr int niheR[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    constexpr int niheV[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int r = 0; r < read; ++r) {
        for (int v = 0; v < veerud; ++v) {
            if (ruudud[r][v].onMiin()) {
                ruudud[r][v].seaNaabriMiinid(-1);
                continue;
            }
            int summa = 0;
            for (int k = 0; k < 8; ++k) {
                int naaber_r = r + niheR[k];
                int naaber_v = v + niheV[k];
                if (piirides(naaber_r, naaber_v) && ruudud[naaber_r][naaber_v].onMiin())
                    ++summa;
            }
            ruudud[r][v].seaNaabriMiinid(summa);
        }
    }
}

bool Laud::avaRuut(int r, int v) {
    if (!piirides(r, v) || ruudud[r][v].onAvatud() || ruudud[r][v].onLipustatud()) {
        std::cout << "Ruut on kas piiridest väljas, juba varem avatud, või lipp peale pandud!\n";
        return true; // kui on midagi tehtud
    }

    ruudud[r][v].ava();
    if (ruudud[r][v].onMiin())
        return false;

    if (ruudud[r][v].naabriMiinid() == 0)
        laiendaTühjad(r, v);

    return true;
}

void Laud::laiendaTühjad(int start_r, int start_v) {
    constexpr int nihe_r[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    constexpr int nihe_v[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    std::queue<std::pair<int, int> > jär;
    jär.emplace(start_r, start_v);

    while (!jär.empty()) {
        auto p = jär.front();
        auto r = p.first;
        auto v = p.second;
        jär.pop();

        for (int k = 0; k < 8; ++k) {
            int naaber_r = r + nihe_r[k];
            int naaber_v = v + nihe_v[k];
            if (!piirides(naaber_r, naaber_v)) continue;

            Ruut &ruut = ruudud[naaber_r][naaber_v];
            if (ruut.onAvatud() || ruut.onLipustatud()) continue;

            ruut.ava();
            if (ruut.naabriMiinid() == 0)
                jär.emplace(naaber_r, naaber_v);
        }
    }
}

void Laud::lülitaLipp(int r, int v) {
    if (piirides(r, v) && !ruudud[r][v].onAvatud())
        ruudud[r][v].lülitaLipp();
}

bool Laud::kasVõit() const {
    for (const auto &rida: ruudud)
        for (const auto &ruut: rida)
            if (!ruut.onMiin() && !ruut.onAvatud())
                return false;
    return true;
}

void Laud::prindi(bool näitaKõik) const {
    //näitaKõik on et kas näitab kõik miinid
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define GRAY    "\033[90m"

    constexpr int lahtriLaius = 3;

    std::cout << "     "; // ruumi rea numbrite jaoks
    for (int v = 0; v < veerud; ++v)
        std::cout << std::setw(lahtriLaius) << v;
    std::cout << "\n     +";
    for (int v = 0; v < veerud * lahtriLaius; ++v)
        std::cout << "-";
    std::cout << "+\n";

    for (int r = 0; r < read; ++r) {
        std::cout << std::setw(3) << r << " |";
        for (int v = 0; v < veerud; ++v) {
            const Ruut &ruut = ruudud[r][v];
            char märk = näitaKõik && ruut.onMiin() ? '*' : ruut.kuva();

            if (märk == '#')
                std::cout << GRAY << std::setw(lahtriLaius) << märk << RESET;
            else if (märk == 'F' || märk == '*')
                std::cout << RED << std::setw(lahtriLaius) << märk << RESET;
            else if (märk >= '1' && märk <= '8')
                std::cout << BLUE << std::setw(lahtriLaius) << märk << RESET;
            else
                std::cout << std::setw(lahtriLaius) << märk;
        }
        std::cout << "  |\n";
    }

    std::cout << "     +";
    for (int v = 0; v < veerud * lahtriLaius; ++v)
        std::cout << "-";
    std::cout << "+\n";
}
