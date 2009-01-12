// Ruler.h

#pragma once
#include "../interface/HeeksObj.h"

struct RulerMark{
	int pos; // distance from the 0 mark
	double length;
	double width;

	void glCommands(); // including text
};

class HRuler: public HeeksObj{
	//      ___________________________________________________________________  
	//     |   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||   | 
	//     |   |    |    |    |    |    |    |    |    |    |    |    |    |   | 
	//     |   |cm      1|        2|        3|        4|         |         |   | 
	//     |                                                                   | 
	//     |                                                                   | 
	//     ��������������������������������������������������������������������  
	//

	//  to do - make options for showing ruler in inches, furlongs, hands, etc.  

	double m_width;
	double m_length;
	double m_empty_length; // space at each end
	int m_gl_list;

	void GetFourCorners(gp_Pnt *point);
	void CalculateMarks(std::list<RulerMark> &marks);

public:
	gp_Trsf m_trsf; // position and orientation ( no scaling allowed )

	HRuler();

	// HeeksObj's virtual functions
	int GetType()const{return RulerType;}
	long GetMarkingMask()const{return MARKING_FILTER_RULER;}
	void glCommands(bool select, bool marked, bool no_color);
	void KillGLLists(void);
	void GetBox(CBox &box);
	const wxChar* GetTypeString(void)const{return _("Ruler");}
	HeeksObj *MakeACopy(void)const;
	bool ModifyByMatrix(const double *mat);
	void GetGripperPositions(std::list<double> *list, bool just_for_endof);
	void GetProperties(std::list<Property *> *list);
	void GetTools(std::list<Tool*>* t_list, const wxPoint* p);
	bool GetScaleAboutMatrix(double *m);
	bool CanBeRemoved(){return false;}
	bool CanBeCopied(){return false;}
};