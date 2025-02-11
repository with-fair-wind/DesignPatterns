#include <Demo/demo_facade.h>

namespace Demo_Facade
{
    void demo_v1()
    {
        using namespace Model_Facade;
        LionCannon lion;
        lion.aimAndLock();
        lion.fire();
    }
} // namespace Model_Facade