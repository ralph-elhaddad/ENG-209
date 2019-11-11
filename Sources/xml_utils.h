/*
 * xml_utils.h
 *
 *  Created on: May 25, 2019
 *      Author: vachoux
 */

#ifndef XML_UTILS_H_
#define XML_UTILS_H_

#include "tinyxml2/tinyxml2.h"
#include <string>

namespace tinyxml2_utils {

typedef const char* xml_string;    //!< String type for TinyXML2.

// create_dom
/*!
 * Loads an XML file and builds the DOM.
 * Throws an error message exception if the XML file has syntax errors.
 *
 * \param   file_name   XML file name to parse.
 *
 */
tinyxml2::XMLDocument* create_dom(std::string file_name);

// get_elem
/*!
 * Gets a pointer to a sub-element of an element.
 * Throws an exception if element is missing.
 *
 *    \param   p_parent    Pointer to parent XML element.
 *    \param   name        Element name.
 *    \param   mandatory   Is the element mandatory?
 *
 *    \return  Pointer to element.
 */
tinyxml2::XMLElement* get_elem(tinyxml2::XMLElement* p_parent,
                               xml_string name,
                               bool mandatory = true);

// get_elem_str
/*!
 * Extracts the string value of an element.
 * Throws an exception if element is mandatory and is missing.
 *
 *    \param   p_parent       Pointer to parent XML element.
 *    \param   name           Element name.
 *    \param   mandatory      Is the element mandatory?
 *    \param   default_val    If not mandatory, use the default value.
 *
 *    \return  Element value from XML DOM or default value.
 */
std::string get_elem_str(tinyxml2::XMLElement* p_parent,
                         xml_string name,
                         bool mandatory = true,
                         std::string default_val = "");

// get_elem_int
/*!
 * Extracts the numeric value of an element.
 * Throws an exception if element is mandatory and is missing
 * or if the value is not an integer.
 *
 *    \param   p_parent       Pointer to parent XML element.
 *    \param   name           Element name.
 *    \param   mandatory      Is the element mandatory?
 *    \param   default_val    If not, use the default value.
 *
 *    \return  Element value from XML DOM or default value.
 */
int get_elem_int(tinyxml2::XMLElement* p_parent,
                 xml_string name,
                 bool mandatory = true,
                 int default_val = 0);

// get_elem_dbl
/*!
 * Extracts the numeric value of an element.
 * Throws an exception if element is mandatory and is missing
 * or if the value is not a double.
 *
 *    \param   p_parent       Pointer to parent XML element.
 *    \param   name           Element name.
 *    \param   mandatory      Is the element mandatory?
 *    \param   default_val    If not, use the default value.
 *
 *    \return  Element value from XML DOM or default value.
 */
double get_elem_dbl(tinyxml2::XMLElement* p_parent,
                    xml_string name,
                    bool mandatory = true,
                    double default_val = 0.0);

// get_attr_str
/*!
 * Extracts the string value of an attribute.
 * Throws an exception if attribute is mandatory and is missing.
 *
 *    \param   p_parent       Pointer XML element that hosts the attribute.
 *    \param   name           Attribute name.
 *    \param   mandatory      Is the attribute mandatory?
 *    \param   default_val    If not mandatory, use the default value.
 *
 *    \return  Attribute value from XML DOM or default value.
 */
std::string get_attr_str(tinyxml2::XMLElement* p_elem,
                         xml_string name,
                         bool mandatory = true,
                         std::string default_val = "");

// get_attr_int
/*!
 * Extracts the integer value of an attribute.
 * Throws an exception if attribute is mandatory and is missing
 * or if the value is not an integer.
 *
 *    \param   p_elem         Pointer to XML element that hosts the attribute.
 *    \param   name           Attribute name.
 *    \param   mandatory      Is the attribute mandatory?
 *    \param   default_val    If not, use the default value.
 *
 *    \return  Attribute value from XML DOM or default value.
 */
int get_attr_int(tinyxml2::XMLElement* p_elem,
                 xml_string name,
                 bool mandatory = true,
                 int default_val = 0);

// get_attr_dbl
/*!
 * Extracts the double value of an attribute.
 * Throws an exception if attribute is mandatory and is missing
 * or if the value is not a double.
 *
 *    \param   p_elem         Pointer to XML element that hosts the attribute.
 *    \param   name           Attribute name.
 *    \param   mandatory      Is the attribute mandatory?
 *    \param   default_val    If not, use the default value.
 *
 *    \return  Attribute value from XML DOM or default value.
 */
double get_attr_dbl(tinyxml2::XMLElement* p_elem,
                    xml_string name,
                    bool mandatory = true,
                    double default_val = 0.0);

// get_attr_yesno
/*!
 * Extracts the yes/no value of an attribute.
 * Throws an exception if attribute is mandatory and is missing
 * or if the value is not "yes" or "no".
 *
 *    \param   p_elem         Pointer to XML element that hosts the attribute.
 *    \param   name           Attribute name.
 *    \param   mandatory      Is the attribute mandatory?
 *    \param   default_val    If not, use the default value.
 *
 *    \return  Attribute value from XML DOM or default value.
 */
bool get_attr_yesno (tinyxml2::XMLElement* p_elem,
                     xml_string name,
                     bool mandatory = true,
                     std::string default_val = "no");

// print_dom
/*!
 * Prints the DOM content.
 * Throws an error message if the XML file has syntax errors.
 *
 *    \param   p_dom       Pointer to XML DOM.
 *    \param   max_level   Stop at level (default: all levels).
 */
void print_dom (tinyxml2::XMLDocument* p_dom, int max_level = -1);

// dump_xml
/*!
 * Loads an XML file, builds the DOM and displays the full DOM content.
 * Throws an error message if the XML file has syntax errors.
 *
 *    \param   xml_file    XML file name to parse.
 *    \param   max_level   Stop at level (default: all levels).
 */
void dump_xml (std::string xml_file, int max_level = -1);

}  // namespace tinyxml2_utils

#endif /* XML_UTILS_H_ */
