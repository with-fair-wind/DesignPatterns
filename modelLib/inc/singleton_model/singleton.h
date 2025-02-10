#pragma once

#include <stdafx.h>

namespace Model_Singleton
{
#define Version_2
#ifdef Version_1
    class Singleton
    {
    public:
        static Singleton &getInstance()
        {
            static Singleton instance;
            return instance;
        }

        void print() { std::cout << "Singleton" << std::endl; }

    private:
        Singleton() = default;
        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton &) = delete;
    };
#elif defined(Version_2)
    class Singleton
    {
    public:
        static Singleton *getInstance();

        void print() { std::cout << "Singleton" << std::endl; }

    private:
        Singleton() = default;
        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton &) = delete;

    private:
        static std::atomic<Singleton *> m_instance;
        static std::mutex m_mtx;
    };
#endif
};