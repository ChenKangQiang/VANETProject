//
// Copyright (C) 2013 OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#ifndef __INETVEINS_IDEALLISTENING_H
#define __INETVEINS_IDEALLISTENING_H

#include "inetveins/physicallayer/base/packetlevel/ListeningBase.h"

namespace inetveins {

namespace physicallayer {

/**
 * This model doesn't specify any listening properties.
 */
class INETVEINS_API IdealListening : public ListeningBase
{
  public:
    IdealListening(const IRadio *radio, simtime_t startTime, simtime_t endTime, Coord startPosition, Coord endPosition);

    virtual std::ostream& printToStream(std::ostream& stream, int level) const override;
};

} // namespace physicallayer

} // namespace inetveins

#endif // ifndef __INETVEINS_IDEALLISTENING_H

