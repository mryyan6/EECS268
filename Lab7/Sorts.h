#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include <random>
#include <cstdlib>

template <typename T>
class Sorts
{
	public:
		static void bogoSort(T arr[], int size);
		static void bubbleSort(T arr[], int size);
		static void insertionSort(T arr[], int size);
		static void mergeSort(T arr[], int size);
		static void quickSort(T arr[], int size);
		static void quickSortWithMedian(T arr[], int size);
		static void selectionSort(T arr[], int size);
		static bool isSorted(T arr[], int size);
		static void shuffle(T arr[], int size, std::default_random_engine& generator);
		static int* createTestArray(int size, int min, int max);
		static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);
		static void shuffle(T arr[], int size);
		static void swap(T arr[], int a, int b);
	private:
		static void merge(T* a1, T* a2, int size1, int size2);
		static void quickSortRec(T arr[], int first, int last, bool median);
		static void setMedianPivot(T arr[], int first, int last);
		static int partition(T arr[], int first, int last, bool median);
		char print;
};
#include "Sorts.hpp"
#endif

