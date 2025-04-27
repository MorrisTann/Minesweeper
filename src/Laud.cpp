#include "Laud.h"
#include <iostream>
#include <random>
#include <queue>

Laud::Laud(int read, int veerud, int miinid)
    : _read(read), _veerud(veerud), _miinid(miinid),
      _ruudud(read, std::vector<Ruut>(veerud))
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distR(0, read-1);
    std::uniform_int_distribution<> distC(0, veerud-1);

    int paigutatud = 0;
    while (paigutatud < miinid)
    {
        int r = distR(gen);
        int c = distC(gen);
        if (!_ruudud[r][c].onMiin())
        {
            _ruudud[r][c].seaMiin();
            ++paigutatud;
        }
    }
    arvutaNaabrid();
}

bool Laud::piirides(int r, int c) const
{
    return r >= 0 && r < _read && c >= 0 && c < _veerud;
}

void Laud::arvutaNaabrid()
{
    const int dr[8] = {-1,-1,-1,0,0,1,1,1};
    const int dc[8] = {-1,0,1,-1,1,-1,0,1};

    for (int r = 0; r < _read; ++r)
    {
        for (int c = 0; c < _veerud; ++c)
        {
            if (_ruudud[r][c].onMiin())
            {
                _ruudud[r][c].seaNaabriMiinid(-1);
                continue;
            }
            int summa = 0;
            for (int k = 0; k < 8; ++k)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (piirides(nr, nc) && _ruudud[nr][nc].onMiin())
                    ++summa;
            }
            _ruudud[r][c].seaNaabriMiinid(summa);
        }
    }
}

bool Laud::avaRuut(int r, int c)
{
    if (!piirides(r, c) || _ruudud[r][c].onAvatud() || _ruudud[r][c].onLipustatud())
        return true; // ei midagi juhtunud

    _ruudud[r][c].ava();
    if (_ruudud[r][c].onMiin())
        return false; // kaotus

    if (_ruudud[r][c].naabriMiinid() == 0)
        laiendaTühjad(r, c);

    return true;
}

void Laud::laiendaTühjad(int sr, int sc)
{
    const int dr[8] = {-1,-1,-1,0,0,1,1,1};
    const int dc[8] = {-1,0,1,-1,1,-1,0,1};

    std::queue<std::pair<int, int>> q;
    q.emplace(sr, sc);

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 8; ++k)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (!piirides(nr, nc)) continue;

            Ruut& ruut = _ruudud[nr][nc];
            if (ruut.onAvatud() || ruut.onLipustatud()) continue;

            ruut.ava();
            if (ruut.naabriMiinid() == 0)
                q.emplace(nr, nc);
        }
    }
}

void Laud::lülitaLipp(int r, int c)
{
    if (piirides(r, c) && !_ruudud[r][c].onAvatud())
        _ruudud[r][c].lülitaLipp();
}

bool Laud::kasVõit() const
{
    for (const auto& rida : _ruudud)
        for (const auto& ruut : rida)
            if (!ruut.onMiin() && !ruut.onAvatud())
                return false;
    return true;
}

void Laud::prindi(bool näitaKõik) const
{
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GRAY    "\033[90m"

    // Veerupäis
    std::cout << "    ";
    for (int c = 0; c < _veerud; ++c)
        std::cout << c % 10 << " ";
    std::cout << "\n  +";
    for (int c = 0; c < _veerud * 2 - 1; ++c)
        std::cout << "-";
    std::cout << "+\n";

    for (int r = 0; r < _read; ++r)
    {
        std::cout << r % 10 << " | ";
        for (int c = 0; c < _veerud; ++c)
        {
            const Ruut& ruut = _ruudud[r][c];
            char s = näitaKõik && ruut.onMiin() ? '*' : ruut.kuva();

            if (s == '#')
                std::cout << GRAY << s << RESET << " ";
            else if (s == 'F')
                std::cout << RED << s << RESET << " ";
            else if (s == '*')
                std::cout << RED << s << RESET << " ";
            else if (s >= '1' && s <= '8')
                std::cout << BLUE << s << RESET << " ";
            else // tühi ruut
                std::cout << s << " ";
        }
        std::cout << "|\n";
    }

    std::cout << "  +";
    for (int c = 0; c < _veerud * 2 - 1; ++c)
        std::cout << "-";
    std::cout << "+\n";
}

