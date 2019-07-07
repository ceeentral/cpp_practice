//
//
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool fuc(int x , int y)
{
    return x > y;
}

void vectorDemo()
{
    vector<int> A = {14,12,13,1};
    cout << A[1] << endl;

    sort(A.begin(), A.end());

    bool present = binary_search(A.begin(), A.end(), 3); //false
    present = binary_search(A.begin(), A.end(), 1); //true

    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100); //true

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    //1,12,13,14,100,100,100,100,123
    A.push_back(123);

    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100); // >=
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // >

    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl; //4

    sort(A.begin(), A.end(), fuc);

    for (int a : A){
        cout << a << " ";
    }

    // print vector content, can either use below method. prefer the way above.

    /*
    vector<int>::iterator it3;
    for(it3 =A.begin(); it3 != A.end(); it3++)
    {
        cout << *it3 << " ";
    }
    */
    cout << "\n";
}

void setDemo()
{
    set<int> s1; //set will automatically use a assent sortion.
    s1.insert(1);
    s1.insert(10);
    s1.insert(0);
    s1.insert(-5);

    for (int x : s1)
        cout << x << " ";
    cout << endl;
    // -5 0 1 10

    auto it = s1.find(-5);
    if (it == s1.end()){
        cout << "not present\n";
    }
    else{
        cout << "present\n";
        cout << *it <<endl;
    }

    auto it2 =s1.lower_bound(-5); // >=
    auto it3 =s1.upper_bound(-10); // >
    cout << *it2 << " " << *it3 << endl;

    auto it4 = s1.upper_bound(11);

    if(it4 == s1.end())
    {
        cout << "not present in this set.\n";
    }
}
int main()
{
    //C++ STL
    setDemo();

    return 0;
}