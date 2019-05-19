/*
 * Node.h
 *
 *  Created on: May 12, 2019
 *      Author: danny
 */

#ifndef NODE_H_
#define NODE_H_

#define ENDCHAR 0x30
#define NULLCHAR 0x00

struct Ascii {
	char c;
	unsigned int count;
};

struct EachChar {
	char c;
	unsigned int count;
	unsigned int bitSize;
	unsigned short enc;
};

struct Node {
		EachChar ec;
		Node *left;
		Node *right;

		Node() {
			left = nullptr;
			right = nullptr;
		}

		~Node(){
			if(left)
				delete left;
			if(right)
				delete right;
		}
};



#endif /* NODE_H_ */
