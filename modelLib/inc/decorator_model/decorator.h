#pragma once

#include <stdafx.h>

namespace Model_Decorator
{
    // 抽象组件
    class Message
    {
    public:
        virtual ~Message() = default;
        virtual void print() const = 0;
    };

    // 具体组件
    class SimpleMessage : public Message
    {
    private:
        std::string text;

    public:
        SimpleMessage(const std::string &msg) : text(msg) {}
        void print() const override { std::cout << text << std::endl; }
    };

    // 装饰器
    class MessageDecorator : public Message
    {
    protected:
        std::shared_ptr<Message> message;

    public:
        MessageDecorator(std::shared_ptr<Message> msg) : message(msg) {}
        void print() const override { message->print(); }
    };

    // 具体装饰器A：加密消息
    class EncryptedMessage : public MessageDecorator
    {
    public:
        using MessageDecorator::MessageDecorator;
        void print() const override
        {
            std::cout << "Encrypted: ";
            MessageDecorator::print();
        }
    };

    // 具体装饰器B：添加时间戳
    class TimestampedMessage : public MessageDecorator
    {
    public:
        using MessageDecorator::MessageDecorator;
        void print() const override
        {
            std::time_t now = std::time(nullptr);
            std::cout << std::ctime(&now) << ": ";
            MessageDecorator::print();
        }
    };
} // namespace Model_Decorator
