/****************************************************************************/
/* BEGIN FILE ColorTable.cpp                                                */
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
/*      @author    jsowers           24MAY24                                */
/*                                                                          */
/*   Modifications:                                                         */
/*                                                                          */
/****************************************************************************/
/* INCLUDE FILES                                                            */
/*                                                                          */
#include <cmath>
#include <iostream>
#include <fstream>
#include "ColorTable.h"

/*                                                                          */
/****************************************************************************/
/* DEFINES                                                                  */
/*                                                                          */

/****************************************************************************/
/*	 Begin Code                                                             */

/**
 * Default Constructor.
 */
ColorTable::ColorTable () {
    loadColorMap ();
    loadNameMap ();
}

/**
 * Default Destructor.
 */
ColorTable::~ColorTable () {}

/**
 * Creates and loads the Color Map.
 */
void ColorTable::loadColorMap () {
    colorMap.insert ({ "UNKNOWN", new Color () });
    colorMap.insert ({ "Alaska Sky", new Color (27, 63, 139) });      // 0x1B3F8B
    colorMap.insert ({ "Alice Blue", new Color (240, 248, 255) });      // 0xF0F8FF
    colorMap.insert ({ "Alizarin Crimson", new Color (227, 38, 54) });      // 0xE32636
    colorMap.insert ({ "Almond", new Color (196, 142, 72) });      // 0xC48E48
    colorMap.insert ({ "Aluminum", new Color (169, 172, 182) });      // 0xA9ACB6
    colorMap.insert ({ "Amethyst", new Color (157, 107, 132) });      // 0x9D6B84
    colorMap.insert ({ "Anjou Pear", new Color (186, 175, 7) });      // 0xBAAF07
    colorMap.insert ({ "Antiquewhite ", new Color (250, 235, 215) });      // 0xFAEBD7
    colorMap.insert ({ "Antiquewhite1", new Color (255, 239, 219) });      // 0xFFEFDB
    colorMap.insert ({ "Antiquewhite2", new Color (238, 223, 204) });      // 0xEEDFCC
    colorMap.insert ({ "Antiquewhite3", new Color (205, 192, 176) });      // 0xCDC0B0
    colorMap.insert ({ "Antiquewhite4", new Color (139, 131, 120) });      // 0x8B8378
    colorMap.insert ({ "Apple", new Color (204, 78, 92) });      // 0xCC4E5C
    colorMap.insert ({ "Apricot", new Color (251, 161, 108) });      // 0xFBA16C
    colorMap.insert ({ "Aqua", new Color (102, 204, 204) });      // 0x66CCCC
    colorMap.insert ({ "Aquaman", new Color (55, 188, 97) });      // 0x37BC61
    colorMap.insert ({ "Aquamarine", new Color (112, 219, 147) });      // 0x70DB93
    colorMap.insert ({ "Aquamarine", new Color (78, 120, 160) });      // 0x4E78A0
    colorMap.insert ({ "Aquamarine ", new Color (127, 255, 212) });      // 0x7FFFD4
    colorMap.insert ({ "Aquamarine2", new Color (118, 238, 198) });      // 0x76EEC6
    colorMap.insert ({ "Aquamarine4", new Color (69, 139, 116) });      // 0x458B74
    colorMap.insert ({ "Aquarium", new Color (47, 170, 150) });      // 0x2FAA96
    colorMap.insert ({ "Army Men", new Color (50, 117, 86) });      // 0x327556
    colorMap.insert ({ "Army Uniform", new Color (53, 63, 62) });      // 0x353F3E
    colorMap.insert ({ "Ash", new Color (198, 195, 181) });      // 0xC6C3B5
    colorMap.insert ({ "Atlantic Green", new Color (42, 142, 130) });      // 0x2A8E82
    colorMap.insert ({ "Aureoline Yellow", new Color (255, 168, 36) });      // 0xFFA824
    colorMap.insert ({ "Avacado", new Color (162, 194, 87) });      // 0xA2C257
    colorMap.insert ({ "Avocado", new Color (152, 161, 72) });      // 0x98A148
    colorMap.insert ({ "Azure ", new Color (240, 255, 255) });      // 0xF0FFFF
    colorMap.insert ({ "Azure2", new Color (224, 238, 238) });      // 0xE0EEEE
    colorMap.insert ({ "Azure3", new Color (193, 205, 205) });      // 0xC1CDCD
    colorMap.insert ({ "Azure4", new Color (131, 139, 139) });      // 0x838B8B
    colorMap.insert ({ "Bacon", new Color (198, 93, 87) });      // 0xC65D57
    colorMap.insert ({ "Bakers Chocolate", new Color (92, 51, 23) });      // 0x5C3317
    colorMap.insert ({ "Banana", new Color (227, 207, 87) });      // 0xE3CF57
    colorMap.insert ({ "Banker's Lamp", new Color (14, 140, 58) });      // 0x0E8C3A
    colorMap.insert ({ "Barney", new Color (212, 49, 140) });      // 0xD4318C
    colorMap.insert ({ "Bartlett Pear", new Color (205, 171, 45) });      // 0xCDAB2D
    colorMap.insert ({ "Battleship", new Color (208, 210, 196) });      // 0xD0D2C4
    colorMap.insert ({ "Beach Sand", new Color (238, 214, 175) });      // 0xEED6AF
    colorMap.insert ({ "Beer", new Color (229, 188, 59) });      // 0xE5BC3B
    colorMap.insert ({ "Beige ", new Color (245, 245, 220) });      // 0xF5F5DC
    colorMap.insert ({ "Beige Dark ", new Color (163, 148, 128) });      // 0xA39480
    colorMap.insert ({ "Bermuda Sand", new Color (246, 201, 204) });      // 0xF6C9CC
    colorMap.insert ({ "Big Blue Bus", new Color (58, 102, 167) });      // 0x3A66A7
    colorMap.insert ({ "Bing Cherry", new Color (160, 36, 34) });      // 0xA02422
    colorMap.insert ({ "Bisque ", new Color (255, 228, 196) });      // 0xFFE4C4
    colorMap.insert ({ "Bisque2", new Color (238, 213, 183) });      // 0xEED5B7
    colorMap.insert ({ "Bisque3", new Color (205, 183, 158) });      // 0xCDB79E
    colorMap.insert ({ "Bisque4", new Color (139, 125, 107) });      // 0x8B7D6B
    colorMap.insert ({ "Black", new Color (0, 0, 0) });      // 0x000000
    colorMap.insert ({ "Black Beauty Plum", new Color (66, 44, 47) });      // 0x422C2F
    colorMap.insert ({ "Blackberry", new Color (58, 58, 56) });      // 0x3A3A38
    colorMap.insert ({ "Blanched Almond ", new Color (255, 235, 205) });      // 0xFFEBCD
    colorMap.insert ({ "Blood Orange", new Color (204, 17, 0) });      // 0xCC1100
    colorMap.insert ({ "Bloodred", new Color (102, 0, 0) });      // 0x660000
    colorMap.insert ({ "Blue ", new Color (0, 0, 255) });      // 0x0000FF
    colorMap.insert ({ "Blue Angels", new Color (43, 79, 129) });      // 0x2B4F81
    colorMap.insert ({ "Blue Bird", new Color (73, 115, 171) });      // 0x4973AB
    colorMap.insert ({ "Blue Bucket", new Color (73, 157, 245) });      // 0x499DF5
    colorMap.insert ({ "Blue Corn", new Color (52, 65, 82) });      // 0x344152
    colorMap.insert ({ "Blue Corn Chips", new Color (88, 78, 86) });      // 0x584000
    colorMap.insert ({ "Blue Cow", new Color (136, 172, 224) });      // 0x88ACE0
    colorMap.insert ({ "Blue Deep", new Color (56, 4, 116) });      // 0x380474
    colorMap.insert ({ "Blue Dog", new Color (82, 92, 101) });      // 0x525C65
    colorMap.insert ({ "Blue Fern", new Color (117, 155, 132) });      // 0x759B84
    colorMap.insert ({ "Blue Grapes", new Color (59, 73, 144) });      // 0x3B4990
    colorMap.insert ({ "Blue Green Algae", new Color (59, 132, 113) });      // 0x3B8471
    colorMap.insert ({ "Blue Ice", new Color (218, 244, 240) });      // 0xDAF4F0
    colorMap.insert ({ "Blue Ice", new Color (116, 187, 251) });      // 0x74BBFB
    colorMap.insert ({ "Blue Jeans", new Color (66, 82, 108) });      // 0x42526C
    colorMap.insert ({ "Blue Lagoon", new Color (76, 183, 165) });      // 0x4CB7A5
    colorMap.insert ({ "Blue Line", new Color (51, 161, 222) });      // 0x33A1DE
    colorMap.insert ({ "Blue Mist", new Color (130, 207, 253) });      // 0x82CFFD
    colorMap.insert ({ "Blue Nile", new Color (125, 127, 148) });      // 0x7D7F94
    colorMap.insert ({ "Blue Pill", new Color (81, 144, 237) });      // 0x5190ED
    colorMap.insert ({ "Blue Ridge Mtns", new Color (73, 129, 206) });      // 0x4981CE
    colorMap.insert ({ "Blue Safe", new Color (102, 0, 255) });      // 0x6600FF
    colorMap.insert ({ "Blue Shark", new Color (105, 150, 173) });      // 0x6996AD
    colorMap.insert ({ "Blue Spider", new Color (38, 70, 109) });      // 0x26466D
    colorMap.insert ({ "Blue Sponge", new Color (93, 146, 177) });      // 0x5D92B1
    colorMap.insert ({ "Blue Stone", new Color (80, 114, 159) });      // 0x50729F
    colorMap.insert ({ "Blue Train", new Color (58, 88, 148) });      // 0x3A5894
    colorMap.insert ({ "Blue Tuna", new Color (104, 124, 151) });      // 0x687C97
    colorMap.insert ({ "Blue Velvet", new Color (22, 34, 82) });      // 0x162252
    colorMap.insert ({ "Blue Whale", new Color (66, 100, 127) });      // 0x42647F
    colorMap.insert ({ "Blue2", new Color (0, 0, 238) });      // 0x0000EE
    colorMap.insert ({ "Blueberry Fresh", new Color (89, 113, 173) });      // 0x5971AD
    colorMap.insert ({ "Bluegrass", new Color (76, 112, 100) });      // 0x4C7064
    colorMap.insert ({ "Blueviolet", new Color (159, 95, 159) });      // 0x9F5F9F
    colorMap.insert ({ "Blueviolet ", new Color (138, 43, 226) });      // 0x8A2BE2
    colorMap.insert ({ "Bone", new Color (255, 255, 204) });      // 0xFFFFCC
    colorMap.insert ({ "Bordeaux", new Color (153, 24, 44) });      // 0x99182C
    colorMap.insert ({ "Bottle Green", new Color (29, 162, 55) });      // 0x1DA237
    colorMap.insert ({ "Braeburn Apple", new Color (187, 42, 60) });      // 0xBB2A3C
    colorMap.insert ({ "Brass", new Color (181, 166, 66) });      // 0xB5A642
    colorMap.insert ({ "Bread", new Color (252, 213, 156) });      // 0xFCD59C
    colorMap.insert ({ "Breadfruit", new Color (133, 156, 39) });      // 0x859C27
    colorMap.insert ({ "Brick", new Color (156, 102, 31) });      // 0x9C661F
    colorMap.insert ({ "Bright Gold", new Color (217, 217, 25) });      // 0xD9D919
    colorMap.insert ({ "Bright Red", new Color (255, 0, 51) });      // 0xFF0033
    colorMap.insert ({ "Broadway Pink", new Color (255, 0, 102) });      // 0xFF0066
    colorMap.insert ({ "Broccoli", new Color (88, 105, 73) });      // 0x586949
    colorMap.insert ({ "Bronze", new Color (140, 120, 83) });      // 0x8C7853
    colorMap.insert ({ "Bronzeii", new Color (166, 125, 61) });      // 0xA67D3D
    colorMap.insert ({ "Brown", new Color (128, 42, 42) });      // 0x802A2A
    colorMap.insert ({ "Brown Madder", new Color (219, 41, 41) });      // 0xDB2929
    colorMap.insert ({ "Brown Ochre", new Color (135, 66, 31) });      // 0x87421F
    colorMap.insert ({ "Brown1", new Color (139, 37, 0) });      // 0x8B2500
    colorMap.insert ({ "Brown2", new Color (238, 59, 59) });      // 0xEE3B3B
    colorMap.insert ({ "Brown3", new Color (205, 51, 51) });      // 0xCD3333
    colorMap.insert ({ "Brushed Aluminum", new Color (182, 197, 190) });      // 0xB6C5BE
    colorMap.insert ({ "Bubble Gum", new Color (255, 146, 187) });      // 0xFF92BB
    colorMap.insert ({ "Bunny Eye", new Color (165, 67, 92) });      // 0xA5435C
    colorMap.insert ({ "Burgundy", new Color (158, 5, 8) });      // 0x9E0508
    colorMap.insert ({ "Burlywood ", new Color (222, 184, 135) });      // 0xDEB887
    colorMap.insert ({ "Burlywood2", new Color (238, 197, 145) });      // 0xEEC591
    colorMap.insert ({ "Burlywood3", new Color (205, 170, 125) });      // 0xCDAA7D
    colorMap.insert ({ "Burlywood4", new Color (139, 115, 85) });      // 0x8B7355
    colorMap.insert ({ "Burnt Sienna", new Color (138, 54, 15) });      // 0x8A360F
    colorMap.insert ({ "Burnt Umber", new Color (138, 51, 36) });      // 0x8A3324
    colorMap.insert ({ "Cactus", new Color (99, 111, 87) });      // 0x636F57
    colorMap.insert ({ "Cadetblue", new Color (95, 159, 159) });      // 0x5F9F9F
    colorMap.insert ({ "Cadetblue1", new Color (152, 245, 255) });      // 0x98F5FF
    colorMap.insert ({ "Cadetblue2", new Color (142, 229, 238) });      // 0x8EE5EE
    colorMap.insert ({ "Cadetblue3", new Color (122, 197, 205) });      // 0x7AC5CD
    colorMap.insert ({ "Cadetblue4", new Color (83, 134, 139) });      // 0x53868B
    colorMap.insert ({ "Cadmium Lemon", new Color (255, 227, 3) });      // 0xFFE303
    colorMap.insert ({ "Cadmium Orange", new Color (255, 97, 3) });      // 0xFF6103
    colorMap.insert ({ "Cadmium Red Deep", new Color (227, 23, 13) });      // 0xE3170D
    colorMap.insert ({ "Cadmium Red Light", new Color (255, 3, 13) });      // 0xFF030D
    colorMap.insert ({ "Cadmium Yellow", new Color (255, 153, 18) });      // 0xFF9912
    colorMap.insert ({ "Cadmium Yellowlight", new Color (255, 176, 15) });      // 0xFFB00F
    colorMap.insert ({ "Cafe Americano", new Color (54, 40, 25) });      // 0x362819
    colorMap.insert ({ "Cafe Au Lait", new Color (182, 124, 61) });      // 0xB67C3D
    colorMap.insert ({ "Camo1", new Color (207, 219, 197) });      // 0xCFDBC5
    colorMap.insert ({ "Camo2", new Color (169, 201, 164) });      // 0xA9C9A4
    colorMap.insert ({ "Camo3", new Color (157, 182, 140) });      // 0x9DB68C
    colorMap.insert ({ "Cantaloupe", new Color (156, 169, 152) });      // 0x9CA998
    colorMap.insert ({ "Canvas", new Color (157, 136, 81) });      // 0x9D8851
    colorMap.insert ({ "Cappuccino", new Color (178, 134, 71) });      // 0xB28647
    colorMap.insert ({ "Caribbean", new Color (66, 192, 251) });      // 0x42C0FB
    colorMap.insert ({ "Carnation", new Color (222, 133, 177) });      // 0xDE85B1
    colorMap.insert ({ "Carolina Blue", new Color (83, 157, 194) });      // 0x539DC2
    colorMap.insert ({ "Carrot", new Color (237, 145, 33) });      // 0xED9121
    colorMap.insert ({ "Cashew", new Color (223, 174, 116) });      // 0xDFAE74
    colorMap.insert ({ "Cat Eye", new Color (190, 229, 84) });      // 0xBEE554
    colorMap.insert ({ "Cat Eye2", new Color (122, 169, 221) });      // 0x7AA9DD
    colorMap.insert ({ "Celery", new Color (207, 215, 132) });      // 0xCFD784
    colorMap.insert ({ "Celtics", new Color (0, 97, 28) });      // 0x00611C
    colorMap.insert ({ "Cerulean", new Color (5, 184, 204) });      // 0x05B8CC
    colorMap.insert ({ "Chartreuse ", new Color (127, 255, 0) });      // 0x7FFF00
    colorMap.insert ({ "Chartreuse Verte", new Color (188, 233, 55) });      // 0xBCE937
    colorMap.insert ({ "Chartreuse2", new Color (118, 238, 0) });      // 0x76EE00
    colorMap.insert ({ "Chartreuse3", new Color (102, 205, 0) });      // 0x66CD00
    colorMap.insert ({ "Chartreuse4", new Color (69, 139, 0) });      // 0x458B00
    colorMap.insert ({ "Cheddar", new Color (255, 196, 105) });      // 0xFFC469
    colorMap.insert ({ "Chemical Suit", new Color (89, 147, 229) });      // 0x599300
    colorMap.insert ({ "Cherry", new Color (235, 94, 102) });      // 0xEB5E66
    colorMap.insert ({ "Chili", new Color (212, 73, 66) });      // 0xD44942
    colorMap.insert ({ "Chili Powder", new Color (199, 63, 23) });      // 0xC73F17
    colorMap.insert ({ "Chocolate", new Color (153, 51, 0) });      // 0x993300
    colorMap.insert ({ "Chocolate ", new Color (210, 105, 30) });      // 0xD2691E
    colorMap.insert ({ "Chocolate1", new Color (255, 127, 36) });      // 0xFF7F24
    colorMap.insert ({ "Chocolate2", new Color (238, 118, 33) });      // 0xEE7621
    colorMap.insert ({ "Chocolate3", new Color (205, 102, 29) });      // 0xCD661D
    colorMap.insert ({ "Chrome", new Color (232, 241, 212) });      // 0xE8F1D4
    colorMap.insert ({ "Chrome Oxide Green", new Color (102, 128, 20) });      // 0x668014
    colorMap.insert ({ "Cichlid", new Color (0, 62, 255) });      // 0x003EFF
    colorMap.insert ({ "Cinnabar Green", new Color (97, 179, 41) });      // 0x61B329
    colorMap.insert ({ "Cinnamon", new Color (170, 102, 0) });      // 0xAA6600
    colorMap.insert ({ "Cinnamon", new Color (123, 63, 0) });      // 0x7B3F00
    colorMap.insert ({ "Circuit Board", new Color (58, 102, 41) });      // 0x3A6629
    colorMap.insert ({ "Clover", new Color (62, 160, 85) });      // 0x3EA055
    colorMap.insert ({ "Cobalt", new Color (102, 102, 255) });      // 0x6666FF
    colorMap.insert ({ "Cobalt", new Color (61, 89, 171) });      // 0x3D59AB
    colorMap.insert ({ "Cobalt Green", new Color (61, 145, 64) });      // 0x3D9140
    colorMap.insert ({ "Cobalt Violet Deep", new Color (145, 33, 158) });      // 0x91219E
    colorMap.insert ({ "Coconut", new Color (255, 252, 207) });      // 0xFFFCCF
    colorMap.insert ({ "Coconut Shell", new Color (188, 118, 66) });      // 0xBC7642
    colorMap.insert ({ "Coffee", new Color (170, 83, 3) });      // 0xAA5303
    colorMap.insert ({ "Coke Bottle", new Color (121, 168, 136) });      // 0x79A888
    colorMap.insert ({ "Cola", new Color (175, 64, 53) });      // 0xAF4035
    colorMap.insert ({ "Cold Grey", new Color (128, 138, 135) });      // 0x808A87
    colorMap.insert ({ "Conch", new Color (208, 169, 170) });      // 0xD0A9AA
    colorMap.insert ({ "Concord Grape", new Color (102, 1, 152) });      // 0x660198
    colorMap.insert ({ "Cool Copper", new Color (217, 135, 25) });      // 0xD98719
    colorMap.insert ({ "Cool Mint", new Color (144, 254, 251) });      // 0x90FEFB
    colorMap.insert ({ "Cooler", new Color (40, 73, 66) });      // 0x284942
    colorMap.insert ({ "Copper", new Color (184, 115, 51) });      // 0xB87333
    colorMap.insert ({ "Coral ", new Color (255, 127, 80) });      // 0xFF7F50
    colorMap.insert ({ "Coral1", new Color (255, 114, 86) });      // 0xFF7256
    colorMap.insert ({ "Coral2", new Color (238, 106, 80) });      // 0xEE6A50
    colorMap.insert ({ "Coral3", new Color (205, 91, 69) });      // 0xCD5B45
    colorMap.insert ({ "Coral4", new Color (139, 62, 47) });      // 0x8B3E2F
    colorMap.insert ({ "Corfu Pink", new Color (236, 200, 236) });      // 0xECC8EC
    colorMap.insert ({ "Corn", new Color (251, 236, 93) });      // 0xFBEC5D
    colorMap.insert ({ "Cornflower", new Color (51, 0, 255) });      // 0x3300FF
    colorMap.insert ({ "Cornflower Blue", new Color (66, 66, 111) });      // 0x42426F
    colorMap.insert ({ "Cornflower Blue 2", new Color (100, 149, 237) });      // 0x6495ED
    colorMap.insert ({ "Cornsilk ", new Color (255, 248, 220) });      // 0xFFF8DC
    colorMap.insert ({ "Cornsilk2", new Color (238, 232, 205) });      // 0xEEE8CD
    colorMap.insert ({ "Cornsilk3", new Color (205, 200, 177) });      // 0xCDC8B1
    colorMap.insert ({ "Cornsilk4", new Color (139, 136, 120) });      // 0x8B8878
    colorMap.insert ({ "Cotton Candy", new Color (247, 179, 218) });      // 0xF7B3DA
    colorMap.insert ({ "Cranberry", new Color (182, 49, 108) });      // 0xB6316C
    colorMap.insert ({ "Cranberry Jello", new Color (245, 77, 112) });      // 0xF54D70
    colorMap.insert ({ "Crema", new Color (199, 110, 6) });      // 0xC76E06
    colorMap.insert ({ "Crimson ", new Color (220, 20, 60) });      // 0xDC143C
    colorMap.insert ({ "Cucumber", new Color (44, 93, 63) });      // 0x2C5D3F
    colorMap.insert ({ "Curacao", new Color (91, 89, 186) });      // 0x5B59BA
    colorMap.insert ({ "Cyan ", new Color (0, 255, 255) });      // 0x00FFFF
    colorMap.insert ({ "Cyan2", new Color (0, 238, 238) });      // 0x00EEEE
    colorMap.insert ({ "Cyan3", new Color (0, 205, 205) });      // 0x00CDCD
    colorMap.insert ({ "Dark   Goldenrod ", new Color (184, 134, 11) });      // 0xB8860B
    colorMap.insert ({ "Dark   Goldenrod1", new Color (255, 185, 15) });      // 0xFFB90F
    colorMap.insert ({ "Dark   Goldenrod2", new Color (238, 173, 14) });      // 0xEEAD0E
    colorMap.insert ({ "Dark   Goldenrod3", new Color (205, 149, 12) });      // 0xCD950C
    colorMap.insert ({ "Dark  Blue ", new Color (0, 0, 139) });      // 0x00008B
    colorMap.insert ({ "Dark  Cherry Red", new Color (51, 0, 0) });      // 0x330000
    colorMap.insert ({ "Dark  Cyan ", new Color (0, 139, 139) });      // 0x008B8B
    colorMap.insert ({ "Dark  Goldenrod4", new Color (139, 101, 8) });      // 0x8B6508
    colorMap.insert ({ "Dark  Gray ", new Color (169, 169, 169) });      // 0xA9A9A9
    colorMap.insert ({ "Dark  Green", new Color (47, 79, 47) });      // 0x2F4F2F
    colorMap.insert ({ "Dark  Green ", new Color (0, 100, 0) });      // 0x006400
    colorMap.insert ({ "Dark  Green Copper", new Color (74, 118, 110) });      // 0x4A766E
    colorMap.insert ({ "Dark  Grey ", new Color (169, 169, 169) });      // 0xA9A9A9
    colorMap.insert ({ "Dark  Khaki ", new Color (189, 183, 107) });      // 0xBDB76B
    colorMap.insert ({ "Dark  Wheat", new Color (232, 199, 130) });      // 0xE8C782
    colorMap.insert ({ "Dark Magenta ", new Color (139, 0, 139) });      // 0x8B008B
    colorMap.insert ({ "Dark Olivegreen", new Color (79, 79, 47) });      // 0x4F4F2F
    colorMap.insert ({ "Dark Olivegreen ", new Color (85, 107, 47) });      // 0x556B2F
    colorMap.insert ({ "Dark Olivegreen1", new Color (202, 255, 112) });      // 0xCAFF70
    colorMap.insert ({ "Dark Olivegreen2", new Color (188, 238, 104) });      // 0xBCEE68
    colorMap.insert ({ "Dark Olivegreen3", new Color (162, 205, 90) });      // 0xA2CD5A
    colorMap.insert ({ "Dark Olivegreen4", new Color (110, 139, 61) });      // 0x6E8B3D
    colorMap.insert ({ "Dark Orange ", new Color (255, 140, 0) });      // 0xFF8C00
    colorMap.insert ({ "Dark Orange1", new Color (255, 127, 0) });      // 0xFF7F00
    colorMap.insert ({ "Dark Orange2", new Color (238, 118, 0) });      // 0xEE7600
    colorMap.insert ({ "Dark Orange3", new Color (205, 102, 0) });      // 0xCD6600
    colorMap.insert ({ "Dark Orange4", new Color (139, 69, 0) });      // 0x8B4500
    colorMap.insert ({ "Dark Orange5", new Color (255, 134, 0) });      // 0xFF8600
    colorMap.insert ({ "Dark Orchid", new Color (153, 50, 205) });      // 0x9932CD
    colorMap.insert ({ "Dark Orchid ", new Color (153, 50, 204) });      // 0x9932CC
    colorMap.insert ({ "Dark Orchid2", new Color (178, 58, 238) });      // 0xB23AEE
    colorMap.insert ({ "Dark Orchid3", new Color (154, 50, 205) });      // 0x9A32CD
    colorMap.insert ({ "Dark Orchid4", new Color (104, 34, 139) });      // 0x68228B
    colorMap.insert ({ "Dark Purple", new Color (135, 31, 120) });      // 0x871F78
    colorMap.insert ({ "Dark Red ", new Color (139, 0, 0) });      // 0x8B0000
    colorMap.insert ({ "Dark Salmon ", new Color (233, 150, 122) });      // 0xE9967A
    colorMap.insert ({ "Dark Seagreen ", new Color (143, 188, 143) });      // 0x8FBC8F
    colorMap.insert ({ "Dark Seagreen1", new Color (193, 255, 193) });      // 0xC1FFC1
    colorMap.insert ({ "Dark Seagreen2", new Color (180, 238, 180) });      // 0xB4EEB4
    colorMap.insert ({ "Dark Seagreen3", new Color (155, 205, 155) });      // 0x9BCD9B
    colorMap.insert ({ "Dark Seagreen4", new Color (105, 139, 105) });      // 0x698B69
    colorMap.insert ({ "Dark Slateblue", new Color (107, 35, 142) });      // 0x6B238E
    colorMap.insert ({ "Dark Slateblue ", new Color (72, 61, 139) });      // 0x483D8B
    colorMap.insert ({ "Dark Slategray ", new Color (47, 79, 79) });      // 0x2F4F4F
    colorMap.insert ({ "Dark Slategray1", new Color (151, 255, 255) });      // 0x97FFFF
    colorMap.insert ({ "Dark Slategray2", new Color (141, 238, 238) });      // 0x8DEEEE
    colorMap.insert ({ "Dark Slategray3", new Color (121, 205, 205) });      // 0x79CDCD
    colorMap.insert ({ "Dark Slategray4", new Color (82, 139, 139) });      // 0x528B8B
    colorMap.insert ({ "Dark Slategrey ", new Color (47, 79, 79) });      // 0x2F4F4F
    colorMap.insert ({ "Dark Tan", new Color (151, 105, 79) });      // 0x97694F
    colorMap.insert ({ "Dark Turquoise", new Color (112, 147, 219) });      // 0x7093DB
    colorMap.insert ({ "Dark Turquoise ", new Color (0, 206, 209) });      // 0x00CED1
    colorMap.insert ({ "Dark Violet ", new Color (148, 0, 211) });      // 0x9400D3
    colorMap.insert ({ "Dark Wood", new Color (133, 94, 66) });      // 0x855000
    colorMap.insert ({ "Deep Ochre", new Color (115, 61, 26) });      // 0x733D1A
    colorMap.insert ({ "Deep Pink ", new Color (255, 20, 147) });      // 0xFF1493
    colorMap.insert ({ "Deep Pink2", new Color (238, 18, 137) });      // 0xEE1289
    colorMap.insert ({ "Deep Pink3", new Color (205, 16, 118) });      // 0xCD1076
    colorMap.insert ({ "Deep Pink4", new Color (139, 10, 80) });      // 0x8B0A50
    colorMap.insert ({ "Deep Purple", new Color (85, 16, 51) });      // 0x551033
    colorMap.insert ({ "Deep Skyblue ", new Color (0, 191, 255) });      // 0x00BFFF
    colorMap.insert ({ "Deep Skyblue2", new Color (0, 178, 238) });      // 0x00B2EE
    colorMap.insert ({ "Deep Skyblue3", new Color (0, 154, 205) });      // 0x009ACD
    colorMap.insert ({ "Deep Skyblue4", new Color (0, 104, 139) });      // 0x00688B
    colorMap.insert ({ "Delft", new Color (34, 49, 108) });      // 0x22316C
    colorMap.insert ({ "Denim", new Color (67, 114, 170) });      // 0x4372AA
    colorMap.insert ({ "Desert Sand", new Color (254, 232, 214) });      // 0xFEE8D6
    colorMap.insert ({ "Diamond Blue", new Color (14, 191, 233) });      // 0x0EBFE9
    colorMap.insert ({ "Dimgray ", new Color (105, 105, 105) });      // 0x696969
    colorMap.insert ({ "Dimgrey ", new Color (105, 105, 105) });      // 0x696969
    colorMap.insert ({ "Dodgerblue ", new Color (30, 144, 255) });      // 0x1E90FF
    colorMap.insert ({ "Dodgerblue2", new Color (28, 134, 238) });      // 0x1C86EE
    colorMap.insert ({ "Dodgerblue3", new Color (24, 116, 205) });      // 0x1874CD
    colorMap.insert ({ "Dodgerblue4", new Color (16, 78, 139) });      // 0x104E8B
    colorMap.insert ({ "Dog Tongue", new Color (246, 164, 213) });      // 0xF6A4D5
    colorMap.insert ({ "Dolphin", new Color (111, 114, 133) });      // 0x6F7285
    colorMap.insert ({ "Douglas Fir", new Color (63, 96, 43) });      // 0x3F602B
    colorMap.insert ({ "Dress Blue", new Color (59, 49, 120) });      // 0x3B3178
    colorMap.insert ({ "Dumpster", new Color (0, 79, 0) });      // 0x004F00
    colorMap.insert ({ "Dustyrose", new Color (133, 99, 99) });      // 0x856363
    colorMap.insert ({ "Eggplant", new Color (129, 102, 135) });      // 0x816687
    colorMap.insert ({ "Eggshell", new Color (252, 230, 201) });      // 0xFCE6C9
    colorMap.insert ({ "Electric Turquoise", new Color (73, 233, 189) });      // 0x49E9BD
    colorMap.insert ({ "Emerald", new Color (91, 156, 100) });      // 0x5B9C64
    colorMap.insert ({ "Emerald City", new Color (32, 191, 159) });      // 0x20BF9F
    colorMap.insert ({ "Emerald Green", new Color (0, 201, 87) });      // 0x00C957
    colorMap.insert ({ "Emerald Green2", new Color (40, 174, 123) });      // 0x28AE7B
    colorMap.insert ({ "England Pound", new Color (104, 133, 113) });      // 0x688571
    colorMap.insert ({ "Englishred", new Color (212, 61, 26) });      // 0xD43D1A
    colorMap.insert ({ "Espresso", new Color (231, 198, 165) });      // 0xE7C6A5
    colorMap.insert ({ "Feldspar", new Color (209, 146, 117) });      // 0xD19275
    colorMap.insert ({ "Fenway Grass", new Color (82, 111, 53) });      // 0x526F35
    colorMap.insert ({ "Fenway Monster", new Color (74, 119, 122) });      // 0x4A777A
    colorMap.insert ({ "Fire Truck Green", new Color (205, 215, 4) });      // 0xCDD704
    colorMap.insert ({ "Firebrick ", new Color (178, 34, 34) });      // 0xB22222
    colorMap.insert ({ "Firebrick1", new Color (255, 48, 48) });      // 0xFF3030
    colorMap.insert ({ "Firebrick2", new Color (238, 44, 44) });      // 0xEE2C2C
    colorMap.insert ({ "Firebrick3", new Color (205, 38, 38) });      // 0xCD2626
    colorMap.insert ({ "Firebrick4", new Color (139, 26, 26) });      // 0x8B1A1A
    colorMap.insert ({ "Firebrick5", new Color (142, 35, 35) });      // 0x8E2323
    colorMap.insert ({ "Fisherman's Float", new Color (96, 124, 110) });      // 0x607C6E
    colorMap.insert ({ "Flat Pink", new Color (255, 204, 204) });      // 0xFFCCCC
    colorMap.insert ({ "Flesh Ochre", new Color (255, 87, 33) });      // 0xFF5721
    colorMap.insert ({ "Floral White ", new Color (255, 250, 240) });      // 0xFFFAF0
    colorMap.insert ({ "Fog", new Color (203, 202, 182) });      // 0xCBCAB6
    colorMap.insert ({ "Forestgreen2", new Color (86, 126, 58) });      // 0x567E3A
    colorMap.insert ({ "Forget Me Nots", new Color (126, 182, 255) });      // 0x7EB6FF
    colorMap.insert ({ "Fraser Fir", new Color (77, 107, 80) });      // 0x4D6B50
    colorMap.insert ({ "Fresh Green", new Color (94, 218, 158) });      // 0x5EDA9E
    colorMap.insert ({ "Frog", new Color (132, 190, 106) });      // 0x84BE6A
    colorMap.insert ({ "Fuchsia ", new Color (255, 0, 255) });      // 0xFF00FF
    colorMap.insert ({ "Fuchsia2", new Color (255, 0, 170) });      // 0xFF00AA
    colorMap.insert ({ "Fuji Apple", new Color (214, 111, 98) });      // 0xD66F62
    colorMap.insert ({ "Gainsboro ", new Color (220, 220, 220) });      // 0xDCDCDC
    colorMap.insert ({ "Ganegreen", new Color (119, 119, 51) });      // 0x777733
    colorMap.insert ({ "Garden Hose", new Color (19, 143, 106) });      // 0x138F6A
    colorMap.insert ({ "Garden Plum", new Color (113, 99, 125) });      // 0x71637D
    colorMap.insert ({ "Geranium Lake", new Color (227, 18, 48) });      // 0xE31230
    colorMap.insert ({ "Ghostwhite ", new Color (248, 248, 255) });      // 0xF8F8FF
    colorMap.insert ({ "Go", new Color (67, 213, 140) });      // 0x43D58C
    colorMap.insert ({ "Gold ", new Color (255, 215, 0) });      // 0xFFD700
    colorMap.insert ({ "Gold Green", new Color (170, 221, 0) });      // 0xAADD00
    colorMap.insert ({ "Gold Ochre", new Color (199, 120, 38) });      // 0xC77826
    colorMap.insert ({ "Gold2", new Color (238, 201, 0) });      // 0xEEC900
    colorMap.insert ({ "Gold3", new Color (205, 173, 0) });      // 0xCDAD00
    colorMap.insert ({ "Gold4", new Color (139, 117, 0) });      // 0x8B7500
    colorMap.insert ({ "Gold5", new Color (204, 127, 50) });      // 0xCC7F32
    colorMap.insert ({ "Gold6", new Color (205, 127, 50) });      // 0xCD7F32
    colorMap.insert ({ "Gold7", new Color (255, 170, 0) });      // 0xFFAA00
    colorMap.insert ({ "Golden Delicious Apple", new Color (237, 203, 98) });      // 0xEDCB62
    colorMap.insert ({ "Goldenrod", new Color (219, 219, 112) });      // 0xDBDB70
    colorMap.insert ({ "Goldenrod ", new Color (218, 165, 32) });      // 0xDAA520
    colorMap.insert ({ "Goldenrod1", new Color (255, 193, 37) });      // 0xFFC125
    colorMap.insert ({ "Goldenrod2", new Color (238, 180, 34) });      // 0xEEB422
    colorMap.insert ({ "Goldenrod3", new Color (205, 155, 29) });      // 0xCD9B1D
    colorMap.insert ({ "Goldenrod4", new Color (139, 105, 20) });      // 0x8B6914
    colorMap.insert ({ "Grape", new Color (84, 57, 72) });      // 0x543948
    colorMap.insert ({ "Grape", new Color (204, 0, 255) });      // 0xCC00FF
    colorMap.insert ({ "Grapefruit", new Color (243, 232, 142) });      // 0xF3E88E
    colorMap.insert ({ "Grass", new Color (77, 189, 51) });      // 0x4DBD33
    colorMap.insert ({ "Gray", new Color (190, 190, 190) });      // 0xBEBEBE
    colorMap.insert ({ "Gray ", new Color (128, 128, 128) });      // 0x808080
    colorMap.insert ({ "Gray1", new Color (3, 3, 3) });      // 0x030303
    colorMap.insert ({ "Gray10", new Color (26, 26, 26) });      // 0x1A1A1A
    colorMap.insert ({ "Gray11", new Color (28, 28, 28) });      // 0x1C1C1C
    colorMap.insert ({ "Gray12", new Color (31, 31, 31) });      // 0x1F1F1F
    colorMap.insert ({ "Gray13", new Color (33, 33, 33) });      // 0x212121
    colorMap.insert ({ "Gray14", new Color (36, 36, 36) });      // 0x242424
    colorMap.insert ({ "Gray15", new Color (38, 38, 38) });      // 0x262626
    colorMap.insert ({ "Gray16", new Color (41, 41, 41) });      // 0x292929
    colorMap.insert ({ "Gray17", new Color (43, 43, 43) });      // 0x2B2B2B
    colorMap.insert ({ "Gray18", new Color (46, 46, 46) });      // 0x2E2E2E
    colorMap.insert ({ "Gray19", new Color (48, 48, 48) });      // 0x303030
    colorMap.insert ({ "Gray2", new Color (5, 5, 5) });      // 0x050505
    colorMap.insert ({ "Gray20", new Color (51, 51, 51) });      // 0x333333
    colorMap.insert ({ "Gray21", new Color (54, 54, 54) });      // 0x363636
    colorMap.insert ({ "Gray22", new Color (56, 56, 56) });      // 0x383838
    colorMap.insert ({ "Gray23", new Color (59, 59, 59) });      // 0x3B3B3B
    colorMap.insert ({ "Gray24", new Color (61, 61, 61) });      // 0x3D3D3D
    colorMap.insert ({ "Gray25", new Color (64, 64, 64) });      // 0x404040
    colorMap.insert ({ "Gray26", new Color (66, 66, 66) });      // 0x424242
    colorMap.insert ({ "Gray27", new Color (69, 69, 69) });      // 0x454545
    colorMap.insert ({ "Gray28", new Color (71, 71, 71) });      // 0x474747
    colorMap.insert ({ "Gray29", new Color (74, 74, 74) });      // 0x4A4A4A
    colorMap.insert ({ "Gray3", new Color (8, 8, 8) });      // 0x80808
    colorMap.insert ({ "Gray30", new Color (77, 77, 77) });      // 0x4D4D4D
    colorMap.insert ({ "Gray31", new Color (79, 79, 79) });      // 0x4F4F4F
    colorMap.insert ({ "Gray32", new Color (82, 82, 82) });      // 0x525252
    colorMap.insert ({ "Gray33", new Color (85, 85, 85) });      // 0x555555
    colorMap.insert ({ "Gray34", new Color (87, 87, 87) });      // 0x575757
    colorMap.insert ({ "Gray35", new Color (89, 89, 89) });      // 0x595959
    colorMap.insert ({ "Gray36", new Color (92, 92, 92) });      // 0x5C5C5C
    colorMap.insert ({ "Gray37", new Color (94, 94, 94) });      // 0x5E5E5E
    colorMap.insert ({ "Gray38", new Color (97, 97, 97) });      // 0x616161
    colorMap.insert ({ "Gray39", new Color (99, 99, 99) });      // 0x636363
    colorMap.insert ({ "Gray4", new Color (10, 10, 10) });      // 0x0A0A0A
    colorMap.insert ({ "Gray40", new Color (102, 102, 102) });      // 0x666666
    colorMap.insert ({ "Gray42", new Color (107, 107, 107) });      // 0x6B6B6B
    colorMap.insert ({ "Gray43", new Color (110, 110, 110) });      // 0x6E6E6E
    colorMap.insert ({ "Gray44", new Color (112, 112, 112) });      // 0x707070
    colorMap.insert ({ "Gray45", new Color (115, 115, 115) });      // 0x737373
    colorMap.insert ({ "Gray46", new Color (117, 117, 117) });      // 0x757575
    colorMap.insert ({ "Gray47", new Color (120, 120, 120) });      // 0x787878
    colorMap.insert ({ "Gray48", new Color (122, 122, 122) });      // 0x7A7A7A
    colorMap.insert ({ "Gray49", new Color (125, 125, 125) });      // 0x7D7D7D
    colorMap.insert ({ "Gray5", new Color (13, 13, 13) });      // 0x0D0D0D
    colorMap.insert ({ "Gray50", new Color (127, 127, 127) });      // 0x7F7F7F
    colorMap.insert ({ "Gray51", new Color (130, 130, 130) });      // 0x828282
    colorMap.insert ({ "Gray52", new Color (133, 133, 133) });      // 0x858585
    colorMap.insert ({ "Gray53", new Color (135, 135, 135) });      // 0x878787
    colorMap.insert ({ "Gray54", new Color (138, 138, 138) });      // 0x8A8A8A
    colorMap.insert ({ "Gray55", new Color (140, 140, 140) });      // 0x8C8C8C
    colorMap.insert ({ "Gray56", new Color (143, 143, 143) });      // 0x8F8F8F
    colorMap.insert ({ "Gray57", new Color (145, 145, 145) });      // 0x919191
    colorMap.insert ({ "Gray58", new Color (148, 148, 148) });      // 0x949494
    colorMap.insert ({ "Gray59", new Color (150, 150, 150) });      // 0x969696
    colorMap.insert ({ "Gray6", new Color (15, 15, 15) });      // 0x0F0F0F
    colorMap.insert ({ "Gray60", new Color (153, 153, 153) });      // 0x999999
    colorMap.insert ({ "Gray61", new Color (156, 156, 156) });      // 0x9C9C9C
    colorMap.insert ({ "Gray62", new Color (158, 158, 158) });      // 0x9E9E9E
    colorMap.insert ({ "Gray63", new Color (161, 161, 161) });      // 0xA1A1A1
    colorMap.insert ({ "Gray64", new Color (163, 163, 163) });      // 0xA3A3A3
    colorMap.insert ({ "Gray65", new Color (166, 166, 166) });      // 0xA6A6A6
    colorMap.insert ({ "Gray66", new Color (168, 168, 168) });      // 0xA8A8A8
    colorMap.insert ({ "Gray67", new Color (171, 171, 171) });      // 0xABABAB
    colorMap.insert ({ "Gray68", new Color (173, 173, 173) });      // 0xADADAD
    colorMap.insert ({ "Gray69", new Color (176, 176, 176) });      // 0xB0B0B0
    colorMap.insert ({ "Gray7", new Color (18, 18, 18) });      // 0x121212
    colorMap.insert ({ "Gray70", new Color (179, 179, 179) });      // 0xB3B3B3
    colorMap.insert ({ "Gray71", new Color (181, 181, 181) });      // 0xB5B5B5
    colorMap.insert ({ "Gray72", new Color (184, 184, 184) });      // 0xB8B8B8
    colorMap.insert ({ "Gray73", new Color (186, 186, 186) });      // 0xBABABA
    colorMap.insert ({ "Gray74", new Color (189, 189, 189) });      // 0xBDBDBD
    colorMap.insert ({ "Gray75", new Color (191, 191, 191) });      // 0xBFBFBF
    colorMap.insert ({ "Gray76", new Color (194, 194, 194) });      // 0xC2C2C2
    colorMap.insert ({ "Gray77", new Color (196, 196, 196) });      // 0xC4C4C4
    colorMap.insert ({ "Gray78", new Color (199, 199, 199) });      // 0xC7C7C7
    colorMap.insert ({ "Gray79", new Color (201, 201, 201) });      // 0xC9C9C9
    colorMap.insert ({ "Gray8", new Color (20, 20, 20) });      // 0x141414
    colorMap.insert ({ "Gray80", new Color (204, 204, 204) });      // 0xCCCCCC
    colorMap.insert ({ "Gray81", new Color (207, 207, 207) });      // 0xCFCFCF
    colorMap.insert ({ "Gray82", new Color (209, 209, 209) });      // 0xD1D1D1
    colorMap.insert ({ "Gray83", new Color (212, 212, 212) });      // 0xD4D4D4
    colorMap.insert ({ "Gray84", new Color (214, 214, 214) });      // 0xD6D6D6
    colorMap.insert ({ "Gray85", new Color (217, 217, 217) });      // 0xD9D9D9
    colorMap.insert ({ "Gray86", new Color (219, 219, 219) });      // 0xDBDBDB
    colorMap.insert ({ "Gray87", new Color (222, 222, 222) });      // 0xDEDEDE
    colorMap.insert ({ "Gray88", new Color (224, 224, 224) });      // 0xE0E0E0
    colorMap.insert ({ "Gray89", new Color (227, 227, 227) });      // 0xE3E3E3
    colorMap.insert ({ "Gray9", new Color (23, 23, 23) });      // 0x171717
    colorMap.insert ({ "Gray90", new Color (229, 229, 229) });      // 0xE5E5E5
    colorMap.insert ({ "Gray91", new Color (232, 232, 232) });      // 0xE8E8E8
    colorMap.insert ({ "Gray92", new Color (235, 235, 235) });      // 0xEBEBEB
    colorMap.insert ({ "Gray93", new Color (237, 237, 237) });      // 0xEDEDED
    colorMap.insert ({ "Gray94", new Color (240, 240, 240) });      // 0xF0F0F0
    colorMap.insert ({ "Gray95", new Color (242, 242, 242) });      // 0xF2F2F2
    colorMap.insert ({ "Gray97", new Color (247, 247, 247) });      // 0xF7F7F7
    colorMap.insert ({ "Gray98", new Color (250, 250, 250) });      // 0xFAFAFA
    colorMap.insert ({ "Gray99", new Color (252, 252, 252) });      // 0xFCFCFC
    colorMap.insert ({ "Greek Roof", new Color (59, 106, 160) });      // 0x3B6AA0
    colorMap.insert ({ "Green ", new Color (0, 128, 0) });      // 0x008000
    colorMap.insert ({ "Green Agate", new Color (69, 115, 113) });      // 0x457371
    colorMap.insert ({ "Green Algae", new Color (99, 171, 98) });      // 0x63AB62
    colorMap.insert ({ "Green Apple", new Color (98, 150, 50) });      // 0x629632
    colorMap.insert ({ "Green Ash", new Color (102, 142, 134) });      // 0x6.68E+88
    colorMap.insert ({ "Green Bark", new Color (89, 115, 104) });      // 0x597368
    colorMap.insert ({ "Green Card", new Color (208, 250, 238) });      // 0xD0FAEE
    colorMap.insert ({ "Green Cheese", new Color (143, 168, 128) });      // 0x8FA880
    colorMap.insert ({ "Green Gables", new Color (62, 118, 109) });      // 0x3E766D
    colorMap.insert ({ "Green Goo", new Color (119, 137, 108) });      // 0x77896C
    colorMap.insert ({ "Green Grape", new Color (206, 204, 21) });      // 0xCECC15
    colorMap.insert ({ "Green Grass Of Home", new Color (57, 93, 51) });      // 0x395D33
    colorMap.insert ({ "Green Hornet", new Color (106, 132, 85) });      // 0x6A8455
    colorMap.insert ({ "Green Lantern", new Color (61, 139, 55) });      // 0x3D8B37
    colorMap.insert ({ "Green Led", new Color (93, 252, 10) });      // 0x5DFC0A
    colorMap.insert ({ "Green Line", new Color (50, 149, 85) });      // 0x329555
    colorMap.insert ({ "Green Mist", new Color (188, 237, 145) });      // 0xBCED91
    colorMap.insert ({ "Green Mm", new Color (75, 183, 76) });      // 0x4BB74C
    colorMap.insert ({ "Green Moth", new Color (123, 191, 106) });      // 0x7BBF6A
    colorMap.insert ({ "Green Party", new Color (62, 107, 79) });      // 0x3E6B4F
    colorMap.insert ({ "Green Pepper", new Color (57, 125, 2) });      // 0x397D02
    colorMap.insert ({ "Green Quartz", new Color (138, 163, 123) });      // 0x8AA37B
    colorMap.insert ({ "Green Scrubs", new Color (79, 142, 131) });      // 0x4F8E83
    colorMap.insert ({ "Green Soap", new Color (140, 221, 129) });      // 0x8CDD81
    colorMap.insert ({ "Green Stamp", new Color (81, 123, 88) });      // 0x517B58
    colorMap.insert ({ "Green Taxi", new Color (63, 158, 77) });      // 0x3F9E4D
    colorMap.insert ({ "Green Visor", new Color (77, 120, 101) });      // 0x4D7865
    colorMap.insert ({ "Green2", new Color (0, 238, 0) });      // 0x00EE00
    colorMap.insert ({ "Green3", new Color (0, 205, 0) });      // 0x00CD00
    colorMap.insert ({ "Green4", new Color (0, 139, 0) });      // 0x008B00
    colorMap.insert ({ "Greencopper", new Color (82, 127, 118) });      // 0x527F76
    colorMap.insert ({ "Greenyellow", new Color (147, 219, 112) });      // 0x93DB70
    colorMap.insert ({ "Greenyellow ", new Color (173, 255, 47) });      // 0xADFF2F
    colorMap.insert ({ "Grey ", new Color (128, 128, 128) });      // 0x808080
    colorMap.insert ({ "Guacamole", new Color (166, 215, 133) });      // 0xA6D785
    colorMap.insert ({ "Gummi Green", new Color (36, 211, 48) });      // 0x24D330
    colorMap.insert ({ "Gummi Red", new Color (252, 21, 1) });      // 0xFC1501
    colorMap.insert ({ "Gummi Yellow", new Color (251, 219, 12) });      // 0xFBDB0C
    colorMap.insert ({ "Harold'S Crayon", new Color (182, 32, 132) });      // 0xB62084
    colorMap.insert ({ "Heather Blue", new Color (183, 195, 208) });      // 0xB7C3D0
    colorMap.insert ({ "Hematite", new Color (227, 81, 82) });      // 0xE35152
    colorMap.insert ({ "Holly", new Color (72, 130, 20) });      // 0x488214
    colorMap.insert ({ "Honey", new Color (254, 229, 172) });      // 0xFEE5AC
    colorMap.insert ({ "Honeydew ", new Color (240, 255, 240) });      // 0xF0FFF0
    colorMap.insert ({ "Honeydew2", new Color (224, 238, 224) });      // 0xE0EEE0
    colorMap.insert ({ "Honeydew3", new Color (193, 205, 193) });      // 0xC1CDC1
    colorMap.insert ({ "Honeydew4", new Color (131, 139, 131) });      // 0x838B83
    colorMap.insert ({ "Hotpink ", new Color (255, 105, 180) });      // 0xFF69B4
    colorMap.insert ({ "Hotpink1", new Color (255, 110, 180) });      // 0xFF6EB4
    colorMap.insert ({ "Hotpink2", new Color (238, 106, 167) });      // 0xEE6AA7
    colorMap.insert ({ "Hotpink3", new Color (205, 96, 144) });      // 0xCD6090
    colorMap.insert ({ "Hotpink4", new Color (139, 58, 98) });      // 0x8B3A62
    colorMap.insert ({ "Huntergreen", new Color (33, 94, 33) });      // 0x215000
    colorMap.insert ({ "Iceberg Lettuce", new Color (205, 228, 114) });      // 0xCDE472
    colorMap.insert ({ "Indianred", new Color (176, 23, 31) });      // 0xB0171F
    colorMap.insert ({ "Indianred ", new Color (205, 92, 92) });      // 0xCD5C5C
    colorMap.insert ({ "Indianred1", new Color (255, 106, 106) });      // 0xFF6A6A
    colorMap.insert ({ "Indianred2", new Color (238, 99, 99) });      // 0xEE6363
    colorMap.insert ({ "Indianred3", new Color (205, 85, 85) });      // 0xCD5555
    colorMap.insert ({ "Indianred4", new Color (139, 58, 58) });      // 0x8B3A3A
    colorMap.insert ({ "Indiglo", new Color (5, 233, 255) });      // 0x05E9FF
    colorMap.insert ({ "Indigo", new Color (46, 8, 84) });      // 0x2E0854
    colorMap.insert ({ "Indigo ", new Color (75, 0, 130) });      // 0x4B0082
    colorMap.insert ({ "Indigo Dye", new Color (13, 79, 139) });      // 0x0D4F8B
    colorMap.insert ({ "Indigo Tile", new Color (114, 88, 127) });      // 0x72587F
    colorMap.insert ({ "Indigo2", new Color (33, 136, 104) });      // 0x218868
    colorMap.insert ({ "Irish Flag", new Color (0, 153, 0) });      // 0x009900
    colorMap.insert ({ "Isle Royale Greenstone", new Color (66, 99, 82) });      // 0x426352
    colorMap.insert ({ "Ivory ", new Color (255, 255, 240) });      // 0xFFFFF0
    colorMap.insert ({ "Ivory2", new Color (238, 238, 224) });      // 0xEEEEE0
    colorMap.insert ({ "Ivory3", new Color (205, 205, 193) });      // 0xCDCDC1
    colorMap.insert ({ "Ivory4", new Color (139, 139, 131) });      // 0x8B8B83
    colorMap.insert ({ "Ivoryblack", new Color (41, 36, 33) });      // 0x292421
    colorMap.insert ({ "Jack Pine", new Color (65, 79, 18) });      // 0x414F12
    colorMap.insert ({ "Jolly Green", new Color (156, 203, 25) });      // 0x9CCB19
    colorMap.insert ({ "Jonathan Apple", new Color (179, 67, 43) });      // 0xB3432B
    colorMap.insert ({ "Kakapo", new Color (74, 112, 35) });      // 0x4A7023
    colorMap.insert ({ "Kelly", new Color (76, 187, 23) });      // 0x4CBB17
    colorMap.insert ({ "Kermit", new Color (162, 188, 19) });      // 0xA2BC13
    colorMap.insert ({ "Key Lime Pie", new Color (179, 201, 90) });      // 0xB3C95A
    colorMap.insert ({ "Khaki", new Color (159, 159, 95) });      // 0x9F9F5F
    colorMap.insert ({ "Khaki ", new Color (240, 230, 140) });      // 0xF0E68C
    colorMap.insert ({ "Khaki1", new Color (255, 246, 143) });      // 0xFFF68F
    colorMap.insert ({ "Khaki2", new Color (238, 230, 133) });      // 0xEEE685
    colorMap.insert ({ "Khaki3", new Color (205, 198, 115) });      // 0xCDC673
    colorMap.insert ({ "Khaki4", new Color (139, 134, 78) });      // 0x8B864E
    colorMap.insert ({ "Kidney Bean", new Color (177, 62, 15) });      // 0xB13E0F
    colorMap.insert ({ "Kiwi", new Color (127, 154, 101) });      // 0x7F9A65
    colorMap.insert ({ "Kumquat", new Color (220, 137, 9) });      // 0xDC8909
    colorMap.insert ({ "La Maison Bleue", new Color (96, 175, 254) });      // 0x60AFFE
    colorMap.insert ({ "Lake Erie", new Color (97, 131, 166) });      // 0x6183A6
    colorMap.insert ({ "Lake Huron", new Color (93, 123, 147) });      // 0x5D7B93
    colorMap.insert ({ "Lake Ontario", new Color (77, 113, 163) });      // 0x4D71A3
    colorMap.insert ({ "Lake Superior", new Color (80, 105, 135) });      // 0x506987
    colorMap.insert ({ "Lampblack", new Color (46, 71, 59) });      // 0x2E473B
    colorMap.insert ({ "Latte", new Color (159, 112, 58) });      // 0x9F703A
    colorMap.insert ({ "Lavender", new Color (204, 153, 204) });      // 0xCC99CC
    colorMap.insert ({ "Lavender ", new Color (230, 230, 250) });      // 0xE6E6FA
    colorMap.insert ({ "Lavender Field", new Color (117, 76, 120) });      // 0x754C78
    colorMap.insert ({ "Lavenderblush ", new Color (255, 240, 245) });      // 0xFFF0F5
    colorMap.insert ({ "Lavenderblush2", new Color (238, 224, 229) });      // 0xEEE0E5
    colorMap.insert ({ "Lavenderblush3", new Color (205, 193, 197) });      // 0xCDC1C5
    colorMap.insert ({ "Lavenderblush4", new Color (139, 131, 134) });      // 0x8B8386
    colorMap.insert ({ "Lawngreen ", new Color (124, 252, 0) });      // 0x7CFC00
    colorMap.insert ({ "Lcd Back", new Color (145, 180, 156) });      // 0x91B49C
    colorMap.insert ({ "Lcd Dark ", new Color (80, 119, 134) });      // 0x507786
    colorMap.insert ({ "Leaf", new Color (85, 174, 58) });      // 0x55AE3A
    colorMap.insert ({ "Lemon", new Color (214, 197, 55) });      // 0xD6C537
    colorMap.insert ({ "Lemonchiffon ", new Color (255, 250, 205) });      // 0xFFFACD
    colorMap.insert ({ "Lemonchiffon2", new Color (238, 233, 191) });      // 0xEEE9BF
    colorMap.insert ({ "Lemonchiffon3", new Color (205, 201, 165) });      // 0xCDC9A5
    colorMap.insert ({ "Lemonchiffon4", new Color (139, 137, 112) });      // 0x8B8970
    colorMap.insert ({ "Liberty", new Color (164, 220, 209) });      // 0xA4DCD1
    colorMap.insert ({ "Lichen", new Color (192, 217, 175) });      // 0xC0D9AF
    colorMap.insert ({ "Light Blue", new Color (192, 217, 217) });      // 0xC0D9D9
    colorMap.insert ({ "Light Blue", new Color (143, 216, 216) });      // 0x8FD8D8
    colorMap.insert ({ "Light Blue ", new Color (173, 216, 230) });      // 0xADD8E6
    colorMap.insert ({ "Light Blue1", new Color (191, 239, 255) });      // 0xBFEFFF
    colorMap.insert ({ "Light Blue3", new Color (154, 192, 205) });      // 0x9AC0CD
    colorMap.insert ({ "Light Blue4", new Color (104, 131, 139) });      // 0x68838B
    colorMap.insert ({ "Light Copper", new Color (237, 195, 147) });      // 0xEDC393
    colorMap.insert ({ "Light Coral ", new Color (240, 128, 128) });      // 0xF08080
    colorMap.insert ({ "Light Cyan ", new Color (224, 255, 255) });      // 0xE0FFFF
    colorMap.insert ({ "Light Cyan2", new Color (209, 238, 238) });      // 0xD1EEEE
    colorMap.insert ({ "Light Cyan3", new Color (180, 205, 205) });      // 0xB4CDCD
    colorMap.insert ({ "Light Cyan4", new Color (122, 139, 139) });      // 0x7A8B8B
    colorMap.insert ({ "Light Goldenrod", new Color (238, 221, 130) });      // 0xEEDD82
    colorMap.insert ({ "Light Goldenrod Yellow ", new Color (250, 250, 210) });      // 0xFAFAD2
    colorMap.insert ({ "Light Goldenrod1", new Color (255, 236, 139) });      // 0xFFEC8B
    colorMap.insert ({ "Light Goldenrod2", new Color (238, 220, 130) });      // 0xEEDC82
    colorMap.insert ({ "Light Goldenrod3", new Color (205, 190, 112) });      // 0xCDBE70
    colorMap.insert ({ "Light Goldenrod4", new Color (139, 129, 76) });      // 0x8B814C
    colorMap.insert ({ "Light Gray ", new Color (211, 211, 211) });      // 0xD3D3D3
    colorMap.insert ({ "Light Green ", new Color (144, 238, 144) });      // 0x90EE90
    colorMap.insert ({ "Light Grey ", new Color (211, 211, 211) });      // 0xD3D3D3
    colorMap.insert ({ "Light Pink ", new Color (255, 182, 193) });      // 0xFFB6C1
    colorMap.insert ({ "Light Pink1", new Color (255, 174, 185) });      // 0xFFAEB9
    colorMap.insert ({ "Light Pink2", new Color (238, 162, 173) });      // 0xEEA2AD
    colorMap.insert ({ "Light Pink3", new Color (205, 140, 149) });      // 0xCD8C95
    colorMap.insert ({ "Light Pink4", new Color (139, 95, 101) });      // 0x8B5F65
    colorMap.insert ({ "Light Salmon ", new Color (255, 160, 122) });      // 0xFFA07A
    colorMap.insert ({ "Light Salmon2", new Color (238, 149, 114) });      // 0xEE9572
    colorMap.insert ({ "Light Salmon3", new Color (205, 129, 98) });      // 0xCD8162
    colorMap.insert ({ "Light Salmon4", new Color (139, 87, 66) });      // 0x8B5742
    colorMap.insert ({ "Light Seagreen ", new Color (32, 178, 170) });      // 0x20B2AA
    colorMap.insert ({ "Light Skyblue ", new Color (135, 206, 250) });      // 0x87CEFA
    colorMap.insert ({ "Light Skyblue1", new Color (176, 226, 255) });      // 0xB0E2FF
    colorMap.insert ({ "Light Skyblue2", new Color (164, 211, 238) });      // 0xA4D3EE
    colorMap.insert ({ "Light Skyblue3", new Color (141, 182, 205) });      // 0x8DB6CD
    colorMap.insert ({ "Light Skyblue4", new Color (96, 123, 139) });      // 0x607B8B
    colorMap.insert ({ "Light Slateblue", new Color (132, 112, 255) });      // 0x8470FF
    colorMap.insert ({ "Light Slategray", new Color (119, 136, 153) });      // 0x778899
    colorMap.insert ({ "Light Slategrey", new Color (119, 136, 153) });      // 0x778899
    colorMap.insert ({ "Light Steelblue", new Color (143, 143, 188) });      // 0x8F8FBC
    colorMap.insert ({ "Light Steelblue ", new Color (176, 196, 222) });      // 0xB0C4DE
    colorMap.insert ({ "Light Steelblue1", new Color (202, 225, 255) });      // 0xCAE1FF
    colorMap.insert ({ "Light Steelblue2", new Color (188, 210, 238) });      // 0xBCD2EE
    colorMap.insert ({ "Light Steelblue3", new Color (162, 181, 205) });      // 0xA2B5CD
    colorMap.insert ({ "Light Steelblue4", new Color (110, 123, 139) });      // 0x6E7B8B
    colorMap.insert ({ "Light Teal", new Color (0, 255, 204) });      // 0x00FFCC
    colorMap.insert ({ "Light Wood", new Color (233, 194, 166) });      // 0xE9C2A6
    colorMap.insert ({ "Light Yellow ", new Color (255, 255, 224) });      // 0xFFFFE0
    colorMap.insert ({ "Light Yellow2", new Color (238, 238, 209) });      // 0xEEEED1
    colorMap.insert ({ "Light Yellow3", new Color (205, 205, 180) });      // 0xCDCDB4
    colorMap.insert ({ "Light Yellow4", new Color (139, 139, 122) });      // 0x8B8B7A
    colorMap.insert ({ "Lime ", new Color (0, 255, 0) });      // 0x00FF00
    colorMap.insert ({ "Lime Green ", new Color (50, 205, 50) });      // 0x32CD32
    colorMap.insert ({ "Lime Pulp", new Color (212, 237, 145) });      // 0xD4ED91
    colorMap.insert ({ "Lime Rind", new Color (50, 79, 23) });      // 0x324F17
    colorMap.insert ({ "Lindsay Eyes", new Color (101, 144, 154) });      // 0x65909A
    colorMap.insert ({ "Linen ", new Color (250, 240, 230) });      // 0xFAF0E6
    colorMap.insert ({ "Liz Eyes", new Color (50, 92, 116) });      // 0x325C74
    colorMap.insert ({ "Lizard", new Color (90, 99, 81) });      // 0x5A6351
    colorMap.insert ({ "Madder Lake Deep", new Color (227, 46, 48) });      // 0xE32E30
    colorMap.insert ({ "Magenta", new Color (255, 0, 255) });      // 0xFF00FF
    colorMap.insert ({ "Magenta2", new Color (238, 0, 238) });      // 0xEE00EE
    colorMap.insert ({ "Magenta3", new Color (205, 0, 205) });      // 0xCD00CD
    colorMap.insert ({ "Mailbox", new Color (48, 99, 165) });      // 0x3063A5
    colorMap.insert ({ "Malachite", new Color (16, 128, 112) });      // 0x108070
    colorMap.insert ({ "Malta Blue", new Color (81, 118, 147) });      // 0x517693
    colorMap.insert ({ "Manatee Gray", new Color (176, 166, 164) });      // 0xB0A6A4
    colorMap.insert ({ "Mandarian Orange", new Color (228, 120, 51) });      // 0xE47833
    colorMap.insert ({ "Manganese Blue", new Color (3, 168, 158) });      // 0x03A89E
    colorMap.insert ({ "Maroon ", new Color (128, 0, 0) });      // 0x800000
    colorMap.insert ({ "Maroon1", new Color (255, 52, 179) });      // 0xFF34B3
    colorMap.insert ({ "Maroon3", new Color (205, 41, 144) });      // 0xCD2990
    colorMap.insert ({ "Maroon4", new Color (139, 28, 98) });      // 0x8B1C62
    colorMap.insert ({ "Maroon5", new Color (105, 31, 1) });      // 0x691F01
    colorMap.insert ({ "Maroon6", new Color (142, 35, 107) });      // 0x8E236B
    colorMap.insert ({ "Maroonb0", new Color (176, 48, 96) });      // 0xB03060
    colorMap.insert ({ "Mars Orange", new Color (150, 69, 20) });      // 0x964514
    colorMap.insert ({ "Mars Yellow", new Color (227, 112, 26) });      // 0xE3701A
    colorMap.insert ({ "Martini Olive", new Color (139, 164, 70) });      // 0x8BA446
    colorMap.insert ({ "Masters Jacket", new Color (23, 64, 56) });      // 0x174038
    colorMap.insert ({ "Mediterranean", new Color (62, 118, 109) });      // 0x3E766D
    colorMap.insert ({ "Medium Aquamarine ", new Color (102, 205, 170) });      // 0x66CDAA
    colorMap.insert ({ "Medium Aquamarine2", new Color (50, 204, 153) });      // 0x32CC99
    colorMap.insert ({ "Medium Aquamarine3", new Color (50, 205, 153) });      // 0x32CD99
    colorMap.insert ({ "Medium Blue", new Color (50, 50, 204) });      // 0x3232CC
    colorMap.insert ({ "Medium Blue ", new Color (0, 0, 205) });      // 0x0000CD
    colorMap.insert ({ "Medium Blue2", new Color (50, 50, 205) });      // 0x3232CD
    colorMap.insert ({ "Medium Goldenrod", new Color (234, 234, 174) });      // 0xEAEAAE
    colorMap.insert ({ "Medium Orchid ", new Color (186, 85, 211) });      // 0xBA55D3
    colorMap.insert ({ "Medium Orchid1", new Color (224, 102, 255) });      // 0xE066FF
    colorMap.insert ({ "Medium Orchid2", new Color (209, 95, 238) });      // 0xD15FEE
    colorMap.insert ({ "Medium Orchid3", new Color (180, 82, 205) });      // 0xB452CD
    colorMap.insert ({ "Medium Orchid4", new Color (122, 55, 139) });      // 0x7A378B
    colorMap.insert ({ "Medium Purple ", new Color (147, 112, 219) });      // 0x9370DB
    colorMap.insert ({ "Medium Purple1", new Color (171, 130, 255) });      // 0xAB82FF
    colorMap.insert ({ "Medium Purple2", new Color (159, 121, 238) });      // 0x9F79EE
    colorMap.insert ({ "Medium Purple3", new Color (137, 104, 205) });      // 0x8968CD
    colorMap.insert ({ "Medium Purple4", new Color (93, 71, 139) });      // 0x5D478B
    colorMap.insert ({ "Medium Seagreen", new Color (66, 111, 66) });      // 0x426F42
    colorMap.insert ({ "Medium Seagreen ", new Color (60, 179, 113) });      // 0x3CB371
    colorMap.insert ({ "Medium Slateblue ", new Color (123, 104, 238) });      // 0x7B68EE
    colorMap.insert ({ "Medium Slateblue2", new Color (127, 0, 255) });      // 0x7F00FF
    colorMap.insert ({ "Medium Springgreen ", new Color (0, 250, 154) });      // 0x00FA9A
    colorMap.insert ({ "Medium Turquoise", new Color (112, 219, 219) });      // 0x70DBDB
    colorMap.insert ({ "Medium Turquoise ", new Color (72, 209, 204) });      // 0x48D1CC
    colorMap.insert ({ "Medium Violetred ", new Color (199, 21, 133) });      // 0xC71585
    colorMap.insert ({ "Medium Wood", new Color (166, 128, 100) });      // 0xA68064
    colorMap.insert ({ "Melon", new Color (227, 168, 105) });      // 0xE3A869
    colorMap.insert ({ "Melonrind Green", new Color (223, 255, 165) });      // 0xDFFFA5
    colorMap.insert ({ "Metallic Mint", new Color (55, 253, 252) });      // 0x37FDFC
    colorMap.insert ({ "Midnight Blue ", new Color (25, 25, 112) });      // 0x191970
    colorMap.insert ({ "Midnight Blue2", new Color (0, 0, 51) });      // 0x000033
    colorMap.insert ({ "Midnightblue", new Color (47, 47, 79) });      // 0x2F2F4F
    colorMap.insert ({ "Mint Blue", new Color (219, 254, 248) });      // 0xDBFEF8
    colorMap.insert ({ "Mint Candy", new Color (156, 186, 127) });      // 0x9CBA7F
    colorMap.insert ({ "Mint Green", new Color (189, 252, 201) });      // 0xBDFCC9
    colorMap.insert ({ "Mint Ice Cream", new Color (197, 227, 191) });      // 0xC5E3BF
    colorMap.insert ({ "Mintcream ", new Color (245, 255, 250) });      // 0xF5FFFA
    colorMap.insert ({ "Mistyrose ", new Color (255, 228, 225) });      // 0xFFE4E1
    colorMap.insert ({ "Mistyrose2", new Color (238, 213, 210) });      // 0xEED5D2
    colorMap.insert ({ "Mistyrose3", new Color (205, 183, 181) });      // 0xCDB7B5
    colorMap.insert ({ "Mistyrose4", new Color (139, 125, 123) });      // 0x8B7D7B
    colorMap.insert ({ "Moccasin ", new Color (255, 228, 181) });      // 0xFFE4B5
    colorMap.insert ({ "Mocha Latte", new Color (201, 175, 148) });      // 0xC9AF94
    colorMap.insert ({ "Moon", new Color (219, 230, 224) });      // 0xDBE6E0
    colorMap.insert ({ "Mtn Dew Bottle", new Color (87, 122, 58) });      // 0x577A3A
    colorMap.insert ({ "Mustard", new Color (255, 204, 17) });      // 0xFFCC11
    colorMap.insert ({ "Naples Yellow Deep", new Color (255, 168, 18) });      // 0xFFA812
    colorMap.insert ({ "Natural Gas", new Color (91, 144, 246) });      // 0x5B90F6
    colorMap.insert ({ "Natural Turquoise", new Color (69, 195, 184) });      // 0x45C3B8
    colorMap.insert ({ "Navajowhite ", new Color (255, 222, 173) });      // 0xFFDEAD
    colorMap.insert ({ "Navajowhite2", new Color (238, 207, 161) });      // 0xEECFA1
    colorMap.insert ({ "Navajowhite3", new Color (205, 179, 139) });      // 0xCDB38B
    colorMap.insert ({ "Navajowhite4", new Color (139, 121, 94) });      // 0x8B795E
    colorMap.insert ({ "Navy ", new Color (0, 0, 128) });      // 0x000080
    colorMap.insert ({ "Navy Blue", new Color (35, 35, 142) });      // 0x23238E
    colorMap.insert ({ "Nectarine", new Color (255, 51, 0) });      // 0xFF3300
    colorMap.insert ({ "Neon Avocado", new Color (0, 255, 102) });      // 0x00FF66
    colorMap.insert ({ "Neon Blue", new Color (103, 200, 255) });      // 0x67C8FF
    colorMap.insert ({ "Neon Blue", new Color (77, 77, 255) });      // 0x4D4DFF
    colorMap.insert ({ "Neon Green", new Color (131, 245, 44) });      // 0x83F52C
    colorMap.insert ({ "Neon Pink", new Color (255, 110, 199) });      // 0xFF6EC7
    colorMap.insert ({ "Neptune", new Color (109, 155, 241) });      // 0x6D9BF1
    colorMap.insert ({ "Nerf Green", new Color (73, 226, 14) });      // 0x49E20E
    colorMap.insert ({ "New $20", new Color (183, 200, 182) });      // 0xB7C8B6
    colorMap.insert ({ "New Midnightblue", new Color (0, 0, 156) });      // 0x00009C
    colorMap.insert ({ "New Tan", new Color (235, 199, 158) });      // 0xEBC79E
    colorMap.insert ({ "Night Vision", new Color (123, 204, 112) });      // 0x7BCC70
    colorMap.insert ({ "Nikko Blue", new Color (131, 142, 222) });      // 0x838EDE
    colorMap.insert ({ "Noble Fir", new Color (71, 106, 52) });      // 0x476A34
    colorMap.insert ({ "Novascotia Salmon", new Color (255, 51, 51) });      // 0xFF3333
    colorMap.insert ({ "Nypd Blue", new Color (57, 183, 205) });      // 0x39B7CD
    colorMap.insert ({ "Obsidian", new Color (61, 91, 67) });      // 0x3D5B43
    colorMap.insert ({ "Ochre", new Color (204, 119, 34) });      // 0xCC7722
    colorMap.insert ({ "Octopus", new Color (52, 146, 94) });      // 0x34925E
    colorMap.insert ({ "Offwhiteblue", new Color (204, 204, 255) });      // 0xCCCCFF
    colorMap.insert ({ "Offwhitegreen", new Color (204, 255, 204) });      // 0xCCFFCC
    colorMap.insert ({ "Old Copper", new Color (115, 177, 183) });      // 0x73B1B7
    colorMap.insert ({ "Old Gold", new Color (207, 181, 59) });      // 0xCFB53B
    colorMap.insert ({ "Old Green", new Color (70, 82, 60) });      // 0x46523C
    colorMap.insert ({ "Old Lace ", new Color (253, 245, 230) });      // 0xFDF5E6
    colorMap.insert ({ "Old Money", new Color (51, 113, 71) });      // 0x337147
    colorMap.insert ({ "Olive ", new Color (128, 128, 0) });      // 0x808000
    colorMap.insert ({ "Olive3B", new Color (59, 94, 43) });      // 0x3B5E2B
    colorMap.insert ({ "Olivedrab ", new Color (107, 142, 35) });      // 0x6B8E23
    colorMap.insert ({ "Olivedrab1", new Color (192, 255, 62) });      // 0xC0FF3E
    colorMap.insert ({ "Olivedrab2", new Color (179, 238, 58) });      // 0xB3EE3A
    colorMap.insert ({ "Olivedrab4", new Color (105, 139, 34) });      // 0x698B22
    colorMap.insert ({ "Ooze", new Color (62, 122, 94) });      // 0x3E7A5E
    colorMap.insert ({ "Orange", new Color (255, 128, 0) });      // 0xFF8000
    colorMap.insert ({ "Orange", new Color (255, 102, 0) });      // 0xFF6600
    colorMap.insert ({ "Orange", new Color (204, 50, 50) });      // 0xCC3232
    colorMap.insert ({ "Orange ", new Color (255, 165, 0) });      // 0xFFA500
    colorMap.insert ({ "Orange Candy", new Color (213, 183, 122) });      // 0xD5B77A
    colorMap.insert ({ "Orange Crush", new Color (248, 117, 49) });      // 0xF87531
    colorMap.insert ({ "Orange2", new Color (238, 154, 0) });      // 0xEE9A00
    colorMap.insert ({ "Orange3", new Color (205, 133, 0) });      // 0xCD8500
    colorMap.insert ({ "Orange4", new Color (139, 90, 0) });      // 0x8B5A00
    colorMap.insert ({ "Orange5", new Color (255, 125, 64) });      // 0xFF7D40
    colorMap.insert ({ "Orangered", new Color (255, 0, 127) });      // 0xFF007F
    colorMap.insert ({ "Orangered", new Color (255, 36, 0) });      // 0xFF2400
    colorMap.insert ({ "Orangered ", new Color (255, 69, 0) });      // 0xFF4500
    colorMap.insert ({ "Orangered2", new Color (238, 64, 0) });      // 0xEE4000
    colorMap.insert ({ "Orangered3", new Color (205, 55, 0) });      // 0xCD3700
    colorMap.insert ({ "Orangered4", new Color (255, 64, 64) });      // 0xFF4040
    colorMap.insert ({ "Orchid", new Color (219, 112, 219) });      // 0xDB70DB
    colorMap.insert ({ "Orchid ", new Color (218, 112, 214) });      // 0xDA70D6
    colorMap.insert ({ "Orchid1", new Color (255, 131, 250) });      // 0xFF83FA
    colorMap.insert ({ "Orchid2", new Color (238, 122, 233) });      // 0xEE7AE9
    colorMap.insert ({ "Orchid3", new Color (205, 105, 201) });      // 0xCD69C9
    colorMap.insert ({ "Orchid4", new Color (139, 71, 137) });      // 0x8B4789
    colorMap.insert ({ "Oregon Salmon", new Color (255, 119, 34) });      // 0xFF7722
    colorMap.insert ({ "Organic Tea", new Color (172, 127, 36) });      // 0xAC7F24
    colorMap.insert ({ "Pabst Blue", new Color (40, 58, 144) });      // 0x283A90
    colorMap.insert ({ "Pacific Blue", new Color (53, 88, 108) });      // 0x35586C
    colorMap.insert ({ "Pacific Green", new Color (54, 219, 202) });      // 0x36DBCA
    colorMap.insert ({ "Packer Gold", new Color (252, 181, 20) });      // 0xFCB514
    colorMap.insert ({ "Packer Green", new Color (33, 61, 48) });      // 0x213D30
    colorMap.insert ({ "Pale Green ", new Color (152, 251, 152) });      // 0x98FB98
    colorMap.insert ({ "Pale Green1", new Color (154, 255, 154) });      // 0x9AFF9A
    colorMap.insert ({ "Pale Green3", new Color (124, 205, 124) });      // 0x7CCD7C
    colorMap.insert ({ "Pale Green4", new Color (84, 139, 84) });      // 0x548B54
    colorMap.insert ({ "Pale Turquoise ", new Color (175, 238, 238) });      // 0xAFEEEE
    colorMap.insert ({ "Pale Turquoise1", new Color (187, 255, 255) });      // 0xBBFFFF
    colorMap.insert ({ "Pale Turquoise2", new Color (174, 238, 238) });      // 0xAEEEEE
    colorMap.insert ({ "Pale Turquoise3", new Color (150, 205, 205) });      // 0x96CDCD
    colorMap.insert ({ "Pale Turquoise4", new Color (102, 139, 139) });      // 0x668B8B
    colorMap.insert ({ "Pale Violetred ", new Color (219, 112, 147) });      // 0xDB7093
    colorMap.insert ({ "Pale Violetred1", new Color (255, 130, 171) });      // 0xFF82AB
    colorMap.insert ({ "Pale Violetred2", new Color (238, 121, 159) });      // 0xEE799F
    colorMap.insert ({ "Pale Violetred3", new Color (205, 104, 137) });      // 0xCD6889
    colorMap.insert ({ "Pale Violetred4", new Color (139, 71, 93) });      // 0x8B475D
    colorMap.insert ({ "Palegoldenrod ", new Color (238, 232, 170) });      // 0xEEE8AA
    colorMap.insert ({ "Palm", new Color (96, 131, 65) });      // 0x608341
    colorMap.insert ({ "Papaya", new Color (255, 255, 126) });      // 0xFFFF7E
    colorMap.insert ({ "Papayawhip ", new Color (255, 239, 213) });      // 0xFFEFD5
    colorMap.insert ({ "Park Bench", new Color (46, 100, 68) });      // 0x2E6444
    colorMap.insert ({ "Park Ranger", new Color (72, 77, 70) });      // 0x484D46
    colorMap.insert ({ "Parrot", new Color (53, 121, 220) });      // 0x3579DC
    colorMap.insert ({ "Parrot Green", new Color (51, 255, 51) });      // 0x33FF33
    colorMap.insert ({ "Passion Fruit", new Color (85, 20, 28) });      // 0x55141C
    colorMap.insert ({ "Pastel Blue", new Color (193, 240, 246) });      // 0xC1F0F6
    colorMap.insert ({ "Pastel Green", new Color (146, 204, 166) });      // 0x92CCA6
    colorMap.insert ({ "Pea", new Color (121, 151, 63) });      // 0x79973F
    colorMap.insert ({ "Pea", new Color (120, 171, 70) });      // 0x78AB46
    colorMap.insert ({ "Peach", new Color (255, 153, 85) });      // 0xFF9955
    colorMap.insert ({ "Peach", new Color (254, 240, 219) });      // 0xFEF0DB
    colorMap.insert ({ "Peachpuff", new Color (255, 173, 185) });      // 0xFFADB9
    colorMap.insert ({ "Peachpuff ", new Color (255, 218, 185) });      // 0xFFDAB9
    colorMap.insert ({ "Peachpuff2", new Color (238, 203, 173) });      // 0xEECBAD
    colorMap.insert ({ "Peachpuff3", new Color (205, 175, 149) });      // 0xCDAF95
    colorMap.insert ({ "Peachpuff4", new Color (139, 119, 101) });      // 0x8B7765
    colorMap.insert ({ "Peacock", new Color (51, 161, 201) });      // 0x33A1C9
    colorMap.insert ({ "Peafowl", new Color (29, 124, 242) });      // 0x1D7CF2
    colorMap.insert ({ "Pear", new Color (209, 226, 49) });      // 0xD1E231
    colorMap.insert ({ "Pecan", new Color (225, 142, 46) });      // 0xE18E2E
    colorMap.insert ({ "Periwinkle", new Color (170, 170, 255) });      // 0xAAAAFF
    colorMap.insert ({ "Permanent Green", new Color (10, 201, 43) });      // 0x0AC92B
    colorMap.insert ({ "Permanent Redviolet", new Color (219, 38, 69) });      // 0xDB2645
    colorMap.insert ({ "Peru ", new Color (205, 133, 63) });      // 0xCD853F
    colorMap.insert ({ "Picasso Blue", new Color (2, 118, 253) });      // 0x0276FD
    colorMap.insert ({ "Pickle", new Color (123, 121, 34) });      // 0x7B7922
    colorMap.insert ({ "Piglet Snout", new Color (236, 195, 191) });      // 0xECC3BF
    colorMap.insert ({ "Pineapple", new Color (252, 220, 59) });      // 0xFCDC3B
    colorMap.insert ({ "Pinegreen", new Color (0, 51, 0) });      // 0x3300
    colorMap.insert ({ "Pink ", new Color (255, 192, 203) });      // 0xFFC0CB
    colorMap.insert ({ "Pink Candy", new Color (220, 162, 205) });      // 0xDCA2CD
    colorMap.insert ({ "Pink Cloud", new Color (246, 168, 182) });      // 0xF6A8B6
    colorMap.insert ({ "Pink Glass", new Color (211, 190, 207) });      // 0xD3BECF
    colorMap.insert ({ "Pink Jeep", new Color (224, 66, 127) });      // 0xE0427F
    colorMap.insert ({ "Pink Shell", new Color (246, 204, 218) });      // 0xF6CCDA
    colorMap.insert ({ "Pink1", new Color (255, 181, 197) });      // 0xFFB5C5
    colorMap.insert ({ "Pink2", new Color (238, 169, 184) });      // 0xEEA9B8
    colorMap.insert ({ "Pink3", new Color (205, 145, 158) });      // 0xCD919E
    colorMap.insert ({ "Pink4", new Color (139, 99, 108) });      // 0x8B636C
    colorMap.insert ({ "Pistachio Shell", new Color (235, 206, 172) });      // 0xEBCEAC
    colorMap.insert ({ "Plum ", new Color (221, 160, 221) });      // 0xDDA0DD
    colorMap.insert ({ "Plum Pudding", new Color (134, 42, 81) });      // 0x862A51
    colorMap.insert ({ "Plum1", new Color (255, 187, 255) });      // 0xFFBBFF
    colorMap.insert ({ "Plum2", new Color (234, 173, 234) });      // 0xEAADEA
    colorMap.insert ({ "Plum2", new Color (238, 174, 238) });      // 0xEEAEEE
    colorMap.insert ({ "Plum3", new Color (205, 150, 205) });      // 0xCD96CD
    colorMap.insert ({ "Plum4", new Color (139, 102, 139) });      // 0x8B668B
    colorMap.insert ({ "Police Strobe", new Color (11, 181, 255) });      // 0x0BB5FF
    colorMap.insert ({ "Pollock Blue", new Color (77, 111, 172) });      // 0x4D6FAC
    colorMap.insert ({ "Pomegranate", new Color (246, 77, 84) });      // 0xF64D54
    colorMap.insert ({ "Pond Scum", new Color (104, 126, 90) });      // 0x687E5A
    colorMap.insert ({ "Pool Table", new Color (49, 185, 77) });      // 0x31B94D
    colorMap.insert ({ "Popcorn Yellow", new Color (255, 255, 170) });      // 0xFFFFAA
    colorMap.insert ({ "Powderblue ", new Color (176, 224, 230) });      // 0xB0E0E6
    colorMap.insert ({ "Presidential Blue", new Color (48, 43, 84) });      // 0x302B54
    colorMap.insert ({ "Pumice", new Color (120, 164, 137) });      // 0x78A489
    colorMap.insert ({ "Pummelo Pulp", new Color (245, 120, 90) });      // 0xF5785A
    colorMap.insert ({ "Purple", new Color (160, 32, 240) });      // 0xA020F0
    colorMap.insert ({ "Purple ", new Color (128, 0, 128) });      // 0x800080
    colorMap.insert ({ "Purple Candy", new Color (189, 160, 203) });      // 0xBDA0CB
    colorMap.insert ({ "Purple Fish", new Color (178, 114, 166) });      // 0xB272A6
    colorMap.insert ({ "Purple Ink", new Color (156, 107, 152) });      // 0x9C6B98
    colorMap.insert ({ "Purple Rain", new Color (105, 68, 137) });      // 0x694489
    colorMap.insert ({ "Purple Rose", new Color (94, 45, 121) });      // 0x5E2D79
    colorMap.insert ({ "Purple1", new Color (155, 48, 255) });      // 0x9B30FF
    colorMap.insert ({ "Purple2", new Color (145, 44, 238) });      // 0x912CEE
    colorMap.insert ({ "Purple3", new Color (125, 38, 205) });      // 0x7D26CD
    colorMap.insert ({ "Purple4", new Color (85, 26, 139) });      // 0x551A8B
    colorMap.insert ({ "Purple6", new Color (170, 0, 255) });      // 0xAA00FF
    colorMap.insert ({ "Putting", new Color (105, 152, 100) });      // 0x699864
    colorMap.insert ({ "Pyridium Orange", new Color (240, 168, 4) });      // 0xF0A804
    colorMap.insert ({ "Quartz", new Color (217, 217, 243) });      // 0xD9D9F3
    colorMap.insert ({ "Ralph Yellow", new Color (204, 204, 0) });      // 0xCCCC00
    colorMap.insert ({ "Raspberry", new Color (135, 38, 87) });      // 0x872657
    colorMap.insert ({ "Raspberry Red", new Color (250, 29, 47) });      // 0xFA1D2F
    colorMap.insert ({ "Raw Sienna", new Color (199, 97, 20) });      // 0xC76114
    colorMap.insert ({ "Raw Umber", new Color (115, 74, 18) });      // 0x734A12
    colorMap.insert ({ "Red ", new Color (255, 0, 0) });      // 0xFF0000
    colorMap.insert ({ "Red Coat", new Color (184, 19, 36) });      // 0xB81324
    colorMap.insert ({ "Red Delicious Apple", new Color (157, 19, 9) });      // 0x9D1309
    colorMap.insert ({ "Red Roof", new Color (199, 93, 77) });      // 0xC75D4D
    colorMap.insert ({ "Red2", new Color (238, 0, 0) });      // 0xEE0000
    colorMap.insert ({ "Red3", new Color (205, 0, 0) });      // 0xCD0000
    colorMap.insert ({ "Robin's Egg", new Color (195, 228, 237) });      // 0xC3E4ED
    colorMap.insert ({ "Romaine Lettuce", new Color (59, 83, 35) });      // 0x3B5323
    colorMap.insert ({ "Rose", new Color (255, 0, 204) });      // 0xFF00CC
    colorMap.insert ({ "Rose Madder", new Color (227, 54, 56) });      // 0xE33638
    colorMap.insert ({ "Rosybrown ", new Color (188, 143, 143) });      // 0xBC8F8F
    colorMap.insert ({ "Rosybrown1", new Color (255, 193, 193) });      // 0xFFC1C1
    colorMap.insert ({ "Rosybrown2", new Color (238, 180, 180) });      // 0xEEB4B4
    colorMap.insert ({ "Rosybrown3", new Color (205, 155, 155) });      // 0xCD9B9B
    colorMap.insert ({ "Rosybrown4", new Color (139, 105, 105) });      // 0x8B6969
    colorMap.insert ({ "Royal Palm", new Color (63, 104, 38) });      // 0x3F6826
    colorMap.insert ({ "Royalblue", new Color (51, 51, 255) });      // 0x3333FF
    colorMap.insert ({ "Royalblue ", new Color (65, 105, 225) });      // 0x41690
    colorMap.insert ({ "Royalblue1", new Color (72, 118, 255) });      // 0x4876FF
    colorMap.insert ({ "Royalblue2", new Color (67, 110, 238) });      // 0x436EEE
    colorMap.insert ({ "Royalblue3", new Color (58, 95, 205) });      // 0x3A5FCD
    colorMap.insert ({ "Royalblue4", new Color (39, 64, 139) });      // 0x27408B
    colorMap.insert ({ "Ruby Red", new Color (200, 37, 54) });      // 0xC82536
    colorMap.insert ({ "Saddlebrown ", new Color (139, 69, 19) });      // 0x8B4513
    colorMap.insert ({ "Safety Cone", new Color (255, 83, 51) });      // 0xFF5333
    colorMap.insert ({ "Safety Vest", new Color (200, 245, 38) });      // 0xC8F526
    colorMap.insert ({ "Salmon ", new Color (250, 128, 114) });      // 0xFA8072
    colorMap.insert ({ "Salmon1", new Color (255, 140, 105) });      // 0xFF8C69
    colorMap.insert ({ "Salmon2", new Color (238, 130, 98) });      // 0xEE8262
    colorMap.insert ({ "Salmon3", new Color (205, 112, 84) });      // 0xCD7054
    colorMap.insert ({ "Salmon4", new Color (139, 76, 57) });      // 0x8B4C39
    colorMap.insert ({ "Salmon5", new Color (111, 66, 66) });      // 0x6F4242
    colorMap.insert ({ "Sand", new Color (255, 204, 153) });      // 0xFFCC99
    colorMap.insert ({ "Sandstone", new Color (167, 141, 132) });      // 0xA78D84
    colorMap.insert ({ "Sandybrown ", new Color (244, 164, 96) });      // 0xF4A460
    colorMap.insert ({ "Sapgreen", new Color (48, 128, 20) });      // 0x308014
    colorMap.insert ({ "Scarlet", new Color (140, 23, 23) });      // 0x8C1717
    colorMap.insert ({ "Scotland Pound", new Color (72, 113, 83) });      // 0x487153
    colorMap.insert ({ "Sea Green", new Color (6, 132, 129) });      // 0x68481
    colorMap.insert ({ "Sea Urchin", new Color (104, 58, 94) });      // 0x683A5E
    colorMap.insert ({ "Seagreen", new Color (0, 255, 170) });      // 0x00FFAA
    colorMap.insert ({ "Seagreen1", new Color (84, 255, 159) });      // 0x54FF9F
    colorMap.insert ({ "Seagreen2", new Color (78, 238, 148) });      // 0x4EEE94
    colorMap.insert ({ "Seagreen3", new Color (46, 139, 87) });      // 0x2E8B57
    colorMap.insert ({ "Seashell ", new Color (255, 245, 238) });      // 0xFFF5EE
    colorMap.insert ({ "Seashell2", new Color (238, 229, 222) });      // 0xEEE5DE
    colorMap.insert ({ "Seashell3", new Color (205, 197, 191) });      // 0xCDC5BF
    colorMap.insert ({ "Seashell4", new Color (139, 134, 130) });      // 0x8B8682
    colorMap.insert ({ "Seattle Salmon", new Color (255, 102, 102) });      // 0xFF6666
    colorMap.insert ({ "Seaweed", new Color (100, 111, 94) });      // 0x646F5E
    colorMap.insert ({ "Seaweed Roll", new Color (116, 130, 105) });      // 0x748269
    colorMap.insert ({ "Semisweet Chocolate1", new Color (107, 66, 38) });      // 0x6B4226
    colorMap.insert ({ "Semisweet Chocolate2", new Color (230, 180, 38) });      // 0xE6B426
    colorMap.insert ({ "Sepia", new Color (94, 38, 18) });      // 0x5E2612
    colorMap.insert ({ "Seurat Blue", new Color (115, 154, 197) });      // 0x739AC5
    colorMap.insert ({ "Sgi Beet", new Color (142, 56, 142) });      // 0x8E388E
    colorMap.insert ({ "Sgi Brightgray", new Color (197, 193, 170) });      // 0xC5C1AA
    colorMap.insert ({ "Sgi Chartreuse", new Color (113, 198, 113) });      // 0x71C671
    colorMap.insert ({ "Sgi Light Blue", new Color (125, 158, 192) });      // 0x7D9EC0
    colorMap.insert ({ "Sgi Light Gray", new Color (170, 170, 170) });      // 0xAAAAAA
    colorMap.insert ({ "Sgi Olivedrab", new Color (142, 142, 56) });      // 0x8E8E38
    colorMap.insert ({ "Sgi Salmon", new Color (198, 113, 113) });      // 0xC67171
    colorMap.insert ({ "Sgi Slate Blue", new Color (113, 113, 198) });      // 0x7171C6
    colorMap.insert ({ "Sgi Teal", new Color (56, 142, 142) });      // 0x388E8E
    colorMap.insert ({ "Shamrock", new Color (64, 102, 77) });      // 0x40664D
    colorMap.insert ({ "Shamrock Shake", new Color (178, 208, 180) });      // 0xB2D0B4
    colorMap.insert ({ "Sienna", new Color (142, 107, 35) });      // 0x8E6B23
    colorMap.insert ({ "Sienna ", new Color (160, 82, 45) });      // 0xA0522D
    colorMap.insert ({ "Sienna1", new Color (255, 130, 71) });      // 0xFF8247
    colorMap.insert ({ "Sienna2", new Color (238, 121, 66) });      // 0xEE7942
    colorMap.insert ({ "Sienna3", new Color (205, 104, 57) });      // 0xCD6839
    colorMap.insert ({ "Sienna4", new Color (139, 71, 38) });      // 0x8B4726
    colorMap.insert ({ "Sign Blue", new Color (0, 63, 135) });      // 0x003F87
    colorMap.insert ({ "Sign Brown", new Color (96, 51, 17) });      // 0x603311
    colorMap.insert ({ "Sign Green", new Color (0, 107, 84) });      // 0x006B54
    colorMap.insert ({ "Sign Orange", new Color (221, 117, 0) });      // 0xDD7500
    colorMap.insert ({ "Sign Red", new Color (175, 30, 45) });      // 0xAF1E2D
    colorMap.insert ({ "Sign Yellow", new Color (252, 209, 22) });      // 0xFCD116
    colorMap.insert ({ "Silver", new Color (230, 232, 250) });      // 0xE6E8FA
    colorMap.insert ({ "Silver ", new Color (192, 192, 192) });      // 0xC0C0C0
    colorMap.insert ({ "Skyblue ", new Color (135, 206, 235) });      // 0x87CEEB
    colorMap.insert ({ "Skyblue1", new Color (135, 206, 255) });      // 0x87CEFF
    colorMap.insert ({ "Skyblue2", new Color (126, 192, 238) });      // 0x7EC0EE
    colorMap.insert ({ "Skyblue3", new Color (108, 166, 205) });      // 0x6CA6CD
    colorMap.insert ({ "Skyblue4", new Color (74, 112, 139) });      // 0x4A708B
    colorMap.insert ({ "Skyblue5", new Color (0, 153, 204) });      // 0x0099CC
    colorMap.insert ({ "Skyblue6", new Color (50, 153, 204) });      // 0x3299CC
    colorMap.insert ({ "Slateblue", new Color (0, 127, 255) });      // 0x007FFF
    colorMap.insert ({ "Slateblue ", new Color (106, 90, 205) });      // 0x6A5ACD
    colorMap.insert ({ "Slateblue1", new Color (131, 111, 255) });      // 0x836FFF
    colorMap.insert ({ "Slateblue2", new Color (122, 103, 238) });      // 0x7A67EE
    colorMap.insert ({ "Slateblue3", new Color (105, 89, 205) });      // 0x6959CD
    colorMap.insert ({ "Slateblue4", new Color (71, 60, 139) });      // 0x473C8B
    colorMap.insert ({ "Slategray ", new Color (112, 128, 144) });      // 0x708090
    colorMap.insert ({ "Slategray1", new Color (198, 226, 255) });      // 0xC6E2FF
    colorMap.insert ({ "Slategray2", new Color (185, 211, 238) });      // 0xB9D3EE
    colorMap.insert ({ "Slategray3", new Color (159, 182, 205) });      // 0x9FB6CD
    colorMap.insert ({ "Slategray4", new Color (108, 123, 139) });      // 0x6C7B8B
    colorMap.insert ({ "Slategrey ", new Color (112, 128, 144) });      // 0x708090
    colorMap.insert ({ "Smyrna Purple", new Color (162, 98, 122) });      // 0xA2627A
    colorMap.insert ({ "Snake", new Color (89, 108, 86) });      // 0x596C56
    colorMap.insert ({ "Snow ", new Color (255, 250, 250) });      // 0xFFFAFA
    colorMap.insert ({ "Snow2", new Color (238, 233, 233) });      // 0xEEE9E9
    colorMap.insert ({ "Snow3", new Color (205, 201, 201) });      // 0xCDC9C9
    colorMap.insert ({ "Snow4", new Color (139, 137, 137) });      // 0x8B8989
    colorMap.insert ({ "Soylent Green", new Color (139, 168, 112) });      // 0x8BA870
    colorMap.insert ({ "Soylent Red", new Color (224, 64, 6) });      // 0xE04006
    colorMap.insert ({ "Soylent Yellow", new Color (244, 247, 118) });      // 0xF4F776
    colorMap.insert ({ "Spicy Pink", new Color (255, 28, 174) });      // 0xFF1CAE
    colorMap.insert ({ "Spinach", new Color (67, 93, 54) });      // 0x435D36
    colorMap.insert ({ "Springgreen", new Color (0, 255, 51) });      // 0x00FF33
    colorMap.insert ({ "Springgreen ", new Color (0, 255, 127) });      // 0x00FF7F
    colorMap.insert ({ "Springgreen2", new Color (0, 238, 118) });      // 0x00EE76
    colorMap.insert ({ "Springgreen3", new Color (0, 205, 102) });      // 0x00CD66
    colorMap.insert ({ "Springgreen4", new Color (0, 139, 69) });      // 0x008B45
    colorMap.insert ({ "St Louis Blues", new Color (44, 81, 151) });      // 0x2C5197
    colorMap.insert ({ "Stained Glass", new Color (46, 55, 254) });      // 0x2E37FE
    colorMap.insert ({ "Stainless Steel", new Color (224, 223, 219) });      // 0xE0DFDB
    colorMap.insert ({ "Starbucks", new Color (0, 102, 51) });      // 0x006633
    colorMap.insert ({ "Steelblue", new Color (35, 107, 142) });      // 0x236B8E
    colorMap.insert ({ "Steelblue ", new Color (70, 130, 180) });      // 0x4682B4
    colorMap.insert ({ "Steelblue1", new Color (99, 184, 255) });      // 0x63B8FF
    colorMap.insert ({ "Steelblue2", new Color (92, 172, 238) });      // 0x5CACEE
    colorMap.insert ({ "Steelblue3", new Color (79, 148, 205) });      // 0x4F94CD
    colorMap.insert ({ "Steelblue4", new Color (54, 100, 139) });      // 0x36648B
    colorMap.insert ({ "Strawberry", new Color (190, 38, 37) });      // 0xBE2625
    colorMap.insert ({ "Strawberry Smoothie", new Color (234, 181, 197) });      // 0xEAB5C5
    colorMap.insert ({ "Summer Sky", new Color (56, 176, 222) });      // 0x38B0DE
    colorMap.insert ({ "Surf", new Color (99, 209, 244) });      // 0x63D1F4
    colorMap.insert ({ "Sweet Potato Vine", new Color (162, 201, 58) });      // 0xA2C93A
    colorMap.insert ({ "Swimming Pool", new Color (103, 230, 236) });      // 0x67E6EC
    colorMap.insert ({ "Tan", new Color (219, 147, 112) });      // 0xDB9370
    colorMap.insert ({ "Tan", new Color (238, 136, 51) });      // 0xEE8833
    colorMap.insert ({ "Tan ", new Color (210, 180, 140) });      // 0xD2B48C
    colorMap.insert ({ "Tan1", new Color (255, 165, 79) });      // 0xFFA54F
    colorMap.insert ({ "Tan2", new Color (238, 154, 73) });      // 0xEE9A49
    colorMap.insert ({ "Tan4", new Color (139, 90, 43) });      // 0x8B5A2B
    colorMap.insert ({ "Tangerine", new Color (255, 114, 22) });      // 0xFF7216
    colorMap.insert ({ "Tank", new Color (97, 94, 63) });      // 0x615E3F
    colorMap.insert ({ "Tea Leaves", new Color (95, 117, 94) });      // 0x5F755E
    colorMap.insert ({ "Teal ", new Color (0, 128, 128) });      // 0x008080
    colorMap.insert ({ "Teal LED", new Color (5, 237, 255) });      // 0x05EDFF
    colorMap.insert ({ "Terreverte", new Color (56, 94, 15) });      // 0x385E0F
    colorMap.insert ({ "Thistle", new Color (181, 80, 156) });      // 0xB5509C
    colorMap.insert ({ "Thistle ", new Color (216, 191, 216) });      // 0xD8BFD8
    colorMap.insert ({ "Thistle1", new Color (255, 225, 255) });      // 0xFFE1FF
    colorMap.insert ({ "Thistle2", new Color (238, 210, 238) });      // 0xEED2EE
    colorMap.insert ({ "Thistle3", new Color (205, 181, 205) });      // 0xCDB5CD
    colorMap.insert ({ "Thistle4", new Color (139, 123, 139) });      // 0x8B7B8B
    colorMap.insert ({ "Titanium", new Color (182, 175, 169) });      // 0xB6AFA9
    colorMap.insert ({ "Titanium White", new Color (252, 255, 240) });      // 0xFCFFF0
    colorMap.insert ({ "Tomato ", new Color (255, 99, 71) });      // 0xFF6347
    colorMap.insert ({ "Tomato2", new Color (238, 92, 66) });      // 0xEE5C42
    colorMap.insert ({ "Tomato3", new Color (205, 79, 57) });      // 0xCD4F39
    colorMap.insert ({ "Tomato4", new Color (139, 54, 38) });      // 0x8B3626
    colorMap.insert ({ "Tongue", new Color (231, 158, 169) });      // 0xE79EA9
    colorMap.insert ({ "Topaz", new Color (1, 152, 225) });      // 0x001980
    colorMap.insert ({ "Tree Moss", new Color (101, 157, 50) });      // 0x659D32
    colorMap.insert ({ "Tropical Blue", new Color (98, 177, 246) });      // 0x62B1F6
    colorMap.insert ({ "Truegreen", new Color (0, 175, 51) });      // 0x00AF33
    colorMap.insert ({ "Truepurple", new Color (153, 0, 153) });      // 0x990099
    colorMap.insert ({ "Turnip", new Color (167, 76, 171) });      // 0xA74CAB
    colorMap.insert ({ "Turquoise", new Color (173, 234, 234) });      // 0xADEAEA
    colorMap.insert ({ "Turquoise", new Color (15, 221, 175) });      // 0x0FDDAF
    colorMap.insert ({ "Turquoise ", new Color (64, 224, 208) });      // 0x40E0D0
    colorMap.insert ({ "Turquoise1", new Color (0, 245, 255) });      // 0x00F5FF
    colorMap.insert ({ "Turquoise2", new Color (0, 229, 238) });      // 0x00E5EE
    colorMap.insert ({ "Turquoise3", new Color (0, 197, 205) });      // 0x00C5CD
    colorMap.insert ({ "Turquoise4", new Color (0, 134, 139) });      // 0x00868B
    colorMap.insert ({ "Turquoiseblue", new Color (0, 199, 140) });      // 0x00C78C
    colorMap.insert ({ "Ty Nant", new Color (1, 71, 250) });      // 0x0147FA
    colorMap.insert ({ "Ultramarine", new Color (18, 10, 143) });      // 0x120A8F
    colorMap.insert ({ "Ultramarine Violet", new Color (92, 36, 110) });      // 0x5C246E
    colorMap.insert ({ "Ulysses Butterfly", new Color (20, 100, 244) });      // 0x1464F4
    colorMap.insert ({ "Vandyke Brown", new Color (94, 38, 5) });      // 0x5E2605
    colorMap.insert ({ "Vanilla Mint", new Color (180, 215, 191) });      // 0xB4D7BF
    colorMap.insert ({ "Venetian Red", new Color (212, 26, 31) });      // 0xD41A1F
    colorMap.insert ({ "Very Dark Brown", new Color (92, 64, 51) });      // 0x5C4033
    colorMap.insert ({ "Very Light Grey", new Color (205, 205, 205) });      // 0xCDCDCD
    colorMap.insert ({ "Violet", new Color (79, 47, 79) });      // 0x4F2F4F
    colorMap.insert ({ "Violet", new Color (143, 94, 153) });      // 0x8F5E99
    colorMap.insert ({ "Violet ", new Color (238, 130, 238) });      // 0xEE82EE
    colorMap.insert ({ "Violet Flower", new Color (191, 95, 255) });      // 0xBF5FFF
    colorMap.insert ({ "Violetred", new Color (204, 50, 153) });      // 0xCC3299
    colorMap.insert ({ "Violetred", new Color (208, 32, 144) });      // 0xD02090
    colorMap.insert ({ "Violetred1", new Color (255, 62, 150) });      // 0xFF3E96
    colorMap.insert ({ "Violetred2", new Color (238, 58, 140) });      // 0xEE3A8C
    colorMap.insert ({ "Violetred3", new Color (205, 50, 120) });      // 0xCD3278
    colorMap.insert ({ "Violetred4", new Color (139, 34, 82) });      // 0x8B2252
    colorMap.insert ({ "Viridian Light", new Color (110, 255, 112) });      // 0x6EFF70
    colorMap.insert ({ "Wales", new Color (74, 201, 72) });      // 0x4AC948
    colorMap.insert ({ "Warmgrey", new Color (128, 128, 105) });      // 0x808069
    colorMap.insert ({ "Wasabi", new Color (102, 255, 102) });      // 0x66FF66
    colorMap.insert ({ "Wasabi Sauce", new Color (174, 187, 81) });      // 0xAEBB51
    colorMap.insert ({ "Watermelon Pulp", new Color (242, 71, 63) });      // 0xF2473F
    colorMap.insert ({ "Watermelon Rind", new Color (84, 99, 44) });      // 0x54632C
    colorMap.insert ({ "Wavecrest", new Color (153, 205, 201) });      // 0x99CDC9
    colorMap.insert ({ "Wet Moss", new Color (61, 82, 41) });      // 0x3D5229
    colorMap.insert ({ "Wheat", new Color (216, 216, 191) });      // 0xD8D8BF
    colorMap.insert ({ "Wheat ", new Color (245, 222, 179) });      // 0xF5DEB3
    colorMap.insert ({ "Wheat1", new Color (255, 231, 186) });      // 0xFFE7BA
    colorMap.insert ({ "Wheat2", new Color (238, 216, 174) });      // 0xEED8AE
    colorMap.insert ({ "Wheat3", new Color (205, 186, 150) });      // 0xCDBA96
    colorMap.insert ({ "Wheat4", new Color (139, 126, 102) });      // 0x8B7E66
    colorMap.insert ({ "White ", new Color (255, 255, 255) });      // 0xFFFFFF
    colorMap.insert ({ "Whitesmoke ", new Color (245, 245, 245) });      // 0xF5F5F5
    colorMap.insert ({ "Wild Violet", new Color (130, 11, 187) });      // 0x820BBB
    colorMap.insert ({ "Yellow Candy", new Color (238, 235, 141) });      // 0xEEEB8D
    colorMap.insert ({ "Yellow Perch", new Color (224, 216, 115) });      // 0xE0D873
    colorMap.insert ({ "Yellow", new Color (255, 255, 0) });       // 0xFFFF0
    colorMap.insert ({ "Yellow2", new Color (238, 238, 0) });      // 0xEEEE00
    colorMap.insert ({ "Yellow3", new Color (205, 205, 0) });      // 0xCDCD00
    colorMap.insert ({ "Yellow4", new Color (139, 139, 0) });      // 0x8B8B00
    colorMap.insert ({ "Yellowgreen ", new Color (154, 205, 50) });      // 0x9ACD32
    colorMap.insert ({ "Yellowgreen2", new Color (153, 204, 50) });      // 0x99CC32
    colorMap.insert ({ "Yellowochre", new Color (227, 130, 23) });      // 0xE38217
    colorMap.insert ({ "Yinmn Blue", new Color (46, 80, 144) });      // 0x2E5090
    colorMap.insert ({ "Yolk", new Color (255, 230, 0) });      // 0xFFE600
    colorMap.insert ({ "Zincwhite", new Color (253, 248, 255) });      // 0xFDF8FF
    colorMap.insert ({ "100 Euro", new Color (134, 198, 124) });      // 0x86C67C
    colorMap.insert ({ "20 Pound", new Color (164, 101, 130) });      // 0xA46582
    colorMap.insert ({ "6 Ball", new Color (27, 100, 83) });      // 0x1B6453
}

