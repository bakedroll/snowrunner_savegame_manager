#pragma once

#include <memory>
#include <vector>

#include <QObject>

#include "SnapshotItem.h"
#include "SavegameManager.h"

class MainwindowContext : public QObject
{
  Q_OBJECT

public:
  MainwindowContext();

  Q_PROPERTY(QList<QObject*> snapshotItems READ snapshotItems NOTIFY snapshotItemsChanged)
  Q_PROPERTY(bool errorNoSavegamePath READ errorNoSavegamePath NOTIFY errorNoSavegamePathChanged)

  QList<QObject*> snapshotItems() const;
  bool errorNoSavegamePath() const;

Q_SIGNALS:
  void snapshotItemsChanged();
  void errorNoSavegamePathChanged();

private:
  void raiseErrorNoSavegamePath();

  std::vector<std::shared_ptr<SnapshotItem>> m_snapshotItems;

  SavegameManager m_savegameManager;

  bool m_errorNoSavegamePath;

};
