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
    // ---------- Michael Code To Complete ----------
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
    // ---------- James Code To Complete ----------
    return 99;
}

/******************************************************
 * ADD LEFT (tree)
 ******************************************************/
template <class T>
inline void addLeft(BNode<T>* pNode, BNode<T>* pAdd)
{
    // ---------- Brayden Code To Complete ----------
    
}

/******************************************************
 * ADD RIGHT (tree)
 ******************************************************/
template <class T>
inline void addRight(BNode<T>* pNode, BNode<T>* pAdd)
{
    // ---------- Brayden Code To Complete ----------
    
}

/******************************************************
 * ADD LEFT (value)
 ******************************************************/
template <class T>
inline void addLeft(BNode<T>* pNode, const T& t)
{
    // ---------- Brayden Code To Complete ----------
    
}

template <class T>
inline void addLeft(BNode<T>* pNode, T&& t)
{
    // ---------- Brayden Code To Complete ----------
    
}

/******************************************************
 * ADD RIGHT (value)
 ******************************************************/
template <class T>
void addRight(BNode<T>* pNode, const T& t)
{
    // ---------- James Code To Complete ----------
    
    
}

template <class T>
void addRight(BNode<T>* pNode, T&& t)
{
    // ---------- James Code To Complete ----------
    
    
}

/*****************************************************
 * CLEAR (post-order LRV)
 ****************************************************/
template <class T>
void clear(BNode<T>*& pThis)
{
    // ---------- Michael Code To Complete ----------
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
    // ---------- Michael Code To Complete ----------
    std::swap(pLHS, pRHS);
    
}

/**********************************************
 * COPY (deep copy, fix parent pointers)
 *********************************************/
template <class T>
BNode<T>* copy(const BNode<T>* pSrc)
{
    // ---------- Michael Code To Complete ----------
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
void assign(BNode<T>*& pDest, const BNode<T>* pSrc, BNode<T>* pParent = nullptr)
{
    // ---------- Michael Code To Complete ----------
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

