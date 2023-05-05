#include "funkcje.h"

using namespace std;

void pomoc() {
    cout << "Nalezy podac argumenty:" << endl;
    cout << "-i plik_wejsciowy -o plik_wyjsciowy" << endl;
}

string wczytajZnak(ifstream& plik, int x) {
    const char SEPARATOR = ';';
    string napis;
    if (x == 8) {
        getline(plik, napis);
    }
    else {
        getline(plik, napis, SEPARATOR);
    }
    return napis;
}

void dodajWsp(int tab[9][9], vector<Wsp>& wspolrzedne, int x, int y) {
    Wsp w;
    w.x = x;
    w.y = y;
    wspolrzedne.push_back(w);
    tab[y][x] = 0;
}

void wczytajKomorke(ifstream& plikwe, int tab[9][9], int x, int y, vector<Wsp>& wspolrzedne) {
    string napis = wczytajZnak(plikwe, x);
    if (napis == "x") {
        dodajWsp(tab, wspolrzedne, x, y);
    }
    else {
        istringstream str(napis); // tworzy strumien str ze zmiennej napis
        int liczba;
        str >> liczba; // wczytuje ze strumienia wartosc do zmiennej liczba 
        tab[y][x] = liczba;
    }
}

bool wczytaj(int tab[9][9], vector<Wsp>& wspolrzedne, string sciezka) {
    ifstream plikwe(sciezka);
    if (plikwe.is_open()) {
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                wczytajKomorke(plikwe, tab, x, y, wspolrzedne);
            }
        }
        plikwe.close();
    }
    else {
        return false;
    }
    return true;
}

bool istniejeWWierszu(int tab[9][9], Wsp& w, int wartosc) {
    for (int x = 0; x < 9; x++) {
        if (tab[w.y][x] == wartosc) {
            return true;
        }
    }
    return false;
}

bool istniejeWKolumnie(int tab[9][9], Wsp& w, int wartosc) {
    for (int y = 0; y < 9; y++) {
        if (tab[y][w.x] == wartosc) {
            return true;
        }
    }
    return false;
}

int poczatekKwadratu(int liczba) {
    if (liczba < 3) {
        return 0;
    }
    else if (liczba < 6) {
        return 3;
    }
    else {
        return 6;
    }
}

bool istniejeWKwadracie(int tab[9][9], Wsp& w, int wartosc) {
    const int pky = poczatekKwadratu(w.y);
    const int kky = pky + 3;
    const int pkx = poczatekKwadratu(w.x);
    const int kkx = pkx + 3;
    for (int j = pky; j < kky; j++) {
        for (int i = pkx; i < kkx; i++) {
            if (tab[j][i] == wartosc) {
                return true;
            }
        }
    }
    return false;
}

bool wartoscPrawidlowa(int tab[9][9], Wsp& w, int wartosc) {
    if (!istniejeWWierszu(tab, w, wartosc)
        && !istniejeWKolumnie(tab, w, wartosc)
        && !istniejeWKwadracie(tab, w, wartosc)) {
        return true;
    }
    return false;
}

bool zwiekszWartosc(int tab[9][9], Wsp& w) {
    int wartosc = tab[w.y][w.x];
    tab[w.y][w.x] = 0;
    wartosc++;
    if (wartosc > 9) {
        return false;
    }
    else if (wartoscPrawidlowa(tab, w, wartosc)) {
        tab[w.y][w.x] = wartosc;
        return true;
    }
    else {
        tab[w.y][w.x] = wartosc;
        return zwiekszWartosc(tab, w);
    }
}

bool rozwiaz(int tab[9][9], vector<Wsp>& wspolrzedne) {
    if (wspolrzedne.size() == 0) {
        return false;
    }
    for (int i = 0; i < wspolrzedne.size(); i++) {
        if (!zwiekszWartosc(tab, wspolrzedne[i])) {
            if (i == 0) {
                return false;
            }
            else {
                i = i - 2;
            }
        }
    }
    return true;
}

bool zapiszWynik(int tab[9][9], string sciezka) {
    ofstream plikwe(sciezka);
    if (plikwe.is_open()) {
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                plikwe << tab[y][x] << " ";
            }
            plikwe << endl;
        }
        plikwe.close();
    }
    else {
        return false;
    }
    return true;
}

void wypiszWynik(int tab[9][9]) {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            cout << tab[y][x] << " ";
        }
        cout << endl;
    }
}