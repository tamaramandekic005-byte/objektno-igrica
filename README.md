Igra Vješala (Hangman)


   Opis projekta

Ovaj projekt predstavlja konzolnu igru Vješala (Hangman) implementiranu u programskom jeziku C++ koristeći principe objektno orijentiranog programiranja.  
Igra nasumično odabire pojam iz datoteke `words.txt`, a igrač pogađa slova dok ne otkrije cijeli pojam ili ne potroši sve dozvoljene pokušaje.


Kako pokrenuti projekt
1. Preuzeti i raspakirati ZIP arhivu
2. Ući u mapu `Vjesala`
3. Pokrenuti datoteku:
4. Igra se pokreće u konzolnom prozoru


Kontrole u igri
- Igrač bira kategoriju pojma kojeg pogađa
- Igrač bira težinu pogađanja(easy,medium,hard)
- Igrač unosi jedno slovo putem tipkovnice (može iskoristiti hint za jedno slovo -'?')
- Nakon svakog unosa prikazuje se:
- trenutno stanje pojma
- iskorištena slova
Igra završava kada:
- igrač pogodi cijelu riječ (pobjeda)
- ili potroši sve pokušaje (poraz)


Struktura projekta i klase

 main.cpp
- Ulazna točka programa
- Pokreće tijek igre i povezuje ostale klase


Hangman.h / Hangman.cpp
- Upravljanje pokušajima
- Provjera pogođenih slova
- Praćenje stanja igre (pobjeda / poraz)

WordManager.h / WordManager.cpp`
- Učitavanje pojmova iz datoteke `words.txt`
- Nasumičan odabir pojma za igru ovisno o kategoriji

UI.h / UI.cpp
- Zadužen za ispis poruka u konzoli
- Prikaz stanja igre i uputa igraču

Statistics.h
- Sadrži pomoćne strukture za praćenje statistike igre


  Projekt koristi isključivo standardnu C++ biblioteku



Mogući problem i rješenje:

-Problem: Riječi se ne učitavaju
-Rješenje:** Provjeriti da se 'words.txt' nalazi u istom folderu kao 'Vjesala.exe'


## Razvojno okruženje
- Microsoft Visual Studio 2019
- Programski jezik: C++
