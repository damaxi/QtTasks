#ifndef MORSECONVERTER_H
#define MORSECONVERTER_H

#include <QString>

template <typename T, typename U> struct QPair;
template <typename T> class QVector;

class MorseConverter {
public:
  MorseConverter();

  const QString code(QString &text) const;
  const QString decode(QString &text) const;

private:
  const QChar findCode(const QString &code) const;
  const QString findChar(const QChar &character) const;

  const QString m_letterSeparator;
  const QString m_wordSeparator;

  static const QVector<QPair<QChar, QString>> MORSE_CODE;
};

#endif // MORSECONVERTER_H
