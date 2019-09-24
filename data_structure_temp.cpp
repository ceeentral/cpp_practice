//
// Created by old wang on 2019-09-14.
//
#include <iostream>
#include <vector>
#include <functional>
#define MYARRAY {1,100,20,55,34,99,500,54}
/*
 name                time         space         stablility       suited storage
directInsert        O(n2)         O(1)           stable          sequential & linked
halfsearchInsert    O(n2)         O(1)           stable          sequential



*/
using vec = std::vector<int>;
class base
{
public:
    typedef void(*callback)();
    void print(vec A){
        for(auto a : A)
            std::cout << a<<" ";
        std::cout<<"\n";
    }
    template <class T>
    void Callfunc()
    {
        T caller;
        caller.callfunc();
    }
    void swap(vec& A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

};

class directInsert : public base
{

public:
    void insertSort(std::vector<int> &A, int n)
    {
        int i,j;
        for(i=2;i<=n;i++)
        {
            A[0]=A[i];
            for(j=i-1;A[0]<A[j];j--)
            {
                A[j+1]=A[j];
            }
            A[j+1]=A[0];
        }
    }

    void callfunc()
    {
        std::vector<int> A = {1,99,3,77,5 ,6,7,8,9,10};
        insertSort(A, 9);
        print(A);
    }
    void print(std::vector<int> &A)
    {
        for(auto a : A)
            std::cout << a<<" ";
        std::cout<<"\n";
    }
};

class HalfInsert :public base
{
public:
    void hInsertSort(std::vector<int> &A, int len)
    {
        int i, j, low, high, mid; //i for all member in list, j for
        for(i=2; i<=len;++i)
        {
            A[0] = A[i];
            low = 1;   //half search start
            high = i -1;
            while(low<=high)
            {
                mid = (low+high)/2;
                if(A[mid]>A[0])
                    high = mid -1;
                else
                    low = mid +1;
            }       //half search end.
            for(j=i-1;j>=high +1;j--)  //move para after the high +1 ,because we need to insert the int to location high +1
                A[j+1]=A[j];
            A[high+1] = A[0];

        }
    }
     void callfunc()
     {
        std::vector<int> B = {33, 2, 55, 11, 56, 44, 10}; //size 7
        hInsertSort(B, 6);
        print(B);
     }
};


//shell sort need to debug. not working now..
class Shellsort : public base  //decrease increment method
{
    using vec = std::vector<int>;
public:
    void shellSort(vec &A, int len)
    {
        for(int dk=len/2; dk>=1; dk=dk/2)  //decrease increment, dk stand for increment
            for(int i =dk+1; i<=len; ++i) //sort insert in each group
            {
                if(A[i]<A[i-dk]){
                    int recordJ;
                    A[0] = A[i];  //A[0]  not guard
                    for(int j = i-dk; j>0 and A[0]<A[j]; j-=dk)
                    {
                        A[j+dk]=A[j];
                        recordJ = j;
                    }//j= j-dk means sort in current group
                    A[recordJ+dk]=A[0];
                }
            }

    }
    void callfunc()
    {
        std::vector<int> C = {1,100,20,55,34,99,500,54};
        shellSort(C, 8);
        print(C);
    }
};

class Bubblesort : public base
{
public:

    void bubbleSort(vec &A, int n)
    {
        for(int i=0;i<n-1;i++) //several bubble
        {
            bool flag=false;
            for(int j=n-1;j>i;j--)  //one bubble
            {
                if(A[j-1]>A[j]){  //if disordered
                    swap(A, j-1, j); //swap
                    flag = true;  //
                }
            }
            if(not flag)   //if no swap anymore, means list is ordered
                return;
        }
    }
    void callfunc()
    {
        std::vector<int> D = {1,100,20,55,34,99,500,54};
        bubbleSort(D, 8);
        print(D);
    }
};


class Fastsort: public base
{
public:
    int Partition(vec& A, int low, int high)
    {
        int pivot = A[low];
        while (low<high)
        {
            while (low<high and A[high]>=pivot) --high;
            A[low] = A[high];
            while (low<high and A[low]<=pivot) ++low;
            A[high] = A[low];
        }
        A[low] = pivot;
        return low;
    }
    void Quicksort(vec& A, int low, int high)
    {
        if(low < high)
        {
            //Partion();
            int pivotpos = Partition(A,low,high);
            Quicksort(A,low,pivotpos-1);
            Quicksort(A,pivotpos+1,high);
        }
    }
    void callfunc()
    {
        vec E=MYARRAY;
        Quicksort(E,1,7);
        print(E);
    }
};

class Selectsort :public base
{
public:
    void selectsort(vec& A, int n)
    {
        for(int i =0; i<n-1;i++)
        {
            int min=i;
            for(int j = i+1;j<n;j++)
            {
                if(A[j]<A[min]) min=j;
            }
            if(min!=i) swap(A, i, min);
        }
    }
    void callfunc()
    {
        vec D = {1,100,20,55,34,99,500,54};
        selectsort(D, 8);
        print(D);
    }
};


class MaxHeapsort : public base
{
    void buildMaxheap(vec& A, int len)
    {
        for(int i=len/2; i>0;i--)
            AdjustDown(A, i, len);
    }
    void AdjustDown(vec& A, int k, int len){
        A[0] = A[k];
        for(int i = 2*k; i<=len; i*=2)
        {
            if(i<len  and A[i]<A[i+1])
                i++;
            if(A[0]>=A[i])
                break;
            else{
                A[k]=A[i];
                k=i;
            }
        }
        A[k] =A[0];
    }
    void heapsort(vec& A, int len)
    {
        buildMaxheap(A, len);

        for(int i = len;i>1; i--)
        {
            swap(A, i,1);
            AdjustDown(A, 1, i-1);
        }
    }
    void callfunc()
    {
        vec E = {1,100,20,55,34,99,500,54};
        heapsort(E, 8);
        print(E);
    }

};

class merge : public base
{
    vec B;
    void Merge(vec& A, int low, int mid, int high){
        for(int k = low;k <=high;k++)
            B[k]=A[k];
        //int i,j,k;
        for(int i =low,j=mid+1,k =i;i<mid and j<=high;i++ )
        {
            if(B[i]<=B[j])
                A[k]=B[i++];
            else
                A[k] = B[j++];
        }
        while (i<=mid)
            A[k++]=B[i++];
        while (j<=high)
            A[k++]=B[j++];
    }
    void mergesort(vec& A, int low, int high){
        if(low<high){
            int mid=(low+high)/2;
            mergesort(A,low,high);
            mergesort(A, mid+1,high);
            Merge(A,low,mid,high);
        }
    }
};


int main()
{
    base bb;
    bb.Callfunc<Selectsort>();

    return 0;
}

