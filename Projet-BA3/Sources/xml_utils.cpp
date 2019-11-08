/*
 * xml_utils.cpp
 *
 *  Created on: May 25, 2019
 *      Author: vachoux
 */

#include "xml_utils.h"

#include <iostream>
#include <sstream>
#include "tinyxml2/tinyxml2.h"
using namespace std;
using namespace tinyxml2;

/*----------------------------------------------------------------------------------------
*    create_dom
*/
XMLDocument* tinyxml2_utils::create_dom(string file_name) {

  XMLDocument* p_dom = new XMLDocument;

  p_dom->LoadFile(file_name.c_str());

  XMLError error_ID = p_dom->ErrorID();
  if (error_ID) {
     ostringstream ostr;
     ostr << "Incorrect XML file '" << file_name << "'" << endl
          << p_dom->ErrorStr();
     throw ostr.str();
  }
  else cout << "XML file '" << file_name << "' and DOM OK" << endl;

  return p_dom;
}

/*----------------------------------------------------------------------------------------
 *    get_elem
 */
XMLElement* tinyxml2_utils::get_elem(XMLElement* p_parent, xml_string name, bool mandatory) {

   if ( XMLElement* p_elem = p_parent->FirstChildElement(name) ) return p_elem;
   else if ( mandatory ) {
      ostringstream ostr;
      ostr << "Element '" << name << "' expected"
           << " (line " << p_parent->GetLineNum() << ", "
           << "parent element '" << p_parent->Name() << "')";
      throw ostr.str();
   }
   return NULL;
}

/*----------------------------------------------------------------------------------------
 *    get_elem_str
 */
string tinyxml2_utils::get_elem_str(
   XMLElement* p_parent, xml_string name, bool mandatory, string default_val) {

   string val;

   XMLElement* p_elem = get_elem(p_parent, name, mandatory);

   if ( p_elem == 0 && !mandatory ) val = default_val;
   else if ( xml_string str = p_elem->GetText() ) val = str;
   else if ( !mandatory ) val = default_val;
   else {  // empty element value
      ostringstream ostr;
      ostr << "Query error: empty element value"
           << " (line "   << p_elem->GetLineNum() << ", "
           << "element '" << p_elem->Name()       << "', "
           << "parent '"  << p_parent->Name()     << "')";
      throw ostr.str();
   }
   return val;
}

/*----------------------------------------------------------------------------------------
 *    get_elem_int
 */
int tinyxml2_utils::get_elem_int(
   XMLElement* p_parent, xml_string name, bool mandatory, int default_val) {

   int val;

   XMLElement* p_elem = get_elem(p_parent, name, mandatory);

   if ( p_elem == 0 && !mandatory ) val = default_val;
   else if ( p_elem->QueryIntText(&val) != 0 ) {
      ostringstream ostr;
      ostr << "Query error: integer element value expected" << endl
           << "    Got "  << (p_elem->GetText()? ("'" + string(p_elem->GetText()) + "'") : "empty field")
           << ", "
           << "line "     << p_elem->GetLineNum() << ", "
           << "element '" << p_elem->Name()       << "', "
           << "parent '"  << p_parent->Name()     << "'";
      throw ostr.str();
   }
   return val;
}

/*----------------------------------------------------------------------------------------
 *    get_elem_dbl
 */
double tinyxml2_utils::get_elem_dbl(
   XMLElement* p_parent, xml_string name, bool mandatory, double default_val) {

   double val;

   XMLElement* p_elem = get_elem(p_parent, name, mandatory);

   if ( p_elem == 0 && !mandatory ) val = default_val;
   else if ( p_elem->QueryDoubleText(&val) != 0 ) {
      ostringstream ostr;
      ostr << "Query error: double element value expected" << endl
           << "    Got "  << (p_elem->GetText()? ("'" + string(p_elem->GetText()) + "'") : "empty field")
           << ", "
           << "line "     << p_elem->GetLineNum() << ", "
           << "element '" << p_elem->Name()       << "', "
           << "parent '"  << p_parent->Name()     << "'";
      throw ostr.str();
   }
   return val;
}

/*----------------------------------------------------------------------------------------
 *    get_attr_str
 */
string tinyxml2_utils::get_attr_str(
   XMLElement* p_elem, xml_string name, bool mandatory, string default_val) {

   xml_string val = p_elem->Attribute(name);
   if ( val == 0 ) {
      if ( !mandatory ) val = default_val.c_str();
      else {
         ostringstream ostr;
         ostr << "Attribute '" << name << "' expected"
              << " (line "   << p_elem->GetLineNum() << ", "
              << "element '" << p_elem->Name()       << "')";
         throw ostr.str();
      }
   }
   return val;
}

