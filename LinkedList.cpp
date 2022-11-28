// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}

/** Returns true  if list is empty, otherwise true */
bool ILinkedList::isEmpty() const
{
	//TODO - hint use m_count

	if(m_count == 0){
		return true;
	}

	return false;
	
}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
	// you can recursively handle this which would require some code
	// Otherwise you need to delete each node individuall in the owner of the Nodes (i.e. the LinkedList)
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{
	m_head = NULL;
	m_count = 0;
}

/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	
	Node *newNode;
	newNode = new Node;
	newNode->setItem(val);
	newNode->setNext(NULL);

	Node *prevNode = NULL;
	Node *currNode = m_head;

	if(m_head == NULL){
		m_head = newNode;
		//delete newNode;
		m_count++;
		return true;
	}
	else{
		int dontFryMyPC = 0;
		//currNode->setNext(m_head);
		//prevNode->setNext(currNode);
		while(currNode != NULL && dontFryMyPC < 99){
			
			prevNode = currNode;
			currNode = currNode->getNext();

			dontFryMyPC++;
		}
		if (dontFryMyPC < 99){
			prevNode->setNext(newNode);
			newNode->setNext(currNode);
			m_count++;
			return true;
		}
		else{
			return false;	
		}
	};


	//TODO
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	Node *prevNode = m_head;
	Node *currNode = m_head;

	if(m_head == NULL){
		cout << "List is empty, cannot delete." << endl;
		return false;
	}
	else{
		while((currNode != NULL) && (currNode->getItem() != val)){
			
			prevNode = currNode;
			currNode = currNode->getNext();
		}

		if(currNode != NULL && currNode == m_head){
			m_head = m_head->getNext();
			cout << "Deleting entry with value of " << currNode->getItem() << endl;
			//delete currNode;
			m_count--;
			return true;

		}
		else if(currNode != NULL){
			prevNode->setNext(currNode->getNext());
			cout << "Deleting entry with value of " << currNode->getItem() << endl;
			//delete currNode;
			m_count--;
			return true;
		}
		else{
			cout << "Cannot find entry with value of " << val;
			return false;
		}
	}
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	delete m_head;
	m_count = 0;
    //TODO
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	//TODO - maybe not depending on how you implement Node::~Node

}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";

	Node *currNode = m_head;

	while(currNode != NULL){
		str = str + to_string(currNode->getItem()) + " "; 
		currNode = currNode->getNext();
	}

	if (str.length() > 1){
		int i = 0;
		string newStr;
		while(i < (str.length() - 1)){
		newStr = newStr + str[i];
		i++;
		}
		str = newStr;
	};
	
    //TODO
	return str;
}

ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
	int i = 0;
	while(i < 10){
		m_values[i] = 0;
		i++;
	}
    m_count = 0;
	// you got it for free :)
}

bool ArrayBasedLinkedList::add(int val)
{


	while(m_count < 10)
	{
		if(m_values[m_count] == 0) {
			m_values[m_count] = val;
			m_count++;
			return true;
		}

		m_count++;
	}
	return false;
}
bool ArrayBasedLinkedList::remove(int val)
{
	//ArrayBasedLinkedList();
	
	int dubVal = 0;
	int i = 0;

	while(i < 10)
	{
		if(m_values[i] == val)
		{
			int k = 0;

			while(k+i < m_count){
				m_values[k+i] = m_values[k+i+1];
				k++;
			}
			m_values[m_count] = 0;
			m_count--;
			return true;
		}

		i++;
	}
	return false;
}
void ArrayBasedLinkedList::clear()
{

	int i = 0;

	while(i < m_count)
	{
		m_values[i] = 0;

		m_count--;
	}

}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{
 //cout << "TEST";  ** PAY NO ATTENTION TO THE COMMENT BEHIND THE CURTAIN
}

std::string ArrayBasedLinkedList::toString() const
{

	string str = "";
	int i = 0;
	if(m_count == 0){
		return str;
	}	

	while(i < m_count)
	{
        if(m_values[i] != m_values[10])
		{
			str = str + to_string(m_values[i]) + " ";
		}
		else
		{
			str = str + to_string(m_values[i]);
		}

		i++;
    }

	if (str.length() > 1){
		int i = 0;
		string newStr;
		while(i < (str.length() - 1)){
		newStr = newStr + str[i];
		i++;
		}
		str = newStr;
	};

	return str;
}
