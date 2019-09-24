//
//
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include<iterator>
#include <sstream>

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
    set<int> s1; //set will automatically use a ascent sortion.
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

void mapDemo()
{
    map<int, int> A;
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;
    A[12389304] = 1;

    map<char, int> cnt;
    string x = "chuan chuan is awesome";

    for (char c : x)
    {
        cnt[c]++;
    }

    cout << cnt['a'] << " " << cnt['c'] << endl;

    for(auto pair : cnt)
    {
        cout << pair.first << " " << pair.second << endl;  // we can see that map is like set, follow a ascent of alphabet.
    }
}

void powOfSet()
{
    set< pair<int, int> > S;
    S.insert({401, 450});
    S.insert({10,20});
    S.insert({2,3});
    S.insert({30,400});

    //2,3
    //10,20
    //30, 400
    //401,450

    int point =402;
    auto it = S.upper_bound({point, INT32_MAX});
    if (it == S.begin())
    {
        cout << "the given point is not lying in any interval..\n";
        return;
    }
    if (it == S.end())
    {
        cout << "man, you reached the end.\n";
    }
    it--;
    pair<int, int> current = *it;
    if(current.first <= point and point <= current.second)
    {
        cout << "yes, it's present: " << current.first << " " << current.second << endl;
    }
    else
    {
        cout << " the given point is not lying in there.\n ";
    }

}
void unorderedMap()
{
    map<char, int> M;
    unordered_map<char, int> U;

    string s = "this is a great show.";
    //add(key, value) map: O(logN)  unorderedmaps: O(1)
    //erase(key) map: O(logN)  unorderedmaps: O(1)

    for(char c : s) M[c]++; //O(NlogN) N= s's size.

    for(char c : s) U[c]++; //O(N)  N means s's size.
}

void mapDemo2()
{
    map<char, int> mymap;
    mymap.insert (pair<char, int>('a', 100));
    mymap.insert (make_pair('z', 200));

    map<char, int>::iterator it = mymap.begin();
    mymap.insert(it, pair<char, int>('b', 300));  //it is a hint

    it = mymap.find('z'); //O(log(n))

//show content
    for(it=mymap.begin(); it!=mymap.end(); it++)
        cout << (*it).first << " =>" << (*it).second << endl;

//multimap is a map that allows duplicated keys
    multimap<char, int> myMultimap;


//map/multimap
// --key cannot be modified
// type of *it pair<const char, int>
//    (*it).first = 'd'; //error

}

void streamIteratorDemo()
{
    copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, ", "));
}

void parseStringStreamPrint()
{
    // stringstream can parse string to integers
    stringstream ss("25,1,32");
    int s;
    char a;
    while(ss >> s >> a) //loop when ss can extract to int and char. for the last integer, out of loop
    {
        cout << "you made it." << endl;
        cout << s << endl;
    }
    ss >> s;  // have to made another extract.
    cout << s << endl;
}

void writeData2StringStream()
{
    stringstream ss;
    int age =14;
    string name = "chuan";
    int score = 12;
    ss << age << "," <<name<< ","<< score;
    cout << ss.str() << endl;
}

void getline_sstream(){
    string i ;
    cout << "input your scores\n";
    getline(std::cin,i);
    cout << i <<endl;
    vector<int> scores;
    stringstream ss(i);
    int grade;
    char ch; // no need char, in sstream class, it will automatically identify space~, not like comma in function  parseStringStreamPrint()
    while (ss>>grade)
    {
        scores.push_back(grade);
    }
    for(int a = 0; a < scores.size(); ++a){
        cout << scores.at(a) << endl;
    }

}
class Student
{
public:
    int calculateTotalScore(){
        int sum=0;
        for(int i =0; i<5; ++i)
        {

            sum +=scores[i];
            cout << sum << endl;
        }
        return sum;
    }
    void input(){
        string str;
        cout << "why you not stop\n";
        getline(std::cin, str);
        cout << str << endl;
        //vector<int> tmpVec;
        stringstream ss(str);
        int grade;
        while ( ss >> grade)
        {
            scores.push_back(grade);
        }
        for(int i=0; i<scores.size(); ++i)
            cout << scores[i] << endl;
    }
private:
    vector<int> scores;
    static int chuan;
};

void checkCinIgnore()
{

    int n; // number of students
    cout << "please input number of students\n";
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "please input " << i << " students grades\n";
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();
    cout << kristen_score << endl;
    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
}

int main()
{


    Student Student::chuan;
    //cout << Student::chuan << "\n";

    return 0;
}