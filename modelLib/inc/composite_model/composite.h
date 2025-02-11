#pragma once

#include <stdafx.h>

namespace Model_Composite
{
    using std::string;

    // Component（抽象组件）
    class Component : public std::enable_shared_from_this<Component>
    {
    protected:
        std::weak_ptr<Component> m_parent; // 父节点指针 // 避免循环引用
    public:
        virtual ~Component() = default;
        virtual void Operation() const = 0;
        virtual void Add(std::shared_ptr<Component> component) {}
        virtual void Remove(std::shared_ptr<Component> component) {}
        virtual std::shared_ptr<Component> GetChild(int index) const { return nullptr; }

        void SetParent(std::shared_ptr<Component> parent) { m_parent = parent; }
        std::shared_ptr<Component> GetParent() const { return m_parent.lock(); }
    };

    // Leaf（叶子节点）
    class Leaf : public Component
    {
    public:
        void Operation() const override { std::cout << "Leaf Operation" << std::endl; }
    };

    // Composite（组合节点）
    class Composite : public Component
    {
    private:
        std::list<std::shared_ptr<Component>> m_children;

    public:
        void Operation() const override
        {
            std::cout << "Composite Operation" << std::endl;
            for (const auto &child : m_children)
                child->Operation();
        }

        void Add(std::shared_ptr<Component> component) override
        {
            m_children.push_back(component);
            component->SetParent(shared_from_this());
        }

        void Remove(std::shared_ptr<Component> component) override
        {
            m_children.remove(component);
            component->SetParent(nullptr);
        }

        std::shared_ptr<Component> GetChild(int index) const override
        {
            if (index < 0 || index >= m_children.size())
                return nullptr;
            auto it = m_children.begin();
            std::advance(it, index);
            return *it;
        }
    };
} // namespace Model_Composite
