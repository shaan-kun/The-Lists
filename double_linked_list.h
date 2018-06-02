#ifndef DOUBLE_LINKED_LIST_H_INCLUDED
#define DOUBLE_LINKED_LIST_H_INCLUDED

#include <iostream>
#include <fstream>



template <class item>
class DoubleLinkedList {
private:
        // структура хранит информационное поле, а также указатели на следующий и предыдущий элементы
        struct Element {
            item data;
            Element *next;
            Element *prev;

            Element (item obj, Element *link1, Element *link2):
                data(obj), next(link1), prev(link2) {}
        };

        Element *head; // указатель на первый элемент списка
        Element *tail; // указатель на последний элемент списка
        int size; // длина списка

        // возвращает указатель на элемент, стоящий на позиции index
        Element *find(int index) {
            if (index < 1 || index > size)
                    return NULL;
            else
                {
                    Element *cursor = head;

                    for (int i = 1; i < index; ++i)
                            cursor = cursor->next;

                    return cursor;
                }
        }
    public:
        // конструктор по умолчанию
        DoubleLinkedList(): head(NULL), tail(NULL), size(0) {}

        // деструктор (очищает список, начиная с начала)
        ~DoubleLinkedList() {
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

        // возвращает количество элементов в списке
        int length() {
            return size;
        }

        // вставляет элемент на позицию index
        void insert(int index, item obj) {
            try
            {
                if (index < 1 || index > size + 1)
                        throw "DoubleLinkedList: insert - access error";

                if (empty() )
                {
                    Element *new_el = new Element (obj, NULL, NULL);
                    head = new_el;
                    tail = new_el;
                }
                else
                {
                    if (index == 1)
                    {
                        Element *new_el = new Element (obj, head, NULL);
                        head->prev = new_el;
                        head = new_el;
                    }
                    else
                    {
                        if (index == size + 1)
                        {
                                        Element *new_el = new Element (obj, NULL, tail);
                                        tail->next = new_el;
                                        tail = new_el;
                        }
                        else
                        {
                            Element *current = find(index);
                            Element *prior = current->prev;

                            Element *new_el = new Element (obj, current, prior);

                            prior->next = new_el;
                            current->prev = new_el;
                        }
                    }
                }

                ++size;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        // возвращает элемент, стоящий на позиции index
        item get(int index) {
            try
            {
                if (index < 1 || index > size)
                        throw "ListException: get - access error";

                Element *cur = find(index);
                item obj = cur->data;

                return obj;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        // удаляет элемент на позиции index
        void remove(int index) {
            try
            {
                if (index < 1 || index > size)
                        throw "ListException: remove - access error";

                Element *cur = find(index);

                if (index == 1)
                        head = cur->next;
                else
                    if (index == size)
                        tail = cur->prev;
                    else
                    {
                        Element *prev = cur->prev;
                        Element *next = cur->next;

                        prev->next = next;
                        next->prev = prev;
                    }

                delete cur;
                --size;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        // выводит на экран элементы списка слева направо
        void showLeftToRight() {
            for (Element *cursor = head; cursor != NULL; cursor = cursor->next)
                    std::cout << cursor->data << " ";
        }

        // выводит на экран элементы списка справа налево
        void showRightToLeft() {
            for (Element *cursor = tail; cursor != NULL; cursor = cursor->prev)
                    std::cout << cursor->data << " ";
        }

        // выводит в файл элементы списка слева направо
        void printLeftToRight(std::ofstream &out) {
            for (Element *cursor = head; cursor != 0; cursor = cursor->next)
                    out << cursor->data << " ";
        }

        // выводит в файл элементы списка справо налево
        void printRightToLeft(std::ofstream &out) {
            for (Element *cursor = tail; cursor != 0; cursor = cursor->prev)
                    out << cursor->data << " ";
        }

        // проверка на существование элемента в списке
        bool exist(item obj) {
            for (Element *cur = head; cur != NULL; cur = cur->next)
                if (cur->data == obj) return true;

            return false;
        }
};

#endif // DOUBLE_LINKED_LIST_H_INCLUDED
