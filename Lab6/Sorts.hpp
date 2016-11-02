/*
* @file: Sorts.hpp
* @author: Zack Mryyan
* @date: 10/28/2015
* @brief: class that handles all the sorting methods
*/
#include "Sorts.h"
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>
#include <string> 	
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
template<typename T>
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
template<typename T>
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
