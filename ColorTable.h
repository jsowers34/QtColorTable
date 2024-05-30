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
	map<string, Color*>  getColorMap ();
	map<string, string>  getNameMap ();

	void dumpColorMapNames ();
	void dumpNameMapNames ();



private:
	map<string, Color* >  colorMap;
	map<string, string> nameMap;

	void loadColorMap ();
	void loadNameMap ();

};

#endif
