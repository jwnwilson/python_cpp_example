#include <boost/python.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

void thread_process(int threadno, int runs){
	for(int i=0;i<runs;i++){
		cout << "Thread no: " +to_string(threadno)+ ", process :" + to_string(i);
	}
}

class Multithreader
{
public:
    Multithreader(int t, int r){
    	threads = t;
    	runs = r;
    }
    void run(){
    	Py_BEGIN_ALLOW_THREADS

    	vector<thread> thread_vector;

    	/*for(int i =0;i<threads;i++){
    		thread t = thread(thread_process, runs);
    		thread_vector.push_back(t);
    	}

    	for(int i =0;i<threads;i++){
    		thread_vector[i].join();
    	}*/

    	thread t1 = thread(thread_process, 1, runs);

    	t1.join();

    	Py_END_ALLOW_THREADS
    }
private:
	int runs;
	int threads;
};

using namespace boost::python;

BOOST_PYTHON_MODULE(multithreader)
{
    class_<Multithreader>("Multithreader", init<int, int>())
        .def("run", &Multithreader::run)
    ;
};