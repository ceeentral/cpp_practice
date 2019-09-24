#include <functional>
#include <iostream>
using namespace std;
struct Foo {
    Foo(int num) : num_(num) {cout << "construct first"<<endl;}
    void print_add(int i ,int b) const { std::cout << num_+i <<" "<< b<<'\n'; }
    ~Foo(){cout << "hi bae, this deconsturctor"<<endl;}
    int num_;
};

void print_num(int i)
{
    std::cout << i << '\n';
}

struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

int main()
{
    /*
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);

    // store a lambda
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();

    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();

    // store a call to a member function
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);

    // store a call to a data member accessor
    std::function<int(Foo const&)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n';
*/
    // store a call to a member function and object
    const Foo foo(314159);
    using std::placeholders::_2;
    std::function<void(int, int)> f_add_display2 = std::bind( &Foo::print_add, foo, std::placeholders::_1, std::placeholders::_2 );
    f_add_display2(2,3);

    // store a call to a member function and object ptr
    //std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _2 );
    //f_add_display3(3,4);

    // store a call to a function object
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
}