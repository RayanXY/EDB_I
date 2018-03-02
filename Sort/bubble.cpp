#include <iostream>

int cmp(int a, int b){

	/// a > b return positvo, iguais return 0, b > a return negativo
	return a-b;

}

void bubble_sort(int A[], int len, int(*cmp)(int,int)){

	bool houve_troca = true;
	while(houve_troca){
		houve_troca = false;
		for(auto i(0); i < len-1; i++){
			if(cmp(A[i], A[i++]) > 0){
				std::swap(A[i], A[i+1]);
				houve_troca = true;
			}
		}
	} 

}

int main(){
	
	int i;
	int A[] = {2, 5, 1, 4, 5, 8, 7, 6, 9, 10};

	bubble_sort(A, 10, cpm)

	std::cout << "A: ";
	for(i = 0; i < 10; i++){
		std::cout << "|" << A[i];
	}
	std::cout << "|\n";

}
