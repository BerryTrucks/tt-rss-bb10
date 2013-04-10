#ifndef __CATEGORY_HPP__
#define __CATEGORY_HPP__

class Feed;

#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QVariant>

class Category : public QObject {

	Q_OBJECT

	Q_PROPERTY(QString title READ getTitle CONSTANT);
	Q_PROPERTY(bool hasUnreadArticles READ hasUnreadArticles NOTIFY unreadArticlesChanged);
	Q_PROPERTY(unsigned int unreadArticlesCount READ unreadArticlesCount NOTIFY unreadArticlesCountChanged);

public:
	Category(QString title = "", QList<Feed*> feeds = QList<Feed*>());
	Category(const Category& other);
	virtual ~Category();

	QString getTitle() const;
	QList<Feed*> getFeeds() const;

	bool hasUnreadArticles() const;
	unsigned int unreadArticlesCount() const;

Q_SIGNALS:
	// TODO: emit it
	void unreadArticlesChanged(bool hasUnreadArticles);
	// TODO: emit it
	void unreadArticlesCountChanged(unsigned int unreadArticlesCount);

private:
	QString			_title;
	QList<Feed*>	_feeds;
};

Q_DECLARE_METATYPE(Category)

inline QString Category::getTitle() const {
	return _title;
}

inline QList<Feed*> Category::getFeeds() const {
	return _feeds;
}

#endif // __CATEGORY_HPP__
