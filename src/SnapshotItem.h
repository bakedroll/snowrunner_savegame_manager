#pragma once

#include <QObject>

class SnapshotItem : public QObject
{
  Q_OBJECT

public:
  Q_INVOKABLE
  QString test() const;
};
