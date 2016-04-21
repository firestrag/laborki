#include <iostream>
using namespace std;

/**
    @desc Funkcja do wypisywania tablicy
    @param (int[]) tab  WstaŸnik na tablicê do wypisania
    @param ( int ) size Rozmiar tablicy
*/
void out(int tab[], int size){
    /// 80 znaków = dla oddzielenia od reszty
    /// 80 - tyle wynosi domyœlnie szerokoœæ konsoli
    for(int i=0; i<80; i++) cout << "=";
    for(int i=0; i<size; i++){
        cout << "tab[ " << i << " ]: " << tab[i] << endl;
    }
}

/**
    @desc Sortuje tablice metod¹ mege_sort
    @param (int[] ) tab WskaŸnik na tablice do posortowania
    @param ( int ) l    Indeks elementu w tablicy od którego w³¹cznie ma byæ sortowane
    @param ( int ) p    Indeks elementu w tablicy do którego w³¹cznie ma byæ sortowane
*/
void merge_sort(int tab[], int l, int p){
    /**
        @var Œrodkowa pozycja
    */
    int s = (p+l)/2;

    /// jeœli œrodkowa pozycja jest wiêksz od lewej, oznacza to, ¿e podany fragment tablicy ma wiêcej ni¿ jeden element
    /// ewentualnie mo¿na zastosofaæ if( l == p )
    if( s>l ){
        /// wykon¹j t¹ procedurê dla lewej czêœci podanej tablicy
        merge_sort(tab, l, s);
        /// wykonaj t¹ procedurê dla prawej czêœci podanej tablicy
        merge_sort(tab, s+1, p);
    }

    /**
        @var Rozmiar tablicy t1
    */
    int l_size = s-l+1;

    /**
        @var Rozmiar tablicy t2
    */
    int p_size = p-s;

    /**
        @var Tymczasowa tablica przechowuj¹ca elementy po lewej stronie tablicy przekazanej do funkcji
    */
    int t1[l_size];
    /**
        @var Tymczasowa tablica przechowuj¹ca elementy po prawej stronie tablicy przekazanej do funkcji
    */
    int t2[p_size];

    /// skopiowanie danych z przekazanej tablicy do tablic tymczasowaych
    for(int i=l; i<=s; i++) t1[i-l]=tab[i];
    for(int i=s; i<=p; i++) t2[i-s-1]=tab[i];

    /**
        @var Zmienna przechowuje numer indeksu kolejnego elemntu do porównania w tablicy t1
    */
    int tmp_l = 0;

    /**
        @var Zmienna przechowuje numer indeksu kolejnego elemntu do porównania w tablicy t2
    */
    int tmp_p = 0;

    /**
        @var Zmienna steruj¹ca pêtl¹, jej zakres to od l do p obustronnie w³¹cznie, gdy¿ sortowany jest tylko przekazany fragment
    */
    int i = l;

    /// pêtla wykonuje siê dla ca³ego podanego fragmentu przekazanej tablicy
    for(; i<=p; i++){

        if(tmp_l >= l_size){/// jeœli tmp_l wiêksze b¹dŸ równe maksymalnej iloœci elementów w tablicy t1
            /// przekopiuj do przekazanej tablicy pod indeks i dane z t2 z miejsca o indeksie tmp_p i go zwiêksz
            tab[i] = t2[tmp_p];
            tmp_p++;
        }else if( tmp_p >= p_size){/// jeœli tmp_p wiêksze b¹dŸ równe maksymalnej iloœci elementów w tablicy t2
            /// przekopiuj do przekazanej tablicy pod indeks i dane z t1 z miejsca o indeksie tmp_l i go zwiêksz
            tab[i] = t1[tmp_l];
            tmp_l++;
        }else{
            /// jeœli aktualnie wskazywana zmienna przez tmp_l w t1 jest wiêksza od aktualnie wskazywanej zmiennej przez tmp_p w 2
            if( t1[tmp_l] > t2[tmp_p] ){
                /// skopiuj do przekazanej tablicy pod indeks i dane z t1 z miejsca o indeksie tmp_l i go zwiêksz
                tab[i] = t1[tmp_l];
                tmp_l++;
            }else{  /// WPP
                /// skopiuj do przekazanej tablicy pod indeks i dane z t2 z miejsca o indeksie tmp_p i go zwiêksz
                tab[i] = t2[tmp_p];
                tmp_p++;
            }
        }
    }

}

int main(){

    /**
        @var Tablica liczb
    */
    int tab[] = {5, 10, 6, 8, 4, 7, 3, 9, 2};

    /**
        @var Iloœæ elementów w tablicy
        @info Rozmiar jaki zajmuje zmienna typu (int) nie jest zdefiniowany w standardzie jêzyka i mo¿e byæ ró¿ny w zale¿noœci od kompilatora
    */
    int size = sizeof(tab) / sizeof(int);

    /// wypisuje tablice przed posortowaniem
    out(tab, size);

    /// sortowanie tablicy
    merge_sort(tab, 0, size-1);

    /// wypisuje tablice po posortowaniu
    out(tab, size);

    return 0;
}