/**
 * Creates and loads the Name Map.
 */
void ColorTable::loadNameMap () {
    nameMap.insert ({ "000001", "UNKNOWN" });
    nameMap.insert ({ "1B3F8B","Alaska Sky" });
    nameMap.insert ({ "F0F8FF","Alice Blue" });
    nameMap.insert ({ "E32636","Alizarin Crimson" });
    nameMap.insert ({ "C48E48","Almond" });
    nameMap.insert ({ "A9ACB6","Aluminum" });
    nameMap.insert ({ "9D6B84","Amethyst" });
    nameMap.insert ({ "BAAF07","Anjou Pear" });
    nameMap.insert ({ "FAEBD7","Antiquewhite " });
    nameMap.insert ({ "FFEFDB","Antiquewhite1" });
    nameMap.insert ({ "EEDFCC","Antiquewhite2" });
    nameMap.insert ({ "CDC0B0","Antiquewhite3" });
    nameMap.insert ({ "8B8378","Antiquewhite4" });
    nameMap.insert ({ "CC4E5C","Apple" });
    nameMap.insert ({ "FBA16C","Apricot" });
    nameMap.insert ({ "66CCCC","Aqua" });
    nameMap.insert ({ "37BC61","Aquaman" });
    nameMap.insert ({ "70DB93","Aquamarine" });
    nameMap.insert ({ "4E78A0","Aquamarine" });
    nameMap.insert ({ "7FFFD4","Aquamarine " });
    nameMap.insert ({ "76EEC6","Aquamarine2" });
    nameMap.insert ({ "458B74","Aquamarine4" });
    nameMap.insert ({ "2FAA96","Aquarium" });
    nameMap.insert ({ "327556","Army Men" });
    nameMap.insert ({ "353F3E","Army Uniform" });
    nameMap.insert ({ "C6C3B5","Ash" });
    nameMap.insert ({ "2A8E82","Atlantic Green" });
    nameMap.insert ({ "FFA824","Aureoline Yellow" });
    nameMap.insert ({ "A2C257","Avacado" });
    nameMap.insert ({ "98A148","Avocado" });
    nameMap.insert ({ "F0FFFF","Azure " });
    nameMap.insert ({ "E0EEEE","Azure2" });
    nameMap.insert ({ "C1CDCD","Azure3" });
    nameMap.insert ({ "838B8B","Azure4" });
    nameMap.insert ({ "C65D57","Bacon" });
    nameMap.insert ({ "5C3317","Bakers Chocolate" });
    nameMap.insert ({ "E3CF57","Banana" });
    nameMap.insert ({ "0E8C3A","Banker's Lamp" });
    nameMap.insert ({ "D4318C","Barney" });
    nameMap.insert ({ "CDAB2D","Bartlett Pear" });
    nameMap.insert ({ "D0D2C4","Battleship" });
    nameMap.insert ({ "EED6AF","Beach Sand" });
    nameMap.insert ({ "E5BC3B","Beer" });
    nameMap.insert ({ "F5F5DC","Beige " });
    nameMap.insert ({ "A39480","Beige Dark " });
    nameMap.insert ({ "F6C9CC","Bermuda Sand" });
    nameMap.insert ({ "3A66A7","Big Blue Bus" });
    nameMap.insert ({ "A02422","Bing Cherry" });
    nameMap.insert ({ "FFE4C4","Bisque " });
    nameMap.insert ({ "EED5B7","Bisque2" });
    nameMap.insert ({ "CDB79E","Bisque3" });
    nameMap.insert ({ "8B7D6B","Bisque4" });
    nameMap.insert ({ "000000","Black" });
    nameMap.insert ({ "422C2F","Black Beauty Plum" });
    nameMap.insert ({ "3A3A38","Blackberry" });
    nameMap.insert ({ "FFEBCD","Blanched Almond " });
    nameMap.insert ({ "CC1100","Blood Orange" });
    nameMap.insert ({ "660000","Bloodred" });
    nameMap.insert ({ "0000FF","Blue " });
    nameMap.insert ({ "2B4F81","Blue Angels" });
    nameMap.insert ({ "4973AB","Blue Bird" });
    nameMap.insert ({ "499DF5","Blue Bucket" });
    nameMap.insert ({ "344152","Blue Corn" });
    nameMap.insert ({ "584000","Blue Corn Chips" });
    nameMap.insert ({ "88ACE0","Blue Cow" });
    nameMap.insert ({ "380474","Blue Deep" });
    nameMap.insert ({ "525C65","Blue Dog" });
    nameMap.insert ({ "759B84","Blue Fern" });
    nameMap.insert ({ "3B4990","Blue Grapes" });
    nameMap.insert ({ "3B8471","Blue Green Algae" });
    nameMap.insert ({ "DAF4F0","Blue Ice" });
    nameMap.insert ({ "74BBFB","Blue Ice" });
    nameMap.insert ({ "42526C","Blue Jeans" });
    nameMap.insert ({ "4CB7A5","Blue Lagoon" });
    nameMap.insert ({ "33A1DE","Blue Line" });
    nameMap.insert ({ "82CFFD","Blue Mist" });
    nameMap.insert ({ "7D7F94","Blue Nile" });
    nameMap.insert ({ "5190ED","Blue Pill" });
    nameMap.insert ({ "4981CE","Blue Ridge Mtns" });
    nameMap.insert ({ "6600FF","Blue Safe" });
    nameMap.insert ({ "6996AD","Blue Shark" });
    nameMap.insert ({ "26466D","Blue Spider" });
    nameMap.insert ({ "5D92B1","Blue Sponge" });
    nameMap.insert ({ "50729F","Blue Stone" });
    nameMap.insert ({ "3A5894","Blue Train" });
    nameMap.insert ({ "687C97","Blue Tuna" });
    nameMap.insert ({ "162252","Blue Velvet" });
    nameMap.insert ({ "42647F","Blue Whale" });
    nameMap.insert ({ "0000EE","Blue2" });
    nameMap.insert ({ "5971AD","Blueberry Fresh" });
    nameMap.insert ({ "4C7064","Bluegrass" });
    nameMap.insert ({ "9F5F9F","Blueviolet" });
    nameMap.insert ({ "8A2BE2","Blueviolet " });
    nameMap.insert ({ "FFFFCC","Bone" });
    nameMap.insert ({ "99182C","Bordeaux" });
    nameMap.insert ({ "1DA237","Bottle Green" });
    nameMap.insert ({ "BB2A3C","Braeburn Apple" });
    nameMap.insert ({ "B5A642","Brass" });
    nameMap.insert ({ "FCD59C","Bread" });
    nameMap.insert ({ "859C27","Breadfruit" });
    nameMap.insert ({ "9C661F","Brick" });
    nameMap.insert ({ "D9D919","Bright Gold" });
    nameMap.insert ({ "FF0033","Bright Red" });
    nameMap.insert ({ "FF0066","Broadway Pink" });
    nameMap.insert ({ "586949","Broccoli" });
    nameMap.insert ({ "8C7853","Bronze" });
    nameMap.insert ({ "A67D3D","Bronzeii" });
    nameMap.insert ({ "802A2A","Brown" });
    nameMap.insert ({ "DB2929","Brown Madder" });
    nameMap.insert ({ "87421F","Brown Ochre" });
    nameMap.insert ({ "8B2500","Brown1" });
    nameMap.insert ({ "EE3B3B","Brown2" });
    nameMap.insert ({ "CD3333","Brown3" });
    nameMap.insert ({ "B6C5BE","Brushed Aluminum" });
    nameMap.insert ({ "FF92BB","Bubble Gum" });
    nameMap.insert ({ "A5435C","Bunny Eye" });
    nameMap.insert ({ "9E0508","Burgundy" });
    nameMap.insert ({ "DEB887","Burlywood " });
    nameMap.insert ({ "EEC591","Burlywood2" });
    nameMap.insert ({ "CDAA7D","Burlywood3" });
    nameMap.insert ({ "8B7355","Burlywood4" });
    nameMap.insert ({ "8A360F","Burnt Sienna" });
    nameMap.insert ({ "8A3324","Burnt Umber" });
    nameMap.insert ({ "636F57","Cactus" });
    nameMap.insert ({ "5F9F9F","Cadetblue" });
    nameMap.insert ({ "98F5FF","Cadetblue1" });
    nameMap.insert ({ "8EE5EE","Cadetblue2" });
    nameMap.insert ({ "7AC5CD","Cadetblue3" });
    nameMap.insert ({ "53868B","Cadetblue4" });
    nameMap.insert ({ "FFE303","Cadmium Lemon" });
    nameMap.insert ({ "FF6103","Cadmium Orange" });
    nameMap.insert ({ "E3170D","Cadmium Red Deep" });
    nameMap.insert ({ "FF030D","Cadmium Red Light" });
    nameMap.insert ({ "FF9912","Cadmium Yellow" });
    nameMap.insert ({ "FFB00F","Cadmium Yellowlight" });
    nameMap.insert ({ "362819","Cafe Americano" });
    nameMap.insert ({ "B67C3D","Cafe Au Lait" });
    nameMap.insert ({ "CFDBC5","Camo1" });
    nameMap.insert ({ "A9C9A4","Camo2" });
    nameMap.insert ({ "9DB68C","Camo3" });
    nameMap.insert ({ "9CA998","Cantaloupe" });
    nameMap.insert ({ "9D8851","Canvas" });
    nameMap.insert ({ "B28647","Cappuccino" });
    nameMap.insert ({ "42C0FB","Caribbean" });
    nameMap.insert ({ "DE85B1","Carnation" });
    nameMap.insert ({ "539DC2","Carolina Blue" });
    nameMap.insert ({ "ED9121","Carrot" });
    nameMap.insert ({ "DFAE74","Cashew" });
    nameMap.insert ({ "BEE554","Cat Eye" });
    nameMap.insert ({ "7AA9DD","Cat Eye2" });
    nameMap.insert ({ "CFD784","Celery" });
    nameMap.insert ({ "00611C","Celtics" });
    nameMap.insert ({ "05B8CC","Cerulean" });
    nameMap.insert ({ "7FFF00","Chartreuse " });
    nameMap.insert ({ "BCE937","Chartreuse Verte" });
    nameMap.insert ({ "76EE00","Chartreuse2" });
    nameMap.insert ({ "66CD00","Chartreuse3" });
    nameMap.insert ({ "458B00","Chartreuse4" });
    nameMap.insert ({ "FFC469","Cheddar" });
    nameMap.insert ({ "599300","Chemical Suit" });
    nameMap.insert ({ "EB5E66","Cherry" });
    nameMap.insert ({ "D44942","Chili" });
    nameMap.insert ({ "C73F17","Chili Powder" });
    nameMap.insert ({ "993300","Chocolate" });
    nameMap.insert ({ "D2691E","Chocolate " });
    nameMap.insert ({ "FF7F24","Chocolate1" });
    nameMap.insert ({ "EE7621","Chocolate2" });
    nameMap.insert ({ "CD661D","Chocolate3" });
    nameMap.insert ({ "E8F1D4","Chrome" });
    nameMap.insert ({ "668014","Chrome Oxide Green" });
    nameMap.insert ({ "003EFF","Cichlid" });
    nameMap.insert ({ "61B329","Cinnabar Green" });
    nameMap.insert ({ "AA6600","Cinnamon" });
    nameMap.insert ({ "7B3F00","Cinnamon" });
    nameMap.insert ({ "3A6629","Circuit Board" });
    nameMap.insert ({ "3EA055","Clover" });
    nameMap.insert ({ "6666FF","Cobalt" });
    nameMap.insert ({ "3D59AB","Cobalt" });
    nameMap.insert ({ "3D9140","Cobalt Green" });
    nameMap.insert ({ "91219E","Cobalt Violet Deep" });
    nameMap.insert ({ "FFFCCF","Coconut" });
    nameMap.insert ({ "BC7642","Coconut Shell" });
    nameMap.insert ({ "AA5303","Coffee" });
    nameMap.insert ({ "79A888","Coke Bottle" });
    nameMap.insert ({ "AF4035","Cola" });
    nameMap.insert ({ "808A87","Cold Grey" });
    nameMap.insert ({ "D0A9AA","Conch" });
    nameMap.insert ({ "660198","Concord Grape" });
    nameMap.insert ({ "D98719","Cool Copper" });
    nameMap.insert ({ "90FEFB","Cool Mint" });
    nameMap.insert ({ "284942","Cooler" });
    nameMap.insert ({ "B87333","Copper" });
    nameMap.insert ({ "FF7F50","Coral " });
    nameMap.insert ({ "FF7256","Coral1" });
    nameMap.insert ({ "EE6A50","Coral2" });
    nameMap.insert ({ "CD5B45","Coral3" });
    nameMap.insert ({ "8B3E2F","Coral4" });
    nameMap.insert ({ "ECC8EC","Corfu Pink" });
    nameMap.insert ({ "FBEC5D","Corn" });
    nameMap.insert ({ "3300FF","Cornflower" });
    nameMap.insert ({ "42426F","Cornflower Blue" });
    nameMap.insert ({ "6495ED","Cornflower Blue 2" });
    nameMap.insert ({ "FFF8DC","Cornsilk " });
    nameMap.insert ({ "EEE8CD","Cornsilk2" });
    nameMap.insert ({ "CDC8B1","Cornsilk3" });
    nameMap.insert ({ "8B8878","Cornsilk4" });
    nameMap.insert ({ "F7B3DA","Cotton Candy" });
    nameMap.insert ({ "B6316C","Cranberry" });
    nameMap.insert ({ "F54D70","Cranberry Jello" });
    nameMap.insert ({ "C76E06","Crema" });
    nameMap.insert ({ "DC143C","Crimson " });
    nameMap.insert ({ "2C5D3F","Cucumber" });
    nameMap.insert ({ "5B59BA","Curacao" });
    nameMap.insert ({ "00FFFF","Cyan " });
    nameMap.insert ({ "00EEEE","Cyan2" });
    nameMap.insert ({ "00CDCD","Cyan3" });
    nameMap.insert ({ "B8860B","Dark   Goldenrod " });
    nameMap.insert ({ "FFB90F","Dark   Goldenrod1" });
    nameMap.insert ({ "EEAD0E","Dark   Goldenrod2" });
    nameMap.insert ({ "CD950C","Dark   Goldenrod3" });
    nameMap.insert ({ "00008B","Dark  Blue " });
    nameMap.insert ({ "330000","Dark  Cherry Red" });
    nameMap.insert ({ "008B8B","Dark  Cyan " });
    nameMap.insert ({ "8B6508","Dark  Goldenrod4" });
    nameMap.insert ({ "A9A9A9","Dark  Gray " });
    nameMap.insert ({ "2F4F2F","Dark  Green" });
    nameMap.insert ({ "006400","Dark  Green " });
    nameMap.insert ({ "4A766E","Dark  Green Copper" });
    nameMap.insert ({ "A9A9A9","Dark  Grey " });
    nameMap.insert ({ "BDB76B","Dark  Khaki " });
    nameMap.insert ({ "E8C782","Dark  Wheat" });
    nameMap.insert ({ "8B008B","Dark Magenta " });
    nameMap.insert ({ "4F4F2F","Dark Olivegreen" });
    nameMap.insert ({ "556B2F","Dark Olivegreen " });
    nameMap.insert ({ "CAFF70","Dark Olivegreen1" });
    nameMap.insert ({ "BCEE68","Dark Olivegreen2" });
    nameMap.insert ({ "A2CD5A","Dark Olivegreen3" });
    nameMap.insert ({ "6E8B3D","Dark Olivegreen4" });
    nameMap.insert ({ "FF8C00","Dark Orange " });
    nameMap.insert ({ "FF7F00","Dark Orange1" });
    nameMap.insert ({ "EE7600","Dark Orange2" });
    nameMap.insert ({ "CD6600","Dark Orange3" });
    nameMap.insert ({ "8B4500","Dark Orange4" });
    nameMap.insert ({ "FF8600","Dark Orange5" });
    nameMap.insert ({ "9932CD","Dark Orchid" });
    nameMap.insert ({ "9932CC","Dark Orchid " });
    nameMap.insert ({ "B23AEE","Dark Orchid2" });
    nameMap.insert ({ "9A32CD","Dark Orchid3" });
    nameMap.insert ({ "68228B","Dark Orchid4" });
    nameMap.insert ({ "871F78","Dark Purple" });
    nameMap.insert ({ "8B0000","Dark Red " });
    nameMap.insert ({ "E9967A","Dark Salmon " });
    nameMap.insert ({ "8FBC8F","Dark Seagreen " });
    nameMap.insert ({ "C1FFC1","Dark Seagreen1" });
    nameMap.insert ({ "B4EEB4","Dark Seagreen2" });
    nameMap.insert ({ "9BCD9B","Dark Seagreen3" });
    nameMap.insert ({ "698B69","Dark Seagreen4" });
    nameMap.insert ({ "6B238E","Dark Slateblue" });
    nameMap.insert ({ "483D8B","Dark Slateblue " });
    nameMap.insert ({ "2F4F4F","Dark Slategray " });
    nameMap.insert ({ "97FFFF","Dark Slategray1" });
    nameMap.insert ({ "8DEEEE","Dark Slategray2" });
    nameMap.insert ({ "79CDCD","Dark Slategray3" });
    nameMap.insert ({ "528B8B","Dark Slategray4" });
    nameMap.insert ({ "2F4F4F","Dark Slategrey " });
    nameMap.insert ({ "97694F","Dark Tan" });
    nameMap.insert ({ "7093DB","Dark Turquoise" });
    nameMap.insert ({ "00CED1","Dark Turquoise " });
    nameMap.insert ({ "9400D3","Dark Violet " });
    nameMap.insert ({ "855000","Dark Wood" });
    nameMap.insert ({ "733D1A","Deep Ochre" });
    nameMap.insert ({ "FF1493","Deep Pink " });
    nameMap.insert ({ "EE1289","Deep Pink2" });
    nameMap.insert ({ "CD1076","Deep Pink3" });
    nameMap.insert ({ "8B0A50","Deep Pink4" });
    nameMap.insert ({ "551033","Deep Purple" });
    nameMap.insert ({ "00BFFF","Deep Skyblue " });
    nameMap.insert ({ "00B2EE","Deep Skyblue2" });
    nameMap.insert ({ "009ACD","Deep Skyblue3" });
    nameMap.insert ({ "00688B","Deep Skyblue4" });
    nameMap.insert ({ "22316C","Delft" });
    nameMap.insert ({ "4372AA","Denim" });
    nameMap.insert ({ "FEE8D6","Desert Sand" });
    nameMap.insert ({ "0EBFE9","Diamond Blue" });
    nameMap.insert ({ "696969","Dimgray " });
    nameMap.insert ({ "696969","Dimgrey " });
    nameMap.insert ({ "1E90FF","Dodgerblue " });
    nameMap.insert ({ "1C86EE","Dodgerblue2" });
    nameMap.insert ({ "1874CD","Dodgerblue3" });
    nameMap.insert ({ "104E8B","Dodgerblue4" });
    nameMap.insert ({ "F6A4D5","Dog Tongue" });
    nameMap.insert ({ "6F7285","Dolphin" });
    nameMap.insert ({ "3F602B","Douglas Fir" });
    nameMap.insert ({ "3B3178","Dress Blue" });
    nameMap.insert ({ "004F00","Dumpster" });
    nameMap.insert ({ "856363","Dustyrose" });
    nameMap.insert ({ "816687","Eggplant" });
    nameMap.insert ({ "FCE6C9","Eggshell" });
    nameMap.insert ({ "49E9BD","Electric Turquoise" });
    nameMap.insert ({ "5B9C64","Emerald" });
    nameMap.insert ({ "20BF9F","Emerald City" });
    nameMap.insert ({ "00C957","Emerald Green" });
    nameMap.insert ({ "28AE7B","Emerald Green2" });
    nameMap.insert ({ "688571","England Pound" });
    nameMap.insert ({ "D43D1A","Englishred" });
    nameMap.insert ({ "E7C6A5","Espresso" });
    nameMap.insert ({ "D19275","Feldspar" });
    nameMap.insert ({ "526F35","Fenway Grass" });
    nameMap.insert ({ "4A777A","Fenway Monster" });
    nameMap.insert ({ "CDD704","Fire Truck Green" });
    nameMap.insert ({ "B22222","Firebrick " });
    nameMap.insert ({ "FF3030","Firebrick1" });
    nameMap.insert ({ "EE2C2C","Firebrick2" });
    nameMap.insert ({ "CD2626","Firebrick3" });
    nameMap.insert ({ "8B1A1A","Firebrick4" });
    nameMap.insert ({ "8E2323","Firebrick5" });
    nameMap.insert ({ "607C6E","Fisherman's Float" });
    nameMap.insert ({ "FFCCCC","Flat Pink" });
    nameMap.insert ({ "FF5721","Flesh Ochre" });
    nameMap.insert ({ "FFFAF0","Floral White " });
    nameMap.insert ({ "CBCAB6","Fog" });
    nameMap.insert ({ "567E3A","Forestgreen2" });
    nameMap.insert ({ "7EB6FF","Forget Me Nots" });
    nameMap.insert ({ "4D6B50","Fraser Fir" });
    nameMap.insert ({ "5EDA9E","Fresh Green" });
    nameMap.insert ({ "84BE6A","Frog" });
    nameMap.insert ({ "FF00FF","Fuchsia " });
    nameMap.insert ({ "FF00AA","Fuchsia2" });
    nameMap.insert ({ "D66F62","Fuji Apple" });
    nameMap.insert ({ "DCDCDC","Gainsboro " });
    nameMap.insert ({ "777733","Ganegreen" });
    nameMap.insert ({ "138F6A","Garden Hose" });
    nameMap.insert ({ "71637D","Garden Plum" });
    nameMap.insert ({ "E31230","Geranium Lake" });
    nameMap.insert ({ "F8F8FF","Ghostwhite " });
    nameMap.insert ({ "43D58C","Go" });
    nameMap.insert ({ "FFD700","Gold " });
    nameMap.insert ({ "AADD00","Gold Green" });
    nameMap.insert ({ "C77826","Gold Ochre" });
    nameMap.insert ({ "EEC900","Gold2" });
    nameMap.insert ({ "CDAD00","Gold3" });
    nameMap.insert ({ "8B7500","Gold4" });
    nameMap.insert ({ "CC7F32","Gold5" });
    nameMap.insert ({ "CD7F32","Gold6" });
    nameMap.insert ({ "FFAA00","Gold7" });
    nameMap.insert ({ "EDCB62","Golden Delicious Apple" });
    nameMap.insert ({ "DBDB70","Goldenrod" });
    nameMap.insert ({ "DAA520","Goldenrod " });
    nameMap.insert ({ "FFC125","Goldenrod1" });
    nameMap.insert ({ "EEB422","Goldenrod2" });
    nameMap.insert ({ "CD9B1D","Goldenrod3" });
    nameMap.insert ({ "8B6914","Goldenrod4" });
    nameMap.insert ({ "543948","Grape" });
    nameMap.insert ({ "CC00FF","Grape" });
    nameMap.insert ({ "F3E88E","Grapefruit" });
    nameMap.insert ({ "4DBD33","Grass" });
    nameMap.insert ({ "BEBEBE","Gray" });
    nameMap.insert ({ "808080","Gray " });
    nameMap.insert ({ "030303","Gray1" });
    nameMap.insert ({ "1A1A1A","Gray10" });
    nameMap.insert ({ "1C1C1C","Gray11" });
    nameMap.insert ({ "1F1F1F","Gray12" });
    nameMap.insert ({ "212121","Gray13" });
    nameMap.insert ({ "242424","Gray14" });
    nameMap.insert ({ "262626","Gray15" });
    nameMap.insert ({ "292929","Gray16" });
    nameMap.insert ({ "2B2B2B","Gray17" });
    nameMap.insert ({ "2E2E2E","Gray18" });
    nameMap.insert ({ "303030","Gray19" });
    nameMap.insert ({ "050505","Gray2" });
    nameMap.insert ({ "333333","Gray20" });
    nameMap.insert ({ "363636","Gray21" });
    nameMap.insert ({ "383838","Gray22" });
    nameMap.insert ({ "3B3B3B","Gray23" });
    nameMap.insert ({ "3D3D3D","Gray24" });
    nameMap.insert ({ "404040","Gray25" });
    nameMap.insert ({ "424242","Gray26" });
    nameMap.insert ({ "454545","Gray27" });
    nameMap.insert ({ "474747","Gray28" });
    nameMap.insert ({ "4A4A4A","Gray29" });
    nameMap.insert ({ "80808","Gray3" });
    nameMap.insert ({ "4D4D4D","Gray30" });
    nameMap.insert ({ "4F4F4F","Gray31" });
    nameMap.insert ({ "525252","Gray32" });
    nameMap.insert ({ "555555","Gray33" });
    nameMap.insert ({ "575757","Gray34" });
    nameMap.insert ({ "595959","Gray35" });
    nameMap.insert ({ "5C5C5C","Gray36" });
    nameMap.insert ({ "5E5E5E","Gray37" });
    nameMap.insert ({ "616161","Gray38" });
    nameMap.insert ({ "636363","Gray39" });
    nameMap.insert ({ "0A0A0A","Gray4" });
    nameMap.insert ({ "666666","Gray40" });
    nameMap.insert ({ "6B6B6B","Gray42" });
    nameMap.insert ({ "6E6E6E","Gray43" });
    nameMap.insert ({ "707070","Gray44" });
    nameMap.insert ({ "737373","Gray45" });
    nameMap.insert ({ "757575","Gray46" });
    nameMap.insert ({ "787878","Gray47" });
    nameMap.insert ({ "7A7A7A","Gray48" });
    nameMap.insert ({ "7D7D7D","Gray49" });
    nameMap.insert ({ "0D0D0D","Gray5" });
    nameMap.insert ({ "7F7F7F","Gray50" });
    nameMap.insert ({ "828282","Gray51" });
    nameMap.insert ({ "858585","Gray52" });
    nameMap.insert ({ "878787","Gray53" });
    nameMap.insert ({ "8A8A8A","Gray54" });
    nameMap.insert ({ "8C8C8C","Gray55" });
    nameMap.insert ({ "8F8F8F","Gray56" });
    nameMap.insert ({ "919191","Gray57" });
    nameMap.insert ({ "949494","Gray58" });
    nameMap.insert ({ "969696","Gray59" });
    nameMap.insert ({ "0F0F0F","Gray6" });
    nameMap.insert ({ "999999","Gray60" });
    nameMap.insert ({ "9C9C9C","Gray61" });
    nameMap.insert ({ "9E9E9E","Gray62" });
    nameMap.insert ({ "A1A1A1","Gray63" });
    nameMap.insert ({ "A3A3A3","Gray64" });
    nameMap.insert ({ "A6A6A6","Gray65" });
    nameMap.insert ({ "A8A8A8","Gray66" });
    nameMap.insert ({ "ABABAB","Gray67" });
    nameMap.insert ({ "ADADAD","Gray68" });
    nameMap.insert ({ "B0B0B0","Gray69" });
    nameMap.insert ({ "121212","Gray7" });
    nameMap.insert ({ "B3B3B3","Gray70" });
    nameMap.insert ({ "B5B5B5","Gray71" });
    nameMap.insert ({ "B8B8B8","Gray72" });
    nameMap.insert ({ "BABABA","Gray73" });
    nameMap.insert ({ "BDBDBD","Gray74" });
    nameMap.insert ({ "BFBFBF","Gray75" });
    nameMap.insert ({ "C2C2C2","Gray76" });
    nameMap.insert ({ "C4C4C4","Gray77" });
    nameMap.insert ({ "C7C7C7","Gray78" });
    nameMap.insert ({ "C9C9C9","Gray79" });
    nameMap.insert ({ "141414","Gray8" });
    nameMap.insert ({ "CCCCCC","Gray80" });
    nameMap.insert ({ "CFCFCF","Gray81" });
    nameMap.insert ({ "D1D1D1","Gray82" });
    nameMap.insert ({ "D4D4D4","Gray83" });
    nameMap.insert ({ "D6D6D6","Gray84" });
    nameMap.insert ({ "D9D9D9","Gray85" });
    nameMap.insert ({ "DBDBDB","Gray86" });
    nameMap.insert ({ "DEDEDE","Gray87" });
    nameMap.insert ({ "E0E0E0","Gray88" });
    nameMap.insert ({ "E3E3E3","Gray89" });
    nameMap.insert ({ "171717","Gray9" });
    nameMap.insert ({ "E5E5E5","Gray90" });
    nameMap.insert ({ "E8E8E8","Gray91" });
    nameMap.insert ({ "EBEBEB","Gray92" });
    nameMap.insert ({ "EDEDED","Gray93" });
    nameMap.insert ({ "F0F0F0","Gray94" });
    nameMap.insert ({ "F2F2F2","Gray95" });
    nameMap.insert ({ "F7F7F7","Gray97" });
    nameMap.insert ({ "FAFAFA","Gray98" });
    nameMap.insert ({ "FCFCFC","Gray99" });
    nameMap.insert ({ "3B6AA0","Greek Roof" });
    nameMap.insert ({ "008000","Green " });
    nameMap.insert ({ "457371","Green Agate" });
    nameMap.insert ({ "63AB62","Green Algae" });
    nameMap.insert ({ "629632","Green Apple" });
    nameMap.insert ({ "6.68E+88","Green Ash" });
    nameMap.insert ({ "597368","Green Bark" });
    nameMap.insert ({ "D0FAEE","Green Card" });
    nameMap.insert ({ "8FA880","Green Cheese" });
    nameMap.insert ({ "3E766D","Green Gables" });
    nameMap.insert ({ "77896C","Green Goo" });
    nameMap.insert ({ "CECC15","Green Grape" });
    nameMap.insert ({ "395D33","Green Grass Of Home" });
    nameMap.insert ({ "6A8455","Green Hornet" });
    nameMap.insert ({ "3D8B37","Green Lantern" });
    nameMap.insert ({ "5DFC0A","Green Led" });
    nameMap.insert ({ "329555","Green Line" });
    nameMap.insert ({ "BCED91","Green Mist" });
    nameMap.insert ({ "4BB74C","Green Mm" });
    nameMap.insert ({ "7BBF6A","Green Moth" });
    nameMap.insert ({ "3E6B4F","Green Party" });
    nameMap.insert ({ "397D02","Green Pepper" });
    nameMap.insert ({ "8AA37B","Green Quartz" });
    nameMap.insert ({ "4F8E83","Green Scrubs" });
    nameMap.insert ({ "8CDD81","Green Soap" });
    nameMap.insert ({ "517B58","Green Stamp" });
    nameMap.insert ({ "3F9E4D","Green Taxi" });
    nameMap.insert ({ "4D7865","Green Visor" });
    nameMap.insert ({ "00EE00","Green2" });
    nameMap.insert ({ "00CD00","Green3" });
    nameMap.insert ({ "008B00","Green4" });
    nameMap.insert ({ "527F76","Greencopper" });
    nameMap.insert ({ "93DB70","Greenyellow" });
    nameMap.insert ({ "ADFF2F","Greenyellow " });
    nameMap.insert ({ "808080","Grey " });
    nameMap.insert ({ "A6D785","Guacamole" });
    nameMap.insert ({ "24D330","Gummi Green" });
    nameMap.insert ({ "FC1501","Gummi Red" });
    nameMap.insert ({ "FBDB0C","Gummi Yellow" });
    nameMap.insert ({ "B62084","Harold'S Crayon" });
    nameMap.insert ({ "B7C3D0","Heather Blue" });
    nameMap.insert ({ "E35152","Hematite" });
    nameMap.insert ({ "488214","Holly" });
    nameMap.insert ({ "FEE5AC","Honey" });
    nameMap.insert ({ "F0FFF0","Honeydew " });
    nameMap.insert ({ "E0EEE0","Honeydew2" });
    nameMap.insert ({ "C1CDC1","Honeydew3" });
    nameMap.insert ({ "838B83","Honeydew4" });
    nameMap.insert ({ "FF69B4","Hotpink " });
    nameMap.insert ({ "FF6EB4","Hotpink1" });
    nameMap.insert ({ "EE6AA7","Hotpink2" });
    nameMap.insert ({ "CD6090","Hotpink3" });
    nameMap.insert ({ "8B3A62","Hotpink4" });
    nameMap.insert ({ "215000","Huntergreen" });
    nameMap.insert ({ "CDE472","Iceberg Lettuce" });
    nameMap.insert ({ "B0171F","Indianred" });
    nameMap.insert ({ "CD5C5C","Indianred " });
    nameMap.insert ({ "FF6A6A","Indianred1" });
    nameMap.insert ({ "EE6363","Indianred2" });
    nameMap.insert ({ "CD5555","Indianred3" });
    nameMap.insert ({ "8B3A3A","Indianred4" });
    nameMap.insert ({ "05E9FF","Indiglo" });
    nameMap.insert ({ "2E0854","Indigo" });
    nameMap.insert ({ "4B0082","Indigo " });
    nameMap.insert ({ "0D4F8B","Indigo Dye" });
    nameMap.insert ({ "72587F","Indigo Tile" });
    nameMap.insert ({ "218868","Indigo2" });
    nameMap.insert ({ "009900","Irish Flag" });
    nameMap.insert ({ "426352","Isle Royale Greenstone" });
    nameMap.insert ({ "FFFFF0","Ivory " });
    nameMap.insert ({ "EEEEE0","Ivory2" });
    nameMap.insert ({ "CDCDC1","Ivory3" });
    nameMap.insert ({ "8B8B83","Ivory4" });
    nameMap.insert ({ "292421","Ivoryblack" });
    nameMap.insert ({ "414F12","Jack Pine" });
    nameMap.insert ({ "9CCB19","Jolly Green" });
    nameMap.insert ({ "B3432B","Jonathan Apple" });
    nameMap.insert ({ "4A7023","Kakapo" });
    nameMap.insert ({ "4CBB17","Kelly" });
    nameMap.insert ({ "A2BC13","Kermit" });
    nameMap.insert ({ "B3C95A","Key Lime Pie" });
    nameMap.insert ({ "9F9F5F","Khaki" });
    nameMap.insert ({ "F0E68C","Khaki " });
    nameMap.insert ({ "FFF68F","Khaki1" });
    nameMap.insert ({ "EEE685","Khaki2" });
    nameMap.insert ({ "CDC673","Khaki3" });
    nameMap.insert ({ "8B864E","Khaki4" });
    nameMap.insert ({ "B13E0F","Kidney Bean" });
    nameMap.insert ({ "7F9A65","Kiwi" });
    nameMap.insert ({ "DC8909","Kumquat" });
    nameMap.insert ({ "60AFFE","La Maison Bleue" });
    nameMap.insert ({ "6183A6","Lake Erie" });
    nameMap.insert ({ "5D7B93","Lake Huron" });
    nameMap.insert ({ "4D71A3","Lake Ontario" });
    nameMap.insert ({ "506987","Lake Superior" });
    nameMap.insert ({ "2E473B","Lampblack" });
    nameMap.insert ({ "9F703A","Latte" });
    nameMap.insert ({ "CC99CC","Lavender" });
    nameMap.insert ({ "E6E6FA","Lavender " });
    nameMap.insert ({ "754C78","Lavender Field" });
    nameMap.insert ({ "FFF0F5","Lavenderblush " });
    nameMap.insert ({ "EEE0E5","Lavenderblush2" });
    nameMap.insert ({ "CDC1C5","Lavenderblush3" });
    nameMap.insert ({ "8B8386","Lavenderblush4" });
    nameMap.insert ({ "7CFC00","Lawngreen " });
    nameMap.insert ({ "91B49C","Lcd Back" });
    nameMap.insert ({ "507786","Lcd Dark " });
    nameMap.insert ({ "55AE3A","Leaf" });
    nameMap.insert ({ "D6C537","Lemon" });
    nameMap.insert ({ "FFFACD","Lemonchiffon " });
    nameMap.insert ({ "EEE9BF","Lemonchiffon2" });
    nameMap.insert ({ "CDC9A5","Lemonchiffon3" });
    nameMap.insert ({ "8B8970","Lemonchiffon4" });
    nameMap.insert ({ "A4DCD1","Liberty" });
    nameMap.insert ({ "C0D9AF","Lichen" });
    nameMap.insert ({ "C0D9D9","Light Blue" });
    nameMap.insert ({ "8FD8D8","Light Blue" });
    nameMap.insert ({ "ADD8E6","Light Blue " });
    nameMap.insert ({ "BFEFFF","Light Blue1" });
    nameMap.insert ({ "9AC0CD","Light Blue3" });
    nameMap.insert ({ "68838B","Light Blue4" });
    nameMap.insert ({ "EDC393","Light Copper" });
    nameMap.insert ({ "F08080","Light Coral " });
    nameMap.insert ({ "E0FFFF","Light Cyan " });
    nameMap.insert ({ "D1EEEE","Light Cyan2" });
    nameMap.insert ({ "B4CDCD","Light Cyan3" });
    nameMap.insert ({ "7A8B8B","Light Cyan4" });
    nameMap.insert ({ "EEDD82","Light Goldenrod" });
    nameMap.insert ({ "FAFAD2","Light Goldenrod Yellow " });
    nameMap.insert ({ "FFEC8B","Light Goldenrod1" });
    nameMap.insert ({ "EEDC82","Light Goldenrod2" });
    nameMap.insert ({ "CDBE70","Light Goldenrod3" });
    nameMap.insert ({ "8B814C","Light Goldenrod4" });
    nameMap.insert ({ "D3D3D3","Light Gray " });
    nameMap.insert ({ "90EE90","Light Green " });
    nameMap.insert ({ "D3D3D3","Light Grey " });
    nameMap.insert ({ "FFB6C1","Light Pink " });
    nameMap.insert ({ "FFAEB9","Light Pink1" });
    nameMap.insert ({ "EEA2AD","Light Pink2" });
    nameMap.insert ({ "CD8C95","Light Pink3" });
    nameMap.insert ({ "8B5F65","Light Pink4" });
    nameMap.insert ({ "FFA07A","Light Salmon " });
    nameMap.insert ({ "EE9572","Light Salmon2" });
    nameMap.insert ({ "CD8162","Light Salmon3" });
    nameMap.insert ({ "8B5742","Light Salmon4" });
    nameMap.insert ({ "20B2AA","Light Seagreen " });
    nameMap.insert ({ "87CEFA","Light Skyblue " });
    nameMap.insert ({ "B0E2FF","Light Skyblue1" });
    nameMap.insert ({ "A4D3EE","Light Skyblue2" });
    nameMap.insert ({ "8DB6CD","Light Skyblue3" });
    nameMap.insert ({ "607B8B","Light Skyblue4" });
    nameMap.insert ({ "8470FF","Light Slateblue" });
    nameMap.insert ({ "778899","Light Slategray" });
    nameMap.insert ({ "778899","Light Slategrey" });
    nameMap.insert ({ "8F8FBC","Light Steelblue" });
    nameMap.insert ({ "B0C4DE","Light Steelblue " });
    nameMap.insert ({ "CAE1FF","Light Steelblue1" });
    nameMap.insert ({ "BCD2EE","Light Steelblue2" });
    nameMap.insert ({ "A2B5CD","Light Steelblue3" });
    nameMap.insert ({ "6E7B8B","Light Steelblue4" });
    nameMap.insert ({ "00FFCC","Light Teal" });
    nameMap.insert ({ "E9C2A6","Light Wood" });
    nameMap.insert ({ "FFFFE0","Light Yellow " });
    nameMap.insert ({ "EEEED1","Light Yellow2" });
    nameMap.insert ({ "CDCDB4","Light Yellow3" });
    nameMap.insert ({ "8B8B7A","Light Yellow4" });
    nameMap.insert ({ "00FF00","Lime " });
    nameMap.insert ({ "32CD32","Lime Green " });
    nameMap.insert ({ "D4ED91","Lime Pulp" });
    nameMap.insert ({ "324F17","Lime Rind" });
    nameMap.insert ({ "65909A","Lindsay Eyes" });
    nameMap.insert ({ "FAF0E6","Linen " });
    nameMap.insert ({ "325C74","Liz Eyes" });
    nameMap.insert ({ "5A6351","Lizard" });
    nameMap.insert ({ "E32E30","Madder Lake Deep" });
    nameMap.insert ({ "FF00FF","Magenta" });
    nameMap.insert ({ "EE00EE","Magenta2" });
    nameMap.insert ({ "CD00CD","Magenta3" });
    nameMap.insert ({ "3063A5","Mailbox" });
    nameMap.insert ({ "108070","Malachite" });
    nameMap.insert ({ "517693","Malta Blue" });
    nameMap.insert ({ "B0A6A4","Manatee Gray" });
    nameMap.insert ({ "E47833","Mandarian Orange" });
    nameMap.insert ({ "03A89E","Manganese Blue" });
    nameMap.insert ({ "800000","Maroon " });
    nameMap.insert ({ "FF34B3","Maroon1" });
    nameMap.insert ({ "CD2990","Maroon3" });
    nameMap.insert ({ "8B1C62","Maroon4" });
    nameMap.insert ({ "691F01","Maroon5" });
    nameMap.insert ({ "8E236B","Maroon6" });
    nameMap.insert ({ "B03060","Maroonb0" });
    nameMap.insert ({ "964514","Mars Orange" });
    nameMap.insert ({ "E3701A","Mars Yellow" });
    nameMap.insert ({ "8BA446","Martini Olive" });
    nameMap.insert ({ "174038","Masters Jacket" });
    nameMap.insert ({ "3E766D","Mediterranean" });
    nameMap.insert ({ "66CDAA","Medium Aquamarine " });
    nameMap.insert ({ "32CC99","Medium Aquamarine2" });
    nameMap.insert ({ "32CD99","Medium Aquamarine3" });
    nameMap.insert ({ "3232CC","Medium Blue" });
    nameMap.insert ({ "0000CD","Medium Blue " });
    nameMap.insert ({ "3232CD","Medium Blue2" });
    nameMap.insert ({ "EAEAAE","Medium Goldenrod" });
    nameMap.insert ({ "BA55D3","Medium Orchid " });
    nameMap.insert ({ "E066FF","Medium Orchid1" });
    nameMap.insert ({ "D15FEE","Medium Orchid2" });
    nameMap.insert ({ "B452CD","Medium Orchid3" });
    nameMap.insert ({ "7A378B","Medium Orchid4" });
    nameMap.insert ({ "9370DB","Medium Purple " });
    nameMap.insert ({ "AB82FF","Medium Purple1" });
    nameMap.insert ({ "9F79EE","Medium Purple2" });
    nameMap.insert ({ "8968CD","Medium Purple3" });
    nameMap.insert ({ "5D478B","Medium Purple4" });
    nameMap.insert ({ "426F42","Medium Seagreen" });
    nameMap.insert ({ "3CB371","Medium Seagreen " });
    nameMap.insert ({ "7B68EE","Medium Slateblue " });
    nameMap.insert ({ "7F00FF","Medium Slateblue2" });
    nameMap.insert ({ "00FA9A","Medium Springgreen " });
    nameMap.insert ({ "70DBDB","Medium Turquoise" });
    nameMap.insert ({ "48D1CC","Medium Turquoise " });
    nameMap.insert ({ "C71585","Medium Violetred " });
    nameMap.insert ({ "A68064","Medium Wood" });
    nameMap.insert ({ "E3A869","Melon" });
    nameMap.insert ({ "DFFFA5","Melonrind Green" });
    nameMap.insert ({ "37FDFC","Metallic Mint" });
    nameMap.insert ({ "191970","Midnight Blue " });
    nameMap.insert ({ "000033","Midnight Blue2" });
    nameMap.insert ({ "2F2F4F","Midnightblue" });
    nameMap.insert ({ "DBFEF8","Mint Blue" });
    nameMap.insert ({ "9CBA7F","Mint Candy" });
    nameMap.insert ({ "BDFCC9","Mint Green" });
    nameMap.insert ({ "C5E3BF","Mint Ice Cream" });
    nameMap.insert ({ "F5FFFA","Mintcream " });
    nameMap.insert ({ "FFE4E1","Mistyrose " });
    nameMap.insert ({ "EED5D2","Mistyrose2" });
    nameMap.insert ({ "CDB7B5","Mistyrose3" });
    nameMap.insert ({ "8B7D7B","Mistyrose4" });
    nameMap.insert ({ "FFE4B5","Moccasin " });
    nameMap.insert ({ "C9AF94","Mocha Latte" });
    nameMap.insert ({ "DBE6E0","Moon" });
    nameMap.insert ({ "577A3A","Mtn Dew Bottle" });
    nameMap.insert ({ "FFCC11","Mustard" });
    nameMap.insert ({ "FFA812","Naples Yellow Deep" });
    nameMap.insert ({ "5B90F6","Natural Gas" });
    nameMap.insert ({ "45C3B8","Natural Turquoise" });
    nameMap.insert ({ "FFDEAD","Navajowhite " });
    nameMap.insert ({ "EECFA1","Navajowhite2" });
    nameMap.insert ({ "CDB38B","Navajowhite3" });
    nameMap.insert ({ "8B795E","Navajowhite4" });
    nameMap.insert ({ "000080","Navy " });
    nameMap.insert ({ "23238E","Navy Blue" });
    nameMap.insert ({ "FF3300","Nectarine" });
    nameMap.insert ({ "00FF66","Neon Avocado" });
    nameMap.insert ({ "67C8FF","Neon Blue" });
    nameMap.insert ({ "4D4DFF","Neon Blue" });
    nameMap.insert ({ "83F52C","Neon Green" });
    nameMap.insert ({ "FF6EC7","Neon Pink" });
    nameMap.insert ({ "6D9BF1","Neptune" });
    nameMap.insert ({ "49E20E","Nerf Green" });
    nameMap.insert ({ "B7C8B6","New $20" });
    nameMap.insert ({ "00009C","New Midnightblue" });
    nameMap.insert ({ "EBC79E","New Tan" });
    nameMap.insert ({ "7BCC70","Night Vision" });
    nameMap.insert ({ "838EDE","Nikko Blue" });
    nameMap.insert ({ "476A34","Noble Fir" });
    nameMap.insert ({ "FF3333","Novascotia Salmon" });
    nameMap.insert ({ "39B7CD","Nypd Blue" });
    nameMap.insert ({ "3D5B43","Obsidian" });
    nameMap.insert ({ "CC7722","Ochre" });
    nameMap.insert ({ "34925E","Octopus" });
    nameMap.insert ({ "CCCCFF","Offwhiteblue" });
    nameMap.insert ({ "CCFFCC","Offwhitegreen" });
    nameMap.insert ({ "73B1B7","Old Copper" });
    nameMap.insert ({ "CFB53B","Old Gold" });
    nameMap.insert ({ "46523C","Old Green" });
    nameMap.insert ({ "FDF5E6","Old Lace " });
    nameMap.insert ({ "337147","Old Money" });
    nameMap.insert ({ "808000","Olive " });
    nameMap.insert ({ "3B5E2B","Olive3B" });
    nameMap.insert ({ "6B8E23","Olivedrab " });
    nameMap.insert ({ "C0FF3E","Olivedrab1" });
    nameMap.insert ({ "B3EE3A","Olivedrab2" });
    nameMap.insert ({ "698B22","Olivedrab4" });
    nameMap.insert ({ "3E7A5E","Ooze" });
    nameMap.insert ({ "FF8000","Orange" });
    nameMap.insert ({ "FF6600","Orange" });
    nameMap.insert ({ "CC3232","Orange" });
    nameMap.insert ({ "FFA500","Orange " });
    nameMap.insert ({ "D5B77A","Orange Candy" });
    nameMap.insert ({ "F87531","Orange Crush" });
    nameMap.insert ({ "EE9A00","Orange2" });
    nameMap.insert ({ "CD8500","Orange3" });
    nameMap.insert ({ "8B5A00","Orange4" });
    nameMap.insert ({ "FF7D40","Orange5" });
    nameMap.insert ({ "FF007F","Orangered" });
    nameMap.insert ({ "FF2400","Orangered" });
    nameMap.insert ({ "FF4500","Orangered " });
    nameMap.insert ({ "EE4000","Orangered2" });
    nameMap.insert ({ "CD3700","Orangered3" });
    nameMap.insert ({ "FF4040","Orangered4" });
    nameMap.insert ({ "DB70DB","Orchid" });
    nameMap.insert ({ "DA70D6","Orchid " });
    nameMap.insert ({ "FF83FA","Orchid1" });
    nameMap.insert ({ "EE7AE9","Orchid2" });
    nameMap.insert ({ "CD69C9","Orchid3" });
    nameMap.insert ({ "8B4789","Orchid4" });
    nameMap.insert ({ "FF7722","Oregon Salmon" });
    nameMap.insert ({ "AC7F24","Organic Tea" });
    nameMap.insert ({ "283A90","Pabst Blue" });
    nameMap.insert ({ "35586C","Pacific Blue" });
    nameMap.insert ({ "36DBCA","Pacific Green" });
    nameMap.insert ({ "FCB514","Packer Gold" });
    nameMap.insert ({ "213D30","Packer Green" });
    nameMap.insert ({ "98FB98","Pale Green " });
    nameMap.insert ({ "9AFF9A","Pale Green1" });
    nameMap.insert ({ "7CCD7C","Pale Green3" });
    nameMap.insert ({ "548B54","Pale Green4" });
    nameMap.insert ({ "AFEEEE","Pale Turquoise " });
    nameMap.insert ({ "BBFFFF","Pale Turquoise1" });
    nameMap.insert ({ "AEEEEE","Pale Turquoise2" });
    nameMap.insert ({ "96CDCD","Pale Turquoise3" });
    nameMap.insert ({ "668B8B","Pale Turquoise4" });
    nameMap.insert ({ "DB7093","Pale Violetred " });
    nameMap.insert ({ "FF82AB","Pale Violetred1" });
    nameMap.insert ({ "EE799F","Pale Violetred2" });
    nameMap.insert ({ "CD6889","Pale Violetred3" });
    nameMap.insert ({ "8B475D","Pale Violetred4" });
    nameMap.insert ({ "EEE8AA","Palegoldenrod " });
    nameMap.insert ({ "608341","Palm" });
    nameMap.insert ({ "FFFF7E","Papaya" });
    nameMap.insert ({ "FFEFD5","Papayawhip " });
    nameMap.insert ({ "2E6444","Park Bench" });
    nameMap.insert ({ "484D46","Park Ranger" });
    nameMap.insert ({ "3579DC","Parrot" });
    nameMap.insert ({ "33FF33","Parrot Green" });
    nameMap.insert ({ "55141C","Passion Fruit" });
    nameMap.insert ({ "C1F0F6","Pastel Blue" });
    nameMap.insert ({ "92CCA6","Pastel Green" });
    nameMap.insert ({ "79973F","Pea" });
    nameMap.insert ({ "78AB46","Pea" });
    nameMap.insert ({ "FF9955","Peach" });
    nameMap.insert ({ "FEF0DB","Peach" });
    nameMap.insert ({ "FFADB9","Peachpuff" });
    nameMap.insert ({ "FFDAB9","Peachpuff " });
    nameMap.insert ({ "EECBAD","Peachpuff2" });
    nameMap.insert ({ "CDAF95","Peachpuff3" });
    nameMap.insert ({ "8B7765","Peachpuff4" });
    nameMap.insert ({ "33A1C9","Peacock" });
    nameMap.insert ({ "1D7CF2","Peafowl" });
    nameMap.insert ({ "D1E231","Pear" });
    nameMap.insert ({ "E18E2E","Pecan" });
    nameMap.insert ({ "AAAAFF","Periwinkle" });
    nameMap.insert ({ "0AC92B","Permanent Green" });
    nameMap.insert ({ "DB2645","Permanent Redviolet" });
    nameMap.insert ({ "CD853F","Peru " });
    nameMap.insert ({ "0276FD","Picasso Blue" });
    nameMap.insert ({ "7B7922","Pickle" });
    nameMap.insert ({ "ECC3BF","Piglet Snout" });
    nameMap.insert ({ "FCDC3B","Pineapple" });
    nameMap.insert ({ "003300","Pinegreen" });
    nameMap.insert ({ "FFC0CB","Pink " });
    nameMap.insert ({ "DCA2CD","Pink Candy" });
    nameMap.insert ({ "F6A8B6","Pink Cloud" });
    nameMap.insert ({ "D3BECF","Pink Glass" });
    nameMap.insert ({ "E0427F","Pink Jeep" });
    nameMap.insert ({ "F6CCDA","Pink Shell" });
    nameMap.insert ({ "FFB5C5","Pink1" });
    nameMap.insert ({ "EEA9B8","Pink2" });
    nameMap.insert ({ "CD919E","Pink3" });
    nameMap.insert ({ "8B636C","Pink4" });
    nameMap.insert ({ "EBCEAC","Pistachio Shell" });
    nameMap.insert ({ "DDA0DD","Plum " });
    nameMap.insert ({ "862A51","Plum Pudding" });
    nameMap.insert ({ "FFBBFF","Plum1" });
    nameMap.insert ({ "EAADEA","Plum2" });
    nameMap.insert ({ "EEAEEE","Plum2" });
    nameMap.insert ({ "CD96CD","Plum3" });
    nameMap.insert ({ "8B668B","Plum4" });
    nameMap.insert ({ "0BB5FF","Police Strobe" });
    nameMap.insert ({ "4D6FAC","Pollock Blue" });
    nameMap.insert ({ "F64D54","Pomegranate" });
    nameMap.insert ({ "687E5A","Pond Scum" });
    nameMap.insert ({ "31B94D","Pool Table" });
    nameMap.insert ({ "FFFFAA","Popcorn Yellow" });
    nameMap.insert ({ "B0E0E6","Powderblue " });
    nameMap.insert ({ "302B54","Presidential Blue" });
    nameMap.insert ({ "78A489","Pumice" });
    nameMap.insert ({ "F5785A","Pummelo Pulp" });
    nameMap.insert ({ "A020F0","Purple" });
    nameMap.insert ({ "800080","Purple " });
    nameMap.insert ({ "BDA0CB","Purple Candy" });
    nameMap.insert ({ "B272A6","Purple Fish" });
    nameMap.insert ({ "9C6B98","Purple Ink" });
    nameMap.insert ({ "694489","Purple Rain" });
    nameMap.insert ({ "5E2D79","Purple Rose" });
    nameMap.insert ({ "9B30FF","Purple1" });
    nameMap.insert ({ "912CEE","Purple2" });
    nameMap.insert ({ "7D26CD","Purple3" });
    nameMap.insert ({ "551A8B","Purple4" });
    nameMap.insert ({ "AA00FF","Purple6" });
    nameMap.insert ({ "699864","Putting" });
    nameMap.insert ({ "F0A804","Pyridium Orange" });
    nameMap.insert ({ "D9D9F3","Quartz" });
    nameMap.insert ({ "CCCC00","Ralph Yellow" });
    nameMap.insert ({ "872657","Raspberry" });
    nameMap.insert ({ "FA1D2F","Raspberry Red" });
    nameMap.insert ({ "C76114","Raw Sienna" });
    nameMap.insert ({ "734A12","Raw Umber" });
    nameMap.insert ({ "FF0000","Red " });
    nameMap.insert ({ "B81324","Red Coat" });
    nameMap.insert ({ "9D1309","Red Delicious Apple" });
    nameMap.insert ({ "C75D4D","Red Roof" });
    nameMap.insert ({ "EE0000","Red2" });
    nameMap.insert ({ "CD0000","Red3" });
    nameMap.insert ({ "C3E4ED","Robin's Egg" });
    nameMap.insert ({ "3B5323","Romaine Lettuce" });
    nameMap.insert ({ "FF00CC","Rose" });
    nameMap.insert ({ "E33638","Rose Madder" });
    nameMap.insert ({ "BC8F8F","Rosybrown " });
    nameMap.insert ({ "FFC1C1","Rosybrown1" });
    nameMap.insert ({ "EEB4B4","Rosybrown2" });
    nameMap.insert ({ "CD9B9B","Rosybrown3" });
    nameMap.insert ({ "8B6969","Rosybrown4" });
    nameMap.insert ({ "3F6826","Royal Palm" });
    nameMap.insert ({ "3333FF","Royalblue" });
    nameMap.insert ({ "41690","Royalblue " });
    nameMap.insert ({ "4876FF","Royalblue1" });
    nameMap.insert ({ "436EEE","Royalblue2" });
    nameMap.insert ({ "3A5FCD","Royalblue3" });
    nameMap.insert ({ "27408B","Royalblue4" });
    nameMap.insert ({ "C82536","Ruby Red" });
    nameMap.insert ({ "8B4513","Saddlebrown " });
    nameMap.insert ({ "FF5333","Safety Cone" });
    nameMap.insert ({ "C8F526","Safety Vest" });
    nameMap.insert ({ "FA8072","Salmon " });
    nameMap.insert ({ "FF8C69","Salmon1" });
    nameMap.insert ({ "EE8262","Salmon2" });
    nameMap.insert ({ "CD7054","Salmon3" });
    nameMap.insert ({ "8B4C39","Salmon4" });
    nameMap.insert ({ "6F4242","Salmon5" });
    nameMap.insert ({ "FFCC99","Sand" });
    nameMap.insert ({ "A78D84","Sandstone" });
    nameMap.insert ({ "F4A460","Sandybrown " });
    nameMap.insert ({ "308014","Sapgreen" });
    nameMap.insert ({ "8C1717","Scarlet" });
    nameMap.insert ({ "487153","Scotland Pound" });
    nameMap.insert ({ "68481","Sea Green" });
    nameMap.insert ({ "683A5E","Sea Urchin" });
    nameMap.insert ({ "00FFAA","Seagreen" });
    nameMap.insert ({ "54FF9F","Seagreen1" });
    nameMap.insert ({ "4EEE94","Seagreen2" });
    nameMap.insert ({ "2E8B57","Seagreen3" });
    nameMap.insert ({ "FFF5EE","Seashell " });
    nameMap.insert ({ "EEE5DE","Seashell2" });
    nameMap.insert ({ "CDC5BF","Seashell3" });
    nameMap.insert ({ "8B8682","Seashell4" });
    nameMap.insert ({ "FF6666","Seattle Salmon" });
    nameMap.insert ({ "646F5E","Seaweed" });
    nameMap.insert ({ "748269","Seaweed Roll" });
    nameMap.insert ({ "6B4226","Semisweet Chocolate1" });
    nameMap.insert ({ "E6B426","Semisweet Chocolate2" });
    nameMap.insert ({ "5E2612","Sepia" });
    nameMap.insert ({ "739AC5","Seurat Blue" });
    nameMap.insert ({ "8E388E","Sgi Beet" });
    nameMap.insert ({ "C5C1AA","Sgi Brightgray" });
    nameMap.insert ({ "71C671","Sgi Chartreuse" });
    nameMap.insert ({ "7D9EC0","Sgi Light Blue" });
    nameMap.insert ({ "AAAAAA","Sgi Light Gray" });
    nameMap.insert ({ "8E8E38","Sgi Olivedrab" });
    nameMap.insert ({ "C67171","Sgi Salmon" });
    nameMap.insert ({ "7171C6","Sgi Slate Blue" });
    nameMap.insert ({ "388E8E","Sgi Teal" });
    nameMap.insert ({ "40664D","Shamrock" });
    nameMap.insert ({ "B2D0B4","Shamrock Shake" });
    nameMap.insert ({ "8E6B23","Sienna" });
    nameMap.insert ({ "A0522D","Sienna " });
    nameMap.insert ({ "FF8247","Sienna1" });
    nameMap.insert ({ "EE7942","Sienna2" });
    nameMap.insert ({ "CD6839","Sienna3" });
    nameMap.insert ({ "8B4726","Sienna4" });
    nameMap.insert ({ "003F87","Sign Blue" });
    nameMap.insert ({ "603311","Sign Brown" });
    nameMap.insert ({ "006B54","Sign Green" });
    nameMap.insert ({ "DD7500","Sign Orange" });
    nameMap.insert ({ "AF1E2D","Sign Red" });
    nameMap.insert ({ "FCD116","Sign Yellow" });
    nameMap.insert ({ "E6E8FA","Silver" });
    nameMap.insert ({ "C0C0C0","Silver " });
    nameMap.insert ({ "87CEEB","Skyblue " });
    nameMap.insert ({ "87CEFF","Skyblue1" });
    nameMap.insert ({ "7EC0EE","Skyblue2" });
    nameMap.insert ({ "6CA6CD","Skyblue3" });
    nameMap.insert ({ "4A708B","Skyblue4" });
    nameMap.insert ({ "0099CC","Skyblue5" });
    nameMap.insert ({ "3299CC","Skyblue6" });
    nameMap.insert ({ "007FFF","Slateblue" });
    nameMap.insert ({ "6A5ACD","Slateblue " });
    nameMap.insert ({ "836FFF","Slateblue1" });
    nameMap.insert ({ "7A67EE","Slateblue2" });
    nameMap.insert ({ "6959CD","Slateblue3" });
    nameMap.insert ({ "473C8B","Slateblue4" });
    nameMap.insert ({ "708090","Slategray " });
    nameMap.insert ({ "C6E2FF","Slategray1" });
    nameMap.insert ({ "B9D3EE","Slategray2" });
    nameMap.insert ({ "9FB6CD","Slategray3" });
    nameMap.insert ({ "6C7B8B","Slategray4" });
    nameMap.insert ({ "708090","Slategrey " });
    nameMap.insert ({ "A2627A","Smyrna Purple" });
    nameMap.insert ({ "596C56","Snake" });
    nameMap.insert ({ "FFFAFA","Snow " });
    nameMap.insert ({ "EEE9E9","Snow2" });
    nameMap.insert ({ "CDC9C9","Snow3" });
    nameMap.insert ({ "8B8989","Snow4" });
    nameMap.insert ({ "8BA870","Soylent Green" });
    nameMap.insert ({ "E04006","Soylent Red" });
    nameMap.insert ({ "F4F776","Soylent Yellow" });
    nameMap.insert ({ "FF1CAE","Spicy Pink" });
    nameMap.insert ({ "435D36","Spinach" });
    nameMap.insert ({ "00FF33","Springgreen" });
    nameMap.insert ({ "00FF7F","Springgreen " });
    nameMap.insert ({ "00EE76","Springgreen2" });
    nameMap.insert ({ "00CD66","Springgreen3" });
    nameMap.insert ({ "008B45","Springgreen4" });
    nameMap.insert ({ "2C5197","St Louis Blues" });
    nameMap.insert ({ "2E37FE","Stained Glass" });
    nameMap.insert ({ "E0DFDB","Stainless Steel" });
    nameMap.insert ({ "006633","Starbucks" });
    nameMap.insert ({ "236B8E","Steelblue" });
    nameMap.insert ({ "4682B4","Steelblue " });
    nameMap.insert ({ "63B8FF","Steelblue1" });
    nameMap.insert ({ "5CACEE","Steelblue2" });
    nameMap.insert ({ "4F94CD","Steelblue3" });
    nameMap.insert ({ "36648B","Steelblue4" });
    nameMap.insert ({ "BE2625","Strawberry" });
    nameMap.insert ({ "EAB5C5","Strawberry Smoothie" });
    nameMap.insert ({ "38B0DE","Summer Sky" });
    nameMap.insert ({ "63D1F4","Surf" });
    nameMap.insert ({ "A2C93A","Sweet Potato Vine" });
    nameMap.insert ({ "67E6EC","Swimming Pool" });
    nameMap.insert ({ "DB9370","Tan" });
    nameMap.insert ({ "EE8833","Tan" });
    nameMap.insert ({ "D2B48C","Tan " });
    nameMap.insert ({ "FFA54F","Tan1" });
    nameMap.insert ({ "EE9A49","Tan2" });
    nameMap.insert ({ "8B5A2B","Tan4" });
    nameMap.insert ({ "FF7216","Tangerine" });
    nameMap.insert ({ "615E3F","Tank" });
    nameMap.insert ({ "5F755E","Tea Leaves" });
    nameMap.insert ({ "008080","Teal " });
    nameMap.insert ({ "05EDFF","Teal LED" });
    nameMap.insert ({ "385E0F","Terreverte" });
    nameMap.insert ({ "B5509C","Thistle" });
    nameMap.insert ({ "D8BFD8","Thistle " });
    nameMap.insert ({ "FFE1FF","Thistle1" });
    nameMap.insert ({ "EED2EE","Thistle2" });
    nameMap.insert ({ "CDB5CD","Thistle3" });
    nameMap.insert ({ "8B7B8B","Thistle4" });
    nameMap.insert ({ "B6AFA9","Titanium" });
    nameMap.insert ({ "FCFFF0","Titanium White" });
    nameMap.insert ({ "FF6347","Tomato " });
    nameMap.insert ({ "EE5C42","Tomato2" });
    nameMap.insert ({ "CD4F39","Tomato3" });
    nameMap.insert ({ "8B3626","Tomato4" });
    nameMap.insert ({ "E79EA9","Tongue" });
    nameMap.insert ({ "001980","Topaz" });
    nameMap.insert ({ "659D32","Tree Moss" });
    nameMap.insert ({ "62B1F6","Tropical Blue" });
    nameMap.insert ({ "00AF33","Truegreen" });
    nameMap.insert ({ "990099","Truepurple" });
    nameMap.insert ({ "A74CAB","Turnip" });
    nameMap.insert ({ "ADEAEA","Turquoise" });
    nameMap.insert ({ "0FDDAF","Turquoise" });
    nameMap.insert ({ "40E0D0","Turquoise " });
    nameMap.insert ({ "00F5FF","Turquoise1" });
    nameMap.insert ({ "00E5EE","Turquoise2" });
    nameMap.insert ({ "00C5CD","Turquoise3" });
    nameMap.insert ({ "00868B","Turquoise4" });
    nameMap.insert ({ "00C78C","Turquoiseblue" });
    nameMap.insert ({ "0147FA","Ty Nant" });
    nameMap.insert ({ "120A8F","Ultramarine" });
    nameMap.insert ({ "5C246E","Ultramarine Violet" });
    nameMap.insert ({ "1464F4","Ulysses Butterfly" });
    nameMap.insert ({ "5E2605","Vandyke Brown" });
    nameMap.insert ({ "B4D7BF","Vanilla Mint" });
    nameMap.insert ({ "D41A1F","Venetian Red" });
    nameMap.insert ({ "5C4033","Very Dark Brown" });
    nameMap.insert ({ "CDCDCD","Very Light Grey" });
    nameMap.insert ({ "4F2F4F","Violet" });
    nameMap.insert ({ "8F5E99","Violet" });
    nameMap.insert ({ "EE82EE","Violet " });
    nameMap.insert ({ "BF5FFF","Violet Flower" });
    nameMap.insert ({ "CC3299","Violetred" });
    nameMap.insert ({ "D02090","Violetred" });
    nameMap.insert ({ "FF3E96","Violetred1" });
    nameMap.insert ({ "EE3A8C","Violetred2" });
    nameMap.insert ({ "CD3278","Violetred3" });
    nameMap.insert ({ "8B2252","Violetred4" });
    nameMap.insert ({ "6EFF70","Viridian Light" });
    nameMap.insert ({ "4AC948","Wales" });
    nameMap.insert ({ "808069","Warmgrey" });
    nameMap.insert ({ "66FF66","Wasabi" });
    nameMap.insert ({ "AEBB51","Wasabi Sauce" });
    nameMap.insert ({ "F2473F","Watermelon Pulp" });
    nameMap.insert ({ "54632C","Watermelon Rind" });
    nameMap.insert ({ "99CDC9","Wavecrest" });
    nameMap.insert ({ "3D5229","Wet Moss" });
    nameMap.insert ({ "D8D8BF","Wheat" });
    nameMap.insert ({ "F5DEB3","Wheat " });
    nameMap.insert ({ "FFE7BA","Wheat1" });
    nameMap.insert ({ "EED8AE","Wheat2" });
    nameMap.insert ({ "CDBA96","Wheat3" });
    nameMap.insert ({ "8B7E66","Wheat4" });
    nameMap.insert ({ "FFFFFF","White " });
    nameMap.insert ({ "F5F5F5","Whitesmoke " });
    nameMap.insert ({ "820BBB","Wild Violet" });
    nameMap.insert ({ "EEEB8D","Yellow Candy" });
    nameMap.insert ({ "E0D873","Yellow Perch" });
    nameMap.insert ({ "FFFF00","Yellow" });
    nameMap.insert ({ "EEEE00","Yellow2" });
    nameMap.insert ({ "CDCD00","Yellow3" });
    nameMap.insert ({ "8B8B00","Yellow4" });
    nameMap.insert ({ "9ACD32","Yellowgreen " });
    nameMap.insert ({ "99CC32","Yellowgreen2" });
    nameMap.insert ({ "E38217","Yellowochre" });
    nameMap.insert ({ "2E5090","Yinmn Blue" });
    nameMap.insert ({ "FFE600","Yolk" });
    nameMap.insert ({ "FDF8FF","Zincwhite" });
    nameMap.insert ({ "86C67C","100 Euro" });
    nameMap.insert ({ "A46582","20 Pound" });
    nameMap.insert ({ "1B6453","6 Ball" });



}

