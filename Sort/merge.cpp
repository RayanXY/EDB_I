#include <iostream>     // cout, endl
#include <algorithm>

/// Displays on the screen (std::cout) the content of a range of integers.
void print( int * first_, int * last_ ){

    std::cout << "[ ";
    while( first_ < last_ )
    {
        std::cout << *first_ << " ";
        first_++;
    }
    std::cout << "]";

}

/*!
 * Combina os elementos de um _range_ `a` com os elemento de um _range_ `b`
 * em um _range_ de saída `c`.
 *
 * \note
 * Os _ranges_ de entrada, `a` e `b`, devem estar em ordem **não decrescente**.
 *
 * \note
 * Assume que: sizeof(c) >= sizeof(a) + sizeof(b).
 */
void merge( int *first_a, int *last_a, int *first_b, int *last_b, int *first_c ){

    /// Enquanto houver elementos em A faça:
    while(first_a != last_a){
        /// Se o B acabar primeiro:
        if(first_b == last_b){
            /// Copiar todos os elementos remanescentes de A para C
            std::copy(first_a, last_a, first_c);
            return;
        }
        /// Se primeiro de A < primeiro de B:
        if(*first_a <= *first_b){
            /// Copie primeiro de A para C
            *first_c = *first_a;
            /// Incremente A
            *first_a++;
        /// Senão:
        }else{
            /// Copie primeiro de B para C]
            *first_c = *first_b;
            /// Incremente B
            *first_b++;
        /// Fim-Se
        }
        /// Incremento de C
        first_c++;
    /// Fim-Enquanto
    }
    /// Copie elementos restantes de B para C
    std::copy(first_b, last_b, first_c);

}

void merge_sort(int *first, int *last){

    /// Calcular o tamanoho do vetor
    auto n = std::distance(first, last);

    /// Caso base da recursão
    if(n < 2){                                      //!< Vetor já ordenado
        return;
    }

    auto len_left = n/2;                            //!< Tamanho do vetor da esquerda
    auto len_right = n - n/2;                       //!< Tamanho do vetor da direita
    int * L = new int[len_left];
    int * R = new int[len_right];

    std::copy(first, first+len_left, L);
    std::copy(first+len_left, last, R);

    /// Leap of Faith
    merge_sort(L, L+len_left);
    merge_sort(R, R+len_right);

    merge(L, L+len_left, R, R+len_right, first);    //!< Mesclar L com R no vetor original 'first'

    delete [] L;
    delete [] R;

}

int main( void ){

    int A[] = { 1, 1, 3, 5, 5, 7,  9, 11, 11, 13 };                         //!< Size = 10.
    int B[] = { 2, 2, 4, 6, 8, 8, 10, 10, 12, 12, 14, 16, 16, 18, 20 };     //!< Size = 15.
    int C[25];                                                              // Size of A + Size of B.

    std::cout << ">>> Array A:\n";
    print( std::begin(A), std::end(A) );
    std::cout << std::endl;

    std::cout << ">>> Array B:\n";
    print( std::begin(B), std::end(B) );
    std::cout << std::endl;

    merge_sort(std::begin(A), std::end(C));

    std::cout << ">>> Array C:\n";
    print( std::begin(C), std::end(C) );
    std::cout << std::endl;

    return 0;

}
