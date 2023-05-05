#include "funkcje.h"

int main(int argc, char** argv) {
    const string PARAM_WE = "-i";
    const string PARAM_WY = "-o";
    string plikWe;
    string plikWy;
    if (argc != 5) {
        pomoc();
        return -1;
    }
    else {
        for (int i = 1; i < argc; i += 2) {
            if (string(argv[i]) == PARAM_WE) {
                plikWe = string(argv[i + 1]);
            }
            else if (string(argv[i]) == PARAM_WY) {
                plikWy = string(argv[i + 1]);
            }
            else {
                pomoc();
                return -1;
            }
        }
    }
    cout << "Plik wejsciowy: " << plikWe << endl;
    cout << "Plik wyjsciowy: " << plikWy << endl;
    const int TAB_Y = 9;
    const int TAB_X = 9;
    int tab[TAB_Y][TAB_X];
    vector<Wsp> wspolrzedne;
    if (wczytaj(tab, wspolrzedne, plikWe)) {
        cout << "Sudoku wczytane do rozwiazania" << endl;
    }
    else {
        cout << "Nie udalo sie otworzyc pliku";
        return -1;
    }
    if (rozwiaz(tab, wspolrzedne)) {
        cout << "Sudoku rozwiazane poprawnie" << endl;
        if (zapiszWynik(tab, plikWy)) {
            wypiszWynik(tab);
        }
        else {
            cout << "Nie udalo sie zapisac pliku";
        }
    }
    else {
        cout << "Sudoku niepoprawne" << endl;
    }
}

