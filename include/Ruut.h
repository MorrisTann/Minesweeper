#pragma once
#include <string>

// Üks mänguruut (väli) miiniväljal
class Ruut {
public:
    Ruut();

    // Kas ruudus on miin?
    bool onMiin() const { return kasMiin; }
    void seaMiin(bool val = true) { kasMiin = val; }

    // Kas ruut on juba avatud?
    bool onAvatud() const { return avatud; }
    void ava() { avatud = true; }

    // Näitab kas kasutaja on ruudu lipustanud
    bool onLipustatud() const { return lipustatud; }
    void lülitaLipp() { lipustatud = !lipustatud; }

    // Naabermiine näitav arv
    int naabriMiinid() const { return naaberMiinideArv; }
    void seaNaabriMiinid(int n) { naaberMiinideArv = n; }

    // Sümbol ekraanil
    char kuva() const;

private:
    bool kasMiin{false};
    bool avatud{false};
    bool lipustatud{false};
    int naaberMiinideArv{0};
};
