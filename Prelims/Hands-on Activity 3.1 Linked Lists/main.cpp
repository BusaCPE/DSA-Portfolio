#include <iostream>
using namespace std;

template <typename T>
struct SimplyList
{
    T data;
    SimplyList* next;
};

// Function to delete the entire list
template <typename T>
void sllDeleteList(SimplyList<T>** head)
{
    SimplyList<T>* current = *head;

    while (current != nullptr)
    {
        SimplyList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}

int main()
{
    SimplyList<char>* head = new SimplyList<char>;
    SimplyList<char>* second = new SimplyList<char>;
    SimplyList<char>* third = new SimplyList<char>;
    SimplyList<char>* fourth = new SimplyList<char>;
    SimplyList<char>* fifth = new SimplyList<char>;

    head->data = 'E';
    head->next = second;

    second->data = 'M';
    second->next = third;

    third->data = 'M';
    third->next = fourth;

    fourth->data = 'A';
    fourth->next = fifth;

    fifth->data = 'N';
    fifth->next = nullptr;

    cout << head->data
         << second->data
         << third->data
         << fourth->data
         << fifth->data
         << endl;

    cout << "Deleting the entire list\n";

    sllDeleteList(&head);

    if (head == nullptr)
        cout << "List deleted successfully.\n";

    return 0;
}