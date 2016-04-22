#include <iostream>

using namespace std;

void out(int tab[], int size){
    for(int i=0; i<80; i++) cout << "=";
    for(int i=0; i<size; i++){
        cout << "tab[ " << i << " ]:  " << tab[i] << endl;
    }
}

void quick_sort_lomuto(int tab[], int left, int right){

    int pivot=tab[right];
    int j=left;
    int i=left;

    for (; i < right ; i++)
        if (tab[i]<=pivot){
            swap(tab[i], tab[j]);
            j++;
        }
    swap(tab[j], tab[right]);

    if(right > j) quick_sort_lomuto(tab, left, j-1);
    if(left < i) quick_sort_lomuto(tab, j+1, right);
}

void quick_sort_hoare(int tab[], int left, int right){
    if( right-left <= 0 )
        return;

    int pivot = tab[ (left + right)/2 ];
    int l = left;
    int r = right;

    for(;l<r;){
        for(;tab[l]<pivot; l++);
        for(;tab[r]>pivot; r--);

        if( l<=r ){
            swap(tab[l], tab[r]);
            l++;
            r--;
        }

        if( left < r ) quick_sort_hoare(tab, left, r);
        if( right > l ) quick_sort_hoare(tab, l, right);
    }
}


int main(){

    int tab[] = {5, 7, 6, 4, 8, 1, 2, 9, 3};
    int size = sizeof(tab) / sizeof(int);

    out(tab, size);

    //quick_sort(tab, 0, size-1);
    quick_sort_lomuto(tab, 0, size-1);

    out(tab, size);

    return 0;
}
