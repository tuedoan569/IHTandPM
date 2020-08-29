/**
 Author       : Dr. Daniel Spiegel
 Update by    : Tue Doan
 Date         : March 1, 2019
 File         : LinkedList.h
 Purpose      : Circular Linked List with node and list Iterator class
 */

#ifndef _LinkedList_
#define _LinkedList_
#include <assert.h>
#include <iostream>

using namespace std;

// Need to prototype template classes if they are to be friends
template <typename eltType> class LinkedList;
template <typename eltType> class listItr;

/**
 * implement node, which link and hold data for each node in Circular Linked List
 */
template <typename eltType> class node
{  private:
  node(eltType info, node* link = NULL ) :
  data(info), next(link) {};
  eltType data;
  node*  next;
  friend class LinkedList<eltType>;
  friend class listItr<eltType>;
};

/**
 * Circular Linked List, nodes connect in circular pattern
 */
template <typename eltType> class LinkedList
{
public:
  /**
   Function name: LinkedList \n
   Description  : Constructor - construct an empty Circular Linked List \n
   Member type  : Mutator \n
   Parameters   : None \n
   Return value : None \n
   */
  LinkedList();
  
  /**
   Function name: LinkedList \n
   Description  : Copy Constructor - deep copy of another Circular Linked List \n
   Member type  : Mutator \n
   Parameters   : LinkedList &clist - list being copied from - input \n
   Return value : None \n
   */
  LinkedList(LinkedList &clist);
  
  /**
   Function name: LinkedList \n
   Description  : Destructor - destroy Circular Linked List \n
   Member type  : Mutator \n
   Parameters   : None \n
   Return value : None \n
   */
  ~LinkedList();
  
  /**
   Function name: operator= \n
   Description  : Assign another LinkedList to this LinkedList (deep copy) \n
   Member type  : Mutator \n
   Parameters   : const LinkedList &clist - list being assigned from - input \n
   Return value : *this - LinkedList \n
   */
  LinkedList& operator=(const LinkedList &clist);
  
  
  /**
   Function name: empty \n
   Description  : is the LinkedList empty? \n
   Member type  : Facilitator \n
   Parameters   : None \n
   Return value : bool - true of the list empty, otherwise false \n
   */
  bool empty();
  
  /**
   Function name: find \n
   Description  : is the element in the list? \n
   Member type  : Facilitator \n
   Parameters   : eltType elt - find this element in the list \n
   Return value : bool - true if found, otherwise false \n
   */
  bool find(eltType elt);
  
  /**
   Function name: insert \n
   Description  : Insert element into the Circular Linked List - ordered \n
   Member type  : Mutator \n
   Parameters   : eltype elt - element being inserted - input\n
   Return value : None \n
   */
  eltType *insert(eltType elt);
  
  /**
   Function name: insert \n
   Description  : Remove element into the Circular Linked List \n
   Member type  : Mutator \n
   Parameters   : eltype elt - element being removed - input\n
   Return value : bool - true if the element removed, otherwise false \n
   */
  bool remove(eltType elt);
  
private:
  
  // linked list pointer
  node<eltType>*  last;
  
  // Get a copy of a (deep) node
  node<eltType>*  copy(node<eltType> *);
  
  void helpCopy(node<eltType> *nod, node<eltType> *nodePtr, node<eltType> *first);
  
  // Free nodes of a linked list
  /**
   Function name: destroy \n
   Description  : Remove all nodes in the Circular Linked List \n
   Member type  : Mutator \n
   Parameters   : node<eltype> * nodePtr - pointer of a node in the list - input\n
   Return value : None \n
   */
  void  destroy(node<eltType> *);
  
  
  // Needed to use a list iterator
  friend class listItr<eltType>;
};

/**
 * Set up an iterator for the Circular Linked List,
 * an object that provides a pointer to a linked list
 */
