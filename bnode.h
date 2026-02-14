/***********************************************************************
 * Header:
 *    BINARY NODE
 * Summary:
 *    One node in a binary tree (and the functions to support them).
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *
 *    This will contain the class definition of:
 *        BNode         : A class representing a BNode
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    Michael, James, Brayden
 ************************************************************************/



#pragma once

#include <cassert>
#include <cstddef>  // size_t
#include <utility>  // std::move, std::swap

/*****************************************************************
 * BNODE
 *****************************************************************/
template <class T>
class BNode
{
public:
    // Construct
    BNode() : pLeft(nullptr), pRight(nullptr), pParent(nullptr), data() {}
    BNode(const T& t) : pLeft(nullptr), pRight(nullptr), pParent(nullptr), data(t) {}
    BNode(T&& t) : pLeft(nullptr), pRight(nullptr), pParent(nullptr), data(std::move(t)) {}

    // Data
    BNode<T>* pLeft;
    BNode<T>* pRight;
    BNode<T>* pParent;
    T data;
};

/*******************************************************************
 * SIZE BTREE
 *******************************************************************/
template <class T>
inline size_t size(const BNode<T>* p)
{
    // Recursively travel through every node

    // Stop when the current node doesn't exist
    if (!p)
      return 0;
    // Add 1 plus whatever is on the left and right sides
    else
       return (size(p->pLeft) + 1 + size(p->pRight));
}

/******************************************************
 * ADD LEFT (tree)
 ******************************************************/
template <class T>
inline void addLeft(BNode<T>* pNode, BNode<T>* pAdd)
{
    assert(pNode != nullptr);
    assert(pAdd != nullptr);
    assert(pNode->pLeft == nullptr);   // prevent accidental overwrite/leak
 
    // Link child upward to its parent
    pAdd->pParent = pNode;
    // Link parent downward to its (left) child
    pNode->pLeft = pAdd;
}

/******************************************************
 * ADD RIGHT (tree)
 ******************************************************/
template <class T>
inline void addRight(BNode<T>* pNode, BNode<T>* pAdd)
{
    assert(pNode != nullptr);
    assert(pAdd != nullptr);
    assert(pNode->pRight == nullptr);
    
    // Link child upward to its parent
    pAdd->pParent = pNode;
    // Link parent downward to its (right) child
    pNode->pRight = pAdd;
}

/******************************************************
 * ADD LEFT (value)
 ******************************************************/
template <class T>
inline void addLeft(BNode<T>* pNode, const T& t)
{
    // Make a new pointer for the new node
    BNode<T>* pAdd = new BNode<T>(t);
    addLeft(pNode, pAdd);
}

template <class T>
inline void addLeft(BNode<T>* pNode, T&& t)
{
    // Make a new pointer for the new node (with move constructor)
    BNode<T>* pAdd = new BNode<T>(std::move(t));
    addLeft(pNode, pAdd);
}

/******************************************************
 * ADD RIGHT (value)
 ******************************************************/
template <class T>
inline void addRight(BNode<T>* pNode, const T& t)
{
    // Make a new pointer for the new node
    BNode<T>* pAdd = new BNode<T>(t);
    addRight(pNode, pAdd);
}

template <class T>
inline void addRight(BNode<T>* pNode, T&& t)
{
    // Make a new pointer for the new node (with move constructor)
    BNode<T>* pAdd = new BNode<T>(std::move(t));
    addRight(pNode, pAdd);
}

/*****************************************************
 * CLEAR (post-order LRV)
 ****************************************************/
template <class T>
inline void clear(BNode<T>*& pThis)
{
    if (pThis == nullptr)
        return;

    clear(pThis->pLeft);
    clear(pThis->pRight);

    delete pThis;
    pThis = nullptr;
}

/***********************************************
 * SWAP
 **********************************************/
template <class T>
inline void swap(BNode<T>*& pLHS, BNode<T>*& pRHS)
{
    std::swap(pLHS, pRHS);
}

/**********************************************
 * COPY (deep copy, fix parent pointers)
 *********************************************/
template <class T>
inline BNode<T>* copy(const BNode<T>* pSrc)
{
    if (pSrc == nullptr)
        return nullptr;

    BNode<T>* pNew = new BNode<T>(pSrc->data);

    pNew->pLeft = copy(pSrc->pLeft);
    if (pNew->pLeft)
        pNew->pLeft->pParent = pNew;

    pNew->pRight = copy(pSrc->pRight);
    if (pNew->pRight)
        pNew->pRight->pParent = pNew;

    // root's parent is nullptr by constructor
    return pNew;
}

template <class T>
inline void assign(BNode<T>*& pDest, const BNode<T>* pSrc, BNode<T>* pParent = nullptr)
{
    if (pSrc == nullptr)
    {
        clear(pDest);
        return;
    }

    // create or update this node
    if (pDest == nullptr)
        pDest = new BNode<T>(pSrc->data);
    else
        pDest->data = pSrc->data;

    pDest->pParent = pParent;

    // recurse into children
    assign(pDest->pLeft, pSrc->pLeft, pDest);
    assign(pDest->pRight, pSrc->pRight, pDest);
}

