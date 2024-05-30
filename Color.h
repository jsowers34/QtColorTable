/****************************************************************************/
/* BEGIN FILE  Color.h                                                      */
/*                                                                          */
/****************************************************************************/
/* PURPOSE                                                                  */
/*      Provide basic color methods.                                                                    */
/****************************************************************************/
/* DESIGN NOTES                                                             */
/*                                                                          */
/****************************************************************************/
/* REVISION HISTORY                                                         */
/*                                                                          */
/*   Initial Code:                                                          */
/*      @author    jsowers              24MAY24                             */
/*                                                                          */
/*   Modifications:                                                         */
/*                                                                          */
/****************************************************************************/
/* SAFETY DEFINITION                                                        */
/*                                                                          */

#ifndef _COLOR_H_
#define _COLOR_H_

/****************************************************************************/
/* INCLUDE FILES                                                            */
/*                                                                          */

#include <string>

/****************************************************************************/
/* DEFINES                                                                  */
/*                                                                          */
#pragma once

using namespace std;

/****************************************************************************/
/*	 Begin Code                                                             */

class Color {

public:
    Color ();
    Color (int red, int green, int blue);
    Color (float red, float green, float blue);
    Color (string hexstring);

    static int hex2int (string hexstr);
    static string int2hex (int x);
    string getHexColor ();
    static string getRedHex (string hexstr);
    static string getGreenHex (string hexstr);
    static string getBlueHex (string hexstr);
    static int getRedInt (string hexstr);
    static int getGreenInt (string hexstr);
    static int getBlueInt (string hexstr);

    int getRed ();
    int getGreen ();
    int getBlue ();
    void   toString ();

    static const int UNKNOWN = 1;


private:
    int m_red = 0;
    int m_green = 0;
    int m_blue = 0;

    int colorValue;
};

#endif

