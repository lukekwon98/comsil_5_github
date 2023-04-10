#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
#include <string>
using namespace std;

//LinkedList Node
template <typename T> //template
class Node{
	public:
		//데이터를 저장할 변수
		T data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node<T> *link;

		Node(T element){ //receive T type elem and change link to null
		  data = element;
		  link = 0;
		}
	};

//LinkedList Class
template <typename T>
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first;
		int current_size; //num of total nodes
	public:
		//생성자, 초기화 
		LinkedList(){
			first = 0; //initial state = no nodes
			current_size = 0; //num nodes = 0
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size; //return num of nodes
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element);
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element);

		//리스트 출력
		void Print();
};


//새 노드를 맨 앞에 붙이고 값을 넣음
template <typename T>
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first; //newnode link points to previous first
	first = newnode; //newnode becomes first
	current_size++; //increment size
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template <typename T>
bool LinkedList<T>::Delete(T &element){

	if (first == 0)
		return false;
	
	Node<T> *current = first; //start at first node
	Node<T> *previous = 0;
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous) //if there are more than 2 nodes
				previous -> link = current -> link; //sets prev link (remaining link) to NULL
			else
				first = first -> link; //if there is only 1 node, first will now point to NULL
			break;
		}
		previous = current; //keep moving forward, former current is now prev
		current = current -> link; //move to next node
	}
	element = current -> data; //save deleted data in element (reference)
	delete current; //delete node current
	current_size--; //reduce size by 1

	return true;
}

//리스트를 출력하는 Print 함수
template <typename T>
void LinkedList<T>::Print(){
	Node<T> *i; //node currently being printed
	int index = 1; //index of curr node

	if (current_size != 0){ //if there is at least 1 node in list
		for( i = first; i != NULL; i=i->link){ //print until current node becomes NULL (end of list)
			if (index == current_size){  //last index
				cout << "[" << index << "|"; //print index of current node
				cout << i -> data <<"]"; //print data of current node, no arrow for the last node
			}
			
			else {
				cout << "[" << index << "|"; //index
				cout << i -> data << "]->"; //last node
				index++; //increment index
			}
		}
		cout << endl;
	}

}


#endif
