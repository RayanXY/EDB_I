#include <iostream>
#include <functional>

void print(int * first, int * last){
	
	std::cout << "A: ";
	while(first != last){
		std::cout << "|" << *first;
		first++;
	}
	std::cout << "|\n";

}

int * partition(int * first, int * last){

	auto pivot = *(last - 1); 	//!< Último elemento válido
	auto slow(first);
	auto fast(first);
	while(first != last){      //!< Percorre todo o arranjo
		if(fast <= *pivot){    //!< Condição que faz o slow avançar: elemento <= pivot
			std::swap(*fast, *slow);
			slow++;
		}
		first++;               //!< Sempre avança
	}
	return slow;

}

int main(void){
	
	 int A1[] = {7, 10, 1, 3, 6, 8, 2, 9, 4, 5};
	 int A2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	 int A3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	 std::cout << "Before Partition:\n";
	 print(std::begin(A1), std::end(A1));

	 auto past_the_pivot = partition(std::begin(A1), std::end(A1));
	 auto pivot = past_the_pivot - 1;

	 print(std::begin(A1), pivot); //!< Imprime a primeira
	 std::cout << " " << *pivot << " ";
	 print(past_the_pivot, std::end(A1));

}