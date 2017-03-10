#include "engine.h"

static const int CROSSES = 1;
static const int NOUGHTS = -1;

Engine::Engine(QObject *parent)
    : QObject(parent), m_player(PLAYERS[0]), m_maxSize(9), m_cellArray() {}

QString Engine::player() const { return m_player; }

int Engine::maxSize() const { return m_maxSize; }

bool Engine::isWon(uint cell) {
  QString nextPlayer;
  if (m_player == PLAYERS[0]) {
    m_cellArray[cell] = CROSSES;
    nextPlayer = PLAYERS[1];
  } else {
    m_cellArray[cell] = NOUGHTS;
    nextPlayer = PLAYERS[0];
  }
  if (check())
    return true;

  setPlayer(nextPlayer);
  return false;
}

void Engine::reset() { m_cellArray.fill(0); }

void Engine::setPlayer(const QString &player) {
  if (player == m_player)
    return;

  m_player = player;
  emit playerChanged();
}

bool Engine::check() const {
  int sum = 0;
  for (uint j = 0; j < 7; j += 3) {
    for (uint i = j; i < j + 3; ++i) {
      sum += m_cellArray[i];
    }
    if (finishCondition(sum))
      return true;
  }

  for (uint j = 0; j < 3; j += 1) {
    for (uint i = j; i < 9; i += 3) {
      sum += m_cellArray[i];
    }
    if (finishCondition(sum))
      return true;
  }

  for (uint j = 0; j < 3; j += 2) {
    for (uint i = j; i < 9 - j; i += (4 - j)) {
      sum += m_cellArray[i];
    }
    if (finishCondition(sum))
      return true;
  }

  return false;
}

bool Engine::isDraw() const {
  for (auto cell : m_cellArray) {
    if (cell == 0)
      return false;
  }

  return true;
}

bool Engine::finishCondition(int &sum) const {
  if (sum == 3 || sum == -3)
    return true;
  else
    sum = 0;

  return false;
}

const QStringList Engine::PLAYERS{{"crosses"}, {"noughts"}};
