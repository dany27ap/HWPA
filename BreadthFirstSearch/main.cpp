/*
 * main.cpp
 *
 *  Created on: May 8, 2019
 *      Author: danny
 */
#include <iostream>
#include "list.h"
#include "Bfs.h"

int main() {
	Graph g(5);
	g.createList();
	g.printBFS();
}


