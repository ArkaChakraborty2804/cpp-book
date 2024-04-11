#include <bits/stdc++.h>

template <class T>
class fenwicktree{
	private:
		ll size;
		vector <T> fenwick;
		vector <T> arr;

	public:
		fenwicktree(ll size): size(size), fenwick(size+1), arr(size){}

		//set the value at index ind to val
		void set(ll ind, ll val){
			add(ind, val-arr[ind]);
		}

		// add val to index and fenwick tree
		void add(ll ind, ll val){
			arr[ind]+=val;
			ind++;
			for(; ind <= size; ind += ind & -ind){
				fenwick[ind] += val;
			}
		}

		// prefix sum in O(logn)
		T pref_sum(ll ind){
			ind++;
			T total = 0;
			for(; ind>0; ind -= ind & -ind){
				total += fenwick[ind];	
			}
			return total;
		}
};



