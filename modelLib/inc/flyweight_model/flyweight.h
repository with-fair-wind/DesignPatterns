#pragma once

#include <stdafx.h>

namespace Model_Flyweight
{
    using std::cout;
    using std::endl;
    using std::string;

    class FlyWeightBody
    {
    public:
        FlyWeightBody(string sprite) : m_sprite(sprite) {}
        virtual void move(int x, int y, int speed) = 0;
        virtual void draw(int x, int y) = 0;
        virtual ~FlyWeightBody() {}

    protected:
        string m_sprite;
        string m_color;
    };

    // 享元类的子类 - 炮弹
    class SharedBombBody : public FlyWeightBody
    {
    public:
        using FlyWeightBody::FlyWeightBody;
        void move(int x, int y, int speed)
        {
            cout << "炸弹以每小时" << speed << "速度飞到了("
                 << x << ", " << y << ") 的位置..." << endl;
        }
        void draw(int x, int y)
        {
            cout << "在 (" << x << ", " << y << ") 的位置重绘炸弹弹体..." << endl;
        }
    };

    // 享元类的子类 - 彩蛋
    class UniqueBombBody : public FlyWeightBody
    {
    public:
        using FlyWeightBody::FlyWeightBody;
        void move(int x, int y, int speed)
        {
            // 此处省略对参数 x, y, speed的处理
            cout << "彩蛋在往指定位置移动, 准备爆炸发放奖励..." << endl;
        }
        void draw(int x, int y)
        {
            cout << "在 (" << x << ", " << y << ") 的位置重绘彩蛋运动轨迹..." << endl;
        }
    };

    // 发射炮弹
    class LaunchBomb
    {
    public:
        LaunchBomb(FlyWeightBody *body) : m_body(body) {}
        void setSpeed(int speed)
        {
            m_speed = speed;
        }
        void move(int x, int y)
        {
            m_x = x;
            m_y = y;
            m_body->move(m_x, m_y, m_speed);
            draw();
        }
        void draw()
        {
            m_body->draw(m_x, m_y);
        }

    private:
        FlyWeightBody *m_body;
        int m_speed = 100;
        int m_x = 0;
        int m_y = 0;
    };

    // 享元工厂类
    class BombBodyFactory
    {
    public:
        // 参数就是炸弹的型号
        FlyWeightBody *getSharedData(string name)
        {
            FlyWeightBody *data = nullptr;
            // 遍历容器
            for (auto item : m_bodyMap)
            {
                if (item.first == name)
                {
                    // 找到了
                    data = item.second;
                    cout << "正在复用 <" << name << ">..." << endl;
                    break;
                }
            }
            if (data == nullptr)
            {
                data = new SharedBombBody(name);
                cout << "正在创建 <" << name << ">..." << endl;
                m_bodyMap.insert(make_pair(name, data));
            }
            return data;
        }

        ~BombBodyFactory()
        {
            for (auto item : m_bodyMap)
            {
                delete item.second;
            }
        }

    private:
        std::map<string, FlyWeightBody *> m_bodyMap;
    };
} // namespace Model_Flyweight
