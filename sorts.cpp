template<typename T, int size>
void buuble_sort(T (&arr)[size]){
	bool wasCLange = true;

	int L = 0;
	int R = size-1;

	for(;wasCLange;){
		wasCLange = false;
		int a = L;
		for(; a<R; a++)
			if(arr[a] < arr[a+1]){
				std::swap( arr[a], arr[a+1] );
				wasCLange = true;
			}
		R = a;
		for(; a>L; a--)
			if(arr[a] > arr[a-1]){
				std::swap( arr[a], arr[a-1] );
				wasCLange = true;
			}
		L = a;
	}
};


template<typename T, const int size>
void merge_sort(T (&arr)[size], const int L=0, const int R=(size-1) ){
	if(R < L) return;
	if(R > size) return;

	int pivot = (L+R)/2;

	if(pivot > L){
		merge_sort( arr, L, pivot);
		merge_sort( arr, pivot+1, R);
	}

	const int SIZE = R-L+1;
	const int sizeL = pivot - L + 1;
	const int sizeR = R - pivot;

	// jeœli ostatni element lewej arrlicy(który w niej póŸniej siê znajdzie)
	// jest mniejszy b¹dŸ równy od pierwszego elementu prawej arrlicy(który siê w niej póŸniej znajdzie)
	// to oznacza, ¿e arrlica jest posortowana :D
	if(arr[sizeL+L-1] <= arr[sizeL+L])
		return;

	T arrL[sizeL];
	T arrR[sizeR];

	for(int i=0; i<sizeL; arrL[i] = arr[i+L], i++);
	for(int i=0; i<sizeR; arrR[i] = arr[i+L + sizeL], i++);

	int l = 0;
	int r = 0;
	for(int i=0; i<SIZE; i++){
		if( l < sizeL && r < sizeR){
			if(arrL[l] < arrR[r]){
				arr[i+L] = arrL[l];
				l++;
			}else{
				arr[i+L] = arrR[r];
				r++;
			}

			continue;
		}
		if(l < sizeL){
			arr[i+L] = arrL[l];
			l++;
			break;
		}
		arr[i+L] = arrR[r];
		r++;
		break;
	}
}

template<typename T, const int size>
void insert_sort(T (&arr)[size] ){
	int j = 0;
	T tmp;
    for(int i=1; i<size; i++){
        tmp = arr[i];
        for(j=i-1; j>=0 && arr[j]<tmp; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
    }
}

template<typename T, const int size>
void quick_sort_Loare(T (&arr)[size], const int L=0, const int R=(size-1)){
	if(R<=L) return;
	const int pivot = (R+L)/2;

	int l = L;
	int r = R;

	for(;l<r;){
		/**
		 * Zmiana kolejnosci
		 * zamieniæ oba warunki na przeciwne
		 */
		for(;arr[l] > arr[pivot]; l++);
		for(;arr[r] < arr[pivot]; r--);

		if(l < r){
			std::swap( arr[l], arr[r]);
			l++;
			r--;
		}
	}

	if(l < R) quick_sort_Loare( arr, L, r);
	if(r > L) quick_sort_Loare( arr, l, R);
}

template<typename T, const int size>
void quick_sort_lomuto(T (&arr)[size], const int L=0, const int R=(size-1)){

	if(L>=R) return;
	int i=L;
	int j=L;
	int pivot=arr[R];

	for(;j<R;j++){
		if(arr[j] <= pivot){
			std::swap(arr[i], arr[j]);
			i++;
		};
	};

	std::swap( arr[i], arr[j] );

	quick_sort_lomuto(arr, L, i-1);
	quick_sort_lomuto(arr, i+1, R);
};

template<typename T, const int size>
void heap_sort(T (&arr)[size], const int L=0, const int R=(size-1)){

	for(int i=2; i<=R+1; i++){
		if(arr[i/2 -1]<arr[i -1]){
			std::swap( arr[i/2-1], arr[i-1]);
			if(i>2) i=i/2 -1;
		};
	};

	std::swap( arr[L], arr[R]);

	if(0 == R)
		return;

	heap_sort(arr, L, R-1);
}

