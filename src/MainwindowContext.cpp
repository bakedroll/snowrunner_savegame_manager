#include "MainwindowContext.h"

MainwindowContext::MainwindowContext()
  : m_errorNoSavegamePath(false)
{
  if (!m_savegameManager.initialize())
  {
    raiseErrorNoSavegamePath();
    return;
  }

  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
  m_snapshotItems.emplace_back(std::make_shared<SnapshotItem>());
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

bool MainwindowContext::errorNoSavegamePath() const
{
  return m_errorNoSavegamePath;
}

void MainwindowContext::raiseErrorNoSavegamePath()
{
  m_errorNoSavegamePath = true;
  Q_EMIT errorNoSavegamePathChanged();
}
