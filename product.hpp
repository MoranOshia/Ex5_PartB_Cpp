/**
 * this Header file Represents a Cartesian product of a container. 
 * @author Israel Buskila and Moran Oshia
 * @since 05-2019
 */
#include "iostream"


namespace itertools {

	bool b=false;
    template <typename T, typename U>
    class product {
	
    private:
        T x;
        U y;

    public:
	
        product(T begin, U end) :  x(begin), y(end) {
          b=false;
          if(!(end.begin()!=end.end())){
            b=true;
          }
        }

    auto begin() const{
        return  iterator<decltype(x.begin()),decltype(y.begin())>(x.begin(), y.begin()); 
	} 

    auto end() const{
        return iterator<decltype(x.end()),decltype(y.end())>(x.end(), y.end()); 
	}  

    template <typename X, typename Y>
    class iterator {

        private:
            X x;
            Y y;
            Y index;
            bool next;

        public:
            iterator(X itA , Y itB): 
			x(itA) , 
			y(itB) , 
			index(y),
			next(false) {}



            auto operator*() const {
			   return  std::pair<decltype(*x),decltype(*y)> (*x , *y);
            }

			bool operator!=(iterator const  it) {
				
                if((x != it.x) && !(y != it.y)){
                  next=true;
                }
                if(next){

                next=false;
                    y = index;
                    ++x;
                }
                return (x != it.x&& !b);

            }

			iterator<X,Y>& operator++() {
            if(!next)
               ++y;
               return *this;

            }

        };


    };

}