/****************************************************************************/
/* BEGIN FILE  ColorTable.h                                                 */
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
/*      @author    jsowers              24MAY24                             */
/*                                                                          */
/*   Modifications:                                                         */
/*                                                                          */
/****************************************************************************/
/* SAFETY DEFINITION                                                        */
/*                                                                          */

#ifndef _COLORTABLE_H_
#define _COLORTABLE_H_

/****************************************************************************/
/* INCLUDE FILES                                                            */
/*                                                                          */

#include <map>
#include <string>
#include "Color.h"

/****************************************************************************/
/* DEFINES                                                                  */
/*                                                                          */

#pragma once

using namespace std;

/****************************************************************************/
/*	 Begin Code                                                             */

class ColorTable {

public:
	ColorTable ();
	~ColorTable ();

	Color *getColor (string colorName);
	string getColorName (string hexstr);

	typedef map<string, Color *> ColorMap;
	typedef map<string, string> NameMap;


	ColorMap  getColorMap ();
	map<string, string>  getNameMap ();

	void dumpColorMapNames ();
	void dumpNameMapNames ();

private:
	ColorMap  colorMap;      /**< Maps the Color Name to the corresponding Color class. */
	NameMap   nameMap;       /**< Maps the 6-Char Hex code to the Color Name. */

	void loadColorMap ();
	void createNameMap ();

};

#endif
