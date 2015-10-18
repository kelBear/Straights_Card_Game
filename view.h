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


#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include <gtkmm.h>
#include "Card.h"
#include "DeckGUI.h"
#include "observer.h"

class Controller;
class Model;


class View : public Gtk::Window, public Observer {
public:
        View( Controller*, Model* );
	virtual ~View();
	virtual void update();	// Observer Pattern: concrete update() method

private:
	// Observer Pattern: to access Model accessors without having to downcast subject
	Model *model_;
	
	// Strategy Pattern member (plus signal handlers)
	Controller *controller_;

	// Card Images
	DeckGUI deck;

	// Member widgets:
    Gtk::HBox background;
    Gtk::VBox functionalitybox;
    Gtk::VBox gamebox;
    Gtk::VBox menubox;
    Gtk::Frame movesframe;
    Gtk::VBox movesbox;
    Gtk::Label moveslbl;
    Gtk::VScrollbar scrollbar;
    Gtk::Button startbtn;
    Gtk::VBox seedbox;
    Gtk::Label seedlbl;
    Gtk::Entry seedentry;
    Gtk::Button ragequitbtn;
    Gtk::Button quitbtn;
    Gtk::HBox allscorebox;
    Gtk::VBox p1box;
    Gtk::VBox p2box;
    Gtk::VBox p3box;
    Gtk::VBox p4box;
    Gtk::Table cardstbl;
    Gtk::HBox currenthandbox;
    Gtk::Label playerTurn;
    Gtk::Button handcard1;
    Gtk::Button handcard2;
    Gtk::Button handcard3;
    Gtk::Button handcard4;
    Gtk::Button handcard5;
    Gtk::Button handcard6;
    Gtk::Button handcard7;
    Gtk::Button handcard8;
    Gtk::Button handcard9;
    Gtk::Button handcard10;
    Gtk::Button handcard11;
    Gtk::Button handcard12;
    Gtk::Button handcard13;
    
	Gtk::HBox panels;      // Main window divided into two horizontal panels
	Gtk::VBox butBox;      // Vertical boxes for stacking buttons vertically
    Gtk::HBox deckBox;
	Gtk::Button next_button;
	Gtk::Button reset_button;
    Gtk::Button random_button;
	Gtk::Image card1;
    Gtk::Image card2;
    Gtk::Image card3;
    Gtk::Image card4;
    Gtk::Image card5;
    Gtk::Image card6;
    Gtk::Image card7;
    Gtk::Image card8;
    Gtk::Image card9;
    Gtk::Image card10;
    Gtk::Image card11;
    Gtk::Image card12;
    Gtk::Image card13;
    Gtk::Image CA;
    Gtk::Image C2;
    Gtk::Image C3;
    Gtk::Image C4;
    Gtk::Image C5;
    Gtk::Image C6;
    Gtk::Image C7;
    Gtk::Image C8;
    Gtk::Image C9;
    Gtk::Image C10;
    Gtk::Image CJ;
    Gtk::Image CQ;
    Gtk::Image CK;
    Gtk::Image HA;
    Gtk::Image H2;
    Gtk::Image H3;
    Gtk::Image H4;
    Gtk::Image H5;
    Gtk::Image H6;
    Gtk::Image H7;
    Gtk::Image H8;
    Gtk::Image H9;
    Gtk::Image H10;
    Gtk::Image HJ;
    Gtk::Image HQ;
    Gtk::Image HK;
    Gtk::Image SA;
    Gtk::Image S2;
    Gtk::Image S3;
    Gtk::Image S4;
    Gtk::Image S5;
    Gtk::Image S6;
    Gtk::Image S7;
    Gtk::Image S8;
    Gtk::Image S9;
    Gtk::Image S10;
    Gtk::Image SJ;
    Gtk::Image SQ;
    Gtk::Image SK;
    Gtk::Image DA;
    Gtk::Image D2;
    Gtk::Image D3;
    Gtk::Image D4;
    Gtk::Image D5;
    Gtk::Image D6;
    Gtk::Image D7;
    Gtk::Image D8;
    Gtk::Image D9;
    Gtk::Image D10;
    Gtk::Image DJ;
    Gtk::Image DQ;
    Gtk::Image DK;
    Gtk::Label p1info;
    Gtk::Label p2info;
    Gtk::Label p3info;
    Gtk::Label p4info;
    Gtk::Frame p1infoFrame;
    Gtk::Frame p2infoFrame;
    Gtk::Frame p3infoFrame;
    Gtk::Frame p4infoFrame;
    Gtk::VBox p1typebox;
    Gtk::VBox p2typebox;
    Gtk::VBox p3typebox;
    Gtk::VBox p4typebox;
    Gtk::ScrolledWindow moveScroll;
    Gtk::RadioButton p1humanbtn, p2humanbtn,  p3humanbtn,  p4humanbtn, p1compbtn, p2compbtn,  p3compbtn,  p4compbtn;

    Gtk::Image *handImage[CARD_COUNT/PLAYER_COUNT];		//array of images of cards in hand
	Gtk::Button *handbtn[CARD_COUNT / PLAYER_COUNT];	//array of buttons of cards in hand
	Gtk::VBox *playerbox[PLAYER_COUNT];					//array of vbox for each player
	Gtk::VBox *playerTypebox[PLAYER_COUNT];				//array of vbox for each player to determine type of player
	Gtk::RadioButton *playerHumanbtn[PLAYER_COUNT];		//array of human radio button for each player
	Gtk::RadioButton *playerCompbtn[PLAYER_COUNT];		//array of computer radio button for each player
	Gtk::Image *spades[CARD_COUNT / SUIT_COUNT];		//array of spades images for table
    Gtk::Image *clubs[CARD_COUNT/SUIT_COUNT];			//array of clubs images for table
    Gtk::Image *hearts[CARD_COUNT/SUIT_COUNT];			//array of hearts images for table
    Gtk::Image *diamonds[CARD_COUNT/SUIT_COUNT];		//array of diamonds images for table
    Gtk::Label *playerInfo[PLAYER_COUNT];				//array of Label for player's score and # of discards
    Gtk::Frame *infoFrame[SUIT_COUNT];					//array of Frame to hold player's info
    
    int seed;
    Gdk::Color green;		//colour for border of buttons for hand to provide visual aid (green for play, red for discard)
    Gdk::Color red;
    
    // Signal handlers:
    void startButtonClicked();		//start button
    void quitButtonClicked();		//quit button
    void handButtonClicked1();		//hand cards
    void handButtonClicked2();
    void handButtonClicked3();
    void handButtonClicked4();
    void handButtonClicked5();
    void handButtonClicked6();
    void handButtonClicked7();
    void handButtonClicked8();
    void handButtonClicked9();
    void handButtonClicked10();
    void handButtonClicked11();
    void handButtonClicked12();
    void handButtonClicked13();
    void p1humanButtonClicked();	//human radio buttons
    void p2humanButtonClicked();
    void p3humanButtonClicked();
    void p4humanButtonClicked();
    void p1compButtonClicked();		//computer radio buttons
    void p2compButtonClicked();
    void p3compButtonClicked();
    void p4compButtonClicked();
    void handButtonClicked(int);	//helper function for hand cards button
    void rageButtonClicked();		//rage quit

    void popUp(std::string);		//helper function for pop up box
    void updateTable();				//helper function to update table
}; // View

#endif
