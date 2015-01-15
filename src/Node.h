#ifndef NODE_H
#define NODE_H

#include "Block.h"
//TODO Make head and tail blocks contained in here.
//The concept of a node.
struct Node
{
	public:
		Block BlockNode;
		int Index;
		Node *Next;
		Node *Prev;
};

//Methods for working on these nodes.
class NodeMethods
{
	private:
		Node *head;
		Node *last;
		int startIndex;

	public:
		NodeMethods();
		void Insert(Block block);
		void InsertAsFirstElement(Block block);
		bool IsEmpty();
		bool IsEmpty(Node *current);
		void Remove(Block block);
		void RemoveAt(Node *&current, const int index);
		Node *ReLinkList(Node *&current);
		void Search(Node *&current);
		void ResetToHead(Node *&current);
		void SetCurrent(Node *&current);

};
#endif
