/****************************************************************************/
/* BEGIN FILE qtcolortable.cpp                                              */
/*                                                                          */
/****************************************************************************/
/* PURPOSE                                                                  */
/*                                                                          */
/****************************************************************************/
/* DESIGN NOTES                                                             */
/*                                                                          */
/****************************************************************************/
/* REVISION HISTORY                                                         */
/*                                                                          */
/*   Initial Code:                                                          */
/*      @author    jsowers           26MAY24                                */
/*                                                                          */
/*   Modifications:                                                         */
/*                                                                          */
/****************************************************************************/
/* INCLUDE FILES                                                            */
/*                                                                          */

#include <iostream>
#include <QComboBox>
#include <QString>
#include <qcolor.h>
#include "qtcolortable.h"
#include "../ColorTable/Color.h"
#include "../ColorTable/ColorTable.h"
#include <cmath>

using namespace std;

/*                                                                          */
/****************************************************************************/
/* DEFINES                                                                  */
/*                                                                          */
/****************************************************************************/

/**
 * Default Constructor.
 *
 * \param parent a pointer to a QWidget.
 */
QtColorTable::QtColorTable (QWidget* parent) : QMainWindow (parent) {
	ui.setupUi (this);
	ui.redSlider->setStyleSheet ("QSlider::groove:horizontal {background-color:red;height:16px;}"
		"QSlider::handle:horizontal {background-color:black; height: 16px; width: 4px;}");
	ui.greenSlider_2->setStyleSheet ("QSlider::groove:horizontal {background-color:green;height:16px;}"
		"QSlider::handle:horizontal {background-color:black; height: 16px; width: 4px;}");
	ui.blueSlider_3->setStyleSheet ("QSlider::groove:horizontal {background-color:blue;height:16px;}"
		"QSlider::handle:horizontal {background-color:black; height: 16px; width: 4px;}");

	connect (ui.findBtn, &QPushButton::clicked, this, &QtColorTable::findClosestNamedColor);

	setSignals (true);

	loadNameList ();
	loadComboBox ();
	ui.colorNameCB->setCurrentIndex (0);
}

/**
 * Default Destructor.
 *
 */
QtColorTable::~QtColorTable () {}

/**
 * Loads the list of Color Names.
 */
