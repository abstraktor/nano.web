#include "ElementFisheyeApp.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QVector>
#include <QTimer>
#include <QtDebug>
#include <QtCore/qmath.h>
#include "widgets/BackgroundWidget.h"
#include "widgets/TitleBarWidget.h"
#include "widgets/TextWidget.h"
#include "widgets/ScalableButtonWidget.h"
#include "helpers.h"
#include "webhelpers.h"

#define ANIMATION_TIME 500.0
#define FRAMES 25.0

#define NOAXIS 0
#define XAXIS 1
#define YAXIS 2

namespace ipn
{

    ElementFisheyeApp::ElementFisheyeApp(QWidget *parent) : App(parent)
    {
            connect(this, SIGNAL(elementTapped(QWebElement)), parent, SLOT(instantPopApp()));
            connect(this, SIGNAL(elementTapped(QWebElement)), parent, SLOT(elementTappedInFisheye(QWebElement)));
            connect(this, SIGNAL(backButtonClickTriggered()), parent, SLOT(elementTappedInFisheye()));

            translation = QPoint();

            diff = QPoint();
            mousePressed = false;
            moves = 0;
            animationTimer = new QTimer(this);
            animationTimer->setInterval(ANIMATION_TIME / FRAMES);
            connect(animationTimer, SIGNAL(timeout()), this, SLOT(timerTick()));
            doSwiping = false;
            axis = NOAXIS;



            animationStart = QPoint();
            animationDestination = QPoint();
            tickCount = 0;

            lastSwipeDownwards = false;

            connect(this, SIGNAL(swipeRightTriggered()), this, SLOT(swipeRight()));
            connect(this, SIGNAL(swipeUpTriggered()), this, SLOT(swipeUp()));
            connect(this, SIGNAL(swipeDownTriggered()), this, SLOT(swipeDown()));
            connect(this, SIGNAL(swipeLeftTriggered()), this, SLOT(swipeLeft()));
    }

    void ElementFisheyeApp::resetChild() {
            lastSwipeDownwards = false;
            lastChild = QWebElement();
    }

    void ElementFisheyeApp::setElement(QWebElement el) {
            currentEl = el;
            update();
    }
    QWebElement ElementFisheyeApp::getElement() {
            return currentEl;
    }

    void ElementFisheyeApp::backButtonClick()
    {
            //nop to override default action
            qDebug() << "Backbutton clicked! ";
    }

    void ElementFisheyeApp::swipeRight()
    {
            animationStart = translation;
            if (ipn::webhelpers::hasPreviousSibling(currentEl)) {
                    animationDestination = QPoint(240, 0);
                    nextEl = currentEl.previousSibling();
            }
            else {
                    setAnimationParametersToZero();
            }
            animationTimer->start();
    }
    void ElementFisheyeApp::swipeUp()
    {
            animationStart = translation;
            if (ipn::webhelpers::hasFirstChild(currentEl)) {
                    animationDestination = QPoint(0, -240);
                    if (lastSwipeDownwards)
                            nextEl = lastChild;
                    else
                            nextEl = currentEl.firstChild();
            }
            else {
                    setAnimationParametersToZero();

            }
            animationTimer->start();
    }
    void ElementFisheyeApp::swipeDown()
    {
            animationStart = translation;
            if (ipn::webhelpers::hasParent(currentEl)) {
                    animationDestination = QPoint(0, 240);
                    nextEl = currentEl.parent();
                    lastSwipeDownwards = true;
                    lastChild = currentEl;
            }
            else {
                    setAnimationParametersToZero();
            }
            animationTimer->start();
    }
    void ElementFisheyeApp::swipeLeft()
    {
            animationStart = translation;
            if (ipn::webhelpers::hasNextSibling(currentEl)) {
                    animationDestination = QPoint(-240, 0);
                    nextEl = currentEl.nextSibling();

            }
            else {
                    setAnimationParametersToZero();
            }
            animationTimer->start();
    }

