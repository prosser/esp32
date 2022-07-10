#ifndef LinkedList_hpp
#define LinkedList_hpp

// copied from https://stackoverflow.com/questions/9986591/vectors-in-arduino

template <class T>
class ListNode
{
public:
  T element;
  ListNode *next;
  ListNode *prev;

  ListNode(T element, ListNode *prev, ListNode *next) : element(element)
  {
    this->next = next;
    this->prev = prev;
  };
};

template <class T>
class LinkedList
{
private:
  int length;
  ListNode<T> *head;
  ListNode<T> *tail;
  ListNode<T> *curr;

public:
  LinkedList();
  LinkedList(const LinkedList<T> &);
  ~LinkedList();
  T &getCurrent();
  T &first() const;
  T &last() const;
  int getLength();
  void append(T);
  void deleteLast();
  void deleteFirst();
  void deleteCurrent();
  bool next();
  bool moveToStart();
  bool prev();
  void remove(T &);
  void reverse();
  bool search(T);
  void clear();
  void putFirstToLast();
  void update(T elem);
  LinkedList &operator=(const LinkedList<T> &);
};

template <class T>
LinkedList<T>::LinkedList()
{
  length = 0;
  head = nullptr;
  tail = nullptr;
  curr = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
  length = 0;
  head = nullptr;
  tail = nullptr;
  curr = nullptr;

  ListNode<T> *temp = list.head;

  while (temp != nullptr)
  {
    append(temp->element);
    temp = temp->next;
  }
}

template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list)
{
  clear();

  ListNode<T> *temp = list.head;

  while (temp != nullptr)
  {
    append(temp->element);
    temp = temp->next;
  }

  return *this;
}

template <class T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template <class T>
T &LinkedList<T>::getCurrent()
{
  return curr->element;
}

template <class T>
T &LinkedList<T>::first() const
{
  return head->element;
}

template <class T>
T &LinkedList<T>::last() const
{
  return tail->element;
}

template <class T>
int LinkedList<T>::getLength()
{
  return length;
}

template <class T>
void LinkedList<T>::append(T element)
{
  ListNode<T> *node = new ListNode<T>(element, tail, nullptr);

  if (length == 0)
    curr = tail = head = node;
  else
  {
    tail->next = node;
    tail = node;
  }

  length++;
}

template <class T>
void LinkedList<T>::deleteLast()
{
  if (length == 0)
    return;
  curr = tail;
  deleteCurrent();
}

template <class T>
void LinkedList<T>::deleteFirst()
{
  if (length == 0)
    return;
  curr = head;
  deleteCurrent();
}

template <class T>
bool LinkedList<T>::next()
{
  if (length == 0)
    return false;

  if (curr->next == nullptr)
    return false;

  curr = curr->next;
  return true;
}

template <class T>
bool LinkedList<T>::moveToStart()
{
  curr = head;
  return length != 0;
}

template <class T>
bool LinkedList<T>::prev()
{
  if (length == 0)
    return false;

  if (curr->prev != nullptr)
    return false;

  curr = curr->prev;
  return true;
}

template <class T>
void LinkedList<T>::remove(T &elem)
{
  if (search(elem))
    deleteCurrent();
}

template <class T>
void LinkedList<T>::reverse()
{
  ListNode<T> *temp = nullptr;
  ListNode<T> *current = head;
  tail = head;

  while (current != nullptr)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }

  if (temp != nullptr)
  {
    head = temp->prev;
  }
}

template <class T>
void LinkedList<T>::deleteCurrent()
{
  if (length == 0)
    return;
  length--;
  ListNode<T> *temp = curr;

  if (temp->prev != nullptr)
    temp->prev->next = temp->next;
  if (temp->next != nullptr)
    temp->next->prev = temp->prev;

  if (length == 0)
    head = curr = tail = nullptr;
  else if (curr == head)
    curr = head = head->next;
  else if (curr == tail)
    curr = tail = tail->prev;
  else
    curr = curr->prev;

  delete temp;
}

template <class T>
bool LinkedList<T>::search(T elem)
{
  if (length == 0)
    return false;
  if (moveToStart())
    do
    {
      if (curr->element == elem)
        return true;
    } while (next());
  return false;
}

template <class T>
void LinkedList<T>::putFirstToLast()
{
  if (length < 2)
    return;
  ListNode<T> *temp = head->next;
  head->next->prev = nullptr;
  head->next = nullptr;
  head->prev = tail;
  tail->next = head;
  tail = head;
  head = temp;
}

template <class T>
void LinkedList<T>::update(T elem)
{
  if (search(elem))
    curr->element = elem;
}

template <class T>
void LinkedList<T>::clear()
{
  if (length == 0)
    return;
  ListNode<T> *temp = head;

  while (temp != nullptr)
  {
    head = head->next;
    delete temp;
    temp = head;
  }

  head = curr = tail = nullptr;

  length = 0;
}

#endif