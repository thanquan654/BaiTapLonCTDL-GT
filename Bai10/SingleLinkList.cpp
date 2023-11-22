#include <bits/stdc++.h>
#include "sNode.cpp"
#include "SListIterator.cpp"

#ifndef __SingleLinkList_cpp__
#define __SingleLinkList_cpp__

using namespace std;

template <class T>
class SingleLinkList {
	private:
		Node<T> *head,*tail;
		unsigned int n;//so phan tu hien tai trong list -> n
	public:
		typedef SListIterator<T> iterator;
		SingleLinkList() { // Khoi tao list ko co doi so
			head = tail = nullptr;
			n = 0;
		}
		SingleLinkList(int n, T element) { // Khoi tao list co <n> phan tu co gia tri <element>
			head = tail = nullptr;
			this->n = 0;
			for(int i=1; i<=n; i++)
				push_back(element);
		}
		iterator begin() {
			return head;
		}
		iterator end() {
			return nullptr;
		}
		unsigned int size() {
			return n;
		}
		bool empty() {
			return n==0;
		}
		T &front() {
			return head->getElement();
		}
		T &back() {
			return tail->getElement();
		}
		void push_front(T element) {
			head = new Node<T>(element,head);
			if(n==0) tail = head;
			n++;
		}
		void push_back(T element) {
			if (n == 0) {
				push_front(element);
			} else {
				Node<T> *newNode = new Node<T>(element);
				tail->setNext(newNode);
				tail = newNode;
				n++;
			}
		}
		void pop_front() {
			if(n==0) return;
			if(n==1) {
				head = tail = nullptr;
			} else {
				head = head->getNext();
			}
			n--;
		}
		void pop_back() {
			if (n == 0) return;
			if (n == 1) {
				delete head;
				head = tail = nullptr;
			} else {
				Node<T> *temp = tail;
				tail = tail->getPrev();
				tail->setNext(nullptr);
				delete temp;
			}
			n--;
		}
		void insert(int position, T element) {
			if (position < 0) { // Vi tri khong hop le
				push_front(element);
			} else if (position >= n) { // Vi tri ko hop le -> chen vao cuoi list
				push_back(element);
			} else { // Vi tri hop le
				Node<T> *newNode = new Node<T>(element);
				Node<T> *curr = head;

				for (int i = 0; i < position-1; ++i) {
					curr = curr->getNext();
				}

				// prevNode -> newNode -> currNode
				newNode->setNext(curr->getNext());
				curr->setNext(newNode);

				n++;
			}
		}
		void assign(const SingleLinkList& other) {
			Node<T>* temp = other.head;
			while (temp != nullptr) {
				push_back(temp->getElement());
				temp = temp->getNext();
			}
		}
};
#endif