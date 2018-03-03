#include "inputhandler.h"
#include <QDebug>
#include <QEvent>
#include <iostream>

InputHandler::InputHandler(Client *input_client, GameState *game_state){
    client=input_client;
    gameState=game_state;
//    qDebug()<<gameState->getJsonDocFromGameState().toJson();
}

void InputHandler::setGameState(GameState *game_state){
    gameState=game_state;

}

void InputHandler::keyPressEvent(QKeyEvent *event){

    qDebug()<<"Input read";

    qreal x_pos = gameState->players[client->id]->pos().x();
    qreal y_pos = gameState->players[client->id]->pos().y();
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (x_pos > 0)
        {
            //left pressed
            QJsonObject gamestate1;
            gamestate1.insert("id",client->id);
            gamestate1.insert("key","LEFT");
            QJsonDocument doc(gamestate1);
            QByteArray bytes = doc.toJson();
            client->sendBinaryMessageToServer(bytes);
        }
    }
    else if (event->key() == Qt::Key_Right){
        if (x_pos + 100 < 800)
        {

            QJsonObject gamestate1;
            gamestate1.insert("id",client->id);
            gamestate1.insert("key","RIGHT");
            QJsonDocument doc(gamestate1);
            QByteArray bytes = doc.toJson();
            client->sendBinaryMessageToServer(bytes);
        }
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
         //create a bullet
        bullet * bull = new bullet();
        bull->a_finder=gameState->players[0]->find_a();
        bull->setPos(x_pos+45,y_pos);
        gameState->addBullet(bull);
        scene()->addItem(bull);
    }

    qDebug()<<"Json doc is: ";
    qDebug()<<gameState->getJsonDocFromGameState().toJson();
}
