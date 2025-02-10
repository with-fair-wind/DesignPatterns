#include <Demo/demo_factory.h>

namespace Demo_Factory
{
    void demo_v1()
    {
        using namespace Model_NormalFactory;
        AbstractFactory *factory = new LionFactory;
        AbstractSmile *obj = factory->createSmile();
        obj->transform();
        obj->ability();
        delete factory;
        delete obj;
    }

    void demo_v2()
    {
        using namespace Model_AbstractFactory;
        AbstractFactory *factory = new UltimataFactory;
        Ship *ship = factory->createShip();
        std::cout << ship->getProperty();
        delete ship;
        delete factory;
    }
} // namespace Demo_Factory
