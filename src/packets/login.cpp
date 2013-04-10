#include "login.hpp"

#include <QtCore/QDebug>

Login::Login(QString login, QString password, TTRSSManager* manager, unsigned long long id) :	APacket(manager, id),
																								_login(login), _password(password) {
}

Login::~Login() {
}

void Login::handleSuccess(QMap<QString, QVariant> reply) {
	qDebug() << "Successfuly logged in as user" << _login;
	QMap<QString, QVariant>::ConstIterator it = reply.constFind("session_id");
	if (it != reply.constEnd()) {
		getManager()->setSessionID(it->value());
		getManager()->setLoginStatus(TTRSSManager::LOGGED_IN);
	} else {
		getManager()->setLoginStatus(TTRSSManager::FAILED);
	}
}

void Login::handleError(QMap<QString, QVariant> reply) {
	qDebug() << "Error logging in as user" << _login;
	getManager()->setLoginStatus(TTRSSManager::FAILED);
}

QVariantMap Login::getRequestDataImpl() const {
	QVariantMap packet;
	packet["op"] = "login";
	packet["user"] = _login;
	packet["password"] = _password;
	return packet;
}
