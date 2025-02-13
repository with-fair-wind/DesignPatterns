#pragma once

#include <stdafx.h>

namespace Model_Command
{
    // 厨师 -> 命令的执行者, 收不到命令是不会工作的
    class CookerZeff
    {
    public:
        void makeDSX() { std::cout << "开始烹饪地三鲜..."; }
        void makeYXRS() { std::cout << "开始烹饪鱼香肉丝..."; }
        void makeGBJD() { std::cout << "开始烹饪宫保鸡丁..."; }
        void makeHSPG() { std::cout << "开始烹饪红烧排骨..."; }
    };

    // 命令
    class AbstractCommand
    {
    public:
        AbstractCommand(std::shared_ptr<CookerZeff> zeff) : m_cooker(zeff) {}
        virtual void excute() = 0;
        virtual std::string name() = 0;
        virtual ~AbstractCommand() {}

    protected:
        std::shared_ptr<CookerZeff> m_cooker = nullptr;
    };

    class DSXCommand : public AbstractCommand
    {
    public:
        using AbstractCommand::AbstractCommand;
        void excute() override { m_cooker->makeDSX(); }
        std::string name() override { return "地三鲜"; }
    };

    class GBJDCommand : public AbstractCommand
    {
    public:
        using AbstractCommand::AbstractCommand;
        void excute() override { m_cooker->makeGBJD(); }
        std::string name() override { return "宫保鸡丁"; }
    };

    class YXRSCommand : public AbstractCommand
    {
    public:
        using AbstractCommand::AbstractCommand;
        void excute() override { m_cooker->makeYXRS(); }
        std::string name() override { return "鱼香肉丝"; }
    };

    class HSPGCommand : public AbstractCommand
    {
    public:
        using AbstractCommand::AbstractCommand;
        void excute() override { m_cooker->makeHSPG(); }
        std::string name() override { return "红烧排骨"; }
    };

    // 服务员
    class WaiterLuffy
    {
    public:
        // 下单
        void setOrder(int index, std::shared_ptr<AbstractCommand> command)
        {
            std::cout << index << "号桌点了" << command->name() << std::endl;
            if (command->name() == "鱼香肉丝")
            {
                std::cout << "没有鱼了, 做不了鱼香肉丝, 点个别的菜吧..." << std::endl;
                return;
            }
            if (m_cmdList.find(index) == m_cmdList.end())
            {
                std::list<std::shared_ptr<AbstractCommand>> mylist{command};
                m_cmdList.insert(std::make_pair(index, mylist));
            }
            else
                m_cmdList[index].push_back(command);
        }
        // 撤销订单
        void cancelOrder(int index, std::shared_ptr<AbstractCommand> command)
        {
            if (m_cmdList.find(index) != m_cmdList.end())
            {
                m_cmdList[index].remove(command);
                std::cout << index << "号桌, 撤销了" << command->name() << std::endl;
            }
        }
        // 结账
        void checkOut(int index)
        {
            std::cout << "第[" << index << "]号桌的顾客点的菜是: 【";
            for (const auto &item : m_cmdList[index])
            {
                std::cout << item->name();
                if (item != m_cmdList[index].back())
                    std::cout << ",";
            }
            std::cout << "】" << std::endl;
        }
        // 发送通知 -> 要求厨师执行某些命令
        void notify(int index)
        {
            for (const auto &item : m_cmdList[index])
            {
                item->excute();
                std::cout << index << "号桌" << std::endl;
            }
        }

    private:
        std::map<int, std::list<std::shared_ptr<AbstractCommand>>> m_cmdList;
    };
} // namespace Model_Command
