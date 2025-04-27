#include "Ruut.h"

Ruut::Ruut() = default;

char Ruut::kuva() const
{
    if (_avatud)
    {
        if (_onMiin)          return '*';
        if (_naabriMiinid==0) return ' ';
        return static_cast<char>('0' + _naabriMiinid);
    }
    else
    {
        if (_lipustatud) return 'F';
        return '#';
    }
}
