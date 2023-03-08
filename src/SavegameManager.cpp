#include "SavegameManager.h"

#include <QSettings>
#include <QDir>
#include <QTextStream>

static const QString s_snowrunnerId = "1465360";
static const QString s_userIdFilename = "./steamUserID.txt";

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
      m_userIds.push_back(id.fileName());
    }
  }

  if (m_userIds.empty())
  {
    return false;
  }

  if (m_userIds.size() == 1)
  {
    m_currentUserId = m_userIds.at(0);
  }
  else
  {
    const auto userId = loadUserIdFromFile();
    if (!userId.isEmpty())
    {
      for (const auto& id : m_userIds)
      {
        if (id == userId)
        {
          m_currentUserId = userId;
          break;
        }
      }
    }
  }

  m_steamUserPath = userDataPath;
  return true;
}

QStringList SavegameManager::getSteamUserIds() const
{
  return m_userIds;
}

void SavegameManager::setCurrentUserId(const QString& userId)
{
  m_currentUserId = userId;
  saveUserIdToFile(userId);
}

QString SavegameManager::getCurrentUserId() const
{
  return m_currentUserId;
}

QString SavegameManager::loadUserIdFromFile()
{
  QFile file(s_userIdFilename);
  if (!file.open(QIODevice::ReadOnly))
  {
    return "";
  }

  return file.readLine();
}

void SavegameManager::saveUserIdToFile(const QString& userId)
{
  QFile file(s_userIdFilename);
  if (!file.open(QIODevice::WriteOnly))
  {
    return;
  }

  QTextStream stream(&file);
  stream << userId;
}
