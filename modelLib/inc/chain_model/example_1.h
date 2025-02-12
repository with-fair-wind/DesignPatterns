#pragma once

#include <stdafx.h>

namespace Model_Chain
{
    enum class RequestType : char
    {
        QingJia,
        ZhangXin,
        CiZhi
    };
    // 抽象的管理者节点
    class AbstractManager
    {
    public:
        void setNext(AbstractManager *next) { m_next = next; }
        virtual void handleRequest(RequestType type) = 0;
        virtual ~AbstractManager() {}

    protected:
        AbstractManager *m_next = nullptr;
    };

    // 底层管理者
    class Manager : public AbstractManager
    {
    public:
        void handleRequest(RequestType type) override
        {
            switch (type)
            {
            case RequestType::QingJia:
                std::cout << "请假: 同意请假，好好休息~~~" << std::endl;
                break;
            case RequestType::ZhangXin:
                std::cout << "涨薪: 这个我得请示一下咱们CEO..." << " ====> ";
                m_next->handleRequest(type);
                break;
            case RequestType::CiZhi:
                std::cout << "辞职: 我给你向上级反应一下..." << " ====> ";
                m_next->handleRequest(type);
                break;
            default:
                break;
            }
        }
    };

    // CEO
    class CEO : public AbstractManager
    {
    public:
        void handleRequest(RequestType type) override
        {
            switch (type)
            {
            case RequestType::QingJia:
                std::cout << "请假: 同意请假, 下不为例..." << std::endl;
                break;
            case RequestType::ZhangXin:
                std::cout << "涨薪: 你工资不少了, 给你个购物券吧..." << std::endl;
                break;
            case RequestType::CiZhi:
                std::cout << "辞职: 这个我得问问咱们老板..." << " ====> ";
                m_next->handleRequest(type);
                break;
            default:
                break;
            }
        }
    };

    // BOSS
    class Boss : public AbstractManager
    {
    public:
        void handleRequest(RequestType type) override
        {
            switch (type)
            {
            case RequestType::QingJia:
                std::cout << "请假: 只有工作才能实现人生价值，回去好好坚守岗位！！！" << std::endl;
                break;
            case RequestType::ZhangXin:
                std::cout << "涨薪: 钱财乃身外之物, 要视其如粪土!!!" << std::endl;
                break;
            case RequestType::CiZhi:
                std::cout << "辞职: 巴洛克工作社就是你的家, 这次把你留下, 下次别再提了!!!" << std::endl;
                break;
            default:
                break;
            }
        }
    };

    // 提交请求的类
    class DaCongMing
    {
    public:
        void request(RequestType type, AbstractManager *manager) { manager->handleRequest(type); }
    };
} // namespace Model_Chain
