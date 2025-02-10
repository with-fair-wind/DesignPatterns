#include <Demo/demo_singleton.h>

namespace Demo_singleton
{
    void demo_v1()
    {
        Model_Singleton::Singleton &singleton = Model_Singleton::Singleton::getInstance();
        singleton.print();
    }
} // namespace Demo_singleton