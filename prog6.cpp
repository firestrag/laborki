#include <iostream>

using namespace std;

struct node{
    int info = 0;
    node* next = NULL;
    node* prev = NULL;
};

struct list{
    node* head = NULL;
    node* tail = NULL;
    int size = 0;

    void out(){
        node* tmp = head;
        for(;tmp;tmp=tmp->next){
            std::cout << tmp->info << " ";
        }
        std::cout << std::endl;
    }

    void addLast(int info){
        size++;

        if(!tail){
            head = new node;
            tail = head;
            tail->info = info;
            return;
        }

        node* tmp = new node;
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
        tail->info = info;

    }

    void insert_sort(){
        if(!head) return;

        node* next_sort_el = head->next;

        int i =0;

        for(;next_sort_el; next_sort_el=next_sort_el->next){
            node* tmp = next_sort_el;      /// adres przestawianego elementu


            /// usuniecie zamienianego elementu z listy z listy
            node* tmp2 = tmp->prev;
            if(tmp->next){
                node* tmp3 = tmp->next;

                tmp2->next = tmp3;
                tmp3->prev = tmp2;
            }else{
                tmp2->next=NULL;
            }

            cout << "asd" << endl;
            int i=0;
            for(;tmp2->prev && tmp2->info < tmp->info;tmp2=tmp2->prev ){
                i++;
                if(i>this->size){
                    cout << "Debug info: " << endl;

                    cout << "tmp2: " << tmp2 << endl;
                    cout << "tmp2->next: " << tmp2->next << endl;
                    cout << "tmp2->prev: " << tmp2->prev << endl;

                    tmp2 = tmp2 -> prev;
                    cout << "tmp0: " << tmp2 << endl;
                    cout << "tmp0->next: " << tmp2->next << endl;
                    cout << "tmp0->prev: " << tmp2->prev << endl;

                    for(;;);
                }
            }
            //this->out();
            cout << "xyz" << endl;

            cout << tmp2->info << "  " << tmp->info << endl;

            if(tmp2->info < tmp->info){
                if(tmp2->prev){
                    cout << "1" << endl;
                    tmp->next = tmp2->next;
                    tmp->prev = tmp2;
                    tmp2=tmp->next;
                    tmp2->prev = tmp;
                }else{
                    cout << "2" << endl;
                    tmp -> next = tmp2;
                    tmp->prev=NULL;
                    tmp2->prev = tmp;
                    this->head = tmp;
                }
            }else{
                cout << "3" << endl;
                node* tmp3 = tmp2->next;
                /*tmp->next = tmp3;
                tmp3->prev = tmp;
                tmp2 = tmp->next;*/

                tmp2->next = tmp;
                tmp->next = tmp3;
                if(tmp3)tmp3->prev=tmp;
                tmp->prev=tmp2;



                /*if(tmp2){
                    tmp2->prev = tmp;
                }*/
            }





            this->out();
        }
    }
};


void out(int tab[], int size){
    for(int i=0; i<size; i++){
        std::cout << tab[i] << " " ;
    }
    std::cout << std::endl;
}

void insert_sort(int tab[], int size){

    int j, tmp;
    for(int i=1; i<size; i++){
        tmp = tab[i];
        for(j=i-1; j>=0 && tab[j]<tmp; j--){
            tab[j+1] = tab[j];
        }
        tab[j+1] = tmp;
    }

}

int main(){

    list l1;

    l1.addLast(5);
    l1.addLast(4);
    l1.addLast(3);
    l1.addLast(8);
    l1.addLast(7);
    l1.addLast(2);
    l1.addLast(5);
    l1.addLast(9);
    l1.addLast(4);
    l1.addLast(2);
    l1.addLast(3);

    l1.out();
    l1.insert_sort();
    l1.out();


    /*int tab[] = {5, 6, 8, 1, 0, 9, 7, 6, 5};
    int size = sizeof(tab)/4;


    out(tab, size);
    insert_sort(tab, size);
    out(tab, size);*/

    return 0;
}
