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


#include "controller.h"
#include "model.h"

using namespace std;


Controller::Controller(Model *m) : model_(m) {}


void Controller::startButtonClicked(int seed) {		//start button clicked event - calls model's start game
	model_->startGame(seed);
}

void Controller::quitButtonClicked() {		//quit button clicked - calls model's quit game
	model_->quitGame();
}
void Controller::rageButtonClicked() {		//rage quit button clicked - calls model's rage quit
	model_->ragequit();
}
void Controller::playcard(int index) {		//card in hand played - calls model's play card
	model_->Playcard(index);
}
void Controller::p1playertype(string type) {	//radio button clicked
	model_->setPlayerType(1, type);
}
void Controller::p2playertype(string type) {		//radio button clicked
	model_->setPlayerType(2, type);
}
void Controller::p3playertype(string type) {		//radio button clicked
	model_->setPlayerType(3, type);
}
void Controller::p4playertype(string type) {		//radio button clicked
	model_->setPlayerType(4, type);
}
void Controller::initgame(int seed){				//setup game for next round
	model_->init(seed);
}