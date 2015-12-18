#include <boost/python.hpp>
#include <string>

//using namespace std;

class SomeClass
{
public:
    SomeClass(std::string n){
        name = n;
    }

    void set(std::string msg) { 
        mMsg = msg; 
    }

    std::string greet() {
        return mMsg + " from " + name; 
    }
private:
    std::string name;
    std::string mMsg;
};

using namespace boost::python;

BOOST_PYTHON_MODULE(someclass)
{
    class_<SomeClass>("SomeClass", init<std::string>())
        .def("greet", &SomeClass::greet)
        .def("set", &SomeClass::set)
    ;
};