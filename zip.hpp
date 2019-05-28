#include "iostream"


namespace itertools {



	template <typename T, typename U>

	class zip {



			private:

			T first;
			U second;



			public:

			zip(T start, U end) :  
			first(start), 
			second(end) {}


			auto begin() const{

					return iterator<decltype(first.begin()),decltype(second.begin())>(first.begin(), second.begin());

			}

			auto end() const{

					return iterator<decltype(first.end()),decltype(second.end())>(first.end(), second.end());

			}



			template <typename X, typename Y>
			class iterator {



				private:

				X x;            
				Y y;          



				public:

				iterator(X x1, Y y1) : 
					x(x1), 
					y(y1)  {}



				iterator<X,Y>& operator++() {

						++x;
						++y;

						return *this;

				}


				std::pair<decltype(*x),decltype(*y)> operator*() const {

						return std::pair<decltype(*x),decltype(*y)> (*x, *y);

				}



				bool operator!=(iterator<X,Y>  it){

						return (x != it.x) && (y != it.y);


				}

			};





	};

	template <typename X,typename Y>

	std::ostream &operator<<(std::ostream &out, const std::pair<X,Y> &p){

			out << p.first << ',' << p.second;

			return out;

	}

}