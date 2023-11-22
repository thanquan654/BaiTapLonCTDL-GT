#import <bits/stdc++.h>
#ifndef __PriorityQueue_cpp__
#define __PriorityQueue_cpp__
using namespace std;

template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
    >
class PriorityQueue {
	private:
		Container heap;
		Compare compare;

	public:
		// Constructors
		PriorityQueue() = default;
		PriorityQueue(const Container& compare) {
			this->heap = heap;
		};

		// Member functions
		bool empty() {
			return heap.empty();
		}

		size_t size() const {
			return heap.size();
		}

		T top() {
			return heap.front();
		}

		void push(const T& value) {
			heap.push_back(value);
			std::push_heap(heap.begin(), heap.end(), compare);
		}

		void pop() {
			std::pop_heap(heap.begin(), heap.end(), compare);
			heap.pop_back();
		}
};
#endif
