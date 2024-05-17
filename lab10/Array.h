#include <exception>
#include <iostream>

using namespace std;

class exceptie1 : public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul se afla inafara intervalului!";
    }
}index_out_of_range;

class exceptie2 : public exception
{
    virtual const char* what() const throw()
    {
        return "Lista este plina!";
    }
}full_list;

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class MyCompare : Compare
{
public:
    int CompareElements(void* e1, void* e2)
    {
        T* a = static_cast<T*>(e1);
        T* b = static_cast<T*>(e2);
        if (*a > *b)
            return 1;
        if (*a == *b)
            return 0;
        return -1;
    }
};

template <class T>
int compare(const T& a, const T& b)
{
    if (a > b)
        return 1;
    if (a == b)
        return 0;
    return -1;
}

template<class T>
class ArrayIterator
{
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
    T* curr;
public:
    ArrayIterator()
    {
        Current = 0;
        curr = new T;
    }
    ArrayIterator& operator ++ ()
    {
        ++Current;
        return (*this);
    }
    ArrayIterator& operator -- ()
    {
        --Current;
        return (*this);
    }
    bool operator== (ArrayIterator<T>& it)
    {
        return (Current == it.Current && curr==it.curr);
    }
    bool operator!= (ArrayIterator<T>& it)
    {
        return (Current != it.Current && curr!=it.curr);
    }
    T* GetElement()
    {
        return curr;
    }
    void SetCurr(T* ceva)
    {
        curr = ceva;
    }
};

template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() // Lista nu e alocata, Capacity si Size = 0
    {
        Capacity = 0;
        Size = 0;
        List = nullptr;
    }
    ~Array() // destructor
    {
        Capacity = Size = 0;
        int i;
        for (i = 0; i < Capacity; i++)
        {
            delete List[i];
            List[i] = nullptr;
        }
        delete[] List;
        List = nullptr;
    }
    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        Capacity = capacity;
        Size = 0;
        List = new T * [Capacity];
        int i;
        for (i = 0; i < Capacity; i++)
            List[i] = new T;
    }
    Array(const Array<T>& otherArray) // constructor de copiere
    {
        int i;
        Capacity = otherArray.GetCapacity();
        Size = otherArray.GetSize();
        List = new T * [Capacity];
        for (i = 0; i < Capacity; i++)
            List[i] = new T;
        for (i = 0; i < Size; i++)
            *List[i] = otherArray[i];
    }

    T& operator[] (int index) const // arunca exceptie daca index este out of range
    {
        //exceptie1 index_out_of_range;
        try
        {
            if (index < 0 || index >= Size)
                throw index_out_of_range;
            else
                return *List[index];
        }
        catch (exception& e)
        {
            cout << "Exceptie la operatorul []: " << e.what() << '\n';
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        //exceptie2 full_list;
        try
        {
            if (Size == Capacity)
                throw full_list;
            else
            {
                *List[Size] = newElem;
                Size++;
                return (*this);
            }
        }
        catch (exception& e)
        {
            cout << "Exceptie la operatorul +=: " << e.what() << '\n';
        }
        return (*this);
    }
    const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        /*exceptie1 index_out_of_range;
        exceptie2 full_list;*/
        try
        {
            if (index < 0 || index >= Size)
                throw index_out_of_range;
            else
                if (Size == Capacity)
                    throw full_list;
                else
                {
                    int i;
                    Size++;
                    for (i = Size-1; i > index; i--)
                        *List[i] = *List[i - 1];
                    *List[index] = newElem;
                    return (*this);
                }
        }
        catch (exception& e)
        {
            cout << "Exceptie la inserare element: " << e.what() << '\n';
        }
        return (*this);
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        /*exceptie1 index_out_of_range;
        exceptie2 full_list;*/
        try
        {
            if (index < 0 || index >= Size)
                throw index_out_of_range;
            else
                if (Size + otherArray.GetSize() > Capacity)
                    throw full_list;
                else
                {
                    int i;
                    for (i = Size-1; i >=index; i--)
                        *List[i + otherArray.GetSize()] = *List[i];
                    for (i = index; i <= (index + otherArray.GetSize() - 1); i++)
                        *List[i] = otherArray[i - index];
                    Size += otherArray.GetSize();
                    return (*this);
                }
        }
        catch (exception& e)
        {
            cout << "Exceptie la inserare lista: " << e.what() << '\n';
        }
        return (*this);
    }
    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        //exceptie1 index_out_of_range;
        try
        {
            if (index < 0 || index >= Size)
                throw index_out_of_range;
            else
            {
                int i;
                for (i = index; i < Size - 1; i++)
                    List[i] = List[i + 1];
                delete List[Size-1];
                Size--;
                return (*this);
            }
        }
        catch (exception& e)
        {
            cout << "Exceptie la stergere element: " << e.what() << '\n';
        }
        return (*this);
    }

    bool operator==(const Array<T>& otherArray)
    {
        int i;
        if (Size != otherArray.GetSize())
            return false;
        for (i = 0; i < Size; i++)
            if (*List[i] != otherArray[i])
                return false;
        return true;
    }

    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        int i, j;
        for (i = 0; i < Size - 1; i++)
            for (j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                    swap(List[i], List[j]);
    }
    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        int i, j;
        for (i = 0; i < Size - 1; i++)
            for (j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]) > 0)
                    swap(List[i], List[j]);
    }
    void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
    {
        int i, j;
        for (i = 0; i < Size - 1; i++)
            for (j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                    swap(List[i], List[j]);
    }

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        Sort();
        int st = 0, dr = Size , m;
        while (st <= dr)
        {
            m = (st + dr) / 2;
            if (*List[m] == elem)
                return m;
            else
                if (*List[m] > elem)
                    dr = m - 1;
                else
                    st = m + 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        Sort(compare);
        int st = 0, dr = Size - 1, m;
        while (st<= dr)
        {
            m = (st + dr) / 2;
            if (compare(*List[m], elem) == 0)
                return m;
            else
            {
                if (compare(*List[m], elem) > 0)
                    dr = m - 1;
                else
                    st = m + 1;
            }
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        Sort(comparator);
        int st = 0, dr = Size - 1, m;
        while (st<= dr)
        {
            m = (st + dr) / 2;
            if (comparator->CompareElements(List[m], (void*)elem) == 0)
                return m;
            else
                if (comparator->CompareElements(List[m], (void*)elem) > 0)
                    dr = m - 1;
                else
                    st = m + 1;
        }
        return -1;
    }

    int Find(const T& elem) // cauta un element in Array
    {
        int i;
        for (i = 0; i < Size; i++)
            if (List[i] == elem)
                return i;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        int i;
        for (i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0)
                return i;
        return -1;
    }
    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
    {
        int i;
        for (i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], elem) == 0)
                return i;
        return -1;
    }

    int GetSize() const
    {
        return Size;
    }
    int GetCapacity() const
    {
        return Capacity;
    }

    ArrayIterator<T>& GetBeginIterator()
    {
        ArrayIterator<T> it;
        it.SetCurr(List[0]);
        return it;
    }
    ArrayIterator<T>& GetEndIterator()
    {
        ArrayIterator<T> it;
        it.SetCurr(List[Size]);
        return it;
    }
    void Print()
    {
        for (int i = 0; i <Size; i++)
            cout << *List[i] << ' ';
        cout << '\n';
    }
};
