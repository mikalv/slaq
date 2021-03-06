#pragma once

#include <QString>
#include <QRegularExpression>

class User;
class ChatsModel;
class Chat;

class MessageFormatter
{
public:
    MessageFormatter();

    void replaceUserInfo(User *user, QString &message);
    void replaceTargetInfo(QString &message);
    void replaceChannelInfo(ChatsModel *chatModel, QString &message);
    void replaceSpecialCharacters(QString &message);
    void replaceLinks(QString &message);
    void replaceMarkdown(QString &message);
    void replaceEmoji(QString &message);
    void replaceAll(ChatsModel* chat,  QString &message);
    void doReplaceChannelInfo(Chat *chat, QString &message);

private:
    QRegularExpression m_labelPattern;
    QRegularExpression m_plainPattern;
    QRegularExpression m_mailtoPattern;

    QRegularExpression m_italicPattern;
    QRegularExpression m_boldPattern;
    QRegularExpression m_strikePattern;
    QRegularExpression m_codePattern;
    QRegularExpression m_codeBlockPattern;

    QRegularExpression m_variableLabelPattern;
    QRegularExpression m_variablePattern;
    QRegularExpression m_emojiPattern;
    QRegularExpression m_channelPattern;
};

