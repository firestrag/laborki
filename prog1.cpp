#include <iostream>
#include <cstdlib>

using namespace std;

#define n 10	// rozmiar tablicy

/**
	@desc Zwraca informacje o pełnym stosie
	@param (int*) top adres zmiennej przechowywującej informacje o ilości elementów na stosie(index pierwszego elementu na stosie)
	@return (bool) TRUE - jeśli stos jest pełny, wpp. FALSE
*/
bool isFull(int *top){
	if(*top >= n) 
		return true;
	return false;
}

/**
	@desc Zwraca informacje o pustym stosie
	@param (int*) top adres zmiennej przechowywującej informacje o ilości elementów na stosie(index pierwszego elementu na stosie)
	@return (bool) TRUE - jeśli stos jest pusty, wpp. FALSE
*/
bool isEmpty(int *top){
	if(*top)	 
		return false;
	return true;
}

/**
	@desc Dodaje element na stos
	@param (int) stos[] tablica stosu
	@param (int*)  top adres zmiennej przechowywującej informacje o ilości elementów na stosie(index pierwszego elementu na stosie)
	@param (int) element element do dodania na stosie
	@return (bool) TRUE - jeśli udało się dodać element na stos, FALSE jeśli stos przepełniony
*/
bool push(int stos[], int *top, int element){
	// jeśli stos przepełniony to zwróć infformację o tym, że nie można dodać elementu
    if( isFull(top) )
        return false;

	// dodaj element na stos
    stos[*top] = element;
    (*top)++;
    return true;
}

/**
	@desc Ściąga element ze stosu
	@param (int) stos[] tablica stosu
	@param (int*)  top adres zmiennej przechowywującej informacje o ilości elementów na stosie(index pierwszego elementu na stosie)
	@return (int) element na stosie, 0 jeśli stos jest pusty
*/
int pop(int stos[], int *top){
	// jeśli stos jest pusty zwróć NIC
    if( isEmpty(top) ){
        /// ?
        return 0;
    }

	// zdejmij element stosu i go zwróć
    (*top)--;
    return stos[*top];
}

/**
	@desc Wyświetla wszystkie lementy na stosie w kolejności od dolnego do górnego
	@param (int) stos[] tablica stosu
	@param (int*)  top adres zmiennej przechowywującej informacje o ilości elementów na stosie(index pierwszego elementu na stosie)
	@return (void)
*/
void show(int stos[], int *index){
	for(int i=0; i<*index; i++){
		std::cout << "stos[" << i << "] = " << stos[i] << std::endl;
	}
	return;
}

/**
	@desc Wyświetla menu
	@return (int) wybór: 1-dodaj element, 2-usuń element, 3-wyświet, 0-wyjście
*/
int menu(){

	int a = -1; // początkopwa wartość

	// dopóki nie wybrano poprawnej opcji
	while( a<0 || a > 3){
		/// pasek górny
		for(int i=0; i<38; i++){
			cout << "=";
		}
		cout << "MENU";
		for(int i=0; i<38; i++){
			cout << "=";
		}

		/// opcje
		cout << "Wybierz:\n1 - aby dodac element na stos\n2 - aby usunac element ze stosu\n3 - abny wiswietlic stos\n0 - aby wyjsc\n";
		cin >> a;
	}
	return a;
}

int main(int argc, char* argv[]){
	int stos[n]={};	/// stos
	int index = 0;	/// początek stosu

	int wybor = -1;
	while(wybor){
		wybor = menu();

		switch(wybor){
		case 1:
			if( isFull(&index) ){
				std::cout << "STOS PELNY!!!" << std::endl;
				break;
			}

			cout << "Podaj wartosc: ";
			int a;
			cin >> a;
			push(stos, &index, a);
			break;
		case 2:
			if( isEmpty(&index) ){
				std::cout << "STOS PUSTY!!!" << std::endl;
				break;
			}
			pop(stos, &index);
			break;
		case 3:
			show(stos, &index);
			break;
		}
	}


	return 0;
}
