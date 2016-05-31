#include <iostream>
using namespace std;
/**
 * Cool tricks with templates and macros
 */
#define GET(dest, obj, name)\
struct B{\
    template <typename T>\
    static typename enable_if<sizeof(&T::name), decltype(((T*)0)->name)>::type get_val(T t) {\
        return t.name;\
    };\
    template <typename T>\
    static typename enable_if<sizeof(&T::get_##name()), decltype(((T*)0)->get_##name())>::type get_val(T t) {\
        t.get_name;\
    };\
};\
dest = B::get_val(obj);

#define DECLARE_GET(name)\
    template <typename T>\
    static typename enable_if<sizeof(&T::name), decltype(((T*)0)->name)>::type get_##name(T t) {\
        return t.name;\
    }\
    template <typename T>\
    static typename enable_if<sizeof(&T::get_##name()), decltype(((T*)0)->get_##name())>::type get_##name(T t) {\
        t.get_name;\
    }\


class A{
public:
    string name = "Work";
    string get_name() {
        return "010213";
    }
    int foo(int x) {

    }
};

A a;
GET(auto str, a, name);

DECLARE_GET(name)

int main() {

    cout << str << get_name(a) << endl;

    return 0;
}