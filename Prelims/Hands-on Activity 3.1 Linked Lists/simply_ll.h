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