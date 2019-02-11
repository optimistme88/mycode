#include <iostream>
#include <memory>

using namespace std;

struct linked_node {
    int val;
    linked_node *next;

    linked_node(int value) : val (value), next(nullptr) {}
    linked_node() : next(nullptr) {}
};

class linked_list {
     public:
     linked_list() : head (nullptr), _size(0) {}

     // insert the node at the head of the list
     void insert(linked_node *node)
     {
         node->next = head;
         head = node;
         ++_size;
     }

     // finds node containing given value val, if val is found it returns the pointer
     // to node else it returns nullptr.
     linked_node *find(int val)
     {
         linked_node *tmp = head;
         while (tmp && tmp->val != val)
         {
             tmp = tmp->next;
         }

         return tmp;
     }

     bool remove(int val)
     {
         linked_node *node = find(val);
         return remove(node);
     }
     
     bool remove(linked_node *node)
     {
         if (node == nullptr)
         {
             return false;
         }

         linked_node *cur = head;
         if (node == head)
         {
             head = head->next;
             --_size;
             delete node;
         }
         else
         {
             while (cur && cur->next != node)
             {
                 cur = cur->next;
             }

             if (cur == nullptr)
             {
                 return false;
             }

             cur->next = cur->next->next;
             --_size;
             // should we free input node
             delete node;
         }
         return true;
     }

     void print()
     {
         cout << "linked list nodes are:" << endl;
         linked_node *node = head;
         while (node)
         {
              cout << node-> val << ", ";
              node = node->next;
         }
         cout << endl;
     }

     int size()
     {
         return _size;
     }

     private:
	linked_node *head;
        int _size;
};

int main()
{
     linked_list ll;
     linked_node *n = new linked_node(2);
     ll.insert(n);
     n = new linked_node(3);
     ll.insert(n);
     ll.print();    
     cout << ll.size() << endl;

     int val;
     cout << "input from keyboarad: ";
     while (cin >> val)
     {
         n = new linked_node(val);
         ll.insert(n);
     }

     // remove element 3
     ll.remove(3);
     ll.remove(2);
     ll.print();    
     cout << ll.size() << endl;
}