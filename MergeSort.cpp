#include "MergeSort.h"

void merge(vector<int>& data, int leftStart, int leftEnd, int rightEnd)
{
    const int LEFT_SIZE = leftEnd - leftStart+1;
    const int RIGHT_SIZE = rightEnd - leftEnd;

    int* leftArray = new int[LEFT_SIZE];
    for (int index = 0; index < LEFT_SIZE; index++)
        leftArray[index] = data[leftStart + index];

    int* rightArray = new int[RIGHT_SIZE];
    for (int index = 0; index < RIGHT_SIZE; index++)
        rightArray[index] = data[leftEnd+1 + index];

    int leftIter = 0, rightIter = 0;
    int mergeIter = leftStart;

    while (leftIter != LEFT_SIZE && rightIter != RIGHT_SIZE)
    {
        if (leftArray[leftIter] < rightArray[rightIter]) {
            data[mergeIter] = leftArray[leftIter];
            leftIter++;
        }
        else {
            data[mergeIter] = rightArray[rightIter];
            rightIter++;
        }
        mergeIter++;
    }

    while (leftIter != LEFT_SIZE) {
        data[mergeIter] = leftArray[leftIter];
        leftIter++;
        mergeIter++;
    }
    while (rightIter != RIGHT_SIZE) {
        data[mergeIter] = rightArray[rightIter];
        rightIter++;
        mergeIter++;
    }
    delete[] leftArray; delete[] rightArray;
}

void mergeSort(vector<int>& data, int startIndex, int endIndex)
{
    if (startIndex >= endIndex) return;
    
    int midIndex = startIndex + (endIndex - startIndex) / 2;
    mergeSort(data, startIndex, midIndex);
    mergeSort(data, midIndex + 1, endIndex);
    merge(data, startIndex, midIndex, endIndex);
}
