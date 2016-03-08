#include <iostream>

using namespace std;

#define SIZE 10
#define EMPTY -1

/**
    @var Wskazuje, na ostatni zajêty element, wartoœæ EMPTY (-1) jeœli kolejka jest pusta
*/
int tail = EMPTY;

/**
    @var Wskazuje na pierwszy zajêty element, jeœli kolejka jest pusta, to wskazuje na pierwszy element do zapisania
*/
int head = 0;

/**
    @var tablica - kolejka
*/
int kolejka[SIZE]={};

/**
    @desc Sprawdza czy kolejka jest pustu
    @return (bool) TRUE - jeœli kolejka jest pusta, wpw - FALSE
*/
bool isEmpty(){
    if(EMPTY == tail)
        return true;
    return false;
}

/**
    @desc Sprawdza czy kolejka jest pe³na
    @return (bool) TRUE - jeœli kolejka jest pe³na, wpw - FALSE
*/
bool isFull(){
    if( isEmpty() ) return false;
    if( tail != head) return false;
    return true;
}

/**
    @desc Dodaje element na koniec kolejki
    @param (int) liczba Liczba, która ma zostaæ dodana do kolejki
    @return (bool) TRUE - jeœli uda³o siêdodaæ element do kolejki, wpw. FALSE
*/
bool enqueue(int liczba){

    /// jeœli kolejka jest pe³na zwróæ informacje, ¿e nie mo¿na dodaæ kolejnego elementu
    if( isFull() ) return false;

    /// jeœli kolejka jest pusta ustaw miejsce zapisu, na miejsce na któe wskazuje g³owa
    if( EMPTY == tail){
        tail = head;
    }

    /// wstaw element do kolejki
    kolejka[tail] = liczba;

    /// przesuñ $tail o jedno miejsce dalej
    tail++;

    /// jeœli $tail jest poza zakresem wielkoœci tablicy kolejki, przesuñ go na pocz¹tek tablicy
    if( SIZE == tail){
        tail = 0;
    }

    /// zwróæinformacjê, ¿e uda³o siêdodaæ element
    return true;
}

/**
    @desc Usuwa pierwszy element z kolejki
    @return (int) Wartoœæ elementu który zosta³ uzuniêty || NULL - jeœli kolejka pusta
*/
int dequeue(){

    /// jeœli kolejka pusta
    if( isEmpty() ) return (int)NULL;

    /// zapisz element do zwrotu i przesuñ $head o jedno miejsce dalej
    int ret = kolejka[head];
    head++;
    /// jeœli $head wykracza poza zakres tablicy kolejki ustaw $head na pocz¹tek tablicy kolejki
    if(SIZE == head){
        head = 0;
    }

    /// jeœli $head znajduje siêw tym samym miejscu co $tail to oznacza, ¿e œci¹gniêto ostatni element z kolejki
    if( head == tail){
        tail = EMPTY;   /// ustaw $tail na EMPTY (-1), oznacza to, ¿e kolejka jest pusta
        head = 0;       /// ustawia $head na samym pocz¹tku tablicy
    }

    /// zwróæ œci¹gniêty element
    return ret;
}

/**
    @desc Wyœwietla wszystkie elementy kolejki bez zachowania kolejnoœci oraz iloœæi(tryb debugowania)
*/
void d_show(){
    for(int i=0; i<SIZE; i++){
        cout << "tab[" << i << "] = " << kolejka[i] << endl;
    }
}

/**
    @desc Zwraca iloœæ elementó w kolejce
    @return (int) iloœæ elementów w kolejce
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
    @desc Wyœwietla elementu w kolejce w odpowiedniej kolejnoœæi, wraz z informacj¹ w której komóre tablicy kolejki siê one znajduj¹
*/
void show(){
    /// jeœli kolejka jest pusta
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
    @desc Wyœwietla menu
    @return Zwraca informacje co wybra³u¿ytkownik: 1 - dodanie elementu, 2 - usuniêczie elementu, 3 - wyœwietlenie kolejki, 4-wyœwietlenie kolejki w trybie dobugowania, 0 - zakoñczenie probramu
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
