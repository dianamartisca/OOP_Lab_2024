class Sort
{
    int n;
    int *v;
public:
    Sort(int nr, int min, int max);
    Sort();
    Sort(int a[], int nr);
    Sort(int nr, ...);
    Sort(char s[]);
    void InsertSort(bool ascendent = false);
    void QuickSort(int l, int r, bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
