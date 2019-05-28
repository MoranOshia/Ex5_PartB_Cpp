/**
 * Header file Represents all of the subgroups of the container. 
 * @author Israel Buskila and Moran Oshia
 * @since 05-2019
 */
#include "iostream"
#include <iostream>
#include <cmath>
#include <vector>

namespace itertools {




	template <typename U>
	class powerset {

		private:
		U x;

		public:
		powerset(U begin) : 
		x(begin) {}

		auto begin() const {
				return iterator<decltype(x.begin())> (x.begin(), x.end());
		}
		auto end() const {
				return iterator<decltype(x.begin())>(x.end(), x.end());
		}

		template <typename T>
		class iterator {
				private:

				size_t size(const T begin,const T end){
						T runner = begin;
						size_t a = 0;
						while(runner != end) {
								a++;
								++runner;
						}
						return pow(2,a);
				}

				vector<vector<T>>  combination(const vector<T> & k){
						vector<vector<T> > v;
						vector<T> temp;
						v.push_back(temp);
						for (int i = 0; i < k.size(); i++) {
								vector<vector<T> > vTemp = v;
								for (int j = 0; j < vTemp.size(); j++) {
										vTemp[j].push_back(k[i]);
								}
								for (int j = 0; j < vTemp.size(); j++) {
										v.push_back( vTemp[j] );
								}
						}
						return v;
				}

				vector<T> change(const T i,const T j){
						vector<T> a;
						T runner = i;
						while(runner != j) {
								a.push_back(runner);
								++runner;
						}
						return a;
				}


				public:

				T xBegin;
				T yBegin;
				uint index;
				size_t count;
				vector<vector<T> > v;

				iterator(T itA, T itB) : 
				xBegin(itA), 
				yBegin(itB), 
				count(size(itA,itB)),
				index(0){}

				auto operator*(){
						vector<T> S = change(xBegin,yBegin);
						v = combination(S);
						vector<typename remove_const<typename remove_reference<decltype(*xBegin)>::type>::type> vec; 
						for(auto i : v[index]) {
								vec.push_back(*i);
						}
						return vec;
				}

				auto operator++() {      
						++index;
						return *this;
				}

				bool operator!= (const iterator & temp){
						return (index != count);
				}
		};


	};
		
		template <typename T>
		std::ostream &operator<<(std::ostream &ost, const std::vector<T> &v)
		{
				ost << "{";
				auto iter = v.begin();
				if(iter != v.end())
				{
						ost << *iter;
						++iter;
				}
				while (iter != v.end())
				{
						ost << ',' << *iter;
						++iter;
				}
				ost << "}";
				return ost;
		}
};