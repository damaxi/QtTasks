#include "morseconverter.h"

#include <QPair>
#include <QSet>
#include <QVector>

MorseConverter::MorseConverter()
    : m_letterSeparator(' '), m_wordSeparator("  ") {}

const QString MorseConverter::code(QString &&text) const {
  QStringList words = text.split(' ', QString::SkipEmptyParts);
  QString result;
  QString tmp;
  foreach (auto &word, words) {
    for (auto iter = word.begin(); iter != word.end(); ++iter) {
      if (iter->isLower())
        tmp = findChar(*iter);
      else
        tmp = findChar(iter->toLower());

      if (!tmp.isEmpty()) {
        result.append(tmp);
        result.append(QChar::Space);
      }
    }
    if (result.at(result.length() - 1) == QChar::Space)
      result.append(QChar::Space);
    else {
      result.append(QChar::Space);
      result.append(QChar::Space);
    }
  }

  return result;
}

const QString MorseConverter::decode(QString &&text) const {
  QStringList words = text.split(m_wordSeparator, QString::SkipEmptyParts);
  QStringList letters;
  QString result;
  foreach (auto &word, words) {
    letters = word.split(m_letterSeparator, QString::SkipEmptyParts);
    for (auto iter = letters.begin(); iter != letters.end(); ++iter) {
      result.append(findCode(*iter));
    }
    result.append(QChar::Space);
  }

  return result;
}

bool MorseConverter::validate(QString &&text) const {
  for (auto iter = text.begin(); iter != text.end(); ++iter) {
    if (MORSE_VALIDATOR.constFind(*iter) == MORSE_VALIDATOR.constEnd())
      return false;
  }
  return true;
}

const QChar MorseConverter::findCode(const QString &code) const {
  foreach (auto &pair, MORSE_CODE) {
    if (pair.second == code)
      return pair.first;
  }

  return QChar::Space;
}

const QString MorseConverter::findChar(const QChar &character) const {
  foreach (auto &pair, MORSE_CODE) {
    if (pair.first == character)
      return pair.second;
  }

  return QString("");
}

const QVector<QPair<QChar, QString>> MorseConverter::MORSE_CODE(
    {{'a', ".--"},    {'b', "-..."},   {'c', "-.-."},   {'d', "-.."},
     {'e', "."},      {'f', "..-."},   {'g', "--."},    {'h', "...."},
     {'i', ".."},     {'j', ".---"},   {'k', "-.-"},    {'l', ".-.."},
     {'m', "--"},     {'n', "-."},     {'o', "---"},    {'p', ".--."},
     {'q', "--.-"},   {'r', ".-."},    {'s', "..."},    {'t', "-"},
     {'u', "..-"},    {'v', "...-"},   {'w', ".--"},    {'x', "-..-"},
     {'y', "-.--"},   {'z', "--.."},   {'0', "-----"},  {'1', ".----"},
     {'2', "..---"},  {'3', "...--"},  {'4', "....-"},  {'5', "....."},
     {'6', "-...."},  {'7', "--..."},  {'8', "---.."},  {'9', "----."},
     {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'/', "-..-."},
     {'@', ".--.-."}});

const QSet<QChar> MorseConverter::MORSE_VALIDATOR({{QChar::Space},
                                                   {QChar('.')},
                                                   {QChar('-')}});
