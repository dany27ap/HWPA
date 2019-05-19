/*
 * Bfs.h
 *
 *  Created on: May 11, 2019
 *      Author: danny
 */

#ifndef BFS_H_
#define BFS_H_

#include <iostream>
#include "list.h"
#include <queue>


class Graph {

	int *np;
	List *L;
	int n;

public:
	Graph(int n){
		this->n = n;
		this->np = new int[n];
		this->L = new List[n];
		for(int i = 0; i < n ; ++i){
			np[i] = 0;
		}
	}

	void createList() {
		int value;
		for(int i = 0; i < n; ++i){
			std::cout << "Source " << i << std::endl;
			std::cout << "Destination: ";
			std::cin >> value;
			while(value >= 0 and value < n){
				L[i].insertOnEndPosition(value);
				np[value]++;
				std::cin >> value;
			}
		}
	}

	~Graph(){
		delete[] L;
		delete[] np;
	}



	void printBFS(){

		List coada;
		for(int u = 0; u < n; ++u){
			if(np[u] == 0){
				coada.insertOnEndPosition(u);
				coada.print();
			}
		}

		for(int k = 0; k < n; ++k){
			if(coada.isEmpty()){
				std::cout << "Graful contine cicluri";
				exit(1);
			}

			int u = coada.removeFirst();
			std::cout << u << " ";
			node *p = L[u].getHead();
			while(p != nullptr){
				int v = p->data;
				np[v]--;
				if(np[v] == 0)
					coada.insertOnEndPosition(v);
				p = p->next;
			}
		}
	}
};




#endif /* BFS_H_ */
