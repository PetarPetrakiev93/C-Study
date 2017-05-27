#include "PopulationArray.h"
#include<iostream>
#include<vector>
#include <algorithm> 

int main() {
	int L, H, M;
	std::cin >> L >> H >> M;
	std::vector<long long> pop(array, array+6342);
	
	int counter = 0;
	for(auto p = pop.begin(); p != pop.end(); p++){
		long long lowBound = ((*p) * L);
		long long highBound = ((*p) * H);
	std::vector<long long>::iterator low,up;
	low=std::lower_bound (pop.begin(), pop.end(), lowBound);
  	up= std::upper_bound (pop.begin(), pop.end(), highBound);
		if((up - low) >= M){
		counter++;
		}		
	}
	std::cout << counter << std::endl;
}