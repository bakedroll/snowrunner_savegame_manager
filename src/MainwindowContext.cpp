#include "MainwindowContext.h"

MainwindowContext::MainwindowContext() :
  m_errorNoSavegamePath(false),
  m_isUserIDWindowVisible(false)
{
  if (!m_savegameManager.initialize())
  {
    raiseErrorNoSavegamePath();
    return;
  }

  if (m_savegameManager.getSteamUserIds().size() > 1 && m_savegameManager.getCurrentUserId().isEmpty())
  {
    setIsUserIdWindowVisible(true);
  }

  // m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
}

void MainwindowContext::setCurrentSteamUserId(const QString& userId)
{
  m_savegameManager.setCurrentUserId(userId);
  setIsUserIdWindowVisible(false);

  Q_EMIT selectedUserIdChanged();
}

void MainwindowContext::setIsUserIdWindowVisible(bool visible)
{
  m_isUserIDWindowVisible = visible;
  Q_EMIT isUserIdWindowVisibleChanged();
}

QList<QObject*> MainwindowContext::snapshotItems() const
{
  QList<QObject*> result;
  for (const auto& item : m_snapshotItems)
  {
    result.push_back(item.get());
  };
  return result;
}

QStringList MainwindowContext::steamUserIds() const
{
  return m_savegameManager.getSteamUserIds();
}

bool MainwindowContext::errorNoSavegamePath() const
{
  return m_errorNoSavegamePath;
}

bool MainwindowContext::isUserIdWindowVisible() const
{
  return m_isUserIDWindowVisible;
}

bool MainwindowContext::isUserIdBarVisible() const
{
  return m_savegameManager.getSteamUserIds().size() > 1;
}

QString MainwindowContext::selectedUserId() const
{
  return m_savegameManager.getCurrentUserId();
}

void MainwindowContext::raiseErrorNoSavegamePath()
{
  m_errorNoSavegamePath = true;
  Q_EMIT errorNoSavegamePathChanged();
}
