#include "helpers.h"
#include <QDebug>
#include <QtGlobal>

#ifdef __APPLE__
#include <CoreFoundation/CoreFoundation.h>
#endif

namespace ipn
{
	namespace helpers
	{

		#ifdef __APPLE__

		/** Heavily based on code from Qt (Mac only):
		 *  http://doc.qt.nokia.com/4.6/mac-differences.html#accessing-the-bundle-path
		 */
		QString bundlePath()
		{
			CFURLRef appUrlRef = CFBundleCopyBundleURL(CFBundleGetMainBundle());
			CFStringRef macPath = CFURLCopyFileSystemPath(appUrlRef, kCFURLPOSIXPathStyle);
			const char *pathPtr = CFStringGetCStringPtr(macPath, CFStringGetSystemEncoding());

			QString result(pathPtr);

			CFRelease(appUrlRef);
			CFRelease(macPath);

			return result;
		}

		QString resourcePath()
		{
			return bundlePath() + "/Contents/Resources/img/";
		}

		#else

		QString resourcePath()
		{
			return ":/img/";
		}

		#endif

		int limitedRand(int pMaxNumber)
		{
			qreal val = qreal(qrand());

			return qRound((val / qreal(RAND_MAX)) * qreal(pMaxNumber));
		}

		int min(int a, int b)
		{
			return (a < b ? a : b);
		}

		int max(int a, int b)
		{
			return (a < b ? b : a);
		}

		float minf(float a, float b)
		{
			return (a < b ? a : b);
		}

		float maxf(float a, float b)
		{
			return (a < b ? b : a);
		}

	} // namespace helpers
} // namespace ipn
