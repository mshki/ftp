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
			if (head == nullptr) head = newNode;
			else {
				Node* curr = head;
				while (curr->next != nullptr) curr = curr->next;
				curr->next = newNode;
				newNode->prev = curr;
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
			if (head == nullptr || i < 0) return;

			Node* curr = head;
			int cnt = 0;

			while (curr != nullptr && cnt < i) {
				curr = curr->next;
				cnt++;
			}

			if (curr == nullptr) return;
			
			if (curr->prev != nullptr) curr->prev->next = curr->next;
			else head = curr->next;

			if (curr->next != nullptr) curr->next->prev = curr->prev;

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
    std::cout << "Initial list: ";
    list.Print();

    // Remove an element
    list.Remove(2); // Remove the third element ("This")

    // Print the list after removal
    std::cout << "List after removing element: ";
    list.Print();

    return 0;
}
