#include <string>
#include <fstream>

namespace infoArrays {
typedef long long ID;

bool isFileExist(const char* fileName)
{	bool res;
    std::ifstream infile (fileName);
    res = infile.good() ;
    infile.close() ;
    return res;	}

struct infoRecord
  {	ID _id ; // unique
	std::string _description ;
  } ;

template <class key>
struct quotation
{	key _idStoka ; // the pair is an offer key
	key _idPrice ;
} ;

} ;

template <class K>
class infoArraysAPI // abstract class
{ // DEFs placed into an infoArraysAPI
public:
	virtual infoArrays::infoRecord getRecord(K id) = 0  ;
	virtual infoArrays::infoRecord setNewRecord() = 0 ;
	virtual void printList() = 0 ; 
	virtual infoArrays::infoRecord selectRecord() = 0 ;
} ;