/*----------------------------------------------------------------------------------------
 *    get_attr_int
 */
int tinyxml2_utils::get_attr_int(
   XMLElement* p_elem, xml_string name, bool mandatory, int default_val) {

   int val;

   if ( p_elem->QueryIntAttribute(name, &val) ) {
      if ( !mandatory ) val = default_val;
      else {
         ostringstream ostr;
         ostr << "Integer attribute value expected"
              << " (got '"     << p_elem->Attribute(name) << "', "
              << "line "       << p_elem->GetLineNum()    << "', "
              << "element '"   << p_elem->Name()          << "', "
              << "attribute '" << name                    << "')";
         throw ostr.str();
      }
   }
   return val;
}

/*----------------------------------------------------------------------------------------
 *    get_attr_dbl
 */
double tinyxml2_utils::get_attr_dbl(
   XMLElement* p_elem, xml_string name, bool mandatory, double default_val) {

   double val;

   if ( p_elem->QueryDoubleAttribute(name, &val) ) {
      if ( !mandatory ) val = default_val;
      else {
         ostringstream ostr;
         ostr << "Double attribute value expected"
              << " (got '"     << p_elem->Attribute(name) << "', "
              << "line "       << p_elem->GetLineNum()    << "', "
              << "element '"   << p_elem->Name()          << "', "
              << "attribute '" << name                    << "')";
         throw ostr.str();
      }
   }
   return val;
}

/*----------------------------------------------------------------------------------------
 *    get_attr_yesno
 */
bool tinyxml2_utils::get_attr_yesno (
   XMLElement* p_elem, xml_string name, bool mandatory, string default_val) {

   bool val = false;

   string str = get_attr_str(p_elem, name, mandatory, default_val);

   if ( str == "yes" || str == "no" ) return (str == "yes")? true : false;
   else if ( mandatory ) {
      ostringstream ostr;
      ostr << "yes/no attribute value expected"
           << " (got '"     << p_elem->Attribute(name) << "', "
           << "line "       << p_elem->GetLineNum()    << "', "
           << "element '"   << p_elem->Name()          << "', "
           << "attribute '" << name                    << "')";
      throw ostr.str();
   }
   return val;
}

/*----------------------------------------------------------------------------------------
 *    print_level (local)
 */
void print_level (tinyxml2::XMLElement* p_level, int prev_level, int max_level) {
   using namespace tinyxml2;
   using namespace std;

   const string INDENT = "   ";  // indentation for one level
   int level = prev_level + 1;

   // define the indentation for printing elements and attributes at the current level

   ostringstream ident_elem;
   for (int i = 0; i < level; ++i) ident_elem << INDENT;

   ostringstream ident_attr;
   for (int i = 0; i <= level; ++i) ident_attr << INDENT;

   // visit all elements at the current level

   for (auto p_elem = p_level;
        p_elem;
        p_elem = p_elem->NextSiblingElement()) {

      ostringstream elem_str;
      elem_str << ident_elem.str() << "Element '" << p_elem->Name() << "'";
      if ( p_elem->GetText() ) {
         // remove end of line, if any
         string text = p_elem->GetText();
         if ( text.find('\n') != string::npos ) text.erase(text.find('\n'));
         elem_str << " (" << text << ")";
      }
      cout << elem_str.str() << endl;

      // visit all element attributes

      for (auto p_attr = p_elem->FirstAttribute();
          p_attr;
          p_attr = p_attr->Next()) {

         ostringstream attr_str;
         attr_str << ident_attr.str() << "Attribute '" << p_attr->Name() << "' (" << p_attr->Value() << ")";
         cout << attr_str.str() << endl;
      }

      // visit next level, if any

      if ( max_level == -1 || level < max_level) {
         auto p_elem_next = p_elem->FirstChildElement();
         if ( p_elem_next ) print_level(p_elem_next, level, max_level);
      }
   }
}

/*----------------------------------------------------------------------------------------
 *    print_dom
 */
void tinyxml2_utils::print_dom (XMLDocument* p_dom, int max_level) {

   cout << "DOM:" << endl;
   print_level(p_dom->RootElement(), -1, max_level);
}

/*----------------------------------------------------------------------------------------
 *    dump_xml
 */
void tinyxml2_utils::dump_xml (string file_name, int max_level) {

   // DOM creation
   XMLDocument* dom = create_dom(file_name);

   // If DOM OK, scan it
   cout << "XML document contents:" << endl;
   print_level(dom->RootElement(), -1, max_level);
}
