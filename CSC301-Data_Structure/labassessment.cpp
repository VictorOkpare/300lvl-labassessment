#include <iostream>
#include <string>
using namespace std;

// Node structure for the linked list
struct Customer {
    string name;
    int id; // Customer ID
    Customer* next;

    Customer(string n, int i) : name(n), id(i), next(nullptr) {}
};

// Linked list class for the restaurant queue
class RestaurantQueue {
private:
    Customer* head;

public:
    RestaurantQueue() : head(nullptr) {}

    // Add customer at the END of the queue (Regular customers)
    void addCustomerAtEnd(string name, int id) {
        Customer* newCustomer = new Customer(name, id);
        if (!head) {
            head = newCustomer;
        } else {
            Customer* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newCustomer;
        }
        cout << name << " (Customer #" << id << ") has joined the queue at the end." << endl;
    }

    // Add customer at the BEGINNING of the queue (VIP customers)
    void addCustomerAtBeginning(string name, int id) {
        Customer* newCustomer = new Customer(name, id);
        newCustomer->next = head;
        head = newCustomer;
        cout << name << " (Customer #" << id << ") has joined the queue at the beginning as a VIP." << endl;
    }

    // Add customer at a specific POSITION in the queue
    void addCustomerAtPosition(string name, int id, int position) {
        Customer* newCustomer = new Customer(name, id);
        if (position == 1) {
            addCustomerAtBeginning(name, id);
            return;
        }

        Customer* temp = head;
        for (int i = 1; temp && i < position - 1; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Invalid position! Adding customer at the end instead." << endl;
            addCustomerAtEnd(name, id);
        } else {
            newCustomer->next = temp->next;
            temp->next = newCustomer;
            cout << name << " (Customer #" << id << ") has joined the queue at position " << position << "." << endl;
        }
    }

    // Serve the first customer in the queue
    void serveCustomer() {
        if (!head) {
            cout << "No customers in the queue to serve." << endl;
            return;
        }
        Customer* temp = head;
        head = head->next;
        cout << temp->name << " (Customer #" << temp->id << ") has been served and removed from the queue." << endl;
        delete temp;
    }

    // Remove a customer by name
    void removeCustomerByName(string name) {
        if (!head) {
            cout << "Queue is empty. Cannot remove customer." << endl;
            return;
        }

        if (head->name == name) {
            Customer* temp = head;
            head = head->next;
            cout << temp->name << " (Customer #" << temp->id << ") has left the queue." << endl;
            delete temp;
            return;
        }

        Customer* temp = head;
        while (temp->next && temp->next->name != name) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "Customer " << name << " not found in the queue." << endl;
            return;
        }

        Customer* customerToRemove = temp->next;
        temp->next = temp->next->next;
        cout << customerToRemove->name << " (Customer #" << customerToRemove->id << ") has left the queue." << endl;
        delete customerToRemove;
    }

    // Remove a customer by position
    void removeCustomerByPosition(int position) {
        if (!head) {
            cout << "Queue is empty. Cannot remove customer." << endl;
            return;
        }

        if (position == 1) {
            serveCustomer();
            return;
        }

        Customer* temp = head;
        for (int i = 1; temp->next && i < position - 1; i++) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "Invalid position! No customer at position " << position << "." << endl;
            return;
        }

        Customer* customerToRemove = temp->next;
        temp->next = temp->next->next;
        cout << customerToRemove->name << " (Customer #" << customerToRemove->id << ") has been removed from the queue." << endl;
        delete customerToRemove;
    }

    // Display all customers in the queue
    void displayQueue() {
        if (!head) {
            cout << "Queue is empty." << endl;
            return;
        }

        Customer* temp = head;
        cout << "Current Queue: ";
        while (temp) {
            cout << temp->name << " (Customer #" << temp->id << ") -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    //  free memory
    ~RestaurantQueue() {
        while (head) {
            serveCustomer();
        }
    }
};

int main() {
    RestaurantQueue queue;

    // Test Case 1: Adding customers at different positions
    cout << "\nTest Case 1: Adding Customers\n";
    queue.addCustomerAtEnd("Obi", 101);
    queue.addCustomerAtEnd("Chisom", 102);
    queue.addCustomerAtBeginning("VIP Dangote", 103);
    queue.addCustomerAtPosition("Reserved Sarah", 104, 2);
    queue.displayQueue();

    // Test Case 2: Serving customers
    cout << "\nTest Case 2: Serving Customers\n";
    queue.serveCustomer();
    queue.displayQueue();

    // Test Case 3: Removing a customer by name
    cout << "\nTest Case 3: Removing a Customer by Name\n";
    queue.removeCustomerByName("Chisom");
    queue.displayQueue();

    // Test Case 4: Removing a customer by position
    cout << "\nTest Case 4: Removing a Customer by Position\n";
    queue.removeCustomerByPosition(2);
    queue.displayQueue();

     // Test Case 5: Removing a customer that is not in the queue.
     cout << "\nTest Case 5: Removing a Customer name that is not in the queue\n";
     queue.removeCustomerByName("Tinubu");
     queue.displayQueue();

    return 0;
}
