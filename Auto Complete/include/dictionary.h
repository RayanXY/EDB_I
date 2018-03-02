/**
 * @file dictionary.h
 * @author Anderson Caio & Rayan Avelino
 * @date 24/05/2017
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/**
 * @class Dictionary
 *
 * This class contains a set of function for controlling
 * the weight and words passed in the wikidictionary file by the 
 * user.
 */
class Dictionary{

	private:
		long int weight;
		std::string word;
		std::string::iterator it_curr_char;

	public:
		/// Contructor
		Dictionary(){/* Empty */};

		/**
		 * Gets the current word.
		 * @return word The current word is returned.
		 */
		std::string get_word(void){
			return word;
		}

		/**
		 * Verify if the string is a number.
		 * @return T if the condition is satisfied; F otherwise.
		 */
		bool is_num(void){
			return (*it_curr_char >= '0' and *it_curr_char <= '9');
		}

		/**
		 * Verify if there is a white space or a tab on the string.
		 * @return T if the condition is satisfied; F otherwise.
		 */
		bool is_ws(void){
			return (*it_curr_char == ' ' or *it_curr_char == '\t');
		}

		/**
		 * Searchs in the Dictionary vector words that initiate with the input and print them.
		 * @param str_ The input that was given by the user.
		 */
		bool search_sugestions(std::string str_){

			bool equal = true;
			auto w_ = get_word();
			if(w_.size() < str_.size())
				{return false;}
			else{
				for(auto i(0); i!=str_.size(); i++){
					if(w_[i] != str_[i])
						equal = false;
				}
				if(equal==true){
					std::cout << w_ << "\n";
					return true;
				}
				else return false;
			}

		}

		/**
		 * Converts a string into an integer.
		 * @param a_ The string to be converted.
		 * @return v_ The interger.
		 */
		long int str_to_int(std::string a_){

			std::istringstream iss(a_);
			long int v_;
			iss >> v_;

			return v_;
		}

		/**
		 * Recives the line, reads and deal with the spaces, then verify which part is the weight and save the rest as a 'word'.
		 * @param line_ The line to be read.
		 */
		void set_dict(std::string line_){

			it_curr_char = line_.begin();
			std::string w_;
			std::string wo_;

			while(it_curr_char != line_.end()){

				if(is_ws()){
					it_curr_char++;
				}
				else if(is_num()){
					w_.push_back(*it_curr_char);
					it_curr_char++;
				}else{
					wo_.push_back(*it_curr_char);
					it_curr_char++;
				}
			}

			weight = str_to_int(w_);
			word = wo_;
		}

};