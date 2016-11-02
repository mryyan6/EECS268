/*
* @file: Sorts.h
* @author: Zack Mryyan
* @date: 10/28/2015
* @brief: header file for sort class
*/ 
#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>
template<typename T>
class Sorts
{
	public:
		/**
		*@pre array full of numbers
		*@post organizes array in ascending orders
		*@return an organized array
		*/
		static void bubbleSort(T arr[], int size);
		/**
		*@pre array full of numbers
		*@post organizes array in ascending orders
		*@return an organized array
		*/
		static void bogoSort(T arr[], int size);
		/**
		*@pre array full of numbers
		*@post organizes array in ascending orders
		*@return an organized array
		*/
		static void insertionSort(T arr[], int size);
		/**
		*@pre array full of numbers
		*@post organizes array in ascending orders
		*@return an organized array
		*/
		static void selectionSort(T arr[], int size);
		/**
		*@pre array full of numbers
		*@post None
		*@return true if array is sorted
		*/
		static bool isSorted(T arr[], int size);
		/**
		*@pre array full of numbers
		*@post None
		*@return an shuffled array
		*/
		static void shuffle(T arr[], int size, std::default_random_engine& generator);
		/**
		*@pre none
		*@post an array that is the size specified
		*@return an unorganized array
		*/
		static int* createTestArray(int size, int min, int max);
		/**
		*@pre none
		*@post none
		*@return a time of how long it takes to sort an array
		*/
		static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);
		
};
#include "Sorts.hpp"
#endif
