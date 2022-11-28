// LinkedListExe.cpp : Defines the entry point for the console application.
//

//EXTRA COMMENT FOR COOL BRANCH

#include "LinkedList.h"


void FreeNodeList(Node * n)
{
	if (n->getNext() == nullptr)
	{
		delete n;
	}
	else
	{
		Node * cur = n->getNext();
		n->setNext(nullptr);
		delete n;
		FreeNodeList(cur);
	}
}

// This code is just sandbox code
int main()
{

	Node * head = nullptr;

	Node * cur = nullptr;

	head = new Node(1);

	cur = head;

	Node * temp = new Node(2);

	cur->setNext(temp);

	cur = cur->getNext();

	temp = nullptr;
	temp = new Node(3);

	cur->setNext(temp);

	cur = cur->getNext();

	//Now delete the memory

	FreeNodeList(head);


    return 0;
}

