#include "game.h"

const QStringList Game::PATH_TO_LEVELS = QStringList() << ":/res/level/level1.lvl"
                                                       << ":/res/level/level1_1.lvl"
                                                       << ":/res/level/level2.lvl"
                                                       << ":/res/level/level3.lvl"
                                                       << ":/res/level/level4.lvl"
                                                       << ":/res/level/level5.lvl"
                                                       << ":/res/level/level6.lvl";

const QString Game::PATH_TO_SPACESHIP_PIXMAP        = ":/res/sprite/spaceship.png";
const QString Game::PATH_TO_ENEMY_PROJECTILE_PIXMAP = ":/res/sprite/enemy_projectile.png";
const QString Game::PATH_TO_PROJECTILE_PIXMAP       = ":/res/sprite/projectile.png";
const QString Game::PATH_TO_BG_PIXMAP               = ":/res/sprite/bg.png";
const QString Game::PATH_TO_ENEMIES_PIXMAP          = ":/res/sprite/enemies.png";
const QString Game::PATH_TO_EXPLOSION_PIXMAP        = ":/res/sprite/explosion.png";
const QString Game::PATH_TO_UFO_PIXMAP              = ":/res/sprite/ufo.png";
const QString Game::PATH_TO_POWERUP_PIXMAP          = ":/res/sprite/power_ups.png";
const QString Game::PATH_TO_SPACESHIP_SPRITE_PIXMAP = ":/res/sprite/spaceship_spritesheet.png";

const QString Game::PATH_TO_FONT = ":/res/font/Minecraft.ttf";

const QUrl Game::ExplosionSFX = QUrl("qrc:/res/sfx/explosion.wav");
const QUrl Game::InvaderKilledSFX = QUrl("qrc:/res/sfx/invaderkilled.wav");
const QUrl Game::ShootSFX = QUrl("qrc:/res/sfx/shoot.wav");

bool Game::SPACESHIP_DEAD = false;

int  Game::MIN_ENEMY_SHOOT_COUNTER  = 2.75 * (1000.0f/FPS);
int  Game::MAX_ENEMY_SHOOT_COUNTER  = 4.75 * (1000.0f/FPS);;

Game::Game()
{

}

int Game::convertPixelToGridPoint(int pixelVal)
{
    return int(pixelVal/GRID_SIZE);
}

int Game::convertGridPointToPixel(int gridPointVal)
{
    return gridPointVal*GRID_SIZE;
}
