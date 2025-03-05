#include <iostream>
#include <cstring>

struct Node {
	char data[256];
	Node* prev;
	Node* next;

	Node(const char* d) {
		strncpy(data, d, 255);
		data[255] = '\0';
		prev = next = nullptr;
	}
};

class DLL {
	public:
		Node* head;
		Node* tail;
		int length;
		DLL() {
			this->head = nullptr;
			this->tail = nullptr;
			this->length = 0;	
		}
		void Add(const char* data) {
			Node* newNode = new Node(data);

			if (head == nullptr) {head = newNode; tail = head;}
			else {
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
			length++;
		}
		void Print() {
			Node* curr = head;
			while (curr != nullptr) {
				std::cout << curr->data << " ";
				curr = curr->next;
			}
			std::cout << std::endl;
		}

		void Remove(int i) {
			if (head == nullptr || i < 0 || i >= length) return;

			Node* curr = head;
			for (int j = 0; j < i; j++) curr = curr->next;

			if (curr == head) {
				head = curr->next;
				if (head != nullptr) head->prev = nullptr;
				else tail = nullptr;
			} else if (curr == tail) {
				tail = curr->prev;
				tail->next = nullptr;
			} else {
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
			}

			length--;
		}

};

int main() {
    DLL list;

    // Add elements
    list.Add("Hello");
    list.Add("world!");
    list.Add("This");
    list.Add("is");
    list.Add("a");
    list.Add("test.");

    // Print the list
    std::cout << "List: ";
    list.Print();

    // Remove an element
    list.Remove(2); // Remove the third element ("This")

    // Print the list after removal
    std::cout << "List after removing element: ";
    list.Print();

    return 0;
}
