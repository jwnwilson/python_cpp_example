char const* greet()
{
   return "hello, world";
}

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hello_python)
{
    using namespace boost::python;
    def("greet", greet);
}