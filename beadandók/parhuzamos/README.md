1. pthread :

- Feladat leirása: Hatékonyan összeszorozni két nagyméretü mátrixot.

- Mérési folyamat:

Futásidő: A program futásidejét másodpercekben mérjük.

Problémaméret: A felhasználótól bekért mátrix mérete meghatározza a probléma méretet.

Szálak száma: A program 1-10 szálon való futás idejét nézi meg.

Mérési pontok: A programban több futásidő mérés történik különböző szálak száma mellett, hogy lássuk a szálak számának hatását a futásidőre nézve.

- Eredmények:

How big should the matrix be? : 1000
Time taken with 1 threads: 5.373726 seconds
Time taken with 2 threads: 3.291818 seconds
Time taken with 3 threads: 2.451364 seconds
Time taken with 4 threads: 2.088667 seconds
Time taken with 5 threads: 1.822057 seconds
Time taken with 6 threads: 1.611161 seconds
Time taken with 7 threads: 1.461408 seconds
Time taken with 8 threads: 1.320308 seconds
Time taken with 9 threads: 1.217560 seconds
Time taken with 10 threads: 1.142882 seconds

2. OpenMp :

- Feladat leirása: A program egy példa függvény (jelen esetben a sinus) Taylor sorbafejtését számolja ki a megadott x és a pontok körül amelyek random számok. Ehhez több szálon végzi el a számítást OpenMP segítségével.

- Mérési folyamat:

Futásidő: 1-től 10 szálig futtatja a Taylor sor kiszámítását, minden egyes számításhoz méri az eltelt időt.

Problémaméret: A felhasználótól kérjük be, ami a Taylor sorban felhasznált tagok számát jelenti.

Mérési pontok: Kiírja a futási időt mindegyik számítás mellett, megjelenítve, hogy milyen gyorsan hajtotta végre a programot az egyes szálak száma mellett.

Please enter the problem size (number of terms in the Taylor series): 100 000 000
Time taken with 1 thread(s): 6.243113 seconds
Time taken with 2 thread(s): 3.518711 seconds
Time taken with 3 thread(s): 2.374051 seconds
Time taken with 4 thread(s): 1.939701 seconds
Time taken with 5 thread(s): 1.589735 seconds
Time taken with 6 thread(s): 1.456865 seconds
Time taken with 7 thread(s): 1.371542 seconds
Time taken with 8 thread(s): 1.304944 seconds
Time taken with 9 thread(s): 1.294432 seconds
Time taken with 10 thread(s): 1.275210 seconds

3. Java ForkJoinPool

- Feladat leirása: A program célja a Merge Sort algoritmus párhuzamos megvalósításának bemutatása Java-ban a Fork/Join keretrendszer segítségével. Egy tömb egész számok párhuzamos rendezését végzi el

- Mérési folyamat:

Futásidő: Kiírja a futási időt a megadott probléma méretre és szál/ak-ra.

Problémaméret: A felhasználótól kérjük be, ekkora lesz a tömb amiben dolgozunk.

Mérési pontok:

Sorting the array with 1 thread(s): 17.566 seconds
Sorting the array with 2 thread(s): 9.553 seconds
Sorting the array with 4 thread(s): 5.176 seconds
Sorting the array with 8 thread(s): 2.892 seconds
Sorting the array with 16 thread(s): 1.684 seconds
Sorting the array with 32 thread(s): 0.961 seconds