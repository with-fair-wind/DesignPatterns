#include <singleton_model/singleton.h>

namespace Model_Singleton
{
#ifdef Version_2
    std::atomic<Singleton *> Singleton::m_instance{nullptr};
    std::mutex Singleton::m_mtx;

    Singleton *Singleton::getInstance()
    {
        Singleton *instance = m_instance.load();
        if (!instance)
        {
            std::lock_guard<std::mutex> lock(m_mtx);
            instance = m_instance.load();
            if (!instance)
            {
                instance = new Singleton;
                m_instance.store(instance);
            }
        }
        return instance;
    }
#endif
}; // namespace Model_Singleton