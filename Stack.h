#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 inherited 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <typename T>
class Stack : public LinkedList<T>{
	public: //only overload delete function -> LIFO
		bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first == 0){ //if this->first is 0
				return false;
			}
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T> *current = this->first; //you must use 'this' because you are accessing a base class member
			this->first = current->link; //change first to node to 2nd node
			element = current->data; //save data to element (reference)
			delete current; //delete current
			this->current_size -= 1; //decrement link size

			return true;
			}
};
