/*
 * HuffmanTree.h
 *
 *  Created on: May 12, 2019
 *      Author: danny
 */

#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_
#include <string>
#include <iostream>
#include <vector>
#include "Node.h"
#include <algorithm>

class HuffmanTree {

	std::string text;
	std::vector<Node*> nodes, nodeList;
	Ascii ascii[256];
	Node *root;


public:
	HuffmanTree();
	~HuffmanTree();

	void countChars();
	void createTreeList();
	void generateHuffmanTree();
	void traverse(Node *root, unsigned short encodint, unsigned int bitCount);
	void compress(std::string pathFrom, std::string pathTo);
	void loadFile(std::string fileName);
	void showCompress(unsigned int n, unsigned int s);

};

#endif /* HUFFMANTREE_H_ */
