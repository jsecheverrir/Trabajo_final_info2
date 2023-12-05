#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enemigo.h"
#include "jugador.h".h"
#include <QKeyEvent>
#include <muros.h>
//#include <QList>
#include <vector>

std::vector<Muros*> muros;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    personaje(nullptr)
{
    ui->setupUi(this);

    // Crear una escena
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,600,300);
    scene->addItem(personaje);

    // Crear un objeto QPixmap con la imagen de fondo
    QPixmap backgroundImage("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Proyecto-Final/Trabajo_final_info2/NIVEL3/fotos/level/nivel3.jpg");

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
            QPixmap heartImage("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Proyecto-Final/Trabajo_final_info2/NIVEL3/fotos/sprite/heart.png");
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
        QString spritePath = "C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Proyecto-Final/Trabajo_final_info2/NIVEL3/fotos/sprite/personaje1.png";
        personaje = new Personaje(scene, spritePath);
        personaje->setPos(0, scene->height() - personaje->pixmap().height() + 75);
        scene->addItem(personaje);

        // Agregar el enemigo
        QString spritePathEnemigo = "C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Proyecto-Final/Trabajo_final_info2/NIVEL3/fotos/sprite/enemigo.png";
        Enemigo *enemigo = new Enemigo(scene, spritePathEnemigo);
        const int xOffsetEnemigo = 250;
        const int yOffsetEnemigo = -25;
        enemigo->setPos(xOffsetEnemigo, scene->height() - enemigo->pixmap().height() + yOffsetEnemigo);
        scene->addItem(enemigo);

        int i = 0;
        QPixmap scoreimage("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Proyecto-Final/Trabajo_final_info2/NIVEL3/fotos/sprite/score.png");
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

        ui->graphicsView->setScene(scene);
        muros.push_back(new Muros(0,0,700,10));
        scene->addItem(static_cast<QGraphicsItem*>(muros.back()));
        muros.push_back(new Muros(600,0,10,700));
        scene->addItem(static_cast<QGraphicsItem*>(muros.back()));
        muros.push_back(new Muros(0,300,600,20));
        scene->addItem(static_cast<QGraphicsItem*>(muros.back()));
        muros.push_back(new Muros(0,0,10,400));
        scene->addItem(static_cast<QGraphicsItem*>(muros.back()));
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

