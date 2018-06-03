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
            Element *prev;

            Element (item obj, Element *link):
                data(obj), prev(link) {}
        };

        Element *head; // указатель на верхний элемент
    public:
        // конструктор по умолчанию
        Stack(): head(NULL) {}

        // деструктор (очищает стек, начиная с головы)
        ~Stack() {
            while (head != NULL) {
                Element *cur = head;
                head = head->prev;

                delete cur;
            }
        }

        // проверка на пустоту
        bool empty() {
            return head == NULL;
        }

        // помещает элемент в стек
        void push(item obj) {
            head = new Element (obj, head);
        }

        // забирает верхний элемент из стека
        item get() {
            try
            {
                if (empty() )
                        throw "StackException: get - stack is empty!";

                item obj = head->data;

                Element *cur = head;
                head = head->prev;

                delete cur;

                return obj;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        // возвращает верхний элемент стека
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

        // выводит на экран содержимое стека
        void show() {
            for (Element *cur = head; cur != NULL; cur = cur->prev)
                    std::cout << cur->data << " ";
        }

        // выводит в файл содержимое стека
        void print(std::ofstream &out) {
            for (Element *cur = head; cur != NULL; cur = cur->prev)
                    out << cur->data << " ";
        }

        // проверка на существование элемента в стеке
        bool exist(item obj) {
            for (Element *cur = head; cur != NULL; cur = cur->prev)
                if (cur->data == obj)
                        return true;

            return false;
        }
};

#endif // STACK_H_INCLUDED
