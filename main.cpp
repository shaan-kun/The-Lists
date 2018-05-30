#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "stack.cpp"
#include "queue.cpp"
#include "list.cpp"
#include "double_linked_list.cpp"

int main() {
    setlocale(LC_ALL, "rus");

    ifstream in("input.txt");
    ofstream out("output.txt");



    Stack <string> test_stack;

    while (in.peek() != EOF) {
        string sub;
        in >> sub;

        if (!test_stack.isExist(sub) )
                test_stack.Push(sub);
    }

    out << "_____STACK_____" << endl;
    test_stack.Print(out);
    out << endl;

    in.clear();
    in.seekg(0);



    Queue <string> test_queue;

    while (in.peek() != EOF) {
        string sub;
        in >> sub;

        if (!test_queue.isExist(sub) )
                test_queue.Push(sub);
    }

    out << "_____QUEUE_____" << endl;
    test_queue.Print(out);
    out << endl;

    in.clear();
    in.seekg(0);



    List <string> test_list;

    while (in.peek() != EOF) {
        string sub;
        in >> sub;

        if (!test_list.isExist(sub) )
                test_list.Insert(1, sub);
    }

    out << "_____LIST_____" << endl;
    test_list.Print(out);
    out << endl;

    in.clear();
    in.seekg(0);



    DoubleLinkedList <string> test_dl_list;

    while (in.peek() != EOF) {
        string sub;
        in >> sub;

        if (!test_dl_list.isExist(sub) )
                test_dl_list.InsertLeft(1, sub);
    }

    out << "_____DoubleLinkedList_____" << endl;
    test_dl_list.PrintLeftToRight(out);
    out << endl;



    in.close();
    out.close();

    return 0;
}
