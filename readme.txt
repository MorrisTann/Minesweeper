Minesweeper / Miiniväli
Grupi liikmed: Hannes Jaakson, Morris Tann

1. Lühikokkuvõte ja oodatav tulemus
Projekt realiseerib klassikalise miinivälja mängu C++-s. Mäng loob juhuslikult miinidega täidetud laua, kuvab selle ANSI-värvidega ning võimaldab kasutajal ruute avada või lipuga märkida. Oodatav tulemus on töötav mäng, mis ütleb mängu võitmise korral et võitsid ja kaotuse korral et kaotasid ning kuvab lõppseisu.

2. Koodi käivitamine
Kompileeri kõik lähtekoodifailid (C++23) või kasuta meie antud kompileeritud miinitaja.exe faili (lisasime kodukausta ka vajalikud .dll failid, et see töötaks).

g++ -std=c++23 Main.cpp Mang.cpp Laud.cpp Ruut.cpp -o minesweeper
Käivita binaar fail PowerShellis (või muus terminalis, mis toetab ANSI-värve), sest CLioni sisemine terminal kasutab vaikimisi PowerShelli ja värvikoodid töötavad seal korrektselt:

.\minesweeper          # vaikimisi 5×5 laud, 8 miini
.\minesweeper 10 12 20 # [read] [veerud] [miinid] – valikuline
Rea- ja veerunumbreid sisestatakse alates nullist; käsud on o R V (ava/open), f R V (lipp/flag) ja e (välju/exit).

3. Käivitamise eeldatav tulemus
Programmi alustamisel kuvatakse juhised ja tühi, suletud ruutudega laud.

Mängu jooksul värvitakse:
suletud # – hall, lipud F ja miinid * – punane, arvud – sinine. ​

Miini avamisel teavitab mäng kaotusest, prindib kõik miinid ning lõpetab programmi.

Kõigi ohutute ruutude avamisel teavitab mäng võidust ja lõpetab progammi.

4. Lisafailid / andmed
Projekt ei vaja väliseid andmefaile; kõik miinid genereeritakse käivitamisel juhuslikult. Ainuke nõue on kasutada võimekamat terminali (nt powershell), et värvid töötaksid õigesti. Windowsi cmd.exe ei sobi.