/**
 * Access Method.
 * 
 * \param colorName : name of Color; e.g., "Orange"
 * \return the the Color representing the input name.
 */
Color *ColorTable::getColor (string colorName)  {
    Color *result = new Color ();
    map<string, Color *>::iterator it;
    it = colorMap.find (colorName);
    if (it != colorMap.end ())
        result = it->second;
    return result;
}

/**
 * Access Method.
 *
 * \param colorName : 6 character HEX value
 * \return the the name corresponding the the HEX value. If not found, return "UNKNOWN".
 */
string ColorTable::getColorName (string hexstr) {
    string result = "UNKNOWN";
    map<string, string>::iterator it;
    it = nameMap.find (hexstr);
    if (it != nameMap.end ()) {
        result = it->second;
    }
    return result;
}

/**
 * Access method.
 * 
 * \return the Color Map as a map<string, Color*>.
 */
map<string, Color* > ColorTable::getColorMap () {
    return this->colorMap;
}

/**
 * Access method.
 *
 * \return the Name Map as a map<string, string>.
 */
map<string, string> ColorTable::getNameMap () {
    return nameMap;
}

/**
 * Debug aid.
 * Prints the list of Color Map Names to /tmp/ColorMapNames.txt
 */
void ColorTable::dumpColorMapNames () {
    map<string, Color*>::iterator it;
    ofstream outfile;
    outfile.open ("c:\\tmp\\ColorMapNames.txt");
    if (it != colorMap.end ())
        outfile << it->second << "\n";
    outfile.close ();
}

/**
 * Debug aid.
 * Prints the list of Name Map Names to /tmp/NameMapNames.txt
 */
void ColorTable::dumpNameMapNames () {
    map<string, string>::iterator it;
    ofstream outfile;
    outfile.open ("C:\\tmp\\NameMapNames.txt");
    if (it != nameMap.end ()) {
        outfile << it->second << "\n";
    }
    outfile.close ();
}
