/*
 * Route.cpp
 *
 *  Created on: 23 oct. 2012
 *      Author: laplace
 */

#include "Route.h"

namespace Routing {

Route::Route(const QString& name) :
    _name(name) {
}

Route::~Route() {
}

QString                Route::getName()                           const                   { return _name;                 }
QString                Route::getUri()                            const                   { return _uri;                  }
QString                Route::getModule()                         const                   { return _module;               }
QString                Route::getProcessor()                      const                   { return _processor;            }
QString                Route::getRequirement(const QString& name) const                   { return _requirements[name];   }
QMap<QString, QString> Route::getRequirements()                   const                   { return _requirements;         }

void                   Route::setName(const QString& name)                                { _name = name;                 }
void                   Route::setUri(const QString& uri)                                  { _uri = uri;                   }
void                   Route::setModule(const QString& module)                            { _module = module;             }
void                   Route::setProcessor(const QString& processor)                      { _processor = processor;       }
void                   Route::setRequirement(const QString& name, const QString value)    { _requirements[name] = value;  }
void                   Route::setRequirements(const QMap<QString, QString>& requirements) { _requirements = requirements; }

QString Route::toString() const {
    return "Route " + _name + " uri: " + _uri;
}

QDebug operator<<(QDebug debug, const Route& route) {
    return debug << route.toString();
}

QDebug operator<<(QDebug debug, Route* route) {
    return debug << route->toString();
}

} // namespace Rounting

