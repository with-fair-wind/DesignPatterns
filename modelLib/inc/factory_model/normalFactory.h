#pragma once

#include <stdafx.h>

namespace Model_NormalFactory
{
    class AbstractSmile
    {
    public:
        virtual void transform() = 0;
        virtual void ability() = 0;
        virtual ~AbstractSmile() = default;
    };

    class SheepSmile : public AbstractSmile
    {
    public:
        void transform() override { std::cout << "变成人兽 -- 山羊人形态..." << std::endl; }
        void ability() override { std::cout << "将手臂变成绵羊角的招式 -- 巨羊角" << std::endl; }
    };

    class LionSmile : public AbstractSmile
    {
    public:
        void transform() override { std::cout << "变成人兽 -- 狮子人形态..." << std::endl; }
        void ability() override { std::cout << "火遁· 豪火球之术..." << std::endl; }
    };

    class BatSmile : public AbstractSmile
    {
    public:
        void transform() override { std::cout << "变成人兽 -- 蝙蝠人形态..." << std::endl; }
        void ability() override { std::cout << "声纳引箭之万剑归宗..." << std::endl; }
    };

    class AbstractFactory
    {
    public:
        virtual AbstractSmile *createSmile() = 0;
        virtual ~AbstractFactory() = default;
    };

    class SheepFactory : public AbstractFactory
    {
    public:
        AbstractSmile *createSmile() { return new SheepSmile; }
    };

    // 生产狮子的恶魔果实
    class LionFactory : public AbstractFactory
    {
    public:
        AbstractSmile *createSmile() { return new LionSmile; }
    };

    // 生产蝙蝠的恶魔果实
    class BatFactory : public AbstractFactory
    {
    public:
        AbstractSmile *createSmile() { return new BatSmile; }
    };
} // namespace Model_