template <typename eltType> class listItr {
  
public:
  // Construc a List Iterator
  /**
   Function name: listItr \n
   Description  : Contruct a list iterator from a Circular Linked List \n
   Member type  : Mutator \n
   Parameters   : LinkedList<eltType> &list - a Circular List - input\n
   Return value : None \n
   */
  listItr(LinkedList<eltType> &list);
  
  /**
   Function name: listItr \n
   Description  : Contruct a list iterator from a constant Circular Linked List \n
   Member type  : Mutator \n
   Parameters   : const LinkedList<eltType> &list - a Circular List - input\n
   Return value : None \n
   */
  listItr(const LinkedList<eltType> &list);
  
  /**
   Function name: begin \n
   Description  : Set curr to point at the first node of itr \n
   Member type  : Mutator \n
   Parameters   : None \n
   Return value : None \n
   */
  void begin();
  
  /**
   Function name: isEmpty \n
   Description  : Is curr equal to NULL (empty)? \n
   Member type  : Facilitator \n
   Parameters   : None \n
   Return value : bool - true if curr is NULL, otherwise false \n
   */
  bool isEmpty();
  
  /**
   Function name: isFirstNode \n
   Description  : Is curr the first node? \n
   Member type  : Facilitator \n
   Parameters   : None \n
   Return value : bool - true if curr is the first node, otherwise false \n
   */
  bool isFirstNode();
  
  /**
   Function name: isLastNode \n
   Description  : Is curr the last node? \n
   Member type  : Facilitator \n
   Parameters   : None \n
   Return value : bool - true if curr is the last node, otherwise false \n
   */
  bool isLastNode();
  
  /**
   Function name: operator* \n
   Description  : Return the data of the node currently pointed at \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : eltType - the data value \n
   */
  eltType operator*();
  
  /**
   Function name: operator* \n
   Description  : Return the data of the node currently pointed at \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : eltType - the data value \n
   */
  const eltType operator*() const;
  
  /**
   Function name: operator++ \n
   Description  : Pre-Increment - Advance the pointer to the next node in the list \n
   Member type  : Mutator \n
   Parameters   : None \n
   Return value : listItr<eltType> - the list iterator \n
   */
  listItr<eltType> & operator++();
  
  /**
   Function name: operator++ \n
   Description  : Post-Increment - Advance the pointer to the next node in the list \n
   Member type  : Mutator \n
   Parameters   : None \n
   Return value : listItr<eltType> - the list iterator \n
   */
  listItr<eltType> operator++(int);
  
private:
  const LinkedList<eltType> &itr;
  node<eltType> *curr;
};

// Construct empty LinkedList
template <typename eltType> LinkedList<eltType>::LinkedList() : last(NULL)
{}

// Copy constructor. copy() does the deep copy
template <typename eltType>
LinkedList<eltType>::LinkedList(LinkedList<eltType> &clist)
{last = copy( clist.last );}

// Free all nodes
template <typename eltType> LinkedList<eltType>::~LinkedList()
{destroy(last);}

// Assignment operator: copy() does the deep copy
template <typename eltType> LinkedList<eltType>
&LinkedList<eltType>::operator =(const LinkedList<eltType>& clist)
{  if (this != &clist)
{  destroy(last);
  last = copy(clist.last);
}
  return *this;
}

// Place x into the list in order
template <typename eltType>
eltType *LinkedList<eltType>::insert(eltType x) {
  eltType *ptr;
  if (empty()) {
    last=new node<eltType>(x,last);
    last->next = last;
    return NULL;
  } else if (last->data < x) {
    if (last->data == x) {
      ptr = &last->data;
      return ptr;
    } else {
      last->next = new node<eltType>(x, last->next);
      last = last->next;
    }
  } else if (x < last->next->data) {
    if (last->next->data == x) {
      ptr = &last->next->data;
      return ptr;
    } else {
       last->next = new node<eltType>(x, last->next);
    }
  } else {
    node<eltType>*  p  = last -> next; // last;
    node<eltType>*  trailp  = last;         // NULL;
    while (p != NULL && x > p->data) {
      trailp = p;
      p = p->next;
    }
    if (p->data == x) {
      ptr = &p->data;
      return ptr;
    } else {
      trailp->next = new node<eltType>(x, p);
    }
    
  }
}
// Inline: Look into this.
template <typename eltType> inline bool LinkedList<eltType>::empty()
{return (last == NULL);}

