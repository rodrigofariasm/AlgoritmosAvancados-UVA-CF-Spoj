// Rodrigo Farias de Mac�do

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 
#include <math.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	double aux, max = 0.0, sum = 0.0;
	for(int i = 0; i < n; i++){
		cin >> aux;
		sum += aux;
		if(aux > max){
			max = aux;
		}
	}

	long long x = ceil(sum/(n-1));

	while (x*(n - 1) < sum){
		x++;
	}
	
	if (x < max){
		x = max;
	}
	
	cout << x << endl;
	
}
