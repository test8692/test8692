// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	size = 0;
	homeNode = new Node('-');
	endNode = homeNode->InsertNextNode('-');
	currentNode = homeNode;
  return;
}

void TypingMachine::HomeKey() {
	currentNode = homeNode;
  return;
}

void TypingMachine::EndKey() {
	currentNode = endNode;
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
	if (0x20>=key||0x7E<=key)
		return false;
	if (size >= 100)
		return false;
	
	currentNode = currentNode->InsertNextNode(key);
	size++;
	endNode = currentNode;
	while (endNode->GetNextNode() != nullptr)
		endNode = endNode->GetNextNode();
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
		if (it != homeNode && it != endNode )
		builder += it->GetData();
		if (it == currentNode)
			builder += separator;
		it = it->GetNextNode();
	}
  return builder;
}