// Is this element in the linked list?
template <typename eltType> bool LinkedList<eltType>::find(eltType elt) {
  node<eltType> *ptr = NULL;
  if (!empty()) {
    ptr = last->next;
    while (ptr != last && ptr->data != elt) {
      ptr = ptr->next;
    }
  }
  return (ptr != NULL && ptr->data == elt);
}

// Remove a node in an ordered list
// Pre: Node will be found
template <typename eltType> bool LinkedList<eltType>::remove(eltType elt) {
  bool remove = false;
  node<eltType> *ptr = NULL;
  node<eltType> *trailPtr = NULL;
  if (find(elt)) {
    ptr = last->next;
    while (ptr->data != elt) {
      trailPtr = ptr;
      ptr = ptr->next;
    }
    
    if (trailPtr == NULL && ptr->next == last->next) { // only 1 node in the list
      last = NULL;
    } else if (ptr == last) {         // last node in the list
      trailPtr->next = last->next;
      last = trailPtr;
    } else if(ptr == last->next) {    // first node in the list
      last->next = last->next->next;
    } else {
      trailPtr->next = ptr->next;
    }
    delete ptr;
    remove = true;
  }
  return remove;
}

// Remove all nodes in the linked list
template <typename eltType> void LinkedList<eltType>::destroy(node<eltType> *nodePtr)
{
  if (nodePtr != last) {
    node<eltType> *doomed = nodePtr;
    destroy(nodePtr->next);
    delete doomed;
  }
}

// The deep copy. Copy the source list l, one node at a time
template <typename eltType>
node<eltType>* LinkedList<eltType>::copy(node<eltType> *list) {
  /*
  node<eltType> *first = NULL;
  node<eltType> *lastt = NULL;
  node<eltType> *source = list->next;
  if (!empty()) {
    first = lastt = new node<eltType> (source->data, NULL);
    helpCopy(source, lastt, list);
  }
  lastt->next = first;
  return lastt;*/
  
  node<eltType> *last = NULL;  // ptr to last item of copied LinkedList
  node<eltType>* follow = NULL;  // ptr to second last item in the copy
  
  if (list != NULL) {
    assert((last=follow=new node<eltType>(list->data,NULL)) != NULL);
    for (node<eltType>* source = list->next ;source !=list ;source = source->next,follow = follow->next)
    {  follow->next = new node<eltType>(source->data,NULL);
      assert(follow->next);
    }
    follow->next = last;
  }
  return last;
}

template <typename eltType>
void LinkedList<eltType>::helpCopy(node<eltType> *source, node<eltType> *nodePtr, node<eltType> *list) {
  if (source != list) {
    helpCopy(source->next, nodePtr->next, list);
    nodePtr = new node<eltType>(source->data, NULL);
  }
}

template <typename eltType>
listItr<eltType>::listItr(LinkedList<eltType> &list): itr(list), curr(list.last)
{}

template <typename eltType>
listItr<eltType>::listItr(const LinkedList<eltType> &list): itr(list),curr(list.last)
{}

template <typename eltType> void listItr<eltType>::begin() {
  curr = itr.last->next;
}

template <typename eltType> bool listItr<eltType>::isEmpty() {
  return (curr == NULL);
}

template <typename eltType> bool listItr<eltType>::isFirstNode() {
  return (curr == itr.last->next);
}

template <typename eltType> bool listItr<eltType>::isLastNode() {
  return curr == itr.last;
}

template <typename eltType> eltType listItr<eltType>::operator*() {
  return curr->data;
}

template <typename eltType> const eltType listItr<eltType>::operator*() const {
  return curr->data;
}

template <typename eltType> listItr<eltType> & listItr<eltType>::operator++() {
  curr = curr->next;
  return *this;
}

template <typename eltType> listItr<eltType> listItr<eltType>::operator++(int) {
  listItr<eltType> temp = itr;
  curr = curr->next;
  return temp;
}


#endif
