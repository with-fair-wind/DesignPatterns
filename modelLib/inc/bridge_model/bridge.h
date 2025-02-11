#pragma once

#include <stdafx.h>

namespace Model_Bridge
{
    /*
     * 需求: 对海贼世界中的 海贼团 和 海军 通过桥接模式进行管理
     */
    using std::cout;
    using std::endl;
    using std::string;

    // 成员对应的类
    struct Person
    {
        Person(string name, string job, string ability, string reward, string beizhu)
        {
            this->name = name;
            this->job = job;
            this->ability = ability;
            this->reward = reward;
            this->beizhu = beizhu;
        }
        ~Person() { cout << name << "被析构了..." << endl; }
        string name;
        string job;
        string ability;
        string reward;
        string beizhu;
    };

    class AbstractTeam
    {
    public:
        AbstractTeam(string name) : m_name(name) {}
        virtual ~AbstractTeam()
        {
            for (const auto &item : m_teamMap)
                delete item.second;
        }

        string getTeamName() { return m_name; }
        void addMember(Person *p) { m_teamMap.insert(make_pair(p->name, p)); }
        void show()
        {
            cout << m_name << ": " << endl;
            for (const auto &item : m_teamMap)
            {
                cout << "【name: " << item.second->name
                     << "，job: " << item.second->job
                     << "，ability: " << item.second->ability
                     << "，reward: " << item.second->reward
                     << "，beizhu: " << item.second->beizhu
                     << "】" << endl;
            }
        }
        virtual void executeTask() = 0;

    protected:
        string m_name;
        std::map<string, Person *> m_teamMap;
    };

    // 草帽
    class CaoMaoTeam : public AbstractTeam
    {
    public:
        using AbstractTeam::AbstractTeam;
        void executeTask() override { cout << "在海上冒险，找到 ONE PIECE 成为海贼王！" << endl; }
        ~CaoMaoTeam() { cout << "草帽海贼团被析构..." << endl; }
    };

    // 海军
    class SmokerTeam : public AbstractTeam
    {
    public:
        using AbstractTeam::AbstractTeam;
        void executeTask() override { cout << "为了正义, 先将草帽一网打尽!!!" << endl; }
        ~SmokerTeam() { cout << "斯摩格的海军被析构..." << endl; }
    };

    // 定义抽象部分 - 船
    class AbstractShip
    {
    public:
        AbstractShip(AbstractTeam *team) : m_team(team) {}
        void show()
        {
            m_team->show();
            m_team->executeTask();
        }
        virtual string getName() = 0;
        virtual void feature() = 0;

    protected:
        AbstractTeam *m_team;
    };

    class Merry : public AbstractShip
    {
    public:
        using AbstractShip::AbstractShip;
        string getName() override { return "前进 - 梅利号"; }
        void feature() override { cout << getName() << " -- 船首为羊头, 化身船精灵在司法岛舍己救下了草帽一伙！" << endl; }
    };

    class HaiJunShip : public AbstractShip
    {
    public:
        using AbstractShip::AbstractShip;
        string getName() override { return "无敌海军号"; }
        void feature() override { cout << getName() << " -- 船底由海楼石建造, 可以传过无风带的巨大炮舰!" << endl; }
    };
} // namespace Model_Bridge
