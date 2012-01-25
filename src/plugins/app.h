#ifndef APP_H
#define APP_H

#include "../pgplugin.h"

class App : public PGPlugin
{
    Q_OBJECT
public:
    explicit App();

signals:
    void s_clearCache();
    void s_clearHistory();
    void s_backHistory();
    void s_exitApp();

public slots:

    void clearCache(int scId, int ecId);
    void clearHistory(int scId, int ecId);
    void backHistory(int scId, int ecId);
    void exitApp(int scId, int ecId);

private:

    static App *m_app;
};

#endif // APP_H
