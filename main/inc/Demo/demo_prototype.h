#pragma once

#include <prototype_model/prototype.h>

namespace Demo_Prototype
{
    using namespace Model_Prototype;
    template <typename T>
    static void cloneSoldier()
    {
        GermaSoldier *obj = new T;
        GermaSoldier *soldier = obj->clone();
        std::cout << soldier->whoAmI() << std::endl;
        delete soldier;
        delete obj;
    }

    void demo_v1();
} // namespace Demo_Prototype
