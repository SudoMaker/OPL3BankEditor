/*
 * OPL Bank Editor by Wohlstand, a free tool for music bank editing
 * Copyright (c) 2016-2019 Vitaly Novichkov <admin@wohlnet.ru>
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

#ifndef OPL_SERIAL_PORT_H
#define OPL_SERIAL_PORT_H

#ifdef ENABLE_HW_OPL_SERIAL_PORT

#include "opl_chip_base.h"

class QSerialPort;
class QString;

///
class OPL_SerialPort : public OPLChipBaseT<OPL_SerialPort>
{
public:
    OPL_SerialPort();
    ~OPL_SerialPort() override;

    bool connectPort(const QString &name, unsigned baudRate);

    bool canRunAtPcmRate() const override { return false; }
    void setRate(uint32_t /*rate*/) override {}
    void reset() override {}
    void writeReg(uint16_t addr, uint8_t data) override;
    void nativePreGenerate() override {}
    void nativePostGenerate() override {}
    void nativeGenerate(int16_t *frame) override;
    const char *emulatorName() override;
    ChipType chipType() override;

private:
    QSerialPort *m_port;
};

#endif // ENABLE_HW_OPL_SERIAL_PORT

#endif // OPL_SERIAL_PORT_H
