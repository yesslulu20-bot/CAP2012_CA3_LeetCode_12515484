
class MyLinkedList {
private:
    struct Node {
        int value;
        Node* next;

        Node(int y) {
            value = y;
            next = nullptr;
        }
    };

    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->value;
    }

    void addAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;

            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newNode;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* current = head;

        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        Node* temp;

        if (index == 0) {
            temp = head;
            head = head->next;
        } else {
            Node* current = head;

            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            temp = current->next;
            current->next = temp->next;
        }

        delete temp;
        size--;
    }
};
