#include <iostream>
#include <cstring>

using namespace std;

struct Node {
	char data[256];
	Node* prev;
	Node* next;

	Node(const char* str) {
		strncpy(data, str, 255);
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
			if (head == nullptr) head = tail = newNode;
			else {
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
				Node* curr = head;
			}
			length++;
		}

		void Print() {
			Node* curr = head;
			while (curr != nullptr) {
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << endl;
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
			if (curr->next != nullptr) curr->next->prev = curr->prev;
			if (curr == head) head = curr->next;
			if (curr == tail) tail = curr->prev;

			length--;
		}

};

int main() {
    DLL list;

    // Add elements
    list.Add("Cats");
    list.Add("rule");
    list.Add("the");
    list.Add("world");
    list.Add("<3");
    list.Add("!");

    // Print the list
    cout << "Initial list: ";
    list.Print();

    // Remove an element
    list.Remove(2); // Remove the third elemnt ("the")

    // Print the list after removal
    cout << "List after removing element: ";
    list.Print();

    return 0;
}

