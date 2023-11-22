#import "Heap.cpp"
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
		Heap<T, Container, Compare> heap;Compare compare;

	public:
		// Constructors
		PriorityQueue() = default;
		PriorityQueue(const Container& heap) {
			this->heap = Heap<T, Container, Compare>(heap);
		};

		// Member functions
		bool empty() {
			return heap.empty();
		}

		size_t size() {
			return heap.size();
		}

		T top() {
			return heap.top();
		}

		void push(const T& value) {
			heap.push(value);
		}

		void pop() {
			heap.pop();
		}
};
#endif
