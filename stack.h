#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <fstream>



template <class item>
class Stack {
    private:
        // Структура хранит информационное поле и указатель на следующий элемент стека
        struct Element {
            item data;
            Element *next;

            Element (item obj, Element *link):
                data(obj), next(link) {}
        };

        Element *head; // указатель на верхний элемент
    public:
        // конструктор по умолчанию
        Stack(): head(NULL) {}

        // деструктор (очищает стек, начиная с головы)
        ~Stack() {
            if (head != NULL)
                {
                    do {
                        Element *cur = head;
                        head = head->next;

                        delete cur;
                    } while (head != NULL);
                }
        }

        // проверка на пустоту
        bool empty() {
            return head == NULL;
        }

        // поместить элемент в стек
        void push(item obj) {
            head = new Element (obj, head);
        }

        // взять верхний элемент из стека
        item get() {
            try
            {
                if (empty() )
                        throw "StackException: get - stack is empty!";

                Element *cur = head;
                item obj = head->data;
                head = head->next;

                delete cur;
                return obj;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        // просмотреть верхний элемент стека
        item view() {
            try
            {
                if (empty() )
                        throw "StackException: view - stack is empty!";

                return head->data;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        // вывести на экран содержимое стека
        void show() {
            for (Element *cur = head; cur != NULL; cur = cur->next)
                    std::cout << cur->data << " ";
        }

        // вывести в файл содержимое стека
        void print(std::ofstream &out) {
            for (Element *cur = head; cur != NULL; cur = cur->next)
                    out << cur->data << " ";
        }

        // проверка, есть ли в стеке элемент
        bool exist(item obj) {
            for (Element *cur = head; cur != NULL; cur = cur->next)
                if (cur->data == obj)
                        return true;

            return false;
        }
};

#endif // STACK_H_INCLUDED
