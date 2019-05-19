/*
 * list.h
 *
 *  Created on: May 11, 2019
 *      Author: danny
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>

struct node {
	int data;
	node *next;
};

class List {

private:
	node *head, *tail;

public:
	List() {
		head = nullptr;
		tail = nullptr;
	}

	node *getHead(){
		return head;
	}


	void createNode(int value) {
		node *temp = new node;
		temp->data = value;
		temp->next = nullptr;
		if(head == nullptr){
			head = temp;
			tail = temp;
			temp = nullptr;
		} else {
			tail->next = temp;
			tail = temp;
		}
	}

	void print() {
		node *temp = new node;
		temp = getHead();
		while(temp != nullptr){
			std::cout << temp->data << "  ";
			temp = temp->next;
		}
	}

	void insertOnStartPosition(int value){
		node *temp = new node;
		temp->data = value;
		if(head == nullptr){
			temp->next = nullptr;
			head = temp;
			tail = temp;
			temp = nullptr;
		} else{
			temp->next = head;
			head = temp;
		}
	}

	void insertOnEndPosition(int value){
		node *temp = new node;
		temp->data = value;
		if(head == nullptr){
			head = temp;
			tail = temp;
			temp = nullptr;
		} else{
			tail->next = temp;
			tail = temp;
			temp = nullptr;
		}
	}

	void insertOnSpecificPosition(int value, int position) {
		node *predecesor = new node;
		node *current = new node;
		node *temp = new node;
		current = head;

		for(int i = 0; i < position - 1; i++){
			predecesor= current;
			current = current->next;
		}

		temp->data = value;
		temp->next = current;
		predecesor->next = temp;
	}

	bool isEmpty(){
		if(head == nullptr)
			return true;
		return false;
	}

	int removeFirst() {
		int value = head->data;
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;
		return value;
	}

	int removeLast() {
		int value = tail->data;
		node *current = new node;
		node *previous = new node;
		current = head;
		while(current->next != nullptr){
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = nullptr;
		delete current;
		return value;
	}

	int getData() {
		return head->data;
	}

	void nextElem() {
		if(head->next){
			head = head->next;
		} else
			return;
	}
};


#endif /* LIST_H_ */
