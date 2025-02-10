#include <Demo/demo_builder.h>

namespace Demo_Builder
{
    using namespace Model_Builder;
    template <typename T>
    void buildShip()
    {
        Director *director = new Director;
        ShipBuilder *builder = new T;
        director->setBuilder(builder);

        // 简约型
        director->buildSimpleShip();
        Ship *ship = builder->getShip();
        ship->showParts();
        delete ship;

        // 标准型
        builder->reset();
        director->buildStandardShip();
        ship = builder->getShip();
        ship->showParts();
        delete ship;

        // 豪华型
        builder->reset();
        director->buildRegalShip();
        ship = builder->getShip();
        ship->showParts();
        delete ship;

        delete builder;
        delete director;
    }

    template void buildShip<SunnyBuilder>();
    template void buildShip<MerryBuilder>();

    void demo_v1()
    {
        buildShip<SunnyBuilder>();
        std::cout << "===============" << std::endl;
        buildShip<MerryBuilder>();
    }
} // namespace Demo_Builder
