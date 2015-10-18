/*
 * MVC example of GTKmm program
 *
 * Controller class.  Is responsible for translating UI events (from the View)
 * into method calls to the Model.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H


#include <gtkmm.h>

class Model;

class Controller {
public:
    Controller( Model* );
    void startButtonClicked(int);
    void playcard(int);
    void quitButtonClicked();
    void rageButtonClicked();
    void p1playertype(std::string);			//set player type from radio button
    void p2playertype(std::string);			
    void p3playertype(std::string);
    void p4playertype(std::string);			//used to reset game
    void initgame(int);
private:
    Model *model_;
}; // Controller


#endif

