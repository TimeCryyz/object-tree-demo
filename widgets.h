#ifndef WIDGETS_H
#define WIDGETS_H

#include <QTextStream>
#include <QStringConverter>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

inline void logMsg(const QString &msg)
{
    QTextStream out(stdout);
    out.setEncoding(QStringConverter::Utf8);
    out << msg << "\n";
    out.flush();
}

class LogLabel : public QLabel
{
public:
    explicit LogLabel(const QString &text, QWidget *parent = nullptr)
        : QLabel(text, parent)
    {
        logMsg("[CREATE] LogLabel \"" + text + "\"");
    }

    ~LogLabel() override
    {
        logMsg("[DESTROY] LogLabel \"" + text() + "\"");
    }
};

class LogLineEdit : public QLineEdit
{
public:
    explicit LogLineEdit(QWidget *parent = nullptr)
        : QLineEdit(parent)
    {
        logMsg("[CREATE] LogLineEdit");
    }

    ~LogLineEdit() override
    {
        logMsg("[DESTROY] LogLineEdit");
    }
};

class LogPanel : public QFrame
{
public:
    explicit LogPanel(const QString &name, QWidget *parent = nullptr)
        : QFrame(parent)
    {
        setObjectName(name);
        setFrameShape(QFrame::Box);
        logMsg("[CREATE] LogPanel \"" + name + "\"");
    }

    ~LogPanel() override
    {
        logMsg("[DESTROY] LogPanel \"" + objectName() + "\"");
    }
};

class LogButton : public QPushButton
{
public:
    explicit LogButton(const QString &text, QWidget *parent = nullptr)
        : QPushButton(text, parent)
    {
        logMsg("[CREATE] LogButton \"" + text + "\"");
    }

    ~LogButton() override
    {
        logMsg("[DESTROY] LogButton \"" + text() + "\"");
    }
};

#endif // WIDGETS_H