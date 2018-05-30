#include <iostream>
#include <fstream>

/*
    =========
    Интерфейс
    =========
    * - экземпляр класса Queue

    *.Empty() - проверка на пустоту
    *.Push(x) - поместить x в очередь
    *.Get() - взять первый элемент из очереди
    *.View() - просмотреть первый элемент очереди
    *.Print() - вывести на экран содержимое очереди
    *.isExist(obj) - есть ли в очереди элемент obj
*/

template <class item>
class Queue {
    private:
        struct Element {
            item data;
            Element *next;
            Element (item obj): data(obj), next(0) {}
        };

        Element *head, *tail;
    public:
        Queue(): head(0), tail(0) {}

        bool Empty() {
            return head == 0;
        }

        void Push(item obj) {
            Element *temp = tail;
            tail = new Element (obj);

            if (head == 0)
                head = tail;
            else
                temp->next = tail;
        }

        item Get() {
            try
            {
                if (Empty() )
                        throw "QueueException: get - queue is empty";

                item obj = head->data;
                head = head->next;

                if (head == 0)
                        tail = 0;

                return obj;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        item View() {
            try
            {
                if (Empty() )
                        throw "QueueException: View - queue is empty";

                return head->data;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        void Print(std::ofstream &out) {
            Element *cursor = head;

            while (cursor != 0) {
                out << cursor->data << " ";

                cursor = cursor->next;
            }
        }

        bool isExist(item obj) {
            Element *cursor = head;

            while (cursor != 0) {
                if (cursor->data == obj)
                        return true;

                cursor = cursor->next;
            }

            return false;
        }
};
