/** @file */
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;
/** struct Wsp
* Reprezentuje wspó³rzêdne zawartoœci pola planszy sudoku.
*/
struct Wsp {
	int x;
	int y;
};

/** Wyœwietla pomoc.
*/
void pomoc();

/** Wczytuje kolejny znak z pliku tekstowego oddzielony separatorem ';'.
* @param plik plik tekstowy zawieraj¹cy sudoku do rozwi¹zania
* @param x wspó³rzêdna kolumny 
*/
string wczytajZnak(ifstream& plik, int x);

/**
* Dodaje do wektora wspó³rzêdne pola, w którym znajdujê siê znak ,,x'' reprezentuj¹cy niewype³nione pole w sudoku.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
* @param wpsolrzedne wektor zawieraj¹cy dane utworzone na podstawie struktury Wsp
* @param x wspó³rzêdna kolumny
* @param y wspó³rzêdna wiersza
*/
void dodajWsp(int tab[9][9], vector<Wsp>& wspolrzedne, int x, int y);

/** 
* Wczytuje z pliku tekstowego wartoœci znajduj¹ce siê w polach planszy sudoku oraz zapisuje wspó³rzêdne pól planszy, które trzeba uzupe³niæ.
* @param plikwe plik wejœciowy zawieraj¹cy sudoku do rozwi¹zania
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
* @param x wspó³rzêdna kolumny
* @param y wspó³rzêdna wiersza
* @param wspolrzedne wektor, w którym zapisywane s¹ wspó³rzêdne niewype³nionych pól sudoku oznaczonych symbolem ,,x''
*/
void wczytajKomorke(ifstream& plikwe, int tab[9][9], int x, int y, vector<Wsp>& wspolrzedne);

/**
* Wczytuje sudoku do rozwi¹zania. 
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
* @param wspolrzedne wektor, w którym zapisywane s¹ wspó³rzêdne niewype³nionych pól sudoku oznaczonych symbolem ,,x''
* @param sciezka œcie¿ka do wejœciowego pliku tekstowego
*/
bool wczytaj(int tab[9][9], vector<Wsp>& wspolrzedne, string sciezka);

/**
* Sprawdza czy dana wartoœæ istnieje w wierszu.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
* @param w wspó³rzêdne, dla których dla danej kolumny sprawdzane jest czy zadana wartoœæ wystêpujê w kolejnych wierszach
* @param wartosc wartoœæ do sprawdzenia
*/
bool istniejeWWierszu(int tab[9][9], Wsp& w, int wartosc);

/**
* Sprawdza czy dana wartoœæ istnieje w kolumnie.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
* @param w wspó³rzêdne, dla których dla danego wiersza sprawdzane jest czy zadana wartoœæ wystêpujê w kolejnych kolumnach
* @param wartosc wartoœæ do sprawdzenia
*/
bool istniejeWKolumnie(int tab[9][9], Wsp& w, int wartosc);

/**
* Wskazuje gdzie zaczyna siê kwadrat, w którym nie mog¹ powtórzyæ siê liczby.
* @param liczba sprawdza gdzie dla danej wartoœæ znajdujê siê pocz¹tek kwadratu
*/
int poczatekKwadratu(int liczba);

/** 
* Sprawdza czy dana wartoœæ istnieje w kwadracie.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
* @param w wspó³rzêdne, dla których sprawdzane jest czy dana wartoœæ istnieje w kwadracie
* @param wartosc wartoœæ do sprawdzenia
*/
bool istniejeWKwadracie(int tab[9][9], Wsp& w, int wartosc);

/** Sprawdza czy dana wartoœæ nie wystêpuje w wierszu, kolumnie oraz kwadracie i zwraca wartoœæ true, w przeciwnym wypadku false.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
* @param w wspó³rzêdne pola, dla którego sprawdzana jest wartoœæ  
* @param wartosc wartoœæ do sprawdzenia
*/
bool wartoscPrawidlowa(int tab[9][9], Wsp& w, int wartosc);

/** Próbuje dopasowaæ kolejne liczby do pola.
* Jeœli wypróbowana liczba jest prawid³owa, zwraca wartoœæ true, w przeciwnym wypadku funkcja wywo³uje sam¹ siebie i sprawdza liczbê o jeden wiêksz¹.
* Jeœli dojdzie do liczby wiêkszej od 9, zwraca false.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
* @param w wspó³rzêdne pola, dla którego sprawdzana jest wartoœæ
*/
bool zwiekszWartosc(int tab[9][9], Wsp& w);

/** Funkcja rozwi¹zuj¹ca sudoku.
* Testuje kolejne mo¿liwe wartoœæi, dla ka¿dego z pól, które jest nieuzupe³nione.
* Jeœli znajdzie wszystkie poprawne wartoœci zwraca true i sudoku jest rozwi¹zane.
* Jeœli nie mo¿na dla któregoœ pola znaleŸæ poprawnej wartoœci to znaczy, ¿e sudoku jest niepoprawne i funkcja zwraca false.
* Jeœli nie ma ¿adnej wspó³rzêdnej do rozwi¹zania, funkcja zwraca false.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
* @param wspolrzedne wspó³rzêdne pól, dla których trzeba znaleŸæ wartoœæ
*/
bool rozwiaz(int tab[9][9], vector<Wsp>& wspolrzedne);

/**
* Zapisuje rozwi¹zane sudoku do pliku tekstowego.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
* @param sciezka œcie¿ka do pliku, w którym ma byæ zapisane rozwi¹zane sudoku
*/
bool zapiszWynik(int tab[9][9], string sciezka);

/**
* Wypisuje do konsoli planszê sudoku.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj¹ca planszê
*/
void wypiszWynik(int tab[9][9]);