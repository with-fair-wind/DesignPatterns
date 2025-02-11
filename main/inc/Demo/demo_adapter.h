#pragma once

#include <adapter_model/adapter.h>

namespace Demo_Adapter
{
    using namespace Model_Adapter;
    template <typename T, typename Adapter>
    static void translate()
    {
        Foreigner *foreigner = new T;
        AbstractChopper *adapter = new Adapter(foreigner);
        adapter->translateToPanda();
        adapter->translateToHuman();
        delete foreigner;
        delete adapter;
    }

    void demo_v1();
} // namespace Demo_Adapter
