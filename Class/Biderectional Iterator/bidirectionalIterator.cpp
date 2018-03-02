#include <iostream>
#include <iterator>
#include <cassert>

template <typename T>
class MybidirectionalIterator{

	private:
		T *m_ptr;

	public:
		using self_type = MybidirectionalIterator;
		using value_type = T;
		using pointer = T *;
		using reference = T &;
		using difference_type = std::ptrdiff_t; //!< Difference type used to calculated distance
		using iterator_category = std::bidirectional_iterator_tag; //!< Iterator category	

	public:
		MybidirectionalIterator(T *ptr_ = nullptr)
			:m_ptr(ptr_)
		{/*empty*/}

		~MybidirectionalIterator() = default;
		MybidirectionalIterator(const self_type &) = default;
		self_type & operator=(const self_type &) = default;

			/// *it
			reference operator*(){
				assert(m_ptr != nullptr);
				return *m_ptr;
			}

			/// ++it
			self_type operator++(){
				m_ptr++;
				return *this;
			}

			/// it++
			self_type operator++(T){
				self_type temp = *this;
				m_ptr++;
				return temp;
			}

			/// --it
			self_type operator--(){
				m_ptr--;
				return *this;
			}

			/// it--
			self_type operator--(T){
				self_type temp = *this;
				m_ptr--;
				return temp;
			}

			/// it == it2
			bool operator==(const self_type & rhs_){
				return m_ptr == rhs_.m_ptr;
			}

			/// it != it2
			bool operator!=(const self_type & rhs_){
				return m_ptr != rhs_.m_ptr;
			}

		};

class VectorInt{

	public:
		using iterator = MybidirectionalIterator<int>;
		using const_iterator = MybidirectionalIterator<const int>;

	private:
		size_t m_len;
		size_t m_capacity;
		int *m_data;

	public:
		VectorInt(size_t sz_=0)
			: m_len(0)
			, m_capacity(sz_)
			, m_data(new int[sz_])
		{/* empty */}

		~VectorInt(void){
			delete [] m_data;
		}

		iterator begin(void) const{
			return iterator(&m_data[0]);
		}
		iterator end(void) const{
			return iterator(&m_data[m_len]);
		}
		const_iterator cbegin(void) const{
			return const_iterator(&m_data[0]);
		}
		const_iterator cend(void) const{
			return const_iterator(&m_data[m_len]);
		}

		bool full(void) const{
			return m_len == m_capacity;
		}

		void reserve(size_t new_cap_){
			
			if(new_cap_ <= m_capacity){
				return;
			}
			/// Cria nova memoria
			int * temp = new int[new_cap_];
			/// Backup
			for(auto i(0u); i < m_capacity; ++i){
				temp[i] = m_data[i];
			}
			/// Apaga área de armazenamento antigo
			delete[] m_data;
			/// Nova área de armazenamento
			m_data = temp;
			/// Atualiza a nova capacidade
			m_capacity = new_cap_;

		}

		void push_back(int e_){
			
			if(full()){
				reserve(2 * m_capacity);
			}
			m_data[m_len++] = e_;

		}
		
};

int main(){

	VectorInt v(10);
	VectorInt::iterator it = v.begin();
	VectorInt::const_iterator cit = v.cbegin();

	for(auto i(0); i < 10; i++){
		v.push_back(i+1);
	}

	for( ; cit != v.cend(); ++cit){
		std::cout << *cit << " ";
	}
	std::cout << std::endl;

	std::cout << ">>> begin() = " << *it << "\n";

	std::cout << ">>> Array: [";
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "]\n";

	/** 
		int *ptr = v.m_data;
		*ptr = 10;
		ptr++;
	*/

	return 0;

}