#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double Gauss(double a[100][100], int n) {
    ofstream g("date.out");
    int i, j, k, l, coef_det = 1, linie_pivot, b, c;
    double det = 1, aux, coeficient;
    for(j = 0; j < n-1; j++) {
        //cautam pe fiecare coloana o prima valoare nenula
        i = j;
        while (i < n){
            if (a[i][j] != 0) {
                linie_pivot = i;
                break;
            }
            i++;
        }
        // daca nu exista valori nenule pe coloana j, trecem la coloana urmatoare
        if (linie_pivot == n)
            continue;
        // daca linia pivotului nu se afla exact sub linia pivotului anterior, le interschimbam
        if (linie_pivot != j) {
            // retinem modificarea determinantului prin interschimbarea a doua linii
            coef_det *= (-1);
            for (k = 0; k < n; k++) {
                aux = a[j][k];
                a[j][k] = a[linie_pivot][k];
                a[linie_pivot][k] = aux;
            }
        }
        // facem zerouri pe coloana pivotului sub acesta
        for (l = j + 1; l < n; l++) {
            coeficient = a[l][j] / a[j][j];
            for (k = j; k < n; k++)
                a[l][k] -= coeficient * a[j][k];
        }
    }
    // afisare matrice pentru verificare
    g << "Forma esalon:\n";
    for (b = 0; b < n; b++) {
        for (c = 0; c < n; c++)
            g << a[b][c] << " ";
        g << endl;
    }
    // calculam determinantul ca fiind produsul elementelor de pe diagonala principala
    for(i = 0; i < n; i++ )
        det *= a[i][i];
    // rezultatul este det calculat anterior la care inmultim ce am retinut
    return det * coef_det;
}


double recursiva(double a[100][100], int n, int vcol[100], int liniecrt = 0 ) {
    double det = 0;
    // determinantul pentru matrice 1x1
    if (n == 1) return a[liniecrt][vcol[0]];
    // determinantul pentru matrice 2x2
    if(n == 2)
        return a[liniecrt][vcol[0]] * a[liniecrt+1][vcol[1]] - a[liniecrt][vcol[1]] * a[liniecrt+1][vcol[0]];
    else {
        int poz;
        // pt fiecare element de pe prima linie calculam el*semn*det_submatrice
        for(poz = 0; poz < n; poz++) {
            int vcolaux[n], i, k = 0;
            // retinem ce coloane apar in submatrice
            for(i = 0; i < n; i++)
                if(i != poz)
                    vcolaux[k++] = vcol[i];
            // calculam determinantul pentru matrice cu apeluri recursive pentru determinantul submatricelor acesteia
            det += recursiva(a, n-1, vcolaux, liniecrt+1) * a[liniecrt][vcol[poz]] * pow((-1),poz);
        }
        return det;
    }
}


