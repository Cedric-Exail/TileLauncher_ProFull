
#include "TileLauncher.h"
#include <QPropertyAnimation>
#include <QPushButton>

TileLauncher::TileLauncher(){
 auto *btn=new QPushButton("TileLauncher PRO",this);
 btn->setGeometry(50,50,200,80);
 auto *anim=new QPropertyAnimation(btn,"geometry");
 anim->setDuration(200);
 btn->installEventFilter(this);
}
