#pragma once

#include <stdafx.h>

namespace Model_Command
{
    // 命令接口
    class Command
    {
    public:
        virtual ~Command() {}
        virtual void Execute() = 0;
        virtual void Undo() = 0;
    };

    // 接收者类
    class TextEditor
    {
    public:
        void AppendText(const std::string &text) { content_ += text; }
        void RemoveText(size_t length)
        {
            if (length <= content_.size())
                content_.erase(content_.size() - length, length);
        }
        const std::string &GetContent() const { return content_; }

    private:
        std::string content_;
    };

    // 具体命令类
    class AppendCommand : public Command
    {
    public:
        AppendCommand(std::shared_ptr<TextEditor> editor, const std::string &text)
            : editor_(editor), text_(text) {}
        void Execute() override { editor_->AppendText(text_); }
        void Undo() override { editor_->RemoveText(text_.size()); }

    private:
        std::shared_ptr<TextEditor> editor_;
        std::string text_;
    };

    // 调用者类
    class CommandManager
    {
    public:
        void ExecuteCommand(std::unique_ptr<Command> command)
        {
            command->Execute();
            undoStack_.push(std::move(command));
            while (!redoStack_.empty())
                redoStack_.pop();
        }
        void Undo()
        {
            if (!undoStack_.empty())
            {
                auto command = std::move(undoStack_.top());
                undoStack_.pop();
                command->Undo();
                redoStack_.push(std::move(command));
            }
        }
        void Redo()
        {
            if (!redoStack_.empty())
            {
                auto command = std::move(redoStack_.top());
                redoStack_.pop();
                command->Execute();
                undoStack_.push(std::move(command));
            }
        }

    private:
        std::stack<std::unique_ptr<Command>> undoStack_;
        std::stack<std::unique_ptr<Command>> redoStack_;
    };

} // namespace Model_Command
