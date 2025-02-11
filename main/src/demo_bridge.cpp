#include <Demo/demo_bridge.h>

namespace Demo_Bridge
{
    void demo_v1()
    {
        using namespace Model_Bridge;
        AbstractTeam *team = new CaoMaoTeam("草帽海贼团");
        Person *luffy = new Person("路飞", "船长", "橡胶果实能力者", "30亿贝里", "爱吃肉");
        Person *zoro = new Person("索隆", "剑士", "三刀流", "11亿1100万贝里", "路痴");
        Person *sanji = new Person("山治", "厨师", "隐形黑", "10亿3200万贝里", "好色");
        Person *nami = new Person("娜美", "航海士", "天候棒+宙斯", "3亿6600万贝里", "喜欢钱");
        team->addMember(luffy);
        team->addMember(zoro);
        team->addMember(sanji);
        team->addMember(nami);

        AbstractShip *ship = new Merry(team);
        ship->show();
        ship->feature();
        delete team;
        delete ship;
        cout << "=======================" << endl;
        // 斯摩格的船队
        team = new SmokerTeam("斯摩格的海军部队");
        Person *smoker = new Person("斯摩格", "中将", "冒烟果实能力者", "", "爱吃烟熏鸡肉");
        Person *dasiqi = new Person("达斯琪", "大佐", "一刀流", "", "近视");
        team->addMember(smoker);
        team->addMember(dasiqi);
        ship = new HaiJunShip(team);
        ship->feature();
        ship->show();
        delete team;
        delete ship;
    }
} // namespace Demo_Bridge
