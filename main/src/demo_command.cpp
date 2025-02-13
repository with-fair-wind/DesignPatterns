#include <Demo/demo_command.h>

namespace Demo_Command
{
    using namespace Model_Command;
    void demo_v1()
    {
        auto editor = std::make_shared<TextEditor>();
        CommandManager manager;

        manager.ExecuteCommand(std::make_unique<AppendCommand>(editor, "Hello, "));
        manager.ExecuteCommand(std::make_unique<AppendCommand>(editor, "world!"));

        std::cout << "Content: " << editor->GetContent() << std::endl;
        manager.Undo();
        std::cout << "After undo: " << editor->GetContent() << std::endl;

        manager.Redo();
        std::cout << "After redo: " << editor->GetContent() << std::endl;
    }

    void demo_v2()
    {
        std::shared_ptr<CookerZeff> zeff = std::make_shared<CookerZeff>();
        std::unique_ptr<WaiterLuffy> luffy = std::make_unique<WaiterLuffy>();

        std::shared_ptr<AbstractCommand> yxrs = std::make_shared<YXRSCommand>(zeff);
        std::shared_ptr<AbstractCommand> dsx = std::make_shared<DSXCommand>(zeff);
        std::shared_ptr<AbstractCommand> gbjd = std::make_shared<GBJDCommand>(zeff);
        std::shared_ptr<AbstractCommand> hspg = std::make_shared<HSPGCommand>(zeff);

        std::cout << "顾客开始点餐" << std::endl;
        luffy->setOrder(1, yxrs);
        luffy->setOrder(1, dsx);
        luffy->setOrder(1, gbjd);
        luffy->setOrder(1, hspg);

        luffy->setOrder(2, hspg);
        luffy->setOrder(2, dsx);
        luffy->setOrder(2, gbjd);

        std::cout << "撤销订单=============" << std::endl;
        luffy->cancelOrder(1, dsx);
        std::cout << "开始下单 ++++++++++++++++" << std::endl;
        luffy->notify(1);
        luffy->notify(2);
        std::cout << "结账*******************" << std::endl;
        luffy->checkOut(1);
        luffy->checkOut(2);
    }
} // namespace Demo_Command
