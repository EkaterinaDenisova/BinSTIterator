#pragma once
// author: �������� ���������
// ����� ��������� ������ ������

#include <iostream>
#include "TreeNode.h"

template <typename T>
class BinSTree
{
private:
	// ��������� �� ������ � �� ������� ����
	TreeNode<T>* root;
	TreeNode<T>* current;

	// ����� ��������� ������ 
	int size;


public:
	// ����������� �� ���������
	BinSTree();

	// ����������� � ����������
	BinSTree(TreeNode<T>* tree);


	// ����������� �����������
	BinSTree(const BinSTree<T>& tree);

	// �������� ����������� (������������)
	BinSTree<T>& operator= (const BinSTree<T>& rhs);

	// ����������
	~BinSTree() { deleteTree(this->root); }


	// ����������� ������ ��������� �������

	// ���������� �������, �� ������� ��������� ������� ����
	// ���� -1, ���� ���� � ����� ��������� � ������ ���
	int Find(const T& item);
	void Insert(const T& item);
	void Delete(const T& item);
	void ClearList();

	// ��������, ������ �� ������
	bool ListEmpty() const;

	// ���������� ����� � ������
	int ListSize() const;

	TreeNode<T>* GetRoot();
};

// ����������� �� ���������
template <typename T>
BinSTree<T>::BinSTree()
{
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

// ����������� � �����������
template <typename T>
BinSTree<T>::BinSTree(TreeNode<T>* tree)
{
	this->root = CopyTree(tree);
	this->current = nullptr;
	this->size = treeCount(this->root);
}

// ����������� �����������
template <typename T>
BinSTree<T>::BinSTree(const BinSTree<T>& tree)
{
	this->root = CopyTree(tree.root);

	// ��������� �������� ��������� �������� ����� � ������ ������ ������
	this->current = this->root;
	this->size = tree.size;
}


// �������� ����������� (������������)
template <class T>
BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs)
{
	// ������ ���������� ������ � ���� ����
	if (this == &rhs)
		return *this;

	// �������� ������� ������
	ClearList();

	// ����������� ����� ������ � ������� ������
	this->root = CopyTree(rhs.root);

	// ��������� �������� ��������� �������� ����� � ������ ������ ������
	this->current = this->root;
	this->size = rhs.size;

	// ���������� ������ �� ������� ������
	return *this;
}

// ������� ������
template <typename T>
void BinSTree<T>::ClearList() {
	deleteTree(this->root);
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

//��������, ������ �� ������
template<class T>
bool BinSTree<T>::ListEmpty() const {
	return (this->root == nullptr);
}

// ���������� ����� � ������
template<class T>
int BinSTree<T>::ListSize() const {
	return this->size;
}


// ����� ����
// ���������� �������, �� ������� ��� ������ ����
// ���� -1, ���� ���� � ������� ��������� ���
template<class T>
int BinSTree<T>::Find(const T& item) {
	return SearchNode(this->root, item);
}

// ������� ����
template<class T>
void BinSTree<T>::Insert(const T& item) {
	this->root = InsertNode(this->root, item);
	size = treeCount(this->root);
}

// �������� ����
template<class T>
void BinSTree<T>::Delete(const T& item) {
	this->root = DeleteNode(this->root, item);
	size = treeCount(this->root);
}

// ���������� ��������� �� ������
template <typename T>
TreeNode<T>* BinSTree<T>::GetRoot()
{
	return this->root;
}

