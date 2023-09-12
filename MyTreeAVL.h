#pragma once
#include "MyTree.h"

template <class T> class MyTreeAVL : public MyTree<T> {
public:
	MyTreeAVL() : MyTree<T>() {};
	MyTreeAVL(MyTree<T>& mytree) : MyTree<T>(mytree) {};
	void add(int key, T value, typename MyTree<T>::Node* r);
	void deleteNodeByKey(int key, typename MyTree<T>::Node* r);
	void R(typename MyTree<T>::Node* r);
	void L(typename MyTree<T>::Node* r);
	void LR(typename MyTree<T>::Node* r);
	void RL(typename MyTree<T>::Node* r);
	void getParent(typename MyTree<T>::Node* &a, typename MyTree<T>::Node* b, typename MyTree<T>::Node* r);
	void getNodeByKey(int key, typename MyTree<T>::Node* &n, typename MyTree<T>::Node* r);
	void toBalance(typename MyTree<T>::Node* r);
	int getBal(typename MyTree<T>::Node* r);
};


template <class T> void MyTreeAVL<T>::add(int key, T value, typename MyTree<T>::Node* r) {
	MyTree<T>::add(key, value, r);
	typename MyTree<T>::Node* n = NULL;
	getNodeByKey(key, n, MyTree<T>::root);
	toBalance(n);
}

template <class T> void MyTreeAVL<T>::deleteNodeByKey(int key, typename MyTree<T>::Node* r) {
	typename MyTree<T>::Node* parent = NULL;
	getParent(parent, r, MyTree<T>::root);
	MyTree<T>::deleteNodeByKey(key, r);
	if (parent == NULL) {
		toBalance(MyTree<T>::root);
	}
	else {
		if (getBal(parent->left) > 1 or getBal(parent->left) < -1) {
			toBalance(parent->left);
		}
		else if (getBal(parent->right) > 1 or getBal(parent->right) < -1) {
			toBalance(parent->right);
		}
	}
}

template <class T> void MyTreeAVL<T>::R(typename MyTree<T>::Node* r) {
	typename MyTree<T>::Node* l = r->left;
	typename MyTree<T>::Node* parent = NULL;
	getParent(parent, r, MyTree<T>::root);
	bool checkParent = false;
	if (parent == NULL) {
		checkParent = true;
	}
	if (r == MyTree<T>::root) {
		MyTree<T>::root = l;
	}
	r->left = l->right;
	l->right = r;
	if (!checkParent) {
		if (parent->key < l->key) {
			parent->right = l;
		}
		else {
			parent->left = l;
		}
	}
}

template <class T> void MyTreeAVL<T>::L(typename MyTree<T>::Node* r) {
	typename MyTree<T>::Node* l = r->right;
	typename MyTree<T>::Node* parent = NULL;
	getParent(parent, r, MyTree<T>::root);
	bool checkParent = false;
	if (parent == NULL) {
		checkParent = true;
	}
	if (r == MyTree<T>::root) {
		MyTree<T>::root = l;
	}
	r->right = l->left;
	l->left = r;
	if (!checkParent) {
		if (parent->key < l->key) {
			parent->right = l;
		}
		else {
			parent->left = l;
		}
	}
}

template <class T> void MyTreeAVL<T>::LR(typename MyTree<T>::Node* r) {
	L(r->left);
	R(r);
}

template <class T> void MyTreeAVL<T>::RL(typename MyTree<T>::Node* r) {
	R(r->right);
	L(r);
}

template <class T> void MyTreeAVL<T>::toBalance(typename MyTree<T>::Node* r) {
	if (r == NULL) {
		return;
	}
	MyTree<T>::iterations++;
	int bal = getBal(r);
	typename MyTree<T>::Node* parent = NULL;
	getParent(parent, r, MyTree<T>::root);
	if (bal <= 1 and bal >= -1) {

	}
	else {
		if (bal > 0) {
			int bal2 = getBal(r->right);
			if (bal2 > 0) {
				L(r);
			}
			else {
				RL(r);
			}
		}
		else {
			int bal2 = getBal(r->left);
			if (bal2 < 0) {
				R(r);
			}
			else {
				LR(r);
			}
		}
	}

	toBalance(parent);

}

template <class T> void MyTreeAVL<T>::getParent(typename MyTree<T>::Node* &parent,typename MyTree<T>::Node* child, typename MyTree<T>::Node* r) {
	if (r == NULL) {
		return;
	}
	getParent(parent, child, r->left);
	getParent(parent, child, r->right);
	if (r->left == child or r->right == child) {
		parent = r;
		return;
	}
	return;
}

template <class T> void MyTreeAVL<T>::getNodeByKey(int key, typename MyTree<T>::Node* &n, typename MyTree<T>::Node* r) {
	if (r == NULL) {
		return;
	}
	getNodeByKey(key, n, r->left);
	getNodeByKey(key, n, r->right);
	if (r->key == key) {
		n = r;
		return;
	}
	return;
}

template <class T> int MyTreeAVL<T>::getBal(typename MyTree<T>::Node* r) {
	int h1 = MyTree<T>::getHeight(0, r->left);
	int h2 = MyTree<T>::getHeight(0, r->right);
	return h2 - h1;
}