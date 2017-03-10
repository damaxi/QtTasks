#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <array>

class Engine : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString player READ player WRITE setPlayer NOTIFY playerChanged)
public:
  explicit Engine(QObject *parent = 0);

  QString player() const;
  Q_INVOKABLE int maxSize() const;
  Q_INVOKABLE bool isWon(uint cell);
  Q_INVOKABLE void reset();
  Q_INVOKABLE bool isDraw() const;

signals:
  void playerChanged();

public slots:
  void setPlayer(const QString &player);

private:
  bool check() const;
  bool finishCondition(int &sum) const;

  QString m_player;
  const int m_maxSize;
  std::array<int, 9> m_cellArray;
  static const QStringList PLAYERS;
};

#endif // ENGINE_H
