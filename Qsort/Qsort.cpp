// Qsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <time.h>

void swap(int *arr, int begin, int end){
	int temp = arr[begin];
	arr[begin] = arr[end];
	arr[end] = temp;
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
	int i;
	int arr[10] = { 2, 3, 3, 5, 7, 6, 1, 9, 3, 5 };
	Qsort1(arr, 0, 9);
	Qsort2(arr, 0, 9);
	return 0;
}

