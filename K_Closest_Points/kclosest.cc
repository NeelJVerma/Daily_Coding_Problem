/*
Given a list of points, a central point, and an integer k, find the nearest k points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)], the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].
*/

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

double Distance(pair<int, int> p_1, pair<int, int> p_2) {
  int x_1 = p_1.first;
  int x_2 = p_2.first;
  int y_1 = p_1.second;
  int y_2 = p_2.second;

  return abs(sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2)));
}

class MaxHeap {
 public:
  MaxHeap(int capacity);
  void Heapify(int index);
  int ParentIndex(int index);
  int LeftIndex(int index);
  int RightIndex(int index);
  double SwapMax(pair<double, int> key);
  void Insert(pair<double, int> key);
  pair<double, int> Get(int index);
  int GetSize();

 private:
  pair<double, int>* heap;
  int capacity;
  int size;
};

MaxHeap::MaxHeap(int capacity) {
  size = 0;
  this->capacity = capacity;
  heap = new pair<double, int>[capacity];
}

void MaxHeap::Heapify(int index) {
  int left = LeftIndex(index);
  int right = RightIndex(index);
  int largest = index;

  if (left < size && heap[left].first > heap[index].first) {
    largest = left;
  }

  if (right < size && heap[right].first > heap[largest].first) {
    largest = right;
  }

  if (largest != index) {
    swap(heap[index], heap[largest]);
    Heapify(largest);
  }
}

int MaxHeap::ParentIndex(int index) {
  return (index - 1) / 2;
}

int MaxHeap::LeftIndex(int index) {
  return (2 * index) + 1;
}

int MaxHeap::RightIndex(int index) {
  return (2 * index) + 2;
}

double MaxHeap::SwapMax(pair<double, int> key) {
  heap[0] = key;
  Heapify(0);
}

void MaxHeap::Insert(pair<double, int> key) {
  if (size == capacity) {
    if (key.first < heap[0].first) {
      SwapMax(key);
    }

    return;
  }

  size++;
  int index = size - 1;
  heap[index] = key;

  while (index != 0 && heap[ParentIndex(index)].first < heap[index].first) {
    swap(heap[index], heap[ParentIndex(index)]);
    index = ParentIndex(index);
  }
}

pair<double, int> MaxHeap::Get(int index) {
  return heap[index];
}

int MaxHeap::GetSize() {
  return size;
}

vector<pair<int, int>> KClosest(pair<int, int>* arr, int size, pair<int, int> center, int k) {
  MaxHeap mh(k);

  for (int i = 0; i < size; i++) {
    pair<double, int> p = make_pair<double, int>(Distance(arr[i], center), int(i));
    mh.Insert(p);
  }

  vector<pair<int, int>> k_closest;

  for (int i = 0; i < k; i++) {
    k_closest.push_back(arr[mh.Get(i).second]);
  }

  return k_closest;
}

int main() {
  pair<int, int> center = make_pair<int, int>(1, 2);
  pair<int, int> point_1 = make_pair<int, int>(0, 0);
  pair<int, int> point_2 = make_pair<int, int>(5, 4);
  pair<int, int> point_3 = make_pair<int, int>(3, 1);
  pair<int, int> arr[] = {point_1, point_2, point_3};
  vector<pair<int, int>> k_closest = KClosest(arr, 3, center, 2);

  for (auto p : k_closest) {
    cout << p.first << 'x' << p.second << endl;
  }

  return 0;
}