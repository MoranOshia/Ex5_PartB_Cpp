#pragma once



namespace itertools{



		template <typename T> 

		class range{

			const T startNum;
			const T endNum;



			public: 
			
				range(T s ,T e): 
				startNum(s), 
				endNum(e){}



			auto begin() const { 
			return range<T>::iterator(startNum);
			}

			auto end() const { 
			return range<T>::iterator(endNum);
			}   


				class iterator {

				private:

					T it;



				public:



				   iterator(const T &iter): 
				   it(iter){}
				   
					auto& operator*() const {
					   return it;
					   }


				   auto& operator++() {
					   ++(it);return *this;
					   }

				   const iterator operator++(int) {

					 iterator tmp(*this); 

					 it++;

					 return tmp;}

				   bool operator==(const iterator &other) const {
					   return it == other.it;
					   }

				   bool operator!=(const iterator &other) const {
					   return it != other.it;
					   }

				  




				};

		  
		};

		}

