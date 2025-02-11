#include <Demo/demo_decorator.h>

namespace Demo_Decorator
{
    void demo_v1()
    {
        using namespace Model_Decorator;
        std::shared_ptr<Message> message = std::make_shared<SimpleMessage>("Hello, World!");
        std::shared_ptr<Message> encryptedMessage = std::make_shared<EncryptedMessage>(message);
        std::shared_ptr<Message> timestampedMessage = std::make_shared<TimestampedMessage>(encryptedMessage);

        timestampedMessage->print();
    }

    void demo_v2()
    {
        using namespace Model_Decorator;
        Soldier *soldier = new Teach;
        DevilFruit *dark = new DarkFruit;
        DevilFruit *quake = new QuakeFruit;
        DevilFruit *pie = new PieFruit;
        dark->enchantment(soldier);
        quake->enchantment(dark);
        pie->enchantment(quake);
        pie->fight();

        delete soldier;
        delete dark;
        delete quake;
        delete pie;
    }
} // namespace Demo_Decorator