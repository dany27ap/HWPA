/*
 * HuffmanTree.cpp
 *
 *  Created on: May 12, 2019
 *      Author: danny
 */

#include "HuffmanTree.h"
#include <vector>
#include <cstring>
#include <fstream>
#include <bitset>
#include <algorithm>

bool comparatorDeNoduri(Node *a, Node *b){
	return a->ec.count > b->ec.count;
}

HuffmanTree::HuffmanTree() {
	memset(ascii, 0, sizeof(Ascii)*256);
	root = nullptr;
}

HuffmanTree::~HuffmanTree() {
//	delete root;
}

void HuffmanTree::countChars() {

	for(unsigned int i = 0; i < text.size(); ++i){
		char c = text[i];
		ascii[(int)c].c = c;
		ascii[(int)c].count++;
	}
}

void HuffmanTree::showCompress(unsigned int n, unsigned int s){
	unsigned int num = 1 << (s-1);

	while(num) {
		if(n & num)
			std::cout << "1";
		else
			std::cout << "0";
		num >>= 1;
	}
}

void HuffmanTree::createTreeList(){
	for(int i = 0; i < 255; ++i){
		if(ascii[i].count > 0){
			Node *n = new Node;
			n->ec.c = ascii[i].c;
			n->ec.count = ascii[i].count;
			n->ec.bitSize = 0;
			n->ec.enc = 0;
			n->left = nullptr;
			n->right = nullptr;
			nodes.push_back(n);
		}
	}

}

void HuffmanTree::generateHuffmanTree(){

	std::make_heap(nodes.begin(), nodes.end(), comparatorDeNoduri);

	while(nodes.size() > 1){

		Node *n1 = nodes.front();
		std::pop_heap(nodes.begin(), nodes.end(), comparatorDeNoduri);
		nodes.pop_back();

		Node *n2 = nodes.front();
		std::pop_heap(nodes.begin(), nodes.end(), comparatorDeNoduri);
		nodes.pop_back();

		Node *n = new Node;
		n->ec.c = NULLCHAR;
		n->ec.count = n1->ec.count + n2->ec.count;
		n->ec.bitSize = 0;
		n->ec.enc = 0;
		n->left = n1;
		n->right = n2;

		nodes.push_back(n);
		std::push_heap(nodes.begin(), nodes.end(), comparatorDeNoduri);

	}

//	compFunctor comparator = compFunctor();
//
//	std::make_heap(nodes.begin(), nodes.end(), comparator);
//
//	while(nodes.size() > 1){
//
//		Node *n1 = nodes.front();
//		std::pop_heap(nodes.begin(), nodes.end(), comparator);
//		nodes.pop_back();
//
//		Node *n2 = nodes.back();
//		std::pop_heap(nodes.begin(), nodes.end(), comparator);
//		nodes.pop_back();
//
//		Node *n = new Node;
//		n->ec.c = NULLCHAR;
//		n->ec.count = n1->ec.count + n2->ec.count;
//		n->ec.bitSize = 0;
//		n->ec.enc = 0;
//		n->left = n1;
//		n->right = n2;
//
//		nodes.push_back(n);
//		std::push_heap(nodes.begin(), nodes.end(), comparator);
//	}
}


void HuffmanTree::traverse(Node *root, unsigned short encoding, unsigned int bitCount){
	if(root->left == nullptr and root->right == nullptr){
		nodeList.push_back(root);

		root->ec.enc = encoding;
		root->ec.bitSize = bitCount;

	}else if(root->left != nullptr && root->right != nullptr){

		traverse(root->left, encoding << 1, bitCount + 1);
		traverse(root->right, (encoding << 1) | 1, bitCount + 1);

	}else{
		throw 1;
	}

}
void HuffmanTree::compress(std::string pathFrom, std::string pathTo){

	loadFile(pathFrom);

	std::ofstream inFile;
	inFile.open(pathTo, std::ios::binary | std::ios::out);

	if(!inFile.is_open()) {
		std::cerr << "Unable to open file " << pathTo;
		exit(1);
	}

	countChars();
	createTreeList();
	generateHuffmanTree();


	root = nodes.front();

	traverse(root, 0, 0);


	for(unsigned int i = 0; i < 1; ++i) {
		for(unsigned int j = 0; j < nodeList.size(); ++j){
			if(nodeList[j]->ec.c){

				std::cout << nodeList[j]->ec.c << " : ";
				unsigned int encoding = nodeList[j]->ec.enc;
				unsigned int mask = 1 << (nodeList[j]->ec.bitSize - 1);
				for(unsigned int i = 0; i < nodeList[j]->ec.bitSize; ++i){
					std::cout << ((encoding & mask) ? '1' : '0');
					mask >>= 1;
				}
				std::cout << std::endl;

				inFile << std::bitset<16>(nodeList[j]->ec.enc);

			}
		}
	}

	inFile.close();

}
void HuffmanTree::loadFile(std::string fileName){

	std::ifstream inFile;
	inFile.open(fileName);

	if(!inFile) {
		std::cerr << "Unable to open file " << fileName;
		exit(1);
	}

	inFile.seekg(0, std::ios::end);
	unsigned length = inFile.tellg();
	inFile.seekg(0, std::ios::beg);

	text.reserve(length);

	text.assign(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>());

	inFile.close();
}



