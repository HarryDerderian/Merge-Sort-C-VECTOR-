#ifndef MERGESORT_H
#define MERGESORT_H
#include<vector>
using namespace std;

void  mergeSort(vector<int>& data, int startIndex, int endIndex);
void merge(vector<int>& data, int leftStart, int leftEnd, int rightEnd);

#endif
