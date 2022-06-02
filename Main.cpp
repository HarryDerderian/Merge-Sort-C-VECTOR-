#include "MergeSort.h"  
#include <iostream>
#include <vector>  
#include <chrono>        
#include <algorithm>
using namespace std;
using namespace chrono;


void randomizeVec(vector<int>& vec)
{
	auto iter = vec.begin();
	auto end = vec.end();
	while (iter != end) {
		*iter = rand();
		iter++;
	}
}

int main()
{
	const int DATA_AMOUNT = 10000000;
	vector<int> data(DATA_AMOUNT);
	cout << "SAMPLE SIZE: " << DATA_AMOUNT << endl;
	
	
	// MERGE SORT 
	randomizeVec(data);
	auto startTime = high_resolution_clock::now();
	mergeSort(data,0, DATA_AMOUNT -1);
	auto stopTime = high_resolution_clock::now();
	auto timeTaken = duration_cast<seconds>(stopTime - startTime);
	
	cout << "merge sort: " << timeTaken.count()  << " seconds." << endl;

	// STL SORT
	randomizeVec(data);
	startTime = high_resolution_clock::now();
	sort(data.begin(), data.end());
	stopTime = high_resolution_clock::now();
	timeTaken = duration_cast<seconds>(stopTime - startTime);
	
	cout << "std::sort:  " << timeTaken.count() <<" seconds." << endl;
}