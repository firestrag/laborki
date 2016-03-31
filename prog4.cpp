#include <iostream>

using namespace std;

#include <iostream>
#include <cstdlib>
using namespace std;

/**
    taka tam struktura ;)
*/
struct node{
    int info;   /// przechowywana informacja
    node* next; /// wskaźnik na kolejny element struktury
};

/**
    @desc Zlicza elementy w liście
    @param (node*) head - wskaźnik na główny element listy
    @return (int) Ilość elementó w liście
*/
int size(node* head){
    if(!head) return 0;


    int i = 1;
    node* element = head;

    while(element->next){
        i++;
        element = element->next;
    }
    //cout << "size(): " << i << endl;
    return i;
}

/**
    @desc Informuje, czy są elementy w liście
    @param (node*) head Wskaźnik na główny(pierwszy) element listy
    @return (bool) Informacja o tym ile jest elementów w liście
*/
bool isEmpty(node *head){
    /// jeśli head == NULL to (!head) zwróci TRUE (lista pusta)
    /// jeśli head != NULL to (!head) zwróci FALSE (jest coś w liście)
    return (!head);
}

/**
    @desc Dodaje element do listy
    @param (node**) head - adres wskaźnika na główny element liczby
    @param (int) liczba - liczba któa ma zostać dodana do kolejki
    @param (int) gdzie - index(liczone od 0) miejsca na któe ma zostać wstawiony element
    @desc (bool) Informacja czy udało sę dodać element do listy
*/
bool add(node **head, int liczba, int gdzie){

    /// można oddawać tylko po poprzednim elemencie, albo jako element główny
    if( gdzie > size(*head))
        return false;

    /// jeśli pusty dodaje na 0 element
    if(isEmpty(*head)){

        *head = new node;
        (*head)->info = liczba;
        (*head)->next = NULL;
        return true;
    }

    /// jeœli zamieniany jest g³ówny element(g³owa)
    if(0 == gdzie){
        node* el = new node;
        el->info = liczba;
        el->next = *head;
        *head = el;
        return true;
    }

    /// jeœli dodawany jest element w inno miejsce ni¿ na pocz¹tek
    node* el = *head;
    for(int i=0; i<gdzie-1; i++){
        el = el->next;
    }

    node* el2 = new node;
    el2->next = el->next;
    el2->info = liczba;
    el->next = el2;



    return true;
}

/**
    @desc Usówa wybrany element z listy
    @param (node**) head - adres wskaźnika na główny element listy
    @param (int) ktory - index elementu(liczone od 0), który ma zostać usunięty z listy
*/
void usun(node** head, int ktory){

    /// jeœli nie ma elementu o tym indexie(kolejka zamiera mniej elementow)
    if(ktory > size(*head))
        return;

    /// jeœli usuwany jest g³ówny element
    if(0 == ktory){
        node* el = *head;
        *head = (*head)->next;
        delete el;
        return;
    }

    /// usuwanie innego elementu
    node* el = *head;
    for(int i=0; i<ktory-1; i++){
        el = el->next;
    }

    node* el2 = el->next;
    if(el2 && el2->next){
        el->next = el2->next;
    }else{
        el->next = NULL;
    }

    delete el2;

    return;
}

/**
    @desc Wyświetla elementy w kolejce
    @param (node*) head - wskaźnik na głóny element kolejki
*/
void show(node* head){
    if(!head){
        cout << "Brak elementow w kolejce" << endl;
        return;
    }

    node* el = head;

    for(int i=0; el; i++){
        cout << "kolejka[ " << i << " ] = " << el->info << endl;
        el = el->next;
    }
}

int getFirstMore(node* el, int a){
    int ret = 0;

    int r =size(el);
    for(ret=0; ret<r; ret++){
        if( a < el->info){
            return ret;
        }
        el = el->next;
    }


    return ret;
}

void addSort(node** head, int a){
    int pos = getFirstMore(*head, a);
    //cout << ": " << pos << endl;
    add(head, a, pos);
}

void odwroc(node** head){

    /// nie mozna odwrocic jednego elementu lub listy pustej
    if(size((*head)) <= 1)
        return;

    node* tmp1 = *head; /// wskazuje na poczatek starej listy

    /// ustawia head na koniec
    for(;(*head)->next;){
        (*head) = (*head) -> next;
    }

    int r = size(tmp1);    /// rozmiar kolejki(ilosc elementow)
    //cout << "rozmiar: " << r <<endl;
    for(;r>0; r--){
        node *el = tmp1;
        for(int i=0;i<r-2; i++){
            el = el->next;
        }
        node* el2 = el->next;
        el2->next = el;
        //cout << "r: " << r  << "   el->next: " << el->next << endl;
    }

    tmp1->next = NULL;
}

void odwroc2(node** head){

    /// nie mozna odwrocic jednego elementu lub listy pustej
    if(size(*head) <= 1)
        return;

    if(size(*head) == 2){
        node* el = *head;
        node* el2 = (*head)->next;
        el2->next = el;
        el->next = NULL;
        *head = el2;
        return;
    }

    node* tmp1 = *head; /// wskazuje na poczatek starej listy

    /// ustawia head na koniec
    for(;(*head)->next;){
        (*head) = (*head) -> next;
    }

    node* el = tmp1;
    node* el2 = el->next;
    node* el3 = el2->next;

    for(;el3;){
        el2->next = el;
        el = el2;
        el2 = el3;
        el3 = el3->next;
        //cout << "dasasasasas" << endl;
    }

    //el3->next = el2;
    tmp1->next = NULL;
    (*head)->next = el;
    cout << (*head)->info << endl;
}

int main(){
    node* kolejka = NULL;

    for(;;){
        int wybor = 0;
        cout << "Wybierz:\n"
        << "1 - aby dodac w sposob posortowany\n"
        << "2 - aby wyswietlic kolejke\n"
        << "3 - aby odwrocic kolejke\n"
        << "0 - aby zakonczyc dzialanie programu\n"
        << "Wybor: ";

        cin >> wybor;

        switch(wybor){
        case 0:
            return 0;

        case 2:
            if(!size(kolejka)){
                cout << "Stos pusty"<< endl;
                break;
            }
            show(kolejka);
            break;

        case 1:
            cout << "Wprowadz liczbe jaka chcesz dodac do kolejki:";
            cin >> wybor;
            addSort(&kolejka, wybor);
            break;

        case 3:
            odwroc2(&kolejka);
            break;

        default:
            cout << "Zostala wybrana bledna opcja!!!" << endl;
        }

    }



    return 0;
}
