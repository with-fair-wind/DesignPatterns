#include <Demo/demo_singleton.h>

namespace Demo_singleton
{
    void demo_v1()
    {
#ifdef Version_1
        Model_Singleton::Singleton &singleton = Model_Singleton::Singleton::getInstance();
        singleton.print();
#elif defined(Version_2)
        Model_Singleton::Singleton *singleton = Model_Singleton::Singleton::getInstance();
        singleton->print();
        delete Model_Singleton::Singleton::getInstance();
#endif
    }
} // namespace Demo_singleton