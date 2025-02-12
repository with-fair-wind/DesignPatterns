#include <Demo/demo_proxy.h>

namespace Demo_Proxy
{
    using namespace Model_Proxy;
    void demo_v1()
    {
        // 直接交流
        Communication *speaker = new Speaker;
        speaker->communicate();
        delete speaker;
        std::cout << "=====================" << std::endl;
        // 通过电话虫(代理)交流
        speaker = new DenDenMuShi;
        speaker->communicate();
        delete speaker;
    }
} // namespace Demo_Proxy