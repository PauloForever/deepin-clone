/*
 * Copyright (C) 2017 ~ 2017 Deepin Technology Co., Ltd.
 *
 * Author:     zccrs <zccrs@live.com>
 *
 * Maintainer: zccrs <zhangjide@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "utilitylistdeviceitem.h"
#include "helper.h"

#include <QProgressBar>
#include <QLabel>
#include <QVBoxLayout>

UtilityListDeviceItem::UtilityListDeviceItem(QWidget *parent)
    : UtilityListItem(parent)
{
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widget);

    m_progressBar = new QProgressBar(widget);
    m_progressBar->setRange(0, 100);
    m_progressBar->setTextVisible(false);
    m_sizeLabel = new QLabel(widget);

    layout->addWidget(m_sizeLabel, 0, Qt::AlignRight);
    layout->addWidget(m_progressBar, 0, Qt::AlignRight);

    addWidget(widget, 0, Qt::AlignRight);
}

void UtilityListDeviceItem::setSize(qint64 used, qint64 total)
{
    m_sizeLabel->setText(QString("%1/%2").arg(Helper::sizeDisplay(used)).arg(Helper::sizeDisplay(total)));
    m_progressBar->setValue(100 * ((used / 1000.0) / (total / 1000.0)));
}
