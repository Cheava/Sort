// Qsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <time.h>

void swap(int *arr, int begin, int end){
	int temp = arr[begin];
	arr[begin] = arr[end];
	arr[end] = temp;
}

int Partition3(int *arr, int begin, int end){
	int m = begin + (end - begin) / 2;
	if (arr[begin] > arr[end]) swap(arr, begin, end);
	if (arr[m] > arr[end]) swap(arr, m, end);
	if (arr[begin] > arr[m]) swap(arr, begin, m);

	int pivotkey = arr[begin];
	int pivotkey_stored = pivotkey;
	while (begin<end){
		while (begin<end&&arr[end] >= pivotkey)end--;
		arr[begin] = arr[end];
		while (begin<end&&arr[begin] <= pivotkey)begin++;
		arr[end] = arr[begin];
	}
	arr[begin] = pivotkey;
	return begin;
}

int Partition2(int *arr, int begin, int end){
	int pivotkey = arr[begin];
	int pivotkey_stored = pivotkey;
	while (begin<end){
		while (begin<end&&arr[end] >= pivotkey)end--;
		arr[begin] = arr[end];
		while (begin<end&&arr[begin] <= pivotkey)begin++;
		arr[end] = arr[begin];
	}
	arr[begin] = pivotkey;
	return begin;
}

int Partition1(int *arr, int begin, int end){
	int pivotkey = arr[begin];
	while (begin<end){
		while (begin<end&&arr[end] >= pivotkey)end--;
		swap(arr, begin, end);
		while (begin<end&&arr[begin] <= pivotkey)begin++;
		swap(arr, begin, end);
	}
	return begin;
}

void Qsort3(int *arr, int begin, int end){
	int pivot;
	while (begin<end){
		pivot = Partition2(arr, begin, end);
		Qsort3(arr, begin, pivot);
		begin = pivot + 1;
	}
}

void Qsort4(int *arr, int begin, int end){
	int pivot;
	while (begin<end){
		pivot = Partition3(arr, begin, end);
		Qsort3(arr, begin, pivot);
		begin = pivot + 1;
	}
}

void Qsort2(int *arr, int begin, int end){
	int pivot;
	while (begin<end){
		pivot = Partition1(arr, begin, end);
		Qsort2(arr, begin, pivot);
		begin = pivot + 1;
	}
}

void Qsort1(int *arr, int begin, int end){
	int pivot;
	if(begin<end){
		pivot = Partition1(arr, begin, end);
		Qsort1(arr, begin, pivot);
		Qsort1(arr, pivot+1, end);
	}
}



int _tmain(int argc, _TCHAR* argv[])
{


	int arr1[10] = { 2, 3, 3, 5, 7, 6, 1, 9, 3, 5 };
	int arr2[10] = { 2, 3, 3, 5, 7, 6, 1, 9, 3, 5 };
	int arr3[10] = { 2, 3, 3, 5, 7, 6, 1, 9, 3, 5 };
	int arr4[10] = { 2, 3, 3, 5, 7, 6, 1, 9, 3, 5 };
	int end = 10 - 1;

	Qsort1(arr1, 0, end);

	Qsort2(arr2, 0, end);

	Qsort3(arr3, 0, end);

	Qsort4(arr4, 0, end);

	return 0;
}

