/*
 * main.cpp
 *
 *  Created on: May 11, 2019
 *      Author: danny
 */

#include <iostream>
#include <bitset>
#include <fstream>
#include "HuffmanTree.h"


int main(){

	HuffmanTree h;
	h.compress("date.txt", "dateOut.txt");

	return 0;
}


