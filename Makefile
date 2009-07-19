#############################################################################
# Makefile for building: yukon
# Generated by qmake (2.01a) (Qt 4.5.0) on: Sun Jul 19 12:02:36 2009
# Project:  yukon.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile yukon.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -D_REENTRANT -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -D_REENTRANT -Wall -W $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Iengine -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lQtGui -lQtCore -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = yukon.cpp \
		Y_Game.cpp \
		Y_Level.cpp \
		Y_Perso.cpp \
		Y_Wolf.cpp \
		Y_Fire.cpp \
		engine/Actor.cpp \
		engine/Anim_Sprite.cpp \
		engine/Animation.cpp \
		engine/Camera.cpp \
		engine/Game.cpp \
		engine/Ground_Plane.cpp \
		engine/Level.cpp \
		engine/Particle.cpp \
		engine/Particle_Src.cpp \
		engine/Phys_Object.cpp 
OBJECTS       = yukon.o \
		Y_Game.o \
		Y_Level.o \
		Y_Perso.o \
		Y_Wolf.o \
		Y_Fire.o \
		Actor.o \
		Anim_Sprite.o \
		Animation.o \
		Camera.o \
		Game.o \
		Ground_Plane.o \
		Level.o \
		Particle.o \
		Particle_Src.o \
		Phys_Object.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		yukon.pro
QMAKE_TARGET  = yukon
DESTDIR       = 
TARGET        = yukon

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: yukon.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile yukon.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile yukon.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/yukon1.0.0 || $(MKDIR) .tmp/yukon1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/yukon1.0.0/ && $(COPY_FILE) --parents Y_Game.h Y_Level.h Y_Perso.h Y_Wolf.h Y_Fire.h engine/Actor.h engine/Anim_Sprite.h engine/Animation.h engine/Camera.h engine/Game.h engine/Ground_Plane.h engine/Level.h engine/Particle.h engine/Particle_Src.h engine/Phys_Object.h .tmp/yukon1.0.0/ && $(COPY_FILE) --parents yukon.cpp Y_Game.cpp Y_Level.cpp Y_Perso.cpp Y_Wolf.cpp Y_Fire.cpp engine/Actor.cpp engine/Anim_Sprite.cpp engine/Animation.cpp engine/Camera.cpp engine/Game.cpp engine/Ground_Plane.cpp engine/Level.cpp engine/Particle.cpp engine/Particle_Src.cpp engine/Phys_Object.cpp .tmp/yukon1.0.0/ && (cd `dirname .tmp/yukon1.0.0` && $(TAR) yukon1.0.0.tar yukon1.0.0 && $(COMPRESS) yukon1.0.0.tar) && $(MOVE) `dirname .tmp/yukon1.0.0`/yukon1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/yukon1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

yukon.o: yukon.cpp Y_Game.h \
		engine/Game.h \
		engine/Camera.h \
		engine/Anim_Sprite.h \
		engine/Animation.h \
		engine/Phys_Object.h \
		engine/Level.h \
		engine/Ground_Plane.h \
		engine/Particle.h \
		engine/Particle_Src.h \
		Y_Level.h \
		Y_Perso.h \
		engine/Actor.h \
		Y_Fire.h \
		Y_Wolf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o yukon.o yukon.cpp

Y_Game.o: Y_Game.cpp Y_Game.h \
		engine/Game.h \
		engine/Camera.h \
		engine/Anim_Sprite.h \
		engine/Animation.h \
		engine/Phys_Object.h \
		engine/Level.h \
		engine/Ground_Plane.h \
		engine/Particle.h \
		engine/Particle_Src.h \
		Y_Level.h \
		Y_Perso.h \
		engine/Actor.h \
		Y_Fire.h \
		Y_Wolf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Y_Game.o Y_Game.cpp

Y_Level.o: Y_Level.cpp Y_Level.h \
		engine/Level.h \
		engine/Camera.h \
		engine/Anim_Sprite.h \
		engine/Animation.h \
		engine/Phys_Object.h \
		engine/Ground_Plane.h \
		engine/Particle.h \
		engine/Particle_Src.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Y_Level.o Y_Level.cpp

Y_Perso.o: Y_Perso.cpp Y_Perso.h \
		engine/Actor.h \
		engine/Phys_Object.h \
		engine/Anim_Sprite.h \
		engine/Animation.h \
		Y_Fire.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Y_Perso.o Y_Perso.cpp

Y_Wolf.o: Y_Wolf.cpp Y_Wolf.h \
		engine/Actor.h \
		engine/Phys_Object.h \
		engine/Anim_Sprite.h \
		engine/Animation.h \
		Y_Perso.h \
		Y_Fire.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Y_Wolf.o Y_Wolf.cpp

Y_Fire.o: Y_Fire.cpp Y_Fire.h \
		engine/Anim_Sprite.h \
		engine/Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Y_Fire.o Y_Fire.cpp

Actor.o: engine/Actor.cpp engine/Actor.h \
		engine/Phys_Object.h \
		engine/Anim_Sprite.h \
		engine/Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Actor.o engine/Actor.cpp

Anim_Sprite.o: engine/Anim_Sprite.cpp engine/Anim_Sprite.h \
		engine/Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Anim_Sprite.o engine/Anim_Sprite.cpp

Animation.o: engine/Animation.cpp engine/Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Animation.o engine/Animation.cpp

Camera.o: engine/Camera.cpp engine/Camera.h \
		engine/Anim_Sprite.h \
		engine/Animation.h \
		engine/Phys_Object.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Camera.o engine/Camera.cpp

Game.o: engine/Game.cpp engine/Game.h \
		engine/Camera.h \
		engine/Anim_Sprite.h \
		engine/Animation.h \
		engine/Phys_Object.h \
		engine/Level.h \
		engine/Ground_Plane.h \
		engine/Particle.h \
		engine/Particle_Src.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Game.o engine/Game.cpp

Ground_Plane.o: engine/Ground_Plane.cpp engine/Ground_Plane.h \
		engine/Camera.h \
		engine/Anim_Sprite.h \
		engine/Animation.h \
		engine/Phys_Object.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Ground_Plane.o engine/Ground_Plane.cpp

Level.o: engine/Level.cpp engine/Level.h \
		engine/Camera.h \
		engine/Anim_Sprite.h \
		engine/Animation.h \
		engine/Phys_Object.h \
		engine/Ground_Plane.h \
		engine/Particle.h \
		engine/Particle_Src.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Level.o engine/Level.cpp

Particle.o: engine/Particle.cpp engine/Particle.h \
		engine/Animation.h \
		engine/Phys_Object.h \
		engine/Anim_Sprite.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Particle.o engine/Particle.cpp

Particle_Src.o: engine/Particle_Src.cpp engine/Particle_Src.h \
		engine/Phys_Object.h \
		engine/Anim_Sprite.h \
		engine/Animation.h \
		engine/Particle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Particle_Src.o engine/Particle_Src.cpp

Phys_Object.o: engine/Phys_Object.cpp engine/Phys_Object.h \
		engine/Anim_Sprite.h \
		engine/Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Phys_Object.o engine/Phys_Object.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

