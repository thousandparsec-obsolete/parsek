/* loggerwidget.cpp

  Copyright (c) 2007   Jure Repinc (jlp@holodeck1.com)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#include "loggerwidget.h"
#include "loggerwidget.moc"
#include <QString>
#include <cstdarg>

LoggerWidget::LoggerWidget(QWidget *parent)
            : QWidget(parent)
{
    setupUi(this);
}

LoggerWidget::~LoggerWidget()
{
}

void LoggerWidget::error(char* mesg, ...)
{
    QString message;
    va_list ap;
    va_start(ap, mesg);
    message.vsprintf(mesg, ap);
    va_end(ap);
    QString fullmessage = "EE: " + message;
    logView->append(fullmessage);
}

void LoggerWidget::warning(char* mesg, ...)
{
    QString message;
    va_list ap;
    va_start(ap, mesg);
    message.vsprintf(mesg, ap);
    va_end(ap);
    QString fullmessage = "WW: " + message;
    logView->append(fullmessage);
}

void LoggerWidget::info(char* mesg, ...)
{
    QString message;
    va_list ap;
    va_start(ap, mesg);
    message.vsprintf(mesg, ap);
    va_end(ap);
    QString fullmessage = "II: " + message;
    logView->append(fullmessage);
}

void LoggerWidget::debug(char* mesg, ...)
{
    QString message;
    va_list ap;
    va_start(ap, mesg);
    message.vsprintf(mesg, ap);
    va_end(ap);
    QString fullmessage = "DD: " + message;
    logView->append(fullmessage);
}
