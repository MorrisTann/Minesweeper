#pragma once
#include <string>

/// Üks mänguruut (väli) miiniväljal
class Ruut
{
public:
    Ruut();

    /// Kas ruudus on miin?
    bool onMiin() const                         { return _onMiin; }
    void seaMiin(bool val = true)               { _onMiin = val;  }

    /// Kas ruut on juba avatud?
    bool onAvatud() const                       { return _avatud; }
    void ava()                                  { _avatud = true; }

    /// Kas kasutaja on siia lipu pannud?
    bool onLipustatud() const                   { return _lipustatud; }
    void lülitaLipp()                           { _lipustatud = !_lipustatud; }

    /// Naabermiine näitav arv
    int naabriMiinid() const                    { return _naabriMiinid; }
    void seaNaabriMiinid(int n)                 { _naabriMiinid = n; }

    /// Sümbol ekraanil (CLI-vaates)
    char kuva() const;

private:
    bool _onMiin        {false};
    bool _avatud        {false};
    bool _lipustatud    {false};
    int  _naabriMiinid  {0};
};
