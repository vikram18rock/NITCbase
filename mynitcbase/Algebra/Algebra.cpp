#include "Algebra.h"

#include <cstring>
#include <iostream>


// will return if a string can be parsed as a floating point number
bool isNumber(char* str) {
	int len;
	float ignore;
	/*
	  sscanf returns the number of elements read, so if there is no float matching
	  the first %f, ret will be 0, else it'll be 1

	  %n gets the number of characters read. this scanf sequence will read the
	  first float ignoring all the whitespace before and after. and the number of
	  characters read that far will be stored in len. if len == strlen(str), then
	  the string only contains a float with/without whitespace. else, there's other
	  characters.
	*/
	int ret = sscanf(str, "%f %n", &ignore, &len);
	return ret == 1 && len == strlen(str);
}

int Algebra::select(char srcRel[ATTR_SIZE], char targetRel[ATTR_SIZE], char attr[ATTR_SIZE], int op, char strVal[ATTR_SIZE]) {
    // get the srcRel's rel-id (let it be srcRelid), using OpenRelTable::getRelId()
    // if srcRel is not open in open relation table, return E_RELNOTOPEN

    // get the attr-cat entry for attr, using AttrCacheTable::getAttrCatEntry()
    // if getAttrcatEntry() call fails return E_ATTRNOTEXIST


    /*** Convert strVal to an attribute of data type NUMBER or STRING ***/

    Attribute attrVal;
    int type = attrCatEntry.attrType;

    if (type == NUMBER)
    {
        // if the input argument strVal can be converted to a number
        // (check this using isNumber() function)
        {
            // convert strVal to double and store it at attrVal.nVal using atof()
        }
        // else
        {
            return E_ATTRTYPEMISMATCH;
        }
    }
    else if (type == STRING)
    {
        // copy strVal to attrVal.sVal
    }

    /*** Creating and opening the target relation ***/
    // Prepare arguments for createRel() in the following way:
    // get RelcatEntry of srcRel using RelCacheTable::getRelCatEntry()
    int src_nAttrs = /* the no. of attributes present in src relation */ ;


    /* let attr_names[src_nAttrs][ATTR_SIZE] be a 2D array of type char
        (will store the attribute names of rel). */
    // let attr_types[src_nAttrs] be an array of type int

    /*iterate through 0 to src_nAttrs-1 :
        get the i'th attribute's AttrCatEntry using AttrCacheTable::getAttrCatEntry()
        fill the attr_names, attr_types arrays that we declared with the entries
        of corresponding attributes
    */


    /* Create the relation for target relation by calling Schema::createRel()
       by providing appropriate arguments */
    // if the createRel returns an error code, then return that value.

    /* Open the newly created target relation by calling OpenRelTable::openRel()
       method and store the target relid */
    /* If opening fails, delete the target relation by calling Schema::deleteRel()
       and return the error value returned from openRel() */

    /*** Selecting and inserting records into the target relation ***/
    /* Before calling the search function, reset the search to start from the
       first using RelCacheTable::resetSearchIndex() */

    Attribute record[src_nAttrs];

    /*
        The BlockAccess::search() function can either do a linearSearch or
        a B+ tree search. Hence, reset the search index of the relation in the
        relation cache using RelCacheTable::resetSearchIndex().
        Also, reset the search index in the attribute cache for the select
        condition attribute with name given by the argument `attr`. Use
        AttrCacheTable::resetSearchIndex().
        Both these calls are necessary to ensure that search begins from the
        first record.
    */
    RelCacheTable::resetSearchIndex(/* fill arguments */);
    AttrCacheTable::resetSearchIndex(/* fill arguments */);

    // read every record that satisfies the condition by repeatedly calling
    // BlockAccess::search() until there are no more records to be read

    while (/* BlockAccess::search() returns success */) {

        // ret = BlockAccess::insert(targetRelId, record);

        // if (insert fails) {
        //     close the targetrel(by calling Schema::closeRel(targetrel))
        //     delete targetrel (by calling Schema::deleteRel(targetrel))
        //     return ret;
        // }
    }

    // Close the targetRel by calling closeRel() method of schema layer

    // return SUCCESS.
}

/* This method inserts the given record into the specified Relation. Insertion
  is only done if the Relation is open and attribute number and types match.
 */
int Algebra::insert(char relName[ATTR_SIZE], int nAttrs, char record[][ATTR_SIZE]) {
	// if relName is equal to "RELATIONCAT" or "ATTRIBUTECAT"
	// return E_NOTPERMITTED;
	if (
		strcmp(relName, RELCAT_RELNAME) == 0 ||
		strcmp(relName, ATTRCAT_RELNAME) == 0
		) {
		return E_NOTPERMITTED;
	}

	// get the relation's rel-id using OpenRelTable::getRelId() method
	int relId = OpenRelTable::getRelId(relName);

	// if relation is not open in open relation table, return E_RELNOTOPEN
	// (check if the value returned from getRelId function call = E_RELNOTOPEN)
	// get the relation catalog entry from relation cache
	// (use RelCacheTable::getRelCatEntry() of Cache Layer)
	if (relId == E_RELNOTOPEN) {
		return E_RELNOTOPEN;
	}

	RelCatEntry relCatEntry;
	RelCacheTable::getRelCatEntry(relId, &relCatEntry);

	/* if relCatEntry.numAttrs != numberOfAttributes in relation,
	   return E_NATTRMISMATCH */
	if (relCatEntry.numAttrs != nAttrs) {
		return E_NATTRMISMATCH;
	}

	// let recordValues[numberOfAttributes] be an array of type union Attribute
	Attribute recordValues[nAttrs];

	/*
		Converting 2D char array of record values to Attribute array recordValues
	 */
	 // iterate through 0 to nAttrs-1: (let i be the iterator)
	for (int i = 0; i < nAttrs; i++)
	{
		// get the attr-cat entry for the i'th attribute from the attr-cache
		// (use AttrCacheTable::getAttrCatEntry())
		AttrCatEntry attrCatEntry;
		AttrCacheTable::getAttrCatEntry(relId, i, &attrCatEntry);

		// let type = attrCatEntry.attrType;
		int type = attrCatEntry.attrType;

		if (type == NUMBER)
		{
			// if the char array record[i] can be converted to a number
			// (check this using isNumber() function)
			if (isNumber(record[i])) {
				/* convert the char array to numeral and store it
				   at recordValues[i].nVal using atof() */
				recordValues[i].nVal = atof(record[i]);

			}
			// else
			else {
				return E_ATTRTYPEMISMATCH;
			}
		}
		else if (type == STRING)
		{
			// copy record[i] to recordValues[i].sVal
			strcpy(recordValues[i].sVal, record[i]);
		}
	}

	// insert the record by calling BlockAccess::insert() function
	// let retVal denote the return value of insert call
	int retVal = BlockAccess::insert(relId, recordValues);

	return retVal;
}