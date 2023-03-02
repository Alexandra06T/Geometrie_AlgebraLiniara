# Calculul determinantului unei matrice

### Utilizare program/ Input
Programul are doua moduri de functionare.
1. In urma optarii in consola pentru modul **1**, datele sunt generate aleatoriu, transcrise in fisierul *date.in* (din folderul *cmake-build-debug*) si apoi procesate. Pentru ca finalizarea rularii sa aiba loc intr-un timp rezonabil, dimensiunea matricei si elementele generate vor fi mici.
2. Datele sunt introduse manual si salvate in fisierul *date.in*, apoi in consola se opteaza pentru modul **0** si se apasa pe tasta ENTER.

### Output
Programul calculeaza determinantul matricei introduse prin doua metode si afiseaza pentru fiecare **rezultatul obtinut** si **timpul de executie**.

### Observatii in urma rularii
Se observa ca pentru dimensiuni mici ale matricei, metoda recursiva este mai rapida, dar pentru dimensiuni mai mari, metoda Gauss se dovedeste a fi mult mai utila.

### Descriere fisiere utilizate
Fisierul *functii.hpp* contine functia Gauss, 
ce calculeaza matricea prin metoda Gauss, aducand-o la
forma esalon (aceasta poate fi verificata in fisierul *date.out* din folderul cmake-build-debug),
si functia recursiva, ce calculeaza determinantul prin 
expansiune Laplace.

### Mentiuni
Secventele de cod pentru calcularea timpului de executie au fost preluate de pe (https://www.geeksforgeeks.org/measure-execution-time-function-cpp/).