void QtColorTable::loadNameList () {
	nameList.append ("Alaska Sky");
	nameList.append ("Alice Blue");
	nameList.append ("Alizarin Crimson");
	nameList.append ("Almond");
	nameList.append ("Aluminum");
	nameList.append ("Amethyst");
	nameList.append ("Anjou Pear");
	nameList.append ("Antiquewhite ");
	nameList.append ("Antiquewhite1");
	nameList.append ("Antiquewhite2");
	nameList.append ("Antiquewhite3");
	nameList.append ("Antiquewhite4");
	nameList.append ("Apple");
	nameList.append ("Apricot");
	nameList.append ("Aqua");
	nameList.append ("Aquaman");
	nameList.append ("Aquamarine");
	nameList.append ("Aquamarine");
	nameList.append ("Aquamarine ");
	nameList.append ("Aquamarine2");
	nameList.append ("Aquamarine4");
	nameList.append ("Aquarium");
	nameList.append ("Army Men");
	nameList.append ("Army Uniform");
	nameList.append ("Ash");
	nameList.append ("Atlantic Green");
	nameList.append ("Aureoline Yellow");
	nameList.append ("Avacado");
	nameList.append ("Avocado");
	nameList.append ("Azure ");
	nameList.append ("Azure2");
	nameList.append ("Azure3");
	nameList.append ("Azure4");
	nameList.append ("Bacon");
	nameList.append ("Bakers Chocolate");
	nameList.append ("Banana");
	nameList.append ("Banker's Lamp");
	nameList.append ("Barney");
	nameList.append ("Bartlett Pear");
	nameList.append ("Battleship");
	nameList.append ("Beach Sand");
	nameList.append ("Beer");
	nameList.append ("Beige ");
	nameList.append ("Beige Dark ");
	nameList.append ("Bermuda Sand");
	nameList.append ("Big Blue Bus");
	nameList.append ("Bing Cherry");
	nameList.append ("Bisque ");
	nameList.append ("Bisque2");
	nameList.append ("Bisque3");
	nameList.append ("Bisque4");
	nameList.append ("Black");
	nameList.append ("Black Beauty Plum");
	nameList.append ("Blackberry");
	nameList.append ("Blanched Almond ");
	nameList.append ("Blood Orange");
	nameList.append ("Bloodred");
	nameList.append ("Blue ");
	nameList.append ("Blue Angels");
	nameList.append ("Blue Bird");
	nameList.append ("Blue Bucket");
	nameList.append ("Blue Corn");
	nameList.append ("Blue Corn Chips");
	nameList.append ("Blue Cow");
	nameList.append ("Blue Deep");
	nameList.append ("Blue Dog");
	nameList.append ("Blue Fern");
	nameList.append ("Blue Grapes");
	nameList.append ("Blue Green Algae");
	nameList.append ("Blue Ice");
	nameList.append ("Blue Ice");
	nameList.append ("Blue Jeans");
	nameList.append ("Blue Lagoon");
	nameList.append ("Blue Line");
	nameList.append ("Blue Mist");
	nameList.append ("Blue Nile");
	nameList.append ("Blue Pill");
	nameList.append ("Blue Ridge Mtns");
	nameList.append ("Blue Safe");
	nameList.append ("Blue Shark");
	nameList.append ("Blue Spider");
	nameList.append ("Blue Sponge");
	nameList.append ("Blue Stone");
	nameList.append ("Blue Train");
	nameList.append ("Blue Tuna");
	nameList.append ("Blue Velvet");
	nameList.append ("Blue Whale");
	nameList.append ("Blue2");
	nameList.append ("Blueberry Fresh");
	nameList.append ("Bluegrass");
	nameList.append ("Blueviolet");
	nameList.append ("Blueviolet ");
	nameList.append ("Bone");
	nameList.append ("Bordeaux");
	nameList.append ("Bottle Green");
	nameList.append ("Braeburn Apple");
	nameList.append ("Brass");
	nameList.append ("Bread");
	nameList.append ("Breadfruit");
	nameList.append ("Brick");
	nameList.append ("Bright Gold");
	nameList.append ("Bright Red");
	nameList.append ("Broadway Pink");
	nameList.append ("Broccoli");
	nameList.append ("Bronze");
	nameList.append ("Bronzeii");
	nameList.append ("Brown");
	nameList.append ("Brown Madder");
	nameList.append ("Brown Ochre");
	nameList.append ("Brown1");
	nameList.append ("Brown2");
	nameList.append ("Brown3");
	nameList.append ("Brushed Aluminum");
	nameList.append ("Bubble Gum");
	nameList.append ("Bunny Eye");
	nameList.append ("Burgundy");
	nameList.append ("Burlywood ");
	nameList.append ("Burlywood2");
	nameList.append ("Burlywood3");
	nameList.append ("Burlywood4");
	nameList.append ("Burnt Sienna");
	nameList.append ("Burnt Umber");
	nameList.append ("Cactus");
	nameList.append ("Cadetblue");
	nameList.append ("Cadetblue1");
	nameList.append ("Cadetblue2");
	nameList.append ("Cadetblue3");
	nameList.append ("Cadetblue4");
	nameList.append ("Cadmium Lemon");
	nameList.append ("Cadmium Orange");
	nameList.append ("Cadmium Red Deep");
	nameList.append ("Cadmium Red Light");
	nameList.append ("Cadmium Yellow");
	nameList.append ("Cadmium Yellowlight");
	nameList.append ("Cafe Americano");
	nameList.append ("Cafe Au Lait");
	nameList.append ("Camo1");
	nameList.append ("Camo2");
	nameList.append ("Camo3");
	nameList.append ("Cantaloupe");
	nameList.append ("Canvas");
	nameList.append ("Cappuccino");
	nameList.append ("Caribbean");
	nameList.append ("Carnation");
	nameList.append ("Carolina Blue");
	nameList.append ("Carrot");
	nameList.append ("Cashew");
	nameList.append ("Cat Eye");
	nameList.append ("Cat Eye2");
	nameList.append ("Celery");
	nameList.append ("Celtics");
	nameList.append ("Cerulean");
	nameList.append ("Chartreuse ");
	nameList.append ("Chartreuse Verte");
	nameList.append ("Chartreuse2");
	nameList.append ("Chartreuse3");
	nameList.append ("Chartreuse4");
	nameList.append ("Cheddar");
	nameList.append ("Chemical Suit");
	nameList.append ("Cherry");
	nameList.append ("Chili");
	nameList.append ("Chili Powder");
	nameList.append ("Chocolate");
	nameList.append ("Chocolate ");
	nameList.append ("Chocolate1");
	nameList.append ("Chocolate2");
	nameList.append ("Chocolate3");
	nameList.append ("Chrome");
	nameList.append ("Chrome Oxide Green");
	nameList.append ("Cichlid");
	nameList.append ("Cinnabar Green");
	nameList.append ("Cinnamon");
	nameList.append ("Cinnamon");
	nameList.append ("Circuit Board");
	nameList.append ("Clover");
	nameList.append ("Cobalt");
	nameList.append ("Cobalt");
	nameList.append ("Cobalt Green");
	nameList.append ("Cobalt Violet Deep");
	nameList.append ("Coconut");
	nameList.append ("Coconut Shell");
	nameList.append ("Coffee");
	nameList.append ("Coke Bottle");
	nameList.append ("Cola");
	nameList.append ("Cold Grey");
	nameList.append ("Conch");
	nameList.append ("Concord Grape");
	nameList.append ("Cool Copper");
	nameList.append ("Cool Mint");
	nameList.append ("Cooler");
	nameList.append ("Copper");
	nameList.append ("Coral ");
	nameList.append ("Coral1");
	nameList.append ("Coral2");
	nameList.append ("Coral3");
	nameList.append ("Coral4");
	nameList.append ("Corfu Pink");
	nameList.append ("Corn");
	nameList.append ("Cornflower");
	nameList.append ("Cornflower Blue");
	nameList.append ("Cornflower Blue 2");
	nameList.append ("Cornsilk ");
	nameList.append ("Cornsilk2");
	nameList.append ("Cornsilk3");
	nameList.append ("Cornsilk4");
	nameList.append ("Cotton Candy");
	nameList.append ("Cranberry");
	nameList.append ("Cranberry Jello");
	nameList.append ("Crema");
	nameList.append ("Crimson ");
	nameList.append ("Cucumber");
	nameList.append ("Curacao");
	nameList.append ("Cyan ");
	nameList.append ("Cyan2");
	nameList.append ("Cyan3");
	nameList.append ("Dark   Goldenrod ");
	nameList.append ("Dark   Goldenrod1");
	nameList.append ("Dark   Goldenrod2");
	nameList.append ("Dark   Goldenrod3");
	nameList.append ("Dark  Blue ");
	nameList.append ("Dark  Cherry Red");
	nameList.append ("Dark  Cyan ");
	nameList.append ("Dark  Goldenrod4");
	nameList.append ("Dark  Gray ");
	nameList.append ("Dark  Green");
	nameList.append ("Dark  Green ");
	nameList.append ("Dark  Green Copper");
	nameList.append ("Dark  Grey ");
	nameList.append ("Dark  Khaki ");
	nameList.append ("Dark  Wheat");
	nameList.append ("Dark Magenta ");
	nameList.append ("Dark Olivegreen");
	nameList.append ("Dark Olivegreen ");
	nameList.append ("Dark Olivegreen1");
	nameList.append ("Dark Olivegreen2");
	nameList.append ("Dark Olivegreen3");
	nameList.append ("Dark Olivegreen4");
	nameList.append ("Dark Orange ");
	nameList.append ("Dark Orange1");
	nameList.append ("Dark Orange2");
	nameList.append ("Dark Orange3");
	nameList.append ("Dark Orange4");
	nameList.append ("Dark Orange5");
	nameList.append ("Dark Orchid");
	nameList.append ("Dark Orchid ");
	nameList.append ("Dark Orchid2");
	nameList.append ("Dark Orchid3");
	nameList.append ("Dark Orchid4");
	nameList.append ("Dark Purple");
	nameList.append ("Dark Red ");
	nameList.append ("Dark Salmon ");
	nameList.append ("Dark Seagreen ");
	nameList.append ("Dark Seagreen1");
	nameList.append ("Dark Seagreen2");
	nameList.append ("Dark Seagreen3");
	nameList.append ("Dark Seagreen4");
	nameList.append ("Dark Slateblue");
	nameList.append ("Dark Slateblue ");
	nameList.append ("Dark Slategray ");
	nameList.append ("Dark Slategray1");
	nameList.append ("Dark Slategray2");
	nameList.append ("Dark Slategray3");
	nameList.append ("Dark Slategray4");
	nameList.append ("Dark Slategrey ");
	nameList.append ("Dark Tan");
	nameList.append ("Dark Turquoise");
	nameList.append ("Dark Turquoise ");
	nameList.append ("Dark Violet ");
	nameList.append ("Dark Wood");
	nameList.append ("Deep Ochre");
	nameList.append ("Deep Pink ");
	nameList.append ("Deep Pink2");
	nameList.append ("Deep Pink3");
	nameList.append ("Deep Pink4");
	nameList.append ("Deep Purple");
	nameList.append ("Deep Skyblue ");
	nameList.append ("Deep Skyblue2");
	nameList.append ("Deep Skyblue3");
	nameList.append ("Deep Skyblue4");
	nameList.append ("Delft");
	nameList.append ("Denim");
	nameList.append ("Desert Sand");
	nameList.append ("Diamond Blue");
	nameList.append ("Dimgray ");
	nameList.append ("Dimgrey ");
	nameList.append ("Dodgerblue ");
	nameList.append ("Dodgerblue2");
	nameList.append ("Dodgerblue3");
	nameList.append ("Dodgerblue4");
	nameList.append ("Dog Tongue");
	nameList.append ("Dolphin");
	nameList.append ("Douglas Fir");
	nameList.append ("Dress Blue");
	nameList.append ("Dumpster");
	nameList.append ("Dustyrose");
	nameList.append ("Eggplant");
	nameList.append ("Eggshell");
	nameList.append ("Electric Turquoise");
	nameList.append ("Emerald");
	nameList.append ("Emerald City");
	nameList.append ("Emerald Green");
	nameList.append ("Emerald Green2");
	nameList.append ("England Pound");
	nameList.append ("Englishred");
	nameList.append ("Espresso");
	nameList.append ("Feldspar");
	nameList.append ("Fenway Grass");
	nameList.append ("Fenway Monster");
	nameList.append ("Fire Truck Green");
	nameList.append ("Firebrick ");
	nameList.append ("Firebrick1");
	nameList.append ("Firebrick2");
	nameList.append ("Firebrick3");
	nameList.append ("Firebrick4");
	nameList.append ("Firebrick5");
	nameList.append ("Fisherman's Float");
	nameList.append ("Flat Pink");
	nameList.append ("Flesh Ochre");
	nameList.append ("Floral White ");
	nameList.append ("Fog");
	nameList.append ("Forestgreen2");
	nameList.append ("Forget Me Nots");
	nameList.append ("Fraser Fir");
	nameList.append ("Fresh Green");
	nameList.append ("Frog");
	nameList.append ("Fuchsia ");
	nameList.append ("Fuchsia2");
	nameList.append ("Fuji Apple");
	nameList.append ("Gainsboro ");
	nameList.append ("Ganegreen");
	nameList.append ("Garden Hose");
	nameList.append ("Garden Plum");
	nameList.append ("Geranium Lake");
	nameList.append ("Ghostwhite ");
	nameList.append ("Go");
	nameList.append ("Gold ");
	nameList.append ("Gold Green");
	nameList.append ("Gold Ochre");
	nameList.append ("Gold2");
	nameList.append ("Gold3");
	nameList.append ("Gold4");
	nameList.append ("Gold5");
	nameList.append ("Gold6");
	nameList.append ("Gold7");
	nameList.append ("Golden Delicious Apple");
	nameList.append ("Goldenrod");
	nameList.append ("Goldenrod ");
	nameList.append ("Goldenrod1");
	nameList.append ("Goldenrod2");
	nameList.append ("Goldenrod3");
	nameList.append ("Goldenrod4");
	nameList.append ("Grape");
	nameList.append ("Grape");
	nameList.append ("Grapefruit");
	nameList.append ("Grass");
	nameList.append ("Gray");
	nameList.append ("Gray ");
	nameList.append ("Gray1");
	nameList.append ("Gray10");
	nameList.append ("Gray11");
	nameList.append ("Gray12");
	nameList.append ("Gray13");
	nameList.append ("Gray14");
	nameList.append ("Gray15");
	nameList.append ("Gray16");
	nameList.append ("Gray17");
	nameList.append ("Gray18");
	nameList.append ("Gray19");
	nameList.append ("Gray2");
	nameList.append ("Gray20");
	nameList.append ("Gray21");
	nameList.append ("Gray22");
	nameList.append ("Gray23");
	nameList.append ("Gray24");
	nameList.append ("Gray25");
	nameList.append ("Gray26");
	nameList.append ("Gray27");
	nameList.append ("Gray28");
	nameList.append ("Gray29");
	nameList.append ("Gray3");
	nameList.append ("Gray30");
	nameList.append ("Gray31");
	nameList.append ("Gray32");
	nameList.append ("Gray33");
	nameList.append ("Gray34");
	nameList.append ("Gray35");
	nameList.append ("Gray36");
	nameList.append ("Gray37");
	nameList.append ("Gray38");
	nameList.append ("Gray39");
	nameList.append ("Gray4");
	nameList.append ("Gray40");
	nameList.append ("Gray42");
	nameList.append ("Gray43");
	nameList.append ("Gray44");
	nameList.append ("Gray45");
	nameList.append ("Gray46");
	nameList.append ("Gray47");
	nameList.append ("Gray48");
	nameList.append ("Gray49");
	nameList.append ("Gray5");
	nameList.append ("Gray50");
	nameList.append ("Gray51");
	nameList.append ("Gray52");
	nameList.append ("Gray53");
	nameList.append ("Gray54");
	nameList.append ("Gray55");
	nameList.append ("Gray56");
	nameList.append ("Gray57");
	nameList.append ("Gray58");
	nameList.append ("Gray59");
	nameList.append ("Gray6");
	nameList.append ("Gray60");
	nameList.append ("Gray61");
	nameList.append ("Gray62");
	nameList.append ("Gray63");
	nameList.append ("Gray64");
	nameList.append ("Gray65");
	nameList.append ("Gray66");
	nameList.append ("Gray67");
	nameList.append ("Gray68");
	nameList.append ("Gray69");
	nameList.append ("Gray7");
	nameList.append ("Gray70");
	nameList.append ("Gray71");
	nameList.append ("Gray72");
	nameList.append ("Gray73");
	nameList.append ("Gray74");
	nameList.append ("Gray75");
	nameList.append ("Gray76");
	nameList.append ("Gray77");
	nameList.append ("Gray78");
	nameList.append ("Gray79");
	nameList.append ("Gray8");
	nameList.append ("Gray80");
	nameList.append ("Gray81");
	nameList.append ("Gray82");
	nameList.append ("Gray83");
	nameList.append ("Gray84");
	nameList.append ("Gray85");
	nameList.append ("Gray86");
	nameList.append ("Gray87");
	nameList.append ("Gray88");
	nameList.append ("Gray89");
	nameList.append ("Gray9");
	nameList.append ("Gray90");
	nameList.append ("Gray91");
	nameList.append ("Gray92");
	nameList.append ("Gray93");
	nameList.append ("Gray94");
	nameList.append ("Gray95");
	nameList.append ("Gray97");
	nameList.append ("Gray98");
	nameList.append ("Gray99");
	nameList.append ("Greek Roof");
	nameList.append ("Green ");
	nameList.append ("Green Agate");
	nameList.append ("Green Algae");
	nameList.append ("Green Apple");
	nameList.append ("Green Ash");
	nameList.append ("Green Bark");
	nameList.append ("Green Card");
	nameList.append ("Green Cheese");
	nameList.append ("Green Gables");
	nameList.append ("Green Goo");
	nameList.append ("Green Grape");
	nameList.append ("Green Grass Of Home");
	nameList.append ("Green Hornet");
	nameList.append ("Green Lantern");
	nameList.append ("Green Led");
	nameList.append ("Green Line");
	nameList.append ("Green Mist");
	nameList.append ("Green Mm");
	nameList.append ("Green Moth");
	nameList.append ("Green Party");
	nameList.append ("Green Pepper");
	nameList.append ("Green Quartz");
	nameList.append ("Green Scrubs");
	nameList.append ("Green Soap");
	nameList.append ("Green Stamp");
	nameList.append ("Green Taxi");
	nameList.append ("Green Visor");
	nameList.append ("Green2");
	nameList.append ("Green3");
	nameList.append ("Green4");
	nameList.append ("Greencopper");
	nameList.append ("Greenyellow");
	nameList.append ("Greenyellow ");
	nameList.append ("Grey ");
	nameList.append ("Guacamole");
	nameList.append ("Gummi Green");
	nameList.append ("Gummi Red");
	nameList.append ("Gummi Yellow");
	nameList.append ("Harold'S Crayon");
	nameList.append ("Heather Blue");
	nameList.append ("Hematite");
	nameList.append ("Holly");
	nameList.append ("Honey");
	nameList.append ("Honeydew ");
	nameList.append ("Honeydew2");
	nameList.append ("Honeydew3");
	nameList.append ("Honeydew4");
	nameList.append ("Hotpink ");
	nameList.append ("Hotpink1");
	nameList.append ("Hotpink2");
	nameList.append ("Hotpink3");
	nameList.append ("Hotpink4");
	nameList.append ("Huntergreen");
	nameList.append ("Iceberg Lettuce");
	nameList.append ("Indianred");
	nameList.append ("Indianred ");
	nameList.append ("Indianred1");
	nameList.append ("Indianred2");
	nameList.append ("Indianred3");
	nameList.append ("Indianred4");
	nameList.append ("Indiglo");
	nameList.append ("Indigo");
	nameList.append ("Indigo ");
	nameList.append ("Indigo Dye");
	nameList.append ("Indigo Tile");
	nameList.append ("Indigo2");
	nameList.append ("Irish Flag");
	nameList.append ("Isle Royale Greenstone");
	nameList.append ("Ivory ");
	nameList.append ("Ivory2");
	nameList.append ("Ivory3");
	nameList.append ("Ivory4");
	nameList.append ("Ivoryblack");
	nameList.append ("Jack Pine");
	nameList.append ("Jolly Green");
	nameList.append ("Jonathan Apple");
	nameList.append ("Kakapo");
	nameList.append ("Kelly");
	nameList.append ("Kermit");
	nameList.append ("Key Lime Pie");
	nameList.append ("Khaki");
	nameList.append ("Khaki ");
	nameList.append ("Khaki1");
	nameList.append ("Khaki2");
	nameList.append ("Khaki3");
	nameList.append ("Khaki4");
	nameList.append ("Kidney Bean");
	nameList.append ("Kiwi");
	nameList.append ("Kumquat");
	nameList.append ("La Maison Bleue");
	nameList.append ("Lake Erie");
	nameList.append ("Lake Huron");
	nameList.append ("Lake Ontario");
	nameList.append ("Lake Superior");
	nameList.append ("Lampblack");
	nameList.append ("Latte");
	nameList.append ("Lavender");
	nameList.append ("Lavender ");
	nameList.append ("Lavender Field");
	nameList.append ("Lavenderblush ");
	nameList.append ("Lavenderblush2");
	nameList.append ("Lavenderblush3");
	nameList.append ("Lavenderblush4");
	nameList.append ("Lawngreen ");
	nameList.append ("Lcd Back");
	nameList.append ("Lcd Dark ");
	nameList.append ("Leaf");
	nameList.append ("Lemon");
	nameList.append ("Lemonchiffon ");
	nameList.append ("Lemonchiffon2");
	nameList.append ("Lemonchiffon3");
	nameList.append ("Lemonchiffon4");
	nameList.append ("Liberty");
	nameList.append ("Lichen");
	nameList.append ("Light Blue");
	nameList.append ("Light Blue");
	nameList.append ("Light Blue ");
	nameList.append ("Light Blue1");
	nameList.append ("Light Blue3");
	nameList.append ("Light Blue4");
	nameList.append ("Light Copper");
	nameList.append ("Light Coral ");
	nameList.append ("Light Cyan ");
	nameList.append ("Light Cyan2");
	nameList.append ("Light Cyan3");
	nameList.append ("Light Cyan4");
	nameList.append ("Light Goldenrod");
	nameList.append ("Light Goldenrod Yellow ");
	nameList.append ("Light Goldenrod1");
	nameList.append ("Light Goldenrod2");
	nameList.append ("Light Goldenrod3");
	nameList.append ("Light Goldenrod4");
	nameList.append ("Light Gray ");
	nameList.append ("Light Green ");
	nameList.append ("Light Grey ");
	nameList.append ("Light Pink ");
	nameList.append ("Light Pink1");
	nameList.append ("Light Pink2");
	nameList.append ("Light Pink3");
	nameList.append ("Light Pink4");
	nameList.append ("Light Salmon ");
	nameList.append ("Light Salmon2");
	nameList.append ("Light Salmon3");
	nameList.append ("Light Salmon4");
	nameList.append ("Light Seagreen ");
	nameList.append ("Light Skyblue ");
	nameList.append ("Light Skyblue1");
	nameList.append ("Light Skyblue2");
	nameList.append ("Light Skyblue3");
	nameList.append ("Light Skyblue4");
	nameList.append ("Light Slateblue");
	nameList.append ("Light Slategray");
	nameList.append ("Light Slategrey");
	nameList.append ("Light Steelblue");
	nameList.append ("Light Steelblue ");
	nameList.append ("Light Steelblue1");
	nameList.append ("Light Steelblue2");
	nameList.append ("Light Steelblue3");
	nameList.append ("Light Steelblue4");
	nameList.append ("Light Teal");
	nameList.append ("Light Wood");
	nameList.append ("Light Yellow ");
	nameList.append ("Light Yellow2");
	nameList.append ("Light Yellow3");
	nameList.append ("Light Yellow4");
	nameList.append ("Lime ");
	nameList.append ("Lime Green ");
	nameList.append ("Lime Pulp");
	nameList.append ("Lime Rind");
	nameList.append ("Lindsay Eyes");
	nameList.append ("Linen ");
	nameList.append ("Liz Eyes");
	nameList.append ("Lizard");
	nameList.append ("Madder Lake Deep");
	nameList.append ("Magenta");
	nameList.append ("Magenta2");
	nameList.append ("Magenta3");
	nameList.append ("Mailbox");
	nameList.append ("Malachite");
	nameList.append ("Malta Blue");
	nameList.append ("Manatee Gray");
	nameList.append ("Mandarian Orange");
	nameList.append ("Manganese Blue");
	nameList.append ("Maroon ");
	nameList.append ("Maroon1");
	nameList.append ("Maroon3");
	nameList.append ("Maroon4");
	nameList.append ("Maroon5");
	nameList.append ("Maroon6");
	nameList.append ("Maroonb0");
	nameList.append ("Mars Orange");
	nameList.append ("Mars Yellow");
	nameList.append ("Martini Olive");
	nameList.append ("Masters Jacket");
	nameList.append ("Mediterranean");
	nameList.append ("Medium Aquamarine ");
	nameList.append ("Medium Aquamarine2");
	nameList.append ("Medium Aquamarine3");
	nameList.append ("Medium Blue");
	nameList.append ("Medium Blue ");
	nameList.append ("Medium Blue2");
	nameList.append ("Medium Goldenrod");
	nameList.append ("Medium Orchid ");
	nameList.append ("Medium Orchid1");
	nameList.append ("Medium Orchid2");
	nameList.append ("Medium Orchid3");
	nameList.append ("Medium Orchid4");
	nameList.append ("Medium Purple ");
	nameList.append ("Medium Purple1");
	nameList.append ("Medium Purple2");
	nameList.append ("Medium Purple3");
	nameList.append ("Medium Purple4");
	nameList.append ("Medium Seagreen");
	nameList.append ("Medium Seagreen ");
	nameList.append ("Medium Slateblue ");
	nameList.append ("Medium Slateblue2");
	nameList.append ("Medium Springgreen ");
	nameList.append ("Medium Turquoise");
	nameList.append ("Medium Turquoise ");
	nameList.append ("Medium Violetred ");
	nameList.append ("Medium Wood");
	nameList.append ("Melon");
	nameList.append ("Melonrind Green");
	nameList.append ("Metallic Mint");
	nameList.append ("Midnight Blue ");
	nameList.append ("Midnight Blue2");
	nameList.append ("Midnightblue");
	nameList.append ("Mint Blue");
	nameList.append ("Mint Candy");
	nameList.append ("Mint Green");
	nameList.append ("Mint Ice Cream");
	nameList.append ("Mintcream ");
	nameList.append ("Mistyrose ");
	nameList.append ("Mistyrose2");
	nameList.append ("Mistyrose3");
	nameList.append ("Mistyrose4");
	nameList.append ("Moccasin ");
	nameList.append ("Mocha Latte");
	nameList.append ("Moon");
	nameList.append ("Mtn Dew Bottle");
	nameList.append ("Mustard");
	nameList.append ("Naples Yellow Deep");
	nameList.append ("Natural Gas");
	nameList.append ("Natural Turquoise");
	nameList.append ("Navajowhite ");
	nameList.append ("Navajowhite2");
	nameList.append ("Navajowhite3");
	nameList.append ("Navajowhite4");
	nameList.append ("Navy ");
	nameList.append ("Navy Blue");
	nameList.append ("Nectarine");
	nameList.append ("Neon Avocado");
	nameList.append ("Neon Blue");
	nameList.append ("Neon Blue");
	nameList.append ("Neon Green");
	nameList.append ("Neon Pink");
	nameList.append ("Neptune");
	nameList.append ("Nerf Green");
	nameList.append ("New $20");
	nameList.append ("New Midnightblue");
	nameList.append ("New Tan");
	nameList.append ("Night Vision");
	nameList.append ("Nikko Blue");
	nameList.append ("Noble Fir");
	nameList.append ("Novascotia Salmon");
	nameList.append ("Nypd Blue");
	nameList.append ("Obsidian");
	nameList.append ("Ochre");
	nameList.append ("Octopus");
	nameList.append ("Offwhiteblue");
	nameList.append ("Offwhitegreen");
	nameList.append ("Old Copper");
	nameList.append ("Old Gold");
	nameList.append ("Old Green");
	nameList.append ("Old Lace ");
	nameList.append ("Old Money");
	nameList.append ("Olive ");
	nameList.append ("Olive3B");
	nameList.append ("Olivedrab ");
	nameList.append ("Olivedrab1");
	nameList.append ("Olivedrab2");
	nameList.append ("Olivedrab4");
	nameList.append ("Ooze");
	nameList.append ("Orange");
	nameList.append ("Orange");
	nameList.append ("Orange");
	nameList.append ("Orange ");
	nameList.append ("Orange Candy");
	nameList.append ("Orange Crush");
	nameList.append ("Orange2");
	nameList.append ("Orange3");
	nameList.append ("Orange4");
	nameList.append ("Orange5");
	nameList.append ("Orangered");
	nameList.append ("Orangered");
	nameList.append ("Orangered ");
	nameList.append ("Orangered2");
	nameList.append ("Orangered3");
	nameList.append ("Orangered4");
	nameList.append ("Orchid");
	nameList.append ("Orchid ");
	nameList.append ("Orchid1");
	nameList.append ("Orchid2");
	nameList.append ("Orchid3");
	nameList.append ("Orchid4");
	nameList.append ("Oregon Salmon");
	nameList.append ("Organic Tea");
	nameList.append ("Pabst Blue");
	nameList.append ("Pacific Blue");
	nameList.append ("Pacific Green");
	nameList.append ("Packer Gold");
	nameList.append ("Packer Green");
	nameList.append ("Pale Green ");
	nameList.append ("Pale Green1");
	nameList.append ("Pale Green3");
	nameList.append ("Pale Green4");
	nameList.append ("Pale Turquoise ");
	nameList.append ("Pale Turquoise1");
	nameList.append ("Pale Turquoise2");
	nameList.append ("Pale Turquoise3");
	nameList.append ("Pale Turquoise4");
	nameList.append ("Pale Violetred ");
	nameList.append ("Pale Violetred1");
	nameList.append ("Pale Violetred2");
	nameList.append ("Pale Violetred3");
	nameList.append ("Pale Violetred4");
	nameList.append ("Palegoldenrod ");
	nameList.append ("Palm");
	nameList.append ("Papaya");
	nameList.append ("Papayawhip ");
	nameList.append ("Park Bench");
	nameList.append ("Park Ranger");
	nameList.append ("Parrot");
	nameList.append ("Parrot Green");
	nameList.append ("Passion Fruit");
	nameList.append ("Pastel Blue");
	nameList.append ("Pastel Green");
	nameList.append ("Pea");
	nameList.append ("Pea");
	nameList.append ("Peach");
	nameList.append ("Peach");
	nameList.append ("Peachpuff");
	nameList.append ("Peachpuff ");
	nameList.append ("Peachpuff2");
	nameList.append ("Peachpuff3");
	nameList.append ("Peachpuff4");
	nameList.append ("Peacock");
	nameList.append ("Peafowl");
	nameList.append ("Pear");
	nameList.append ("Pecan");
	nameList.append ("Periwinkle");
	nameList.append ("Permanent Green");
	nameList.append ("Permanent Redviolet");
	nameList.append ("Peru ");
	nameList.append ("Picasso Blue");
	nameList.append ("Pickle");
	nameList.append ("Piglet Snout");
	nameList.append ("Pineapple");
	nameList.append ("Pinegreen");
	nameList.append ("Pink ");
	nameList.append ("Pink Candy");
	nameList.append ("Pink Cloud");
	nameList.append ("Pink Glass");
	nameList.append ("Pink Jeep");
	nameList.append ("Pink Shell");
	nameList.append ("Pink1");
	nameList.append ("Pink2");
	nameList.append ("Pink3");
	nameList.append ("Pink4");
	nameList.append ("Pistachio Shell");
	nameList.append ("Plum ");
	nameList.append ("Plum Pudding");
	nameList.append ("Plum1");
	nameList.append ("Plum2");
	nameList.append ("Plum2");
	nameList.append ("Plum3");
	nameList.append ("Plum4");
	nameList.append ("Police Strobe");
	nameList.append ("Pollock Blue");
	nameList.append ("Pomegranate");
	nameList.append ("Pond Scum");
	nameList.append ("Pool Table");
	nameList.append ("Popcorn Yellow");
	nameList.append ("Powderblue ");
	nameList.append ("Presidential Blue");
	nameList.append ("Pumice");
	nameList.append ("Pummelo Pulp");
	nameList.append ("Purple");
	nameList.append ("Purple ");
	nameList.append ("Purple Candy");
	nameList.append ("Purple Fish");
	nameList.append ("Purple Ink");
	nameList.append ("Purple Rain");
	nameList.append ("Purple Rose");
	nameList.append ("Purple1");
	nameList.append ("Purple2");
	nameList.append ("Purple3");
	nameList.append ("Purple4");
	nameList.append ("Purple6");
	nameList.append ("Putting");
	nameList.append ("Pyridium Orange");
	nameList.append ("Quartz");
	nameList.append ("Ralph Yellow");
	nameList.append ("Raspberry");
	nameList.append ("Raspberry Red");
	nameList.append ("Raw Sienna");
	nameList.append ("Raw Umber");
	nameList.append ("Red ");
	nameList.append ("Red Coat");
	nameList.append ("Red Delicious Apple");
	nameList.append ("Red Roof");
	nameList.append ("Red2");
	nameList.append ("Red3");
	nameList.append ("Robin's Egg");
	nameList.append ("Romaine Lettuce");
	nameList.append ("Rose");
	nameList.append ("Rose Madder");
	nameList.append ("Rosybrown ");
	nameList.append ("Rosybrown1");
	nameList.append ("Rosybrown2");
	nameList.append ("Rosybrown3");
	nameList.append ("Rosybrown4");
	nameList.append ("Royal Palm");
	nameList.append ("Royalblue");
	nameList.append ("Royalblue ");
	nameList.append ("Royalblue1");
	nameList.append ("Royalblue2");
	nameList.append ("Royalblue3");
	nameList.append ("Royalblue4");
	nameList.append ("Ruby Red");
	nameList.append ("Saddlebrown ");
	nameList.append ("Safety Cone");
	nameList.append ("Safety Vest");
	nameList.append ("Salmon ");
	nameList.append ("Salmon1");
	nameList.append ("Salmon2");
	nameList.append ("Salmon3");
	nameList.append ("Salmon4");
	nameList.append ("Salmon5");
	nameList.append ("Sand");
	nameList.append ("Sandstone");
	nameList.append ("Sandybrown ");
	nameList.append ("Sapgreen");
	nameList.append ("Scarlet");
	nameList.append ("Scotland Pound");
	nameList.append ("Sea Green");
	nameList.append ("Sea Urchin");
	nameList.append ("Seagreen");
	nameList.append ("Seagreen1");
	nameList.append ("Seagreen2");
	nameList.append ("Seagreen3");
	nameList.append ("Seashell ");
	nameList.append ("Seashell2");
	nameList.append ("Seashell3");
	nameList.append ("Seashell4");
	nameList.append ("Seattle Salmon");
	nameList.append ("Seaweed");
	nameList.append ("Seaweed Roll");
	nameList.append ("Semisweet Chocolate1");
	nameList.append ("Semisweet Chocolate2");
	nameList.append ("Sepia");
	nameList.append ("Seurat Blue");
	nameList.append ("Sgi Beet");
	nameList.append ("Sgi Brightgray");
	nameList.append ("Sgi Chartreuse");
	nameList.append ("Sgi Light Blue");
	nameList.append ("Sgi Light Gray");
	nameList.append ("Sgi Olivedrab");
	nameList.append ("Sgi Salmon");
	nameList.append ("Sgi Slate Blue");
	nameList.append ("Sgi Teal");
	nameList.append ("Shamrock");
	nameList.append ("Shamrock Shake");
	nameList.append ("Sienna");
	nameList.append ("Sienna ");
	nameList.append ("Sienna1");
	nameList.append ("Sienna2");
	nameList.append ("Sienna3");
	nameList.append ("Sienna4");
	nameList.append ("Sign Blue");
	nameList.append ("Sign Brown");
	nameList.append ("Sign Green");
	nameList.append ("Sign Orange");
	nameList.append ("Sign Red");
	nameList.append ("Sign Yellow");
	nameList.append ("Silver");
	nameList.append ("Silver ");
	nameList.append ("Skyblue ");
	nameList.append ("Skyblue1");
	nameList.append ("Skyblue2");
	nameList.append ("Skyblue3");
	nameList.append ("Skyblue4");
	nameList.append ("Skyblue5");
	nameList.append ("Skyblue6");
	nameList.append ("Slateblue");
	nameList.append ("Slateblue ");
	nameList.append ("Slateblue1");
	nameList.append ("Slateblue2");
	nameList.append ("Slateblue3");
	nameList.append ("Slateblue4");
	nameList.append ("Slategray ");
	nameList.append ("Slategray1");
	nameList.append ("Slategray2");
	nameList.append ("Slategray3");
	nameList.append ("Slategray4");
	nameList.append ("Slategrey ");
	nameList.append ("Smyrna Purple");
	nameList.append ("Snake");
	nameList.append ("Snow ");
	nameList.append ("Snow2");
	nameList.append ("Snow3");
	nameList.append ("Snow4");
	nameList.append ("Soylent Green");
	nameList.append ("Soylent Red");
	nameList.append ("Soylent Yellow");
	nameList.append ("Spicy Pink");
	nameList.append ("Spinach");
	nameList.append ("Springgreen");
	nameList.append ("Springgreen ");
	nameList.append ("Springgreen2");
	nameList.append ("Springgreen3");
	nameList.append ("Springgreen4");
	nameList.append ("St Louis Blues");
	nameList.append ("Stained Glass");
	nameList.append ("Stainless Steel");
	nameList.append ("Starbucks");
	nameList.append ("Steelblue");
	nameList.append ("Steelblue ");
	nameList.append ("Steelblue1");
	nameList.append ("Steelblue2");
	nameList.append ("Steelblue3");
	nameList.append ("Steelblue4");
	nameList.append ("Strawberry");
	nameList.append ("Strawberry Smoothie");
	nameList.append ("Summer Sky");
	nameList.append ("Surf");
	nameList.append ("Sweet Potato Vine");
	nameList.append ("Swimming Pool");
	nameList.append ("Tan");
	nameList.append ("Tan");
	nameList.append ("Tan ");
	nameList.append ("Tan1");
	nameList.append ("Tan2");
	nameList.append ("Tan4");
	nameList.append ("Tangerine");
	nameList.append ("Tank");
	nameList.append ("Tea Leaves");
	nameList.append ("Teal ");
	nameList.append ("Teal LED");
	nameList.append ("Terreverte");
	nameList.append ("Thistle");
	nameList.append ("Thistle ");
	nameList.append ("Thistle1");
	nameList.append ("Thistle2");
	nameList.append ("Thistle3");
	nameList.append ("Thistle4");
	nameList.append ("Titanium");
	nameList.append ("Titanium White");
	nameList.append ("Tomato ");
	nameList.append ("Tomato2");
	nameList.append ("Tomato3");
	nameList.append ("Tomato4");
	nameList.append ("Tongue");
	nameList.append ("Topaz");
	nameList.append ("Tree Moss");
	nameList.append ("Tropical Blue");
	nameList.append ("Truegreen");
	nameList.append ("Truepurple");
	nameList.append ("Turnip");
	nameList.append ("Turquoise");
	nameList.append ("Turquoise");
	nameList.append ("Turquoise ");
	nameList.append ("Turquoise1");
	nameList.append ("Turquoise2");
	nameList.append ("Turquoise3");
	nameList.append ("Turquoise4");
	nameList.append ("Turquoiseblue");
	nameList.append ("Ty Nant");
	nameList.append ("Ultramarine");
	nameList.append ("Ultramarine Violet");
	nameList.append ("Ulysses Butterfly");
	nameList.append ("Vandyke Brown");
	nameList.append ("Vanilla Mint");
	nameList.append ("Venetian Red");
	nameList.append ("Very Dark Brown");
	nameList.append ("Very Light Grey");
	nameList.append ("Violet");
	nameList.append ("Violet");
	nameList.append ("Violet ");
	nameList.append ("Violet Flower");
	nameList.append ("Violetred");
	nameList.append ("Violetred");
	nameList.append ("Violetred1");
	nameList.append ("Violetred2");
	nameList.append ("Violetred3");
	nameList.append ("Violetred4");
	nameList.append ("Viridian Light");
	nameList.append ("Wales");
	nameList.append ("Warmgrey");
	nameList.append ("Wasabi");
	nameList.append ("Wasabi Sauce");
	nameList.append ("Watermelon Pulp");
	nameList.append ("Watermelon Rind");
	nameList.append ("Wavecrest");
	nameList.append ("Wet Moss");
	nameList.append ("Wheat");
	nameList.append ("Wheat ");
	nameList.append ("Wheat1");
	nameList.append ("Wheat2");
	nameList.append ("Wheat3");
	nameList.append ("Wheat4");
	nameList.append ("White ");
	nameList.append ("Whitesmoke ");
	nameList.append ("Wild Violet");
	nameList.append ("Yellow Candy");
	nameList.append ("Yellow Perch");
	nameList.append ("Yellow");
	nameList.append ("Yellow2");
	nameList.append ("Yellow3");
	nameList.append ("Yellow4");
	nameList.append ("Yellowgreen ");
	nameList.append ("Yellowgreen2");
	nameList.append ("Yellowochre");
	nameList.append ("Yinmn Blue");
	nameList.append ("Yolk");
	nameList.append ("Zincwhite");
	nameList.append ("100 Euro");
	nameList.append ("20 Pound");
	nameList.append ("6 Ball");
	nameList.append ("UNKNOWN");
}

