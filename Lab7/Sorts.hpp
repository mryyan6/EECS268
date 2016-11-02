#include "Sorts.h"
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{	
	int temp;
	for(int z = 0; z < size - 1; z++)
    	{
        	for(int i = 0; i < size-1; i++)
        	{
            		if(arr[i] > arr[i+1])
            		{
                		temp = arr[i];
                		arr[i] = arr[i + 1];
                		arr[i + 1] = temp;
            		}
        	}
    	}
        assert(Sorts<T>::isSorted(arr, size));
}
template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
	int j;
	int temp;
	for(int i = 0; i < size; i++)
	{
	        j = i;
	        while(j > 0 && arr[j] < arr[j-1])
	        {
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
	        }
	}  
        assert(Sorts<T>::isSorted(arr, size));
}
template <typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
	if(size<=1)
	{
		return;
	}
	int leftSize = (size/2);
	int rightSize = (size-leftSize);
	T* left = arr;
	T* right = (arr+leftSize);
	mergeSort(left, leftSize);
	mergeSort(right, rightSize);
	merge(left, right, leftSize, rightSize);
	assert(Sorts<T>::isSorted(arr, size));
//
}
template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
	quickSortRec(arr, 0, size-1, false);
}
template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
	quickSortRec(arr, 0, size-1, true);
}
template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
	int temp;
	for(int x = 0; x < size -1; x++)
	{
		for(int i = 0; i < size-1; i++)
	        {
			if(arr[i] > arr[i + 1])
			{	
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}        
		}
	}
	assert(Sorts<T>::isSorted(arr, size));
}
template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
	if(size==1)
	{
		return(true);
	}
	for(int x = 0; x<size-1; x++)
	{
		for(int i = 0; i<size-1; i++)
		{
			if(arr[x]>arr[x+1])
			{
				return(false);
			}
		}
	}
	return(true);	
}
template <typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
	double time;
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;
	start = std::chrono::system_clock::now();
	sort(arr, size);
	end = std::chrono::system_clock::now();
	elapsed = (end - start);
	time = elapsed.count();
	return(time);
}
template<typename T>
void Sorts<T>::swap(T arr[], int a, int b)
{
	T tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
}
template<typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
	std::default_random_engine generator(time(nullptr));
	while(isSorted(arr, size) == false)
	{
		shuffle(arr, size, generator);        
	}
	assert(Sorts<T>::isSorted(arr, size));
}
template<typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{
	int temp;
	int val;
	std::uniform_int_distribution<int> distribution(0, size - 1);
	for(int i = 0; i < size; i++)
	{
		temp = distribution(generator);
		val = arr[temp];
		arr[temp] = arr[i];
		arr[i] = val;         
	}	
}
template<typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{
	int* arr = new int[size];
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min, max);
	for(int i = 0; i < size; i++)
	{
		arr[i] = distribution(generator);      
	}
	return(arr);
}
template<typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{
	if(size1+size2 <= 1)
	{
		return;
	}
	T* tempArr = new T[size1+size2];
	int x=0;
	int y=0;
	int current = 0;
	while(x<size1 && y<size2)
	{
		if(*(a1+x)>*(a2+y))
		{
			tempArr[current] = *(a2+y);
			y++;
		}
		else
		{
			tempArr[current] = *(a1 +x);
			x++;
		}
		current++;
	}

	while(x<size1)
	{
		tempArr[current] = *(a1+x);
		x++;
		current++;
	}
	while(y<size2)
	{
		tempArr[current] = *(a2+y);
		y++;
		current++;
	}
	for(int i = 0; i<(size1+size2); i++)
	{
		a1[i] = tempArr[i];
	}
	delete [] tempArr;
}
template<typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
	if(median && ((last+1)<3))
	{
		selectionSort(arr, (last+1));
		return;
	}
	if(first<last)
	{
		int pivot = partition(arr, first, last, median);
		quickSortRec(arr, first, (pivot-1), median);
		quickSortRec(arr, (pivot+1), last, median);
		return;
	}
}
template<typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
	int mid = (last+1)/2;
	T temp [] = {arr[first], arr[mid], arr[last]};
	selectionSort(temp, 3);
	if(arr[first]==temp[1])
	{
		swap(arr, mid, last);
	}
	else if(arr[mid]==temp[1])
	{
		swap(arr, mid, last);
	}
}
template<typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
	int pivotIndex = last;
	int leftIndex=first;
	int rightIndex = (pivotIndex-1);
	if(median)
	{
		setMedianPivot(arr, first, last);
	}
	bool done = true;
	while(done)
	{
		while((arr[leftIndex]<arr[pivotIndex])&&(leftIndex<(last+1)))
		{
			leftIndex++;
		}
		while((arr[rightIndex]>= arr[pivotIndex])&&(rightIndex>0))
		{
			rightIndex--;
		}
		if(leftIndex<rightIndex)
		{
			swap(arr, leftIndex, rightIndex);
		}
		else
		{
			done = false;
			swap(arr, leftIndex, pivotIndex);
		}
	}
	return leftIndex;
}

