/*
 *  Copyright 2011 Wolfgang Koller - http://www.gofg.at/
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef GEOLOCATION_H
#define GEOLOCATION_H

#include "../pgplugin.h"

#ifdef MOBILE
#include <QGeoPositionInfoSource>
#include <QGeoPositionInfo>
#include <QList>

QTM_USE_NAMESPACE

#endif
class Geolocation : public PGPlugin
{
    Q_OBJECT
public:
    explicit Geolocation();

    void init();

signals:

public slots:
    void getCurrentPosition( int scId, int ecId, QVariantMap p_options );

protected slots:
#ifdef MOBILE
    void positionUpdated( const QGeoPositionInfo &update );
#else
     void positionUpdated();
#endif
    void updateTimeout();

private:
#ifdef MOBILE
    QGeoPositionInfoSource *m_geoPositionInfoSource;
#endif
    QList<int> m_successCallbacks;
    QList<int> m_errorCallbacks;

    static Geolocation *m_geolocation;
};

#endif // GEOLOCATION_H
