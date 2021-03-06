#ifndef VSFTPCONFIG_H
# define VSFTPCONFIG_H

#include "abstractauthentication.h"
#include "vsftpdparser.h"
#include "IServerConfigurationProvider.h"
#include "servicemanager.h"

class VsftpdConfigHandler : public IServerConfigurationProvider
{
public:
    VsftpdConfigHandler(QString serverName, QString serverAddr, QString fileName = DEFAULT_CONFIG_VSFTP_FILE, QString serverBinPath = DEFAULT_BIN_PATH_VSFTP);
    ~VsftpdConfigHandler();

    // Network
    QString getServerName() const;
    void    setServerName(const QString & name);
    QString getServerAddr() const;
    quint16 getServerPort() const;
    void    setServerPort(quint16 port);
    INTERNET_PROTOCOL::ip getInternetProtocol() const;
    void setInternetProtocol(INTERNET_PROTOCOL::ip ip);
    quint16 getIdleTimeout() const;
    void setIdleTimeout(quint16 timeout);
    quint16 getDataConnectionTimeout() const;
    void setDataConnectionTimeout(quint16 timeout);

    // User
    bool isUsingSystemUser() const;
    void useSystemUser(bool use);
    bool isAnonymousAllowed() const;
    void allowAnonymous(bool allow);
    bool isAnonymousUploadAllowed() const;
    void allowAnonymousUpload(bool allow);
    bool isAnonymousCreateDirAllowed() const;
    void allowAnonymousCreateDir(bool allow);

    // Virtual User Management
    void setVirtualUserAuthentication(VIRTUAL_USER_AUTHENTICATION::auth mode);
    VIRTUAL_USER_AUTHENTICATION::auth getVirtualUserAuthentication() const;
    void addVirtualUser(const QString & user, const QString & password);
    void remVirtualUser(const QString & user);
    QStringList virtualUsers() const;

    // Misc
    QString getWelcomeMessage() const;
    void setWelcomeMessage(const QString & message);

    // Log
    QString getLogFile() const;

    // Start/stop
    void start() const;
    void stop() const;
    void restart() const;

    // fichier de conf
    QString exportConfiguration() const;
    void importConfiguration(const QString &configuration);
    void resetConfiguration();

private:
    QString	m_serverName;
    QString	m_serverAddr;
    VsftpdParser m_parser;
    QString	m_serverPath;
    QString m_serviceName;
    AbstractAuthentication * m_authentificator;
};

#endif // VSFTPCONFIG_H
