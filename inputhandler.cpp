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

    qreal x_pos = gameState->players[client->main_id]->pos().x();
    qreal y_pos = gameState->players[client->main_id]->pos().y();
    // move the player left and right
    if (event->key() == Qt::Key_Left){

            //left pressed
            QJsonObject gamestate1;
            gamestate1.insert("id",client->main_id);
            gamestate1.insert("key","LEFT");
            QJsonDocument doc(gamestate1);
            QByteArray bytes = doc.toJson();
            client->sendBinaryMessageToServer(bytes);

    }
    else if (event->key() == Qt::Key_Right){

            QJsonObject gamestate1;
            gamestate1.insert("id",client->main_id);
            gamestate1.insert("key","RIGHT");
            QJsonDocument doc(gamestate1);
            QByteArray bytes = doc.toJson();
            client->sendBinaryMessageToServer(bytes);

    }
    else if (event->key() == Qt::Key_Up){

            QJsonObject gamestate1;
            gamestate1.insert("id",client->main_id);
            gamestate1.insert("key","UP");
            QJsonDocument doc(gamestate1);
            QByteArray bytes = doc.toJson();
            client->sendBinaryMessageToServer(bytes);

    }
    else if (event->key() == Qt::Key_Down){

            QJsonObject gamestate1;
            gamestate1.insert("id",client->main_id);
            gamestate1.insert("key","DOWN");
            QJsonDocument doc(gamestate1);
            QByteArray bytes = doc.toJson();
            client->sendBinaryMessageToServer(bytes);

    }
    // shooting bullets
    else if (event->key() == Qt::Key_W){
         //create a bullet
        QJsonObject gamestate1;
        gamestate1.insert("id",client->main_id);
        gamestate1.insert("key","W");
        QJsonDocument doc(gamestate1);
        QByteArray bytes = doc.toJson();
        client->sendBinaryMessageToServer(bytes);
    }
    else if (event->key() == Qt::Key_A){
         //create a bullet
        QJsonObject gamestate1;
        gamestate1.insert("id",client->main_id);
        gamestate1.insert("key","A");
        QJsonDocument doc(gamestate1);
        QByteArray bytes = doc.toJson();
        client->sendBinaryMessageToServer(bytes);
    }
    else if (event->key() == Qt::Key_S){
         //create a bullet
        QJsonObject gamestate1;
        gamestate1.insert("id",client->main_id);
        gamestate1.insert("key","S");
        QJsonDocument doc(gamestate1);
        QByteArray bytes = doc.toJson();
        client->sendBinaryMessageToServer(bytes);
    }
    else if (event->key() == Qt::Key_D){
         //create a bullet
        QJsonObject gamestate1;
        gamestate1.insert("id",client->main_id);
        gamestate1.insert("key","D");
        QJsonDocument doc(gamestate1);
        QByteArray bytes = doc.toJson();
        client->sendBinaryMessageToServer(bytes);
    }

    qDebug()<<"Json doc is: ";
    qDebug()<<gameState->getJsonDocFromGameState().toJson();
}
