#include <iostream>
#include <cstdlib>
#include "functii.hpp"
#include <chrono>
using namespace std::chrono;
using namespace std;

int main() {
    double a[100][100];
    int n, i, j, input;
    ofstream g("date.in");
    cout << "Daca doriti sa introduceti manual datele in fisier, apasati '0'.\nDaca doriti ca datele sa se genereze aleatoriu, apasati '1'.\n";
    cin >> input;
    if(input == 1) {
        srand(time(0));
        n = int(rand() % 10) + 1;
        g << n << endl;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                a[i][j] = -100 + static_cast <double> (rand()) / (static_cast <double> (100));
                g << a[i][j] << " ";

            }
            g << endl;
        }
    }
    g.close();
    ifstream f("date.in");

    f >> n;  //a o matrice cu n linii si n coloane

    // citire matrice
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            f >> a[i][j];
    auto start = high_resolution_clock::now();
    double gauss = Gauss(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Determinantul calculat prin metoda:\n";
    cout << "- Gauss: " << gauss << " --> timp de executie: "<< duration.count() << endl;

    // initial in vcol apar toate coloanele
    int vcol[n];
    for(i = 0; i < n; i++)
        vcol[i] = i;
    auto start2 = high_resolution_clock::now();
    double rec =  recursiva(a, n, vcol);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "- recursiva: " << rec << " --> timp de executie: " << duration2.count() << endl;
    f.close();
    return 0;
}