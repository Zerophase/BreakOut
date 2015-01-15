#include "Node.h"

//Inserts and element in the node at the next spot and assigns that nodes next and previous, unless it is the first element.

NodeMethods::NodeMethods()
{
	head = nullptr;
	last = nullptr;
}

void NodeMethods::Insert(Block block)
{
	if(IsEmpty())
		InsertAsFirstElement(block);
	else
	{
		Node *temp = new Node;
		temp->BlockNode = block;
		temp->Index = ++startIndex;
		temp->Next = nullptr;
		last->Next = temp;
		temp->Prev = last;
		last = temp;
		last->Prev = temp->Prev;
	}
}

//if it is the first element the node is set to the first node.
void NodeMethods::InsertAsFirstElement(Block block)
{
	Node *temp = new Node;

	startIndex = 0;

	temp->BlockNode = block;
	temp->Index = startIndex;
	temp->Next = nullptr;
	temp->Prev = nullptr;
	head = temp;
	last = temp;
}

//checks if the node has anything in it, so the first node can be set up
bool NodeMethods::IsEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

bool NodeMethods::IsEmpty(Node *current)
{
	if (current == nullptr)
		return true;
	else
		return false;
}
//Removes nodes. I don't believe this works as intended. I didn't end up using it.
void NodeMethods::Remove(Block block)
{
	if (IsEmpty())
	{
		//Do nothing
	}
	else if (head == last)
	{
		delete head;
		head = nullptr;
		last = nullptr;
	}
	else
	{
		Node *temp = head;
		head = head->Next;
		delete temp;
	}
}

//Responsible for Removing the node.
void NodeMethods::RemoveAt(Node *&current, const int index)
{
	Node *temp;
	Node *newNode = current;
	if (IsEmpty(current))
	{
		//Do nothing
	}
	//TODO Might need to add special case for removing the last node.
	else
	{
		//Search(current);
		//delete temp;
		current = ReLinkList(current);
	}
}

//TODO implement conditions for popping head forward
//when ball hits the head node.
Node *NodeMethods::ReLinkList(Node *&current)
{
	Node *temp;

	if(current->Prev != nullptr && current->Next != nullptr)
		temp = current->Prev;
	else if (head == current)
	{
		head = current->Next;
		temp = head;
		temp->Prev = nullptr;
		current = temp;
	}
	else if(last == current)
	{
		//TODO Test
		last = current->Prev;
		temp = last;
		temp->Next = nullptr;
		current = temp;
	}

	if(current->Next != nullptr && temp != current->Next)
		temp->Next = current->Next;
	/*else if(temp->Next != nullptr)
		temp = current->Next;*/

	if(current->Prev != nullptr && temp != current)
		temp->Next->Prev = current->Prev;
	else if(temp->Prev != nullptr)
	{
		//temp->Prev->Next = nullptr;
		//temp->Prev = nullptr;
	}
		
	return temp;
}

//Searches through the node into it finds the index being looked for.
void NodeMethods::Search(Node *&current)
{
	Node *temp = current;
	
	if (temp->Next == nullptr)
	{
		ResetToHead(current);
		return;
	}
			
	if (current->Index == temp->Next->Index)
	{
		current = temp;
		return;
	}
	else
	{
		current = current->Next;
		temp = current;
	}

	if (current == nullptr)
	{
		return;
	}
}

//resets the node to the head.
void NodeMethods::ResetToHead(Node *&current)
{
	current = head;
}

//Same as the top one.  Might have a use to differentiate this one someday.
void NodeMethods::SetCurrent(Node *&current)
{
	current = head;
}