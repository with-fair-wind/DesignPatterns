#include <Demo/demo_chain.h>

namespace Demo_Chain
{
    using namespace Model_Chain;
    void demo_v1()
    {
        std::shared_ptr<Logger> errorLogger = std::make_shared<ErrorLogger>(LogLevel::ERROR);
        std::shared_ptr<Logger> fileLogger = std::make_shared<FileLogger>(LogLevel::INFO);
        std::shared_ptr<Logger> consoleLogger = std::make_shared<ConsoleLogger>(LogLevel::DEBUG);

        consoleLogger->setNext(fileLogger);
        fileLogger->setNext(errorLogger);

        Requester requester(consoleLogger);
        requester.request(LogLevel::DEBUG, "This is a DEBUG message.");
        requester.request(LogLevel::INFO, "This is a INFO message.");
        requester.request(LogLevel::ERROR, "This is a ERROR message.");
        std::cout << "=====================" << std::endl;
        requester.setLogger(fileLogger);
        requester.request(LogLevel::DEBUG, "This is a DEBUG message.");
        requester.request(LogLevel::INFO, "This is a INFO message.");
        requester.request(LogLevel::ERROR, "This is a ERROR message.");
        std::cout << "=====================" << std::endl;
        requester.setLogger(errorLogger);
        requester.request(LogLevel::DEBUG, "This is a DEBUG message.");
        requester.request(LogLevel::INFO, "This is a INFO message.");
        requester.request(LogLevel::ERROR, "This is a ERROR message.");
    }

    void demo_v2()
    {
        Manager *manager = new Manager;
        CEO *ceo = new CEO;
        Boss *boss = new Boss;
        manager->setNext(ceo);
        ceo->setNext(boss);

        // 创建员工的实例
        DaCongMing *boy = new DaCongMing;
        std::cout << "大聪明直接将请求提交给顶头上司" << std::endl;
        boy->request(RequestType::CiZhi, manager);
        boy->request(RequestType::ZhangXin, manager);
        boy->request(RequestType::QingJia, manager);

        std::cout << "大聪明直接将请求提交给CEO" << std::endl;
        boy->request(RequestType::CiZhi, ceo);
        boy->request(RequestType::ZhangXin, ceo);
        boy->request(RequestType::QingJia, ceo);

        std::cout << "大聪明直接将请求提交给boss" << std::endl;
        boy->request(RequestType::CiZhi, boss);
        boy->request(RequestType::ZhangXin, boss);
        boy->request(RequestType::QingJia, boss);

        delete boy;
        delete manager;
        delete ceo;
        delete boss;
    }
} // namespace Demo_Chain