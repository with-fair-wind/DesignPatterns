#include <Demo/demo_composite.h>

namespace Demo_Composite
{
    void demo_v1()
    {
        using namespace Model_Composite;

        std::shared_ptr<Component> leaf1 = std::make_shared<Leaf>();
        std::shared_ptr<Component> leaf2 = std::make_shared<Leaf>();
        std::shared_ptr<Component> composite = std::make_shared<Composite>();

        composite->Add(leaf1);
        composite->Add(leaf2);

        composite->Operation();

        // 检查父节点
        if (auto parent = leaf1->GetParent())
            std::cout << "Leaf1 has a parent." << std::endl;
    }
} // namespace Demo_Composite