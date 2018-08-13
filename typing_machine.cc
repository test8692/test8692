// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	size = 0;
	homeNode = new Node('-');
	currentNode = homeNode;
  return;
}

void TypingMachine::HomeKey() {
	currentNode = homeNode;
  return;
}

void TypingMachine::EndKey() {
	while (currentNode->GetNextNode() != nullptr)
		currentNode = currentNode->GetNextNode();
  return;
}

void TypingMachine::LeftKey() {
	if (currentNode->GetPreviousNode() != nullptr)
		currentNode = currentNode->GetPreviousNode();
  return;
}

void TypingMachine::RightKey() {
	if (currentNode->GetNextNode() != nullptr)
		currentNode = currentNode->GetNextNode();
  return;
}

bool TypingMachine::TypeKey(char key) {
	if (0x20>key||0x7E<key)
		return false;
	if (size >= 100)
		return false;
	
	currentNode = currentNode->InsertNextNode(key);
	size++;
	return true;
}

bool TypingMachine::EraseKey() {
	if (size<=0)
		return false;
	if (currentNode == homeNode)
		return false;
	currentNode = currentNode->GetPreviousNode();
	currentNode->EraseNextNode();
	size--;
	return true;
}

std::string TypingMachine::Print(char separator) {
	Node* it = homeNode;
	std::string builder = "";
	while (it != nullptr) {
		if (it != homeNode)
		builder += it->GetData();
		if (it == currentNode && separator != 0)
			builder += separator;
		it = it->GetNextNode();
	}
  return builder;
}
