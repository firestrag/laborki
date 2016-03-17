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

    node* head = NULL;

    add(&head, 5, 0);
    add(&head, 15, 0);
    add(&head, 18, 1);
    add(&head, 29, 3);
    add(&head, 24, 3);
    add(&head, 27, 3);
    add(&head, 28, 3);
    usun(&head, 0);
    usun(&head, 3);
    usun(&head, 4);
    usun(&head, 4);
    usun(&head, 0);
    usun(&head, 0);
    usun(&head, 0);
    usun(&head, 0);
    show(head);


    return 0;
}
