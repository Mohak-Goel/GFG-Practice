#include <iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename E>
class SLinkedList;
template <typename E>
class SNode
{
  private:
    E element;
    int position;
    SNode<E>* next;
    friend class SLinkedList<E>;
};
template <typename E>
class SLinkedList{
  public:
    SLinkedList();
    ~SLinkedList();
    bool isEmpty() const;
    const E& front() const;
    void addFront(const E& e);
    void add(int position, const E& e);
    void removeFront();
    void remove(int position);
    void traverse();
  private:
    SNode<E>* head;
};
int main() {
  char ch; int mch; int element;
  SLinkedList<int> Node;
  while(true)
  {
    cout<<"1. Addition of new element from front."<<endl;
    cout<<"2. Addition of new element at position n."<<endl;
    cout<<"3. Remove the first element."<<endl;
    cout<<"4. Remove the nth element." <<endl;
    cout<<"5. Traverse/Display List." <<endl;
    cout<<"6. Get the First element of the List." <<endl;
    cout<<"7. Exit."<<endl;
    cout<<"Enter Your Choice : ";
    cin>>mch;
    if(mch==1)
    {
      while (true) {
        cout<<"Enter Y for yes & N for No to enter element to the List.(Y/N) : ";
        cin>>ch;
        if(ch=='Y')
        {
          std::cout << "Enter the element : ";
          std::cin >> element;
          Node.addFront(element);
        }
        else if(ch=='N')
        {
          std::cout << "THANK YOU!! :-)" << '\n';
          break;
        }

        else
        {
          std::cout << "Enter a Valid Input!! :-(" << '\n';
          continue;
        }
      }
    }
    else if(mch==2)
    {
      while (true) {
        cout<<"Enter Y for yes & N for No to enter element to the List.(Y/N) : ";
        cin>>ch;
        if(ch=='Y')
        {
          std::cout << "Enter the position of element : ";
          int position;
          cin>>position;
          std::cout << "Enter the element : ";
          std::cin >> element;
          Node.add(position,element);
        }
        else if(ch=='N')
        {
          std::cout << "THANK YOU!! :-)" << '\n';
          break;
        }

        else
        {
          std::cout << "Enter a Valid Input!! :-(" << '\n';
          continue;
        }
      }
    }
    else if(mch==3)
    {
      Node.removeFront();
      std::cout << "THANK YOU!! :-)" << '\n';
    }
    else if(mch==4)
    {
      std::cout << "Enter the position of element : ";
      int position;
      cin >> position;
      Node.remove(position);
      std::cout << "THANK YOU!! :-)" << '\n';
    }
    else if(mch==5)
    {
      std::cout << "Elements in the List are :- " << '\n'<<"\t";
      Node.traverse();
    }
    else if(mch==6)
      std::cout << "Front Element : " << Node.front() <<'\n';
    else if (mch==7)
      break;

    else
    {
      std::cout << "Enter a Valid Input!! :-(" << '\n';
      continue;
    }
  }
  return 0;
}
template <typename E>
SLinkedList<E>::SLinkedList()
{
  head = new SNode<E>;
  head->next = NULL;
  head->position = 0;
}
template <typename E>
bool SLinkedList<E>::isEmpty() const
{
  if(head->next==NULL)
    return true;
  return false;
}
template <typename E>
const E& SLinkedList<E>::front() const
{
  return head->next->element;
}
template <typename E>
void SLinkedList<E>::add(int pos, const E& e)
{
  SNode<E>* temp = head;
  while(temp->position < pos-1)
    temp = temp->next;
  SNode<E>* newNode = new SNode<E>;
  newNode->element = e;
  newNode->next = temp->next;
  temp->next = newNode;
  newNode->position = temp->position + 1;
}
template <typename E>
void SLinkedList<E>::addFront(const E& e)
{
  add(1, e);
}
template <typename E>
void SLinkedList<E>::remove(int position)
{
  SNode<E>* temp1 = head;
  while(temp1->position < position-1)
    temp1 = temp1->next;
  SNode<E>* temp2 = temp1->next;
  temp1->next = temp2->next;
  delete[] temp2;
}
template <typename E>
void SLinkedList<E>::removeFront()
{
  remove(1);
}
template <typename E>
void SLinkedList<E>::traverse()
{
  SNode<E>* temp = head->next;
  while(temp!=NULL)
  {
    cout << temp->element << "\t";
    temp = temp->next;
  }
  std::cout << '\n';
}
template <typename E>
SLinkedList<E>::~SLinkedList()
{
  while (!isEmpty())
    removeFront();
  delete[] head;
}