/**
 * Loads the combobox with the name list.
 */
void QtColorTable::loadComboBox () {
	ui.colorNameCB->addItems (nameList);
}

/**
 * Convenience method.
 * Connects/Disconnects the sliders and the combobox.
 * \param tf : if true, signals are connected; if false, signals are disconnected.
 */
void QtColorTable::setSignals (bool tf) {
	if (tf) {
		connect (ui.colorNameCB, &QComboBox::currentTextChanged, this, &QtColorTable::processNamedColor);
		connect (ui.redSlider, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
		connect (ui.greenSlider_2, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
		connect (ui.blueSlider_3, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
	} else {
		disconnect (ui.colorNameCB, &QComboBox::currentTextChanged, this, &QtColorTable::processNamedColor);
		disconnect (ui.redSlider, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
		disconnect (ui.greenSlider_2, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
		disconnect (ui.blueSlider_3, &QSlider::sliderReleased, this, &QtColorTable::processSliders);
	}
}

/**
 * Finds the closest named color to the current slider positions.
 * Expensive. Computes the sum of squared differences between the current positions and
 * every color. Saves the one with the smallest squared difference and sets the NameComboBox.
 */
void QtColorTable::findClosestNamedColor () {
	ColorTable* ct = new ColorTable ();
	map<string, string> localMap = ct->getNameMap ();
	int rval = ui.redSlider->value ();
	int gval = ui.greenSlider_2->value ();
	int bval = ui.blueSlider_3->value ();
	int colorValue = 256 * (256 * rval + gval) + bval;
	string hexval = Color::int2hex (colorValue);
	string closestName = "";
	int deltamin = INT_MAX;
	for (auto& it : localMap) {
		string namedHexval = it.first;
		int rnam = Color::getRedInt (namedHexval);
		int gnam = Color::getGreenInt (namedHexval);
		int bnam = Color::getBlueInt (namedHexval);
		int delta = pow (rnam - rval, 2) + pow (gnam - gval, 2) + pow (bnam - bval, 2);
		if (delta < deltamin) {
			deltamin = delta;
			closestName = it.second;
		}
	}
	ui.colorNameCB->setCurrentText (QString::fromStdString (closestName));
}

/**
 * Method that is connected to the Color Name combobox.
 * It extracts the 6-char HEX color value corresponding to the name
 * and sets the text below the color swatch as well as putting the
 * color as background to the swatch. Also sets the slider positions to
 * correspond to the color value.
 */
void QtColorTable::processNamedColor () {
	string name = ui.colorNameCB->currentText ().toStdString ();
	ColorTable* ct = new ColorTable ();
	string hexvalue;
	for (const auto& [key, value] : ct->getNameMap ())
		if (value == name)
			hexvalue = key;
	ui.hexValue->setText (QString::fromStdString (hexvalue));
	setAreaColor (hexvalue);

	// Sliders range from 0 to 255, so we need the int value of the appropriate hex
	ui.redSlider->setValue (Color::getRedInt (hexvalue));
	ui.greenSlider_2->setValue (Color::getGreenInt (hexvalue));
	ui.blueSlider_3->setValue (Color::getBlueInt (hexvalue));
}

/**
 * Method connected to the Red/Green/Blue sliders.
 * Uses the slider positions to compute the 6-char HEX color value and
 * sets the text below the color swatch as well as putting the
 * color as background to the swatch. Also sets the slider positions to
 * correspond to the color value.  It then disconnects the signals so that
 * when it sets the combobox the corresponding method is not called. Then resets
 * the signals.
 */
void QtColorTable::processSliders () {
	int rval = ui.redSlider->value ();
	int gval = ui.greenSlider_2->value ();
	int bval = ui.blueSlider_3->value ();
	int colorValue = 256 * (256 * rval + gval) + bval;
	string hexval = Color::int2hex (colorValue);
	ui.hexValue->setText (QString::fromStdString (hexval));
	setAreaColor (hexval);

	setSignals (false);
	string name = lookupName (hexval);
	ui.colorNameCB->setCurrentText (QString::fromStdString (name));
	setSignals (true);
}

/**
 * Looks up the name corresponding to the input value.
 *
 * \param hexval :  6 character HEX color value.
 * \return Name of corresponding color or, if the slider positions do not correspond
 * to a named value, returns "UNKNOWN".
 */
string QtColorTable::lookupName (string hexval) {
	ColorTable* ct = new ColorTable ();
	map<string, string> localMap = ct->getNameMap ();
	// Traverse the map
	for (auto& it : localMap) {
		string foist = it.first;
		if (0 == foist.compare (hexval)) {
			return(it.second);
		}
	}
	// If there is not key mapped with hexval,
	// then return unknown
	return "UNKNOWN";
}

/**
 * Sets the color swatch background color corresponding to the input value.
 * \param rrggbb : 6 character HEX color value.
 */
void QtColorTable::setAreaColor (string rrggbb) {
	QString str = QString::fromStdString ("background-color: #" + rrggbb + ";");
	ui.colorArea->setStyleSheet (str);
}
