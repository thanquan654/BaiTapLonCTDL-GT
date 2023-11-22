#include <bits/stdc++.h>
#ifndef __Heap_cpp__
#define __Heap_cpp__

using namespace std;


template<
   class T,
   class Container = std::vector<T>,
   class Compare = std::less<typename Container::value_type>
>
class Heap {
private:
	Container heap;
	Compare compare;

	void heapify(int index) {
		int n = heap.size() - 1;
		int j = index, minChild;
		bool isHeap = false;

		while (j <= n/2 && isHeap == false) {
			if (2 * j == n) {
				minChild = 2 * j;
			} else {
				if (compare(heap[2 * j], heap[2 * j + 1])) {
					minChild = 2 * j;
				} else {
					minChild = 2 * j + 1;
				}
			}
			if (compare(heap[j], heap[minChild])) {
				swap(heap[j], heap[minChild]);
				j = minChild;
			} else {
				isHeap = true;
			}
		}
	}
	void buildHeap() {
		int n = heap.size() - 1;
		for (int i = n / 2; i > 0; --i) {
			heapify(i);
		}
	}

public:
	Heap() {
		T junk;
		heap.push_back(junk);
	};
	Heap(const Container& heap) {
		T junk;
		this->heap.push_back(junk);
		for (int i=0; i<heap.size(); i++) {
			this->heap.push_back(heap[i]);
		}
		buildHeap();
	}

	void pop() { // Xóa phần tử gốc -> Heapify
		if (!empty()) {
			swap(heap[1], heap.back());
			heap.pop_back();
			heapify(1);
		} else {
			std::cerr << "Error: The heap is empty." << std::endl;
		}
	}

	void push(const T& element) { // Thêm phần tử vào cây heap -> Heapify
  		heap.push_back(element);
		int index = heap.size() - 1;

		while (index > 1 && compare(heap[index], heap[index / 2])) {
        swap(heap[index], heap[index / 2]);
        index /= 2;
    }
	}

	T top() { // Lấy ra phần tử gốc của cây heap
		if (!empty()) {
			return heap[1];
		} else {
			cerr << "Error: The heap is empty." << std::endl;
			return T();
		}
	}

	size_t size() {
		return heap.size() - 1;
	}

	bool empty() {
		return heap.size() <= 1;
	}
};
#endif


