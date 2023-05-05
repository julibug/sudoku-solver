/** @file */
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;
/** struct Wsp
* Reprezentuje wsp�rz�dne zawarto�ci pola planszy sudoku.
*/
struct Wsp {
	int x;
	int y;
};

/** Wy�wietla pomoc.
*/
void pomoc();

/** Wczytuje kolejny znak z pliku tekstowego oddzielony separatorem ';'.
* @param plik plik tekstowy zawieraj�cy sudoku do rozwi�zania
* @param x wsp�rz�dna kolumny 
*/
string wczytajZnak(ifstream& plik, int x);

/**
* Dodaje do wektora wsp�rz�dne pola, w kt�rym znajduj� si� znak ,,x'' reprezentuj�cy niewype�nione pole w sudoku.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
* @param wpsolrzedne wektor zawieraj�cy dane utworzone na podstawie struktury Wsp
* @param x wsp�rz�dna kolumny
* @param y wsp�rz�dna wiersza
*/
void dodajWsp(int tab[9][9], vector<Wsp>& wspolrzedne, int x, int y);

/** 
* Wczytuje z pliku tekstowego warto�ci znajduj�ce si� w polach planszy sudoku oraz zapisuje wsp�rz�dne p�l planszy, kt�re trzeba uzupe�ni�.
* @param plikwe plik wej�ciowy zawieraj�cy sudoku do rozwi�zania
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
* @param x wsp�rz�dna kolumny
* @param y wsp�rz�dna wiersza
* @param wspolrzedne wektor, w kt�rym zapisywane s� wsp�rz�dne niewype�nionych p�l sudoku oznaczonych symbolem ,,x''
*/
void wczytajKomorke(ifstream& plikwe, int tab[9][9], int x, int y, vector<Wsp>& wspolrzedne);

/**
* Wczytuje sudoku do rozwi�zania. 
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
* @param wspolrzedne wektor, w kt�rym zapisywane s� wsp�rz�dne niewype�nionych p�l sudoku oznaczonych symbolem ,,x''
* @param sciezka �cie�ka do wej�ciowego pliku tekstowego
*/
bool wczytaj(int tab[9][9], vector<Wsp>& wspolrzedne, string sciezka);

/**
* Sprawdza czy dana warto�� istnieje w wierszu.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
* @param w wsp�rz�dne, dla kt�rych dla danej kolumny sprawdzane jest czy zadana warto�� wyst�puj� w kolejnych wierszach
* @param wartosc warto�� do sprawdzenia
*/
bool istniejeWWierszu(int tab[9][9], Wsp& w, int wartosc);

/**
* Sprawdza czy dana warto�� istnieje w kolumnie.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
* @param w wsp�rz�dne, dla kt�rych dla danego wiersza sprawdzane jest czy zadana warto�� wyst�puj� w kolejnych kolumnach
* @param wartosc warto�� do sprawdzenia
*/
bool istniejeWKolumnie(int tab[9][9], Wsp& w, int wartosc);

/**
* Wskazuje gdzie zaczyna si� kwadrat, w kt�rym nie mog� powt�rzy� si� liczby.
* @param liczba sprawdza gdzie dla danej warto�� znajduj� si� pocz�tek kwadratu
*/
int poczatekKwadratu(int liczba);

/** 
* Sprawdza czy dana warto�� istnieje w kwadracie.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
* @param w wsp�rz�dne, dla kt�rych sprawdzane jest czy dana warto�� istnieje w kwadracie
* @param wartosc warto�� do sprawdzenia
*/
bool istniejeWKwadracie(int tab[9][9], Wsp& w, int wartosc);

/** Sprawdza czy dana warto�� nie wyst�puje w wierszu, kolumnie oraz kwadracie i zwraca warto�� true, w przeciwnym wypadku false.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
* @param w wsp�rz�dne pola, dla kt�rego sprawdzana jest warto��  
* @param wartosc warto�� do sprawdzenia
*/
bool wartoscPrawidlowa(int tab[9][9], Wsp& w, int wartosc);

/** Pr�buje dopasowa� kolejne liczby do pola.
* Je�li wypr�bowana liczba jest prawid�owa, zwraca warto�� true, w przeciwnym wypadku funkcja wywo�uje sam� siebie i sprawdza liczb� o jeden wi�ksz�.
* Je�li dojdzie do liczby wi�kszej od 9, zwraca false.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
* @param w wsp�rz�dne pola, dla kt�rego sprawdzana jest warto��
*/
bool zwiekszWartosc(int tab[9][9], Wsp& w);

/** Funkcja rozwi�zuj�ca sudoku.
* Testuje kolejne mo�liwe warto��i, dla ka�dego z p�l, kt�re jest nieuzupe�nione.
* Je�li znajdzie wszystkie poprawne warto�ci zwraca true i sudoku jest rozwi�zane.
* Je�li nie mo�na dla kt�rego� pola znale�� poprawnej warto�ci to znaczy, �e sudoku jest niepoprawne i funkcja zwraca false.
* Je�li nie ma �adnej wsp�rz�dnej do rozwi�zania, funkcja zwraca false.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
* @param wspolrzedne wsp�rz�dne p�l, dla kt�rych trzeba znale�� warto��
*/
bool rozwiaz(int tab[9][9], vector<Wsp>& wspolrzedne);

/**
* Zapisuje rozwi�zane sudoku do pliku tekstowego.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
* @param sciezka �cie�ka do pliku, w kt�rym ma by� zapisane rozwi�zane sudoku
*/
bool zapiszWynik(int tab[9][9], string sciezka);

/**
* Wypisuje do konsoli plansz� sudoku.
* @param tab tablica o rozmiarze 9 na 9 reprezentuj�ca plansz�
*/
void wypiszWynik(int tab[9][9]);