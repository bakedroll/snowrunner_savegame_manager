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
  Q_PROPERTY(QStringList steamUserIds READ steamUserIds NOTIFY steamUserIdsChanged)

  Q_PROPERTY(bool errorNoSavegamePath READ errorNoSavegamePath NOTIFY errorNoSavegamePathChanged)
  Q_PROPERTY(bool isUserIdWindowVisible READ isUserIdWindowVisible NOTIFY isUserIdWindowVisibleChanged)
  Q_PROPERTY(bool isUserIdBarVisible READ isUserIdBarVisible NOTIFY isUserIdBarVisibleChanged)
  Q_PROPERTY(QString selectedUserId READ selectedUserId NOTIFY selectedUserIdChanged)

  Q_INVOKABLE
  void setCurrentSteamUserId(const QString& userId);

  Q_INVOKABLE
  void setIsUserIdWindowVisible(bool visible);

  QList<QObject*> snapshotItems() const;
  QStringList steamUserIds() const;
  bool errorNoSavegamePath() const;
  bool isUserIdWindowVisible() const;
  bool isUserIdBarVisible() const;
  QString selectedUserId() const;

Q_SIGNALS:
  void snapshotItemsChanged();
  void steamUserIdsChanged();
  void errorNoSavegamePathChanged();
  void isUserIdWindowVisibleChanged();
  void isUserIdBarVisibleChanged();
  void selectedUserIdChanged();

private:
  void raiseErrorNoSavegamePath();

  std::vector<std::shared_ptr<SnapshotItem>> m_snapshotItems;

  SavegameManager m_savegameManager;

  bool m_errorNoSavegamePath;
  bool m_isUserIDWindowVisible;

};
