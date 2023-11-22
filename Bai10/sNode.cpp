#include <bits/stdc++.h>
#ifndef __sNode_cpp__
#define __sNode_cpp__

using namespace std;

template<class T>
class Node{
	T element;
	Node *next;
	public:
		Node(){
		}
		Node(T element, Node<T> *next=nullptr){
			this->element = element;
			this->next = next;
		}
		void setElement(T element){
			this->element = element;
		}
		void setNext(Node<T> *next=nullptr){
			this->next = next;
		}
		T &getElement() {
			return element;
		}
		Node<T> *&getNext(){
			return next;
		}
};
#endif