    void ElementFisheyeApp::timerTick()
    {
            tickCount++;
            QPoint vector = animationDestination - animationStart;
            translation = animationStart + ((float) tickCount / FRAMES) * vector;
            update();
            if (tickCount == (int) FRAMES) {
                    animationTimer->stop();
                    lastSwipeDownwards = vector.y() > 0 && ipn::webhelpers::hasFirstChild(currentEl);
                    currentEl = nextEl;
                    translation = animationDestination;
                    tickCount = 0;
                    update();
                    diff = translation = QPoint();
            }
    }

    void ElementFisheyeApp::mousePressEvent(QMouseEvent *event)
    {
    }

    void ElementFisheyeApp::mouseMoveEvent(QMouseEvent *event)
    {
            if (!event->buttons() == Qt::LeftButton)
                    return;
            if (!mousePressed) {
                    mousePressed = true;
                    lastPoint = event->pos();
                    return;
            }
            else {
                    moves++;
                    diff = diff + (event->pos() - lastPoint);
                    lastPoint = event->pos();
                    //if (moves == 1) {
                    double length = qSqrt(diff.x() * diff.x() + diff.y() * diff.y());
                    if (length >= 5 && diff.x() != diff.y()) {
                            doSwiping = true;
                            // detect x or y
                            if (abs(diff.x()) > abs(diff.y()))
                                    axis = XAXIS;
                            else
                                    axis = YAXIS;
                    }

                    //}
                    if (axis == XAXIS)
                            diff.setY(0);
                    else if (axis == YAXIS)
                            diff.setX(0);
                    if (doSwiping) {
                            translation = diff;
                    }
            }
            update();
    }

    void ElementFisheyeApp::mouseReleaseEvent(QMouseEvent *event) {
            if (doSwiping) {
                    if (axis == XAXIS) {
                            // animate x-axis
                            if (abs(diff.x()) < 100) {
                                    animationDestination = QPoint(0, 0);
                                    nextEl = currentEl;
                            }
                            else {
                                    if (signum(diff.x()) == +1) {
                                            if (ipn::webhelpers::hasPreviousSibling(currentEl)) {
                                                    animationDestination = QPoint(240, 0);
                                                    nextEl = currentEl.previousSibling();
                                            }
                                            else {
                                                    setAnimationParametersToZero();
                                            }
                                    }
                                    else if (signum (diff.x()) == -1) {
                                            if (ipn::webhelpers::hasNextSibling(currentEl)) {
                                                    animationDestination = QPoint(-240, 0);
                                                    nextEl = currentEl.nextSibling();
                                            }
                                            else {
                                                    setAnimationParametersToZero();
                                            }
                                    }
                                    else {
                                            qDebug() << "Error: should not happen";
                                    }
                            }
                    }
                    else if (axis == YAXIS) {
                            // animate y-axis
                            if (abs(diff.y()) < 100) {
                                    setAnimationParametersToZero();
                            }
                            else {
                                    if (signum(diff.y()) == +1) {
                                            if (ipn::webhelpers::hasParent(currentEl)) {
                                                    animationDestination = QPoint(0, 240);
                                                    nextEl = currentEl.parent();
                                                    lastSwipeDownwards = true;
                                                    lastChild = currentEl;
                                            }
                                            else {
                                                    setAnimationParametersToZero();
                                            }
                                    }
                                    else if (signum (diff.y()) == -1) {
                                            if (ipn::webhelpers::hasFirstChild(currentEl))
                                            {
                                                    animationDestination = QPoint(0, -240);
                                                    if (lastSwipeDownwards)
                                                            nextEl = lastChild;
                                                    else
                                                            nextEl = currentEl.firstChild();
                                            }
                                            else {
                                                    setAnimationParametersToZero();
                                            }
                                    }
                                    else {
                                            qDebug() << "Error: should not happen";
                                    }
                            }
                    }
                    animationStart = diff;
                    animationTimer->start();
            }
            else {
                    QRect r = QRect(60, 60, 120, 120);
                    if (r.contains(event->pos()) && r.contains(event->pos() - diff) && diff.x() <= 5 && diff.y() <= 5)
                            emit elementTapped(currentEl);
            }
            mousePressed = false;
            doSwiping = false;
            moves = 0;
            axis = NOAXIS;
    }

