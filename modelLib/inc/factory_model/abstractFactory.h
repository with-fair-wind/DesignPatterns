#pragma once

#include <stdafx.h>

namespace Model_AbstractFactory
{
    // 船体
    class ShipBody
    {
    public:
        virtual std::string getBody() = 0;
        virtual ~ShipBody() {}
    };

    class WoodBody : public ShipBody
    {
    public:
        std::string getBody() override { return std::string("使用<木材>制作海贼船的船体..."); }
    };

    class IronBody : public ShipBody
    {
    public:
        std::string getBody() override { return std::string("使用<钢铁>制作海贼船的船体..."); }
    };

    class MetalBody : public ShipBody
    {
    public:
        std::string getBody() override { return std::string("使用<合成金属>制作海贼船的船体..."); }
    };

    // 引擎
    class Engine
    {
    public:
        virtual std::string getEngine() = 0;
        virtual ~Engine() {}
    };

    class Human : public Engine
    {
    public:
        std::string getEngine() { return "海贼船的动力方式是 <手动>..."; }
    };

    class Diesel : public Engine
    {
    public:
        std::string getEngine() { return "海贼船的动力方式是 <内燃机>..."; }
    };

    class Nuclear : public Engine
    {
    public:
        std::string getEngine() { return "海贼船的动力方式是 <核反应堆>..."; }
    };

    // 武器
    class Weapon
    {
    public:
        virtual std::string getWeapon() = 0;
        virtual ~Weapon() {}
    };

    class Gun : public Weapon
    {
    public:
        std::string getWeapon() { return std::string("船上的武器系统是 < 枪 > ..."); }
    };

    class Laser : public Weapon
    {
    public:
        std::string getWeapon() { return std::string("船上的武器系统是 < 激光 > ..."); }
    };

    class Cannon : public Weapon
    {
    public:
        std::string getWeapon() { return std::string("船上的武器系统是 < 加农炮 > ..."); }
    };

    // 船
    class Ship
    {
    public:
        Ship(ShipBody *body, Engine *engine, Weapon *weapon) : m_body(body), m_engine(engine), m_weapon(weapon) {}
        ~Ship()
        {
            delete m_body;
            delete m_weapon;
            delete m_engine;
        }
        std::string getProperty() { return m_body->getBody() + m_weapon->getWeapon() + m_engine->getEngine(); }

    private:
        ShipBody *m_body;
        Engine *m_engine;
        Weapon *m_weapon;
    };

    // 工厂类 - 抽象
    class AbstractFactory
    {
    public:
        virtual Ship *createShip() = 0;
        virtual ~AbstractFactory() {}
    };

    class BasicFactory : public AbstractFactory
    {
    public:
        Ship *createShip() override
        {
            Ship *ship = new Ship(new WoodBody, new Human, new Gun);
            std::cout << "<基础型的海贼船> 已经建造完毕!!!" << std::endl;
            return ship;
        }
    };

    class StandardFactory : public AbstractFactory
    {
    public:
        Ship *createShip() override
        {
            Ship *ship = new Ship(new IronBody, new Diesel, new Cannon);
            std::cout << "<标准型的海贼船> 已经建造完毕!!!" << std::endl;
            return ship;
        }
    };

    class UltimataFactory : public AbstractFactory
    {
    public:
        Ship *createShip() override
        {
            Ship *ship = new Ship(new MetalBody, new Nuclear, new Laser);
            std::cout << "<旗舰型的海贼船> 已经建造完毕!!!" << std::endl;
            return ship;
        }
    };
} // namespace Model_AbstractFactory
