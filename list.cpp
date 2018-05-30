#include <iostream>
#include <fstream>

/*
    =========
    Интерфейс
    =========
    * - экземпляр класса List

    *.Empty() - проверка на пустоту
    *.GetLength() - узнать длину списка
    *.Insert(index, x) - поместить в список x на позицию index
    *.Get(index) - взять элемент на позиции index из списка (элемент остаётся в списке)
    *.Remove(index) - удалить элемент на позиции index из списка
    *.Print() - вывести на экран все элементы списка
    *.isExist(obj) - есть ли в списке элемент obj
*/

template <class item>
class List {
private:
        struct Element {
            item data;
            Element *next;
            Element (item obj): data(obj), next(0) {}
        };

        Element *head;
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
        List(): head(0), size(0) {}

        ~List() {
            while (!Empty() ) Remove(1);
        }

        bool Empty() {
            return head == 0;
        }

        int GetLength() {
            return size;
        }

        void Insert(int index, item obj) {
            try
            {
                if (index < 1 || index > size + 1)
                        throw "ListException: insert - access error";

                Element *newEl = new Element (obj);
                ++size;

                if (index == 1)
                    {
                        newEl->next = head;
                        head = newEl;
                    }
                else
                    {
                        Element *prev = find(index - 1);
                        newEl->next = prev->next;
                        prev->next = newEl;
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

                Element *cursor;
                --size;

                if (index == 1)
                    {
                        cursor = head;
                        head = head->next;
                    }
                else
                    {
                        Element *prev = find(index - 1);
                        cursor = prev->next;
                        prev->next = cursor->next;
                    }

                cursor->next = 0;
                delete cursor;
            }

            catch (char const *str) {
                std::cout << str << std::endl;;
            }
        }

        void Print(std::ofstream &out) {
            for (Element *cursor = head; cursor != 0; cursor = cursor->next)
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
