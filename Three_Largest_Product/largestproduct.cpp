/*
Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class MinHeap {
 public:
  MinHeap(int capacity);
  void Heapify(int index);
  int ParentIndex(int index);
  int LeftIndex(int index);
  int RightIndex(int index);
  int SwapMin(int key);
  void Insert(int key);
  int Get(int index);
  int GetSize();

 private:
  int* heap;
  int capacity;
  int size;
};

MinHeap::MinHeap(int capacity) {
  size = 0;
  this->capacity = capacity;
  heap = new int[capacity];
}

void MinHeap::Heapify(int index) {
  int left = LeftIndex(index);
  int right = RightIndex(index);
  int smallest = index;

  if (left < size && heap[left] < heap[index]) {
    smallest = left;
  }

  if (right < size && heap[right] < heap[smallest]) {
    smallest = right;
  }

  if (smallest != index) {
    swap(heap[index], heap[smallest]);
    Heapify(smallest);
  }
}

int MinHeap::ParentIndex(int index) {
  return (index - 1) / 2;
}

int MinHeap::LeftIndex(int index) {
  return (2 * index) + 1;
}

int MinHeap::RightIndex(int index) {
  return (2 * index) + 2;
}

int MinHeap::SwapMin(int key) {
  heap[0] = key;
  Heapify(0);
}

void MinHeap::Insert(int key) {
  if (size == capacity) {
    if (key > heap[0]) {
      SwapMin(key);
    }

    return;
  }

  size++;
  int index = size - 1;
  heap[index] = key;

  while (index != 0 && heap[ParentIndex(index)] > heap[index]) {
    swap(heap[index], heap[ParentIndex(index)]);
    index = ParentIndex(index);
  }
}

int MinHeap::Get(int index) {
  return heap[index];
}

int MinHeap::GetSize() {
  return size;
}

void PreprocessArray(int* arr, int size) {
  int negs = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] < 0) {
      negs++;
    }
  }

  if (negs > 1 && negs != size) {
    for (int i = 0; i < size; i++) {
      if (arr[i] < 0) {
        arr[i] = -arr[i];
      }
    }
  }
}

int MaxProduct(int* arr, int size) {
  PreprocessArray(arr, size);
  MinHeap heap(3);

  for (int i = 0; i < size; i++) {
    heap.Insert(arr[i]);
  }

  int product = 1;

  for (int i = 0; i < heap.GetSize(); i++) {
    product *= heap.Get(i);
  }

  return product;
}

int main() {
  int arr_1[] = { -10, 10, 1, 2, 7 };
  cout << (MaxProduct(arr_1, 5) == 140 ? 1 : 0) << endl;

  int arr_2[] = { -1, -2, 3 };
  cout << (MaxProduct(arr_2, 3) == 6 ? 1 : 0) << endl;

  int arr_3[] = { -1, 2, 3 };
  cout << (MaxProduct(arr_3, 3) == -6 ? 1 : 0) << endl;

  int arr_4[] = { -4, -1, -3, -2 };
  cout << (MaxProduct(arr_4, 4) == -6 ? 1 : 0) << endl;

  int arr_5[] = { -10, -10, 5, 2 };
  cout << (MaxProduct(arr_5, 4) == 500 ? 1 : 0) << endl;

  return 0;
}