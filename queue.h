#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#include <fstream>



template <class item>
class Queue {
    private:
        // Структура хранит информационное поле и указатель на следующий элемент очереди
        struct Element {
            item data;
            Element *next;

            Element (item obj):
                data(obj), next(NULL) {}
        };

        Element *head; // указатель на первый элемент очереди
        Element *tail; // указатель на последний элемент очереди
    public:
        // конструктор по умолчанию
        Queue(): head(NULL), tail(NULL) {}

        // деструктор (очищает очередь, начиная с начала)
        ~Queue() {
            while (head != NULL) {
                Element *cur = head;
                head = head->next;

                delete cur;
            }
        }

        // проверка на пустоту
        bool empty() {
            return head == NULL;
        }

        // помещает элемент в очередь
        void push(item obj) {
            if ( empty() )
            {
                tail = new Element(obj);
                head = tail;
            }
            else
            {
                Element *cur = tail;
                tail = new Element(obj);
                cur->next = tail;
            }
        }

        // забирает первый элемент из очереди
        item get() {
            try
            {
                if ( empty() )
                        throw "QueueException: get - queue is empty";

                item obj = head->data;

                Element *cur = head;
                head = head->next;

                delete cur;

                if (head == NULL)
                        tail = NULL;

                return obj;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        // возвращает первый элемент очереди
        item view() {
            try
            {
                if ( empty() )
                        throw "QueueException: View - queue is empty";

                return head->data;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        // выводит на экран содержимое очереди
        void show() {
            for (Element *cur = head; cur != NULL; cur = cur->next)
                    std::cout << cur->data << " ";
        }

        // выводит в файл содержимое очереди
        void print(std::ofstream &out) {
            for (Element *cur = head; cur != NULL; cur = cur->next)
                    out << cur->data << " ";
        }

        // проверка на существование элемента в очереди
        bool exist(item obj) {
            for (Element *cur = head; cur != NULL; cur = cur->next)
                if (cur->data == obj) return true;

            return false;
        }
};


#endif // QUEUE_H_INCLUDED
