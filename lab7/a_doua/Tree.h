#include<iostream>
template <typename T>
int compara(T firstValue, T secondValue)
{
	if (firstValue < secondValue)
		return -1;
	else
		if (firstValue > secondValue)
			return 1;
		else
			return 0;
}

template <typename T>
struct Node
{
	T value;
	Node<T>** children;
	Node<T>* father;
	unsigned int nrChildren;
};

template <class T>
class Tree
{
public:
	Node<T>* root;
	unsigned int maxnrChildren;
public:
	Tree(unsigned int nrChildren)
	{
		this->maxnrChildren = nrChildren;
		root = nullptr;
	}

	void add_node(Node<T>* parent, T value)
	{
		if (parent == nullptr)
		{
			root = new Node<T>;
			root->value = value;
			root->nrChildren = 0;
			root->children = new Node<T> *[maxnrChildren] {};
			root->father = nullptr;
		}
		else
		{
			parent->children[parent->nrChildren] = new Node<T>;
			parent->children[parent->nrChildren]->value = value;
			parent->children[parent->nrChildren]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<T>*[maxnrChildren] {};
			parent->children[parent->nrChildren]->father = parent;
			parent->nrChildren++;
		}
	}

	Node<T>& get_node(Node<T>* parent, T value)
	{
		if (parent == nullptr)
			return *root;
		unsigned int i;
		for (i = 0; i < parent->nrChildren; i++)
			if (parent->children[i]->value == value)
				return *(parent->children[i]);
		Node<T> *null= nullptr;
		return *null;
	}

	void delete_node(Node<T>* nod)
	{
		unsigned int i,j;
		for (i = 0; i < nod->nrChildren; i++)
			delete_node(nod->children[i]);
		for (i = 0; i < nod->father->nrChildren; i++)
			if (nod->father->children[i]->value == nod->value)
			{	j = i; 
				break;
			}
		for (i = j; i < nod->father->nrChildren - 1; i++)
			nod->father->children[i] = nod->father->children[i + 1];
		nod->father->nrChildren--;
		nod->value = NULL;
		delete[] nod->children;
		nod->children = nullptr;
		nod->nrChildren = NULL;
		nod = nullptr;
	}

	Node<T>& find(Node<T>* r, T val, int (*compara)(T, T))
	{
		if (compara(val, r->value) == 0)
			return *r;
		Node<T>* n = nullptr;
		for (unsigned int i = 0; i < r->nrChildren; i++)
		{
			n = &find(r->children[i], val, compara);
			if (n != nullptr)
				break;
		}
		return *n;
	}

	void insert(Node<T>* parent, int index, T value)
	{
		unsigned int i;
		Node<T>* nou = new Node<T>;
		nou->value = value;
		nou->children= new Node<T>*[maxnrChildren] {};
		nou->nrChildren = 0;
		parent->children[parent->nrChildren] = new Node<T>;
		parent->nrChildren++;
		for (i = parent->nrChildren - 1; i > index; i--)
			parent->children[i] = parent->children[i - 1];
		parent->children[index] = nou;
	}

	void sort(Node<T>* parent, int (*compara)(T, T))
	{
		unsigned int i, j;
		if (compara == nullptr)
		{
			for (i = 0; i < parent->nrChildren; i++)
				for (j = i + 1; j < parent->nrChildren; j++)
					if (parent->children[i]->value < parent->children[j]->value)
					{
						Node<T>* aux;
						aux = parent->children[i];
						parent->children[i] = parent->children[j];
						parent->children[j] = aux;
					}
		}
		else
		{
			for (i = 0; i < parent->nrChildren; i++)
				for (j = i + 1; j < parent->nrChildren; j++)
					if (compara(parent->children[i]->value, parent->children[j]->value) > 0)
					{
						Node<T>* aux;
						aux = parent->children[i];
						parent->children[i] = parent->children[j];
						parent->children[j] = aux;
					}
		}
	}

	unsigned int count(Node<T>* r)
	{
		if (r == nullptr)
			return count(root);
		unsigned int i,k=0;
		for (i = 0; i < r->nrChildren; i++)
			k=k+1+count(r->children[i]);
		return k;
	}

	void printChildren(Node<T>*parent)
		{
			unsigned int i;
			for (i = 0; i < parent->nrChildren; i++)
				std::cout << parent->children[i]->value << ' ';
			std::cout << '\n';
		}
	};