#pragma once

#include <stdafx.h>

namespace Model_Builder
{
    using std::string;

    class Ship
    {
    public:
        virtual void showParts() = 0;
        virtual ~Ship() = default;
    };

    // 定义桑尼号的船
    class SunnyShip : public Ship
    {
    public:
        void addParts(string name) { m_parts.push_back(name); }

        void showParts() override
        {
            for (const auto &item : m_parts)
                std::cout << item << " ";
            std::cout << std::endl;
        }

    private:
        std::vector<string> m_parts;
    };

    // 定义梅丽号的船
    class MerryShip : public Ship
    {
    public:
        void assemble(string name, string parts) { m_parts.insert(make_pair(parts, name)); }

        void showParts() override
        {
            for (const auto &item : m_parts)
                std::cout << item.first << ":" << item.second;
            std::cout << std::endl;
        }

    private:
        std::map<string, string> m_parts;
    };

    // 定义生成器类 - 3
    class ShipBuilder
    {
    public:
        virtual Ship *getShip() = 0;
        virtual void reset() = 0;
        virtual void buildBody() = 0;
        virtual void buildWeapon() = 0;
        virtual void buildEngine() = 0;
        virtual void buildInterior() = 0;
        virtual ~ShipBuilder() {}
    };

    class SunnyBuilder : public ShipBuilder
    {
    public:
        SunnyBuilder() { reset(); }
        ~SunnyBuilder()
        {
            if (m_ship)
            {
                delete m_ship;
                m_ship = nullptr;
            }
        }

        Ship *getShip() override
        {
            Ship *ship = m_ship;
            m_ship = nullptr;
            return ship;
        }
        void reset() override { m_ship = new SunnyShip; }
        void buildBody() override { dynamic_cast<SunnyShip *>(m_ship)->addParts("船体是神树亚当"); }
        void buildWeapon() override { dynamic_cast<SunnyShip *>(m_ship)->addParts("狮吼炮"); }
        void buildEngine() override { dynamic_cast<SunnyShip *>(m_ship)->addParts("可乐驱动的内燃机"); }
        void buildInterior() override { dynamic_cast<SunnyShip *>(m_ship)->addParts("非常豪华的内室装修"); }

    private:
        Ship *m_ship;
    };

    class MerryBuilder : public ShipBuilder
    {
    public:
        MerryBuilder() { reset(); }
        ~MerryBuilder()
        {
            if (m_ship)
            {
                delete m_ship;
                m_ship = nullptr;
            }
        }

        Ship *getShip() override
        {
            Ship *ship = m_ship;
            m_ship = nullptr;
            return ship;
        }
        void reset() override { m_ship = new MerryShip; }
        void buildBody() override { dynamic_cast<MerryShip *>(m_ship)->assemble("船体是优质木材", "船体"); }
        void buildWeapon() override { dynamic_cast<MerryShip *>(m_ship)->assemble("普通的四门大炮", "武器系统"); }
        void buildEngine() override { dynamic_cast<MerryShip *>(m_ship)->assemble("烧煤的蒸汽机", "动力系统"); }
        void buildInterior() override { dynamic_cast<MerryShip *>(m_ship)->assemble("非常豪华的内室装修", "内室"); }

    private:
        Ship *m_ship;
    };

    // 管理类
    class Director
    {
    public:
        void setBuilder(ShipBuilder *builder) { m_builder = builder; }

        // 简约型
        void buildSimpleShip()
        {
            m_builder->buildBody();
            m_builder->buildEngine();
        }
        // 标准型
        void buildStandardShip()
        {
            buildSimpleShip();
            m_builder->buildWeapon();
        }

        // 豪华型
        void buildRegalShip()
        {
            buildStandardShip();
            m_builder->buildInterior();
        }

    private:
        ShipBuilder *m_builder = nullptr;
    };

} // namespace Model_Builder
