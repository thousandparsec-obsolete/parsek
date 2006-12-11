#include <QString>
#include "converters.h"

QString secondsToDHMS(const int seconds)
{
  int d = 0;
  int h = 0;
  int m = 0;
  int s = seconds;

  if (s >= 86400) {
    d = s / 86400;
    s = s % 86400;
  }
  if (s >= 3600) {
    h = s / 3600;
    s = s % 3600;
  }
  if (s >= 60) {
    m = s / 60;
    s = s % 60;
  }
  return QString::number(d) + "d " + QString::number(h) + "h "
         + QString::number(m) + "m " + QString::number(s) + 's';
}
