#pragma once

#include <QString>

#include <vector>

class SavegameManager
{
public:
  SavegameManager();
  virtual ~SavegameManager();

  bool initialize();

  std::vector<QString> getSteamUserIds() const;

private:
  QString m_steamUserPath;
  std::vector<QString> m_userIds;

};
