#pragma once

#include <stdafx.h>

namespace Model_Chain
{
    enum class LogLevel
    {
        DEBUG,
        INFO,
        ERROR
    };

    class Logger
    {
    public:
        virtual ~Logger() = default;
        void setNext(std::shared_ptr<Logger> nextLogger) { m_next = nextLogger; }
        void logMessage(LogLevel level, const std::string &message)
        {
            if (m_level <= level)
                write(message);
            if (m_next)
                m_next->logMessage(level, message);
        }

    protected:
        LogLevel m_level;
        std::shared_ptr<Logger> m_next;
        virtual void write(const std::string &message) = 0;
    };

    class ConsoleLogger : public Logger
    {
    public:
        ConsoleLogger(LogLevel level) { m_level = level; }

    protected:
        void write(const std::string &message) override { std::cout << "Console Logger: " << message << std::endl; }
    };

    class FileLogger : public Logger
    {
    public:
        FileLogger(LogLevel level) { m_level = level; }

    protected:
        void write(const std::string &message) override { std::cout << "File Logger: " << message << std::endl; }
    };

    class ErrorLogger : public Logger
    {
    public:
        ErrorLogger(LogLevel level) { m_level = level; }

    protected:
        void write(const std::string &message) override { std::cerr << "Error Logger: " << message << std::endl; }
    };

    class Requester
    {
    public:
        Requester() = default;
        Requester(std::shared_ptr<Logger> logger) : m_logger{logger} {}
        void request(LogLevel level, const std::string &msg) { m_logger->logMessage(level, msg); }

    private:
        std::shared_ptr<Logger> m_logger{nullptr};
    };
} // namespace Model_Chain
