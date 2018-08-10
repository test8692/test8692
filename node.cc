// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	rawData = data;
	prevNode = nextNode = nullptr;
  return;
}

char Node::GetData() {
  return rawData;
}

Node* Node::GetPreviousNode() {
  return prevNode;
}

Node* Node::GetNextNode() {
  return nextNode;
}

Node* Node::InsertPreviousNode(char data) {
	Node* newOne = new Node(data);
	newOne->prevNode = GetPreviousNode();
	newOne->nextNode = this;
	if (prevNode != nullptr)
		prevNode->nextNode = newOne;
	prevNode = newOne;
  return newOne;
}

Node* Node::InsertNextNode(char data) {
	Node* newOne = new Node(data);
	newOne->prevNode = this;
	newOne->nextNode = GetNextNode();
	if (nextNode != nullptr)
		nextNode->prevNode = newOne;
	nextNode = newOne;
	return newOne;
}

bool Node::ErasePreviousNode() {
	if (prevNode != nullptr) {
		Node* targetNode = prevNode;
		prevNode = prevNode->GetPreviousNode();
		if (prevNode!=nullptr)
			prevNode->nextNode = this;
		delete targetNode;
		return true;
	}
  return false;
}

bool Node::EraseNextNode() {
	if (nextNode != nullptr) {
		Node* targetNode = nextNode;
		nextNode = nextNode->GetNextNode();
		if (nextNode != nullptr)
			nextNode->prevNode = this;
		delete targetNode;
		return true;
	}
  return false;
}
