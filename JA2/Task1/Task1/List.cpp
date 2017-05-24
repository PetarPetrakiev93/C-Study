#include "List.h"

#include<sstream>

List::Node::Node(T value, Node * prev, Node * next) {
	this->value = value;
	this->prev = prev;
	this->next = next;
}

T List::Node::getValue() const{
	return this->value;
}

void List::Node::setValue(T value) {
	this->value = value;
}

List::Node * List::Node::getNext() const {
	return this->next;
}

void List::Node::setNext(List::Node * next) {
	this->next = next;
}

List::Node * List::Node::getPrev() const {
	return this->prev;
}
void List::Node::setPrev(List::Node * prev) {
	this->prev = prev;
}

List::List():
	head(nullptr),
	tail(nullptr),
	size(0){
}
List::List(const List& other):
	head(nullptr),
	tail(nullptr),
	size(0) {
	this->addAll(other);
}

T List::first() const {
	if (this->isEmpty()) {
		throw "Cannot get first element of empty list";
	}
	return this->head->getValue();
}
void List::add(T value) {
	if (this->isEmpty()) {
		this->head = new Node(value, nullptr, nullptr);
		this->tail = this->head;
	}
	else {
		Node * added = new Node(value, this->tail, nullptr);
		this->tail->setNext(added);
		this->tail = added;
	}

	this->size++;
}
void List::addAll(const List& other) {
	for (Node * node = other.head; node != nullptr; node = node->getNext()) {
		this->add(node->getValue());
	}
}
void List::removeFirst() {
	if (!this->isEmpty()) {
		Node * oldHeadElement = this->head;

		if (this->head != this->tail) {
			this->head = this->head->getNext();
			this->head->setPrev(nullptr);
		}
		else {
			this->head = nullptr;
			this->tail = nullptr;
		}

		delete oldHeadElement;

		this->size--;
	}
}
void List::removeAll() {
	while (!this->isEmpty()) {
		this->removeFirst();
	}
}

size_t List::getSize() const {
	return this->size;
}
bool List::isEmpty() const {
	return this->getSize() == 0;
}

List List::getReversed(List l) {
	List reversed;
	for (Node * node = l.tail; node != nullptr; node = node->getPrev()) {
		reversed.add(node->getValue());
	}

	return reversed;
}
std::string List::toString() const {
	std::ostringstream ss;
	for (Node * node = head; node != nullptr; node = node->getNext()) {
		ss << node->getValue();
		if (node->getNext() != nullptr) {
			ss << " ";
		}
	}
	return ss.str();
}

List& List::operator<<(const T& value) {
	this->add(value);
	return *this;
}
List& List::operator<<(const List& other) {
	this->addAll(other);
	return *this;
}

List& List::operator=(const List& other) {
	if (this != &other) {
		this->removeAll();
		this->addAll(other);
	}

	return *this;
}

List::~List() {
	this->removeAll();
}