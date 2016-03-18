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

    return i;
}

/**
    @desc Informuje, czy są elementy w liście
    @param (node*) head Wskaźnik na główny(pierwszy) element listy
    @return (bool) Informacja o tym ile jest elementó w liście
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



int main(){

    node* stos = NULL;
    node* kolejka = NULL;

    for(;;){
        int wybor = 0;
        cout << "Wybierz:\n"
        << "1 - aby dodac element do stosu\n"
        << "2 - aby usunac element ze stosu\n"
        << "3 - aby wyswietlic ilosc elementow na stosie\n"
        << "4 - aby wyswietlic stos\n"
        << "5 - aby wyswietlic informacje czy stos jest pusty\n"

        << "11 - aby dodac element do kolejki\n"
        << "12 - aby usunac element z kolejki\n"
        << "13 - aby wyswietlic ilosc elementow w kolejce\n"
        << "14 - aby wyswietlic kolejke\n"
        << "15 - aby wyswietlic informacje czy kolejka jest pusta\n"

        << "0 - aby zakonczyc dzialanie programu\n"
        << "Wybor: ";

        cin >> wybor;

        switch(wybor){
        case 0:
            return 0;

        case 1:
            cout << "Wprowadz liczbe jaka chcesz dodac na stos:";
            cin >> wybor;
            add(&stos, wybor, size(stos));
            break;
        case 2:
            if(!size(stos)){
                cout << "Stos pusty!!!" << endl;
                break;
            }
            usun(&stos, size(stos)-1);
            break;
        case 3:
            cout << size(stos) << endl;
            break;
        case 4:
            if(!size(stos)){
                cout << "Stos pusty"<< endl;
                break;
            }
            show(stos);
            break;
        case 5:
            if(size(stos)){
                cout << "Stos nie jest pusty"<< endl;
            }else{
                cout << "Stos jest pusty" << endl;
            }
            break;

        case 11:
            cout << "Wprowadz liczbe jaka chcesz dodac do kolejki:";
            cin >> wybor;
            add(&kolejka, wybor, size(kolejka));
            break;
        case 12:
            if(!size(kolejka)){
                cout << "Kolejka pusta!!!" << endl;
                break;
            }
            usun(&kolejka, 0);
            break;
        case 13:
            cout << size(kolejka) << endl;
            break;
        case 14:
            if(!size(kolejka)){
                cout << "Kolejka pusta"<< endl;
                break;
            }
            show(kolejka);
            break;
        case 15:
            if(size(kolejka)){
                cout << "Kolejka nie jest pusta"<< endl;
            }else{
                cout << "Kolejka jest pusta" << endl;
            }
            break;

        default:
            cout << "Zostala wybrana bledna opcja!!!" << endl;
        }

    }


    return 0;
}
