#pragma once

#include <QStringList>

class SavegameManager
{
public:
  SavegameManager();
  virtual ~SavegameManager();

  bool initialize();

  QStringList getSteamUserIds() const;

  void setCurrentUserId(const QString& userId);
  QString getCurrentUserId() const;

private:
  static QString loadUserIdFromFile();
  static void saveUserIdToFile(const QString& userId);

  QString m_steamUserPath;
  QString m_currentUserId;

  QStringList m_userIds;

};
