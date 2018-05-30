#include <iostream>
#include <fstream>

/*
    =========
    Интерфейс
    =========
    * - экземпляр класса Stack

    *.Empty() - проверка на пустоту
    *.Push(x) - поместить x в стек
    *.Get() - взять верхний элемент из стека
    *.View() - просмотреть верхний элемент стека
    *.Print() - вывести на экран содержимое стека
    *.isExist(obj) - есть ли в стеке элемент obj
*/

template <class item>
class Stack {
    private:
        struct Element {
            item data;
            Element *next;

            Element (item obj, Element *link): data(obj), next(link) {}
        };

        Element *head;
    public:
        Stack(): head(0) {}

        bool Empty() {
            return head == 0;
        }

        void Push(item obj) {
            head = new Element (obj, head);
        }

        item Get() {
            try
            {
                if (Empty() )
                        throw "StackException: Pop - stack is empty";

                item obj = head->data;
                head = head->next;

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
                        throw "StackException: View - stack is empty";

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
