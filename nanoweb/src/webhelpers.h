/// Contains various methods which might be used throughout the whole app.

#pragma once
#ifndef IPN_WEBHELPERS
#define IPN_WEBHELPERS

#include <QString>
#include <QWebElement>

namespace ipn
{
	namespace webhelpers
	{
		QString elementIdentifierString(QWebElement el);
		QString elementContentString(QWebElement el);
	} // namespace webhelpers
} // namespace ipn

#endif /* end of include guard: IPN_WEBHELPERS */
