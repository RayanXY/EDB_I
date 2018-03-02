template <typename T>

	class Stack{

		private:
			static const size_t SIZE = 10; 	//!< Tamanho padrão da pilha
			size_t m_top;   	 		   	//!< Topo da pilha
			size_t m_capacity;   			//!< Tamanho físico da área de armazenamento
			T * m_data; 					//!< Área de armazenamento

		private:
			/// Amplia a área de armazenamento para capacitade solicitada
			void reserve(size_t new_cap);	

		public:
			Stack();
			~Stack();
			Stack(const Stack &) = delete;
			Stack & operator = (const Stack &) = delete;

			void push(const T & value); 			
			T top(void) const;
			void pop(void);					//!< Pode lançar std::lenght_error]
			bool empty(void) const;

	};

	template <typename T>
	Stack<T>::Stack(size_t cap_) 
		: m_top(0)
		, m_capacity(cap_)
		, m_data(new T[m_capacity])
	{
		/// Empty 
	}

	template <typename T>
	Stack<T>::~Stack(void){
		delete [] m_data;
	}

int main(){

	Stack<int> P;

	for(auto i(0); i < 10; i++){
		P.push(i+1);
	}

	while(not P.empty()){
		std::cout << P.top() << " ";
		P.pop();
	}
	std::cout << std::endl;

	return 0;
	
}