	#pragma once

	#include <iostream>

	#include "range.hpp"

	
	namespace itertools{



	template <typename T, typename U> 

				class chain{



				private:

				const T first;
				const U second;

				
				public:

				chain(T f, U s ): 
				first(f), 
				second (s){}

				auto begin() const {  
				return iterator<decltype(first.begin()),decltype(second.begin())> (first.begin(), second.begin()); 
				}

				auto end() const { 
				return iterator<decltype(first.end()),decltype(second.end())> (first.end(), second.end()); }


				template <typename X, typename Y> 
				class iterator {



						private:

						X x;

						Y y;

						bool isX;



						public:

								

						iterator(X x1,Y y1):
							x(x1), 
							y(y1), 
							isX(true)  {}



						iterator<X,Y> &operator++() {

							if (isX){
								++(x);
							}

							else{
								++(y);
							}

							return *this;

						}



						iterator<X,Y> &operator++(int n) {

							iterator it(*this); 
							
							operator++(); 

							return it;

						}



						bool operator!=( iterator<X,Y> r)  {

							if ((isX == true) && !(x != r.x)){

							isX = false;                                                                                                  

							}

							if (isX==true){

							return (x != r.x);

							}

							else{

							return (y != r.y);

							}

						}



						auto &operator*() const {

							if (isX){

							return *x;
							}

							else {

							return *y;
							}

						}



				};


	};

	}