#pragma once
#include "Ruut.h"
#include <vector>
#include <string>

/// Kogu mängulaud
class Laud {
public:
    Laud(int read, int veerud, int miinid);

    /// Ava ruut (r, v). Tagastab false, kui avati miin.
    bool avaRuut(int rida, int veerg);

    /// Lülita lipu/küsimärgi olekut
    void lülitaLipp(int rida, int veerg);

    /// Kas mäng on võidetud?
    bool kasVõit() const;

    /// Prindi laud käsureale
    void prindi(bool näitaKõik=false) const;

    int ridadeArv()  const { return read;   }
    int veergudeArv() const { return veerud; }

    bool piirides(int r, int v) const;

private:
    int read;
    int veerud;
    int miinid;

    std::vector<std::vector<Ruut>> ruudud;

    /// Arvuta ja salvesta kõigi ruutude naabermiini arvud
    void arvutaNaabrid();

    /// Rekursiivne lahtiklapitus tühjade ruutudele
    void laiendaTühjad(int r, int c);
};
