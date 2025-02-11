#pragma once

#include <stdafx.h>

namespace Model_Adapter
{
    using std::cout;
    using std::endl;
    using std::string;

#define Version_1
    class Foreigner
    {
    public:
        virtual string confession() = 0;
        void setResult(string res) { cout << "Panda say: " << res << endl; }
        virtual ~Foreigner() {}
    };

    class American : public Foreigner
    {
    public:
        string confession() override { return "我有罪, 我不要脸!!!"; }
    };

    class French : public Foreigner
    {
    public:
        string confession() override { return "我是强盗, 我该死!!!"; }
    };

    class Panda
    {
    public:
        void recvMessage(string msg) { cout << msg << endl; }
        string sendMessage() { return string("强盗、凶手、罪人是不可能被宽恕和原谅的！"); }
    };

#ifdef Version_1
    // 适配器类和熊猫类是关联关系
    // 适配器类
    class AbstractChopper
    {
    public:
        AbstractChopper(Foreigner *foreigner) : m_foreigner(foreigner) {}
        virtual void translateToPanda() = 0;
        virtual void translateToHuman() = 0;
        virtual ~AbstractChopper() {}

    protected:
        Panda m_panda;
        Foreigner *m_foreigner;
    };

    class EnglishChopper : public AbstractChopper
    {
    public:
        using AbstractChopper::AbstractChopper;
        void translateToPanda()
        {
            string msg = m_foreigner->confession();
            m_panda.recvMessage("美国人说: " + msg);
        }
        void translateToHuman()
        {
            string msg = m_panda.sendMessage();
            m_foreigner->setResult("美国佬: " + msg);
        }
    };

    class FrechChopper : public AbstractChopper
    {
    public:
        using AbstractChopper::AbstractChopper;
        void translateToPanda()
        {
            string msg = m_foreigner->confession();
            m_panda.recvMessage("法国人说: " + msg);
        }
        void translateToHuman()
        {
            string msg = m_panda.sendMessage();
            m_foreigner->setResult("法国佬: " + msg);
        }
    };

#elif defined(Version_2)
    // 适配器类和熊猫类是继承关系，若熊猫类有子类依然建议使用关联关系
    // 适配器类
    class AbstractChopper : public Panda
    {
    public:
        AbstractChopper(Foreigner *foreigner) : m_foreigner(foreigner) {}
        virtual void translateToPanda() = 0;
        virtual void translateToHuman() = 0;
        virtual ~AbstractChopper() {}

    protected:
        Foreigner *m_foreigner;
    };

    class EnglishChopper : public AbstractChopper
    {
    public:
        using AbstractChopper::AbstractChopper;
        void translateToPanda()
        {
            string msg = m_foreigner->confession();
            recvMessage("美国人说: " + msg);
        }
        void translateToHuman()
        {
            string msg = sendMessage();
            m_foreigner->setResult("美国佬: " + msg);
        }
    };

    class FrechChopper : public AbstractChopper
    {
    public:
        using AbstractChopper::AbstractChopper;
        void translateToPanda()
        {
            string msg = m_foreigner->confession();
            recvMessage("法国人说: " + msg);
        }
        void translateToHuman()
        {
            string msg = sendMessage();
            m_foreigner->setResult("法国佬: " + msg);
        }
    };
#endif
    // Version_3 : 让适配器类继承它要为之提供服务器的类，也就是这个例子中的外国人类和熊猫类(多重继承)（如果外国人来没有子类可以使用这种方式）
} // namespace Model_Adapter
