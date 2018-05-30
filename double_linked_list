#include <iostream>
#include <fstream>

/*
    =========
    Интерфейс
    =========
    * - экземпляр класса DoubleLinkedList

    *.Empty() - проверка на пустоту
    *.GetLength() - узнать длину списка
    *.InsertLeft(index, x) - поместить в список x слева от позиции index
    *.InsertRight(index, x) - поместить в список x справа от позиции index
    *.Get(index) - взять элемент на позиции index из списка (элемент остаётся в списке)
    *.Remove(index) - удалить элемент на позиции index из списка
    *.PrintLeftToRight() - вывести на экран все элементы списка слева направо
    *.PrintRightToLeft() - вывести на экран все элементы списка справа налево
    *.isExist(obj) - есть ли в списке элемент obj
*/

template <class item>
class DoubleLinkedList {
private:
        struct Element {
            item data;
            Element *next;
            Element *prev;
            Element (item obj): data(obj), next(0), prev(0) {}
        };

        Element *head;
        Element *tail;
        int size;

        Element *find(int index) {
            if (index < 1 || index > size)
                return 0;
            else
            {
                Element *cursor = head;

                for (int i = 1; i < index; ++i)
                        cursor = cursor->next;

                return cursor;
            }
        }
    public:
        DoubleLinkedList(): head(0), tail(0), size(0) {}

        ~DoubleLinkedList() {
            while (!Empty() ) Remove(1);
        }

        bool Empty() {
            return head == 0;
        }

        int GetLength() {
            return size;
        }

        void InsertLeft(int index, item obj) {
            try
            {
                if (index < 1 || index > size + 1)
                        throw "DoubleLinkedList: insert - access error";

                Element *newEl = new Element (obj);
                ++size;

                Element *cursor = find(index);

                if (cursor == 0)
                    {
                        head = newEl;
                        tail = newEl;
                    }
                else
                    {
                        newEl->next = cursor;
                        newEl->prev = cursor->prev;
                        cursor->prev = newEl;

                        if (cursor == head)
                            head = newEl;
                        else
                            newEl->prev->next = newEl;
                    }
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        void InsertRight(int index, item obj) {
            try
            {
                if ( (index < 1 && head != 0) || (index > size + 1) )
                        throw "DoubleLinkedList: insert - access error";

                Element *newEl = new Element (obj);
                ++size;

                Element *cursor = find(index);

                if (cursor == 0)
                    {
                        head = newEl;
                        tail = newEl;
                    }
                else
                    {
                        newEl->next = cursor->next;
                        newEl->prev = cursor;
                        cursor->next = newEl;

                        if (cursor == tail)
                            tail = newEl;
                        else
                            newEl->next->prev = newEl;
                    }
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        item Get(int index) {
            try
            {
                if (index < 1 || index > size)
                        throw "ListException: get - access error";

                Element *temp = find(index);
                item obj = temp->data;

                return obj;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        void Remove(int index) {
            try
            {
                if (index < 1 || index > size)
                        throw "ListException: remove - access error";

                Element *cursor = find(index);
                --size;

                if (size == 0)
                    {
                        head = 0;
                        tail = 0;
                    }
                else
                    if (cursor == head)
                        {
                            head = head->next;
                            head->prev = 0;
                        }
                    else
                        if (cursor == tail)
                            {
                                tail = tail->prev;
                                tail->next = 0;
                            }
                        else
                            {
                                cursor->prev->next = cursor->next;
                                cursor->next->prev = cursor->prev;
                            }

                cursor->next = 0;
                cursor->prev = 0;
                delete cursor;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        void PrintLeftToRight(std::ofstream &out) {
            for (Element *cursor = head; cursor != 0; cursor = cursor->next)
                    out << cursor->data << " ";
        }

        void PrintRightToLeft(std::ofstream &out) {
            for (Element *cursor = tail; cursor != 0; cursor = cursor->prev)
                    out << cursor->data << " ";
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
