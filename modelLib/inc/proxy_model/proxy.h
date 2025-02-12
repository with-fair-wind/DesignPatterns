#pragma once

#include <stdafx.h>

namespace Model_Proxy
{
    using std::cout;
    using std::endl;

    // 代理类的基类
    class Communication
    {
    public:
        virtual void communicate() = 0;
        virtual ~Communication() {}
    };

    // 子类 - 讲话的类
    class Speaker : public Communication
    {
    public:
        void communicate()
        {
            cout << "开始说话..." << endl;
            cout << "通话时发生了一些列的表情变化..." << endl;
        }
    };

    // 代理类
    class DenDenMuShi : public Communication
    {
    public:
        ~DenDenMuShi()
        {
            if (m_speaker)
            {
                delete m_speaker;
                m_speaker = nullptr;
            }
        }

        bool isStart() const { return m_isStart; }
        void setStart(bool flag) { m_isStart = flag; }

        void communicate() override
        {

            if (CheckAccess())
            {
                m_speaker->communicate();
                LogAccess();
            }
        }

    private:
        bool CheckAccess()
        {
            // 代理可以在调用真实主题的方法之前进行一些检查
            m_isStart = true;
            std::cout
                << "电话虫开始实时模仿通话者的语言和表情..." << std::endl;
            return m_isStart;
        }

        void LogAccess()
        {
            // 代理可以在调用真实主题的方法之后进行一些日志记录
            std::cout << "Proxy: 通话结束" << std::endl;
        }

    private:
        bool m_isStart = false;
        Speaker *m_speaker = new Speaker;
    };
} // namespace Model_Proxy
