#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <fstream>



template <class item>
class List {
private:
        // Структура хранит информационное поле и указатель на следующий элемент списка
        struct Element {
            item data;
            Element *next;

            Element (item obj, Element *link):
                data(obj), next(link) {}
        };

        Element *head; // указатель на первый элемент списка
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
        //конструктор по умолчанию
        List(): head(NULL), size(0) {}

        // деструктор (очищает список, начиная с начала)
        ~List() {
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

        // возвращает количество элементов списка
        int length() {
            return size;
        }

        // вставляет элемент obj на позицию index
        void insert(int index, item obj) {
            try
            {
                if (index < 1 || index > size + 1)
                        throw "ListException: insert - access error";

                if (index == 1)
                    {
                        head = new Element (obj, head);
                    }
                else
                    {
                        Element *prior = find(index - 1);
                        Element *current = prior->next;

                        Element *new_el = new Element (obj, current);
                        prior->next = new_el;
                    }

                ++size;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        // возвращает элемент, стоящий из позиции index
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
                    {
                        head = head->next;
                    }
                else
                    {
                        Element *prior = find(index - 1);
                        prior->next = cur->next;
                    }

                delete cur;
                --size;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        // выводит на экран элементы списка
        void show() {
            for (Element *cursor = head; cursor != NULL; cursor = cursor->next)
                    std::cout << cursor->data << " ";
        }

        // выводит в файл элементы списка
        void print(std::ofstream &out) {
            for (Element *cursor = head; cursor != NULL; cursor = cursor->next)
                    out << cursor->data << " ";
        }

        // проверка на существование элемента в списке
        bool exist(item obj) {
            for (Element *cur = head; cur != NULL; cur = cur->next)
                if (cur->data == obj) return true;

            return false;
        }
};

#endif // LIST_H_INCLUDED
