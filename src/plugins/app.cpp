#include "app.h"

#include "../pluginregistry.h"
#include <QDebug>
// Create static instance of ourself
App *App::m_app = new App();

/**
 * Constructor - NOTE: Never do anything except registering the plugin
 */
App::App() : PGPlugin() {
    PluginRegistry::getRegistry()->registerPlugin( "com.phonegap.App", this );
}


void App::clearCache(int scId, int ecId){
    Q_UNUSED(ecId)
    Q_UNUSED(scId)
    emit s_clearCache();
}

void App::clearHistory(int scId, int ecId){
    Q_UNUSED(ecId)
    Q_UNUSED(scId)
    emit s_clearHistory();
}

void App::backHistory(int scId, int ecId){
    Q_UNUSED(ecId)
    Q_UNUSED(scId)
    emit s_backHistory();
}

void App::exitApp(int scId, int ecId){
    Q_UNUSED(ecId)
    Q_UNUSED(scId)
    qDebug()<<"exit";
    emit s_exitApp();
}
