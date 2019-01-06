#pragma once

template<class T>
class MinHeap final
{
public:
    MinHeap(int maxSize) :
        m_maxSize(maxSize),
        m_last(-1)
    {
        m_pData = new T[m_maxSize];
    }

    ~MinHeap()
    {
        delete[] m_pData;
    }

    void Insert(T t)
    {
        m_pData[++m_last] = t;
        int current       = m_last;
        int parent        = (current - 1) / 2;

        while (current > RootNode && m_pData[parent] > m_pData[current])
        {
            Swap(parent, current);

            current = parent;
            parent  = (current - 1) / 2;
        }
    }

    T ExtractMin()
    {
        T min             = m_pData[RootNode];
        m_pData[RootNode] = m_pData[m_last--];
        int current       = RootNode;
        int child         = (current * 2) + 1;

        while (child <= m_last)
        {
            if (child + 1 <= m_last && m_pData[child + 1] < m_pData[child])
            {
                child++;
            }

            if (m_pData[current] <= m_pData[child])
            {
                break;
            }

            Swap(child, current);

            current = child;
            child   = (current * 2) + 1;
        }

        return min;
    }

private:
    void Swap(int i, int j)
    {
        T tmp      = m_pData[i];
        m_pData[i] = m_pData[j];
        m_pData[j] = tmp;
    }

    int m_last;
    int m_maxSize;
    T*  m_pData;

    static const int RootNode = 0;
};

template<class T>
void SimpleHeapSort(T v[], int n)
{
    // Requires n+1 additional space. The HeapSort function
    // below performs the sort without using extra space.

    MinHeap<T> h(n);
    int i;

    for (i = 0; i < n; i++)
    {
        h.Insert(v[i]);
    }

    for (i = 0; i < n; i++)
    {
        v[i] = h.ExtractMin();
    }
}

template<class T>
void Swap(T v[], int i, int j)
{
    T tmp = v[i];
    v[i]  = v[j];
    v[j]  = tmp;
}

template<class T>
void HeapSort(T v[], int n)
{
    // In-place heap sort.
    // Uses a max heap.

    int current, parent, child;

    for (int i = 1; i < n; i++)
    {
        // siftup(i)

        current = i;
        parent  = (current - 1) / 2;

        while (current > 0 && v[parent] < v[current])
        {
            Swap(v, parent, current);

            current = parent;
            parent  = (current - 1) / 2;
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        Swap(v, 0, i);

        // siftdown(i - 1)
        current = 0;
        child   = (current * 2) + 1;

        while (child < i)
        {
            if (child + 1 < i && v[child + 1] > v[child])
            {
                child++;
            }

            if (v[current] >= v[child])
            {
                break;
            }

            Swap(v, child, current);

            current = child;
            child   = (current * 2) + 1;
        }
    }
}
