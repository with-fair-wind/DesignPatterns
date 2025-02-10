#pragma once

#include <stdafx.h>

namespace Model_Singleton
{
    class Singleton
    {
    public:
        static Singleton &getInstance()
        {
            static Singleton instance;
            return instance;
        }

        void print()
        {
            std::cout << "Singleton" << std::endl;
        }

    private:
        Singleton() = default;
        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton &) = delete;
    };
};