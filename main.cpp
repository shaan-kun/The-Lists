#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "stack.h"
#include "queue.h"
#include "list.h"
#include "double_linked_list.h"

/*
    Задача: создать список только уникальных слов исходного текста
    Реализация: стек, очередь, список в односвязной и двусвязной формах
*/

int main() {
    setlocale(LC_ALL, "rus");

    ifstream in("input.txt");
    ofstream out("output.txt");



    Stack <string> s;

    while (in.peek() != EOF) {
        string sub;
        in >> sub;

        if ( !s.exist(sub) )
                s.push(sub);
    }

    out << "_____STACK_____" << endl;
    s.print(out);
    out << endl;

    in.clear();
    in.seekg(0);



    Queue <string> q;

    while (in.peek() != EOF) {
        string sub;
        in >> sub;

        if ( !q.exist(sub) )
                q.push(sub);
    }

    out << "_____QUEUE_____" << endl;
    q.print(out);
    out << endl;

    in.clear();
    in.seekg(0);



    List <string> l;

    int i = 1;

    while (in.peek() != EOF) {
        string sub;
        in >> sub;

        if ( !l.exist(sub) )
                l.insert(i++, sub);
    }

    out << "_____LIST_____" << endl;
    l.print(out);
    out << endl;

    in.clear();
    in.seekg(0);



    DoubleLinkedList <string> dll;

    i = 1;

    while (in.peek() != EOF) {
        string sub;
        in >> sub;

        if ( !dll.exist(sub) )
                dll.insert(i++, sub);
    }

    out << "_____DOUBLE_LINKED_LIST_____" << endl;
    dll.printLeftToRight(out);

    in.close();
    out.close();

    return 0;
}
