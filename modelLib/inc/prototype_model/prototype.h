#pragma once

#include <stdafx.h>

namespace Model_Prototype
{
    using std::string;
    class GermaSoldier
    {
    public:
        virtual GermaSoldier *clone() = 0;
        virtual string whoAmI() = 0;
        virtual ~GermaSoldier() {}
    };

    // 子类
    class Soldier66 : public GermaSoldier
    {
    public:
        GermaSoldier *clone() override { return new Soldier66(*this); }
        string whoAmI() override { return "我是 Soldier66 的士兵!!!"; }
    };

    class Soldier67 : public GermaSoldier
    {
    public:
        GermaSoldier *clone() override { return new Soldier67(*this); }
        string whoAmI() override { return "我是 Soldier67 的士兵!!!"; }
    };
} // namespace Model_Prototype
