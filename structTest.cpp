//
//
//
#include <string>
#include <iostream>
#include <vector>


struct cat{
    static constexpr auto varias{"Chinacountrycat"};
    //neither static const auto varias{"Chinacountrycat"};
    //nor static auto varias{"Chinacountrycat"};
    //nor  static constexpr std::string varias{"Chinacountrycat"};  working.
    //feel kind confused by this method.
    //only 1 thing is clear, is that we can use static define a variation in struct and then pass nothing to this
    //when initial this struct. like main below.
    std::string name;
    uint32_t age;
};


void test_struct(){
    using namespace std;
    cat feichang{ "feichang", 2};
    cout << feichang.name << "\n" << feichang.varias << "\n" << feichang.age << endl;
}


void test_vector(){
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(1100);
    vec1.push_back(-100);

    for(int it : vec1)
        std::cout << it << " ";
}
int main(){

    test_vector();
    return 0;
}