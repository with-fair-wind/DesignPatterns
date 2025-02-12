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
        std::cout << "=================" << std::endl;
        requester.request(LogLevel::INFO, "This is a INFO message.");
        std::cout << "=================" << std::endl;
        requester.request(LogLevel::ERROR, "This is a ERROR message.");
    }
} // namespace Demo_Chain