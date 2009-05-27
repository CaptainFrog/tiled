/*
 * Tiled Map Editor (Qt)
 * Copyright 2009 Tiled (Qt) developers (see AUTHORS file)
 *
 * This file is part of Tiled (Qt).
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#include "newtilesetdialog.h"
#include "ui_newtilesetdialog.h"

#include "tileset.h"

using namespace Tiled;
using namespace Tiled::Internal;

NewTilesetDialog::NewTilesetDialog(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::NewTilesetDialog)
{
    mUi->setupUi(this);
}

NewTilesetDialog::~NewTilesetDialog()
{
    delete mUi;
}

Tileset *NewTilesetDialog::createTileset() const
{
    const QString name = mUi->name->text();
    const QString image = mUi->image->text();
    const int tileWidth = mUi->tileWidth->value();
    const int tileHeight = mUi->tileHeight->value();
    const int spacing = mUi->spacing->value();
    // TODO: Add support for margin
    //const int margin = mUi->margin->value();

    Tileset *tileset = new Tileset(name,
                                   tileWidth,
                                   tileHeight,
                                   spacing);
    tileset->loadFromImage(image);
    return tileset;
}

void NewTilesetDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        mUi->retranslateUi(this);
        break;
    default:
        break;
    }
}