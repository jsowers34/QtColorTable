/****************************************************************************/
/* BEGIN FILE Color.cpp                                                     */
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

#include "Color.h"
#include <cstddef>
#include <boost/format.hpp>
#include <iostream>
#include <sstream>

/*                                                                          */
/****************************************************************************/
/* DEFINES                                                                  */
/*                                                                          */
using namespace std;
/****************************************************************************/
/*	 Begin Code                                                             */



/**
 * Default Constructor.
 * All values -1.
 */
Color::Color () {
	m_red = -1;
	m_blue = -1;
	m_green = -1;
	colorValue = UNKNOWN;
}

/**
 * Constructor using RGB integer input.
 * 
 * \param red
 * \param green
 * \param blue
 */
Color::Color (int red, int green, int blue) {
	m_red   = red;
	m_blue  = blue;
	m_green = green;
	colorValue = 256 * (256 * red + green) + blue;
}

/**
 * Constructor using RGB float input.
 * float parameters converted to int.
 * 
 * \param red
 * \param green
 * \param blue
 */
Color::Color (float red, float green, float blue) {
	m_red   = int(red);
	m_blue  = int(blue);
	m_green = int(green);
	colorValue = 256 * (256 * m_red + m_green) + m_blue;
}

/**
 * Constructor using a HEX color value as input.
 * 
 * \param hexstring : a 6 character color value, e.g., "FFFF00".
 */
Color::Color (string hexstring) {
	int red = hex2int (getRedHex (hexstring));
	int green = hex2int (getGreenHex (hexstring));
	int blue = hex2int (getBlueHex (hexstring));
	Color (red, green, blue);
}

/**
 * Accessor method.
 * 
 * \return the HEX value of the class' colorValue.
 */
string Color::getHexColor() {
	return int2hex (colorValue);
}

/**
 * Conversion method.
 * 
 * \param x :  integer value
 * \return the HEX string equivalent of the input integer. Alpha characters are uppercase.
 */
string Color::int2hex (int x) {
	stringstream sstream;
	sstream << std::hex << x;
	string hstr = sstream.str ();
	int hlen = (int) hstr.length ();
	if (hlen < 6) {
		if (hlen == 1) {
			hstr = "00000" + hstr;
		} else if (hlen == 2) {
			hstr = "0000" + hstr;
		} else if (hlen == 3) {
			hstr = "000" + hstr;
		} else if (hlen == 4) {
			hstr = "00" + hstr;
		} else hstr = hstr + "0";
	}
	for (auto& c : hstr) c = toupper (c);
	return hstr;
}

/**
 * Conversion method.
 * 
 * \param hexstr : input is a HEX color string
 * \return the integer equivalent.
 */
int Color::hex2int (string hexstr) {
	return stoi (hexstr, 0, 16);
}

/**
 * Accessor method.
 * 
 * \param hexstr : input is a 6 character HEX color string.
 * \return the RED portion (1st 2 characters).
 */
string Color::getRedHex (string hexstr) {
	return hexstr.substr (0, 2);
}

/**
 * Accessor method.
 *
 * \param hexstr : input is a 6 character HEX color string.
 * \return the GREEN portion (middle 2 characters).
 */
string Color::getGreenHex (string hexstr) {
	return hexstr.substr (2, 2);
}

/**
 * Accessor method.
 *
 * \param hexstr : input is a 6 character HEX color string.
 * \return the BLUE portion (last 2 characters).
 */
string Color::getBlueHex (string hexstr) {
	return hexstr.substr (4, 2);
}

/**
 * Accessor method.
 * 
 * \param hexstr : input is a 6 character HEX color string.
 * \return integer value of RED portion of the string.
 */
int Color::getRedInt (string hexstr) {
	return hex2int (getRedHex (hexstr));
}

/**
 * Accessor method.
 *
 * \param hexstr : input is a 6 character HEX color string.
 * \return integer value of GREEN portion of the string.
 */
int Color::getGreenInt (string hexstr){
	return hex2int (getGreenHex (hexstr));
}

/**
 * Accessor method.
 *
 * \param hexstr : input is a 6 character HEX color string.
 * \return integer value of BLUE portion of the string.
 */
int Color::getBlueInt (string hexstr){
	return hex2int (getBlueHex (hexstr));
}

/**
 * Accessor method.
 * 
 * \return the RED value of the class.
 */
int Color::getRed () {
	return m_red;
}

/**
 * Accessor method.
 *
 * \return the GREEN value of the class.
 */
int Color::getGreen () {
	return m_green;
}

/**
 * Accessor method.
 *
 * \return the BLUE value of the class.
 */
int Color::getBlue () {
	return m_blue;
}

/**
 * Debug aid.
 * Print the internal values of the RED, GREEN, BLUE and combined Color values to std output.
 */
void Color::toString () {
	cout << "Red   = " << m_red << "(0x" << int2hex (int (m_red)) << ")" << endl;
	cout << "Green = " << m_green << "(0x" << int2hex (int (m_green)) << ")" << endl;
	cout << "Blue  = " << m_blue << "(0x" << int2hex (int (m_blue)) << ")" << endl;
	cout << "Color Value = " << colorValue << "(0x" << int2hex(colorValue) << ")\n" << endl;
}
