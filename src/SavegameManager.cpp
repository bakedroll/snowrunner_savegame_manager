#include "SavegameManager.h"

#include <QSettings>
#include <QDir>

static const QString s_snowrunnerId = "1465360";

SavegameManager::SavegameManager() = default;
SavegameManager::~SavegameManager() = default;

bool SavegameManager::initialize()
{
  const QSettings regpath("HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\Valve\\Steam", QSettings::NativeFormat);
  if (!regpath.contains("InstallPath"))
  {
    return false;
  }

  const auto path = regpath.value("InstallPath").toString();
  const auto userDataPath = QDir(path).filePath("userdata");

  if (!QDir().exists(userDataPath))
  {
    return false;
  }

  const QDir userDataDir(userDataPath);
  const auto userIds = userDataDir.entryInfoList(QDir::Filter::Dirs | QDir::Filter::NoDotAndDotDot);

  for (const auto& id : userIds)
  {
    QDir userDir(userDataDir.filePath(id.fileName()));
    if (userDir.exists(s_snowrunnerId))
    {
      m_userIds.emplace_back(id.fileName());
    }
  }

  if (m_userIds.empty())
  {
    return false;
  }

  m_steamUserPath = userDataPath;
  return true;
}

std::vector<QString> SavegameManager::getSteamUserIds() const
{
  return m_userIds;
}
