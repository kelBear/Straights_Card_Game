/*
 * MVC example of GTKmm program
 *
 * View class.  Is responsible for buttons (that user clicks) and for displaying
 * the top card of the deck.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "DeckGUI.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

//constructor, initializes widgets with default values
View::View(Controller *c, Model *m) :
model_(m),
controller_(c),
background(false, 0),
startbtn("Start"),
functionalitybox(false, 0),
ragequitbtn("Rage Quit"),
quitbtn("Quit"),
//cards in hand:
card1(deck.null()),
card2(deck.null()),
card3(deck.null()),
card4(deck.null()),
card5(deck.null()),
card6(deck.null()),
card7(deck.null()),
card8(deck.null()),
card9(deck.null()),
card10(deck.null()),
card11(deck.null()),
card12(deck.null()),
card13(deck.null()),
//cards on table:
CA(deck.null()),
C2(deck.null()),
C3(deck.null()),
C4(deck.null()),
C5(deck.null()),
C6(deck.null()),
C7(deck.null()),
C8(deck.null()),
C9(deck.null()),
C10(deck.null()),
CJ(deck.null()),
CQ(deck.null()),
CK(deck.null()),
HA(deck.null()),
H2(deck.null()),
H3(deck.null()),
H4(deck.null()),
H5(deck.null()),
H6(deck.null()),
H7(deck.null()),
H8(deck.null()),
H9(deck.null()),
H10(deck.null()),
HJ(deck.null()),
HQ(deck.null()),
HK(deck.null()),
SA(deck.null()),
S2(deck.null()),
S3(deck.null()),
S4(deck.null()),
S5(deck.null()),
S6(deck.null()),
S7(deck.null()),
S8(deck.null()),
S9(deck.null()),
S10(deck.null()),
SJ(deck.null()),
SQ(deck.null()),
SK(deck.null()),
DA(deck.null()),
D2(deck.null()),
D3(deck.null()),
D4(deck.null()),
D5(deck.null()),
D6(deck.null()),
D7(deck.null()),
D8(deck.null()),
D9(deck.null()),
D10(deck.null()),
DJ(deck.null()),
DQ(deck.null()),
DK(deck.null()),
//buttons and labels:
seedbox(false, 10),
p1humanbtn("Human"),
p1compbtn("Computer"),
p2humanbtn("Human"),
p2compbtn("Computer"),
p3humanbtn("Human"),
p3compbtn("Computer"),
p4humanbtn("Human"),
p4compbtn("Computer"),
seedlbl("Enter a seed value: "),
cardstbl(14, 4, false),
green("#33DDAA"),
red("#FF6666")
{

	*handImage = &card1;		//initialize values of arrays for widgets using address
	*handbtn = &handcard1;
	*playerbox = &p1box;
	*playerTypebox = &p1typebox;
	*playerHumanbtn = &p1humanbtn;
	*playerCompbtn = &p1compbtn;
	*spades = &SA;
	*clubs = &CA;
	*hearts = &HA;
	*diamonds = &DA;
	*playerInfo = &p1info;
	*infoFrame = &p1infoFrame;

	// Sets some properties of the window.
	set_title("straights");
	set_border_width(5);
	set_default_size(100, 100);

	// Add panels to the window
	add(background);
	seedentry.set_text("0");
	background.add(functionalitybox);
	background.add(gamebox);
	functionalitybox.add(menubox);
	functionalitybox.add(movesframe);
	movesframe.add(movesbox);
	menubox.add(seedbox);
	seedbox.add(seedlbl);
	seedbox.add(seedentry);
	menubox.add(startbtn);
	menubox.add(ragequitbtn);
	menubox.add(quitbtn);
	gamebox.add(allscorebox);
	gamebox.add(cardstbl);
	gamebox.add(playerTurn);
	gamebox.add(currenthandbox);
	for (int i = 0; i < CARD_COUNT / PLAYER_COUNT; i++){		//adds widgets using arrays
		(*handbtn)[i].set_image((*handImage)[i]);
		currenthandbox.add((*handbtn)[i]);
		(*handbtn)[i].set_sensitive(false);
	}
	for (int i = 0; i < PLAYER_COUNT; i++){			//add widgets using arrays
		allscorebox.add((*playerbox)[i]);
		Gtk::RadioButton::Group grp = (*playerHumanbtn)[i].get_group();		//set up group for radio buttons
		(*playerCompbtn)[i].set_group(grp);
		(*playerbox)[i].add((*playerTypebox)[i]);
		(*playerTypebox)[i].add((*playerHumanbtn)[i]);
		(*playerTypebox)[i].add((*playerCompbtn)[i]);
		(*playerbox)[i].add((*infoFrame)[i]);
		(*infoFrame)[i].add((*playerInfo)[i]);
		stringstream index;			//initialize labels
		index << "\nPlayer ";
		index << i + 1;
		index << "\n\n     Score 0\n\n     Discard 0\n";
		(*playerInfo)[i].set_text(index.str());
		(*playerInfo)[i].set_alignment(0.05);
	}
	for (int i = 0; i < CARD_COUNT / PLAYER_COUNT; i++) {		//setup table with cards using array
		cardstbl.attach((*spades)[i], i + 1, i + 2, 0, 1);
		cardstbl.attach((*clubs)[i], i + 1, i + 2, 1, 2);
		cardstbl.attach((*hearts)[i], i + 1, i + 2, 2, 3);
		cardstbl.attach((*diamonds)[i], i + 1, i + 2, 3, 4);
	}

	moveslbl.set_alignment(0.5, 0);
	movesbox.add(moveScroll);
	moveScroll.add(moveslbl);
	ragequitbtn.set_sensitive(false);

	// Associate button "clicked" events with local onButtonClicked() method defined below.
	startbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::startButtonClicked));
	quitbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::quitButtonClicked));
	ragequitbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::rageButtonClicked));
	p1humanbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::p1humanButtonClicked));
	p2humanbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::p2humanButtonClicked));
	p3humanbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::p3humanButtonClicked));
	p4humanbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::p4humanButtonClicked));
	p1compbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::p1compButtonClicked));
	p2compbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::p2compButtonClicked));
	p3compbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::p3compButtonClicked));
	p4compbtn.signal_clicked().connect(sigc::mem_fun(*this, &View::p4compButtonClicked));
	handcard1.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked1));
	handcard2.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked2));
	handcard3.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked3));
	handcard4.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked4));
	handcard5.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked5));
	handcard6.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked6));
	handcard7.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked7));
	handcard8.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked8));
	handcard9.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked9));
	handcard10.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked10));
	handcard11.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked11));
	handcard12.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked12));
	handcard13.signal_clicked().connect(sigc::mem_fun(*this, &View::handButtonClicked13));
	show_all();
	// The final step is to display the buttons (they display themselves)


	// Register view as observer of model
	model_->subscribe(this);

} // View::View

View::~View() {}




void View::startButtonClicked(){		//start button clicked event
	ragequitbtn.set_sensitive(true);		//allow ragequit
	for (int i = 0; i < CARD_COUNT / PLAYER_COUNT; i++){		//allow buttons in hand to be clicked
		(*handbtn)[i].set_sensitive(true);
	}

	std::istringstream seedstring(seedentry.get_text());		//gets seed value from input
	seedstring >> seed;
	controller_->startButtonClicked(seed);

}
void View::quitButtonClicked(){				//quit button clicked
	controller_->quitButtonClicked();
}
void View::rageButtonClicked(){				//rage quit button clicked
	controller_->rageButtonClicked();
}
void View::handButtonClicked1(){			//buttons in hand clicked
	handButtonClicked(1);
}
void View::handButtonClicked2(){
	handButtonClicked(2);
}
void View::handButtonClicked3(){
	handButtonClicked(3);
}
void View::handButtonClicked4(){
	handButtonClicked(4);
}
void View::handButtonClicked5(){
	handButtonClicked(5);
}
void View::handButtonClicked6(){
	handButtonClicked(6);
}
void View::handButtonClicked7(){
	handButtonClicked(7);
}
void View::handButtonClicked8(){
	handButtonClicked(8);
}
void View::handButtonClicked9(){
	handButtonClicked(9);
}
void View::handButtonClicked10(){
	handButtonClicked(10);
}
void View::handButtonClicked11(){
	handButtonClicked(11);
}
void View::handButtonClicked12(){
	handButtonClicked(12);
}
void View::handButtonClicked13(){
	handButtonClicked(13);
}

void View::handButtonClicked(int index){		//use one function to handle all events of buttons in hand when clicked
	try{
		controller_->playcard(index);
	}
	catch (Player::IllegalPlayException ex){			//throw illegal play exception
		Gtk::MessageDialog illegalpop("Illegal Play!");
		illegalpop.run();
	}
}

void View::p1humanButtonClicked(){			//radio buttons clicked
	controller_->p1playertype("H");
}
void View::p2humanButtonClicked(){
	controller_->p2playertype("H");
}
void View::p3humanButtonClicked(){
	controller_->p3playertype("H");
}
void View::p4humanButtonClicked(){
	controller_->p4playertype("H");
}
void View::p1compButtonClicked(){
	controller_->p1playertype("C");
}
void View::p2compButtonClicked(){
	controller_->p2playertype("C");
}
void View::p3compButtonClicked(){
	controller_->p3playertype("C");
}
void View::p4compButtonClicked(){
	controller_->p4playertype("C");
}
void View::updateTable(){			//updates table with cards that are on the tables
	for (int i = 0; i < CARD_COUNT; i++){
		if (model_->getTable()[i]){
			(*clubs)[i].set(deck.setImage(i));			//only need address for first one (clubs)
		}
		else
			(*clubs)[i].set(deck.null());
	}
}
void View::update() {			//updates view
	stringstream ssm;
	vector<bool>checklegal = model_->convertLegal();
	ssm << "player " << (model_->getplayerindex() + 1);			//set text of label
	playerTurn.set_text("It is " + ssm.str() + "'s turn to play!");
	for (int i = 0; i < CARD_COUNT / PLAYER_COUNT; i++) {		//updates card images of cards in hand
		if (i < model_->getcurrentplayer()->gethand()->gethand().size()) {
			int place = model_->getcurrentplayer()->gethand()->gethand()[i]->getRank() + 13 * model_->getcurrentplayer()->gethand()->gethand()[i]->getSuit();
			(*handImage)[i].set(deck.setImage(place));
			if (checklegal.at(i)){			//colour code buttons of cards in hand
				(*handbtn)[i].modify_bg(Gtk::STATE_NORMAL, green);
			}
			else
				(*handbtn)[i].modify_bg(Gtk::STATE_NORMAL, red);
		}
		else{
			(*handImage)[i].set(deck.null());			//when card is played, set values of empty card
			(*handbtn)[i].modify_bg(Gtk::STATE_NORMAL, Gdk::Color(NULL));
		}
	}
	updateTable();
	for (int i = 0; i < PLAYER_COUNT; i++){			//radio buttons
		if (model_->getPlayerTypes()[i] == "H"){
			(*playerHumanbtn)[i].clicked();
		}
		else (*playerCompbtn)[i].clicked();
	}
	for (int i = 0; i < PLAYER_COUNT; i++){			//set label texts of players' scores and # of discards
		stringstream index;
		index << "\nPlayer ";
		index << i + 1;
		index << "\n\n     Score " << model_->getScores()[i];
		index << "\n\n     Discard ";
		index << model_->getDiscardSize()[i] << "\n";
		(*playerInfo)[i].set_text(index.str());
	}
	moveslbl.set_text(model_->getmoves());			//sets text of label showing moves by all players
	if (model_->getround() >= CARD_COUNT) {			//if all cards have been played
		for (int i = 0; i < CARD_COUNT / PLAYER_COUNT; i++){		//reset values of cards in hand
			(*handImage)[i].set(deck.null());
			(*handbtn)[i].modify_bg(Gtk::STATE_NORMAL, Gdk::Color(NULL));
			ragequitbtn.set_sensitive(false);
		}
		popUp(model_->getendgamemsgs());		//show end of game pop up
		if (model_->getwinner()) {		//if no winner exists, reset game for next round
			ragequitbtn.set_sensitive(true);
			controller_->initgame(seed);
		}
		else popUp(model_->getwinners());		//if winner exists, show winner message
	}
}
void View::popUp(string message){		//helper function - create pop up
	Gtk::MessageDialog msg(message);
	msg.run();
}
