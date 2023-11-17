#include "../include/Route.h"
#include <iostream>


Route::Route() : head(nullptr), tail(nullptr), color(Color::Black) {
}

Route::Route(Node* head, Node* tail) : head(head), tail(tail), color(Color::White) {
}


void Route::set_start_node(Node* head) {
	this->head = head;
}

Node* Route::get_start_node() {
	return head;
}

void Route::set_end_node(Node* tail) {
	this->tail = tail;
}

Node* Route::get_end_node() {
	return tail;
}

void Route::add_node(Node* node) {

	std::cout << "Nodo anadido: " << node->get_x() << " " << node->get_y() << std::endl;
	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else {
		tail->set_next(node);
		node->set_prev(tail);
		tail = node;
	}
}

void Route::delete_node(Node* node) {
	if (node == head) {
		head = node->get_next();
		head->set_prev(nullptr);
	}
	else if (node == tail) {
		tail = node->get_prev();
		tail->set_next(nullptr);
	}
	else {
		node->get_prev()->set_next(node->get_next());
		node->get_next()->set_prev(node->get_prev());
	}
}


void Route::draw(RenderWindow& window) {

	Node* current = head;
	while (current != nullptr) {


		CircleShape circle(10);
		circle.setFillColor(color);
		circle.setPosition(current->get_x() - 3, current->get_y() - 3);

		CircleShape border(10);
		border.setFillColor(Color::Black);
		border.setPosition(current->get_x() - 3, current->get_y() - 3);

		if (current->get_next() != nullptr) {
			Vertex line[] =
			{
				Vertex(Vector2f(current->get_x(), current->get_y())),
				Vertex(Vector2f(current->get_next()->get_x(), current->get_next()->get_y()))
			};
			window.draw(line, 2, Lines);
		}
		window.draw(border);
		window.draw(circle);
		current = current->get_next();
	}
}

void Route::change_color(Color color) {
	this->color = color;
}