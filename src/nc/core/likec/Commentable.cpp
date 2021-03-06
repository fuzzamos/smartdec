//
// SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
// Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
// Alexander Fokin, Sergey Levin, Leonid Tsvetkov
//
// This file is part of SmartDec decompiler.
//
// SmartDec decompiler is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SmartDec decompiler is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
//

#include "Commentable.h"

#include <QStringList>

#include <nc/common/Foreach.h>

#include "PrintContext.h"

namespace nc {
namespace core {
namespace likec {

void Commentable::printComment(PrintContext &context) const {
    if (comment().isEmpty()) {
        return;
    } else {
        QStringList lines = comment().split('\n');

        if (lines.size() == 1) {
            context.out() << "/* " << lines.first() << " */" << endl;
        } else {
            context.out() << "/*" << endl;
            foreach (const QString &line, lines) {
                context.outIndent() << " * " << line << endl;
            }
            context.out() << " */" << endl;
        }
    }
}

} // namespace likec
} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