    void ElementFisheyeApp::paintEvent(QPaintEvent*)
    {
            QColor current = QColor(20, 20, 20);
            QColor others = QColor(0, 0, 0);

            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing);

            painter.translate(translation);
            // draw select element
            painter.translate(0, 0);
            drawFisheye(&painter, currentEl, current);
            // draw parent
            painter.translate(0, -240);
            drawFisheye(&painter, currentEl.parent(), others);
            // draw left sibling
            painter.translate(-240, 240);
            drawFisheye(&painter, currentEl.previousSibling(), others);
            // draw right sibling
            painter.translate(480, 0);
            drawFisheye(&painter, currentEl.nextSibling(), others);
            // draw child
            painter.translate(-240, 240);
            drawFisheye(&painter, lastSwipeDownwards ? lastChild : currentEl.firstChild(), others);

            painter.translate(0, -240);
            painter.translate(-translation);
            painter.setPen(QPen(Qt::white, 5.0));

            QPixmap pixmap = QPixmap(":img/fisheye-app/lappen_top.png");
            if (ipn::webhelpers::hasParent(currentEl)) {
                    painter.drawPixmap(0, 0, 240, 24, pixmap);
                    painter.drawText(0, 0, 240, 20, Qt::AlignCenter, currentEl.parent().tagName().toUpper());
            }
            painter.rotate(90);
            painter.translate(0, -240);
            if (ipn::webhelpers::hasNextSibling(currentEl)) {
                    painter.drawPixmap(0, 0, 240, 24, pixmap);
                    painter.drawText(0, 0, 240, 20, Qt::AlignCenter, currentEl.nextSibling().tagName().toUpper());
            }

            painter.translate(0, 240);
            painter.rotate(90);
            painter.translate(-240, -240);
            if (ipn::webhelpers::hasFirstChild(currentEl)) {
                    painter.drawPixmap(0, 0, 240, 24, pixmap);
                    //painter.drawText(0, 0, 240, 20, Qt::AlignCenter, currentEl.firstChild().tagName().toUpper());
            }

            painter.translate(240, 240);
            painter.rotate(90);
            painter.translate(-240, 0);
            if (ipn::webhelpers::hasPreviousSibling(currentEl)) {
                    painter.drawPixmap(0, 0, 240, 24, pixmap);
                    painter.drawText(0, 0, 240, 20, Qt::AlignCenter, currentEl.previousSibling().tagName().toUpper());
            }

            painter.translate(240, 0);
            painter.rotate(90);
            if (ipn::webhelpers::hasFirstChild(currentEl)) {
                    painter.drawText(0, 220, 240, 20, Qt::AlignCenter, lastSwipeDownwards ? lastChild.tagName().toUpper() : currentEl.firstChild().tagName().toUpper());
            }


            //painter.drawText(0, 200, 240, 20, Qt::AlignCenter, "tap to go back");
    }

    void ElementFisheyeApp::drawFisheye(QPainter *painter, QWebElement el, QColor bgcolor) {
            bgcolor.setAlpha(230);
            painter->setBrush(QBrush(bgcolor, Qt::SolidPattern));
            painter->setPen(Qt::NoPen);
            painter->drawRect(0, 0, 240, 240);
            painter->setPen(Qt::SolidLine);

            if (!ipn::webhelpers::nodeExists(el))
                    return;

            painter->setPen(QPen(Qt::white, 5.0));
            painter->setFont(QFont("Ubuntu", 15 * ipn::helpers::fontSizeFactor, QFont::Bold	));
            painter->drawText(0, 60, 240, 20, Qt::AlignCenter, ipn::webhelpers::elementIdentifierString(el));
            painter->drawText(0, 90, 240, 20, Qt::AlignCenter, ipn::webhelpers::elementContentString(el));
            painter->setFont(QFont("Ubuntu", 10 * ipn::helpers::fontSizeFactor, QFont::Normal	));
    }

    void ElementFisheyeApp::setAnimationParametersToZero() {
            animationDestination = QPoint(0, 0);
            nextEl = currentEl;
    }

    int ElementFisheyeApp::signum(int number) {
            if (number > 0)
                    return 1;
            else if (number < 0)
                    return -1;
            return 0;
    }

} // namespace ipn
