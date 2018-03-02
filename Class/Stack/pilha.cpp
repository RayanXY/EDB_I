#include <iostream>
#include <cassert>

/// Represent a List's Node
struct Node{
	
	int data; //!< Data storage on the node
	Node * next; //!< Next element's address

	Node(int v_ = 0, Node *n_ = nullptr)
		: data(v_)
		, next(n_)
	{/* Empty */}

};

/// Builds a list with 3 nodes
Node * build123(){

	Node *first, *second, *third;

	/// Creates the first node
	first = new Node;
	first->data = 1; //!< or (*first).data = 1;
	first->next = nullptr;
	/// Creates the second node
	second = new Node;
	second->data = 2; //!< or (*second).data = 2;
	second->next = nullptr;
	/// Creates the third node
	third = new Node;
	third->data = 3; //!< or (*third).data = 3;
	third->next = nullptr;

	/// Connects the first node and the second one
	first->next = second;
	second->next = third;

	/// Returns the beginning of the list
	return first;

}

void print(const Node * h_){

	const Node *work(h_);

	std::cout << "[ ";
	while(work->next != nullptr){

		/// Shows the Node's data
		std::cout << work->data << " ";
		/// Advances to the next node
		work = work->next;

	}
	std::cout << "]\n";

}

size_t length(const Node * h_){

	const Node *work(h_);
	size_t c_(0);

	while (work != nullptr){

		c_++;
		work = work->next;

	}

	return c_;

}

bool empty(Node * head){

	return head == nullptr;

}

bool push_front(Node * & h_, int value){

	/// Step 1: Alocate a new node with value
	Node * temp = new Node(value, nullptr);

	/// Step 2: The new node points to the next
	temp->next = h_;

	/// Step 3: Head points to the new node
	h_ = temp;

	return true;

}

int * get_data(const Node * h_, size_t & l_){

	/// List's size
	l_ = length(h_);

	/// Allocate a vector to storage the data
	int *data = new int[l_];

}

const Node * find(const Node * h_, int value_){

	const Node * result(nullptr);

	result = h_;
	while(result->next != nullptr && result->data !=value_){
		if(h_->data == value_){
			return result;
		}
		result = h_;
		h_ = h_->next;
	}

	return h_;

}

bool remove(Node * & h_, Node *prev_, int &deleted_val_){

	auto target(h_); //!< Points to the node to be removed

	/// If the list is empty
	if(h_ == nullptr){
		return false;
	}

	/// Step 1 - Points the target to the node to be removed
	target = (prev_ == nullptr) ? h_ : prev_->next;

	/// Step 2 - Make the "by-pass" to eliminate the node to be removed
	if(prev_ != nullptr){
		prev_->next = target->next; //!< "By-Pass"
	}else{
		h_ = target->next;
	}

	/// Step 3 - Remove
	deleted_val_ = target->data;
	delete target;

	return true;


}

int main(){

	{ //!< Testing print()
		/// List with { 1, 2, 3 }
		Node * head (nullptr); //!< Creates an empty list
		head = build123();

		std::cout << "Head: ";
		print(head);
	}

	{ //!< Testing find()
		Node * head (nullptr);
		Node * head_2 = build123();

		/// Find 1 in Head
		assert(find(head, 2) == nullptr);

		/// Find 1 in Head 2
		assert(find(head_2, 1) == nullptr);

		/// Find 2 in Head 2
		auto result = find(head_2, 2);
		assert(result->data == 1);

		/// Find 3 in Head 2
		result = find(head_2, 3);
		assert(result->data == 2);

		/// Find non-existing element
		assert(find(head_2, 4) == nullptr);

	}

	{ //!< Testing remove()
		int value = 0;
		Node * head(nullptr);
		Node * ante(nullptr);

		/// Empty list
		remove(head, head, value);
		assert (head == nullptr);

		/// List with one element to be removed
		push_front(head, 1);
		remove(head, ante, value);
		assert(value == 1);
		assert(empty(head) == true);

	}

	{ //!< Testing length()
		Node * head (nullptr);
		head = build123();

		size_t len = length(head);
		assert(len == 3);
		std::cout << "Length: " << len << "\n";
	}

	return 0;

}