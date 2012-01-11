/// Contains various methods which might be used throughout the whole app.

#pragma once
#ifndef IPN_WEBHELPERS
#define IPN_WEBHELPERS

#include <QString>
#include <QWebElement>
#include <QColor>

namespace ipn
{
	namespace webhelpers
	{
		QString elementIdentifierString(QWebElement el);
		QString elementContentString(QWebElement el);
		QColor stringToColor(QString colorString);

		bool hasPreviousSibling(QWebElement el);
		bool hasNextSibling(QWebElement el);
		bool hasFirstChild(QWebElement el);
		bool hasParent(QWebElement el);

		bool nodeExists(QWebElement el);
	} // namespace webhelpers
} // namespace ipn

#endif /* end of include guard: IPN_WEBHELPERS */
