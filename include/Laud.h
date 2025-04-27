#pragma once
#include "Ruut.h"
#include <vector>
#include <string>

/// Kogu mängulaud
class Laud
{
public:
    Laud(int read, int veerud, int miinid);

    /// Ava ruut (r, c). Tagastab false, kui avati miin.
    bool avaRuut(int rida, int veerg);

    /// Lülita lipu/küsimärgi olekut
    void lülitaLipp(int rida, int veerg);

    /// Kas mäng on võidetud?
    bool kasVõit() const;

    /// Prindi laud käsureale
    void prindi(bool näitaKõik=false) const;

    int ridadeArv()  const { return _read;   }
    int veergudeArv() const { return _veerud; }

private:
    int _read;
    int _veerud;
    int _miinid;

    std::vector<std::vector<Ruut>> _ruudud;

    bool piirides(int r, int c) const;

    /// Arvuta ja salvesta kõigi ruutude naabermiini arvud
    void arvutaNaabrid();

    /// Rekursiivne lahtiklapitus tühjade ruutudele
    void laiendaTühjad(int r, int c);
};
