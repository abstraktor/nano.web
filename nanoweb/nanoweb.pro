# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

symbian:TARGET.UID3 = 0xEAE867FA

# Smart Installer package's UID
# This UID is from the protected range 
# and therefore the package will fail to install if self-signed
# By default qmake uses the unprotected range value if unprotected UID is defined for the application
# and 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
# CONFIG += mobility
# MOBILITY +=

# Display a console to display debug messages.
CONFIG += console

SOURCES += \
        src/main.cc \
        src/MainWindow.cc \
        src/IPodFrameWidget.cc \
        src/helpers.cc \
        src/apps/PeepholeApp.cc \
        src/apps/PaintApp.cc \
        src/apps/MusicApp.cc \
        src/apps/ClockApp.cc \
        src/apps/GUIApp.cc \
        src/apps/MapApp.cc \
        src/apps/GestureApp.cc \
        src/apps/MarkingMenuApp.cc \
        src/apps/MultiTapApp.cc \
        src/apps/PickerApp.cc \
        src/apps/App.cc \
        src/widgets/TitleBarWidget.cc \
        src/widgets/TitleBarButtonWidget.cc \
        src/widgets/TextWidget.cc \
        src/widgets/PageIndicatorWidget.cc \
        src/widgets/ImageWidget.cc \
        src/widgets/ClickableWidget.cc \
        src/widgets/ButtonWidget.cc \
        src/widgets/ScalableButtonWidget.cc \
        src/widgets/SwitchButtonWidget.cc \
        src/widgets/SliderWidget.cc \
        src/widgets/BackgroundWidget.cc \
        src/widgets/FlickArea.cc \
        src/widgets/MarkingMenu.cc \
        src/widgets/PickerWidget.cc \
        src/widgets/OverlayWidget.cc \
        src/apps/MenuApp.cc \
        src/apps/InfoApp.cc \
    src/apps/WebviewApp.cc \
    src/nanoweb/NanoWebView.cc \
    src/apps/ElementTappedApp.cc \
    src/apps/ElementFisheyeApp.cc \
    src/nanoweb/NanoQWebview.cc \
    src/webhelpers.cc \
    src/apps/ChooseTool1App.cc \
    src/apps/ChooseToolBoxmodelApp.cc \
    src/apps/BorderEditApp.cc \
    src/widgets/StyleListWidget.cc \
    src/apps/BorderStyleApp.cc \
    src/apps/BorderWidthApp.cc \
    src/widgets/WidthListWidget.cc
HEADERS += \
        src/MainWindow.h \
        src/IPodFrameWidget.h \
        src/helpers.h \
        src/apps/PeepholeApp.h \
        src/apps/PaintApp.h \
        src/apps/MusicApp.h \
        src/apps/ClockApp.h \
        src/apps/GUIApp.h \
        src/apps/MapApp.h \
        src/apps/GestureApp.h \
        src/apps/MarkingMenuApp.h \
        src/apps/MultiTapApp.h \
        src/apps/PickerApp.h \
        src/apps/App.h \
        src/widgets/TitleBarWidget.h \
        src/widgets/TitleBarButtonWidget.h \
        src/widgets/TextWidget.h \
        src/widgets/PageIndicatorWidget.h \
        src/widgets/ImageWidget.h \
        src/widgets/ClickableWidget.h \
        src/widgets/ButtonWidget.h \
        src/widgets/ScalableButtonWidget.h \
        src/widgets/SwitchButtonWidget.h \
        src/widgets/SliderWidget.h \
        src/widgets/BackgroundWidget.h \
        src/widgets/FlickArea.h \
        src/widgets/MarkingMenu.h \
        src/widgets/PickerWidget.h \
        src/widgets/OverlayWidget.h \
        src/apps/MenuApp.h \
        src/apps/InfoApp.h \
    src/apps/WebviewApp.h \
    src/nanoweb/NanoWebView.h \
    src/nanoweb/NanoWebView.h \
    src/apps/ElementTappedApp.h \
    src/apps/ElementFisheyeApp.h \
    src/nanoweb/NanoQWebview.h \
    src/webhelpers.h \
    src/apps/ChooseTool1App.h \
    src/apps/ChooseToolBoxmodelApp.h \
    src/apps/BorderEditApp.h \
    src/widgets/StyleListWidget.h \
    src/apps/BorderStyleApp.h \
    src/apps/BorderWidthApp.h \
    src/widgets/WidthListWidget.h
FORMS +=

INCLUDEPATH += src src/apps src/widgets
QT += webkit


# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    webseite/meilenwerk.html \
    webseite/meilenwerk_files/rb.css \
    webseite/meilenwerk_files/piwik.js \
    webseite/meilenwerk_files/nav.css \
    webseite/meilenwerk_files/MW_Logo.png \
    webseite/meilenwerk_files/mw.css \
    webseite/meilenwerk_files/meilenwerk_stuttgart_start_01.jpg \
    webseite/meilenwerk_files/fouc.css \
    webseite/meilenwerk_files/content.css \
    webseite/meilenwerk_files/_blank.gif \
    img/our_icons/WORLD.png \
    img/our_icons/WIFI.png \
    img/our_icons/website.png \
    img/our_icons/USER - M.png \
    img/our_icons/USER - F.png \
    img/our_icons/USB.png \
    img/our_icons/TV.png \
    img/our_icons/TRASH - FULL.png \
    img/our_icons/TRASH - EMPTY.png \
    img/our_icons/TOOLS.png \
    img/our_icons/TASKS.png \
    img/our_icons/TASKBAR.png \
    img/our_icons/SYNCAPP.png \
    img/our_icons/SPEAKER.png \
    img/our_icons/SOFTWARE.png \
    img/our_icons/SETTINGS.png \
    img/our_icons/SECURITY CENTER.png \
    img/our_icons/SEARCH.png \
    img/our_icons/SD CARD.png \
    img/our_icons/SCANNER.png \
    img/our_icons/RUN.png \
    img/our_icons/RAM.png \
    img/our_icons/PRINTER.png \
    img/our_icons/POWERCFG.png \
    img/our_icons/POWERCFG - SETTINGS.png \
    img/our_icons/POWERCFG - BATTERY.png \
    img/our_icons/POWER - SWITCH USER.png \
    img/our_icons/POWER - STANDBY.png \
    img/our_icons/POWER - SLEEP.png \
    img/our_icons/POWER - SHUT DOWN.png \
    img/our_icons/POWER - RESTART.png \
    img/our_icons/PHOTO.png \
    img/our_icons/PHONE.png \
    img/our_icons/PDA.png \
    img/our_icons/PCMCIA.png \
    img/our_icons/NOTEBOOK.png \
    img/our_icons/NETWORK - PRINTER.png \
    img/our_icons/NETWORK - NOTEBOOK.png \
    img/our_icons/NETWORK - LAN.png \
    img/our_icons/NETWORK - HOME.png \
    img/our_icons/NETWORK - HDD.png \
    img/our_icons/NETWORK - FOLDER.png \
    img/our_icons/NETWORK - FOLDER OPEN.png \
    img/our_icons/NETWORK - FOLDER ADD.png \
    img/our_icons/NETWORK - FAX.png \
    img/our_icons/MOUSE.png \
    img/our_icons/MODEM.png \
    img/our_icons/MOBILE.png \
    img/our_icons/MICROPHONE.png \
    img/our_icons/MAIL.png \
    img/our_icons/LOCK.png \
    img/our_icons/LOCK - UNLOCKED.png \
    img/our_icons/KEYBOARD.png \
    img/our_icons/KEYBOARD MOUSE - SETTINGS.png \
    img/our_icons/KEY.png \
    img/our_icons/INTERNET.png \
    img/our_icons/INFRARED.png \
    img/our_icons/INFO.png \
    img/our_icons/HOME.png \
    img/our_icons/HELP.png \
    img/our_icons/HEADPHONE.png \
    img/our_icons/HDD.png \
    img/our_icons/HDD - EXTERNAL.png \
    img/our_icons/HARDWARE.png \
    img/our_icons/GAMECONTROLLER.png \
    img/our_icons/FOLDER.png \
    img/our_icons/FOLDER - USER.png \
    img/our_icons/FOLDER - SHARE.png \
    img/our_icons/FOLDER - SETTINGS.png \
    img/our_icons/FOLDER - PRINTER.png \
    img/our_icons/FOLDER - PICTURES.png \
    img/our_icons/FOLDER - OPEN.png \
    img/our_icons/FOLDER - MUSIC.png \
    img/our_icons/FOLDER - MOVIE.png \
    img/our_icons/FOLDER - INTERNET.png \
    img/our_icons/FOLDER - GAMES.png \
    img/our_icons/FOLDER - FONTS.png \
    img/our_icons/FOLDER - DOWNLOADS.png \
    img/our_icons/FOLDER - DOCUMENTS.png \
    img/our_icons/FLOPPY.png \
    img/our_icons/FIREWALL.png \
    img/our_icons/FILE.png \
    img/our_icons/FILE - ZIP.png \
    img/our_icons/FILE - TEXT.png \
    img/our_icons/FILE - SOUND.png \
    img/our_icons/FILE - PICTURE.png \
    img/our_icons/FILE - MOVIE.png \
    img/our_icons/FILE - INTERNET.png \
    img/our_icons/FILE - FONT.png \
    img/our_icons/FILE - FONT.A.png \
    img/our_icons/FILE - EXECUTABLE.png \
    img/our_icons/FILE - DLL.png \
    img/our_icons/FILE - CERTIFICATE.png \
    img/our_icons/FILE - BATCH.png \
    img/our_icons/FAX.png \
    img/our_icons/EASY EJECT.png \
    img/our_icons/EARPHONE.png \
    img/our_icons/DVD - NOTEBOOK.png \
    img/our_icons/DOWNLOAD.png \
    img/our_icons/DISPLAY.png \
    img/our_icons/DESKTOP.png \
    img/our_icons/DEFRAG.png \
    img/our_icons/CPU.png \
    img/our_icons/CMD.png \
    img/our_icons/CLOCK.png \
    img/our_icons/CHAT.png \
    img/our_icons/CD.png \
    img/our_icons/CAMERA.png \
    img/our_icons/CALENDAR.png \
    img/our_icons/BURN.png \
    img/our_icons/BOOKMARKS.png \
    img/our_icons/BOOK.png \
    img/our_icons/BLUETOOTH.png \
    img/our_icons/AUTOMATIC UPDATES.png \
    img/our_icons/ATTACHMENT.png \
    img/our_icons/ADDRESSBOOK.png \
    img/our_icons/ACCESS.png \
    img/fisheye-app/lappen_top.png \
    img/fisheye-app/lappen_right.png \
    img/fisheye-app/lappen_left.png \
    img/fisheye-app/lappen_bottom.png \
    img/boxmodel-app/bm_topbutton_pressed.png \
    img/boxmodel-app/bm_rightbutton_pressed.png \
    img/boxmodel-app/bm_released.png \
    img/boxmodel-app/bm_middle_pressed.png \
    img/boxmodel-app/bm_leftbutton_pressed.png \
    img/boxmodel-app/bm_bottombutton_pressed.png \
    img/menu-icons/text.png \
    img/menu-icons/position.png \
    img/menu-icons/color.png \
    img/menu-icons/box_model.png

RESOURCES += \
    resources.qrc










