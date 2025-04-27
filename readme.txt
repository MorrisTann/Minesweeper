Minesweeper / Miiniväli
Grupi liikmed: Hannes Jaakson, Morris Tann

1. Lühikokkuvõte ja oodatav tulemus
Projekt realiseerib klassikalise miinivälja mängu käsurearakenduse C++-s. Mäng loob juhuslikult miinidega täidetud laua, kuvab selle ANSI-värvidega ning võimaldab kasutajal ruute avada või lipuga märkida. Oodatav tulemus on stabiilselt töötav mäng, mis tagastab 0 võidu ja 1 kaotuse korral ning kuvab lõppseisu, et juhendajad saaksid kiiresti funktsionaalsust testida.

2. Koodi käivitamine
Kompileeri kõik lähtekoodifailid (C++23) või jookusta meie miinitaja.exe faili mis on kodukaustas.

g++ -std=c++23 -O2 Main.cpp Mang.cpp Laud.cpp Ruut.cpp -o minesweeper
Käivita PowerShellis (või muus terminalis, mis toetab ANSI-värve), CLioni sisemine terminal kasutab vaikimisi PowerShelli ja värvikoodid töötavad seal korrektselt:

bash
Kopeeri
Redigeeri
.\minesweeper          # vaikimisi 5×5 laud, 8 miini
.\minesweeper 10 12 20 # [read] [veerud] [miinid] – valikuline
Rea- ja veerunumbreid sisestatakse alates nullist; käsud on o R V (ava), f R V (lipp) ja e (välju).

3. Käivitamise eeldatav tulemus
Programmi alustamisel kuvatakse juhised ja tühi, suletud väljadega laud.

Mängu jooksul värvitakse:
suletud # – hall, lipud F ja miinid * – punane, arvud – sinine. ​

Miini avamisel teavitab mäng kaotusest, prindib kõik miinid ning lõpetab koodiga 1.

Kõigi ohutute ruutude avamisel teavitab mäng võidust ja lõpetab koodiga 0.

4. Lisafailid / andmed
Projekt ei vaja väliseid andmefaile; kõik miinid genereeritakse käivitamisel juhuslikult. Vajadusel võib testsisendite või skriptide lisada samasse kausta, kuid mäng töötab ilma lisaressurssideta.

