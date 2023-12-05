// mainwindow.cpp
#include "mainwindow.h"
#include "enemigo.h"
#include "ui_mainwindow.h"
#include "personaje.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    personaje(nullptr)
{
    ui->setupUi(this);

    // Crear una escena
    QGraphicsScene *scene = new QGraphicsScene(this);

    // Crear un objeto QPixmap con la imagen de fondo
    QPixmap backgroundImage("C:/Users/juana/OneDrive/Escritorio/nivel3/fotos/level/nivel3.jpg");

    if (backgroundImage.isNull()) {
        qDebug() << "Error: No se pudo cargar la imagen de fondo.";
    } else {
        // Crear un elemento de imagen pixmap y establecer la imagen de fondo
        QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(backgroundImage);
        scene->addItem(backgroundItem);

        // Agregar corazones (vidas)
        int numHearts = 5;
        int heartSize = 30;
        int scoreSize = 80;
        for (int i = 0; i < numHearts; ++i) {
            QPixmap heartImage("C:/Users/juana/OneDrive/Escritorio/nivel3/fotos/sprite/heart.png");
            if (heartImage.isNull()) {
                qDebug() << "Error: No se pudo cargar la imagen del corazón.";
            } else {
                QGraphicsPixmapItem *heartItem = new QGraphicsPixmapItem(heartImage);
                // Ajustar la posición de los corazones en la parte superior de la escena
                heartItem->setPos(i * (heartSize + 5), 10);
                // Ajustar el tamaño de los corazones
                heartItem->setScale(heartSize / static_cast<double>(heartImage.width()));
                scene->addItem(heartItem);
            }
        }

        // Agregar el personaje
        QString spritePath = "C:/Users/juana/OneDrive/Escritorio/nivel3/fotos/sprite/personaje1.png";
        personaje = new Personaje(scene, spritePath);
        personaje->setPos(0, scene->height() - personaje->pixmap().height() + 75);
        scene->addItem(personaje);

        // Agregar el enemigo
        QString spritePathEnemigo = "C:/Users/juana/OneDrive/Escritorio/nivel3/fotos/sprite/enemigo.png";
        Enemigo *enemigo = new Enemigo(scene, spritePathEnemigo);
        const int xOffsetEnemigo = 250;
        const int yOffsetEnemigo = -25;
        enemigo->setPos(xOffsetEnemigo, scene->height() - enemigo->pixmap().height() + yOffsetEnemigo);
        scene->addItem(enemigo);

        int i = 0;
        QPixmap scoreimage("C:/Users/juana/OneDrive/Escritorio/nivel3/fotos/sprite/score.png");
        if (scoreimage.isNull()) {
            qDebug() << "Error";
        } else {
            QGraphicsPixmapItem *scoreItem = new QGraphicsPixmapItem(scoreimage);
            scoreItem->setPos(i * (scoreSize + 5), 50);
            scoreItem->setScale(scoreSize / static_cast<double>(scoreimage.width()));
            scene->addItem(scoreItem);
        }

        // Establecer la escena en el QGraphicsView
        ui->graphicsView->setScene(scene);


        // Asegurarse de que el personaje tenga el foco para recibir eventos de teclado
        if (personaje) {
            personaje->setFlag(QGraphicsItem::ItemIsFocusable);
            personaje->setFocus();
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (personaje) {
        if (event->key() == Qt::Key_W)
            personaje->MoveUp();
        else if (event->key() == Qt::Key_S)
            personaje->MoveDown();
        else if (event->key() == Qt::Key_A)
            personaje->MoveLeft();
        else if (event->key() == Qt::Key_D)
            personaje->MoveRight();
    }
}

MainWindow::~MainWindow()
{
    delete ui->graphicsView->scene();
    delete ui;
}
