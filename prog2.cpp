#include <iostream>

using namespace std;

#define SIZE 10
#define EMPTY -1

/**
    @var Wskazuje, na ostatni zaj�ty element, warto�� EMPTY (-1) je�li kolejka jest pusta
*/
int tail = EMPTY;

/**
    @var Wskazuje na pierwszy zaj�ty element, je�li kolejka jest pusta, to wskazuje na pierwszy element do zapisania
*/
int head = 0;

/**
    @var tablica - kolejka
*/
int kolejka[SIZE]={};

/**
    @desc Sprawdza czy kolejka jest pustu
    @return (bool) TRUE - je�li kolejka jest pusta, wpw - FALSE
*/
bool isEmpty(){
    if(EMPTY == tail)
        return true;
    return false;
}

/**
    @desc Sprawdza czy kolejka jest pe�na
    @return (bool) TRUE - je�li kolejka jest pe�na, wpw - FALSE
*/
bool isFull(){
    if( isEmpty() ) return false;
    if( tail != head) return false;
    return true;
}

/**
    @desc Dodaje element na koniec kolejki
    @param (int) liczba Liczba, kt�ra ma zosta� dodana do kolejki
    @return (bool) TRUE - je�li uda�o si�doda� element do kolejki, wpw. FALSE
*/
bool enqueue(int liczba){

    /// je�li kolejka jest pe�na zwr�� informacje, �e nie mo�na doda� kolejnego elementu
    if( isFull() ) return false;

    /// je�li kolejka jest pusta ustaw miejsce zapisu, na miejsce na kt�e wskazuje g�owa
    if( EMPTY == tail){
        tail = head;
    }

    /// wstaw element do kolejki
    kolejka[tail] = liczba;

    /// przesu� $tail o jedno miejsce dalej
    tail++;

    /// je�li $tail jest poza zakresem wielko�ci tablicy kolejki, przesu� go na pocz�tek tablicy
    if( SIZE == tail){
        tail = 0;
    }

    /// zwr��informacj�, �e uda�o si�doda� element
    return true;
}

/**
    @desc Usuwa pierwszy element z kolejki
    @return (int) Warto�� elementu kt�ry zosta� uzuni�ty || NULL - je�li kolejka pusta
*/
int dequeue(){

    /// je�li kolejka pusta
    if( isEmpty() ) return (int)NULL;

    /// zapisz element do zwrotu i przesu� $head o jedno miejsce dalej
    int ret = kolejka[head];
    head++;
    /// je�li $head wykracza poza zakres tablicy kolejki ustaw $head na pocz�tek tablicy kolejki
    if(SIZE == head){
        head = 0;
    }

    /// je�li $head znajduje si�w tym samym miejscu co $tail to oznacza, �e �ci�gni�to ostatni element z kolejki
    if( head == tail){
        tail = EMPTY;   /// ustaw $tail na EMPTY (-1), oznacza to, �e kolejka jest pusta
        head = 0;       /// ustawia $head na samym pocz�tku tablicy
    }

    /// zwr�� �ci�gni�ty element
    return ret;
}

/**
    @desc Wy�wietla wszystkie elementy kolejki bez zachowania kolejno�ci oraz ilo��i(tryb debugowania)
*/
void d_show(){
    for(int i=0; i<SIZE; i++){
        cout << "tab[" << i << "] = " << kolejka[i] << endl;
    }
}

/**
    @desc Zwraca ilo�� element� w kolejce
    @return (int) ilo�� element�w w kolejce
*/
int getSize(){
    if( isEmpty() ) return 0;
    int ret = 0;
    if(head >= tail){
        ret += SIZE - head;
        ret += tail;
    }else{
        ret = tail - head;
    }

    return ret;
}

/**
    @desc Wy�wietla elementu w kolejce w odpowiedniej kolejno��i, wraz z informacj� w kt�rej kom�re tablicy kolejki si� one znajduj�
*/
void show(){
    /// je�li kolejka jest pusta
    if( isEmpty() ){
        cout << "Kolejka jest pusta!" << endl;
        return;
    }


    int last = tail;
    int qaz = tail;
    if(head >= tail){
            last = SIZE;
    }

    for(int i=head; i<last; i++){
        cout << "tab[" << i << "] = " << kolejka[i] << endl;
    }

    last = 0;
    if( head>= tail){
        last = tail;
        for(int i=0; i<tail; i++){
            cout << "tab[" << i << "] = " << kolejka[i] << endl;
        }
    }
}

/**
    @desc Wy�wietla menu
    @return Zwraca informacje co wybra�u�ytkownik: 1 - dodanie elementu, 2 - usuni�czie elementu, 3 - wy�wietlenie kolejki, 4-wy�wietlenie kolejki w trybie dobugowania, 0 - zako�czenie probramu
*/
int menu(){
    int wybor = -1;
    do{
        for(int i=0; i<38; i++) cout << "=";
        cout << "MENU";
        for(int i=0; i<38; i++) cout << "=";

        cout << "Wybierz co chcesz zrobic:" << endl
        << "1) dodanie elementu na koncu kolejki" << endl
        << "2) usuniecie elementu z poczatku kolejki" << endl
        << "3) wyswietlic kolejke" << endl
        << "4) wyswietlic kolejke w trybie debudowania" << endl
        << "5) wyswietlic ilosc elementow w kolejce" << endl
        << "0) wyjsc" << endl;

        cout << "Twoj wybor: ";
        cin >> wybor;

    }while(wybor < 0 || wybor > 6);

    return wybor;
}

int main(){
    int wybor = 0;
    do{
        wybor = menu();
        switch(wybor){
        case 1:
            if( isFull() ){
                cout << "Kolejka jest pelna!!!" << endl;
                break;
            }
            int a;
            cout << "Podaj liczbe: ";
            cin >> a;
            enqueue(a);
            break;
        case 2:
            if( isEmpty() ){
                cout << "Kolejka jest pusta!!!" << endl;
                break;
            }
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            d_show();
            break;
        case 5:
            cout << getSize() << endl;
            break;
        }
    }while(wybor);


    return 0;
}
